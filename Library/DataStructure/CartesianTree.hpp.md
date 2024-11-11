---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/CartesianTree.test.cpp
    title: Test/DataStructure/CartesianTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/CartesianTree.hpp\"\n\r\n#include\
    \ <numeric>\r\n#include <queue>\r\n#include <stack>\r\n#include <vector>\r\n\r\
    \nnamespace mtd {\r\n\r\n  template <class T>\r\n  class CartesianTree {\r\n \
    \   const int m_n;\r\n    const std::vector<int> m_par;\r\n\r\n    static auto\
    \ constructTree(const std::vector<T>& a) {\r\n      int n = (int)a.size();\r\n\
    \      std::vector<int> par(n, -1);\r\n      std::stack<int> stk;\r\n      for\
    \ (int i = 0; i < n; i++) {\r\n        int prv = -1;\r\n        while (!stk.empty()\
    \ && a[i] < a[stk.top()]) {\r\n          prv = stk.top();\r\n          stk.pop();\r\
    \n        }\r\n        if (prv != -1) { par[prv] = i; }\r\n        if (!stk.empty())\
    \ { par[i] = stk.top(); }\r\n        stk.emplace(i);\r\n      }\r\n      return\
    \ par;\r\n    }\r\n\r\n  public:\r\n    CartesianTree(const std::vector<T>& a)\r\
    \n        : m_n(a.size()), m_par(constructTree(a)) {}\r\n\r\n    auto p(int f)\
    \ const { return m_par[f]; }\r\n\r\n    auto range() const {\r\n      std::vector<int>\
    \ left(m_n), right(m_n);\r\n      std::iota(left.begin(), left.end(), 0);\r\n\
    \      std::iota(right.begin(), right.end(), 0);\r\n      std::vector<int> in(m_n);\r\
    \n      for (int f = 0; f < m_n; ++f)\r\n        if (m_par[f] > -1) { ++in[m_par[f]];\
    \ }\r\n      std::queue<int> q;\r\n      for (int f = 0; f < m_n; ++f)\r\n   \
    \     if (in[f] == 0) { q.emplace(f); }\r\n      while (!q.empty()) {\r\n    \
    \    auto f = q.front();\r\n        q.pop();\r\n        if (m_par[f] == -1) {\
    \ continue; }\r\n        left[m_par[f]] = std::min(left[f], left[m_par[f]]);\r\
    \n        right[m_par[f]] = std::max(right[f], right[m_par[f]]);\r\n        --in[m_par[f]];\r\
    \n        if (in[m_par[f]] == 0) { q.emplace(m_par[f]); }\r\n      }\r\n     \
    \ return std::make_pair(left, right);\r\n    }\r\n\r\n    auto getEdges() const\
    \ {\r\n      std::vector<std::pair<int, int>> edges;\r\n      edges.reserve(m_n);\r\
    \n      for (int f = 0; f < m_n; ++f)\r\n        if (m_par[f] > -1) { edges.emplace_back(f,\
    \ m_par[f]); }\r\n      return edges;\r\n    }\r\n  };\r\n\r\n}  // namespace\
    \ mtd\r\n"
  code: "#pragma once\r\n\r\n#include <numeric>\r\n#include <queue>\r\n#include <stack>\r\
    \n#include <vector>\r\n\r\nnamespace mtd {\r\n\r\n  template <class T>\r\n  class\
    \ CartesianTree {\r\n    const int m_n;\r\n    const std::vector<int> m_par;\r\
    \n\r\n    static auto constructTree(const std::vector<T>& a) {\r\n      int n\
    \ = (int)a.size();\r\n      std::vector<int> par(n, -1);\r\n      std::stack<int>\
    \ stk;\r\n      for (int i = 0; i < n; i++) {\r\n        int prv = -1;\r\n   \
    \     while (!stk.empty() && a[i] < a[stk.top()]) {\r\n          prv = stk.top();\r\
    \n          stk.pop();\r\n        }\r\n        if (prv != -1) { par[prv] = i;\
    \ }\r\n        if (!stk.empty()) { par[i] = stk.top(); }\r\n        stk.emplace(i);\r\
    \n      }\r\n      return par;\r\n    }\r\n\r\n  public:\r\n    CartesianTree(const\
    \ std::vector<T>& a)\r\n        : m_n(a.size()), m_par(constructTree(a)) {}\r\n\
    \r\n    auto p(int f) const { return m_par[f]; }\r\n\r\n    auto range() const\
    \ {\r\n      std::vector<int> left(m_n), right(m_n);\r\n      std::iota(left.begin(),\
    \ left.end(), 0);\r\n      std::iota(right.begin(), right.end(), 0);\r\n     \
    \ std::vector<int> in(m_n);\r\n      for (int f = 0; f < m_n; ++f)\r\n       \
    \ if (m_par[f] > -1) { ++in[m_par[f]]; }\r\n      std::queue<int> q;\r\n     \
    \ for (int f = 0; f < m_n; ++f)\r\n        if (in[f] == 0) { q.emplace(f); }\r\
    \n      while (!q.empty()) {\r\n        auto f = q.front();\r\n        q.pop();\r\
    \n        if (m_par[f] == -1) { continue; }\r\n        left[m_par[f]] = std::min(left[f],\
    \ left[m_par[f]]);\r\n        right[m_par[f]] = std::max(right[f], right[m_par[f]]);\r\
    \n        --in[m_par[f]];\r\n        if (in[m_par[f]] == 0) { q.emplace(m_par[f]);\
    \ }\r\n      }\r\n      return std::make_pair(left, right);\r\n    }\r\n\r\n \
    \   auto getEdges() const {\r\n      std::vector<std::pair<int, int>> edges;\r\
    \n      edges.reserve(m_n);\r\n      for (int f = 0; f < m_n; ++f)\r\n       \
    \ if (m_par[f] > -1) { edges.emplace_back(f, m_par[f]); }\r\n      return edges;\r\
    \n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/CartesianTree.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/CartesianTree.test.cpp
documentation_of: Library/DataStructure/CartesianTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/CartesianTree.hpp
- /library/Library/DataStructure/CartesianTree.hpp.html
title: Library/DataStructure/CartesianTree.hpp
---
