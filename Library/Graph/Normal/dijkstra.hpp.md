---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/dijkstra.test.cpp
    title: Test/Graph/Normal/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/dijkstra.hpp\"\n#include <unordered_map>\n\
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
    \   return cost;\n}\n"
  code: "#pragma once\n#include <unordered_map>\n#include <queue>\n#include <vector>\n\
    \nstd::vector<long long> dijkstra(int n, const std::unordered_multimap<int, std::pair<int,\
    \ long long>>& graph, int begin) {\n    std::vector<long long> cost(n, 1e18);\n\
    \    cost[begin] = 0;\n    using P = std::pair<long long, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> q;\n    q.emplace(0, begin);\n    while(!q.empty())\
    \ {\n        auto [nowCost, from] = q.top();\n        q.pop();\n        if(cost[from]\
    \ < nowCost) { continue; }\n        auto range = graph.equal_range(from);\n  \
    \      for(auto itr = range.first; itr != range.second; ++itr) {\n           \
    \ auto [to, c] = itr->second;\n            if(nowCost + c < cost[to]) {\n    \
    \            cost[to] = nowCost + c;\n                q.emplace(cost[to], to);\n\
    \            }\n        }\n    }\n    return cost;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-09-27 22:37:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Normal/dijkstra.test.cpp
documentation_of: Library/Graph/Normal/dijkstra.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/dijkstra.hpp
- /library/Library/Graph/Normal/dijkstra.hpp.html
title: Library/Graph/Normal/dijkstra.hpp
---
