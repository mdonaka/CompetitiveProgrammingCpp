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
  bundledCode: "#line 2 \"Library/Container/ConvecHullTrick.hpp\"\n\r\n#include <deque>\r\
    \n\r\n/*\r\n * \u76F4\u7DDA\u306F\u50BE\u304D\u306B\u3064\u3044\u3066\u5E83\u7FA9\
    \u5358\u8ABF\u6E1B\u5C11(\u6700\u5927\u5024\u30AF\u30A8\u30EA\u306E\u5834\u5408\
    \u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0)\r\n * \u30AF\u30A8\u30EA\u306F\u5E83\
    \u7FA9\u5358\u8ABF\u5897\u52A0\r\n */\r\nclass ConvexHullTrick {\r\n    using\
    \ T = long long;\r\n    std::deque<std::pair<T, T>> lines;\r\n\r\n    static auto\
    \ func(const std::pair<T, T>& line, const T& x) {\r\n        return x * line.first\
    \ + line.second;\r\n    }\r\n    static auto check(const std::pair<T, T>& line1,\
    \ const std::pair<T, T>& line2, const std::pair<T, T>& line3) {\r\n        auto\
    \ [a1, b1] = line1;\r\n        auto [a2, b2] = line2;\r\n        auto [a3, b3]\
    \ = line3;\r\n        return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);\r\
    \n    }\r\n\r\npublic:\r\n    ConvexHullTrick() {}\r\n\r\n    auto add(const std::pair<T,\
    \ T>& line) {\r\n        while(lines.size() > 1 &&\r\n              check(*std::next(lines.rbegin()),\
    \ *lines.rbegin(), line)) {\r\n            lines.pop_back();\r\n        }\r\n\
    \        lines.emplace_back(line);\r\n    }\r\n    auto add(const T& a, const\
    \ T& b) { add({a,b}); }\r\n\r\n    auto query(const T& x) {\r\n        while(lines.size()\
    \ > 1 &&\r\n              func(*lines.begin(), x) > func(*std::next(lines.begin()),\
    \ x)) {\r\n            lines.pop_front();\r\n        }\r\n        return func(*lines.begin(),\
    \ x);\r\n    }\r\n};\r\n\r\n"
  code: "#pragma once\r\n\r\n#include <deque>\r\n\r\n/*\r\n * \u76F4\u7DDA\u306F\u50BE\
    \u304D\u306B\u3064\u3044\u3066\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11(\u6700\u5927\
    \u5024\u30AF\u30A8\u30EA\u306E\u5834\u5408\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\
    \u52A0)\r\n * \u30AF\u30A8\u30EA\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\r\n\
    \ */\r\nclass ConvexHullTrick {\r\n    using T = long long;\r\n    std::deque<std::pair<T,\
    \ T>> lines;\r\n\r\n    static auto func(const std::pair<T, T>& line, const T&\
    \ x) {\r\n        return x * line.first + line.second;\r\n    }\r\n    static\
    \ auto check(const std::pair<T, T>& line1, const std::pair<T, T>& line2, const\
    \ std::pair<T, T>& line3) {\r\n        auto [a1, b1] = line1;\r\n        auto\
    \ [a2, b2] = line2;\r\n        auto [a3, b3] = line3;\r\n        return (a2 -\
    \ a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);\r\n    }\r\n\r\npublic:\r\n    ConvexHullTrick()\
    \ {}\r\n\r\n    auto add(const std::pair<T, T>& line) {\r\n        while(lines.size()\
    \ > 1 &&\r\n              check(*std::next(lines.rbegin()), *lines.rbegin(), line))\
    \ {\r\n            lines.pop_back();\r\n        }\r\n        lines.emplace_back(line);\r\
    \n    }\r\n    auto add(const T& a, const T& b) { add({a,b}); }\r\n\r\n    auto\
    \ query(const T& x) {\r\n        while(lines.size() > 1 &&\r\n              func(*lines.begin(),\
    \ x) > func(*std::next(lines.begin()), x)) {\r\n            lines.pop_front();\r\
    \n        }\r\n        return func(*lines.begin(), x);\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/ConvecHullTrick.hpp
  requiredBy: []
  timestamp: '2023-03-07 02:07:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Container/ConvecHullTrick.hpp
layout: document
redirect_from:
- /library/Library/Container/ConvecHullTrick.hpp
- /library/Library/Container/ConvecHullTrick.hpp.html
title: Library/Container/ConvecHullTrick.hpp
---
