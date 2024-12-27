#pragma once

#include <queue>
#include <stack>
#include <unordered_map>

#include "../Graph.hpp"

namespace mtd {
  template <class Node, class Cost>
  class HeavyLightDecomposition {
    using GraphOrderd = std::unordered_map<Node, std::deque<Node>>;

    const Node m_n;
    const std::vector<Node> m_size;
    const GraphOrderd m_tree;
    const std::vector<Node> m_height;
    const std::vector<std::pair<Node, Node>> m_root_par;
    const std::vector<Node> m_ids;
    const std::vector<Node> m_order;
    const std::vector<Node> m_edge_ids;

    static auto constructGraph(const Graph<Node, Cost>& tree) {
      auto n = tree.size();
      std::deque<std::pair<Node, Node>> order;
      std::vector<Node> used(n);
      std::stack<std::pair<Node, Node>> stk;
      stk.emplace(0, -1);
      used[0] = true;
      while (!stk.empty()) {
        auto [f, p] = stk.top();
        order.emplace_front(f, p);
        stk.pop();
        for (const auto& [t, _] : tree.getEdges(f)) {
          if (used[t]) {
            continue;
            ;
          }
          used[t] = true;
          stk.emplace(t, f);
        }
      }

      std::vector<Node> size(n, 1);
      GraphOrderd hld_tree;
      for (const auto& [f, p] : order) {
        Node size_sum = 1;
        Node size_max = 0;
        std::deque<Node> to_list;
        for (const auto& [t, _] : tree.getEdges(f)) {
          if (t == p) { continue; }
          if (size[t] > size_max) {
            size_max = size[t];
            to_list.emplace_back(t);
          } else {
            to_list.emplace_front(t);
          }
          size_sum += size[t];
        }
        if (!to_list.empty()) { hld_tree.emplace(f, to_list); }
        size[f] = size_sum;
      }
      return hld_tree;
    }

    static auto constructSize(const Graph<Node, Cost>& tree) {
      auto n = tree.size();
      std::deque<std::pair<Node, Node>> order;
      std::vector<Node> used(n);
      std::stack<std::pair<Node, Node>> stk;
      stk.emplace(0, -1);
      used[0] = true;
      while (!stk.empty()) {
        auto [f, p] = stk.top();
        order.emplace_front(f, p);
        stk.pop();
        for (const auto& [t, _] : tree.getEdges(f)) {
          if (used[t]) {
            continue;
            ;
          }
          used[t] = true;
          stk.emplace(t, f);
        }
      }

      std::vector<Node> size(n, 1);
      for (const auto& [f, p] : order) {
        Node size_sum = 1;
        for (const auto& [t, _] : tree.getEdges(f)) {
          if (t == p) { continue; }
          size_sum += size[t];
        }
        size[f] = size_sum;
      }
      return size;
    }

    static auto constructRootPar(Node n, const GraphOrderd& tree) {
      std::vector<std::pair<Node, Node>> root_par(n);
      std::stack<std::tuple<Node, Node, Node>> stk;
      stk.emplace(0, 0, -1);
      while (!stk.empty()) {
        auto [f, root, par] = stk.top();
        stk.pop();

        if (tree.find(f) == tree.end()) {
          root_par[f] = {root, par};
          continue;
        }
        auto itr = tree.at(f).rbegin();
        stk.emplace(*itr, root, par);
        root_par[f] = {root, par};
        for (++itr; itr != tree.at(f).rend(); ++itr) {
          stk.emplace(*itr, *itr, f);
        }
      }
      return root_par;
    }
    static auto constructHeight(Node n, const GraphOrderd& tree) {
      std::vector<Node> height(n);
      std::queue<Node> q;
      q.emplace(0);
      while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (tree.find(f) == tree.end()) { continue; }
        for (const auto& t : tree.at(f)) {
          height[t] = height[f] + 1;
          q.emplace(t);
        }
      }
      return height;
    }

    auto constructIds() const {
      std::vector<Node> ids(m_n);
      Node val = 0;
      std::stack<Node> stk;
      stk.emplace(0);
      while (!stk.empty()) {
        auto f = stk.top();
        stk.pop();
        ids[f] = val;
        ++val;
        if (m_tree.find(f) == m_tree.end()) { continue; }
        for (const auto& t : m_tree.at(f)) { stk.emplace(t); }
      }
      return ids;
    }

