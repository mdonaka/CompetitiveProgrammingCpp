#pragma once

#include <algorithm>
#include <concepts>
#include <ranges>
#include <set>
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
    const std::vector<Node> m_group;

    template <class F>
    constexpr static inline auto dfs(const Graph<Node, Cost>& graph, Node from,
                                     std::vector<bool>& is_used, const F& f)
        -> void {
      is_used[from] = true;
      for (const auto& [to, _] : graph.getEdges(from)) {
        if (is_used[to]) { continue; }
        dfs(graph, to, is_used, f);
      }
      f(from);
    }

    constexpr static auto constructGroup(const Graph<Node, Cost>& graph) {
      int n = graph.size();
      std::vector<Node> order;
      std::vector<bool> is_used(n);
      for (auto from : std::views::iota(0, n)) {
        if (is_used[from]) { continue; }
        dfs(graph, from, is_used, [&](auto f) { order.emplace_back(f); });
      }

      int g = 0;
      std::vector<Node> group(n);
      std::vector<bool> is_used2(n);
      auto rev = graph.reverse();
      for (auto from : order | std::views::reverse) {
        if (is_used2[from]) { continue; }
        dfs(rev, from, is_used2, [&](auto f) { group[f] = g; });
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

    constexpr auto size() const {
      return *std::max_element(m_group.begin(), m_group.end()) + 1;
    }
    constexpr auto group(Node a) const { return m_group[a]; }
    constexpr auto isSameGroup(Node a, Node b) const {
      return m_group[a] == m_group[b];
    }
    constexpr auto getGroupNodes() const {
      std::vector<std::vector<Node>> groupNodes(size());
      for (int gi = 0; gi < m_graph.size(); ++gi) {
        groupNodes[m_group[gi]].emplace_back(gi);
      }
      return groupNodes;
    }
    constexpr auto getGroupGraph() const {
      std::unordered_set<std::pair<Node, Node>, HashPair> st;
      st.reserve(m_graph.size());
      for (int f = 0; f < m_graph.size(); ++f) {
        for (const auto& [t, _] : m_graph.getEdges(f)) {
          if (!isSameGroup(f, t)) { st.emplace(m_group[f], m_group[t]); }
        }
      }
      Graph<Node, Cost> ret(size());
      for (const auto& [f, t] : st) { ret.addArc(f, t); }
      return ret;
    }
  };
}  // namespace mtd
