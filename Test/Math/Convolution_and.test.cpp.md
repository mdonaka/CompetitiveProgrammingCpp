---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Math/Bit.hpp
    title: Library/Math/Bit.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Convolution.hpp
    title: Library/Math/Convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/EuclideanAlgorithm.hpp
    title: Library/Math/EuclideanAlgorithm.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Math.hpp
    title: Library/Math/Math.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Mobius.hpp
    title: Library/Math/Mobius.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/ModInt.hpp
    title: Library/Math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Zeta.hpp
    title: Library/Math/Zeta.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"Test/Math/Convolution_and.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n#include <iostream>\n\
    \n// begin:tag includes\n#line 2 \"Library/Math/Convolution.hpp\"\n\n#include\
    \ <ranges>\n#include <vector>\n\n#line 2 \"Library/Math/Mobius.hpp\"\n\n#line\
    \ 5 \"Library/Math/Mobius.hpp\"\n\n#line 2 \"Library/Math/Bit.hpp\"\n\nnamespace\
    \ mtd {\n\n  constexpr unsigned clz(unsigned int x) {\n    int c = 0;\n    if\
    \ (x == 0) { return 0; }\n    if (x & 0xffff0000) {\n      x &= 0xffff0000;\n\
    \      c |= 0x10;\n    }\n    if (x & 0xff00ff00) {\n      x &= 0xff00ff00;\n\
    \      c |= 0x08;\n    }\n    if (x & 0xf0f0f0f0) {\n      x &= 0xf0f0f0f0;\n\
    \      c |= 0x04;\n    }\n    if (x & 0xcccccccc) {\n      x &= 0xcccccccc;\n\
    \      c |= 0x02;\n    }\n    if (x & 0xaaaaaaaa) { c |= 0x01; }\n    return c\
    \ + 1;\n  }\n\n  constexpr unsigned ctz(unsigned int n) {\n    if (!n) return\
    \ -1;\n    unsigned int c = 32;\n    n &= -static_cast<signed int>(n);\n    if\
    \ (n) c--;\n    if (n & 0x0000FFFF) c -= 16;\n    if (n & 0x00FF00FF) c -= 8;\n\
    \    if (n & 0x0F0F0F0F) c -= 4;\n    if (n & 0x33333333) c -= 2;\n    if (n &\
    \ 0x55555555) c -= 1;\n    return c;\n  }\n\n  constexpr unsigned long long popcount(unsigned\
    \ long long x) {\n    x = x - ((x >> 1) & 0x5555555555555555);\n    x = (x & 0x3333333333333333)\
    \ + ((x >> 2) & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;\n\
    \    x = x + (x >> 8);\n    x = x + (x >> 16);\n    x = x + (x >> 32);\n    return\
    \ x & 0x0000007f;\n  }\n\n}  // namespace mtd\n#line 7 \"Library/Math/Mobius.hpp\"\
    \n\nnamespace mtd::mobius {\n\n  template <class T>\n  auto n(const std::vector<T>&\
    \ a) {\n    auto ret = a;\n    for (auto i : std::views::iota(static_cast<size_t>(1),\
    \ a.size())) {\n      ret[i] = a[i] - a[i - 1];\n    }\n    return ret;\n  }\n\
    \n  template <class T>\n  auto bit_subset(const std::vector<T>& a) {\n    auto\
    \ ret = a;\n    int size = clz(a.size());\n    for (auto b : std::views::iota(0,\
    \ size)) {\n      for (auto bit : std::views::iota(0, 1LL << size)) {\n      \
    \  if (((bit >> b) & 1) && bit < a.size()) {\n          ret[bit] -= ret[bit ^\
    \ (1LL << b)];\n        }\n      }\n    }\n    return ret;\n  }\n\n  template\
    \ <class T>\n  auto bit_supset(const std::vector<T>& a) {\n    auto ret = a;\n\
    \    int size = clz(a.size());\n    for (auto b : std::views::iota(0, size)) {\n\
    \      for (auto bit : std::views::iota(0, 1LL << size)) {\n        if (((bit\
    \ >> b) & 1) && bit < a.size()) {\n          ret[bit ^ (1LL << b)] -= ret[bit];\n\
    \        }\n      }\n    }\n    return ret;\n  }\n\n}  // namespace mtd::mobius\n\
    #line 2 \"Library/Math/Zeta.hpp\"\n\n#line 5 \"Library/Math/Zeta.hpp\"\n\n#line\
    \ 7 \"Library/Math/Zeta.hpp\"\n\nnamespace mtd::zeta {\n\n  template <class T>\n\
    \  auto n(const std::vector<T>& a) {\n    auto ret = a;\n    for (auto i : std::views::iota(static_cast<size_t>(1),\
    \ a.size())) {\n      ret[i] += ret[i - 1];\n    }\n    return ret;\n  }\n\n \
    \ template <class T>\n  auto bit_subset(const std::vector<T>& a) {\n    auto ret\
    \ = a;\n    int size = clz(a.size());\n    for (auto b : std::views::iota(0, size))\
    \ {\n      for (auto bit : std::views::iota(0, 1LL << size)) {\n        if (((bit\
    \ >> b) & 1) && bit < a.size()) {\n          ret[bit] += ret[bit ^ (1LL << b)];\n\
    \        }\n      }\n    }\n    return ret;\n  }\n\n  template <class T>\n  auto\
    \ bit_supset(const std::vector<T>& a) {\n    auto ret = a;\n    int size = clz(a.size());\n\
    \    for (auto b : std::views::iota(0, size)) {\n      for (auto bit : std::views::iota(0,\
    \ 1LL << size)) {\n        if (((bit >> b) & 1) && bit < a.size()) {\n       \
    \   ret[bit ^ (1LL << b)] += ret[bit];\n        }\n      }\n    }\n    return\
    \ ret;\n  }\n}  // namespace mtd::zeta\n#line 8 \"Library/Math/Convolution.hpp\"\
    \n\nnamespace mtd::convolution {\n\n  template <class T>\n  auto bitwise_and(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    auto za = mtd::zeta::bit_supset(a);\n\
    \    auto zb = mtd::zeta::bit_supset(b);\n    auto zab = std::vector<T>();\n \
    \   for (auto i : std::views::iota(static_cast<size_t>(0), a.size())) {\n    \
    \  zab.emplace_back(za[i] * zb[i]);\n    }\n    auto zma = mtd::mobius::bit_supset(za);\n\
    \    return mtd::mobius::bit_supset(zab);\n  }\n\n}  // namespace mtd::convolution\n\
    #line 2 \"Library/Math/ModInt.hpp\"\n\n#line 4 \"Library/Math/ModInt.hpp\"\n#include\
    \ <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\n\r\n#include <cmath>\r\n#include\
    \ <numeric>\r\n#include <optional>\r\n#line 7 \"Library/Math/Math.hpp\"\n#include\
    \ <unordered_map>\r\n#line 9 \"Library/Math/Math.hpp\"\n\r\n#line 2 \"Library/Math/EuclideanAlgorithm.hpp\"\
    \n\r\n#line 5 \"Library/Math/EuclideanAlgorithm.hpp\"\n#include <tuple>\r\n\r\n\
    namespace mtd {\r\n\r\n  class EuclideanAlgorithm {\r\n    using T = long long;\r\
    \n\r\n    // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u3066\u3057\u307E\u3046\r\n    const static inline T m_mx =\
    \ 1e9;\r\n\r\n    const T m_a;\r\n    const T m_b;\r\n    const T m_c;\r\n\r\n\
    \    T m_gcd;\r\n    T m_x;\r\n    T m_y;\r\n\r\n    auto excludedEuclidAlgorithm(T\
    \ a, T b) -> std::tuple<T, T, T> {\r\n      if (a < 0) {\r\n        auto [g, x,\
    \ y] = excludedEuclidAlgorithm(-a, -b);\r\n        return {g, -x, -y};\r\n   \
    \   }\r\n      if (b == 0) { return {a, 1, 0}; }\r\n      auto [g, y, x] = excludedEuclidAlgorithm(b,\
    \ a % b);\r\n      y -= a / b * x;\r\n      return {g, x, y};\r\n    }\r\n\r\n\
    \    auto kRange(T x, T b, T l) const -> std::pair<T, T> {\r\n      // x + b *\
    \ k >= l \u3092\u6E80\u305F\u3059 k \u306E\u7BC4\u56F2\u3092\u6C42\u3081\u308B\
    \r\n      T xd = (l - x);\r\n      if (b == 0 && x >= l) { return {-m_mx, m_mx};\
    \ }\r\n      if (b == 0 && x < l) { return {m_mx, -m_mx}; }\r\n      if (b > 0\
    \ && xd < 0) { return {xd / b, m_mx}; }\r\n      if (b > 0 && xd >= 0) { return\
    \ {(xd + b - 1) / b, m_mx}; }\r\n      if (b < 0 && xd < 0) { return {-m_mx, (-xd)\
    \ / (-b)}; }\r\n      if (b < 0 && xd >= 0) { return {-m_mx, -(xd - b - 1) / (-b)};\
    \ }\r\n      return {m_mx, -m_mx};\r\n    }\r\n\r\n  public:\r\n    auto debug()\
    \ const {\r\n      std::cout << m_a << \" * \" << m_x << \" + \" << m_b << \"\
    \ * \" << m_y << \" = \"\r\n                << m_c << std::endl;\r\n      std::cout\
    \ << \"calc: \" << m_a * m_x + m_b * m_y << \" = \" << m_c\r\n               \
    \ << std::endl;\r\n    }\r\n\r\n    EuclideanAlgorithm(T a, T b, T c) : m_a(a),\
    \ m_b(b), m_c(c) {\r\n      if (a == 0 && b == 0) { throw std::runtime_error(\"\
    \"); }\r\n      auto [g, x, y] = excludedEuclidAlgorithm(a, b);\r\n      if (c\
    \ % g > 0) {\r\n        throw std::runtime_error(\r\n            \"There is no\
    \ solution to the equation. c must be divisible by \"\r\n            \"gcd(a,b).\"\
    );\r\n      }\r\n      m_gcd = g;\r\n      m_x = c / g * x;\r\n      m_y = c /\
    \ g * y;\r\n    }\r\n    EuclideanAlgorithm(T a, T b) : EuclideanAlgorithm(a,\
    \ b, std::gcd(a, b)) {}\r\n\r\n    auto gcd() const { return m_gcd; }\r\n    auto\
    \ get(T x, T y) const { return m_a * x + m_b * y; }\r\n    auto get(T k) const\
    \ -> std::pair<T, T> {\r\n      if (m_b == 0) { return {m_x, m_y - k}; }\r\n \
    \     if (m_a == 0) { return {m_x + k, m_y}; }\r\n      return {m_x + m_b * k,\
    \ m_y - m_a * k};\r\n    }\r\n    // x>=x_l\u3068\u306A\u308B\u3088\u3046\u306A\
    k\u306E\u7BC4\u56F2\r\n    auto getMinX(T x_l = 0) const -> std::pair<T, T> {\r\
    \n      return kRange(m_x, m_b, x_l);\r\n    }\r\n    // y>=y_l\u3068\u306A\u308B\
    \u3088\u3046\u306Ak\u306E\u7BC4\u56F2\r\n    auto getMinY(T y_l = 0) const ->\
    \ std::pair<T, T> {\r\n      return kRange(m_y, -1 * m_a, y_l);\r\n    }\r\n \
    \   // x>=x_l, y>=y_l\u3068\u306A\u308B\u3088\u3046\u306Ak\u306E\u7BC4\u56F2\r\
    \n    auto getMin(T x_l = 0, T y_l = 0) const -> std::pair<T, T> {\r\n      auto\
    \ [xl, xr] = getMinX(x_l);\r\n      auto [yl, yr] = getMinY(y_l);\r\n      return\
    \ {std::max(xl, yl), std::min(xr, yr)};\r\n    }\r\n  };\r\n\r\n}  // namespace\
    \ mtd\r\n#line 11 \"Library/Math/Math.hpp\"\n\r\nnamespace mtd {\r\n  template\
    \ <class T>\r\n  class Math {\r\n    const std::vector<T> m_fac;\r\n    const\
    \ std::vector<T> m_finv;\r\n\r\n    auto constructFac(int s) {\r\n      std::vector<T>\
    \ fac(s);\r\n      fac[0] = fac[1] = 1;\r\n      for (long long i = 2; i < s;\
    \ ++i) { fac[i] = fac[i - 1] * i; }\r\n      return fac;\r\n    }\r\n    auto\
    \ constructInv(int s) {\r\n      std::vector<T> finv(s);\r\n      finv[s - 1]\
    \ = 1 / m_fac[s - 1];\r\n      for (long long i = s - 2; i >= 0; --i) {\r\n  \
    \      finv[i] = finv[i + 1] * (i + 1);\r\n      }\r\n      return finv;\r\n \
    \   }\r\n\r\n  public:\r\n    constexpr Math(int size = 3 * static_cast<int>(1e6))\r\
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
    \ - r); }\r\n  };\r\n}  // namespace mtd\r\n#line 7 \"Library/Math/ModInt.hpp\"\
    \n\nnamespace mtd {\n\n  template <int MOD, class T = long long>\n  class ModInt\
    \ {\n  public:\n    using value_type = T;\n    T x;\n\n    constexpr ModInt(T\
    \ _x) : x(_x >= 0 ? _x % MOD : MOD + (_x % MOD)) {}\n    constexpr ModInt() :\
    \ ModInt(0) {}\n\n    // \u56DB\u5247\u6F14\u7B97\n    constexpr auto& operator+=(const\
    \ ModInt<MOD, T>& m) {\n      x += m.x;\n      if (x >= MOD) { x -= MOD; }\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const ModInt<MOD, T>&\
    \ m) {\n      x -= m.x;\n      if (x < 0) { x += MOD; }\n      return *this;\n\
    \    }\n    constexpr auto& operator*=(const ModInt<MOD, T>& m) {\n      x *=\
    \ m.x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n    constexpr\
    \ auto& operator/=(const ModInt<MOD, T>& m) {\n      x *= mtd::Math<ModInt<MOD,\
    \ T>>::pow(m.x, MOD - 2).x;\n      if (x >= MOD) { x %= MOD; }\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const ModInt<MOD, T>& m) const {\n    \
    \  auto t = *this;\n      t += m;\n      return t;\n    }\n    constexpr auto\
    \ operator-(const ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t -=\
    \ m;\n      return t;\n    }\n    constexpr auto operator*(const ModInt<MOD, T>&\
    \ m) const {\n      auto t = *this;\n      t *= m;\n      return t;\n    }\n \
    \   constexpr auto operator/(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t /= m;\n      return t;\n    }\n\n    constexpr auto& operator+=(const\
    \ T& t) {\n      return *this += ModInt<MOD, T>(t);\n    }\n    constexpr auto&\
    \ operator-=(const T& t) {\n      return *this -= ModInt<MOD, T>(t);\n    }\n\
    \    constexpr auto& operator*=(const T& n) {\n      return *this *= ModInt<MOD,\
    \ T>(n);\n    }\n    constexpr auto& operator/=(const T& n) {\n      return *this\
    \ /= ModInt<MOD, T>(n);\n    }\n    constexpr auto operator+(const T& t) const\
    \ {\n      return *this + ModInt<MOD, T>(t);\n    }\n    constexpr auto operator-(const\
    \ T& t) const {\n      return *this - ModInt<MOD, T>(t);\n    }\n    constexpr\
    \ auto operator*(const T& t) const {\n      return *this * ModInt<MOD, T>(t);\n\
    \    }\n    constexpr auto operator/(const T& t) const {\n      return *this /\
    \ ModInt<MOD, T>(t);\n    }\n    constexpr friend auto operator+(const T& t, const\
    \ ModInt<MOD, T>& m) {\n      return m + t;\n    }\n    constexpr friend auto\
    \ operator-(const T& t, const ModInt<MOD, T>& m) {\n      return -m + t;\n   \
    \ }\n    constexpr friend auto operator*(const T& t, const ModInt<MOD, T>& m)\
    \ {\n      return m * t;\n    }\n    constexpr friend auto operator/(const T&\
    \ t, const ModInt<MOD, T>& m) {\n      return ModInt<MOD, T>(1) / m * t;\n   \
    \ }\n\n    // \u5358\u9805\u6F14\u7B97\n    constexpr auto operator-() const {\
    \ return ModInt<MOD, T>(0 - x); }\n\n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr\
    \ auto operator!=(const ModInt<MOD, T>& m) const {\n      return x != m.x;\n \
    \   }\n    constexpr auto operator==(const ModInt<MOD, T>& m) const {\n      return\
    \ !(x != m.x);\n    }\n\n    // \u5165\u51FA\u529B\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const ModInt<MOD, T>& m) {\n      return os << m.x;\n    }\n    constexpr friend\
    \ std::istream& operator>>(std::istream& is,\n                               \
    \               ModInt<MOD, T>& m) {\n      return is >> m.x;\n    }\n\n    constexpr\
    \ auto val() const { return x; }\n    static constexpr auto mod() { return MOD;\
    \ }\n  };\n\n}  // namespace mtd\n#line 2 \"Library/Range/istream.hpp\"\n\n#line\
    \ 4 \"Library/Range/istream.hpp\"\n\n#line 2 \"Library/Utility/io.hpp\"\n\n#line\
    \ 5 \"Library/Utility/io.hpp\"\n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\
    \n\n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#include <functional>\n\nnamespace\
    \ mtd {\n  namespace util {\n    template <class F, class T>\n    constexpr auto\
    \ tuple_transform(F&& f, T&& t) {\n      return std::apply(\n          [&]<class...\
    \ Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n#line 9 \"Library/Utility/io.hpp\"\n\nnamespace mtd\
    \ {\n  namespace io {\n\n    namespace type {\n      template <class T>\n    \
    \  struct vec {\n        using value_type = T;\n      };\n      template <class\
    \ T>\n      concept is_vec = requires {\n        requires std::is_same_v<T, vec<typename\
    \ T::value_type>>;\n      };\n\n      template <class T>\n      struct mat {\n\
    \        using value_type = T;\n      };\n      template <class T>\n      concept\
    \ is_mat = requires {\n        requires std::is_same_v<T, mat<typename T::value_type>>;\n\
    \      };\n    }  // namespace type\n\n    template <class T>\n    auto _input()\
    \ {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n    template <typename\
    \ T>\n    requires requires { typename std::tuple_size<T>::type; }\n    auto _input()\
    \ {\n      T x;\n      util::tuple_for_each([](auto&& i) { std::cin >> i; }, x);\n\
    \      return x;\n    }\n    template <type::is_vec T>\n    auto _input(int n)\
    \ {\n      std::vector<typename T::value_type> v;\n      v.reserve(n);\n     \
    \ for (auto i : std::views::iota(0, n)) {\n        v.emplace_back(_input<typename\
    \ T::value_type>());\n      }\n      return v;\n    }\n    template <type::is_mat\
    \ T>\n    auto _input(int h, int w) {\n      std::vector<std::vector<typename\
    \ T::value_type>> mat;\n      mat.reserve(h);\n      for (auto i : std::views::iota(0,\
    \ h)) {\n        mat.emplace_back(_input<type::vec<typename T::value_type>>(w));\n\
    \      }\n      return mat;\n    }\n\n    template <int N, class Tuple, class\
    \ T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple& t, Sizes...\
    \ sizes);\n    template <int N, class Tuple, type::is_vec T, class... Args, class\
    \ Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t, Size size,\
    \ Sizes... sizes);\n    template <int N, class Tuple, type::is_mat T, class...\
    \ Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes);\n\n    template <int N, class\
    \ Tuple, class T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Sizes... sizes) {\n      std::get<N>(t) = _input<T>();\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);\n\
    \      }\n    }\n    template <int N, class Tuple, type::is_vec T, class... Args,\
    \ class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t,\
    \ Size size, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size);\n    \
    \  if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t,\
    \ sizes...);\n      }\n    }\n    template <int N, class Tuple, type::is_mat T,\
    \ class... Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size_h,\
    \ size_w);\n      if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N\
    \ + 1, Tuple, Args...>(t, sizes...);\n      }\n    }\n\n    template <class T>\n\
    \    struct _Converter {\n      using type = T;\n    };\n    template <class T>\n\
    \    struct _Converter<type::vec<T>> {\n      using type = std::vector<T>;\n \
    \   };\n    template <class T>\n    struct _Converter<type::mat<T>> {\n      using\
    \ type = std::vector<std::vector<T>>;\n    };\n\n    template <class... Args,\
    \ class... Sizes>\n    requires(std::convertible_to<Sizes, size_t>&&...) auto\
    \ in(Sizes... sizes) {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base, sizes...);\n      return\
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ _count) : count(_count) {\n          operator++();\n        }\n\n        constexpr\
    \ auto operator*() const { return val; }\n        constexpr auto& operator++()\
    \ {\n          --count;\n          if (count >= 0) { val = io::in<Args...>();\
    \ }\n          return *this;\n        }\n        constexpr auto operator++(int)\
    \ { return ++*this; }\n\n        constexpr auto operator==(const iterator& s)\
    \ const {\n          return count == s.count;\n        }\n        constexpr auto\
    \ operator==(std::default_sentinel_t) const {\n          return count < 0 || std::cin.eof()\
    \ || std::cin.fail() ||\n                 std::cin.bad();\n        }\n       \
    \ constexpr friend auto operator==(std::default_sentinel_t s,\n              \
    \                           const iterator& li) {\n          return li == s;\n\
    \        }\n      };\n\n      int count;\n\n    public:\n      constexpr explicit\
    \ istream_view(int _count) : count(_count) {}\n      constexpr explicit istream_view()\
    \ : istream_view(_inf) {}\n      constexpr auto begin() const { return iterator(count);\
    \ }\n      constexpr auto end() const { return std::default_sentinel; }\n    };\n\
    \  }  // namespace ranges\n\n  namespace views {\n    namespace __detail {\n \
    \     template <typename... _Args>\n      concept __can_istream_view = requires\
    \ {\n        ranges::istream_view(std::declval<_Args>()...);\n      };\n    }\
    \  // namespace __detail\n\n    template <class... Args>\n    struct _Istream\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 8 \"Test/Math/Convolution_and.test.cpp\"\
    \n// end:tag includes\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  using mint = mtd::ModInt<998244353>;\n\n  auto [n] = mtd::io::in<int>();\n\
    \  auto a = mtd::io::_input<mtd::io::type::vec<mint>>(1LL << n);\n  auto b = mtd::io::_input<mtd::io::type::vec<mint>>(1LL\
    \ << n);\n\n  auto ans = mtd::convolution::bitwise_and(a, b);\n  for (auto x :\
    \ ans) { std::cout << x << \" \"; }\n  std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <iostream>\n\n// begin:tag includes\n#include \"../../Library/Math/Convolution.hpp\"\
    \n#include \"../../Library/Math/ModInt.hpp\"\n#include \"../../Library/Range/istream.hpp\"\
    \n// end:tag includes\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  using mint = mtd::ModInt<998244353>;\n\n  auto [n] = mtd::io::in<int>();\n\
    \  auto a = mtd::io::_input<mtd::io::type::vec<mint>>(1LL << n);\n  auto b = mtd::io::_input<mtd::io::type::vec<mint>>(1LL\
    \ << n);\n\n  auto ans = mtd::convolution::bitwise_and(a, b);\n  for (auto x :\
    \ ans) { std::cout << x << \" \"; }\n  std::cout << std::endl;\n}\n"
  dependsOn:
  - Library/Math/Convolution.hpp
  - Library/Math/Mobius.hpp
  - Library/Math/Bit.hpp
  - Library/Math/Zeta.hpp
  - Library/Math/ModInt.hpp
  - Library/Math/Math.hpp
  - Library/Math/EuclideanAlgorithm.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: true
  path: Test/Math/Convolution_and.test.cpp
  requiredBy: []
  timestamp: '2025-01-02 21:02:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Math/Convolution_and.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/Convolution_and.test.cpp
- /verify/Test/Math/Convolution_and.test.cpp.html
title: Test/Math/Convolution_and.test.cpp
---
