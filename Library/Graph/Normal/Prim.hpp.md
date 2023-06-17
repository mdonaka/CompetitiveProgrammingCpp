---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Prim.test.cpp
    title: Test/Graph/Normal/Prim.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/Prim.hpp\"\n\r\n#include <queue>\r\n\
    #line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\n#include <deque>\r\n\
    \r\ntemplate<class Node = int, class Cost = long long>\r\nclass Graph {\r\n  \
    \  //using Node = int;\r\n    //using Cost = long long;\r\n    using Edge = std::pair<Node,\
    \ Cost>;\r\n    using Edges = std::vector<Edge>;\r\n\r\n    const int m_n;\r\n\
    \    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n    Graph(int n) :m_n(n), m_graph(n)\
    \ {}\r\n\r\n    auto addEdge(const Node& f, const Node& t, const Cost& c = 1)\
    \ {\r\n        m_graph[f].emplace_back(t, c);\r\n    }\r\n    auto addEdgeUndirected(const\
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
    \      return rev;\r\n    }\r\n    auto size()const { return m_n; };\r\n};\n#line\
    \ 5 \"Library/Graph/Normal/Prim.hpp\"\n\r\ntemplate<class Node, class Cost>\r\n\
    auto prim(const Graph<Node, Cost>& graph) {\r\n    auto n = graph.size();\r\n\r\
    \n    Node root = 0;\r\n    Graph<Node, Cost> min_spanning_tree(n);\r\n    using\
    \ Type = std::pair<Cost, std::pair<Node, Node>>;\r\n    std::priority_queue<Type,\
    \ std::vector<Type>, std::greater<Type>> q;\r\n    q.emplace(0, std::make_pair(-1,\
    \ 0));\r\n    std::vector<bool> used(n);\r\n    while(!q.empty()) {\r\n      \
    \  auto [cost, ft] = q.top();\r\n        auto [from, to] = ft;\r\n        q.pop();\r\
    \n        if(used[to]) { continue; }\r\n        used[to] = true;\r\n\r\n     \
    \   if(from >= 0) { min_spanning_tree.addEdgeUndirected(from, to, cost); }\r\n\
    \        for(const auto& [nto, ncost] : graph.getEdges(to)) {\r\n            if(used[nto])\
    \ { continue; }\r\n            q.emplace(ncost, std::make_pair(to, nto));\r\n\
    \        }\r\n    }\r\n    return min_spanning_tree;\r\n}\n"
  code: "#pragma once\r\n\r\n#include <queue>\r\n#include \"./../Graph.hpp\"\r\n\r\
    \ntemplate<class Node, class Cost>\r\nauto prim(const Graph<Node, Cost>& graph)\
    \ {\r\n    auto n = graph.size();\r\n\r\n    Node root = 0;\r\n    Graph<Node,\
    \ Cost> min_spanning_tree(n);\r\n    using Type = std::pair<Cost, std::pair<Node,\
    \ Node>>;\r\n    std::priority_queue<Type, std::vector<Type>, std::greater<Type>>\
    \ q;\r\n    q.emplace(0, std::make_pair(-1, 0));\r\n    std::vector<bool> used(n);\r\
    \n    while(!q.empty()) {\r\n        auto [cost, ft] = q.top();\r\n        auto\
    \ [from, to] = ft;\r\n        q.pop();\r\n        if(used[to]) { continue; }\r\
    \n        used[to] = true;\r\n\r\n        if(from >= 0) { min_spanning_tree.addEdgeUndirected(from,\
    \ to, cost); }\r\n        for(const auto& [nto, ncost] : graph.getEdges(to)) {\r\
    \n            if(used[nto]) { continue; }\r\n            q.emplace(ncost, std::make_pair(to,\
    \ nto));\r\n        }\r\n    }\r\n    return min_spanning_tree;\r\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  isVerificationFile: false
  path: Library/Graph/Normal/Prim.hpp
  requiredBy: []
  timestamp: '2023-06-14 04:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Normal/Prim.test.cpp
documentation_of: Library/Graph/Normal/Prim.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/Prim.hpp
- /library/Library/Graph/Normal/Prim.hpp.html
title: Library/Graph/Normal/Prim.hpp
---
