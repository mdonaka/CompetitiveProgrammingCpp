---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/convolution_and.test.cpp
    title: Test/Math/convolution_and.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/Modint.hpp\"\n\n#include <iostream>\n#include\
    \ <iterator>\n\nnamespace mtd {\n\n  template <int MOD, class T = long long>\n\
    \  class ModInt {\n    T x;\n\n  public:\n    constexpr ModInt(T x) : x(x % MOD)\
    \ {}\n    constexpr ModInt() : ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\
    \n    constexpr auto& operator+=(const ModInt<MOD, T>& m) {\n      x += m.x;\n\
    \      if (x >= MOD) { x -= MOD; }\n      return *this;\n    }\n    constexpr\
    \ auto& operator-=(const ModInt<MOD, T>& m) {\n      x -= m.x;\n      if (x <\
    \ 0) { x += MOD; }\n      return *this;\n    }\n    constexpr auto& operator*=(const\
    \ ModInt<MOD, T>& m) {\n      x *= m.x;\n      if (x >= MOD) { x %= MOD; }\n \
    \     return *this;\n    }\n\n    constexpr auto operator+(const ModInt<MOD, T>&\
    \ m) const {\n      auto t = *this;\n      t += m;\n      return t;\n    }\n \
    \   constexpr auto operator-(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t -= m;\n      return t;\n    }\n    constexpr auto operator*(const\
    \ ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t *= m;\n      return\
    \ t;\n    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const ModInt<MOD, T>& m)\
    \ {\n      return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n  };\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <iterator>\n\nnamespace mtd\
    \ {\n\n  template <int MOD, class T = long long>\n  class ModInt {\n    T x;\n\
    \n  public:\n    constexpr ModInt(T x) : x(x % MOD) {}\n    constexpr ModInt()\
    \ : ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\n    constexpr auto& operator+=(const\
    \ ModInt<MOD, T>& m) {\n      x += m.x;\n      if (x >= MOD) { x -= MOD; }\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const ModInt<MOD, T>&\
    \ m) {\n      x -= m.x;\n      if (x < 0) { x += MOD; }\n      return *this;\n\
    \    }\n    constexpr auto& operator*=(const ModInt<MOD, T>& m) {\n      x *=\
    \ m.x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n\n    constexpr\
    \ auto operator+(const ModInt<MOD, T>& m) const {\n      auto t = *this;\n   \
    \   t += m;\n      return t;\n    }\n    constexpr auto operator-(const ModInt<MOD,\
    \ T>& m) const {\n      auto t = *this;\n      t -= m;\n      return t;\n    }\n\
    \    constexpr auto operator*(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t *= m;\n      return t;\n    }\n\n    // \u5165\u51FA\u529B\n\
    \    constexpr friend std::ostream& operator<<(std::ostream& os,\n           \
    \                                   const ModInt<MOD, T>& m) {\n      return os\
    \ << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n  };\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/Modint.hpp
  requiredBy: []
  timestamp: '2024-11-06 16:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/convolution_and.test.cpp
documentation_of: Library/Math/Modint.hpp
layout: document
redirect_from:
- /library/Library/Math/Modint.hpp
- /library/Library/Math/Modint.hpp.html
title: Library/Math/Modint.hpp
---
