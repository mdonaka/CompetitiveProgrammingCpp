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
  bundledCode: "#line 2 \"Library/Utility/Prime.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <deque>\r\n#include <unordered_map>\r\n\r\nclass Prime {\r\n\tconst int n;\r\
    \n\tconst std::deque<int> p_list;\r\n\r\npublic:\r\n\r\n\tstatic inline auto linearSieve(int\
    \ n) {\r\n\t\tstd::deque<int> p_list;\r\n\t\tstd::vector<int> lpf(n + 1);\r\n\t\
    \tfor (int d = 2; d < n + 1; ++d) {\r\n\t\t\tif (!lpf[d]) {\r\n\t\t\t\tlpf[d]\
    \ = d;\r\n\t\t\t\tp_list.emplace_back(d);\r\n\t\t\t}\r\n\t\t\tfor (const auto&\
    \ p : p_list) {\r\n\t\t\t\tif (p * d > n || p > lpf[d]) { break; }\r\n\t\t\t\t\
    lpf[p * d] = p;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn std::tuple{ p_list,lpf };\r\n\
    \t}\r\n\r\n\tPrime(int n) :n(n), p_list(std::get<0>(linearSieve(n))) {}\r\n\r\n\
    \t/* n\u306Fsqrt(max(x))\u3042\u308C\u3070\u5341\u5206\u306A\u306E\u3067\u6C17\
    \u3092\u4ED8\u3051\u308B */\r\n\tauto factorization(int x) const {\r\n\t\tstd::unordered_map<int,\
    \ int> table;\r\n\t\tfor (const auto& p : p_list) {\r\n\t\t\twhile (x % p == 0)\
    \ {\r\n\t\t\t\ttable[p]++;\r\n\t\t\t\tx /= p;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (x\
    \ > 1) { table[x]++; }\r\n\t\treturn table;\r\n\t}\r\n\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <deque>\r\n#include <unordered_map>\r\
    \n\r\nclass Prime {\r\n\tconst int n;\r\n\tconst std::deque<int> p_list;\r\n\r\
    \npublic:\r\n\r\n\tstatic inline auto linearSieve(int n) {\r\n\t\tstd::deque<int>\
    \ p_list;\r\n\t\tstd::vector<int> lpf(n + 1);\r\n\t\tfor (int d = 2; d < n + 1;\
    \ ++d) {\r\n\t\t\tif (!lpf[d]) {\r\n\t\t\t\tlpf[d] = d;\r\n\t\t\t\tp_list.emplace_back(d);\r\
    \n\t\t\t}\r\n\t\t\tfor (const auto& p : p_list) {\r\n\t\t\t\tif (p * d > n ||\
    \ p > lpf[d]) { break; }\r\n\t\t\t\tlpf[p * d] = p;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    return std::tuple{ p_list,lpf };\r\n\t}\r\n\r\n\tPrime(int n) :n(n), p_list(std::get<0>(linearSieve(n)))\
    \ {}\r\n\r\n\t/* n\u306Fsqrt(max(x))\u3042\u308C\u3070\u5341\u5206\u306A\u306E\
    \u3067\u6C17\u3092\u4ED8\u3051\u308B */\r\n\tauto factorization(int x) const {\r\
    \n\t\tstd::unordered_map<int, int> table;\r\n\t\tfor (const auto& p : p_list)\
    \ {\r\n\t\t\twhile (x % p == 0) {\r\n\t\t\t\ttable[p]++;\r\n\t\t\t\tx /= p;\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\tif (x > 1) { table[x]++; }\r\n\t\treturn table;\r\n\t\
    }\r\n\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Prime.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Utility/Prime.hpp
layout: document
redirect_from:
- /library/Library/Utility/Prime.hpp
- /library/Library/Utility/Prime.hpp.html
title: Library/Utility/Prime.hpp
---
