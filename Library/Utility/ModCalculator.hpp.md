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
    \n    ModCalculator(long long mod = MOD, long long size = 3 * 1e6) :\r\n     \
    \   m_mod(mod), m_fac(constructFac(size)), m_finv(constructInv(size)) {\r\n  \
    \  }\r\n\r\n    long long pow(long long a, long long b) const {\r\n        a %=\
    \ m_mod;\r\n        long long ans = 1;\r\n        while(b > 0) {\r\n         \
    \   if(b & 1) { ans *= a; if(ans >= m_mod) { ans %= m_mod; } }\r\n           \
    \ b >>= 1; a *= a; if(a >= m_mod) { a %= m_mod; }\r\n        }\r\n        return\
    \ ans;\r\n    }\r\n\r\n    auto comb(int n, int r) const {\r\n        long long\
    \ val = m_fac[n] * m_finv[r];\r\n        if(val > m_mod) { val %= m_mod; }\r\n\
    \        val *= m_finv[n - r];;\r\n        if(val > m_mod) { val %= m_mod; }\r\
    \n        return val;\r\n    }\r\n\r\n    auto fact(int n) const {\r\n       \
    \ return m_fac[n];\r\n    }\r\n\r\n    auto factRev(int n) const {\r\n       \
    \ return m_finv[n];\r\n    }\r\n\r\n}calc;\r\n\r\n/**\r\n*\tMOD\u306A\u3057combination\r\
    \n*\tn< 51, r<51\r\n*/\r\nlong long combFast(long long a, long long b) {\r\n \
    \   ++a;\r\n    static long long now = 1;\r\n    static std::vector<std::vector<long\
    \ long>> pascalComb(1);\r\n    pascalComb.reserve(51);\r\n    if(a < now) {\r\n\
    \        return pascalComb[a][b];\r\n    }\r\n    for(; now < a + 1; ++now) {\r\
    \n        std::vector<long long> v(now);\r\n        v[0] = v[now - 1] = 1;\r\n\
    \        for(long long j = 1; j < now - 1; ++j) {\r\n            v[j] = pascalComb[now\
    \ - 1][j - 1] + pascalComb[now - 1][j];\r\n        }\r\n        pascalComb.emplace_back(v);\r\
    \n    }\r\n    return pascalComb[a][b];\r\n}\r\n\r\n/**\r\n*\t\u30B7\u30F3\u30D7\
    \u30EBcombination\r\n*\tO(r)\r\n*/\r\nlong long combSimple(long long a, long long\
    \ b) {\r\n    if(b > a - b) { return combSimple(a, a - b); }\r\n    long long\
    \ ans = 1;\r\n    for(long long i = 0; i < b; ++i) {\r\n        ans *= a - i;\r\
    \n        ans %= MOD;\r\n    }\r\n    long long t = 1;\r\n    for(long long i\
    \ = 1; i < b + 1; ++i) {\r\n        t *= i;\r\n        t %= MOD;\r\n    }\r\n\
    \    ans *= calc.pow(t, MOD - 2);\r\n    ans %= MOD;\r\n    return ans;\r\n}\n"
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
    \   return finv;\r\n    }\r\npublic:\r\n    ModCalculator(long long mod = MOD,\
    \ long long size = 3 * 1e6) :\r\n        m_mod(mod), m_fac(constructFac(size)),\
    \ m_finv(constructInv(size)) {\r\n    }\r\n\r\n    long long pow(long long a,\
    \ long long b) const {\r\n        a %= m_mod;\r\n        long long ans = 1;\r\n\
    \        while(b > 0) {\r\n            if(b & 1) { ans *= a; if(ans >= m_mod)\
    \ { ans %= m_mod; } }\r\n            b >>= 1; a *= a; if(a >= m_mod) { a %= m_mod;\
    \ }\r\n        }\r\n        return ans;\r\n    }\r\n\r\n    auto comb(int n, int\
    \ r) const {\r\n        long long val = m_fac[n] * m_finv[r];\r\n        if(val\
    \ > m_mod) { val %= m_mod; }\r\n        val *= m_finv[n - r];;\r\n        if(val\
    \ > m_mod) { val %= m_mod; }\r\n        return val;\r\n    }\r\n\r\n    auto fact(int\
    \ n) const {\r\n        return m_fac[n];\r\n    }\r\n\r\n    auto factRev(int\
    \ n) const {\r\n        return m_finv[n];\r\n    }\r\n\r\n}calc;\r\n\r\n/**\r\n\
    *\tMOD\u306A\u3057combination\r\n*\tn< 51, r<51\r\n*/\r\nlong long combFast(long\
    \ long a, long long b) {\r\n    ++a;\r\n    static long long now = 1;\r\n    static\
    \ std::vector<std::vector<long long>> pascalComb(1);\r\n    pascalComb.reserve(51);\r\
    \n    if(a < now) {\r\n        return pascalComb[a][b];\r\n    }\r\n    for(;\
    \ now < a + 1; ++now) {\r\n        std::vector<long long> v(now);\r\n        v[0]\
    \ = v[now - 1] = 1;\r\n        for(long long j = 1; j < now - 1; ++j) {\r\n  \
    \          v[j] = pascalComb[now - 1][j - 1] + pascalComb[now - 1][j];\r\n   \
    \     }\r\n        pascalComb.emplace_back(v);\r\n    }\r\n    return pascalComb[a][b];\r\
    \n}\r\n\r\n/**\r\n*\t\u30B7\u30F3\u30D7\u30EBcombination\r\n*\tO(r)\r\n*/\r\n\
    long long combSimple(long long a, long long b) {\r\n    if(b > a - b) { return\
    \ combSimple(a, a - b); }\r\n    long long ans = 1;\r\n    for(long long i = 0;\
    \ i < b; ++i) {\r\n        ans *= a - i;\r\n        ans %= MOD;\r\n    }\r\n \
    \   long long t = 1;\r\n    for(long long i = 1; i < b + 1; ++i) {\r\n       \
    \ t *= i;\r\n        t %= MOD;\r\n    }\r\n    ans *= calc.pow(t, MOD - 2);\r\n\
    \    ans %= MOD;\r\n    return ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/ModCalculator.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Utility/ModCalculator.hpp
layout: document
redirect_from:
- /library/Library/Utility/ModCalculator.hpp
- /library/Library/Utility/ModCalculator.hpp.html
title: Library/Utility/ModCalculator.hpp
---
