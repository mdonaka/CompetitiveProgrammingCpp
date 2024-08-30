---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algorithms/EuclideanAlgorithm.hpp
    title: Library/Algorithms/EuclideanAlgorithm.hpp
  - icon: ':question:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':question:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1009
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1009
  bundledCode: "#line 1 \"Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1009\"\n\
    \n// tag:includes begin\n#line 2 \"Library/Range/istream.hpp\"\n\n#include <ranges>\n\
    \n#line 2 \"Library/Utility/io.hpp\"\n\n#include <iostream>\n#line 5 \"Library/Utility/io.hpp\"\
    \n#include <type_traits>\n#include <vector>\n\nnamespace mtd {\n  namespace io\
    \ {\n\n    namespace type {\n      template <class T, int Pre = 1, int Size =\
    \ 0>\n      struct vec {\n        using value_type = T;\n        static constexpr\
    \ int pre = Pre;\n        static constexpr int size = Size;\n      };\n      template\
    \ <class T>\n      concept is_vec = requires {\n        std::is_same_v<T, vec<typename\
    \ T::value_type, T::pre, T::size>>;\n      };\n    }  // namespace type\n\n  \
    \  template <type::is_vec T>\n    auto _input(int n) {\n      std::vector<typename\
    \ T::value_type> v(n);\n      for (auto i : std::views::iota(0, n)) { std::cin\
    \ >> v[i]; }\n      return v;\n    }\n\n    template <class T>\n    auto _input()\
    \ {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n\n    template\
    \ <int N, class Tuple, class T, class... Args>\n    auto _tuple_input(Tuple& t)\
    \ {\n      if constexpr (type::is_vec<T>) {\n        if constexpr (T::size ==\
    \ 0) {\n          std::get<N>(t) = _input<T>(std::get<N - T::pre>(t));\n     \
    \   } else {\n          std::get<N>(t) = _input<T>(T::size);\n        }\n    \
    \  } else {\n        std::get<N>(t) = _input<T>();\n      }\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t);\n \
    \     }\n    }\n\n    template <class T>\n    struct _Converter {\n      using\
    \ type = T;\n    };\n    template <class T, int Pre, int Size>\n    struct _Converter<type::vec<T,\
    \ Pre, Size>> {\n      using type = std::vector<T>;\n    };\n\n    template <class...\
    \ Args>\n    auto in() {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base);\n      return base;\n \
    \   }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
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
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 2 \"Library/Algorithms/EuclideanAlgorithm.hpp\"\
    \n\r\n#line 4 \"Library/Algorithms/EuclideanAlgorithm.hpp\"\n#include <numeric>\r\
    \n#include <tuple>\r\n\r\nclass EuclideanAlgorithm {\r\n  using T = long long;\r\
    \n\r\n  // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u3066\u3057\u307E\u3046\r\n  const static inline T m_mx = 1e9;\r\n\
    \r\n  const T m_a;\r\n  const T m_b;\r\n  const T m_c;\r\n\r\n  T m_gcd;\r\n \
    \ T m_x;\r\n  T m_y;\r\n\r\n  auto excludedEuclidAlgorithm(T a, T b) -> std::tuple<T,\
    \ T, T> {\r\n    if (a < 0) {\r\n      auto [g, x, y] = excludedEuclidAlgorithm(-a,\
    \ -b);\r\n      return {g, -x, -y};\r\n    }\r\n    if (b == 0) { return {a, 1,\
    \ 0}; }\r\n    auto [g, y, x] = excludedEuclidAlgorithm(b, a % b);\r\n    y -=\
    \ a / b * x;\r\n    return {g, x, y};\r\n  }\r\n\r\n  auto kRange(T x, T b, T\
    \ l) const -> std::pair<T, T> {\r\n    // x + b * k >= l \u3092\u6E80\u305F\u3059\
    \ k \u306E\u7BC4\u56F2\u3092\u6C42\u3081\u308B\r\n    T xd = (l - x);\r\n    if\
    \ (b == 0 && x >= l) { return {-m_mx, m_mx}; }\r\n    if (b == 0 && x < l) { return\
    \ {m_mx, -m_mx}; }\r\n    if (b > 0 && xd < 0) { return {xd / b, m_mx}; }\r\n\
    \    if (b > 0 && xd >= 0) { return {(xd + b - 1) / b, m_mx}; }\r\n    if (b <\
    \ 0 && xd < 0) { return {-m_mx, (-xd) / (-b)}; }\r\n    if (b < 0 && xd >= 0)\
    \ { return {-m_mx, -(xd - b - 1) / (-b)}; }\r\n    return {m_mx, -m_mx};\r\n \
    \ }\r\n\r\npublic:\r\n  auto debug() const {\r\n    std::cout << m_a << \" * \"\
    \ << m_x << \" + \" << m_b << \" * \" << m_y << \" = \"\r\n              << m_c\
    \ << std::endl;\r\n    std::cout << \"calc: \" << m_a * m_x + m_b * m_y << \"\
    \ = \" << m_c << std::endl;\r\n  }\r\n\r\n  EuclideanAlgorithm(T a, T b, T c)\
    \ : m_a(a), m_b(b), m_c(c) {\r\n    if (a == 0 && b == 0) { throw std::runtime_error(\"\
    \"); }\r\n    auto [g, x, y] = excludedEuclidAlgorithm(a, b);\r\n    if (c % g\
    \ > 0) {\r\n      throw std::runtime_error(\r\n          \"There is no solution\
    \ to the equation. c must be divisible by \"\r\n          \"gcd(a,b).\");\r\n\
    \    }\r\n    m_gcd = g;\r\n    m_x = c / g * x;\r\n    m_y = c / g * y;\r\n \
    \ }\r\n  EuclideanAlgorithm(T a, T b) : EuclideanAlgorithm(a, b, std::gcd(a, b))\
    \ {}\r\n\r\n  auto gcd() const { return m_gcd; }\r\n  auto get(T x, T y) const\
    \ { return m_a * x + m_b * y; }\r\n  auto get(T k) const -> std::pair<T, T> {\r\
    \n    if (m_b == 0) { return {m_x, m_y - k}; }\r\n    if (m_a == 0) { return {m_x\
    \ + k, m_y}; }\r\n    return {m_x + m_b * k, m_y - m_a * k};\r\n  }\r\n  auto\
    \ getMinX(T x_l = 0) const -> std::pair<T, T> {\r\n    return kRange(m_x, m_b,\
    \ x_l);\r\n  }\r\n  auto getMinY(T y_l = 0) const -> std::pair<T, T> {\r\n   \
    \ return kRange(m_y, -1 * m_a, y_l);\r\n  }\r\n  auto getMin(T x_l = 0, T y_l\
    \ = 0) const -> std::pair<T, T> {\r\n    auto [xl, xr] = getMinX(x_l);\r\n   \
    \ auto [yl, yr] = getMinY(y_l);\r\n    return {std::max(xl, yl), std::min(xr,\
    \ yr)};\r\n  }\r\n};\r\n#line 6 \"Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp\"\
    \n// tag:includes end\n\n#line 9 \"Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp\"\
    \n\nsigned main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n  for\
    \ (auto [x, y] : mtd::views::istream<int, int>()) {\n    auto ea = EuclideanAlgorithm(x,\
    \ y);\n    std::cout << ea.gcd() << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1009\"\
    \n\n// tag:includes begin\n#include \"../../Library/Range/istream.hpp\"\n#include\
    \ \"./../../Library/Algorithms/EuclideanAlgorithm.hpp\"\n// tag:includes end\n\
    \n#include <iostream>\n\nsigned main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \  for (auto [x, y] : mtd::views::istream<int, int>()) {\n    auto ea = EuclideanAlgorithm(x,\
    \ y);\n    std::cout << ea.gcd() << std::endl;\n  }\n}\n"
  dependsOn:
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Algorithms/EuclideanAlgorithm.hpp
  isVerificationFile: true
  path: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
  requiredBy: []
  timestamp: '2024-08-30 15:28:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
- /verify/Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp.html
title: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
---
