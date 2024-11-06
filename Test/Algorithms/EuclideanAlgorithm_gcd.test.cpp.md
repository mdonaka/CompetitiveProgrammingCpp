---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/EuclideanAlgorithm.hpp
    title: Library/Algorithms/EuclideanAlgorithm.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/415\"\n\n// begin:tag includes\n\
    #line 2 \"Library/Algorithms/EuclideanAlgorithm.hpp\"\n\r\n#include <iostream>\r\
    \n#include <numeric>\r\n#include <tuple>\r\n\r\nclass EuclideanAlgorithm {\r\n\
    \  using T = long long;\r\n\r\n  // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u3066\u3057\u307E\u3046\r\n  const\
    \ static inline T m_mx = 1e9;\r\n\r\n  const T m_a;\r\n  const T m_b;\r\n  const\
    \ T m_c;\r\n\r\n  T m_gcd;\r\n  T m_x;\r\n  T m_y;\r\n\r\n  auto excludedEuclidAlgorithm(T\
    \ a, T b) -> std::tuple<T, T, T> {\r\n    if (a < 0) {\r\n      auto [g, x, y]\
    \ = excludedEuclidAlgorithm(-a, -b);\r\n      return {g, -x, -y};\r\n    }\r\n\
    \    if (b == 0) { return {a, 1, 0}; }\r\n    auto [g, y, x] = excludedEuclidAlgorithm(b,\
    \ a % b);\r\n    y -= a / b * x;\r\n    return {g, x, y};\r\n  }\r\n\r\n  auto\
    \ kRange(T x, T b, T l) const -> std::pair<T, T> {\r\n    // x + b * k >= l \u3092\
    \u6E80\u305F\u3059 k \u306E\u7BC4\u56F2\u3092\u6C42\u3081\u308B\r\n    T xd =\
    \ (l - x);\r\n    if (b == 0 && x >= l) { return {-m_mx, m_mx}; }\r\n    if (b\
    \ == 0 && x < l) { return {m_mx, -m_mx}; }\r\n    if (b > 0 && xd < 0) { return\
    \ {xd / b, m_mx}; }\r\n    if (b > 0 && xd >= 0) { return {(xd + b - 1) / b, m_mx};\
    \ }\r\n    if (b < 0 && xd < 0) { return {-m_mx, (-xd) / (-b)}; }\r\n    if (b\
    \ < 0 && xd >= 0) { return {-m_mx, -(xd - b - 1) / (-b)}; }\r\n    return {m_mx,\
    \ -m_mx};\r\n  }\r\n\r\npublic:\r\n  auto debug() const {\r\n    std::cout <<\
    \ m_a << \" * \" << m_x << \" + \" << m_b << \" * \" << m_y << \" = \"\r\n   \
    \           << m_c << std::endl;\r\n    std::cout << \"calc: \" << m_a * m_x +\
    \ m_b * m_y << \" = \" << m_c << std::endl;\r\n  }\r\n\r\n  EuclideanAlgorithm(T\
    \ a, T b, T c) : m_a(a), m_b(b), m_c(c) {\r\n    if (a == 0 && b == 0) { throw\
    \ std::runtime_error(\"\"); }\r\n    auto [g, x, y] = excludedEuclidAlgorithm(a,\
    \ b);\r\n    if (c % g > 0) {\r\n      throw std::runtime_error(\r\n         \
    \ \"There is no solution to the equation. c must be divisible by \"\r\n      \
    \    \"gcd(a,b).\");\r\n    }\r\n    m_gcd = g;\r\n    m_x = c / g * x;\r\n  \
    \  m_y = c / g * y;\r\n  }\r\n  EuclideanAlgorithm(T a, T b) : EuclideanAlgorithm(a,\
    \ b, std::gcd(a, b)) {}\r\n\r\n  auto gcd() const { return m_gcd; }\r\n  auto\
    \ get(T x, T y) const { return m_a * x + m_b * y; }\r\n  auto get(T k) const ->\
    \ std::pair<T, T> {\r\n    if (m_b == 0) { return {m_x, m_y - k}; }\r\n    if\
    \ (m_a == 0) { return {m_x + k, m_y}; }\r\n    return {m_x + m_b * k, m_y - m_a\
    \ * k};\r\n  }\r\n  auto getMinX(T x_l = 0) const -> std::pair<T, T> {\r\n   \
    \ return kRange(m_x, m_b, x_l);\r\n  }\r\n  auto getMinY(T y_l = 0) const -> std::pair<T,\
    \ T> {\r\n    return kRange(m_y, -1 * m_a, y_l);\r\n  }\r\n  auto getMin(T x_l\
    \ = 0, T y_l = 0) const -> std::pair<T, T> {\r\n    auto [xl, xr] = getMinX(x_l);\r\
    \n    auto [yl, yr] = getMinY(y_l);\r\n    return {std::max(xl, yl), std::min(xr,\
    \ yr)};\r\n  }\r\n};\r\n#line 2 \"Library/Utility/io.hpp\"\n\n#line 4 \"Library/Utility/io.hpp\"\
    \n#include <ranges>\n#include <type_traits>\n#include <vector>\n\nnamespace mtd\
    \ {\n  namespace io {\n\n    namespace type {\n      template <class T, int Pre\
    \ = 1, int Size = 0>\n      struct vec {\n        using value_type = T;\n    \
    \    static constexpr int pre = Pre;\n        static constexpr int size = Size;\n\
    \      };\n      template <class T>\n      concept is_vec = requires {\n     \
    \   std::is_same_v<T, vec<typename T::value_type, T::pre, T::size>>;\n      };\n\
    \    }  // namespace type\n\n    template <type::is_vec T>\n    auto _input(int\
    \ n) {\n      std::vector<typename T::value_type> v(n);\n      for (auto i : std::views::iota(0,\
    \ n)) { std::cin >> v[i]; }\n      return v;\n    }\n\n    template <class T>\n\
    \    auto _input() {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n\
    \n    template <int N, class Tuple, class T, class... Args>\n    auto _tuple_input(Tuple&\
    \ t) {\n      if constexpr (type::is_vec<T>) {\n        if constexpr (T::size\
    \ == 0) {\n          std::get<N>(t) = _input<T>(std::get<N - T::pre>(t));\n  \
    \      } else {\n          std::get<N>(t) = _input<T>(T::size);\n        }\n \
    \     } else {\n        std::get<N>(t) = _input<T>();\n      }\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t);\n \
    \     }\n    }\n\n    template <class T>\n    struct _Converter {\n      using\
    \ type = T;\n    };\n    template <class T, int Pre, int Size>\n    struct _Converter<type::vec<T,\
    \ Pre, Size>> {\n      using type = std::vector<T>;\n    };\n\n    template <class...\
    \ Args>\n    auto in() {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base);\n      return base;\n \
    \   }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp\"\
    \n// end:tag includes\n\n#line 9 \"Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp\"\
    \n\nsigned main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n \
    \ auto [n, d] = mtd::io::in<int, int>();\n  auto ea = EuclideanAlgorithm(n, d);\n\
    \  std::cout << n / ea.gcd() - 1 << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/415\"\n\n// begin:tag\
    \ includes\n#include \"../../Library/Algorithms/EuclideanAlgorithm.hpp\"\n#include\
    \ \"../../Library/Utility/io.hpp\"\n// end:tag includes\n\n#include <iostream>\n\
    \nsigned main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  auto\
    \ [n, d] = mtd::io::in<int, int>();\n  auto ea = EuclideanAlgorithm(n, d);\n \
    \ std::cout << n / ea.gcd() - 1 << std::endl;\n}\n"
  dependsOn:
  - Library/Algorithms/EuclideanAlgorithm.hpp
  - Library/Utility/io.hpp
  isVerificationFile: true
  path: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
  requiredBy: []
  timestamp: '2024-08-30 15:44:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
- /verify/Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp.html
title: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
---
