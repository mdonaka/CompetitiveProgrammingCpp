---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/WarshallFloyd.hpp
    title: Library/Graph/Normal/WarshallFloyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"Test/Graph/Normal/WarshallFloyd.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\r\n\r\n\
    #include <iostream>\r\n#line 2 \"Library/Graph/Normal/WarshallFloyd.hpp\"\n\n\
    #include <vector>\n#line 3 \"Library/Graph/Graph.hpp\"\n#include <deque>\r\n\r\
    \ntemplate<class Node = int, class Cost = long long>\r\nclass Graph {\r\n    //using\
    \ Node = int;\r\n    //using Cost = long long;\r\n    using Edge = std::pair<Node,\
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
    \ 5 \"Library/Graph/Normal/WarshallFloyd.hpp\"\n\ntemplate<class Node, class Cost>\n\
    auto warshallFloyd(int n, const Graph<Node, Cost>& graph, const Cost& lim = 1LL\
    \ << 60) {\n    std::vector<std::vector<Cost>> cost(n, std::vector<Cost>(n, lim));\n\
    \    for(const auto& [from, edge] : graph.getEdgesAll()) {\n        auto [to,\
    \ c] = edge;\n        cost[from][to] = c;\n    }\n    for(int i = 0; i < n; ++i)\
    \ { cost[i][i] = 0; }\n    for(int k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int\
    \ t = 0; t < n; ++t) {\n        cost[f][t] = std::min(cost[f][t], cost[f][k] +\
    \ cost[k][t]);\n    }\n    return cost;\n}\n#line 5 \"Test/Graph/Normal/WarshallFloyd.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\ntemplate<class T, class S = T>\r\nusing P = std::pair<T,\
    \ S>;\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\n    auto\
    \ graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        int u, v, c;\r\
    \n        cin >> u >> v >> c;\r\n        graph.addEdge(u, v, c);\r\n    }\r\n\r\
    \n    auto min_cost = warshallFloyd(n, graph);\r\n\r\n    for(int k = 0; k < n;\
    \ ++k)for(int f = 0; f < n; ++f)for(int t = 0; t < n; ++t) {\r\n        if(min_cost[f][t]\
    \ > min_cost[f][k] + min_cost[k][t]) {\r\n            cout << \"NEGATIVE CYCLE\"\
    \ << endl; return 0;\r\n        }\r\n    }\r\n\r\n    for(const auto r : min_cost)\
    \ {\r\n        for(auto itr = r.begin(); itr != r.end(); ++itr) {\r\n        \
    \    if(*itr > 1e17) {\r\n                cout << \"INF\";\r\n            } else\
    \ {\r\n                cout << *itr;\r\n            }\r\n            if(itr !=\
    \ std::prev(r.end())) { cout << \" \"; }\r\n        }\r\n        cout << endl;\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Normal/WarshallFloyd.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\ntemplate<class T, class S = T>\r\nusing P = std::pair<T,\
    \ S>;\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\n    auto\
    \ graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        int u, v, c;\r\
    \n        cin >> u >> v >> c;\r\n        graph.addEdge(u, v, c);\r\n    }\r\n\r\
    \n    auto min_cost = warshallFloyd(n, graph);\r\n\r\n    for(int k = 0; k < n;\
    \ ++k)for(int f = 0; f < n; ++f)for(int t = 0; t < n; ++t) {\r\n        if(min_cost[f][t]\
    \ > min_cost[f][k] + min_cost[k][t]) {\r\n            cout << \"NEGATIVE CYCLE\"\
    \ << endl; return 0;\r\n        }\r\n    }\r\n\r\n    for(const auto r : min_cost)\
    \ {\r\n        for(auto itr = r.begin(); itr != r.end(); ++itr) {\r\n        \
    \    if(*itr > 1e17) {\r\n                cout << \"INF\";\r\n            } else\
    \ {\r\n                cout << *itr;\r\n            }\r\n            if(itr !=\
    \ std::prev(r.end())) { cout << \" \"; }\r\n        }\r\n        cout << endl;\r\
    \n    }\r\n}"
  dependsOn:
  - Library/Graph/Normal/WarshallFloyd.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/WarshallFloyd.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 03:49:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/WarshallFloyd.test.cpp
- /verify/Test/Graph/Normal/WarshallFloyd.test.cpp.html
title: Test/Graph/Normal/WarshallFloyd.test.cpp
---
