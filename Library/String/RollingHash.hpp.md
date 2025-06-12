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
  bundledCode: "#line 2 \"Library/String/RollingHash.hpp\"\n\n#include <array>\n#include\
    \ <ranges>\n#include <string>\n#include <vector>\n\nnamespace mtd {\n\n  template\
    \ <class T = long long,\n            long long BASE = static_cast<long long>(1LL\
    \ << 30),\n            int HASH_USE = 5>\n  class RollingHash {\n    constexpr\
    \ static int SIZE = 5;\n    constexpr static std::array<T, SIZE> MOD_V = {\n \
    \       998244353, 1000000007, 1000000009, 1000000021, 1000000033};\n\n    std::vector<std::vector<T>>\
    \ hash, power, inv;\n\n    constexpr static auto pow = [](T a, T b, T mod) {\n\
    \      T res = 1;\n      while (b) {\n        if (b & 1) { res = res * a % mod;\
    \ }\n        a = a * a % mod;\n        b >>= 1;\n      }\n      return res;\n\
    \    };\n\n  public:\n    constexpr RollingHash(const std::vector<T>& v)\n   \
    \     : hash(HASH_USE, v),\n          power(HASH_USE, std::vector<T>(v.size(),\
    \ 1)),\n          inv(HASH_USE, std::vector<T>(v.size(), 1)) {\n      for (auto\
    \ mi : std::views::iota(0, HASH_USE)) {\n        T inv_base = pow(BASE, MOD_V[mi]\
    \ - 2, MOD_V[mi]);\n        for (auto i : std::views::iota(1, static_cast<int>(v.size())))\
    \ {\n          power[mi][i] = power[mi][i - 1] * BASE;\n          power[mi][i]\
    \ %= MOD_V[mi];\n          hash[mi][i] += hash[mi][i - 1] * BASE;\n          hash[mi][i]\
    \ %= MOD_V[mi];\n          inv[mi][i] = inv[mi][i - 1] * inv_base;\n         \
    \ inv[mi][i] %= MOD_V[mi];\n        }\n      }\n    }\n\n    constexpr auto calc_hash(int\
    \ l, int r) const {\n      std::vector<T> res;\n      for (auto mi : std::views::iota(0,\
    \ HASH_USE)) {\n        auto val = hash[mi][r] - (l == 0 ? 0 : hash[mi][l - 1])\
    \ *\n                                     power[mi][r - l + 1] % MOD_V[mi];\n\
    \        if (val < 0) { val += MOD_V[mi]; }\n        res.emplace_back(val);\n\
    \      }\n      return res;\n    }\n  };\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <array>\n#include <ranges>\n#include <string>\n\
    #include <vector>\n\nnamespace mtd {\n\n  template <class T = long long,\n   \
    \         long long BASE = static_cast<long long>(1LL << 30),\n            int\
    \ HASH_USE = 5>\n  class RollingHash {\n    constexpr static int SIZE = 5;\n \
    \   constexpr static std::array<T, SIZE> MOD_V = {\n        998244353, 1000000007,\
    \ 1000000009, 1000000021, 1000000033};\n\n    std::vector<std::vector<T>> hash,\
    \ power, inv;\n\n    constexpr static auto pow = [](T a, T b, T mod) {\n     \
    \ T res = 1;\n      while (b) {\n        if (b & 1) { res = res * a % mod; }\n\
    \        a = a * a % mod;\n        b >>= 1;\n      }\n      return res;\n    };\n\
    \n  public:\n    constexpr RollingHash(const std::vector<T>& v)\n        : hash(HASH_USE,\
    \ v),\n          power(HASH_USE, std::vector<T>(v.size(), 1)),\n          inv(HASH_USE,\
    \ std::vector<T>(v.size(), 1)) {\n      for (auto mi : std::views::iota(0, HASH_USE))\
    \ {\n        T inv_base = pow(BASE, MOD_V[mi] - 2, MOD_V[mi]);\n        for (auto\
    \ i : std::views::iota(1, static_cast<int>(v.size()))) {\n          power[mi][i]\
    \ = power[mi][i - 1] * BASE;\n          power[mi][i] %= MOD_V[mi];\n         \
    \ hash[mi][i] += hash[mi][i - 1] * BASE;\n          hash[mi][i] %= MOD_V[mi];\n\
    \          inv[mi][i] = inv[mi][i - 1] * inv_base;\n          inv[mi][i] %= MOD_V[mi];\n\
    \        }\n      }\n    }\n\n    constexpr auto calc_hash(int l, int r) const\
    \ {\n      std::vector<T> res;\n      for (auto mi : std::views::iota(0, HASH_USE))\
    \ {\n        auto val = hash[mi][r] - (l == 0 ? 0 : hash[mi][l - 1]) *\n     \
    \                                power[mi][r - l + 1] % MOD_V[mi];\n        if\
    \ (val < 0) { val += MOD_V[mi]; }\n        res.emplace_back(val);\n      }\n \
    \     return res;\n    }\n  };\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/String/RollingHash.hpp
  requiredBy: []
  timestamp: '2025-06-13 03:39:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/String/RollingHash.hpp
layout: document
redirect_from:
- /library/Library/String/RollingHash.hpp
- /library/Library/String/RollingHash.hpp.html
title: Library/String/RollingHash.hpp
---
