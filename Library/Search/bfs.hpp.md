---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Search/bfs.hpp\"\n/**\r\n * \u91CD\u307F\u306A\u3057\
    \u30B0\u30E9\u30D5\u306EBFS\r\n */\r\nV<bool> isUsed(n, false); isUsed[0] = true;\r\
    \nqueue<PAIR> q;\tq.emplace(0, 0);\r\nwhile (!q.empty()) {\r\n\tauto from = q.front().first;\r\
    \n\tauto cost = q.front().second;\r\n\tq.pop();\r\n\r\n\tauto range = graph.equal_range(from);\r\
    \n\tREPI2(itr, range.first, range.second) {\r\n\t\tauto to = itr->second;\r\n\t\
    \tif (!isUsed[to]) {\r\n\t\t\tq.emplace(to);\r\n\t\t\tisUsed[to] = true;\r\n\t\
    \t}\r\n\t}\r\n}\n"
  code: "/**\r\n * \u91CD\u307F\u306A\u3057\u30B0\u30E9\u30D5\u306EBFS\r\n */\r\n\
    V<bool> isUsed(n, false); isUsed[0] = true;\r\nqueue<PAIR> q;\tq.emplace(0, 0);\r\
    \nwhile (!q.empty()) {\r\n\tauto from = q.front().first;\r\n\tauto cost = q.front().second;\r\
    \n\tq.pop();\r\n\r\n\tauto range = graph.equal_range(from);\r\n\tREPI2(itr, range.first,\
    \ range.second) {\r\n\t\tauto to = itr->second;\r\n\t\tif (!isUsed[to]) {\r\n\t\
    \t\tq.emplace(to);\r\n\t\t\tisUsed[to] = true;\r\n\t\t}\r\n\t}\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Search/bfs.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Search/bfs.hpp
layout: document
redirect_from:
- /library/Library/Search/bfs.hpp
- /library/Library/Search/bfs.hpp.html
title: Library/Search/bfs.hpp
---
