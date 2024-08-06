---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/DataStructure/UnionFind.hpp
    title: Library/DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1390
    links:
    - https://yukicoder.me/problems/no/1390
  bundledCode: "#line 1 \"Test/DataStructure/UnionFind.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1390\"\r\n\r\n#line 2 \"Library/DataStructure/UnionFind.hpp\"\
    \n#include <numeric>\r\n#include <vector>\r\n/**\r\n *\tUnionFind\u6728\u3092\u69CB\
    \u6210\u3059\u308B\r\n *\tnode\u306E\u6DF1\u3055\uFF0C\u6728\u306E\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\u53EF\u80FD\r\n */\r\nclass UnionFind {\r\n  std::vector<int>\
    \ m_root;\r\n  std::vector<int> m_depth;\r\n  std::vector<int> m_size;\r\n\r\n\
    public:\r\n  UnionFind(int size) : m_root(size), m_depth(size, 0), m_size(size,\
    \ 1) {\r\n    std::iota(m_root.begin(), m_root.end(), 0);\r\n  }\r\n  void unite(int\
    \ x, int y) {\r\n    x = root(x);\r\n    y = root(y);\r\n    if (x == y) { return;\
    \ }\r\n    auto t = size(x) + size(y);\r\n    m_size[x] = m_size[y] = t;\r\n \
    \   if (m_depth[x] < m_depth[y]) {\r\n      m_root[x] = y;\r\n    } else {\r\n\
    \      m_root[y] = x;\r\n    }\r\n    if (m_depth[x] == m_depth[y]) { ++m_depth[x];\
    \ }\r\n  }\r\n  bool isSame(int x, int y) { return root(x) == root(y); }\r\n \
    \ int root(int x) {\r\n    if (m_root[x] == x) { return x; }\r\n    return m_root[x]\
    \ = root(m_root[x]);\r\n  }\r\n  int size(int x) {\r\n    if (m_root[x] == x)\
    \ { return m_size[x]; }\r\n    return size(m_root[x] = root(m_root[x]));\r\n \
    \ }\r\n};\r\n#line 4 \"Test/DataStructure/UnionFind.test.cpp\"\n\r\n#include <deque>\r\
    \n#include <iostream>\r\n#line 8 \"Test/DataStructure/UnionFind.test.cpp\"\n\r\
    \nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char\
    \ endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n, m;\r\n  cin >> n >> m;\r\n \
    \ std::vector<std::deque<ll>> cv(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n  \
    \  ll b, c;\r\n    cin >> b >> c;\r\n    cv[c - 1].emplace_back(b - 1);\r\n  }\r\
    \n\r\n  auto dsu = UnionFind(m);\r\n\r\n  ll ans = 0;\r\n  for (const auto& dq\
    \ : cv)\r\n    if (!dq.empty()) {\r\n      auto base = dq.front();\r\n      for\
    \ (const auto& tg : dq) {\r\n        if (!dsu.isSame(base, tg)) {\r\n        \
    \  dsu.unite(base, tg);\r\n          ++ans;\r\n        }\r\n      }\r\n    }\r\
    \n  cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1390\"\r\n\r\n#include\
    \ \"./../../Library/DataStructure/UnionFind.hpp\"\r\n\r\n#include <deque>\r\n\
    #include <iostream>\r\n#include <vector>\r\n\r\nusing ll = long long;\r\nusing\
    \ std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\n\r\nsigned\
    \ main() {\r\n  ll n, m;\r\n  cin >> n >> m;\r\n  std::vector<std::deque<ll>>\
    \ cv(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    ll b, c;\r\n    cin >> b >>\
    \ c;\r\n    cv[c - 1].emplace_back(b - 1);\r\n  }\r\n\r\n  auto dsu = UnionFind(m);\r\
    \n\r\n  ll ans = 0;\r\n  for (const auto& dq : cv)\r\n    if (!dq.empty()) {\r\
    \n      auto base = dq.front();\r\n      for (const auto& tg : dq) {\r\n     \
    \   if (!dsu.isSame(base, tg)) {\r\n          dsu.unite(base, tg);\r\n       \
    \   ++ans;\r\n        }\r\n      }\r\n    }\r\n  cout << ans << endl;\r\n}"
  dependsOn:
  - Library/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: Test/DataStructure/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/UnionFind.test.cpp
- /verify/Test/DataStructure/UnionFind.test.cpp.html
title: Test/DataStructure/UnionFind.test.cpp
---
