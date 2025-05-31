---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Math/EuclideanAlgorithm.hpp
    title: Library/Math/EuclideanAlgorithm.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/415
    links:
    - https://yukicoder.me/problems/no/415
  bundledCode: "#line 1 \"Test/Math/EuclideanAlgorithm_gcd.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/415\"\n\n// begin:tag includes\n#line 2 \"\
    Library/Math/EuclideanAlgorithm.hpp\"\n\r\n#include <iostream>\r\n#include <numeric>\r\
    \n#include <tuple>\r\n\r\nnamespace mtd {\r\n\r\n  class EuclideanAlgorithm {\r\
    \n    using T = long long;\r\n\r\n    // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u3066\u3057\u307E\u3046\r\n    const\
    \ static inline T m_mx = 1e9;\r\n\r\n    const T m_a;\r\n    const T m_b;\r\n\
    \    const T m_c;\r\n\r\n    T m_gcd;\r\n    T m_x;\r\n    T m_y;\r\n\r\n    auto\
    \ excludedEuclidAlgorithm(T a, T b) -> std::tuple<T, T, T> {\r\n      if (a <\
    \ 0) {\r\n        auto [g, x, y] = excludedEuclidAlgorithm(-a, -b);\r\n      \
    \  return {g, -x, -y};\r\n      }\r\n      if (b == 0) { return {a, 1, 0}; }\r\
    \n      auto [g, y, x] = excludedEuclidAlgorithm(b, a % b);\r\n      y -= a /\
    \ b * x;\r\n      return {g, x, y};\r\n    }\r\n\r\n    auto kRange(T x, T b,\
    \ T l) const -> std::pair<T, T> {\r\n      // x + b * k >= l \u3092\u6E80\u305F\
    \u3059 k \u306E\u7BC4\u56F2\u3092\u6C42\u3081\u308B\r\n      T xd = (l - x);\r\
    \n      if (b == 0 && x >= l) { return {-m_mx, m_mx}; }\r\n      if (b == 0 &&\
    \ x < l) { return {m_mx, -m_mx}; }\r\n      if (b > 0 && xd < 0) { return {xd\
    \ / b, m_mx}; }\r\n      if (b > 0 && xd >= 0) { return {(xd + b - 1) / b, m_mx};\
    \ }\r\n      if (b < 0 && xd < 0) { return {-m_mx, (-xd) / (-b)}; }\r\n      if\
    \ (b < 0 && xd >= 0) { return {-m_mx, -(xd - b - 1) / (-b)}; }\r\n      return\
    \ {m_mx, -m_mx};\r\n    }\r\n\r\n  public:\r\n    auto debug() const {\r\n   \
    \   std::cout << m_a << \" * \" << m_x << \" + \" << m_b << \" * \" << m_y <<\
    \ \" = \"\r\n                << m_c << std::endl;\r\n      std::cout << \"calc:\
    \ \" << m_a * m_x + m_b * m_y << \" = \" << m_c\r\n                << std::endl;\r\
    \n    }\r\n\r\n    EuclideanAlgorithm(T a, T b, T c) : m_a(a), m_b(b), m_c(c)\
    \ {\r\n      if (a == 0 && b == 0) { throw std::runtime_error(\"\"); }\r\n   \
    \   auto [g, x, y] = excludedEuclidAlgorithm(a, b);\r\n      if (c % g > 0) {\r\
    \n        throw std::runtime_error(\r\n            \"There is no solution to the\
    \ equation. c must be divisible by \"\r\n            \"gcd(a,b).\");\r\n     \
    \ }\r\n      m_gcd = g;\r\n      m_x = c / g * x;\r\n      m_y = c / g * y;\r\n\
    \    }\r\n    EuclideanAlgorithm(T a, T b) : EuclideanAlgorithm(a, b, std::gcd(a,\
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
    \ yr)};\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 2 \"Library/Utility/io.hpp\"\
    \n\n#line 4 \"Library/Utility/io.hpp\"\n#include <ranges>\n#include <type_traits>\n\
    #include <vector>\n\n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#include <functional>\n\
    \nnamespace mtd {\n  namespace util {\n    template <class F, class T>\n    constexpr\
    \ auto tuple_transform(F&& f, T&& t) {\n      return std::apply(\n          [&]<class...\
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
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Test/Math/EuclideanAlgorithm_gcd.test.cpp\"\
    \n// end:tag includes\n\n#line 9 \"Test/Math/EuclideanAlgorithm_gcd.test.cpp\"\
    \n\nsigned main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n \
    \ auto [n, d] = mtd::io::in<int, int>();\n  auto ea = mtd::EuclideanAlgorithm(n,\
    \ d);\n  std::cout << n / ea.gcd() - 1 << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/415\"\n\n// begin:tag\
    \ includes\n#include \"../../Library/Math/EuclideanAlgorithm.hpp\"\n#include \"\
    ../../Library/Utility/io.hpp\"\n// end:tag includes\n\n#include <iostream>\n\n\
    signed main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  auto\
    \ [n, d] = mtd::io::in<int, int>();\n  auto ea = mtd::EuclideanAlgorithm(n, d);\n\
    \  std::cout << n / ea.gcd() - 1 << std::endl;\n}\n"
  dependsOn:
  - Library/Math/EuclideanAlgorithm.hpp
  - Library/Utility/io.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: true
  path: Test/Math/EuclideanAlgorithm_gcd.test.cpp
  requiredBy: []
  timestamp: '2024-12-25 00:03:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Math/EuclideanAlgorithm_gcd.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/EuclideanAlgorithm_gcd.test.cpp
- /verify/Test/Math/EuclideanAlgorithm_gcd.test.cpp.html
title: Test/Math/EuclideanAlgorithm_gcd.test.cpp
---
