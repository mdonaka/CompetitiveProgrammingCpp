---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DisjointSetUnion.hpp
    title: Library/DataStructure/DisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Kruskal.test.cpp
    title: Test/Graph/Normal/Kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/Kruskal.hpp\"\n\r\n#include <queue>\r\
    \n\r\n#line 2 \"Library/DataStructure/DisjointSetUnion.hpp\"\n\r\n#include <iostream>\r\
    \n#include <numeric>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n\r\n  template\
    \ <class T = int>\r\n  class PotentialDisjointSetUnion {\r\n    std::vector<int>\
    \ m_root;\r\n    std::vector<int> m_rank;\r\n    std::vector<int> m_size;\r\n\
    \    std::vector<T> m_potential;\r\n\r\n  public:\r\n    PotentialDisjointSetUnion()\
    \ = delete;\r\n    PotentialDisjointSetUnion(int n)\r\n        : m_root(n), m_rank(n),\
    \ m_size(n, 1), m_potential(n) {\r\n      std::iota(m_root.begin(), m_root.end(),\
    \ 0);\r\n    }\r\n\r\n    auto unite(int x, int y, T p = 0) {\r\n      p += potential(x);\r\
    \n      p -= potential(y);\r\n      x = root(x);\r\n      y = root(y);\r\n   \
    \   if (x == y) { return false; }\r\n      if (m_rank[x] < m_rank[y]) {\r\n  \
    \      std::swap(x, y);\r\n        p = -p;\r\n      }\r\n      if (m_rank[x] ==\
    \ m_rank[y]) { ++m_rank[x]; }\r\n      m_size[x] = m_size[y] = size(x) + size(y);\r\
    \n      m_root[y] = x;\r\n      m_potential[y] = p;\r\n      return true;\r\n\
    \    }\r\n\r\n    auto root(int x) -> int {\r\n      if (m_root[x] == x) { return\
    \ x; }\r\n      int r = root(m_root[x]);\r\n      m_potential[x] += m_potential[m_root[x]];\r\
    \n      return m_root[x] = r;\r\n    }\r\n\r\n    auto potential(int x) -> T {\r\
    \n      root(x);\r\n      return m_potential[x];\r\n    }\r\n\r\n    auto size(int\
    \ x) -> int {\r\n      if (m_root[x] == x) { return m_size[x]; }\r\n      return\
    \ size(m_root[x] = root(m_root[x]));\r\n    }\r\n\r\n    auto isSame(int x, int\
    \ y) { return root(x) == root(y); }\r\n\r\n    auto diff(int x, int y) { return\
    \ potential(y) - potential(x); }\r\n\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os,\r\n                                    const PotentialDisjointSetUnion&\
    \ dsu) {\r\n      for (const auto& x : dsu.m_root) { os << x << \" \"; }\r\n \
    \     return os;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 2 \"Library/Graph/Graph.hpp\"\
    \n#include <deque>\r\n#line 4 \"Library/Graph/Graph.hpp\"\n#include <ranges>\r\
    \n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\n\r\nnamespace mtd {\r\
    \n  template <class Node = long long, class Cost = long long>\r\n  class Graph\
    \ {\r\n    using Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\n  public:\r\
    \n    Graph(int n) : m_n(n), m_graph(n) {}\r\n    Graph(const std::vector<Edges>&\
    \ edges)\r\n        : m_n(edges.size()), m_graph(edges) {}\r\n    Graph(int n,\
    \ const std::vector<std::tuple<Node, Node>>& edges,\r\n          bool is_arc =\
    \ false, bool is_index1 = true)\r\n        : Graph<Node, Cost>(n) {\r\n      for\
    \ (auto [u, v] : edges) {\r\n        u -= is_index1;\r\n        v -= is_index1;\r\
    \n        if (is_arc) {\r\n          addArc(u, v);\r\n        } else {\r\n   \
    \       addEdge(u, v);\r\n        }\r\n      }\r\n    }\r\n    Graph(int n, const\
    \ std::vector<std::tuple<Node, Node, Cost>>& edges,\r\n          bool is_arc =\
    \ false, bool is_index1 = true)\r\n        : Graph<Node, Cost>(n) {\r\n      for\
    \ (auto [u, v, c] : edges) {\r\n        u -= is_index1;\r\n        v -= is_index1;\r\
    \n        if (is_arc) {\r\n          addArc(u, v, c);\r\n        } else {\r\n\
    \          addEdge(u, v, c);\r\n        }\r\n      }\r\n    }\r\n\r\n    auto\
    \ addEdge(const Node& f, const Node& t, const Cost& c = 1) {\r\n      addArc(f,\
    \ t, c);\r\n      addArc(t, f, c);\r\n    }\r\n    auto addArc(const Node& f,\
    \ const Node& t, const Cost& c = 1) {\r\n      m_graph[f].emplace_back(t, c);\r\
    \n    }\r\n    auto getEdges(const Node& from) const {\r\n      class EdgesRange\
    \ {\r\n        const typename Edges::const_iterator b, e;\r\n\r\n      public:\r\
    \n        EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end()) {}\r\
    \n        auto begin() const { return b; }\r\n        auto end() const { return\
    \ e; }\r\n      };\r\n      return EdgesRange(m_graph[from]);\r\n    }\r\n   \
    \ auto getEdges() const {\r\n      std::deque<std::tuple<Node, Node, Cost>> edges;\r\
    \n      for (Node from : std::views::iota(0, m_n)) {\r\n        for (const auto&\
    \ [to, c] : getEdges(from)) {\r\n          edges.emplace_back(from, to, c);\r\n\
    \        }\r\n      }\r\n      return edges;\r\n    }\r\n    auto getEdgesExcludeCost()\
    \ const {\r\n      std::deque<std::pair<Node, Node>> edges;\r\n      for (Node\
    \ from : std::views::iota(0, m_n)) {\r\n        for (const auto& [to, _] : getEdges(from))\
    \ {\r\n          edges.emplace_back(from, to);\r\n        }\r\n      }\r\n   \
    \   return edges;\r\n    }\r\n    auto reverse() const {\r\n      auto rev = Graph<Node,\
    \ Cost>(m_n);\r\n      for (const auto& [from, to, c] : getEdges()) { rev.addArc(to,\
    \ from, c); }\r\n      return rev;\r\n    }\r\n    auto size() const { return\
    \ m_n; };\r\n    auto debug(bool directed = false) const {\r\n      for (const\
    \ auto& [f, t, c] : getEdges()) {\r\n        if (f < t || directed) {\r\n    \
    \      std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n      \
    \  }\r\n      }\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Graph/Normal/Kruskal.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class Node, class Cost>\r\n  auto kruskal(const\
    \ Graph<Node, Cost>& graph) {\r\n    auto n = graph.size();\r\n    auto min_spanning_tree\
    \ = Graph<Node, Cost>(n);\r\n\r\n    auto dsu = PotentialDisjointSetUnion(n);\r\
    \n    using Type = std::pair<Cost, std::pair<Node, Node>>;\r\n    std::priority_queue<Type,\
    \ std::vector<Type>, std::greater<Type>> q;\r\n    for (const auto& [f, t, c]\
    \ : graph.getEdges()) {\r\n      q.emplace(c, std::make_pair(f, t));\r\n    }\r\
    \n\r\n    while (!q.empty()) {\r\n      auto [cost, ft] = q.top();\r\n      auto\
    \ [from, to] = ft;\r\n      q.pop();\r\n      if (dsu.isSame(from, to)) { continue;\
    \ }\r\n      dsu.unite(from, to);\r\n      min_spanning_tree.addEdge(from, to,\
    \ cost);\r\n    }\r\n\r\n    return min_spanning_tree;\r\n  }\r\n}  // namespace\
    \ mtd\r\n"
  code: "#pragma once\r\n\r\n#include <queue>\r\n\r\n#include \"./../../DataStructure/DisjointSetUnion.hpp\"\
    \r\n#include \"./../Graph.hpp\"\r\n\r\nnamespace mtd {\r\n  template <class Node,\
    \ class Cost>\r\n  auto kruskal(const Graph<Node, Cost>& graph) {\r\n    auto\
    \ n = graph.size();\r\n    auto min_spanning_tree = Graph<Node, Cost>(n);\r\n\r\
    \n    auto dsu = PotentialDisjointSetUnion(n);\r\n    using Type = std::pair<Cost,\
    \ std::pair<Node, Node>>;\r\n    std::priority_queue<Type, std::vector<Type>,\
    \ std::greater<Type>> q;\r\n    for (const auto& [f, t, c] : graph.getEdges())\
    \ {\r\n      q.emplace(c, std::make_pair(f, t));\r\n    }\r\n\r\n    while (!q.empty())\
    \ {\r\n      auto [cost, ft] = q.top();\r\n      auto [from, to] = ft;\r\n   \
    \   q.pop();\r\n      if (dsu.isSame(from, to)) { continue; }\r\n      dsu.unite(from,\
    \ to);\r\n      min_spanning_tree.addEdge(from, to, cost);\r\n    }\r\n\r\n  \
    \  return min_spanning_tree;\r\n  }\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/DataStructure/DisjointSetUnion.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/Kruskal.hpp
  requiredBy: []
  timestamp: '2025-06-14 20:53:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Normal/Kruskal.test.cpp
documentation_of: Library/Graph/Normal/Kruskal.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/Kruskal.hpp
- /library/Library/Graph/Normal/Kruskal.hpp.html
title: Library/Graph/Normal/Kruskal.hpp
---
