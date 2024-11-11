---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/Utility/Prime.hpp
    title: Library/Utility/Prime.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"Test/Utility/Prime.test.cpp\"\n#define PROBLEM \\\r\n  \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\r\n\r\n#line\
    \ 2 \"Library/Utility/Prime.hpp\"\n\r\n#include <deque>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nnamespace mtd {\r\n  class Prime {\r\n    const long\
    \ long n;\r\n    const std::deque<long long> p_list;\r\n\r\n    static inline\
    \ auto linearSieve(long long n) {\r\n      std::deque<long long> p_list;\r\n \
    \     std::vector<long long> lpf(n + 1);\r\n      for (int d = 2; d < n + 1; ++d)\
    \ {\r\n        if (!lpf[d]) {\r\n          lpf[d] = d;\r\n          p_list.emplace_back(d);\r\
    \n        }\r\n        for (const auto& p : p_list) {\r\n          if (p * d >\
    \ n || p > lpf[d]) { break; }\r\n          lpf[p * d] = p;\r\n        }\r\n  \
    \    }\r\n      return std::tuple{p_list, lpf};\r\n    }\r\n\r\n  public:\r\n\
    \    Prime(long long n) : n(n), p_list(std::get<0>(linearSieve(n))) {}\r\n\r\n\
    \    /* n\u306Fsqrt(max(x))\u3042\u308C\u3070\u5341\u5206\u306A\u306E\u3067\u6C17\
    \u3092\u4ED8\u3051\u308B */\r\n    auto factorization(long long x) const {\r\n\
    \      std::unordered_map<long long, long long> table;\r\n      for (const auto&\
    \ p : p_list) {\r\n        while (x % p == 0) {\r\n          table[p]++;\r\n \
    \         x /= p;\r\n        }\r\n      }\r\n      if (x > 1) { table[x]++; }\r\
    \n      return table;\r\n    }\r\n    auto getPList() const { return p_list; }\r\
    \n  };\r\n}  // namespace mtd\r\n#line 5 \"Test/Utility/Prime.test.cpp\"\n\r\n\
    #include <algorithm>\r\n#include <iostream>\r\n\r\nusing ll = long long;\r\nusing\
    \ std::cin;\r\nusing std::cout;\r\nconstexpr char endl = '\\n';\r\n\r\nsigned\
    \ main() {\r\n  ll n;\r\n  cin >> n;\r\n\r\n  auto prime = mtd::Prime(1e5);\r\n\
    \  auto fc = prime.factorization(n);\r\n\r\n  std::vector<ll> ans;\r\n  for (const\
    \ auto& [x, c] : fc)\r\n    for (int i = 0; i < c; ++i) { ans.emplace_back(x);\
    \ }\r\n  std::sort(ans.begin(), ans.end());\r\n\r\n  cout << n << \": \";\r\n\
    \  for (unsigned int i = 0; i < ans.size(); ++i) {\r\n    cout << ans[i] << (i\
    \ + 1 < ans.size() ? \" \" : \"\\n\");\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \r\n\r\n#include \"./../../Library/Utility/Prime.hpp\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing\
    \ std::cout;\r\nconstexpr char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n;\r\
    \n  cin >> n;\r\n\r\n  auto prime = mtd::Prime(1e5);\r\n  auto fc = prime.factorization(n);\r\
    \n\r\n  std::vector<ll> ans;\r\n  for (const auto& [x, c] : fc)\r\n    for (int\
    \ i = 0; i < c; ++i) { ans.emplace_back(x); }\r\n  std::sort(ans.begin(), ans.end());\r\
    \n\r\n  cout << n << \": \";\r\n  for (unsigned int i = 0; i < ans.size(); ++i)\
    \ {\r\n    cout << ans[i] << (i + 1 < ans.size() ? \" \" : \"\\n\");\r\n  }\r\n\
    }\r\n"
  dependsOn:
  - Library/Utility/Prime.hpp
  isVerificationFile: true
  path: Test/Utility/Prime.test.cpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Utility/Prime.test.cpp
layout: document
redirect_from:
- /verify/Test/Utility/Prime.test.cpp
- /verify/Test/Utility/Prime.test.cpp.html
title: Test/Utility/Prime.test.cpp
---
