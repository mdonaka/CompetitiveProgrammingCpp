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
  bundledCode: "#line 1 \"Library/Container/UnionFindWeight.cpp\"\nclass UnionFindWeight\
    \ {\r\npublic:\r\n\tstd::vector<ll> m_root;\r\n\tstd::vector<ll> m_rank;\r\n\t\
    std::vector<ll> m_weight;\r\n\r\n\tll root(ll x) {\r\n\t\tif (m_root[x] == x)\
    \ { return x; }\r\n\t\tll r = root(m_root[x]);\r\n\t\tm_weight[x] += m_weight[m_root[x]];\r\
    \n\t\treturn m_root[x] = r;\r\n\t}\r\n\tll weight(ll x) {\r\n\t\troot(x);\r\n\t\
    \treturn m_weight[x];\r\n\t}\r\npublic:\r\n\tUnionFindWeight() = delete;\r\n\t\
    UnionFindWeight(ll n) :m_root(n), m_rank(n), m_weight(n) {\r\n\t\tstd::iota(m_root.begin(),\
    \ m_root.end(), 0);\r\n\t}\r\n\tbool isSame(ll x, ll y) {\r\n\t\treturn root(x)\
    \ == root(y);\r\n\t}\r\n\tbool merge(ll x, ll y, ll w) {\r\n\t\tw += weight(x);\
    \ w -= weight(y);\r\n\t\tx = root(x); y = root(y);\r\n\t\tif (x == y) { return\
    \ false; }\r\n\t\tif (m_rank[x] < m_rank[y]) { std::swap(x, y); w = -w; }\r\n\t\
    \tif (m_rank[x] == m_rank[y]) { ++m_rank[x]; }\r\n\t\tm_root[y] = x;\r\n\t\tm_weight[y]\
    \ = w;\r\n\t\treturn true;\r\n\t}\r\n\tll diffWeight(ll x, ll y) {\r\n\t\treturn\
    \ weight(y) - weight(x);\r\n\t}\r\n};\n"
  code: "class UnionFindWeight {\r\npublic:\r\n\tstd::vector<ll> m_root;\r\n\tstd::vector<ll>\
    \ m_rank;\r\n\tstd::vector<ll> m_weight;\r\n\r\n\tll root(ll x) {\r\n\t\tif (m_root[x]\
    \ == x) { return x; }\r\n\t\tll r = root(m_root[x]);\r\n\t\tm_weight[x] += m_weight[m_root[x]];\r\
    \n\t\treturn m_root[x] = r;\r\n\t}\r\n\tll weight(ll x) {\r\n\t\troot(x);\r\n\t\
    \treturn m_weight[x];\r\n\t}\r\npublic:\r\n\tUnionFindWeight() = delete;\r\n\t\
    UnionFindWeight(ll n) :m_root(n), m_rank(n), m_weight(n) {\r\n\t\tstd::iota(m_root.begin(),\
    \ m_root.end(), 0);\r\n\t}\r\n\tbool isSame(ll x, ll y) {\r\n\t\treturn root(x)\
    \ == root(y);\r\n\t}\r\n\tbool merge(ll x, ll y, ll w) {\r\n\t\tw += weight(x);\
    \ w -= weight(y);\r\n\t\tx = root(x); y = root(y);\r\n\t\tif (x == y) { return\
    \ false; }\r\n\t\tif (m_rank[x] < m_rank[y]) { std::swap(x, y); w = -w; }\r\n\t\
    \tif (m_rank[x] == m_rank[y]) { ++m_rank[x]; }\r\n\t\tm_root[y] = x;\r\n\t\tm_weight[y]\
    \ = w;\r\n\t\treturn true;\r\n\t}\r\n\tll diffWeight(ll x, ll y) {\r\n\t\treturn\
    \ weight(y) - weight(x);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/UnionFindWeight.cpp
  requiredBy: []
  timestamp: '2019-06-01 18:40:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Container/UnionFindWeight.cpp
layout: document
redirect_from:
- /library/Library/Container/UnionFindWeight.cpp
- /library/Library/Container/UnionFindWeight.cpp.html
title: Library/Container/UnionFindWeight.cpp
---
