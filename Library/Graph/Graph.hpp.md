---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Flow/Dinic.hpp
    title: Library/Graph/Flow/Dinic.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Flow/FordFulkerson.hpp
    title: Library/Graph/Flow/FordFulkerson.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Flow/SuccessiveShortestPath.hpp
    title: Library/Graph/Flow/SuccessiveShortestPath.hpp
  - icon: ':question:'
    path: Library/Graph/Normal/BFS.hpp
    title: Library/Graph/Normal/BFS.hpp
  - icon: ':x:'
    path: Library/Graph/Normal/Kruskal.hpp
    title: Library/Graph/Normal/Kruskal.hpp
  - icon: ':x:'
    path: Library/Graph/Normal/Prim.hpp
    title: Library/Graph/Normal/Prim.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/StronglyConnectedComponents.hpp
    title: Library/Graph/Normal/StronglyConnectedComponents.hpp
  - icon: ':x:'
    path: Library/Graph/Normal/WarshallFloyd.hpp
    title: Library/Graph/Normal/WarshallFloyd.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/dijkstra.hpp
    title: Library/Graph/Normal/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/AuxiliaryTree.hpp
    title: Library/Graph/Tree/AuxiliaryTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/HeavyLightDecomposition.hpp
    title: Library/Graph/Tree/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/LowestCommonAncestor.hpp
    title: Library/Graph/Tree/LowestCommonAncestor.hpp
  - icon: ':warning:'
    path: Library/Graph/Tree/ReRootingDP.hpp
    title: Library/Graph/Tree/ReRootingDP.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/TreeDP.hpp
    title: Library/Graph/Tree/TreeDP.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Flow/Dinic.test.cpp
    title: Test/Graph/Flow/Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Flow/FordFulkerson.test.cpp
    title: Test/Graph/Flow/FordFulkerson.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Flow/SuccessiveShortestPath.test.cpp
    title: Test/Graph/Flow/SuccessiveShortestPath.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/BFS.test.cpp
    title: Test/Graph/Normal/BFS.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Dijkstra.test.cpp
    title: Test/Graph/Normal/Dijkstra.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/Kruskal.test.cpp
    title: Test/Graph/Normal/Kruskal.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/Prim.test.cpp
    title: Test/Graph/Normal/Prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
    title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/WarshallFloyd.test.cpp
    title: Test/Graph/Normal/WarshallFloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/AuxiliaryTree.test.cpp
    title: Test/Graph/Tree/AuxiliaryTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/LowestCommonAncestor.test.cpp
    title: Test/Graph/Tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/TreeDP.test.cpp
    title: Test/Graph/Tree/TreeDP.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\n#include\
    \ <deque>\r\n\r\ntemplate<class Node = int, class Cost = long long>\r\nclass Graph\
    \ {\r\n    //using Node = int;\r\n    //using Cost = long long;\r\n\r\n    using\
    \ Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n\
    \    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n    Graph(int\
    \ n) :m_n(n), m_graph(n) {}\r\n\r\n    auto addEdge(const Node& f, const Node&\
    \ t, const Cost& c = 1) {\r\n        m_graph[f].emplace_back(t, c);\r\n    }\r\
    \n    auto addEdgeUndirected(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n        addEdge(f, t, c); addEdge(t, f, c);\r\n    }\r\n    auto getEdges(const\
    \ Node& from)const {\r\n        class EdgesRange {\r\n            const typename\
    \ Edges::const_iterator b, e;\r\n        public:\r\n            EdgesRange(const\
    \ Edges& edges) :b(edges.begin()), e(edges.end()) {}\r\n            auto begin()const\
    \ { return b; }\r\n            auto end()const { return e; }\r\n        };\r\n\
    \        return EdgesRange(m_graph[from]);\r\n    }\r\n    auto getEdges()const\
    \ {\r\n        std::deque<std::tuple<Node, Node, Cost>> edges;\r\n        for(Node\
    \ from = 0; from < m_n; ++from) for(const auto& [to, c] : getEdges(from)) {\r\n\
    \            edges.emplace_back(from, to, c);\r\n        }\r\n        return edges;\r\
    \n    }\r\n    auto getEdgesExcludeCost()const {\r\n        std::deque<std::pair<Node,\
    \ Node>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ [to, _] : getEdges(from)) {\r\n            edges.emplace_back(from, to);\r\n\
    \        }\r\n        return edges;\r\n    }\r\n    auto reverse()const {\r\n\
    \        auto rev = Graph<Node, Cost>(m_n);\r\n        for(const auto& [from,\
    \ to, c] : getEdges()) {\r\n            rev.addEdge(to, from, c);\r\n        }\r\
    \n        return rev;\r\n    }\r\n    auto size()const { return m_n; };\r\n  \
    \  auto debug(bool directed = false)const {\r\n        for(const auto& [f, t,\
    \ c] : getEdges())if(f < t || directed) {\r\n            std::cout << f << \"\
    \ -> \" << t << \": \" << c << std::endl;\r\n        }\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <deque>\r\n\r\ntemplate<class\
    \ Node = int, class Cost = long long>\r\nclass Graph {\r\n    //using Node = int;\r\
    \n    //using Cost = long long;\r\n\r\n    using Edge = std::pair<Node, Cost>;\r\
    \n    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges>\
    \ m_graph;\r\n\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n \
    \   auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {\r\n      \
    \  m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n        addEdge(f, t, c); addEdge(t,\
    \ f, c);\r\n    }\r\n    auto getEdges(const Node& from)const {\r\n        class\
    \ EdgesRange {\r\n            const typename Edges::const_iterator b, e;\r\n \
    \       public:\r\n            EdgesRange(const Edges& edges) :b(edges.begin()),\
    \ e(edges.end()) {}\r\n            auto begin()const { return b; }\r\n       \
    \     auto end()const { return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto getEdges()const {\r\n        std::deque<std::tuple<Node, Node,\
    \ Cost>> edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto&\
    \ [to, c] : getEdges(from)) {\r\n            edges.emplace_back(from, to, c);\r\
    \n        }\r\n        return edges;\r\n    }\r\n    auto getEdgesExcludeCost()const\
    \ {\r\n        std::deque<std::pair<Node, Node>> edges;\r\n        for(Node from\
    \ = 0; from < m_n; ++from) for(const auto& [to, _] : getEdges(from)) {\r\n   \
    \         edges.emplace_back(from, to);\r\n        }\r\n        return edges;\r\
    \n    }\r\n    auto reverse()const {\r\n        auto rev = Graph<Node, Cost>(m_n);\r\
    \n        for(const auto& [from, to, c] : getEdges()) {\r\n            rev.addEdge(to,\
    \ from, c);\r\n        }\r\n        return rev;\r\n    }\r\n    auto size()const\
    \ { return m_n; };\r\n    auto debug(bool directed = false)const {\r\n       \
    \ for(const auto& [f, t, c] : getEdges())if(f < t || directed) {\r\n         \
    \   std::cout << f << \" -> \" << t << \": \" << c << std::endl;\r\n        }\r\
    \n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Graph.hpp
  requiredBy:
  - Library/Graph/Tree/TreeDP.hpp
  - Library/Graph/Tree/AuxiliaryTree.hpp
  - Library/Graph/Tree/LowestCommonAncestor.hpp
  - Library/Graph/Tree/HeavyLightDecomposition.hpp
  - Library/Graph/Tree/ReRootingDP.hpp
  - Library/Graph/Flow/FordFulkerson.hpp
  - Library/Graph/Flow/SuccessiveShortestPath.hpp
  - Library/Graph/Flow/Dinic.hpp
  - Library/Graph/Normal/Kruskal.hpp
  - Library/Graph/Normal/StronglyConnectedComponents.hpp
  - Library/Graph/Normal/BFS.hpp
  - Library/Graph/Normal/dijkstra.hpp
  - Library/Graph/Normal/Prim.hpp
  - Library/Graph/Normal/WarshallFloyd.hpp
  timestamp: '2024-07-18 22:46:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Graph/Tree/HeavyLightDecomposition_LCA.test.cpp
  - Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  - Test/Graph/Tree/LowestCommonAncestor.test.cpp
  - Test/Graph/Tree/TreeDP.test.cpp
  - Test/Graph/Tree/AuxiliaryTree.test.cpp
  - Test/Graph/Flow/SuccessiveShortestPath.test.cpp
  - Test/Graph/Flow/FordFulkerson.test.cpp
  - Test/Graph/Flow/Dinic.test.cpp
  - Test/Graph/Normal/Prim.test.cpp
  - Test/Graph/Normal/BFS.test.cpp
  - Test/Graph/Normal/WarshallFloyd.test.cpp
  - Test/Graph/Normal/Dijkstra.test.cpp
  - Test/Graph/Normal/Kruskal.test.cpp
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
documentation_of: Library/Graph/Graph.hpp
layout: document
redirect_from:
- /library/Library/Graph/Graph.hpp
- /library/Library/Graph/Graph.hpp.html
title: Library/Graph/Graph.hpp
---
