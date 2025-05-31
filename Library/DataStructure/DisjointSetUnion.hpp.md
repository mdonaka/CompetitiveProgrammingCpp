---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Kruskal.hpp
    title: Library/Graph/Normal/Kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DisjointSetUnion.test.cpp
    title: Test/DataStructure/DisjointSetUnion.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DisjointSetUnion_Potential.test.cpp
    title: Test/DataStructure/DisjointSetUnion_Potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Kruskal.test.cpp
    title: Test/Graph/Normal/Kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/DisjointSetUnion.hpp\"\n\r\n#include\
    \ <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\
    \n\r\n  template <class T = int>\r\n  class PotentialDisjointSetUnion {\r\n  \
    \  std::vector<int> m_root;\r\n    std::vector<int> m_rank;\r\n    std::vector<int>\
    \ m_size;\r\n    std::vector<T> m_potential;\r\n\r\n  public:\r\n    PotentialDisjointSetUnion()\
    \ = delete;\r\n    PotentialDisjointSetUnion(int n)\r\n        : m_root(n), m_rank(n),\
    \ m_size(n, 1), m_potential(n) {\r\n      std::iota(m_root.begin(), m_root.end(),\
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
    \     return os;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <iostream>\r\n#include <numeric>\r\n#include\
    \ <vector>\r\n\r\nnamespace mtd {\r\n\r\n  template <class T = int>\r\n  class\
    \ PotentialDisjointSetUnion {\r\n    std::vector<int> m_root;\r\n    std::vector<int>\
    \ m_rank;\r\n    std::vector<int> m_size;\r\n    std::vector<T> m_potential;\r\
    \n\r\n  public:\r\n    PotentialDisjointSetUnion() = delete;\r\n    PotentialDisjointSetUnion(int\
    \ n)\r\n        : m_root(n), m_rank(n), m_size(n, 1), m_potential(n) {\r\n   \
    \   std::iota(m_root.begin(), m_root.end(), 0);\r\n    }\r\n\r\n    auto unite(int\
    \ x, int y, T p = 0) {\r\n      p += potential(x);\r\n      p -= potential(y);\r\
    \n      x = root(x);\r\n      y = root(y);\r\n      if (x == y) { return false;\
    \ }\r\n      if (m_rank[x] < m_rank[y]) {\r\n        std::swap(x, y);\r\n    \
    \    p = -p;\r\n      }\r\n      if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }\r\
    \n      m_size[x] = m_size[y] = size(x) + size(y);\r\n      m_root[y] = x;\r\n\
    \      m_potential[y] = p;\r\n      return true;\r\n    }\r\n\r\n    auto root(int\
    \ x) -> int {\r\n      if (m_root[x] == x) { return x; }\r\n      int r = root(m_root[x]);\r\
    \n      m_potential[x] += m_potential[m_root[x]];\r\n      return m_root[x] =\
    \ r;\r\n    }\r\n\r\n    auto potential(int x) -> T {\r\n      root(x);\r\n  \
    \    return m_potential[x];\r\n    }\r\n\r\n    auto size(int x) -> int {\r\n\
    \      if (m_root[x] == x) { return m_size[x]; }\r\n      return size(m_root[x]\
    \ = root(m_root[x]));\r\n    }\r\n\r\n    auto isSame(int x, int y) { return root(x)\
    \ == root(y); }\r\n\r\n    auto diff(int x, int y) { return potential(y) - potential(x);\
    \ }\r\n\r\n    friend std::ostream& operator<<(std::ostream& os,\r\n         \
    \                           const PotentialDisjointSetUnion& dsu) {\r\n      for\
    \ (const auto& x : dsu.m_root) { os << x << \" \"; }\r\n      return os;\r\n \
    \   }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/DisjointSetUnion.hpp
  requiredBy:
  - Library/Graph/Normal/Kruskal.hpp
  timestamp: '2024-12-25 00:03:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/DisjointSetUnion.test.cpp
  - Test/DataStructure/DisjointSetUnion_Potential.test.cpp
  - Test/Graph/Normal/Kruskal.test.cpp
documentation_of: Library/DataStructure/DisjointSetUnion.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/DisjointSetUnion.hpp
- /library/Library/DataStructure/DisjointSetUnion.hpp.html
title: Library/DataStructure/DisjointSetUnion.hpp
---
