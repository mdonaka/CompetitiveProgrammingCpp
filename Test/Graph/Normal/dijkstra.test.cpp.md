---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"Test/Graph/Normal/dijkstra.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"Library/Graph/Normal/dijkstra.hpp\"\n#include <unordered_map>\n\
    #include <queue>\n#include <vector>\n\nstd::vector<long long> dijkstra(int n,\
    \ const std::unordered_multimap<int, std::pair<int, long long>>& graph, int begin)\
    \ {\n    std::vector<long long> cost(n, 1e18);\n    cost[begin] = 0;\n    using\
    \ P = std::pair<long long, int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ q;\n    q.emplace(0, begin);\n    while(!q.empty()) {\n        auto [nowCost,\
    \ from] = q.top();\n        q.pop();\n        if(cost[from] < nowCost) { continue;\
    \ }\n        auto range = graph.equal_range(from);\n        for(auto itr = range.first;\
    \ itr != range.second; ++itr) {\n            auto [to, c] = itr->second;\n   \
    \         if(nowCost + c < cost[to]) {\n                cost[to] = nowCost + c;\n\
    \                q.emplace(cost[to], to);\n            }\n        }\n    }\n \
    \   return cost;\n}\n#line 5 \"Test/Graph/Normal/dijkstra.test.cpp\"\n\r\nusing\
    \ ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl\
    \ = '\\n';\r\ntemplate<class T, class S = T>\r\nusing P = std::pair<T, S>;\r\n\
    \r\nsigned main() {\r\n    int n, m, r;\r\n    cin >> n >> m >> r;\r\n    std::unordered_multimap<int,\
    \ P<int, ll>> graph;\r\n    for(int i = 0; i < m; ++i) {\r\n        int u, v,\
    \ c;\r\n        cin >> u >> v >> c;\r\n        graph.emplace(u, P<int>{v, c});\r\
    \n    }\r\n\r\n    auto min_cost = dijkstra(n, graph, r);\r\n\r\n    for(const\
    \ auto x : min_cost) {\r\n        if(x > 1e17) {\r\n            cout << \"INF\"\
    \ << endl;\r\n        } else {\r\n            cout << x << endl;\r\n        }\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Normal/dijkstra.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\ntemplate<class T, class S = T>\r\nusing P = std::pair<T,\
    \ S>;\r\n\r\nsigned main() {\r\n    int n, m, r;\r\n    cin >> n >> m >> r;\r\n\
    \    std::unordered_multimap<int, P<int, ll>> graph;\r\n    for(int i = 0; i <\
    \ m; ++i) {\r\n        int u, v, c;\r\n        cin >> u >> v >> c;\r\n       \
    \ graph.emplace(u, P<int>{v, c});\r\n    }\r\n\r\n    auto min_cost = dijkstra(n,\
    \ graph, r);\r\n\r\n    for(const auto x : min_cost) {\r\n        if(x > 1e17)\
    \ {\r\n            cout << \"INF\" << endl;\r\n        } else {\r\n          \
    \  cout << x << endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - Library/Graph/Normal/dijkstra.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 22:37:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/dijkstra.test.cpp
- /verify/Test/Graph/Normal/dijkstra.test.cpp.html
title: Test/Graph/Normal/dijkstra.test.cpp
---
