---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Prim.hpp
    title: Library/Graph/Normal/Prim.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"Test/Graph/Normal/Prim.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"Library/Graph/Graph.hpp\"\n#include <vector>\r\
    \n#include <deque>\r\n\r\ntemplate<class Node = int, class Cost = long long>\r\
    \nclass Graph {\r\n    //using Node = int;\r\n    //using Cost = long long;\r\n\
    \    using Edge = std::pair<Node, Cost>;\r\n    using Edges = std::vector<Edge>;\r\
    \n\r\n    const int m_n;\r\n    std::vector<Edges> m_graph;\r\n\r\npublic:\r\n\
    \    Graph(int n) :m_n(n), m_graph(n) {}\r\n\r\n    auto addEdge(const Node& f,\
    \ const Node& t, const Cost& c = 1) {\r\n        m_graph[f].emplace_back(t, c);\r\
    \n    }\r\n    auto addEdgeUndirected(const Node& f, const Node& t, const Cost&\
    \ c = 1) {\r\n        addEdge(f, t, c); addEdge(t, f, c);\r\n    }\r\n    auto\
    \ getEdges(const Node& from)const {\r\n        class EdgesRange {\r\n        \
    \    const typename Edges::const_iterator b, e;\r\n        public:\r\n       \
    \     EdgesRange(const Edges& edges) :b(edges.begin()), e(edges.end()) {}\r\n\
    \            auto begin()const { return b; }\r\n            auto end()const {\
    \ return e; }\r\n        };\r\n        return EdgesRange(m_graph[from]);\r\n \
    \   }\r\n    auto getEdgesAll()const {\r\n        std::deque<std::pair<Node, Edge>>\
    \ edges;\r\n        for(Node from = 0; from < m_n; ++from) for(const auto& edge\
    \ : getEdges(from)) {\r\n            edges.emplace_back(from, edge);\r\n     \
    \   }\r\n        return edges;\r\n    }\r\n    auto getEdgesAll2()const {\r\n\
    \        std::deque<std::pair<Node, Node>> edges;\r\n        for(Node from = 0;\
    \ from < m_n; ++from) for(const auto& [to, _] : getEdges(from)) {\r\n        \
    \    edges.emplace_back(from, to);\r\n        }\r\n        return edges;\r\n \
    \   }\r\n    auto reverse()const {\r\n        auto rev = Graph<Node, Cost>(m_n);\r\
    \n        for(const auto& [from, edge] : getEdgesAll()) {\r\n            auto\
    \ [to, c] = edge;\r\n            rev.addEdge(to, from, c);\r\n        }\r\n  \
    \      return rev;\r\n    }\r\n    auto size()const { return m_n; };\r\n};\n#line\
    \ 2 \"Library/Graph/Normal/Prim.hpp\"\n\r\n#include <queue>\r\n#line 5 \"Library/Graph/Normal/Prim.hpp\"\
    \n\r\ntemplate<class Node, class Cost>\r\nauto prim(const Graph<Node, Cost>& graph)\
    \ {\r\n    auto n = graph.size();\r\n\r\n    Node root = 0;\r\n    Graph<Node,\
    \ Cost> min_spanning_tree(n);\r\n    using Type = std::pair<Cost, std::pair<Node,\
    \ Node>>;\r\n    std::priority_queue<Type, std::vector<Type>, std::greater<Type>>\
    \ q;\r\n    q.emplace(0, std::make_pair(-1, 0));\r\n    std::vector<bool> used(n);\r\
    \n    while(!q.empty()) {\r\n        auto [cost, ft] = q.top();\r\n        auto\
    \ [from, to] = ft;\r\n        q.pop();\r\n        if(used[to]) { continue; }\r\
    \n        used[to] = true;\r\n\r\n        if(from >= 0) { min_spanning_tree.addEdgeUndirected(from,\
    \ to, cost); }\r\n        for(const auto& [nto, ncost] : graph.getEdges(to)) {\r\
    \n            if(used[nto]) { continue; }\r\n            q.emplace(ncost, std::make_pair(to,\
    \ nto));\r\n        }\r\n    }\r\n    return min_spanning_tree;\r\n}\n#line 6\
    \ \"Test/Graph/Normal/Prim.test.cpp\"\n\r\nusing ll = long long;\r\nusing std::cout;\r\
    \nusing std::cin;\r\nconstexpr char endl = '\\n';\r\n\r\n\r\nsigned main() {\r\
    \n    int n, m;\r\n    cin >> n >> m;\r\n\r\n    auto graph = Graph(n);\r\n  \
    \  for(int i = 0; i < m; ++i) {\r\n        int s, t, w;\r\n        cin >> s >>\
    \ t >> w;\r\n        graph.addEdgeUndirected(s, t, w);\r\n    }\r\n\r\n    auto\
    \ min_spanning_tree = prim(graph);\r\n\r\n    ll ans = 0;\r\n    for(const auto&\
    \ [f, tc] : min_spanning_tree.getEdgesAll()) {\r\n        auto [t, c] = tc;\r\n\
    \        if(f < t) { ans += c; }\r\n    }\r\n    cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Graph.hpp\"\
    \r\n#include \"./../../../Library/Graph/Normal/Prim.hpp\"\r\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \n\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\n\r\n    auto\
    \ graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        int s, t, w;\r\
    \n        cin >> s >> t >> w;\r\n        graph.addEdgeUndirected(s, t, w);\r\n\
    \    }\r\n\r\n    auto min_spanning_tree = prim(graph);\r\n\r\n    ll ans = 0;\r\
    \n    for(const auto& [f, tc] : min_spanning_tree.getEdgesAll()) {\r\n       \
    \ auto [t, c] = tc;\r\n        if(f < t) { ans += c; }\r\n    }\r\n    cout <<\
    \ ans << endl;\r\n}"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Graph/Normal/Prim.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/Prim.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 04:26:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/Prim.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/Prim.test.cpp
- /verify/Test/Graph/Normal/Prim.test.cpp.html
title: Test/Graph/Normal/Prim.test.cpp
---
