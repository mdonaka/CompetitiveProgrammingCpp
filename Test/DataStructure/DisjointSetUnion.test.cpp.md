---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/DataStructure/DisjointSetUnion.hpp
    title: Library/DataStructure/DisjointSetUnion.hpp
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
  bundledCode: "#line 1 \"Test/DataStructure/DisjointSetUnion.test.cpp\"\n#include\
    \ <vector>\r\n#define PROBLEM \"https://yukicoder.me/problems/no/1390\"\r\n\r\n\
    #include <iostream>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/DisjointSetUnion.hpp\"\
    \n\r\n#line 4 \"Library/DataStructure/DisjointSetUnion.hpp\"\n#include <numeric>\r\
    \n#line 6 \"Library/DataStructure/DisjointSetUnion.hpp\"\n\r\nnamespace mtd {\r\
    \n\r\n  template <class T = int>\r\n  class PotentialDisjointSetUnion {\r\n  \
    \  std::vector<int> m_root;\r\n    std::vector<int> m_rank;\r\n    std::vector<int>\
    \ m_size;\r\n    std::vector<T> m_potential;\r\n\r\n  public:\r\n    PotentialDisjointSetUnion()\
    \ = delete;\r\n    PotentialDisjointSetUnion(int n)\r\n        : m_root(n), m_rank(n),\
    \ m_size(n), m_potential(n) {\r\n      std::iota(m_root.begin(), m_root.end(),\
    \ 0);\r\n    }\r\n\r\n    auto unite(int x, int y, T p = 0) {\r\n      p += potential(x);\r\
    \n      p -= potential(y);\r\n      x = root(x);\r\n      y = root(y);\r\n   \
    \   if (x == y) { return false; }\r\n      if (m_rank[x] < m_rank[y]) {\r\n  \
    \      std::swap(x, y);\r\n        p = -p;\r\n      }\r\n      if (m_rank[x] ==\
    \ m_rank[y]) { ++m_rank[x]; }\r\n      m_size[x] = m_size[y] = size(x) + size(y);\r\
    \n      m_root[y] = x;\r\n      m_potential[y] = p;\r\n      return true;\r\n\
    \    }\r\n\r\n    auto root(int x) -> int {\r\n      if (m_root[x] == x) { return\
    \ x; }\r\n      int r = root(m_root[x]);\r\n      m_potential[x] += m_potential[m_root[x]];\r\
    \n      return m_root[x] = r;\r\n    }\r\n\r\n    auto potential(int x) -> T {\r\
    \n      root(x);\r\n      return m_potential[x];\r\n    }\r\n\r\n    auto size(int\
    \ x) -> int {\r\n      if (m_root[x] == x) { return m_size[x]; }\r\n      return\
    \ size(m_root[x] = root(m_root[x]));\r\n    }\r\n\r\n    auto isSame(int x, int\
    \ y) { return root(x) == root(y); }\r\n\r\n    auto diff(int x, int y) { return\
    \ potential(y) - potential(x); }\r\n\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os,\r\n                                    const PotentialDisjointSetUnion&\
    \ dsu) {\r\n      for (const auto& x : dsu.m_root) { os << x << \" \"; }\r\n \
    \     return os;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n#line 8 \"Test/DataStructure/DisjointSetUnion.test.cpp\"\
    \n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ cv(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    int b, c;\r\n    std::cin >>\
    \ b >> c;\r\n    cv[c - 1].emplace_back(b - 1);\r\n  }\r\n\r\n  auto dsu = mtd::PotentialDisjointSetUnion(m);\r\
    \n\r\n  int ans = 0;\r\n  for (const auto& v : cv)\r\n    if (!v.empty()) {\r\n\
    \      auto base = v.front();\r\n      for (const auto& tg : v) {\r\n        if\
    \ (!dsu.isSame(base, tg)) {\r\n          dsu.unite(base, tg);\r\n          ++ans;\r\
    \n        }\r\n      }\r\n    }\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  code: "#include <vector>\r\n#define PROBLEM \"https://yukicoder.me/problems/no/1390\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#include \"./../../Library/DataStructure/DisjointSetUnion.hpp\"\
    \r\n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ cv(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\n    int b, c;\r\n    std::cin >>\
    \ b >> c;\r\n    cv[c - 1].emplace_back(b - 1);\r\n  }\r\n\r\n  auto dsu = mtd::PotentialDisjointSetUnion(m);\r\
    \n\r\n  int ans = 0;\r\n  for (const auto& v : cv)\r\n    if (!v.empty()) {\r\n\
    \      auto base = v.front();\r\n      for (const auto& tg : v) {\r\n        if\
    \ (!dsu.isSame(base, tg)) {\r\n          dsu.unite(base, tg);\r\n          ++ans;\r\
    \n        }\r\n      }\r\n    }\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/DisjointSetUnion.hpp
  isVerificationFile: true
  path: Test/DataStructure/DisjointSetUnion.test.cpp
  requiredBy: []
  timestamp: '2024-12-19 16:02:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/DisjointSetUnion.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/DisjointSetUnion.test.cpp
- /verify/Test/DataStructure/DisjointSetUnion.test.cpp.html
title: Test/DataStructure/DisjointSetUnion.test.cpp
---
