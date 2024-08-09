---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Utility/Prime.test.cpp
    title: Test/Utility/Prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/Prime.hpp\"\n\r\n#include <deque>\r\n#include\
    \ <unordered_map>\r\n#include <vector>\r\n\r\nclass Prime {\r\n  const long long\
    \ n;\r\n  const std::deque<long long> p_list;\r\n\r\n  static inline auto linearSieve(long\
    \ long n) {\r\n    std::deque<long long> p_list;\r\n    std::vector<long long>\
    \ lpf(n + 1);\r\n    for (int d = 2; d < n + 1; ++d) {\r\n      if (!lpf[d]) {\r\
    \n        lpf[d] = d;\r\n        p_list.emplace_back(d);\r\n      }\r\n      for\
    \ (const auto& p : p_list) {\r\n        if (p * d > n || p > lpf[d]) { break;\
    \ }\r\n        lpf[p * d] = p;\r\n      }\r\n    }\r\n    return std::tuple{p_list,\
    \ lpf};\r\n  }\r\n\r\npublic:\r\n  Prime(long long n) : n(n), p_list(std::get<0>(linearSieve(n)))\
    \ {}\r\n\r\n  /* n\u306Fsqrt(max(x))\u3042\u308C\u3070\u5341\u5206\u306A\u306E\
    \u3067\u6C17\u3092\u4ED8\u3051\u308B */\r\n  auto factorization(long long x) const\
    \ {\r\n    std::unordered_map<long long, long long> table;\r\n    for (const auto&\
    \ p : p_list) {\r\n      while (x % p == 0) {\r\n        table[p]++;\r\n     \
    \   x /= p;\r\n      }\r\n    }\r\n    if (x > 1) { table[x]++; }\r\n    return\
    \ table;\r\n  }\r\n  auto getPList() const { return p_list; }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <deque>\r\n#include <unordered_map>\r\n#include\
    \ <vector>\r\n\r\nclass Prime {\r\n  const long long n;\r\n  const std::deque<long\
    \ long> p_list;\r\n\r\n  static inline auto linearSieve(long long n) {\r\n   \
    \ std::deque<long long> p_list;\r\n    std::vector<long long> lpf(n + 1);\r\n\
    \    for (int d = 2; d < n + 1; ++d) {\r\n      if (!lpf[d]) {\r\n        lpf[d]\
    \ = d;\r\n        p_list.emplace_back(d);\r\n      }\r\n      for (const auto&\
    \ p : p_list) {\r\n        if (p * d > n || p > lpf[d]) { break; }\r\n       \
    \ lpf[p * d] = p;\r\n      }\r\n    }\r\n    return std::tuple{p_list, lpf};\r\
    \n  }\r\n\r\npublic:\r\n  Prime(long long n) : n(n), p_list(std::get<0>(linearSieve(n)))\
    \ {}\r\n\r\n  /* n\u306Fsqrt(max(x))\u3042\u308C\u3070\u5341\u5206\u306A\u306E\
    \u3067\u6C17\u3092\u4ED8\u3051\u308B */\r\n  auto factorization(long long x) const\
    \ {\r\n    std::unordered_map<long long, long long> table;\r\n    for (const auto&\
    \ p : p_list) {\r\n      while (x % p == 0) {\r\n        table[p]++;\r\n     \
    \   x /= p;\r\n      }\r\n    }\r\n    if (x > 1) { table[x]++; }\r\n    return\
    \ table;\r\n  }\r\n  auto getPList() const { return p_list; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Prime.hpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Utility/Prime.test.cpp
documentation_of: Library/Utility/Prime.hpp
layout: document
redirect_from:
- /library/Library/Utility/Prime.hpp
- /library/Library/Utility/Prime.hpp.html
title: Library/Utility/Prime.hpp
---
