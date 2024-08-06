---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/String/TrieTree.test.cpp
    title: Test/String/TrieTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/String/TrieTree.hpp\"\n\r\n#include <memory>\r\n\
    #include <vector>\r\n\r\nconstexpr auto nullLambda = [](int n) {};\r\ntemplate\
    \ <class Val = bool, Val ignore = false>\r\nclass TrieTree {\r\n  Val m_val;\r\
    \n  std::vector<std::unique_ptr<TrieTree>> m_next;\r\n  // static constexpr auto\
    \ nullLambda = [](ll n) {}; c++17\r\n\r\n  auto emplace(const std::vector<int>&\
    \ vec, Val val, int it) {\r\n    if (it == vec.size()) {\r\n      m_val = val;\r\
    \n      return;\r\n    }\r\n    if (!m_next[vec[it]]) { m_next[vec[it]] = std::make_unique<TrieTree>();\
    \ }\r\n    m_next[vec[it]]->emplace(vec, val, it + 1);\r\n  }\r\n\r\n  template\
    \ <class Lambda>\r\n  auto find(const std::vector<int>& vec, int it, const Lambda&\
    \ lambda) const {\r\n    if (m_val != ignore) { lambda(m_val); }\r\n    if (it\
    \ == vec.size()) { return m_val; }\r\n    if (!m_next[vec[it]]) { return ignore;\
    \ }\r\n    return m_next[vec[it]]->find(vec, it + 1, lambda);\r\n  }\r\n\r\npublic:\r\
    \n  TrieTree() : TrieTree(ignore) {}\r\n  TrieTree(Val val)\r\n      : m_val(val),\
    \ m_next(std::vector<std::unique_ptr<TrieTree>>(26)) {}\r\n\r\n  auto emplace(const\
    \ std::vector<int>& vec, Val val) {\r\n    return emplace(vec, val, 0);\r\n  }\r\
    \n\r\n  template <class Lambda = decltype(nullLambda)>\r\n  auto find(const std::vector<int>&\
    \ vec, const Lambda& lambda = nullLambda) {\r\n    return find(vec, 0, lambda);\r\
    \n  }\r\n};\n"
  code: "#pragma once\r\n\r\n#include <memory>\r\n#include <vector>\r\n\r\nconstexpr\
    \ auto nullLambda = [](int n) {};\r\ntemplate <class Val = bool, Val ignore =\
    \ false>\r\nclass TrieTree {\r\n  Val m_val;\r\n  std::vector<std::unique_ptr<TrieTree>>\
    \ m_next;\r\n  // static constexpr auto nullLambda = [](ll n) {}; c++17\r\n\r\n\
    \  auto emplace(const std::vector<int>& vec, Val val, int it) {\r\n    if (it\
    \ == vec.size()) {\r\n      m_val = val;\r\n      return;\r\n    }\r\n    if (!m_next[vec[it]])\
    \ { m_next[vec[it]] = std::make_unique<TrieTree>(); }\r\n    m_next[vec[it]]->emplace(vec,\
    \ val, it + 1);\r\n  }\r\n\r\n  template <class Lambda>\r\n  auto find(const std::vector<int>&\
    \ vec, int it, const Lambda& lambda) const {\r\n    if (m_val != ignore) { lambda(m_val);\
    \ }\r\n    if (it == vec.size()) { return m_val; }\r\n    if (!m_next[vec[it]])\
    \ { return ignore; }\r\n    return m_next[vec[it]]->find(vec, it + 1, lambda);\r\
    \n  }\r\n\r\npublic:\r\n  TrieTree() : TrieTree(ignore) {}\r\n  TrieTree(Val val)\r\
    \n      : m_val(val), m_next(std::vector<std::unique_ptr<TrieTree>>(26)) {}\r\n\
    \r\n  auto emplace(const std::vector<int>& vec, Val val) {\r\n    return emplace(vec,\
    \ val, 0);\r\n  }\r\n\r\n  template <class Lambda = decltype(nullLambda)>\r\n\
    \  auto find(const std::vector<int>& vec, const Lambda& lambda = nullLambda) {\r\
    \n    return find(vec, 0, lambda);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/TrieTree.hpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/String/TrieTree.test.cpp
documentation_of: Library/String/TrieTree.hpp
layout: document
redirect_from:
- /library/Library/String/TrieTree.hpp
- /library/Library/String/TrieTree.hpp.html
title: Library/String/TrieTree.hpp
---
