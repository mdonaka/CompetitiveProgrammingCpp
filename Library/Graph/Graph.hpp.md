---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Library/Graph/Normal/StronglyConnectedComponents.hpp
    title: Library/Graph/Normal/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/WarshallFloyd.hpp
    title: Library/Graph/Normal/WarshallFloyd.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/dijkstra.hpp
    title: Library/Graph/Normal/dijkstra.hpp
  - icon: ':warning:'
    path: Library/Graph/Tree/TreeDP.hpp
    title: Library/Graph/Tree/TreeDP.hpp
  - icon: ':warning:'
    path: Test/Graph/Tree/TreeDP_test.cpp
    title: Test/Graph/Tree/TreeDP_test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Dijkstra.test.cpp
    title: Test/Graph/Normal/Dijkstra.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
    title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/WarshallFloyd.test.cpp
    title: Test/Graph/Normal/WarshallFloyd.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\n#include\
    \ <deque>\r\n\r\ntemplate<class Node = int, class Cost = long long>\r\nclass Graph\
    \ {\r\n    //using Node = int;\r\n    //using Cost = long long;\r\n    using Edge\
    \ = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n   \
    \ const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n    Graph(int\
    \ n) :m_n(n), m_graph(n) {}\r\n\r\n    auto addEdge(const Node& f, const Node&\
    \ t, const Cost& c = 1) {\r\n        m_graph[f].emplace_back(t, c);\r\n    }\r\
    \n    auto addEdgeUndirected(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n        addEdge(f, t, c); addEdge(t, f, c);\r\n    }\r\n    auto getEdges(const\
    \ Node& from)const {\r\n        class EdgesRange {\r\n            const typename\
    \ Edges::const_iterator b, e;\r\n        public:\r\n            EdgesRange(const\
    \ Edges& edges) :b(edges.begin()), e(edges.end()) {}\r\n            auto begin()const\
    \ { return b; }\r\n            auto end()const { return e; }\r\n        };\r\n\
    \        return EdgesRange(m_graph[from]);\r\n    }\r\n    auto getEdgesAll()const\
    \ {\r\n        std::deque<std::pair<Node, Edge>> edges;\r\n        for(Node from\
    \ = 0; from < m_n; ++from) for(const auto& edge : getEdges(from)) {\r\n      \
    \      edges.emplace_back(from, edge);\r\n        }\r\n        return edges;\r\
    \n    }\r\n    auto getEdgesAll2()const {\r\n        std::deque<std::pair<Node,\
    \ Node>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ [to, _] : getEdges(from)) {\r\n            edges.emplace_back(from, to);\r\n\
    \        }\r\n        return edges;\r\n    }\r\n    auto reverse()const {\r\n\
    \        auto rev = Graph<Node, Cost>(m_n);\r\n        for(const auto& [from,\
    \ edge] : getEdgesAll()) {\r\n            auto [to, c] = edge;\r\n           \
    \ rev.addEdge(to, from, c);\r\n        }\r\n        return rev;\r\n    }\r\n \
    \   auto size()const { return m_n; };\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <deque>\r\n\r\ntemplate<class\
    \ Node = int, class Cost = long long>\r\nclass Graph {\r\n    //using Node = int;\r\
    \n    //using Cost = long long;\r\n    using Edge = std::pair<Node, Cost>;\r\n\
    \    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
    \ m_graph;\r\n\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n \
    \   auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {\r\n      \
    \  m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n        addEdge(f, t, c); addEdge(t,\
    \ f, c);\r\n    }\r\n    auto getEdges(const Node& from)const {\r\n        class\
    \ EdgesRange {\r\n            const typename Edges::const_iterator b, e;\r\n \
    \       public:\r\n            EdgesRange(const Edges& edges) :b(edges.begin()),\
    \ e(edges.end()) {}\r\n            auto begin()const { return b; }\r\n       \
    \     auto end()const { return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto getEdgesAll()const {\r\n        std::deque<std::pair<Node,\
    \ Edge>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ edge : getEdges(from)) {\r\n            edges.emplace_back(from, edge);\r\n\
    \        }\r\n        return edges;\r\n    }\r\n    auto getEdgesAll2()const {\r\
    \n        std::deque<std::pair<Node, Node>> edges;\r\n        for(Node from =\
    \ 0; from < m_n; ++from) for(const auto& [to, _] : getEdges(from)) {\r\n     \
    \       edges.emplace_back(from, to);\r\n        }\r\n        return edges;\r\n\
    \    }\r\n    auto reverse()const {\r\n        auto rev = Graph<Node, Cost>(m_n);\r\
    \n        for(const auto& [from, edge] : getEdgesAll()) {\r\n            auto\
    \ [to, c] = edge;\r\n            rev.addEdge(to, from, c);\r\n        }\r\n  \
    \      return rev;\r\n    }\r\n    auto size()const { return m_n; };\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Graph.hpp
  requiredBy:
  - Library/Graph/Tree/TreeDP.hpp
  - Library/Graph/Normal/dijkstra.hpp
  - Library/Graph/Normal/WarshallFloyd.hpp
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  - Test/Graph/Tree/TreeDP_test.cpp
  timestamp: '2023-06-14 03:49:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - Test/Graph/Normal/Dijkstra.test.cpp
  - Test/Graph/Normal/WarshallFloyd.test.cpp
documentation_of: Library/Graph/Graph.hpp
layout: document
redirect_from:
- /library/Library/Graph/Graph.hpp
- /library/Library/Graph/Graph.hpp.html
title: Library/Graph/Graph.hpp
---
