---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/ConvexHullTrick.test.cpp
    title: Test/DataStructure/ConvexHullTrick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/ConvecHullTrick.hpp\"\n\r\n#include\
    \ <deque>\r\n\r\nnamespace mtd {\r\n  /*\r\n   * \u76F4\u7DDA\u306F\u50BE\u304D\
    \u306B\u3064\u3044\u3066\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11(\u6700\u5927\u5024\
    \u30AF\u30A8\u30EA\u306E\u5834\u5408\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\
    )\r\n   * \u30AF\u30A8\u30EA\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\r\n   */\r\
    \n  class ConvexHullTrick {\r\n    using T = long long;\r\n    std::deque<std::pair<T,\
    \ T>> lines;\r\n\r\n    static auto func(const std::pair<T, T>& line, const T&\
    \ x) {\r\n      return x * line.first + line.second;\r\n    }\r\n    static auto\
    \ check(const std::pair<T, T>& line1,\r\n                      const std::pair<T,\
    \ T>& line2,\r\n                      const std::pair<T, T>& line3) {\r\n    \
    \  auto [a1, b1] = line1;\r\n      auto [a2, b2] = line2;\r\n      auto [a3, b3]\
    \ = line3;\r\n      return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);\r\n\
    \    }\r\n\r\n  public:\r\n    ConvexHullTrick() {}\r\n\r\n    auto add(const\
    \ std::pair<T, T>& line) {\r\n      while (lines.size() > 1 &&\r\n           \
    \  check(*std::next(lines.rbegin()), *lines.rbegin(), line)) {\r\n        lines.pop_back();\r\
    \n      }\r\n      lines.emplace_back(line);\r\n    }\r\n    auto add(const T&\
    \ a, const T& b) { add({a, b}); }\r\n\r\n    auto query(const T& x) {\r\n    \
    \  while (lines.size() > 1 &&\r\n             func(*lines.begin(), x) > func(*std::next(lines.begin()),\
    \ x)) {\r\n        lines.pop_front();\r\n      }\r\n      return func(*lines.begin(),\
    \ x);\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <deque>\r\n\r\nnamespace mtd {\r\n  /*\r\n \
    \  * \u76F4\u7DDA\u306F\u50BE\u304D\u306B\u3064\u3044\u3066\u5E83\u7FA9\u5358\u8ABF\
    \u6E1B\u5C11(\u6700\u5927\u5024\u30AF\u30A8\u30EA\u306E\u5834\u5408\u306F\u5E83\
    \u7FA9\u5358\u8ABF\u5897\u52A0)\r\n   * \u30AF\u30A8\u30EA\u306F\u5E83\u7FA9\u5358\
    \u8ABF\u5897\u52A0\r\n   */\r\n  class ConvexHullTrick {\r\n    using T = long\
    \ long;\r\n    std::deque<std::pair<T, T>> lines;\r\n\r\n    static auto func(const\
    \ std::pair<T, T>& line, const T& x) {\r\n      return x * line.first + line.second;\r\
    \n    }\r\n    static auto check(const std::pair<T, T>& line1,\r\n           \
    \           const std::pair<T, T>& line2,\r\n                      const std::pair<T,\
    \ T>& line3) {\r\n      auto [a1, b1] = line1;\r\n      auto [a2, b2] = line2;\r\
    \n      auto [a3, b3] = line3;\r\n      return (a2 - a1) * (b3 - b2) >= (b2 -\
    \ b1) * (a3 - a2);\r\n    }\r\n\r\n  public:\r\n    ConvexHullTrick() {}\r\n\r\
    \n    auto add(const std::pair<T, T>& line) {\r\n      while (lines.size() > 1\
    \ &&\r\n             check(*std::next(lines.rbegin()), *lines.rbegin(), line))\
    \ {\r\n        lines.pop_back();\r\n      }\r\n      lines.emplace_back(line);\r\
    \n    }\r\n    auto add(const T& a, const T& b) { add({a, b}); }\r\n\r\n    auto\
    \ query(const T& x) {\r\n      while (lines.size() > 1 &&\r\n             func(*lines.begin(),\
    \ x) > func(*std::next(lines.begin()), x)) {\r\n        lines.pop_front();\r\n\
    \      }\r\n      return func(*lines.begin(), x);\r\n    }\r\n  };\r\n}  // namespace\
    \ mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/ConvecHullTrick.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/ConvexHullTrick.test.cpp
documentation_of: Library/DataStructure/ConvecHullTrick.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/ConvecHullTrick.hpp
- /library/Library/DataStructure/ConvecHullTrick.hpp.html
title: Library/DataStructure/ConvecHullTrick.hpp
---
