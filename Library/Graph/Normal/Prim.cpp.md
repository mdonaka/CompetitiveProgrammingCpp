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
  bundledCode: "#line 1 \"Library/Graph/Normal/Prim.cpp\"\n/*\r\n * Prim\u6CD5\u306B\
    \u3088\u308B\u6700\u5C0F\u5168\u57DF\u6728\u69CB\u6210\r\n * O(E+VlogV)\uFF1F\r\
    \n */\r\nstd::unordered_multimap<ll, PAIR> Prim(ll n, const unordered_multimap<ll,\
    \ PAIR>& graph) {\r\n\r\n\tstd::unordered_multimap<ll, PAIR> minSpanningTree;\r\
    \n\tstd::vector<bool> isUse(n);\r\n\tusing Type = pair<ll, PAIR>;\r\n\tpriority_queue<Type,\
    \ std::vector<Type>, std::greater<Type>> q;\r\n\r\n\tauto add = [&](ll from) {\r\
    \n\t\tauto range = graph.equal_range(from);\r\n\t\tREPI2(itr, range.first, range.second)\
    \ {\r\n\t\t\tll to = itr->second.first;\r\n\t\t\tll cost = itr->second.second;\r\
    \n\r\n\t\t\tif (isUse[to]) { continue; }\r\n\t\t\tq.emplace(cost, PAIR(from, to));\r\
    \n\t\t}\r\n\t};\r\n\r\n\tisUse[0] = true;\r\n\tadd(0);\r\n\r\n\twhile (!q.empty())\
    \ {\r\n\t\tll from = q.top().second.second;\r\n\t\tll f_from = q.top().second.first;\r\
    \n\t\tll f_cost = q.top().first;\r\n\t\tq.pop();\r\n\t\tif (isUse[from]) { continue;\
    \ }\r\n\t\tisUse[from] = true;\r\n\t\tminSpanningTree.emplace(f_from, PAIR(from,\
    \ f_cost));\r\n\t\tadd(from);\r\n\t}\r\n\treturn minSpanningTree;\r\n}\n"
  code: "/*\r\n * Prim\u6CD5\u306B\u3088\u308B\u6700\u5C0F\u5168\u57DF\u6728\u69CB\
    \u6210\r\n * O(E+VlogV)\uFF1F\r\n */\r\nstd::unordered_multimap<ll, PAIR> Prim(ll\
    \ n, const unordered_multimap<ll, PAIR>& graph) {\r\n\r\n\tstd::unordered_multimap<ll,\
    \ PAIR> minSpanningTree;\r\n\tstd::vector<bool> isUse(n);\r\n\tusing Type = pair<ll,\
    \ PAIR>;\r\n\tpriority_queue<Type, std::vector<Type>, std::greater<Type>> q;\r\
    \n\r\n\tauto add = [&](ll from) {\r\n\t\tauto range = graph.equal_range(from);\r\
    \n\t\tREPI2(itr, range.first, range.second) {\r\n\t\t\tll to = itr->second.first;\r\
    \n\t\t\tll cost = itr->second.second;\r\n\r\n\t\t\tif (isUse[to]) { continue;\
    \ }\r\n\t\t\tq.emplace(cost, PAIR(from, to));\r\n\t\t}\r\n\t};\r\n\r\n\tisUse[0]\
    \ = true;\r\n\tadd(0);\r\n\r\n\twhile (!q.empty()) {\r\n\t\tll from = q.top().second.second;\r\
    \n\t\tll f_from = q.top().second.first;\r\n\t\tll f_cost = q.top().first;\r\n\t\
    \tq.pop();\r\n\t\tif (isUse[from]) { continue; }\r\n\t\tisUse[from] = true;\r\n\
    \t\tminSpanningTree.emplace(f_from, PAIR(from, f_cost));\r\n\t\tadd(from);\r\n\
    \t}\r\n\treturn minSpanningTree;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/Prim.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Normal/Prim.cpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/Prim.cpp
- /library/Library/Graph/Normal/Prim.cpp.html
title: Library/Graph/Normal/Prim.cpp
---
