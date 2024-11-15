#pragma once

#include <algorithm>
#include <ranges>
#include <unordered_set>
#include <vector>

#include "./../Graph.hpp"

namespace mtd {
  template <class Node, class Cost>
  class StronglyConnectedComponents {
    struct HashPair {
      template <class T1, class T2>
      size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
      }
    };

    const Graph<Node, Cost> m_graph;
    const std::vector<int> m_group;

    template <class F>
    constexpr static inline auto dfs(const Graph<Node, Cost>& graph, int from,
                                     std::vector<bool>& is_used, const F& f)
        -> void {
      std::vector<Node> stk{from};
      is_used[from] = true;
      while (!stk.empty()) {
        auto fr = stk.back();
        stk.pop_back();
        f(fr);
        for (const auto& [to, _] : graph.getEdges(fr)) {
          if (is_used[to]) { continue; }
          is_used[to] = true;
          stk.emplace_back(to);
        }
      }
    }

    constexpr static auto constructGroup(const Graph<Node, Cost>& graph) {
      int n = graph.size();
      std::vector<Node> order;
      std::vector<bool> is_used(n);
      for (auto from : std::views::iota(0, n)) {
        if (is_used[from]) { continue; }
        dfs(graph, from, is_used, [&](int f) { order.emplace_back(f); });
      }

      int g = 0;
      std::vector<Node> group(n);
      std::vector<bool> is_used2(n);
      auto rev = graph.reverse();
      for (auto from : order) {
        if (is_used2[from]) { continue; }
        dfs(rev, from, is_used2, [&](int f) { group[f] = g; });
        ++g;
      }
      return group;
    }

  public:
    [[deprecated]] constexpr StronglyConnectedComponents(
        const Graph<Node, Cost>& graph)
        : m_graph(graph), m_group(constructGroup(m_graph)) {}
    // graphのコピーコストが大きいのでこっち推奨
    constexpr StronglyConnectedComponents(Graph<Node, Cost>&& graph)
        : m_graph(std::move(graph)), m_group(constructGroup(m_graph)) {}

    constexpr auto isSameGroup(int a, int b) const {
      return m_group[a] == m_group[b];
    }
    constexpr auto getGroupNodes() const {
      auto size = *std::max_element(m_group.begin(), m_group.end()) + 1;
      std::vector<std::vector<int>> groupNodes(size);
      for (int gi = 0; gi < m_graph.size(); ++gi) {
        groupNodes[m_group[gi]].emplace_back(gi);
      }
      return groupNodes;
    }
    constexpr auto getGroupGraph() const {
      std::unordered_set<std::pair<int, int>, HashPair> st;
      st.reserve(m_graph.size());
      for (int f = 0; f < m_graph.size(); ++f) {
        for (const auto& [t, _] : m_graph.getEdges(f)) {
          if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }
        }
      }
      Graph<Node, Cost> ret(m_graph.size());
      for (const auto& [f, t] : st) { ret.addEdge(f, t); }
      return ret;
    }
  };
}  // namespace mtd
