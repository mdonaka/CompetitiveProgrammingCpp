---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/WarshallFloyd.test.cpp
    title: Test/Graph/Normal/WarshallFloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Graph/Normal/WarshallFloyd.hpp\"\n\n#include <vector>\n\
    #include <unordered_map>\n\nstd::vector<std::vector<long long>> warshallFloyd(int\
    \ n, const std::unordered_multimap<int, std::pair<int, long long>>& graph) {\n\
    \    std::vector<std::vector<long long>> cost(n, std::vector<long long>(n, 1e18));\n\
    \    for(const auto& [from, p] : graph) {\n        auto [to, c] = p;\n       \
    \ cost[from][to] = c;\n    }\n    for(int i = 0; i < n; ++i) { cost[i][i] = 0;\
    \ }\n    for(int k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int t = 0; t\
    \ < n; ++t) {\n        cost[f][t] = std::min(cost[f][t], cost[f][k] + cost[k][t]);\n\
    \    }\n    return cost;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <unordered_map>\n\nstd::vector<std::vector<long\
    \ long>> warshallFloyd(int n, const std::unordered_multimap<int, std::pair<int,\
    \ long long>>& graph) {\n    std::vector<std::vector<long long>> cost(n, std::vector<long\
    \ long>(n, 1e18));\n    for(const auto& [from, p] : graph) {\n        auto [to,\
    \ c] = p;\n        cost[from][to] = c;\n    }\n    for(int i = 0; i < n; ++i)\
    \ { cost[i][i] = 0; }\n    for(int k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int\
    \ t = 0; t < n; ++t) {\n        cost[f][t] = std::min(cost[f][t], cost[f][k] +\
    \ cost[k][t]);\n    }\n    return cost;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2022-09-27 23:19:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Graph/Normal/WarshallFloyd.test.cpp
documentation_of: Library/Graph/Normal/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/WarshallFloyd.hpp
- /library/Library/Graph/Normal/WarshallFloyd.hpp.html
title: Library/Graph/Normal/WarshallFloyd.hpp
---
