---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Utility/ModCalculator.hpp
    title: Library/Utility/ModCalculator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \n    }\r\n};\r\n#line 3 \"Library/Utility/Combination.hpp\"\n\r\n#line 5 \"Library/Utility/Combination.hpp\"\
    \n\r\n\r\n/**\r\n*\tMOD\u306A\u3057combination\r\n*\tn< 51, r<51\r\n*/\r\nlong\
    \ long combFast(long long a, long long b) {\r\n    ++a;\r\n    static long long\
    \ now = 1;\r\n    static std::vector<std::vector<long long>> pascalComb(1);\r\n\
    \    pascalComb.reserve(51);\r\n    if(a < now) {\r\n        return pascalComb[a][b];\r\
    \n    }\r\n    for(; now < a + 1; ++now) {\r\n        std::vector<long long> v(now);\r\
    \n        v[0] = v[now - 1] = 1;\r\n        for(long long j = 1; j < now - 1;\
    \ ++j) {\r\n            v[j] = pascalComb[now - 1][j - 1] + pascalComb[now - 1][j];\r\
    \n        }\r\n        pascalComb.emplace_back(v);\r\n    }\r\n    return pascalComb[a][b];\r\
    \n}\r\n\r\n/**\r\n*\t\u30B7\u30F3\u30D7\u30EBcombination\r\n*\tO(r)\r\n*/\r\n\
    long long combSimple(long long a, long long b, long long MOD) {\r\n    if(b >\
    \ a - b) { return combSimple(a, a - b, MOD); }\r\n    long long ans = 1;\r\n \
    \   for(long long i = 0; i < b; ++i) {\r\n        ans *= a - i;\r\n        ans\
    \ %= MOD;\r\n    }\r\n    long long t = 1;\r\n    for(long long i = 1; i < b +\
    \ 1; ++i) {\r\n        t *= i;\r\n        t %= MOD;\r\n    }\r\n    ans *= calc.pow(t,\
    \ MOD - 2);\r\n    ans %= MOD;\r\n    return ans;\r\n}\n"
  code: "#pragma once\r\n#include \"./ModCalculator.hpp\"\r\n\r\n#include <vector>\r\
    \n\r\n\r\n/**\r\n*\tMOD\u306A\u3057combination\r\n*\tn< 51, r<51\r\n*/\r\nlong\
    \ long combFast(long long a, long long b) {\r\n    ++a;\r\n    static long long\
    \ now = 1;\r\n    static std::vector<std::vector<long long>> pascalComb(1);\r\n\
    \    pascalComb.reserve(51);\r\n    if(a < now) {\r\n        return pascalComb[a][b];\r\
    \n    }\r\n    for(; now < a + 1; ++now) {\r\n        std::vector<long long> v(now);\r\
    \n        v[0] = v[now - 1] = 1;\r\n        for(long long j = 1; j < now - 1;\
    \ ++j) {\r\n            v[j] = pascalComb[now - 1][j - 1] + pascalComb[now - 1][j];\r\
    \n        }\r\n        pascalComb.emplace_back(v);\r\n    }\r\n    return pascalComb[a][b];\r\
    \n}\r\n\r\n/**\r\n*\t\u30B7\u30F3\u30D7\u30EBcombination\r\n*\tO(r)\r\n*/\r\n\
    long long combSimple(long long a, long long b, long long MOD) {\r\n    if(b >\
    \ a - b) { return combSimple(a, a - b, MOD); }\r\n    long long ans = 1;\r\n \
    \   for(long long i = 0; i < b; ++i) {\r\n        ans *= a - i;\r\n        ans\
    \ %= MOD;\r\n    }\r\n    long long t = 1;\r\n    for(long long i = 1; i < b +\
    \ 1; ++i) {\r\n        t *= i;\r\n        t %= MOD;\r\n    }\r\n    ans *= calc.pow(t,\
    \ MOD - 2);\r\n    ans %= MOD;\r\n    return ans;\r\n}"
  dependsOn:
  - Library/Utility/ModCalculator.hpp
  isVerificationFile: false
  path: Library/Utility/Combination.hpp
  requiredBy: []
  timestamp: '2023-04-07 03:18:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Utility/Combination.hpp
layout: document
redirect_from:
- /library/Library/Utility/Combination.hpp
- /library/Library/Utility/Combination.hpp.html
title: Library/Utility/Combination.hpp
---
