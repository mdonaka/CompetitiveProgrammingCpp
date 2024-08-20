---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/WarshallFloyd.test.cpp
    title: Test/Graph/Normal/WarshallFloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/WarshallFloyd.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n#include <iostream>\r\
    \n#include <ranges>\r\n#include <tuple>\r\n#line 7 \"Library/Graph/Graph.hpp\"\
    \n\r\ntemplate <class Node = int, class Cost = long long>\r\nclass Graph {\r\n\
    \  // using Node = int;\r\n  // using Cost = long long;\r\n\r\n  using Edge =\
    \ std::pair<Node, Cost>;\r\n  using Edges = std::vector<Edge>;\r\n\r\n  const\
    \ int m_n;\r\n  std::vector<Edges> m_graph;\r\n\r\npublic:\r\n  Graph(int n) :\
    \ m_n(n), m_graph(n) {}\r\n  Graph(const std::vector<Edges>& edges) : m_n(edges.size()),\
    \ m_graph(edges) {}\r\n\r\n  auto addEdge(const Node& f, const Node& t, const\
    \ Cost& c = 1) {\r\n    m_graph[f].emplace_back(t, c);\r\n  }\r\n  auto addEdgeUndirected(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n    addEdge(f, t, c);\r\n  \
    \  addEdge(t, f, c);\r\n  }\r\n  auto getEdges(const Node& from) const {\r\n \
    \   class EdgesRange {\r\n      const typename Edges::const_iterator b, e;\r\n\
    \r\n    public:\r\n      EdgesRange(const Edges& edges) : b(edges.begin()), e(edges.end())\
    \ {}\r\n      auto begin() const { return b; }\r\n      auto end() const { return\
    \ e; }\r\n    };\r\n    return EdgesRange(m_graph[from]);\r\n  }\r\n  auto getEdges()\
    \ const {\r\n    std::deque<std::tuple<Node, Node, Cost>> edges;\r\n    for (Node\
    \ from : std::views::iota(0, m_n)) {\r\n      for (const auto& [to, c] : getEdges(from))\
    \ {\r\n        edges.emplace_back(from, to, c);\r\n      }\r\n    }\r\n    return\
    \ edges;\r\n  }\r\n  auto getEdgesExcludeCost() const {\r\n    std::deque<std::pair<Node,\
    \ Node>> edges;\r\n    for (Node from : std::views::iota(0, m_n)) {\r\n      for\
    \ (const auto& [to, _] : getEdges(from)) {\r\n        edges.emplace_back(from,\
    \ to);\r\n      }\r\n    }\r\n    return edges;\r\n  }\r\n  auto reverse() const\
    \ {\r\n    auto rev = Graph<Node, Cost>(m_n);\r\n    for (const auto& [from, to,\
    \ c] : getEdges()) { rev.addEdge(to, from, c); }\r\n    return rev;\r\n  }\r\n\
    \  auto size() const { return m_n; };\r\n  auto debug(bool directed = false) const\
    \ {\r\n    for (const auto& [f, t, c] : getEdges()) {\r\n      if (f < t || directed)\
    \ {\r\n        std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n\
    \      }\r\n    }\r\n  }\r\n};\r\n#line 6 \"Library/Graph/Normal/WarshallFloyd.hpp\"\
    \n\ntemplate <class Node, class Cost>\nauto warshallFloyd(int n, const Graph<Node,\
    \ Cost>& graph,\n                   const Cost& lim = 1LL << 60) {\n  std::vector<std::vector<Cost>>\
    \ cost(n, std::vector<Cost>(n, lim));\n  for (const auto& [from, to, c] : graph.getEdges())\
    \ { cost[from][to] = c; }\n  for (int i = 0; i < n; ++i) { cost[i][i] = 0; }\n\
    \  for (int k = 0; k < n; ++k)\n    for (int f = 0; f < n; ++f)\n      for (int\
    \ t = 0; t < n; ++t) {\n        cost[f][t] = std::min(cost[f][t], cost[f][k] +\
    \ cost[k][t]);\n      }\n  return cost;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"./../Graph.hpp\"\n\ntemplate\
    \ <class Node, class Cost>\nauto warshallFloyd(int n, const Graph<Node, Cost>&\
    \ graph,\n                   const Cost& lim = 1LL << 60) {\n  std::vector<std::vector<Cost>>\
    \ cost(n, std::vector<Cost>(n, lim));\n  for (const auto& [from, to, c] : graph.getEdges())\
    \ { cost[from][to] = c; }\n  for (int i = 0; i < n; ++i) { cost[i][i] = 0; }\n\
    \  for (int k = 0; k < n; ++k)\n    for (int f = 0; f < n; ++f)\n      for (int\
    \ t = 0; t < n; ++t) {\n        cost[f][t] = std::min(cost[f][t], cost[f][k] +\
    \ cost[k][t]);\n      }\n  return cost;\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2024-08-20 12:47:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Normal/WarshallFloyd.test.cpp
documentation_of: Library/Graph/Normal/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/WarshallFloyd.hpp
- /library/Library/Graph/Normal/WarshallFloyd.hpp.html
title: Library/Graph/Normal/WarshallFloyd.hpp
---
