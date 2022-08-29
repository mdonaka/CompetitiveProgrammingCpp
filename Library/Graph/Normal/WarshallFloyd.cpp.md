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
  bundledCode: "#line 1 \"Library/Graph/Normal/WarshallFloyd.cpp\"\n/**\n *  \u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u306B\u3088\u308A\u5168node\u304B\
    \u3089\u5168node\u3078\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u5F97\u308B\n\
    \ *  O(V^3)\n */\nvector<vector<ll>> warshallFloyd(const unordered_multimap<ll,\
    \ PAIR>& graph, ll n) {\n\tvector<vector<ll>> cost(n, vector<ll>(n, (1LL << 62)\
    \ - 1));\n\tfor (const auto& p : graph) {\n\t\tll from = p.first;\n\t\tll to =\
    \ p.second.first;\n\t\tll c = p.second.second;\n\t\tcost[from][to] = c;\n\t}\n\
    \tREP(k, n)REP(f, n)REP(t, n) {\n\t\tcost[f][t] = std::min(cost[f][t], cost[f][k]\
    \ + cost[k][t]);\n\t}\n\treturn cost;\n}\n"
  code: "/**\n *  \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u306B\u3088\
    \u308A\u5168node\u304B\u3089\u5168node\u3078\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\
    \u3092\u5F97\u308B\n *  O(V^3)\n */\nvector<vector<ll>> warshallFloyd(const unordered_multimap<ll,\
    \ PAIR>& graph, ll n) {\n\tvector<vector<ll>> cost(n, vector<ll>(n, (1LL << 62)\
    \ - 1));\n\tfor (const auto& p : graph) {\n\t\tll from = p.first;\n\t\tll to =\
    \ p.second.first;\n\t\tll c = p.second.second;\n\t\tcost[from][to] = c;\n\t}\n\
    \tREP(k, n)REP(f, n)REP(t, n) {\n\t\tcost[f][t] = std::min(cost[f][t], cost[f][k]\
    \ + cost[k][t]);\n\t}\n\treturn cost;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/WarshallFloyd.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Normal/WarshallFloyd.cpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/WarshallFloyd.cpp
- /library/Library/Graph/Normal/WarshallFloyd.cpp.html
title: Library/Graph/Normal/WarshallFloyd.cpp
---
