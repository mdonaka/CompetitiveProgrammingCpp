---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Math/EuclideanAlgorithm.hpp
    title: Library/Math/EuclideanAlgorithm.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_dynamic.test.cpp
    title: Test/Math/Math_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_pow_dynamic.test.cpp
    title: Test/Math/Math_pow_dynamic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/DynamicModInt.hpp\"\n\n#include <iostream>\n\
    #include <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\n\r\n#include <cmath>\r\
    \n#include <numeric>\r\n#include <optional>\r\n#include <ranges>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Math/EuclideanAlgorithm.hpp\"\n\r\
    \n#line 5 \"Library/Math/EuclideanAlgorithm.hpp\"\n#include <tuple>\r\n\r\nnamespace\
    \ mtd {\r\n\r\n  class EuclideanAlgorithm {\r\n    using T = long long;\r\n\r\n\
    \    // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u3066\u3057\u307E\u3046\r\n    const static inline T m_mx = 1e9;\r\
    \n\r\n    const T m_a;\r\n    const T m_b;\r\n    const T m_c;\r\n\r\n    T m_gcd;\r\
    \n    T m_x;\r\n    T m_y;\r\n\r\n    auto excludedEuclidAlgorithm(T a, T b) ->\
    \ std::tuple<T, T, T> {\r\n      if (a < 0) {\r\n        auto [g, x, y] = excludedEuclidAlgorithm(-a,\
    \ -b);\r\n        return {g, -x, -y};\r\n      }\r\n      if (b == 0) { return\
    \ {a, 1, 0}; }\r\n      auto [g, y, x] = excludedEuclidAlgorithm(b, a % b);\r\n\
    \      y -= a / b * x;\r\n      return {g, x, y};\r\n    }\r\n\r\n    auto kRange(T\
    \ x, T b, T l) const -> std::pair<T, T> {\r\n      // x + b * k >= l \u3092\u6E80\
    \u305F\u3059 k \u306E\u7BC4\u56F2\u3092\u6C42\u3081\u308B\r\n      T xd = (l -\
    \ x);\r\n      if (b == 0 && x >= l) { return {-m_mx, m_mx}; }\r\n      if (b\
    \ == 0 && x < l) { return {m_mx, -m_mx}; }\r\n      if (b > 0 && xd < 0) { return\
    \ {xd / b, m_mx}; }\r\n      if (b > 0 && xd >= 0) { return {(xd + b - 1) / b,\
    \ m_mx}; }\r\n      if (b < 0 && xd < 0) { return {-m_mx, (-xd) / (-b)}; }\r\n\
    \      if (b < 0 && xd >= 0) { return {-m_mx, -(xd - b - 1) / (-b)}; }\r\n   \
    \   return {m_mx, -m_mx};\r\n    }\r\n\r\n  public:\r\n    auto debug() const\
    \ {\r\n      std::cout << m_a << \" * \" << m_x << \" + \" << m_b << \" * \" <<\
    \ m_y << \" = \"\r\n                << m_c << std::endl;\r\n      std::cout <<\
    \ \"calc: \" << m_a * m_x + m_b * m_y << \" = \" << m_c\r\n                <<\
    \ std::endl;\r\n    }\r\n\r\n    EuclideanAlgorithm(T a, T b, T c) : m_a(a), m_b(b),\
    \ m_c(c) {\r\n      if (a == 0 && b == 0) { throw std::runtime_error(\"\"); }\r\
    \n      auto [g, x, y] = excludedEuclidAlgorithm(a, b);\r\n      if (c % g > 0)\
    \ {\r\n        throw std::runtime_error(\r\n            \"There is no solution\
    \ to the equation. c must be divisible by \"\r\n            \"gcd(a,b).\");\r\n\
    \      }\r\n      m_gcd = g;\r\n      m_x = c / g * x;\r\n      m_y = c / g *\
    \ y;\r\n    }\r\n    EuclideanAlgorithm(T a, T b) : EuclideanAlgorithm(a, b, std::gcd(a,\
    \ b)) {}\r\n\r\n    auto gcd() const { return m_gcd; }\r\n    auto get(T x, T\
    \ y) const { return m_a * x + m_b * y; }\r\n    auto get(T k) const -> std::pair<T,\
    \ T> {\r\n      if (m_b == 0) { return {m_x, m_y - k}; }\r\n      if (m_a == 0)\
    \ { return {m_x + k, m_y}; }\r\n      return {m_x + m_b * k, m_y - m_a * k};\r\
    \n    }\r\n    // x>=x_l\u3068\u306A\u308B\u3088\u3046\u306Ak\u306E\u7BC4\u56F2\
    \r\n    auto getMinX(T x_l = 0) const -> std::pair<T, T> {\r\n      return kRange(m_x,\
    \ m_b, x_l);\r\n    }\r\n    // y>=y_l\u3068\u306A\u308B\u3088\u3046\u306Ak\u306E\
    \u7BC4\u56F2\r\n    auto getMinY(T y_l = 0) const -> std::pair<T, T> {\r\n   \
    \   return kRange(m_y, -1 * m_a, y_l);\r\n    }\r\n    // x>=x_l, y>=y_l\u3068\
    \u306A\u308B\u3088\u3046\u306Ak\u306E\u7BC4\u56F2\r\n    auto getMin(T x_l = 0,\
    \ T y_l = 0) const -> std::pair<T, T> {\r\n      auto [xl, xr] = getMinX(x_l);\r\
    \n      auto [yl, yr] = getMinY(y_l);\r\n      return {std::max(xl, yl), std::min(xr,\
    \ yr)};\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 11 \"Library/Math/Math.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class T>\r\n  class Math {\r\n    const std::vector<T>\
    \ m_fac;\r\n    const std::vector<T> m_finv;\r\n\r\n    auto constructFac(int\
    \ s) {\r\n      std::vector<T> fac(s);\r\n      fac[0] = fac[1] = 1;\r\n     \
    \ for (long long i = 2; i < s; ++i) { fac[i] = fac[i - 1] * i; }\r\n      return\
    \ fac;\r\n    }\r\n    auto constructInv(int s) {\r\n      std::vector<T> finv(s);\r\
    \n      finv[s - 1] = 1 / m_fac[s - 1];\r\n      for (long long i = s - 2; i >=\
    \ 0; --i) {\r\n        finv[i] = finv[i + 1] * (i + 1);\r\n      }\r\n      return\
    \ finv;\r\n    }\r\n\r\n  public:\r\n    constexpr Math(int size = 3 * static_cast<int>(1e6))\r\
    \n        : m_fac(constructFac(size)), m_finv(constructInv(size)) {}\r\n\r\n \
    \   /* O(log b) */\r\n    static constexpr T pow(T a, long long b) {\r\n     \
    \ T ans = 1;\r\n      while (b > 0) {\r\n        if (b & 1) { ans *= a; }\r\n\
    \        b >>= 1;\r\n        a *= a;\r\n      }\r\n      return ans;\r\n    }\r\
    \n\r\n    /* O(log mod) */\r\n    template <class S>\r\n    static constexpr std::optional<long\
    \ long> log(S x, S y, S mod) {\r\n      x %= mod;\r\n      y %= mod;\r\n\r\n \
    \     if (mod == 1) { return 0; }\r\n      if (x == 0 && y == 0) { return 1; }\r\
    \n      if (x == 0 && y == 1) { return 0; }\r\n      if (x == 0) { return std::nullopt;\
    \ }\r\n      if (y == 1) { return 0; }\r\n\r\n      if (auto g = std::gcd(x, mod);\
    \ g > 1) {\r\n        if (y % g) { return std::nullopt; }\r\n        auto nx =\
    \ x / g;\r\n        auto nmod = mod / g;\r\n        auto ea = mtd::EuclideanAlgorithm(nx,\
    \ -nmod, 1);\r\n        auto [t, _] = ea.getMinX();\r\n        auto [nx_inv, __]\
    \ = ea.get(t);\r\n        nx_inv %= nmod;\r\n        if (auto ans = log(x, y /\
    \ g * nx_inv, nmod); ans) {\r\n          return ans.value() + 1;\r\n        }\
    \ else {\r\n          return ans;\r\n        }\r\n      }\r\n\r\n      auto s\
    \ = static_cast<S>(std::sqrt(mod));\r\n      S xe = y;\r\n      std::unordered_map<S,\
    \ S> map;\r\n      map.reserve(s);\r\n      for (auto i : std::views::iota(0,\
    \ s)) {\r\n        (xe *= x) %= mod;\r\n        map[xe] = i + 1;\r\n      }\r\n\
    \r\n      S xs = 1;\r\n      for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ s)) {\r\n        (xs *= x) %= mod;\r\n      }\r\n      S xse = 1;\r\n      for\
    \ (auto i : std::views::iota(0, mod / s + 5)) {\r\n        (xse *= xs) %= mod;\r\
    \n        if (map.contains(xse)) { return s * (i + 1) - map[xse]; }\r\n      }\r\
    \n      return std::nullopt;\r\n    }\r\n    constexpr std::optional<long long>\
    \ log(long long x,\r\n                                           long long y)\
    \ requires requires {\r\n      typename T::value_type;\r\n      T::mod();\r\n\
    \    }\r\n    { return log(x, y, T::mod()); }\r\n\r\n    constexpr auto fact(int\
    \ n) const { return (n < 0) ? 0 : m_fac[n]; }\r\n    constexpr auto factInv(int\
    \ n) const { return (n < 0 ? 0 : m_finv[n]); }\r\n    constexpr auto comb(int\
    \ n, int r) const {\r\n      return fact(n) * factInv(r) * factInv(n - r);\r\n\
    \    }\r\n    constexpr auto perm(int n, int r) const { return fact(n) * factInv(n\
    \ - r); }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Math/DynamicModInt.hpp\"\
    \n\nnamespace mtd {\n\n  template <class T = long long>\n  class DynamicModInt\
    \ {\n  public:\n    using value_type = T;\n    static inline T MOD = 0;\n    T\
    \ x;\n\n    constexpr static inline auto set_mod(T _MOD) { MOD = _MOD; }\n\n \
    \   constexpr DynamicModInt(T _x) : x(_x >= 0 ? _x % MOD : MOD + (_x % MOD)) {}\n\
    \    constexpr DynamicModInt() : DynamicModInt(0) {}\n\n    // \u56DB\u5247\u6F14\
    \u7B97\n    constexpr auto& operator+=(const DynamicModInt<T>& m) {\n      x +=\
    \ m.x;\n      if (x >= MOD) { x -= MOD; }\n      return *this;\n    }\n    constexpr\
    \ auto& operator-=(const DynamicModInt<T>& m) {\n      x -= m.x;\n      if (x\
    \ < 0) { x += MOD; }\n      return *this;\n    }\n    constexpr auto& operator*=(const\
    \ DynamicModInt<T>& m) {\n      x *= m.x;\n      if (x >= MOD) { x %= MOD; }\n\
    \      return *this;\n    }\n    constexpr auto& operator/=(const DynamicModInt<T>&\
    \ m) {\n      x *= mtd::Math<DynamicModInt<T>>::pow(m.x, MOD - 2).x;\n      if\
    \ (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n\n    constexpr auto operator+(const\
    \ DynamicModInt<T>& m) const {\n      auto t = *this;\n      t += m;\n      return\
    \ t;\n    }\n    constexpr auto operator-(const DynamicModInt<T>& m) const {\n\
    \      auto t = *this;\n      t -= m;\n      return t;\n    }\n    constexpr auto\
    \ operator*(const DynamicModInt<T>& m) const {\n      auto t = *this;\n      t\
    \ *= m;\n      return t;\n    }\n    constexpr auto operator/(const DynamicModInt<T>&\
    \ m) const {\n      auto t = *this;\n      t /= m;\n      return t;\n    }\n\n\
    \    constexpr auto& operator+=(const T& t) {\n      return *this += DynamicModInt<T>(t);\n\
    \    }\n    constexpr auto& operator-=(const T& t) {\n      return *this -= DynamicModInt<T>(t);\n\
    \    }\n    constexpr auto& operator*=(const T& n) {\n      return *this *= DynamicModInt<T>(n);\n\
    \    }\n    constexpr auto& operator/=(const T& n) {\n      return *this /= DynamicModInt<T>(n);\n\
    \    }\n    constexpr auto operator+(const T& t) const {\n      return *this +\
    \ DynamicModInt<T>(t);\n    }\n    constexpr auto operator-(const T& t) const\
    \ {\n      return *this - DynamicModInt<T>(t);\n    }\n    constexpr auto operator*(const\
    \ T& t) const {\n      return *this * DynamicModInt<T>(t);\n    }\n    constexpr\
    \ auto operator/(const T& t) const {\n      return *this / DynamicModInt<T>(t);\n\
    \    }\n    constexpr friend auto operator+(const T& t, const DynamicModInt<T>&\
    \ m) {\n      return m + t;\n    }\n    constexpr friend auto operator-(const\
    \ T& t, const DynamicModInt<T>& m) {\n      return -m + t;\n    }\n    constexpr\
    \ friend auto operator*(const T& t, const DynamicModInt<T>& m) {\n      return\
    \ m * t;\n    }\n    constexpr friend auto operator/(const T& t, const DynamicModInt<T>&\
    \ m) {\n      return DynamicModInt<T>(1) / m * t;\n    }\n\n    // \u5358\u9805\
    \u6F14\u7B97\n    constexpr auto operator-() const { return DynamicModInt<T>(0\
    \ - x); }\n\n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr auto operator!=(const\
    \ DynamicModInt<T>& m) const {\n      return x != m.x;\n    }\n    constexpr auto\
    \ operator==(const DynamicModInt<T>& m) const {\n      return !(x != m.x);\n \
    \   }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const DynamicModInt<T>& m)\
    \ {\n      return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              DynamicModInt<T>& m) {\n\
    \      return is >> m.x;\n    }\n\n    constexpr auto val() const { return x;\
    \ }\n    static constexpr auto mod() { return MOD; }\n  };\n\n}  // namespace\
    \ mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <iterator>\n\n#include \"./Math.hpp\"\
    \n\nnamespace mtd {\n\n  template <class T = long long>\n  class DynamicModInt\
    \ {\n  public:\n    using value_type = T;\n    static inline T MOD = 0;\n    T\
    \ x;\n\n    constexpr static inline auto set_mod(T _MOD) { MOD = _MOD; }\n\n \
    \   constexpr DynamicModInt(T _x) : x(_x >= 0 ? _x % MOD : MOD + (_x % MOD)) {}\n\
    \    constexpr DynamicModInt() : DynamicModInt(0) {}\n\n    // \u56DB\u5247\u6F14\
    \u7B97\n    constexpr auto& operator+=(const DynamicModInt<T>& m) {\n      x +=\
    \ m.x;\n      if (x >= MOD) { x -= MOD; }\n      return *this;\n    }\n    constexpr\
    \ auto& operator-=(const DynamicModInt<T>& m) {\n      x -= m.x;\n      if (x\
    \ < 0) { x += MOD; }\n      return *this;\n    }\n    constexpr auto& operator*=(const\
    \ DynamicModInt<T>& m) {\n      x *= m.x;\n      if (x >= MOD) { x %= MOD; }\n\
    \      return *this;\n    }\n    constexpr auto& operator/=(const DynamicModInt<T>&\
    \ m) {\n      x *= mtd::Math<DynamicModInt<T>>::pow(m.x, MOD - 2).x;\n      if\
    \ (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n\n    constexpr auto operator+(const\
    \ DynamicModInt<T>& m) const {\n      auto t = *this;\n      t += m;\n      return\
    \ t;\n    }\n    constexpr auto operator-(const DynamicModInt<T>& m) const {\n\
    \      auto t = *this;\n      t -= m;\n      return t;\n    }\n    constexpr auto\
    \ operator*(const DynamicModInt<T>& m) const {\n      auto t = *this;\n      t\
    \ *= m;\n      return t;\n    }\n    constexpr auto operator/(const DynamicModInt<T>&\
    \ m) const {\n      auto t = *this;\n      t /= m;\n      return t;\n    }\n\n\
    \    constexpr auto& operator+=(const T& t) {\n      return *this += DynamicModInt<T>(t);\n\
    \    }\n    constexpr auto& operator-=(const T& t) {\n      return *this -= DynamicModInt<T>(t);\n\
    \    }\n    constexpr auto& operator*=(const T& n) {\n      return *this *= DynamicModInt<T>(n);\n\
    \    }\n    constexpr auto& operator/=(const T& n) {\n      return *this /= DynamicModInt<T>(n);\n\
    \    }\n    constexpr auto operator+(const T& t) const {\n      return *this +\
    \ DynamicModInt<T>(t);\n    }\n    constexpr auto operator-(const T& t) const\
    \ {\n      return *this - DynamicModInt<T>(t);\n    }\n    constexpr auto operator*(const\
    \ T& t) const {\n      return *this * DynamicModInt<T>(t);\n    }\n    constexpr\
    \ auto operator/(const T& t) const {\n      return *this / DynamicModInt<T>(t);\n\
    \    }\n    constexpr friend auto operator+(const T& t, const DynamicModInt<T>&\
    \ m) {\n      return m + t;\n    }\n    constexpr friend auto operator-(const\
    \ T& t, const DynamicModInt<T>& m) {\n      return -m + t;\n    }\n    constexpr\
    \ friend auto operator*(const T& t, const DynamicModInt<T>& m) {\n      return\
    \ m * t;\n    }\n    constexpr friend auto operator/(const T& t, const DynamicModInt<T>&\
    \ m) {\n      return DynamicModInt<T>(1) / m * t;\n    }\n\n    // \u5358\u9805\
    \u6F14\u7B97\n    constexpr auto operator-() const { return DynamicModInt<T>(0\
    \ - x); }\n\n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr auto operator!=(const\
    \ DynamicModInt<T>& m) const {\n      return x != m.x;\n    }\n    constexpr auto\
    \ operator==(const DynamicModInt<T>& m) const {\n      return !(x != m.x);\n \
    \   }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const DynamicModInt<T>& m)\
    \ {\n      return os << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              DynamicModInt<T>& m) {\n\
    \      return is >> m.x;\n    }\n\n    constexpr auto val() const { return x;\
    \ }\n    static constexpr auto mod() { return MOD; }\n  };\n\n}  // namespace\
    \ mtd\n"
  dependsOn:
  - Library/Math/Math.hpp
  - Library/Math/EuclideanAlgorithm.hpp
  isVerificationFile: false
  path: Library/Math/DynamicModInt.hpp
  requiredBy: []
  timestamp: '2025-01-02 21:02:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/Math_pow_dynamic.test.cpp
  - Test/Math/Math_dynamic.test.cpp
documentation_of: Library/Math/DynamicModInt.hpp
layout: document
redirect_from:
- /library/Library/Math/DynamicModInt.hpp
- /library/Library/Math/DynamicModInt.hpp.html
title: Library/Math/DynamicModInt.hpp
---