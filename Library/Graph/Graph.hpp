#pragma once
#include <deque>
#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>

template <class Node = int, class Cost = long long>
class Graph {
  // using Node = int;
  // using Cost = long long;

  using Edge = std::pair<Node, Cost>;
  using Edges = std::vector<Edge>;

  const int m_n;
  std::vector<Edges> m_graph;

public:
  Graph(int n) : m_n(n), m_graph(n) {}
  Graph(const std::vector<Edges>& edges) : m_n(edges.size()), m_graph(edges) {}

  auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {
    m_graph[f].emplace_back(t, c);
  }
  auto addEdgeUndirected(const Node& f, const Node& t, const Cost& c = 1) {
    addEdge(f, t, c);
    addEdge(t, f, c);
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
    for (const auto& [from, to, c] : getEdges()) { rev.addEdge(to, from, c); }
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
