---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: Library/Graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/dijkstra.hpp
    title: Library/Graph/Normal/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Test/Graph/Normal/Dijkstra.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"Library/Graph/Normal/dijkstra.hpp\"\n#include <queue>\n\
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
    \ 5 \"Library/Graph/Normal/dijkstra.hpp\"\n\ntemplate<class Node, class Cost>\n\
    auto dijkstra(const Graph<Node, Cost>& graph, const Node& begin, const Cost& lim\
    \ = 1LL << 62) {\n    std::vector<Cost> cost(graph.size(), lim);\n    cost[begin]\
    \ = 0;\n\n    using P = std::pair<Cost, Node>;\n    std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> q;\n    q.emplace(cost[begin], begin);\n    while(!q.empty())\
    \ {\n        auto [now_cost, from] = q.top();\n        q.pop();\n        if(cost[from]\
    \ < now_cost) { continue; }\n        for(const auto& [to, c] : graph.getEdges(from))\
    \ {\n            if(now_cost + c < cost[to]) {\n                cost[to] = now_cost\
    \ + c;\n                q.emplace(cost[to], to);\n            }\n        }\n \
    \   }\n    return cost;\n}\n#line 6 \"Test/Graph/Normal/Dijkstra.test.cpp\"\n\r\
    \nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\n\r\nsigned main() {\r\n    int n, m, r;\r\n    cin >> n\
    \ >> m >> r;\r\n\r\n    auto graph = Graph(n);\r\n    for(int i = 0; i < m; ++i)\
    \ {\r\n        int u, v, c;\r\n        cin >> u >> v >> c;\r\n        graph.addEdge(u,\
    \ v, c);\r\n    }\r\n\r\n    auto min_cost = dijkstra(graph, r);\r\n\r\n    for(const\
    \ auto x : min_cost) {\r\n        if(x > 1e17) {\r\n            cout << \"INF\"\
    \ << endl;\r\n        } else {\r\n            cout << x << endl;\r\n        }\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Normal/dijkstra.hpp\"\
    \r\n#include \"./../../../Library/Graph/Graph.hpp\"\r\n\r\nusing ll = long long;\r\
    \nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\n\r\n\r\
    \nsigned main() {\r\n    int n, m, r;\r\n    cin >> n >> m >> r;\r\n\r\n    auto\
    \ graph = Graph(n);\r\n    for(int i = 0; i < m; ++i) {\r\n        int u, v, c;\r\
    \n        cin >> u >> v >> c;\r\n        graph.addEdge(u, v, c);\r\n    }\r\n\r\
    \n    auto min_cost = dijkstra(graph, r);\r\n\r\n    for(const auto x : min_cost)\
    \ {\r\n        if(x > 1e17) {\r\n            cout << \"INF\" << endl;\r\n    \
    \    } else {\r\n            cout << x << endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - Library/Graph/Normal/dijkstra.hpp
  - Library/Graph/Graph.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 03:49:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/Dijkstra.test.cpp
- /verify/Test/Graph/Normal/Dijkstra.test.cpp.html
title: Test/Graph/Normal/Dijkstra.test.cpp
---
