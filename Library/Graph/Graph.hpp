#pragma once
#include <deque>
#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>

namespace mtd {
  template <class Node = long long, class Cost = long long>
  class Graph {
    using Edge = std::pair<Node, Cost>;
    using Edges = std::vector<Edge>;

    const int m_n;
    std::vector<Edges> m_graph;

  public:
    Graph(int n) : m_n(n), m_graph(n) {}
    Graph(const std::vector<Edges>& edges)
        : m_n(edges.size()), m_graph(edges) {}
    Graph(int n, const std::vector<std::tuple<Node, Node>>& edges,
          bool is_arc = false, bool is_index1 = true)
        : Graph<Node, Cost>(n) {
      for (auto [u, v] : edges) {
        u -= is_index1;
        v -= is_index1;
        if (is_arc) {
          addArc(u, v);
        } else {
          addEdge(u, v);
        }
      }
    }
    Graph(int n, const std::vector<std::tuple<Node, Node, Cost>>& edges,
          bool is_arc = false, bool is_index1 = true)
        : Graph<Node, Cost>(n) {
      for (auto [u, v, c] : edges) {
        u -= is_index1;
        v -= is_index1;
        if (is_arc) {
          addArc(u, v, c);
        } else {
          addEdge(u, v, c);
        }
      }
    }

    auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {
      addArc(f, t, c);
      addArc(t, f, c);
    }
    auto addArc(const Node& f, const Node& t, const Cost& c = 1) {
      m_graph[f].emplace_back(t, c);
    }
    auto getEdges(const Node& from) const {
      class EdgesRange {
        const typename Edges::const_iterator b, e;

      public:
        EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end()) {}
        auto begin() const { return b; }
        auto end() const { return e; }
      };
      return EdgesRange(m_graph[from]);
    }
    auto getEdges() const {
      std::deque<std::tuple<Node, Node, Cost>> edges;
      for (Node from : std::views::iota(0, m_n)) {
        for (const auto& [to, c] : getEdges(from)) {
          edges.emplace_back(from, to, c);
        }
      }
      return edges;
    }
    auto getEdgesExcludeCost() const {
      std::deque<std::pair<Node, Node>> edges;
      for (Node from : std::views::iota(0, m_n)) {
        for (const auto& [to, _] : getEdges(from)) {
          edges.emplace_back(from, to);
        }
      }
      return edges;
    }
    auto reverse() const {
      auto rev = Graph<Node, Cost>(m_n);
      for (const auto& [from, to, c] : getEdges()) { rev.addArc(to, from, c); }
      return rev;
    }
    auto size() const { return m_n; };
    auto debug(bool directed = false) const {
      for (const auto& [f, t, c] : getEdges()) {
        if (f < t || directed) {
          std::cout << f << " -> " << t << ": " << c << std::endl;
        }
      }
    }
  };
}  // namespace mtd
