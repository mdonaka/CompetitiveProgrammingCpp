---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/CoordinateCompression_comp.test.cpp
    title: Test/Algorithms/CoordinateCompression_comp.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/CoordinateCompression_to.test.cpp
    title: Test/Algorithms/CoordinateCompression_to.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algorithms/CoordinateCompression.hpp\"\n\r\n#include\
    \ <algorithm>\r\n#include <unordered_map>\r\n#include <vector>\r\n\r\nnamespace\
    \ mtd {\r\n\r\n  class CoordinateCompression {\r\n    const std::vector<long long>\
    \ m_v;\r\n    const std::vector<long long> m_itox;\r\n    const std::unordered_map<long\
    \ long, int> m_xtoi;\r\n\r\n    static inline auto c_itox(const std::vector<long\
    \ long>& v) {\r\n      auto itox = v;\r\n      std::sort(itox.begin(), itox.end());\r\
    \n      itox.erase(std::unique(itox.begin(), itox.end()), itox.end());\r\n   \
    \   return itox;\r\n    }\r\n    static inline auto c_xtoi(const std::vector<long\
    \ long>& itox) {\r\n      std::unordered_map<long long, int> xtoi;\r\n      for\
    \ (unsigned int i = 0; i < itox.size(); ++i) {\r\n        xtoi.emplace(itox[i],\
    \ i);\r\n      }\r\n      return xtoi;\r\n    }\r\n\r\n  public:\r\n    CoordinateCompression(const\
    \ std::vector<long long>& v)\r\n        : m_v(v), m_itox(c_itox(v)), m_xtoi(c_xtoi(m_itox))\
    \ {}\r\n    auto size() const { return m_itox.size(); }\r\n    auto toi(long long\
    \ x) const { return m_xtoi.at(x); }\r\n    auto tox(int i) const { return m_itox[i];\
    \ }\r\n    auto c(const std::vector<long long>& v) const {\r\n      std::vector<long\
    \ long> ret;\r\n      ret.reserve(size());\r\n      for (const auto& x : v) {\
    \ ret.emplace_back(toi(x)); }\r\n      return ret;\r\n    }\r\n    auto c() const\
    \ { return c(m_v); }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <unordered_map>\r\n\
    #include <vector>\r\n\r\nnamespace mtd {\r\n\r\n  class CoordinateCompression\
    \ {\r\n    const std::vector<long long> m_v;\r\n    const std::vector<long long>\
    \ m_itox;\r\n    const std::unordered_map<long long, int> m_xtoi;\r\n\r\n    static\
    \ inline auto c_itox(const std::vector<long long>& v) {\r\n      auto itox = v;\r\
    \n      std::sort(itox.begin(), itox.end());\r\n      itox.erase(std::unique(itox.begin(),\
    \ itox.end()), itox.end());\r\n      return itox;\r\n    }\r\n    static inline\
    \ auto c_xtoi(const std::vector<long long>& itox) {\r\n      std::unordered_map<long\
    \ long, int> xtoi;\r\n      for (unsigned int i = 0; i < itox.size(); ++i) {\r\
    \n        xtoi.emplace(itox[i], i);\r\n      }\r\n      return xtoi;\r\n    }\r\
    \n\r\n  public:\r\n    CoordinateCompression(const std::vector<long long>& v)\r\
    \n        : m_v(v), m_itox(c_itox(v)), m_xtoi(c_xtoi(m_itox)) {}\r\n    auto size()\
    \ const { return m_itox.size(); }\r\n    auto toi(long long x) const { return\
    \ m_xtoi.at(x); }\r\n    auto tox(int i) const { return m_itox[i]; }\r\n    auto\
    \ c(const std::vector<long long>& v) const {\r\n      std::vector<long long> ret;\r\
    \n      ret.reserve(size());\r\n      for (const auto& x : v) { ret.emplace_back(toi(x));\
    \ }\r\n      return ret;\r\n    }\r\n    auto c() const { return c(m_v); }\r\n\
    \  };\r\n\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/CoordinateCompression.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Algorithms/CoordinateCompression_comp.test.cpp
  - Test/Algorithms/CoordinateCompression_to.test.cpp
documentation_of: Library/Algorithms/CoordinateCompression.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/CoordinateCompression.hpp
- /library/Library/Algorithms/CoordinateCompression.hpp.html
title: Library/Algorithms/CoordinateCompression.hpp
---
