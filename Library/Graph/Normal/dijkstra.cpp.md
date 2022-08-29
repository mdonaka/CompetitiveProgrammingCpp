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
  bundledCode: "#line 1 \"Library/Graph/Normal/dijkstra.cpp\"\n/**\n *  \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u306B\u3088\u308A\u4EFB\u610F\u306Enode\u304B\u3089\u5168\
    node\u3078\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u5F97\u308B\n *  O((E+V)logV)\n\
    \ */\nVL dijkstra(const unordered_multimap<ll, PAIR>& graph, ll n, ll begin) {\n\
    \tVL cost(n, 1e15);\n\tcost[begin] = 0;\n\tpriority_queue<PAIR, vector<PAIR>,\
    \ std::greater<PAIR>> q;\n\tq.emplace(0, begin);\n\twhile (!q.empty()) {\n\t\t\
    ll from = q.top().second;\n\t\tll nowCost = q.top().first;\n\t\tq.pop();\n\t\t\
    if (cost[from] < nowCost) { continue; }\n\t\tauto range = graph.equal_range(from);\n\
    \t\tREPI2(itr, range.first, range.second) {\n\t\t\tll to = itr->second.first;\n\
    \t\t\tll c = itr->second.second;\n\t\t\tif (nowCost + c < cost[to]) {\n\t\t\t\t\
    cost[to] = nowCost + c;\n\t\t\t\tq.emplace(cost[to], to);\n\t\t\t}\n\t\t}\n\t\
    }\n\treturn cost;\n}\n"
  code: "/**\n *  \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u306B\u3088\u308A\u4EFB\u610F\
    \u306Enode\u304B\u3089\u5168node\u3078\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\
    \u5F97\u308B\n *  O((E+V)logV)\n */\nVL dijkstra(const unordered_multimap<ll,\
    \ PAIR>& graph, ll n, ll begin) {\n\tVL cost(n, 1e15);\n\tcost[begin] = 0;\n\t\
    priority_queue<PAIR, vector<PAIR>, std::greater<PAIR>> q;\n\tq.emplace(0, begin);\n\
    \twhile (!q.empty()) {\n\t\tll from = q.top().second;\n\t\tll nowCost = q.top().first;\n\
    \t\tq.pop();\n\t\tif (cost[from] < nowCost) { continue; }\n\t\tauto range = graph.equal_range(from);\n\
    \t\tREPI2(itr, range.first, range.second) {\n\t\t\tll to = itr->second.first;\n\
    \t\t\tll c = itr->second.second;\n\t\t\tif (nowCost + c < cost[to]) {\n\t\t\t\t\
    cost[to] = nowCost + c;\n\t\t\t\tq.emplace(cost[to], to);\n\t\t\t}\n\t\t}\n\t\
    }\n\treturn cost;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/dijkstra.cpp
  requiredBy: []
  timestamp: '2021-09-20 16:59:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Normal/dijkstra.cpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/dijkstra.cpp
- /library/Library/Graph/Normal/dijkstra.cpp.html
title: Library/Graph/Normal/dijkstra.cpp
---
