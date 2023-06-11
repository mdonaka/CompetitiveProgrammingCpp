---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Library/Graph/Normal/dijkstra.hpp
    title: Library/Graph/Normal/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Graph/Normal/dijkstra.test.cpp
    title: Test/Graph/Normal/dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\n#include\
    \ <type_traits>\r\n\r\ntemplate<class Node = int, class Cost = long long>\r\n\
    class Graph {\r\n    //using Node = int;\r\n    //using Cost = long long;\r\n\
    \    using Edges = std::vector<std::pair<Node, Cost>>;\r\n\r\n    const int m_n;\r\
    \n    std::vector<Edges> m_graph;\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n)\
    \ {}\r\n\r\n    auto addEdge(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n        m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
    \ Node& f, const Node& t, const Cost& c = 1) {\r\n        addEdge(f, t, c); addEdge(t,\
    \ f, c);\r\n    }\r\n    const auto& getEdges(const Node& from)const {\r\n   \
    \     class EdgesRange {\r\n            const Edges::const_iterator b, e;\r\n\
    \        public:\r\n            EdgesRange(const Edges& edges) :b(edges.begin()),\
    \ e(edges.end()) {}\r\n            auto begin()const { return b; }\r\n       \
    \     auto end()const { return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\
    \n    }\r\n    auto size()const { return m_n; };\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <type_traits>\r\n\r\ntemplate<class\
    \ Node = int, class Cost = long long>\r\nclass Graph {\r\n    //using Node = int;\r\
    \n    //using Cost = long long;\r\n    using Edges = std::vector<std::pair<Node,\
    \ Cost>>;\r\n\r\n    const int m_n;\r\n    std::vector<Edges> m_graph;\r\npublic:\r\
    \n    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n    auto addEdge(const Node&\
    \ f, const Node& t, const Cost& c = 1) {\r\n        m_graph[f].emplace_back(t,\
    \ c);\r\n    }\r\n    auto addEdgeUndirected(const Node& f, const Node& t, const\
    \ Cost& c = 1) {\r\n        addEdge(f, t, c); addEdge(t, f, c);\r\n    }\r\n \
    \   const auto& getEdges(const Node& from)const {\r\n        class EdgesRange\
    \ {\r\n            const Edges::const_iterator b, e;\r\n        public:\r\n  \
    \          EdgesRange(const Edges& edges) :b(edges.begin()), e(edges.end()) {}\r\
    \n            auto begin()const { return b; }\r\n            auto end()const {\
    \ return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\n \
    \   }\r\n    auto size()const { return m_n; };\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Graph.hpp
  requiredBy:
  - Library/Graph/Normal/dijkstra.hpp
  timestamp: '2023-06-10 16:48:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Graph/Normal/dijkstra.test.cpp
documentation_of: Library/Graph/Graph.hpp
layout: document
redirect_from:
- /library/Library/Graph/Graph.hpp
- /library/Library/Graph/Graph.hpp.html
title: Library/Graph/Graph.hpp
---
