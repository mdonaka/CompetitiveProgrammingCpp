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
    \ <ranges>\n#include <vector>\n\n#line 1 \"Library/Math/Mobius.hpp\"\n\n#line\
    \ 4 \"Library/Math/Mobius.hpp\"\n\n#line 2 \"Library/Math/Bit.hpp\"\n\nnamespace\
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
    \ x & 0x0000007f;\n  }\n\n}  // namespace mtd\n#line 6 \"Library/Math/Mobius.hpp\"\
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
    \ <iterator>\n\n#line 2 \"Library/Math/Math.hpp\"\n\r\n#line 4 \"Library/Math/Math.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <class T>\r\n  class Math {\r\n    const std::vector<T>\
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
    \ {\n    T x;\n\n  public:\n    constexpr ModInt(T x) : x(x >= 0 ? x % MOD : MOD\
    \ + (x % MOD)) {}\n    constexpr ModInt() : ModInt(0) {}\n\n    // \u56DB\u5247\
    \u6F14\u7B97\n    constexpr auto& operator+=(const ModInt<MOD, T>& m) {\n    \
    \  x += m.x;\n      if (x >= MOD) { x -= MOD; }\n      return *this;\n    }\n\
    \    constexpr auto& operator-=(const ModInt<MOD, T>& m) {\n      x -= m.x;\n\
    \      if (x < 0) { x += MOD; }\n      return *this;\n    }\n    constexpr auto&\
    \ operator*=(const ModInt<MOD, T>& m) {\n      x *= m.x;\n      if (x >= MOD)\
    \ { x %= MOD; }\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ ModInt<MOD, T>& m) {\n      x *= mtd::Math<ModInt<MOD, T>>::pow(m.x, MOD - 2).x;\n\
    \      if (x >= MOD) { x %= MOD; }\n      return *this;\n    }\n\n    constexpr\
    \ auto operator+(const ModInt<MOD, T>& m) const {\n      auto t = *this;\n   \
    \   t += m;\n      return t;\n    }\n    constexpr auto operator-(const ModInt<MOD,\
    \ T>& m) const {\n      auto t = *this;\n      t -= m;\n      return t;\n    }\n\
    \    constexpr auto operator*(const ModInt<MOD, T>& m) const {\n      auto t =\
    \ *this;\n      t *= m;\n      return t;\n    }\n    constexpr auto operator/(const\
    \ ModInt<MOD, T>& m) const {\n      auto t = *this;\n      t /= m;\n      return\
    \ t;\n    }\n\n    constexpr auto& operator+=(const T& t) {\n      return *this\
    \ += ModInt<MOD, T>(t);\n    }\n    constexpr auto& operator-=(const T& t) {\n\
    \      return *this -= ModInt<MOD, T>(t);\n    }\n    constexpr auto& operator*=(const\
    \ T& n) {\n      return *this *= ModInt<MOD, T>(n);\n    }\n    constexpr auto&\
    \ operator/=(const T& n) {\n      return *this /= ModInt<MOD, T>(n);\n    }\n\
    \    constexpr auto operator+(const T& t) const {\n      return *this + ModInt<MOD,\
    \ T>(t);\n    }\n    constexpr auto operator-(const T& t) const {\n      return\
    \ *this - ModInt<MOD, T>(t);\n    }\n    constexpr auto operator*(const T& t)\
    \ const {\n      return *this * ModInt<MOD, T>(t);\n    }\n    constexpr auto\
    \ operator/(const T& t) const {\n      return *this / ModInt<MOD, T>(t);\n   \
    \ }\n    constexpr friend auto operator+(const T& t, const ModInt<MOD, T>& m)\
    \ {\n      return m + t;\n    }\n    constexpr friend auto operator-(const T&\
    \ t, const ModInt<MOD, T>& m) {\n      return -m + t;\n    }\n    constexpr friend\
    \ auto operator*(const T& t, const ModInt<MOD, T>& m) {\n      return m * t;\n\
    \    }\n    constexpr friend auto operator/(const T& t, const ModInt<MOD, T>&\
    \ m) {\n      return ModInt<MOD, T>(1) / m * t;\n    }\n\n    // \u5358\u9805\u6F14\
    \u7B97\n    constexpr auto operator-() const { return ModInt<MOD, T>(0 - x); }\n\
    \n    // \u6BD4\u8F03\u6F14\u7B97\n    constexpr auto operator!=(const ModInt<MOD,\
    \ T>& m) const {\n      return x != m.x;\n    }\n\n    // \u5165\u51FA\u529B\n\
    \    constexpr friend std::ostream& operator<<(std::ostream& os,\n           \
    \                                   const ModInt<MOD, T>& m) {\n      return os\
    \ << m.x;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is,\n                                              ModInt<MOD, T>& m) {\n  \
    \    return is >> m.x;\n    }\n\n    constexpr auto val() const { return x; }\n\
    \  };\n\n}  // namespace mtd\n#line 2 \"Library/Range/istream.hpp\"\n\n#line 4\
    \ \"Library/Range/istream.hpp\"\n\n#line 2 \"Library/Utility/io.hpp\"\n\n#line\
    \ 5 \"Library/Utility/io.hpp\"\n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\
    \n\nnamespace mtd {\n  namespace io {\n\n    namespace type {\n      template\
    \ <class T, int Pre = 1, int Size = 0>\n      struct vec {\n        using value_type\
    \ = T;\n        static constexpr int pre = Pre;\n        static constexpr int\
    \ size = Size;\n      };\n      template <class T>\n      concept is_vec = requires\
    \ {\n        std::is_same_v<T, vec<typename T::value_type, T::pre, T::size>>;\n\
    \      };\n    }  // namespace type\n\n    template <type::is_vec T>\n    auto\
    \ _input(int n) {\n      std::vector<typename T::value_type> v(n);\n      for\
    \ (auto i : std::views::iota(0, n)) { std::cin >> v[i]; }\n      return v;\n \
    \   }\n\n    template <class T>\n    auto _input() {\n      T x;\n      std::cin\
    \ >> x;\n      return x;\n    }\n\n    template <int N, class Tuple, class T,\
    \ class... Args>\n    auto _tuple_input(Tuple& t) {\n      if constexpr (type::is_vec<T>)\
    \ {\n        if constexpr (T::size == 0) {\n          std::get<N>(t) = _input<T>(std::get<N\
    \ - T::pre>(t));\n        } else {\n          std::get<N>(t) = _input<T>(T::size);\n\
    \        }\n      } else {\n        std::get<N>(t) = _input<T>();\n      }\n \
    \     if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple,\
    \ Args...>(t);\n      }\n    }\n\n    template <class T>\n    struct _Converter\
    \ {\n      using type = T;\n    };\n    template <class T, int Pre, int Size>\n\
    \    struct _Converter<type::vec<T, Pre, Size>> {\n      using type = std::vector<T>;\n\
    \    };\n\n    template <class... Args>\n    auto in() {\n      auto base = std::tuple<typename\
    \ _Converter<Args>::type...>();\n      _tuple_input<0, decltype(base), Args...>(base);\n\
    \      return base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line\
    \ 6 \"Library/Range/istream.hpp\"\n\nnamespace mtd {\n  namespace ranges {\n\n\
    \    constexpr int _inf = 1e9;\n\n    template <class... Args>\n    struct istream_view\n\
    \        : public std::ranges::view_interface<istream_view<Args...>> {\n     \
    \ class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n        constexpr auto operator*()\
    \ const { return val; }\n        constexpr auto& operator++() {\n          --count;\n\
    \          if (count >= 0) { val = io::in<Args...>(); }\n          return *this;\n\
    \        }\n        constexpr auto operator++(int) { return ++*this; }\n\n   \
    \     constexpr auto operator==(const iterator& s) const {\n          return count\
    \ == s.count;\n        }\n        constexpr auto operator==(std::default_sentinel_t\
    \ s) const {\n          return count < 0 || std::cin.eof() || std::cin.fail()\
    \ ||\n                 std::cin.bad();\n        }\n        constexpr friend auto\
    \ operator==(std::default_sentinel_t s,\n                                    \
    \     const iterator& li) {\n          return li == s;\n        }\n      };\n\n\
    \      int count;\n\n    public:\n      constexpr explicit istream_view(int count)\
    \ : count(count) {}\n      constexpr explicit istream_view() : istream_view(_inf)\
    \ {}\n      constexpr auto begin() const { return iterator(count); }\n      constexpr\
    \ auto end() const { return std::default_sentinel; }\n    };\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_istream_view = requires {\n        ranges::istream_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    template <class... Args>\n    struct\
    \ _Istream {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
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
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  isVerificationFile: true
  path: Test/Math/Convolution_and.test.cpp
  requiredBy: []
  timestamp: '2024-11-19 06:52:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Math/Convolution_and.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/Convolution_and.test.cpp
- /verify/Test/Math/Convolution_and.test.cpp.html
title: Test/Math/Convolution_and.test.cpp
---