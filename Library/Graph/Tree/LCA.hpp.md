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
  bundledCode: "#line 2 \"Library/Graph/Tree/LCA.hpp\"\n#include <vector>\r\n#include\
    \ <queue>\r\n#include <cmath>\r\n#include <unordered_map>\r\n\r\n\r\nclass LowestCommonAncestor\
    \ {\r\n\tconst std::vector<std::vector<int>> m_parent;\r\n\tconst std::vector<int>\
    \ m_depth;\r\n\r\n\tauto constructParent(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root) const {\r\n\t\tint toSize = std::log2(n) + 1;\r\n\t\t\
    std::vector<std::vector<int>> parent(n, std::vector<int>(toSize, root));\r\n\t\
    \tstd::queue<int> q;\r\n\t\tq.emplace(root);\r\n\t\tstd::vector<int> used(n);\r\
    \n\t\tused[root] = true;\r\n\t\twhile (!q.empty()) {\r\n\t\t\tauto from = q.front();\r\
    \n\t\t\tq.pop();\r\n\t\t\tauto range = tree.equal_range(from);\r\n\t\t\tfor (auto\
    \ it = range.first; it != range.second; ++it) {\r\n\t\t\t\tauto to = it->second;\r\
    \n\t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tq.emplace(to);\r\n\t\t\t\t\tused[to] =\
    \ true;\r\n\t\t\t\t\tparent[to][0] = from;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\
    \t\tfor (int p2 = 1; p2 < toSize; ++p2)for (int f = 0; f < n; ++f) {\r\n\t\t\t\
    parent[f][p2] = parent[parent[f][p2 - 1]][p2 - 1];\r\n\t\t}\r\n\t\treturn parent;\r\
    \n\t}\r\n\tauto constructDepth(int n, const std::unordered_multimap<int, int>&\
    \ tree, int root)const {\r\n\t\tstd::vector<int> depth(n);\r\n\t\tstd::queue<int>\
    \ q;\r\n\t\tq.emplace(root);\r\n\t\tstd::vector<int> used(n);\r\n\t\tused[root]\
    \ = true;\r\n\t\twhile (!q.empty()) {\r\n\t\t\tauto from = q.front();\r\n\t\t\t\
    q.pop();\r\n\t\t\tauto range = tree.equal_range(from);\r\n\t\t\tfor (auto it =\
    \ range.first; it != range.second; ++it) {\r\n\t\t\t\tauto to = it->second;\r\n\
    \t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tq.emplace(to);\r\n\t\t\t\t\tused[to] = true;\r\
    \n\t\t\t\t\tdepth[to] = depth[from] + 1;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \treturn depth;\r\n\t}\r\npublic:\r\n\tLowestCommonAncestor(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root) :\r\n\t\tm_parent(constructParent(n, tree, root)),\r\n\
    \t\tm_depth(constructDepth(n, tree, root)) {\r\n\t}\r\n\r\n\tauto lca(int l, int\
    \ r)const {\r\n\t\tconst int toSize = m_parent[0].size();\r\n\t\tif (m_depth[l]\
    \ < m_depth[r]) { std::swap(l, r); }\r\n\t\tfor (int k = 0; k < toSize; ++k) {\r\
    \n\t\t\tif (((m_depth[l] - m_depth[r]) >> k) & 1) {\r\n\t\t\t\tl = m_parent[l][k];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif (l == r) { return l; }\r\n\t\tfor (int k = toSize\
    \ - 1; k >= 0; k--) {\r\n\t\t\tif (m_parent[l][k] != m_parent[r][k]) {\r\n\t\t\
    \t\tl = m_parent[l][k];\r\n\t\t\t\tr = m_parent[r][k];\r\n\t\t\t}\r\n\t\t}\r\n\
    \t\treturn m_parent[l][0];\r\n\t}\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <queue>\r\n#include <cmath>\r\
    \n#include <unordered_map>\r\n\r\n\r\nclass LowestCommonAncestor {\r\n\tconst\
    \ std::vector<std::vector<int>> m_parent;\r\n\tconst std::vector<int> m_depth;\r\
    \n\r\n\tauto constructParent(int n, const std::unordered_multimap<int, int>& tree,\
    \ int root) const {\r\n\t\tint toSize = std::log2(n) + 1;\r\n\t\tstd::vector<std::vector<int>>\
    \ parent(n, std::vector<int>(toSize, root));\r\n\t\tstd::queue<int> q;\r\n\t\t\
    q.emplace(root);\r\n\t\tstd::vector<int> used(n);\r\n\t\tused[root] = true;\r\n\
    \t\twhile (!q.empty()) {\r\n\t\t\tauto from = q.front();\r\n\t\t\tq.pop();\r\n\
    \t\t\tauto range = tree.equal_range(from);\r\n\t\t\tfor (auto it = range.first;\
    \ it != range.second; ++it) {\r\n\t\t\t\tauto to = it->second;\r\n\t\t\t\tif (!used[to])\
    \ {\r\n\t\t\t\t\tq.emplace(to);\r\n\t\t\t\t\tused[to] = true;\r\n\t\t\t\t\tparent[to][0]\
    \ = from;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor (int p2 = 1; p2 < toSize;\
    \ ++p2)for (int f = 0; f < n; ++f) {\r\n\t\t\tparent[f][p2] = parent[parent[f][p2\
    \ - 1]][p2 - 1];\r\n\t\t}\r\n\t\treturn parent;\r\n\t}\r\n\tauto constructDepth(int\
    \ n, const std::unordered_multimap<int, int>& tree, int root)const {\r\n\t\tstd::vector<int>\
    \ depth(n);\r\n\t\tstd::queue<int> q;\r\n\t\tq.emplace(root);\r\n\t\tstd::vector<int>\
    \ used(n);\r\n\t\tused[root] = true;\r\n\t\twhile (!q.empty()) {\r\n\t\t\tauto\
    \ from = q.front();\r\n\t\t\tq.pop();\r\n\t\t\tauto range = tree.equal_range(from);\r\
    \n\t\t\tfor (auto it = range.first; it != range.second; ++it) {\r\n\t\t\t\tauto\
    \ to = it->second;\r\n\t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tq.emplace(to);\r\n\
    \t\t\t\t\tused[to] = true;\r\n\t\t\t\t\tdepth[to] = depth[from] + 1;\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn depth;\r\n\t}\r\npublic:\r\n\tLowestCommonAncestor(int\
    \ n, const std::unordered_multimap<int, int>& tree, int root) :\r\n\t\tm_parent(constructParent(n,\
    \ tree, root)),\r\n\t\tm_depth(constructDepth(n, tree, root)) {\r\n\t}\r\n\r\n\
    \tauto lca(int l, int r)const {\r\n\t\tconst int toSize = m_parent[0].size();\r\
    \n\t\tif (m_depth[l] < m_depth[r]) { std::swap(l, r); }\r\n\t\tfor (int k = 0;\
    \ k < toSize; ++k) {\r\n\t\t\tif (((m_depth[l] - m_depth[r]) >> k) & 1) {\r\n\t\
    \t\t\tl = m_parent[l][k];\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (l == r) { return l; }\r\
    \n\t\tfor (int k = toSize - 1; k >= 0; k--) {\r\n\t\t\tif (m_parent[l][k] != m_parent[r][k])\
    \ {\r\n\t\t\t\tl = m_parent[l][k];\r\n\t\t\t\tr = m_parent[r][k];\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\treturn m_parent[l][0];\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Tree/LCA.hpp
  requiredBy: []
  timestamp: '2021-09-20 16:59:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Tree/LCA.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/LCA.hpp
- /library/Library/Graph/Tree/LCA.hpp.html
title: Library/Graph/Tree/LCA.hpp
---
