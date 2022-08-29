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
  bundledCode: "#line 1 \"Library/Search/BFSonGraph.hpp\"\n#include <unordered_map>\r\
    \n#include <queue>\r\n\r\ntemplate<class Lambda>\r\nauto graphBFS(long long n,\
    \ const std::unordered_multimap<long long, long long>& graph, long long root,\
    \ const Lambda& lambda) {\r\n\tV<bool> isUsed(n, false); isUsed[root] = true;\r\
    \n\tstd::queue<long long> q; q.emplace(root);\r\n\twhile (!q.empty()) {\r\n\t\t\
    auto from = q.front();\r\n\t\tq.pop();\r\n\r\n\t\tauto range = graph.equal_range(from);\r\
    \n\t\tREPI2(itr, range.first, range.second) {\r\n\t\t\tauto to = itr->second;\r\
    \n\t\t\tif (!isUsed[to]) {\r\n\t\t\t\tq.emplace(to);\r\n\t\t\t\tisUsed[to] = true;\r\
    \n\t\t\t\tlambda(from, to);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n}\r\n"
  code: "#include <unordered_map>\r\n#include <queue>\r\n\r\ntemplate<class Lambda>\r\
    \nauto graphBFS(long long n, const std::unordered_multimap<long long, long long>&\
    \ graph, long long root, const Lambda& lambda) {\r\n\tV<bool> isUsed(n, false);\
    \ isUsed[root] = true;\r\n\tstd::queue<long long> q; q.emplace(root);\r\n\twhile\
    \ (!q.empty()) {\r\n\t\tauto from = q.front();\r\n\t\tq.pop();\r\n\r\n\t\tauto\
    \ range = graph.equal_range(from);\r\n\t\tREPI2(itr, range.first, range.second)\
    \ {\r\n\t\t\tauto to = itr->second;\r\n\t\t\tif (!isUsed[to]) {\r\n\t\t\t\tq.emplace(to);\r\
    \n\t\t\t\tisUsed[to] = true;\r\n\t\t\t\tlambda(from, to);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t}\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Search/BFSonGraph.hpp
  requiredBy: []
  timestamp: '2020-04-20 10:46:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Search/BFSonGraph.hpp
layout: document
redirect_from:
- /library/Library/Search/BFSonGraph.hpp
- /library/Library/Search/BFSonGraph.hpp.html
title: Library/Search/BFSonGraph.hpp
---
