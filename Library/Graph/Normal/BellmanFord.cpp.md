---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Graph/Normal/BellmanFord.cpp\"\n/**\r\n *  \u30D9\
    \u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\u306B\u3088\u308A\u4EFB\u610F\
    \u306Enode\u304B\u3089\u5168node\u3078\u306E\u6700\u521D\u30B3\u30B9\u30C8\u3092\
    \u5F97\u308B\r\n *  O(ElogV)\r\n */\r\nVL BellmanFord(const unordered_multimap<ll,\
    \ PAIR> graph, ll n, ll begin) {\r\n  VL cost(n, 1e15);\r\n  cost[begin] = 0;\r\
    \n\r\n  REP(_, graph.size()) REP(from, n) {\r\n    auto range = graph.equal_range(from);\r\
    \n    REPI2(itr, range.first, range.second) {\r\n      ll to = itr->second.first;\r\
    \n      ll c = itr->second.second;\r\n      cost[to] = std::min(cost[to], cost[from]\
    \ + c);\r\n    }\r\n  }\r\n  VL cost_ = cost;\r\n  REP(_, n) REP(from, n) {\r\n\
    \    auto range = graph.equal_range(from);\r\n    REPI2(itr, range.first, range.second)\
    \ {\r\n      ll to = itr->second.first;\r\n      ll c = itr->second.second;\r\n\
    \      if (cost[from] + c < cost[to]) {\r\n        cost[to] = cost[from] + c;\r\
    \n        cost_[to] = 1e15;\r\n      }\r\n    }\r\n  }\r\n  return cost_;\r\n\
    }\r\n"
  code: "/**\r\n *  \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\u306B\u3088\
    \u308A\u4EFB\u610F\u306Enode\u304B\u3089\u5168node\u3078\u306E\u6700\u521D\u30B3\
    \u30B9\u30C8\u3092\u5F97\u308B\r\n *  O(ElogV)\r\n */\r\nVL BellmanFord(const\
    \ unordered_multimap<ll, PAIR> graph, ll n, ll begin) {\r\n  VL cost(n, 1e15);\r\
    \n  cost[begin] = 0;\r\n\r\n  REP(_, graph.size()) REP(from, n) {\r\n    auto\
    \ range = graph.equal_range(from);\r\n    REPI2(itr, range.first, range.second)\
    \ {\r\n      ll to = itr->second.first;\r\n      ll c = itr->second.second;\r\n\
    \      cost[to] = std::min(cost[to], cost[from] + c);\r\n    }\r\n  }\r\n  VL\
    \ cost_ = cost;\r\n  REP(_, n) REP(from, n) {\r\n    auto range = graph.equal_range(from);\r\
    \n    REPI2(itr, range.first, range.second) {\r\n      ll to = itr->second.first;\r\
    \n      ll c = itr->second.second;\r\n      if (cost[from] + c < cost[to]) {\r\
    \n        cost[to] = cost[from] + c;\r\n        cost_[to] = 1e15;\r\n      }\r\
    \n    }\r\n  }\r\n  return cost_;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/BellmanFord.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Normal/BellmanFord.cpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/BellmanFord.cpp
- /library/Library/Graph/Normal/BellmanFord.cpp.html
title: Library/Graph/Normal/BellmanFord.cpp
---
