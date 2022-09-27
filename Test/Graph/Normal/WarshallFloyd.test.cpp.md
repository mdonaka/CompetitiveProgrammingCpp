---
data:
  _extendedDependsOn:
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
    #include <vector>\n#include <unordered_map>\n\nstd::vector<std::vector<long long>>\
    \ warshallFloyd(int n, const std::unordered_multimap<int, std::pair<int, long\
    \ long>>& graph) {\n    std::vector<std::vector<long long>> cost(n, std::vector<long\
    \ long>(n, 1e18));\n    for(const auto& [from, p] : graph) {\n        auto [to,\
    \ c] = p;\n        cost[from][to] = c;\n    }\n    for(int i = 0; i < n; ++i)\
    \ { cost[i][i] = 0; }\n    for(int k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int\
    \ t = 0; t < n; ++t) {\n        cost[f][t] = std::min(cost[f][t], cost[f][k] +\
    \ cost[k][t]);\n    }\n    return cost;\n}\n#line 5 \"Test/Graph/Normal/WarshallFloyd.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\ntemplate<class T, class S = T>\r\nusing P = std::pair<T,\
    \ S>;\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\n    std::unordered_multimap<int,\
    \ P<int, ll>> graph;\r\n    for(int i = 0; i < m; ++i) {\r\n        int u, v,\
    \ c;\r\n        cin >> u >> v >> c;\r\n        graph.emplace(u, P<int>{v, c});\r\
    \n    }\r\n\r\n    auto min_cost = warshallFloyd(n, graph);\r\n\r\n    for(int\
    \ k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int t = 0; t < n; ++t) {\r\n\
    \        if(min_cost[f][t] > min_cost[f][k] + min_cost[k][t]) {\r\n          \
    \  cout << \"NEGATIVE CYCLE\" << endl; return 0;\r\n        }\r\n    }\r\n\r\n\
    \    for(const auto r : min_cost) {\r\n        for(auto itr = r.begin(); itr !=\
    \ r.end(); ++itr) {\r\n            if(*itr > 1e17) {\r\n                cout <<\
    \ \"INF\";\r\n            } else {\r\n                cout << *itr;\r\n      \
    \      }\r\n            if(itr != std::prev(r.end())) { cout << \" \"; }\r\n \
    \       }\r\n        cout << endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../../Library/Graph/Normal/WarshallFloyd.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\ntemplate<class T, class S = T>\r\nusing P = std::pair<T,\
    \ S>;\r\n\r\nsigned main() {\r\n    int n, m;\r\n    cin >> n >> m;\r\n    std::unordered_multimap<int,\
    \ P<int, ll>> graph;\r\n    for(int i = 0; i < m; ++i) {\r\n        int u, v,\
    \ c;\r\n        cin >> u >> v >> c;\r\n        graph.emplace(u, P<int>{v, c});\r\
    \n    }\r\n\r\n    auto min_cost = warshallFloyd(n, graph);\r\n\r\n    for(int\
    \ k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int t = 0; t < n; ++t) {\r\n\
    \        if(min_cost[f][t] > min_cost[f][k] + min_cost[k][t]) {\r\n          \
    \  cout << \"NEGATIVE CYCLE\" << endl; return 0;\r\n        }\r\n    }\r\n\r\n\
    \    for(const auto r : min_cost) {\r\n        for(auto itr = r.begin(); itr !=\
    \ r.end(); ++itr) {\r\n            if(*itr > 1e17) {\r\n                cout <<\
    \ \"INF\";\r\n            } else {\r\n                cout << *itr;\r\n      \
    \      }\r\n            if(itr != std::prev(r.end())) { cout << \" \"; }\r\n \
    \       }\r\n        cout << endl;\r\n    }\r\n}"
  dependsOn:
  - Library/Graph/Normal/WarshallFloyd.hpp
  isVerificationFile: true
  path: Test/Graph/Normal/WarshallFloyd.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 23:19:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Graph/Normal/WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/Test/Graph/Normal/WarshallFloyd.test.cpp
- /verify/Test/Graph/Normal/WarshallFloyd.test.cpp.html
title: Test/Graph/Normal/WarshallFloyd.test.cpp
---