    auto constructOrder() const {
      std::vector<Node> order(m_n);
      for (int i = 0; i < m_n; ++i) { order[m_ids[i]] = i; }
      return order;
    }
    /*
     * 辺をnodeとして拡張した場合の辺nodeだけIDを振る
     * (1) - (2)
     * (1) - (e) - (2)
     * [-1, -1, 0]
     */
    auto constructEdgeIds() const {
      Node edge_size = (m_n >> 1);
      std::vector<Node> edge_ids(m_n, -1);
      Node val = 0;
      std::stack<Node> stk;
      stk.emplace(0);
      while (!stk.empty()) {
        auto f = stk.top();
        stk.pop();
        if (f > edge_size) {
          edge_ids[f] = val;
          ++val;
        }
        if (m_tree.find(f) == m_tree.end()) { continue; }
        for (const auto& t : m_tree.at(f)) { stk.emplace(t); }
      }
      return edge_ids;
    }

  public:
    HeavyLightDecomposition(const Graph<Node, Cost>& tree)
        : m_n(tree.size()),
          m_size(constructSize(tree)),
          m_tree(constructGraph(tree)),
          m_root_par(constructRootPar(m_n, m_tree)),
          m_height(constructHeight(m_n, m_tree)),
          m_ids(constructIds()),
          m_order(constructOrder()),
          m_edge_ids(constructEdgeIds()) {}

    auto getId(Node i) const { return m_ids[i]; }
    auto getEdgeId(Node i) const { return m_edge_ids[i]; }
    auto getOrder(Node i) const { return m_order[i]; }

    auto lca(Node f, Node t) const {
      do {
        auto [fr, fp] = m_root_par[f];
        auto [tr, tp] = m_root_par[t];
        if (fr == tr) { break; }
        auto fph = (fp > -1) ? m_height[fp] : -1;
        auto tph = (tp > -1) ? m_height[tp] : -1;
        if (fph < tph) {
          t = tp;
        } else {
          f = fp;
        }
      } while (true);
      return (m_height[f] < m_height[t]) ? f : t;
    }

    auto range(Node f, Node t) const {
      std::deque<std::pair<Node, Node>> ret;
      auto add = [&](Node from, Node to) {
        auto l = std::min(m_ids[from], m_ids[to]);
        auto r = std::max(m_ids[from], m_ids[to]);
        ret.emplace_back(l, r);
      };
      do {
        auto [fr, fp] = m_root_par[f];
        auto [tr, tp] = m_root_par[t];
        if (fr == tr) {
          add(f, t);
          break;
        }
        auto fph = (fp > -1) ? m_height[fp] : -1;
        auto tph = (tp > -1) ? m_height[tp] : -1;
        if (fph < tph) {
          add(t, tr);
          t = tp;
        } else {
          add(f, fr);
          f = fp;
        }
      } while (true);
      return ret;
    }

    auto rangeEdge(Node f, Node t) const {
      Node edge_size = (m_n >> 1);
      std::deque<std::pair<Node, Node>> ret;
      auto add = [&](Node from, Node to) {
        auto l = std::min(m_ids[from], m_ids[to]);
        auto r = std::max(m_ids[from], m_ids[to]);
        if (m_order[l] <= edge_size) { ++l; }
        if (m_order[r] <= edge_size) { --r; }
        if (l > r) { return; }
        auto edge_l = m_edge_ids[m_order[l]];
        auto edge_r = m_edge_ids[m_order[r]];
        ret.emplace_back(edge_l, edge_r);
      };
      do {
        auto [fr, fp] = m_root_par[f];
        auto [tr, tp] = m_root_par[t];
        if (fr == tr) {
          add(f, t);
          break;
        }
        auto fph = (fp > -1) ? m_height[fp] : -1;
        auto tph = (tp > -1) ? m_height[tp] : -1;
        if (fph < tph) {
          add(t, tr);
          t = tp;
        } else {
          add(f, fr);
          f = fp;
        }
      } while (true);
      return ret;
    }

    auto rangeSubTree(Node f) const {
      return std::pair<Node, Node>{m_ids[f], m_ids[f] + m_size[f] - 1};
    }
  };
}  // namespace mtd
