#pragma once
#include <unordered_map>
#include <vector>

#include "../../Algebraic/Monoid.hpp"
#include "../../Graph/Normal/BFS.hpp"
#include "../../Graph/Tree/TreeDP.hpp"

namespace mtd {
  /*
   * Monoid: 部分木の情報
   * edge_f: 辺の情報を親に流す関数: (M, f, t, c) -> M
   * node_f: 子の情報を親に流す関数: (M, i) -> M
   */
  template <monoid Monoid, class Node, class Cost, class Lambda1, class Lambda2>
  auto reRootingDP(const Graph<Node, Cost>& graph, const Lambda1& edge_f,
                   const Lambda2& node_f) {
    constexpr int root = 0;
    auto n = graph.size();

    // <辺情報を考慮したMonoidの2項演算>
    auto merge = [&](Monoid& m1, const Monoid& m2, Node f = -1, Node t = -1,
                     const Cost& c = Cost()) {
      m1 = m1.binaryOperation((f == -1 || t == -1) ? m2 : edge_f(m2, f, t, c));
    };

    // <node:toを根とした木で全てマージした解を求める>
    std::vector<std::vector<std::tuple<Monoid, Node, Cost>>> partial(n);
    auto all_merge = [&](Node to) {
      Monoid val{};
      for (const auto& [ad, from, cost] : partial[to]) {
        merge(val, ad, from, to, cost);
      }
      return node_f(val, to);
    };

    // <node:toを根とした木でfrom以外マージした解を求める>
    std::vector<std::unordered_map<Node, Monoid>> partial_ac(n);
    std::vector<Monoid> ret_m(n);
    auto accumulation = [&](Node to) {
      // 左からマージ
      Monoid val_ord{};
      for (const auto& [ad, from, cost] : partial[to]) {
        partial_ac[to].emplace(from, val_ord);
        merge(val_ord, ad, from, to, cost);
      }
      // 右からマージ
      Monoid val_rord{};
      for (auto rit = partial[to].rbegin(); rit != partial[to].rend(); ++rit) {
        auto [ad, from, cost] = *rit;
        merge(partial_ac[to][from], val_rord, cost);
        merge(val_rord, ad, from, to, cost);
      }
      // node情報を反映させて値を確定
      ret_m[to] = node_f(val_ord, to);
      for (auto&& [_, pac] : partial_ac[to]) { pac = node_f(pac, to); }
    };

    // rootを根とした解を求める
    treeDP(graph, root, [&](Node f, Node t, const Cost& c) {
      partial[t].emplace_back(all_merge(f), f, c);
    });
    accumulation(0);

    // rootからbfsして各nodeを根とした解を求める
    bfs(graph, root, [&](Node f, Node t, const Cost& c) {
      partial[t].emplace_back(partial_ac[f][t], f, c);
      accumulation(t);
    });

    std::vector<typename Monoid::value_type> ret;
    for (const auto x : ret_m) { ret.emplace_back(x.m_val); }
    return ret;
  }
}  // namespace mtd
