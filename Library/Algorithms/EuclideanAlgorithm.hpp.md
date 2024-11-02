---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/EuclideanAlgorithm.test.cpp
    title: Test/Algorithms/EuclideanAlgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
    title: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algorithms/EuclideanAlgorithm.hpp\"\n\r\n#include\
    \ <iostream>\r\n#include <numeric>\r\n#include <tuple>\r\n\r\nclass EuclideanAlgorithm\
    \ {\r\n  using T = long long;\r\n\r\n  // \u5927\u304D\u3059\u304E\u308B\u3068\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u3066\u3057\u307E\u3046\r\n \
    \ const static inline T m_mx = 1e9;\r\n\r\n  const T m_a;\r\n  const T m_b;\r\n\
    \  const T m_c;\r\n\r\n  T m_gcd;\r\n  T m_x;\r\n  T m_y;\r\n\r\n  auto excludedEuclidAlgorithm(T\
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
    \ yr)};\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <iostream>\r\n#include <numeric>\r\n#include\
    \ <tuple>\r\n\r\nclass EuclideanAlgorithm {\r\n  using T = long long;\r\n\r\n\
    \  // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
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
    \ yr)};\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/EuclideanAlgorithm.hpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Algorithms/EuclideanAlgorithm.test.cpp
  - Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
documentation_of: Library/Algorithms/EuclideanAlgorithm.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/EuclideanAlgorithm.hpp
- /library/Library/Algorithms/EuclideanAlgorithm.hpp.html
title: Library/Algorithms/EuclideanAlgorithm.hpp
---
