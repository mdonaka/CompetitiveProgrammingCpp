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
  bundledCode: "#line 1 \"Library/Graph/Normal/Kruskal.cpp\"\n/**\r\n * \u30AF\u30E9\
    \u30B9\u30AB\u30EB\u6CD5\u306B\u3088\u308B\u6700\u5C0F\u5168\u57DF\u6728\u69CB\
    \u6210\r\n * O(ElogE)\uFF1F\r\n * Unionfind\u6728\u304C\u5FC5\u8981\r\n */\r\n\
    std::unordered_multimap<ll, PAIR> Kruskal(ll n, const unordered_multimap<ll, PAIR>&\
    \ graph) {\r\n\r\n\tstd::unordered_multimap<ll, PAIR> minSpanningTree;\r\n\tauto\
    \ tree = UnionFind(n);\r\n\tusing Type = pair<ll, PAIR>;\r\n\tpriority_queue<Type,\
    \ std::vector<Type>, std::greater<Type>> q;\r\n\tREPC(p, graph) {\r\n\t\tq.emplace(p.second.second,\
    \ PAIR(p.first, p.second.first));\r\n\t}\r\n\r\n\twhile (!q.empty()) {\r\n\t\t\
    auto& val = q.top();\r\n\t\tll from = val.second.first;\r\n\t\tll to = val.second.second;\r\
    \n\t\tll cost = val.first;\r\n\t\tq.pop();\r\n\t\tif (tree.isSame(from, to)) {\
    \ continue; }\r\n\t\ttree.unite(from, to);\r\n\t\tminSpanningTree.emplace(from,\
    \ PAIR(to, cost));\r\n\t}\r\n\r\n\treturn minSpanningTree;\r\n}\r\n"
  code: "/**\r\n * \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\u306B\u3088\u308B\u6700\u5C0F\
    \u5168\u57DF\u6728\u69CB\u6210\r\n * O(ElogE)\uFF1F\r\n * Unionfind\u6728\u304C\
    \u5FC5\u8981\r\n */\r\nstd::unordered_multimap<ll, PAIR> Kruskal(ll n, const unordered_multimap<ll,\
    \ PAIR>& graph) {\r\n\r\n\tstd::unordered_multimap<ll, PAIR> minSpanningTree;\r\
    \n\tauto tree = UnionFind(n);\r\n\tusing Type = pair<ll, PAIR>;\r\n\tpriority_queue<Type,\
    \ std::vector<Type>, std::greater<Type>> q;\r\n\tREPC(p, graph) {\r\n\t\tq.emplace(p.second.second,\
    \ PAIR(p.first, p.second.first));\r\n\t}\r\n\r\n\twhile (!q.empty()) {\r\n\t\t\
    auto& val = q.top();\r\n\t\tll from = val.second.first;\r\n\t\tll to = val.second.second;\r\
    \n\t\tll cost = val.first;\r\n\t\tq.pop();\r\n\t\tif (tree.isSame(from, to)) {\
    \ continue; }\r\n\t\ttree.unite(from, to);\r\n\t\tminSpanningTree.emplace(from,\
    \ PAIR(to, cost));\r\n\t}\r\n\r\n\treturn minSpanningTree;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Normal/Kruskal.cpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Normal/Kruskal.cpp
layout: document
redirect_from:
- /library/Library/Graph/Normal/Kruskal.cpp
- /library/Library/Graph/Normal/Kruskal.cpp.html
title: Library/Graph/Normal/Kruskal.cpp
---
