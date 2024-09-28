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
  bundledCode: "#line 2 \"Library/DataStructure/UnionFindWeight.hpp\"\n#include <numeric>\r\
    \n#include <vector>\r\n\r\nclass UnionFindWeight {\r\npublic:\r\n  std::vector<long\
    \ long> m_root;\r\n  std::vector<long long> m_rank;\r\n  std::vector<long long>\
    \ m_weight;\r\n\r\n  long long root(long long x) {\r\n    if (m_root[x] == x)\
    \ { return x; }\r\n    long long r = root(m_root[x]);\r\n    m_weight[x] += m_weight[m_root[x]];\r\
    \n    return m_root[x] = r;\r\n  }\r\n  long long weight(long long x) {\r\n  \
    \  root(x);\r\n    return m_weight[x];\r\n  }\r\n\r\npublic:\r\n  UnionFindWeight()\
    \ = delete;\r\n  UnionFindWeight(long long n) : m_root(n), m_rank(n), m_weight(n)\
    \ {\r\n    std::iota(m_root.begin(), m_root.end(), 0);\r\n  }\r\n  bool isSame(long\
    \ long x, long long y) { return root(x) == root(y); }\r\n  bool merge(long long\
    \ x, long long y, long long w) {\r\n    w += weight(x);\r\n    w -= weight(y);\r\
    \n    x = root(x);\r\n    y = root(y);\r\n    if (x == y) { return false; }\r\n\
    \    if (m_rank[x] < m_rank[y]) {\r\n      std::swap(x, y);\r\n      w = -w;\r\
    \n    }\r\n    if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }\r\n    m_root[y] =\
    \ x;\r\n    m_weight[y] = w;\r\n    return true;\r\n  }\r\n  long long diffWeight(long\
    \ long x, long long y) {\r\n    return weight(y) - weight(x);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <numeric>\r\n#include <vector>\r\n\r\nclass UnionFindWeight\
    \ {\r\npublic:\r\n  std::vector<long long> m_root;\r\n  std::vector<long long>\
    \ m_rank;\r\n  std::vector<long long> m_weight;\r\n\r\n  long long root(long long\
    \ x) {\r\n    if (m_root[x] == x) { return x; }\r\n    long long r = root(m_root[x]);\r\
    \n    m_weight[x] += m_weight[m_root[x]];\r\n    return m_root[x] = r;\r\n  }\r\
    \n  long long weight(long long x) {\r\n    root(x);\r\n    return m_weight[x];\r\
    \n  }\r\n\r\npublic:\r\n  UnionFindWeight() = delete;\r\n  UnionFindWeight(long\
    \ long n) : m_root(n), m_rank(n), m_weight(n) {\r\n    std::iota(m_root.begin(),\
    \ m_root.end(), 0);\r\n  }\r\n  bool isSame(long long x, long long y) { return\
    \ root(x) == root(y); }\r\n  bool merge(long long x, long long y, long long w)\
    \ {\r\n    w += weight(x);\r\n    w -= weight(y);\r\n    x = root(x);\r\n    y\
    \ = root(y);\r\n    if (x == y) { return false; }\r\n    if (m_rank[x] < m_rank[y])\
    \ {\r\n      std::swap(x, y);\r\n      w = -w;\r\n    }\r\n    if (m_rank[x] ==\
    \ m_rank[y]) { ++m_rank[x]; }\r\n    m_root[y] = x;\r\n    m_weight[y] = w;\r\n\
    \    return true;\r\n  }\r\n  long long diffWeight(long long x, long long y) {\r\
    \n    return weight(y) - weight(x);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/UnionFindWeight.hpp
  requiredBy: []
  timestamp: '2024-09-29 01:34:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/DataStructure/UnionFindWeight.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/UnionFindWeight.hpp
- /library/Library/DataStructure/UnionFindWeight.hpp.html
title: Library/DataStructure/UnionFindWeight.hpp
---
