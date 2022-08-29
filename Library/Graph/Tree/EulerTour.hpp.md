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
  bundledCode: "#line 2 \"Library/Graph/Tree/EulerTour.hpp\"\n#include <stack>\r\n\
    #include <vector>\r\n#include <unordered_map>\r\n\r\nclass EulerTour {\r\n\tconst\
    \ std::vector<int> m_tour;\r\n\tconst std::vector<std::pair<int, int>> m_appear;\r\
    \n\r\n\tauto constructTour(int n, const std::unordered_multimap<int, int>& tree,\
    \ int root) const {\r\n\t\tstd::vector<int> tour;\r\n\t\ttour.reserve(2 * n);\r\
    \n\t\tstd::stack<int> stk;\r\n\t\tstd::vector<int> used(n);\r\n\t\tstk.emplace(root);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tauto from = stk.top();\r\n\t\t\ttour.emplace_back(from);\r\
    \n\t\t\tstk.pop();\r\n\t\t\tif (used[from]) { continue; }\r\n\t\t\tstk.emplace(from);\r\
    \n\t\t\tused[from] = true;\r\n\r\n\t\t\tauto range = tree.equal_range(from);\r\
    \n\t\t\tfor (auto it = range.first; it != range.second; ++it) {\r\n\t\t\t\tauto\
    \ to = it->second;\r\n\t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tstk.emplace(to);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn tour;\r\n\t}\r\n\tauto constructAppear(int\
    \ n) const {\r\n\t\tstd::vector<std::pair<int, int>> appear(n, { -1,-1 });\r\n\
    \t\tfor (int i = 0; i < 2 * n; ++i) {\r\n\t\t\tif (appear[m_tour[i]].first ==\
    \ -1) {\r\n\t\t\t\tappear[m_tour[i]].first = i;\r\n\t\t\t} else {\r\n\t\t\t\t\
    appear[m_tour[i]].second = i;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn appear;\r\n\t\
    }\r\npublic:\r\n\tEulerTour(int n, const std::unordered_multimap<int, int>& tree,\
    \ int root)\r\n\t\t:m_tour(constructTour(n, tree, root)),\r\n\t\tm_appear(constructAppear(n))\
    \ {\r\n\t}\r\n\r\n\tauto lessOrder(int li, int ri)const {\r\n\t\treturn m_appear[li].first\
    \ < m_appear[ri].first;\r\n\t}\r\n\tauto isSon(int son, int parent) {\r\n\t\t\
    return m_appear[parent].first < m_appear[son].first&&\r\n\t\t\tm_appear[son].second\
    \ < m_appear[parent].second;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n#include <stack>\r\n#include <vector>\r\n#include <unordered_map>\r\
    \n\r\nclass EulerTour {\r\n\tconst std::vector<int> m_tour;\r\n\tconst std::vector<std::pair<int,\
    \ int>> m_appear;\r\n\r\n\tauto constructTour(int n, const std::unordered_multimap<int,\
    \ int>& tree, int root) const {\r\n\t\tstd::vector<int> tour;\r\n\t\ttour.reserve(2\
    \ * n);\r\n\t\tstd::stack<int> stk;\r\n\t\tstd::vector<int> used(n);\r\n\t\tstk.emplace(root);\r\
    \n\t\twhile (!stk.empty()) {\r\n\t\t\tauto from = stk.top();\r\n\t\t\ttour.emplace_back(from);\r\
    \n\t\t\tstk.pop();\r\n\t\t\tif (used[from]) { continue; }\r\n\t\t\tstk.emplace(from);\r\
    \n\t\t\tused[from] = true;\r\n\r\n\t\t\tauto range = tree.equal_range(from);\r\
    \n\t\t\tfor (auto it = range.first; it != range.second; ++it) {\r\n\t\t\t\tauto\
    \ to = it->second;\r\n\t\t\t\tif (!used[to]) {\r\n\t\t\t\t\tstk.emplace(to);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn tour;\r\n\t}\r\n\tauto constructAppear(int\
    \ n) const {\r\n\t\tstd::vector<std::pair<int, int>> appear(n, { -1,-1 });\r\n\
    \t\tfor (int i = 0; i < 2 * n; ++i) {\r\n\t\t\tif (appear[m_tour[i]].first ==\
    \ -1) {\r\n\t\t\t\tappear[m_tour[i]].first = i;\r\n\t\t\t} else {\r\n\t\t\t\t\
    appear[m_tour[i]].second = i;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn appear;\r\n\t\
    }\r\npublic:\r\n\tEulerTour(int n, const std::unordered_multimap<int, int>& tree,\
    \ int root)\r\n\t\t:m_tour(constructTour(n, tree, root)),\r\n\t\tm_appear(constructAppear(n))\
    \ {\r\n\t}\r\n\r\n\tauto lessOrder(int li, int ri)const {\r\n\t\treturn m_appear[li].first\
    \ < m_appear[ri].first;\r\n\t}\r\n\tauto isSon(int son, int parent) {\r\n\t\t\
    return m_appear[parent].first < m_appear[son].first&&\r\n\t\t\tm_appear[son].second\
    \ < m_appear[parent].second;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Graph/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2021-09-20 16:59:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Graph/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/Library/Graph/Tree/EulerTour.hpp
- /library/Library/Graph/Tree/EulerTour.hpp.html
title: Library/Graph/Tree/EulerTour.hpp
---
