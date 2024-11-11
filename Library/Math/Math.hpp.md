---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math.test.cpp
    title: Test/Math/Math.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_pow.test.cpp
    title: Test/Math/Math_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/Math.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ mtd {\r\n  template <class T>\r\n  class Math {\r\n    const std::vector<T>\
    \ m_fac;\r\n    const std::vector<T> m_finv;\r\n\r\n    auto constructFac(int\
    \ s) {\r\n      std::vector<T> fac(s);\r\n      fac[0] = fac[1] = 1;\r\n     \
    \ for (long long i = 2; i < s; ++i) { fac[i] = fac[i - 1] * i; }\r\n      return\
    \ fac;\r\n    }\r\n    auto constructInv(int s) {\r\n      std::vector<T> finv(s);\r\
    \n      finv[s - 1] = 1 / m_fac[s - 1];\r\n      for (long long i = s - 2; i >=\
    \ 0; --i) {\r\n        finv[i] = finv[i + 1] * (i + 1);\r\n      }\r\n      return\
    \ finv;\r\n    }\r\n\r\n  public:\r\n    constexpr Math(long long size = 3 * 1e6)\r\
    \n        : m_fac(constructFac(size)), m_finv(constructInv(size)) {}\r\n\r\n \
    \   static constexpr T pow(T a, long long b) {\r\n      T ans = 1;\r\n      while\
    \ (b > 0) {\r\n        if (b & 1) { ans *= a; }\r\n        b >>= 1;\r\n      \
    \  a *= a;\r\n      }\r\n      return ans;\r\n    }\r\n    constexpr auto fact(int\
    \ n) const { return (n < 0) ? 0 : m_fac[n]; }\r\n    constexpr auto factInv(int\
    \ n) const { return (n < 0 ? 0 : m_finv[n]); }\r\n    constexpr auto comb(int\
    \ n, int r) const {\r\n      return fact(n) * factInv(r) * factInv(n - r);\r\n\
    \    }\r\n    constexpr auto perm(int n, int r) const { return fact(n) * factInv(n\
    \ - r); }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n  template\
    \ <class T>\r\n  class Math {\r\n    const std::vector<T> m_fac;\r\n    const\
    \ std::vector<T> m_finv;\r\n\r\n    auto constructFac(int s) {\r\n      std::vector<T>\
    \ fac(s);\r\n      fac[0] = fac[1] = 1;\r\n      for (long long i = 2; i < s;\
    \ ++i) { fac[i] = fac[i - 1] * i; }\r\n      return fac;\r\n    }\r\n    auto\
    \ constructInv(int s) {\r\n      std::vector<T> finv(s);\r\n      finv[s - 1]\
    \ = 1 / m_fac[s - 1];\r\n      for (long long i = s - 2; i >= 0; --i) {\r\n  \
    \      finv[i] = finv[i + 1] * (i + 1);\r\n      }\r\n      return finv;\r\n \
    \   }\r\n\r\n  public:\r\n    constexpr Math(long long size = 3 * 1e6)\r\n   \
    \     : m_fac(constructFac(size)), m_finv(constructInv(size)) {}\r\n\r\n    static\
    \ constexpr T pow(T a, long long b) {\r\n      T ans = 1;\r\n      while (b >\
    \ 0) {\r\n        if (b & 1) { ans *= a; }\r\n        b >>= 1;\r\n        a *=\
    \ a;\r\n      }\r\n      return ans;\r\n    }\r\n    constexpr auto fact(int n)\
    \ const { return (n < 0) ? 0 : m_fac[n]; }\r\n    constexpr auto factInv(int n)\
    \ const { return (n < 0 ? 0 : m_finv[n]); }\r\n    constexpr auto comb(int n,\
    \ int r) const {\r\n      return fact(n) * factInv(r) * factInv(n - r);\r\n  \
    \  }\r\n    constexpr auto perm(int n, int r) const { return fact(n) * factInv(n\
    \ - r); }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/Math.hpp
  requiredBy:
  - Library/Math/ModInt.hpp
  timestamp: '2024-11-11 23:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/Math.test.cpp
  - Test/Math/Math_pow.test.cpp
documentation_of: Library/Math/Math.hpp
layout: document
redirect_from:
- /library/Library/Math/Math.hpp
- /library/Library/Math/Math.hpp.html
title: Library/Math/Math.hpp
---
