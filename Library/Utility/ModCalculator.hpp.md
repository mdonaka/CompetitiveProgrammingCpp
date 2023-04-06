---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Utility/Combination.hpp
    title: Library/Utility/Combination.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Utility/ModCalculator.test.cpp
    title: Test/Utility/ModCalculator.test.cpp
  - icon: ':x:'
    path: Test/Utility/ModCalculator_inv.test.cpp
    title: Test/Utility/ModCalculator_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Utility/ModCalculator_pow.test.cpp
    title: Test/Utility/ModCalculator_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/ModCalculator.hpp\"\n#include <vector>\r\
    \n\r\nclass ModCalculator {\r\n    const long long m_mod;\r\n    const std::vector<long\
    \ long> m_fac;\r\n    const std::vector<long long> m_finv;\r\n\r\n    auto constructFac(long\
    \ long s) {\r\n        std::vector<long long> fac(s);\r\n        fac[0] = fac[1]\
    \ = 1;\r\n        for(long long i = 2; i < s; ++i) {\r\n            fac[i] = fac[i\
    \ - 1] * i;\r\n            if(fac[i] > m_mod) { fac[i] %= m_mod; }\r\n       \
    \ }\r\n        return fac;\r\n    }\r\n    auto constructInv(long long s) {\r\n\
    \        std::vector<long long> finv(s);\r\n        finv[s - 1] = this->pow(m_fac[s\
    \ - 1], m_mod - 2);\r\n        for(long long i = s - 2; i >= 0; --i) {\r\n   \
    \         finv[i] = finv[i + 1] * (i + 1);\r\n            if(finv[i] > m_mod)\
    \ { finv[i] %= m_mod; }\r\n        }\r\n        return finv;\r\n    }\r\npublic:\r\
    \n    ModCalculator(long long mod, long long size = 3 * 1e6) :\r\n        m_mod(mod),\
    \ m_fac(constructFac(size)), m_finv(constructInv(size)) {\r\n    }\r\n\r\n   \
    \ static long long pow(long long a, long long b, long long mod) {\r\n        a\
    \ %= mod;\r\n        long long ans = 1;\r\n        while(b > 0) {\r\n        \
    \    if(b & 1) { ans *= a; if(ans >= mod) { ans %= mod; } }\r\n            b >>=\
    \ 1; a *= a; if(a >= mod) { a %= mod; }\r\n        }\r\n        return ans;\r\n\
    \    }\r\n    long long pow(long long a, long long b) const { return pow(a, b,\
    \ m_mod); }\r\n\r\n    auto fact(int n) const {\r\n        if(n < 0) { return\
    \ 0LL; }\r\n        return m_fac[n];\r\n    }\r\n\r\n    auto factInv(int n) const\
    \ {\r\n        if(n < 0) { return 0LL; }\r\n        return m_finv[n];\r\n    }\r\
    \n\r\n    auto comb(int n, int r) const {\r\n        auto val = fact(n) * factInv(r);\r\
    \n        if(val >= m_mod) { val %= m_mod; }\r\n        val *= factInv(n - r);\r\
    \n        if(val >= m_mod) { val %= m_mod; }\r\n        return val;\r\n    }\r\
    \n\r\n    auto perm(int n, int r) const {\r\n        auto val = fact(n) * factInv(n\
    \ - r);\r\n        if(val >= m_mod) { val %= m_mod; }\r\n        return val;\r\
    \n    }\r\n\r\n    auto inv(int n) const {\r\n        return pow(n, m_mod - 2);\r\
    \n    }\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\nclass ModCalculator {\r\n    const\
    \ long long m_mod;\r\n    const std::vector<long long> m_fac;\r\n    const std::vector<long\
    \ long> m_finv;\r\n\r\n    auto constructFac(long long s) {\r\n        std::vector<long\
    \ long> fac(s);\r\n        fac[0] = fac[1] = 1;\r\n        for(long long i = 2;\
    \ i < s; ++i) {\r\n            fac[i] = fac[i - 1] * i;\r\n            if(fac[i]\
    \ > m_mod) { fac[i] %= m_mod; }\r\n        }\r\n        return fac;\r\n    }\r\
    \n    auto constructInv(long long s) {\r\n        std::vector<long long> finv(s);\r\
    \n        finv[s - 1] = this->pow(m_fac[s - 1], m_mod - 2);\r\n        for(long\
    \ long i = s - 2; i >= 0; --i) {\r\n            finv[i] = finv[i + 1] * (i + 1);\r\
    \n            if(finv[i] > m_mod) { finv[i] %= m_mod; }\r\n        }\r\n     \
    \   return finv;\r\n    }\r\npublic:\r\n    ModCalculator(long long mod, long\
    \ long size = 3 * 1e6) :\r\n        m_mod(mod), m_fac(constructFac(size)), m_finv(constructInv(size))\
    \ {\r\n    }\r\n\r\n    static long long pow(long long a, long long b, long long\
    \ mod) {\r\n        a %= mod;\r\n        long long ans = 1;\r\n        while(b\
    \ > 0) {\r\n            if(b & 1) { ans *= a; if(ans >= mod) { ans %= mod; } }\r\
    \n            b >>= 1; a *= a; if(a >= mod) { a %= mod; }\r\n        }\r\n   \
    \     return ans;\r\n    }\r\n    long long pow(long long a, long long b) const\
    \ { return pow(a, b, m_mod); }\r\n\r\n    auto fact(int n) const {\r\n       \
    \ if(n < 0) { return 0LL; }\r\n        return m_fac[n];\r\n    }\r\n\r\n    auto\
    \ factInv(int n) const {\r\n        if(n < 0) { return 0LL; }\r\n        return\
    \ m_finv[n];\r\n    }\r\n\r\n    auto comb(int n, int r) const {\r\n        auto\
    \ val = fact(n) * factInv(r);\r\n        if(val >= m_mod) { val %= m_mod; }\r\n\
    \        val *= factInv(n - r);\r\n        if(val >= m_mod) { val %= m_mod; }\r\
    \n        return val;\r\n    }\r\n\r\n    auto perm(int n, int r) const {\r\n\
    \        auto val = fact(n) * factInv(n - r);\r\n        if(val >= m_mod) { val\
    \ %= m_mod; }\r\n        return val;\r\n    }\r\n\r\n    auto inv(int n) const\
    \ {\r\n        return pow(n, m_mod - 2);\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/ModCalculator.hpp
  requiredBy:
  - Library/Utility/Combination.hpp
  timestamp: '2023-04-07 03:18:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Utility/ModCalculator.test.cpp
  - Test/Utility/ModCalculator_pow.test.cpp
  - Test/Utility/ModCalculator_inv.test.cpp
documentation_of: Library/Utility/ModCalculator.hpp
layout: document
redirect_from:
- /library/Library/Utility/ModCalculator.hpp
- /library/Library/Utility/ModCalculator.hpp.html
title: Library/Utility/ModCalculator.hpp
---
