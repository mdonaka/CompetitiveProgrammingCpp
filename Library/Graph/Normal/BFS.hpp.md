---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: Library/Graph/Tree/LowestCommonAncestor.hpp
    title: Library/Graph/Tree/LowestCommonAncestor.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Graph/Tree/LowestCommonAncestor.test.cpp
    title: Test/Graph/Tree/LowestCommonAncestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/BFS.hpp\"\n\r\n#include <vector>\r\n\
    #include <queue>\r\n\r\n#line 3 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\
    \n\r\ntemplate<class Node = int, class Cost = long long>\r\nclass Graph {\r\n\
    \    //using Node = int;\r\n    //using Cost = long long;\r\n    using Edge =\
    \ std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const\
    \ int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n    Graph(int\
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
    \   auto size()const { return m_n; };\r\n};\n#line 7 \"Library/Graph/Normal/BFS.hpp\"\
    \n\r\ntemplate<class Node, class Cost, class Lambda>\r\nauto bfs(const Graph<Node,\
    \ Cost>& graph, const Node& root, const Lambda& lambda) {\r\n    auto n = graph.size();\r\
    \n    std::vector<bool> used(n); used[root] = true;\r\n    std::queue<Node> q;\
    \ q.emplace(root);\r\n    while(!q.empty()) {\r\n        auto from = q.front();\r\
    \n        q.pop();\r\n        for(const auto& [to, _] : graph.getEdges(from))\
    \ {\r\n            if(used[to]) { continue; }\r\n            q.emplace(to);\r\n\
    \            used[to] = true;\r\n            lambda(from, to);\r\n        }\r\n\
    \    }\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <queue>\r\n\r\n#include\
    \ \"./../Graph.hpp\" \r\n\r\ntemplate<class Node, class Cost, class Lambda>\r\n\
    auto bfs(const Graph<Node, Cost>& graph, const Node& root, const Lambda& lambda)\
    \ {\r\n    auto n = graph.size();\r\n    std::vector<bool> used(n); used[root]\
    \ = true;\r\n    std::queue<Node> q; q.emplace(root);\r\n    while(!q.empty())\
    \ {\r\n        auto from = q.front();\r\n        q.pop();\r\n        for(const\
    \ auto& [to, _] : graph.getEdges(from)) {\r\n            if(used[to]) { continue;\
    \ }\r\n            q.emplace(to);\r\n            used[to] = true;\r\n        \
    \    lambda(from, to);\r\n        }\r\n    }\r\n}\r\n"
  dependsOn:
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/BFS.hpp
  requiredBy:
  - Library/Graph/Tree/LowestCommonAncestor.hpp
  timestamp: '2023-06-18 06:04:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Graph/Tree/LowestCommonAncestor.test.cpp
documentation_of: Library/Graph/Normal/BFS.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/BFS.hpp
- /library/Library/Graph/Normal/BFS.hpp.html
title: Library/Graph/Normal/BFS.hpp
---
