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
  bundledCode: "#line 2 \"Library/Math/ModInt.hpp\"\n\n#include <iostream>\n#include\
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
    \ t;\n    }\n\n    constexpr auto& operator+=(const T& t) {\n      return *this\
    \ += ModInt<MOD, T>(t);\n    }\n    constexpr auto& operator-=(const T& t) {\n\
    \      return *this -= ModInt<MOD, T>(t);\n    }\n    constexpr auto& operator*=(const\
    \ T& n) {\n      return *this *= ModInt<MOD, T>(n);\n    }\n    constexpr auto\
    \ operator+(const T& t) const {\n      return *this + ModInt<MOD, T>(t);\n   \
    \ }\n    constexpr auto operator-(const T& t) const {\n      return *this - ModInt<MOD,\
    \ T>(t);\n    }\n    constexpr auto operator*(const T& t) const {\n      return\
    \ *this * ModInt<MOD, T>(t);\n    }\n    constexpr friend auto operator+(const\
    \ T& t, const ModInt<MOD, T>& m) {\n      return m + t;\n    }\n    constexpr\
    \ friend auto operator-(const T& t, const ModInt<MOD, T>& m) {\n      return m\
    \ - t;\n    }\n    constexpr friend auto operator*(const T& t, const ModInt<MOD,\
    \ T>& m) {\n      return m * t;\n    }\n\n    // \u5165\u51FA\u529B\n    constexpr\
    \ friend std::ostream& operator<<(std::ostream& os,\n                        \
    \                      const ModInt<MOD, T>& m) {\n      return os << m.x;\n \
    \   }\n    constexpr friend std::istream& operator>>(std::istream& is,\n     \
    \                                         ModInt<MOD, T>& m) {\n      return is\
    \ >> m.x;\n    }\n\n    constexpr auto val() const { return x; }\n  };\n\n}  //\
    \ namespace mtd\n"
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
    \ *this;\n      t *= m;\n      return t;\n    }\n\n    constexpr auto& operator+=(const\
    \ T& t) {\n      return *this += ModInt<MOD, T>(t);\n    }\n    constexpr auto&\
    \ operator-=(const T& t) {\n      return *this -= ModInt<MOD, T>(t);\n    }\n\
    \    constexpr auto& operator*=(const T& n) {\n      return *this *= ModInt<MOD,\
    \ T>(n);\n    }\n    constexpr auto operator+(const T& t) const {\n      return\
    \ *this + ModInt<MOD, T>(t);\n    }\n    constexpr auto operator-(const T& t)\
    \ const {\n      return *this - ModInt<MOD, T>(t);\n    }\n    constexpr auto\
    \ operator*(const T& t) const {\n      return *this * ModInt<MOD, T>(t);\n   \
    \ }\n    constexpr friend auto operator+(const T& t, const ModInt<MOD, T>& m)\
    \ {\n      return m + t;\n    }\n    constexpr friend auto operator-(const T&\
    \ t, const ModInt<MOD, T>& m) {\n      return m - t;\n    }\n    constexpr friend\
    \ auto operator*(const T& t, const ModInt<MOD, T>& m) {\n      return m * t;\n\
    \    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const ModInt<MOD, T>& m)\
    \ {\n      return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n\n    constexpr auto val() const { return x; }\n\
    \  };\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/ModInt.hpp
  requiredBy: []
  timestamp: '2024-11-09 15:39:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Math/ModInt.hpp
layout: document
redirect_from:
- /library/Library/Math/ModInt.hpp
- /library/Library/Math/ModInt.hpp.html
title: Library/Math/ModInt.hpp
---
