---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Math/Convolution_and.test.cpp
    title: Test/Math/Convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math.test.cpp
    title: Test/Math/Math.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_pow.test.cpp
    title: Test/Math/Math_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/ModInt.hpp\"\n\n#include <iostream>\n#include\
    \ <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\n\r\n#include <vector>\r\n\r\
    \nnamespace mtd {\r\n  template <class T>\r\n  class Math {\r\n    const std::vector<T>\
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
    \ - r); }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Math/ModInt.hpp\"\
    \n\nnamespace mtd {\n\n  template <int MOD, class T = long long>\n  class ModInt\
    \ {\n    T x;\n\n  public:\n    constexpr ModInt(T x) : x(x % MOD) {}\n    constexpr\
    \ ModInt() : ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\n    constexpr auto&\
    \ operator+=(const ModInt<MOD, T>& m) {\n      x += m.x;\n      if (x >= MOD)\
    \ { x -= MOD; }\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ ModInt<MOD, T>& m) {\n      x -= m.x;\n      if (x < 0) { x += MOD; }\n    \
    \  return *this;\n    }\n    constexpr auto& operator*=(const ModInt<MOD, T>&\
    \ m) {\n      x *= m.x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n\
    \    }\n    constexpr auto& operator/=(const ModInt<MOD, T>& m) {\n      x *=\
    \ mtd::Math<ModInt<MOD, T>>::pow(m.x, MOD - 2).x;\n      if (x >= MOD) { x %=\
    \ MOD; }\n      return *this;\n    }\n\n    constexpr auto operator+(const ModInt<MOD,\
    \ T>& m) const {\n      auto t = *this;\n      t += m;\n      return t;\n    }\n\
    \    constexpr auto operator-(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t -= m;\n      return t;\n    }\n    constexpr auto operator*(const\
    \ ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t *= m;\n      return\
    \ t;\n    }\n    constexpr auto operator/(const ModInt<MOD, T>& m) const {\n \
    \     auto t = *this;\n      t /= m;\n      return t;\n    }\n\n    constexpr\
    \ auto& operator+=(const T& t) {\n      return *this += ModInt<MOD, T>(t);\n \
    \   }\n    constexpr auto& operator-=(const T& t) {\n      return *this -= ModInt<MOD,\
    \ T>(t);\n    }\n    constexpr auto& operator*=(const T& n) {\n      return *this\
    \ *= ModInt<MOD, T>(n);\n    }\n    constexpr auto& operator/=(const T& n) {\n\
    \      return *this /= ModInt<MOD, T>(n);\n    }\n    constexpr auto operator+(const\
    \ T& t) const {\n      return *this + ModInt<MOD, T>(t);\n    }\n    constexpr\
    \ auto operator-(const T& t) const {\n      return *this - ModInt<MOD, T>(t);\n\
    \    }\n    constexpr auto operator*(const T& t) const {\n      return *this *\
    \ ModInt<MOD, T>(t);\n    }\n    constexpr auto operator/(const T& t) const {\n\
    \      return *this / ModInt<MOD, T>(t);\n    }\n    constexpr friend auto operator+(const\
    \ T& t, const ModInt<MOD, T>& m) {\n      return m + t;\n    }\n    constexpr\
    \ friend auto operator-(const T& t, const ModInt<MOD, T>& m) {\n      return -m\
    \ + t;\n    }\n    constexpr friend auto operator*(const T& t, const ModInt<MOD,\
    \ T>& m) {\n      return m * t;\n    }\n    constexpr friend auto operator/(const\
    \ T& t, const ModInt<MOD, T>& m) {\n      return ModInt<MOD, T>(1) / m * t;\n\
    \    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const ModInt<MOD, T>& m)\
    \ {\n      return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n\n    constexpr auto val() const { return x; }\n\
    \  };\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <iterator>\n\n#include \"./Math.hpp\"\
    \n\nnamespace mtd {\n\n  template <int MOD, class T = long long>\n  class ModInt\
    \ {\n    T x;\n\n  public:\n    constexpr ModInt(T x) : x(x % MOD) {}\n    constexpr\
    \ ModInt() : ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\n    constexpr auto&\
    \ operator+=(const ModInt<MOD, T>& m) {\n      x += m.x;\n      if (x >= MOD)\
    \ { x -= MOD; }\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ ModInt<MOD, T>& m) {\n      x -= m.x;\n      if (x < 0) { x += MOD; }\n    \
    \  return *this;\n    }\n    constexpr auto& operator*=(const ModInt<MOD, T>&\
    \ m) {\n      x *= m.x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n\
    \    }\n    constexpr auto& operator/=(const ModInt<MOD, T>& m) {\n      x *=\
    \ mtd::Math<ModInt<MOD, T>>::pow(m.x, MOD - 2).x;\n      if (x >= MOD) { x %=\
    \ MOD; }\n      return *this;\n    }\n\n    constexpr auto operator+(const ModInt<MOD,\
    \ T>& m) const {\n      auto t = *this;\n      t += m;\n      return t;\n    }\n\
    \    constexpr auto operator-(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t -= m;\n      return t;\n    }\n    constexpr auto operator*(const\
    \ ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t *= m;\n      return\
    \ t;\n    }\n    constexpr auto operator/(const ModInt<MOD, T>& m) const {\n \
    \     auto t = *this;\n      t /= m;\n      return t;\n    }\n\n    constexpr\
    \ auto& operator+=(const T& t) {\n      return *this += ModInt<MOD, T>(t);\n \
    \   }\n    constexpr auto& operator-=(const T& t) {\n      return *this -= ModInt<MOD,\
    \ T>(t);\n    }\n    constexpr auto& operator*=(const T& n) {\n      return *this\
    \ *= ModInt<MOD, T>(n);\n    }\n    constexpr auto& operator/=(const T& n) {\n\
    \      return *this /= ModInt<MOD, T>(n);\n    }\n    constexpr auto operator+(const\
    \ T& t) const {\n      return *this + ModInt<MOD, T>(t);\n    }\n    constexpr\
    \ auto operator-(const T& t) const {\n      return *this - ModInt<MOD, T>(t);\n\
    \    }\n    constexpr auto operator*(const T& t) const {\n      return *this *\
    \ ModInt<MOD, T>(t);\n    }\n    constexpr auto operator/(const T& t) const {\n\
    \      return *this / ModInt<MOD, T>(t);\n    }\n    constexpr friend auto operator+(const\
    \ T& t, const ModInt<MOD, T>& m) {\n      return m + t;\n    }\n    constexpr\
    \ friend auto operator-(const T& t, const ModInt<MOD, T>& m) {\n      return -m\
    \ + t;\n    }\n    constexpr friend auto operator*(const T& t, const ModInt<MOD,\
    \ T>& m) {\n      return m * t;\n    }\n    constexpr friend auto operator/(const\
    \ T& t, const ModInt<MOD, T>& m) {\n      return ModInt<MOD, T>(1) / m * t;\n\
    \    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const ModInt<MOD, T>& m)\
    \ {\n      return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n\n    constexpr auto val() const { return x; }\n\
    \  };\n\n}  // namespace mtd\n"
  dependsOn:
  - Library/Math/Math.hpp
  isVerificationFile: false
  path: Library/Math/ModInt.hpp
  requiredBy: []
  timestamp: '2024-11-11 23:25:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Math/Convolution_and.test.cpp
  - Test/Math/Math.test.cpp
  - Test/Math/Math_pow.test.cpp
documentation_of: Library/Math/ModInt.hpp
layout: document
redirect_from:
- /library/Library/Math/ModInt.hpp
- /library/Library/Math/ModInt.hpp.html
title: Library/Math/ModInt.hpp
---
