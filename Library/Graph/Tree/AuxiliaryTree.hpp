#pragma once

#include <set>
#include <vector>

#include "./HeavyLightDecomposition.hpp"

namespace mtd {
  template <class Node, class Cost>
  class AuxiliaryTree {
    // 定数倍高速化のため破壊的
    std::vector<int> compres_map;

    const std::vector<Cost> depth_cost;
    const HeavyLightDecomposition<Node, Cost> hld;

    auto construct_depth(const Graph<Node, Cost>& tree) const {
      std::vector<Cost> depth_cost(tree.size());
      std::vector<int> used(tree.size());
      auto dfs = [&](auto&& self, Node from) -> void {
        used[from] = true;
        for (const auto& [to, c] : tree.getEdges(from))
          if (!used[to]) {
            depth_cost[to] = depth_cost[from] + c;
            self(self, to);
          }
      };
      dfs(dfs, 0);
      return depth_cost;
    }

  public:
    AuxiliaryTree(const Graph<Node, Cost>& tree)
        : compres_map(tree.size()),
          depth_cost(construct_depth(tree)),
          hld(tree) {}

    auto compression(const std::vector<Node>& nodes) {
      auto compare = [&](int a, int b) { return hld.getId(a) < hld.getId(b); };

      // 元の頂点集合
      auto nodes_set =
          std::set<int, decltype(compare)>(nodes.begin(), nodes.end(), compare);
      auto nodes_set_with_lca = nodes_set;

      // pre orderでの全ての隣接nodeのLCAを求める
      for (auto itr = nodes_set_with_lca.begin();
           std::next(itr) != nodes_set_with_lca.end(); ++itr) {
        nodes_set_with_lca.emplace(hld.lca(*itr, *std::next(itr)));
      }

      // 座標圧縮
      int at_size = nodes_set_with_lca.size();
      for (int i = 0; auto x : nodes_set_with_lca) {
        compres_map[x] = i;
        ++i;
      }

      // LCAを含めた全てのnodeで子孫関係を保って辺を張る
      std::stack<int> stk;
      Graph<Node, Cost> auxiliary_tree(at_size);
      for (auto nd : nodes_set_with_lca) {
        while (!stk.empty() && hld.lca(stk.top(), nd) != stk.top()) {
          stk.pop();
        }
        if (!stk.empty()) {
          auto f = compres_map[stk.top()];
          auto t = compres_map[nd];
          auto c = depth_cost[stk.top()] + depth_cost[nd] -
                   depth_cost[hld.lca(stk.top(), nd)] * 2;
          auxiliary_tree.addEdgeUndirected(f, t, c);
        }
        stk.emplace(nd);
      }
      return auxiliary_tree;
    }
  };
}  // namespace mtd
