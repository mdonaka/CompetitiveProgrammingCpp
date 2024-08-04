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
  bundledCode: "#line 1 \"Library/DataStructure/UnionFindWeight.cpp\"\nclass UnionFindWeight\
    \ {\r\npublic:\r\n  std::vector<ll> m_root;\r\n  std::vector<ll> m_rank;\r\n \
    \ std::vector<ll> m_weight;\r\n\r\n  ll root(ll x) {\r\n    if (m_root[x] == x)\
    \ { return x; }\r\n    ll r = root(m_root[x]);\r\n    m_weight[x] += m_weight[m_root[x]];\r\
    \n    return m_root[x] = r;\r\n  }\r\n  ll weight(ll x) {\r\n    root(x);\r\n\
    \    return m_weight[x];\r\n  }\r\n\r\npublic:\r\n  UnionFindWeight() = delete;\r\
    \n  UnionFindWeight(ll n) : m_root(n), m_rank(n), m_weight(n) {\r\n    std::iota(m_root.begin(),\
    \ m_root.end(), 0);\r\n  }\r\n  bool isSame(ll x, ll y) { return root(x) == root(y);\
    \ }\r\n  bool merge(ll x, ll y, ll w) {\r\n    w += weight(x);\r\n    w -= weight(y);\r\
    \n    x = root(x);\r\n    y = root(y);\r\n    if (x == y) { return false; }\r\n\
    \    if (m_rank[x] < m_rank[y]) {\r\n      std::swap(x, y);\r\n      w = -w;\r\
    \n    }\r\n    if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }\r\n    m_root[y] =\
    \ x;\r\n    m_weight[y] = w;\r\n    return true;\r\n  }\r\n  ll diffWeight(ll\
    \ x, ll y) { return weight(y) - weight(x); }\r\n};\n"
  code: "class UnionFindWeight {\r\npublic:\r\n  std::vector<ll> m_root;\r\n  std::vector<ll>\
    \ m_rank;\r\n  std::vector<ll> m_weight;\r\n\r\n  ll root(ll x) {\r\n    if (m_root[x]\
    \ == x) { return x; }\r\n    ll r = root(m_root[x]);\r\n    m_weight[x] += m_weight[m_root[x]];\r\
    \n    return m_root[x] = r;\r\n  }\r\n  ll weight(ll x) {\r\n    root(x);\r\n\
    \    return m_weight[x];\r\n  }\r\n\r\npublic:\r\n  UnionFindWeight() = delete;\r\
    \n  UnionFindWeight(ll n) : m_root(n), m_rank(n), m_weight(n) {\r\n    std::iota(m_root.begin(),\
    \ m_root.end(), 0);\r\n  }\r\n  bool isSame(ll x, ll y) { return root(x) == root(y);\
    \ }\r\n  bool merge(ll x, ll y, ll w) {\r\n    w += weight(x);\r\n    w -= weight(y);\r\
    \n    x = root(x);\r\n    y = root(y);\r\n    if (x == y) { return false; }\r\n\
    \    if (m_rank[x] < m_rank[y]) {\r\n      std::swap(x, y);\r\n      w = -w;\r\
    \n    }\r\n    if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }\r\n    m_root[y] =\
    \ x;\r\n    m_weight[y] = w;\r\n    return true;\r\n  }\r\n  ll diffWeight(ll\
    \ x, ll y) { return weight(y) - weight(x); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/UnionFindWeight.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/DataStructure/UnionFindWeight.cpp
layout: document
redirect_from:
- /library/Library/DataStructure/UnionFindWeight.cpp
- /library/Library/DataStructure/UnionFindWeight.cpp.html
title: Library/DataStructure/UnionFindWeight.cpp
---
