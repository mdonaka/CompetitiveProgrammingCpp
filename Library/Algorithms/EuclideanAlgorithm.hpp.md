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
  bundledCode: "#line 2 \"Library/Algorithms/EuclideanAlgorithm.hpp\"\n\r\n#include\
    \ <iostream>\r\n\r\nclass EuclideanAlgorithm {\r\n    using T = long long;\r\n\
    \r\n    const T m_a;\r\n    const T m_b;\r\n    const T m_mx; // \u5927\u304D\u3059\
    \u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u3066\u3057\
    \u307E\u3046\r\n\r\n    T m_gcd;\r\n    T m_x;\r\n    T m_y;\r\n\r\n    auto excludedEuclidAlgorithm(T\
    \ a, T b) -> std::tuple<T, T, T> {\r\n        if(a < 0) {\r\n            auto\
    \ [g, x, y] = excludedEuclidAlgorithm(-a, -b);\r\n            return {g,-x,-y};\r\
    \n        }\r\n        if(b == 0) { return {a, 1, 0}; }\r\n        auto [g, y,\
    \ x] = excludedEuclidAlgorithm(b, a % b);\r\n        y -= a / b * x;\r\n     \
    \   return {g, x, y};\r\n    }\r\n\r\n    auto kRange(T x, T b, T l) const ->\
    \ std::tuple<T, T> {\r\n        // x + b * k >= l \u3092\u6E80\u305F\u3059 k \u306E\
    \u7BC4\u56F2\u3092\u6C42\u3081\u308B\r\n        T xd = (l - x);\r\n        if(b\
    \ == 0 && x >= l) { return {-m_mx,m_mx}; }\r\n        if(b == 0 && x < l) { return\
    \ {m_mx,-m_mx}; }\r\n        if(b > 0 && xd < 0) { return {xd / b,m_mx}; }\r\n\
    \        if(b > 0 && xd >= 0) { return {(xd + b - 1) / b,m_mx}; }\r\n        if(b\
    \ < 0 && xd < 0) { return {-m_mx,(-xd) / (-b)}; }\r\n        if(b < 0 && xd >=\
    \ 0) { return {-m_mx,-(xd - b - 1) / (-b)}; }\r\n        return {m_mx,-m_mx};\r\
    \n    }\r\n\r\npublic:\r\n    auto debug()const {\r\n        std::cout << m_a\
    \ << \" * \" << m_x\r\n            << \" + \" << m_b << \" * \" << m_y\r\n   \
    \         << \" = \" << m_gcd << std::endl;\r\n        std::cout << m_a * m_x\
    \ + m_b * m_y\r\n            << \" = \" << m_gcd << std::endl;\r\n    }\r\n\r\n\
    \    EuclideanAlgorithm(T a, T b, T mx = 1e9) :m_a(a), m_b(b), m_mx(mx) {\r\n\
    \        if(a == 0 && b == 0) { throw std::runtime_error(\"\"); }\r\n        auto\
    \ [g, x, y] = excludedEuclidAlgorithm(a, b);\r\n        m_gcd = g; m_x = x; m_y\
    \ = y;\r\n    }\r\n\r\n    auto gcd() const {\r\n        return m_gcd;\r\n   \
    \ }\r\n    auto get(T x, T y) const {\r\n        return m_a * x + m_b * y;\r\n\
    \    }\r\n    auto get(T k) const ->std::tuple<T, T> {\r\n        if(m_b == 0)\
    \ { return {m_x,m_y - k}; }\r\n        if(m_a == 0) { return {m_x + k,m_y}; }\r\
    \n        return {m_x + m_b * k, m_y - m_a * k};\r\n    }\r\n    auto getMinX(T\
    \ x_l = 0)const -> std::tuple<T, T> {\r\n        return kRange(m_x, m_b, x_l);\r\
    \n    }\r\n    auto getMinY(T y_l = 0)const -> std::tuple<T, T> {\r\n        return\
    \ kRange(m_y, -1 * m_a, y_l);\r\n    }\r\n    auto getMin(T x_l = 0, T y_l = 0)const\
    \ -> std::tuple<T, T> {\r\n        auto [xl, xr] = getMinX(x_l);\r\n        auto\
    \ [yl, yr] = getMinY(y_l);\r\n        return {std::max(xl,yl),std::min(xr,yr)};\r\
    \n    }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <iostream>\r\n\r\nclass EuclideanAlgorithm {\r\
    \n    using T = long long;\r\n\r\n    const T m_a;\r\n    const T m_b;\r\n   \
    \ const T m_mx; // \u5927\u304D\u3059\u304E\u308B\u3068\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u3066\u3057\u307E\u3046\r\n\r\n    T m_gcd;\r\n    T\
    \ m_x;\r\n    T m_y;\r\n\r\n    auto excludedEuclidAlgorithm(T a, T b) -> std::tuple<T,\
    \ T, T> {\r\n        if(a < 0) {\r\n            auto [g, x, y] = excludedEuclidAlgorithm(-a,\
    \ -b);\r\n            return {g,-x,-y};\r\n        }\r\n        if(b == 0) { return\
    \ {a, 1, 0}; }\r\n        auto [g, y, x] = excludedEuclidAlgorithm(b, a % b);\r\
    \n        y -= a / b * x;\r\n        return {g, x, y};\r\n    }\r\n\r\n    auto\
    \ kRange(T x, T b, T l) const -> std::tuple<T, T> {\r\n        // x + b * k >=\
    \ l \u3092\u6E80\u305F\u3059 k \u306E\u7BC4\u56F2\u3092\u6C42\u3081\u308B\r\n\
    \        T xd = (l - x);\r\n        if(b == 0 && x >= l) { return {-m_mx,m_mx};\
    \ }\r\n        if(b == 0 && x < l) { return {m_mx,-m_mx}; }\r\n        if(b >\
    \ 0 && xd < 0) { return {xd / b,m_mx}; }\r\n        if(b > 0 && xd >= 0) { return\
    \ {(xd + b - 1) / b,m_mx}; }\r\n        if(b < 0 && xd < 0) { return {-m_mx,(-xd)\
    \ / (-b)}; }\r\n        if(b < 0 && xd >= 0) { return {-m_mx,-(xd - b - 1) / (-b)};\
    \ }\r\n        return {m_mx,-m_mx};\r\n    }\r\n\r\npublic:\r\n    auto debug()const\
    \ {\r\n        std::cout << m_a << \" * \" << m_x\r\n            << \" + \" <<\
    \ m_b << \" * \" << m_y\r\n            << \" = \" << m_gcd << std::endl;\r\n \
    \       std::cout << m_a * m_x + m_b * m_y\r\n            << \" = \" << m_gcd\
    \ << std::endl;\r\n    }\r\n\r\n    EuclideanAlgorithm(T a, T b, T mx = 1e9) :m_a(a),\
    \ m_b(b), m_mx(mx) {\r\n        if(a == 0 && b == 0) { throw std::runtime_error(\"\
    \"); }\r\n        auto [g, x, y] = excludedEuclidAlgorithm(a, b);\r\n        m_gcd\
    \ = g; m_x = x; m_y = y;\r\n    }\r\n\r\n    auto gcd() const {\r\n        return\
    \ m_gcd;\r\n    }\r\n    auto get(T x, T y) const {\r\n        return m_a * x\
    \ + m_b * y;\r\n    }\r\n    auto get(T k) const ->std::tuple<T, T> {\r\n    \
    \    if(m_b == 0) { return {m_x,m_y - k}; }\r\n        if(m_a == 0) { return {m_x\
    \ + k,m_y}; }\r\n        return {m_x + m_b * k, m_y - m_a * k};\r\n    }\r\n \
    \   auto getMinX(T x_l = 0)const -> std::tuple<T, T> {\r\n        return kRange(m_x,\
    \ m_b, x_l);\r\n    }\r\n    auto getMinY(T y_l = 0)const -> std::tuple<T, T>\
    \ {\r\n        return kRange(m_y, -1 * m_a, y_l);\r\n    }\r\n    auto getMin(T\
    \ x_l = 0, T y_l = 0)const -> std::tuple<T, T> {\r\n        auto [xl, xr] = getMinX(x_l);\r\
    \n        auto [yl, yr] = getMinY(y_l);\r\n        return {std::max(xl,yl),std::min(xr,yr)};\r\
    \n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/EuclideanAlgorithm.hpp
  requiredBy: []
  timestamp: '2022-08-30 04:52:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Algorithms/EuclideanAlgorithm.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/EuclideanAlgorithm.hpp
- /library/Library/Algorithms/EuclideanAlgorithm.hpp.html
title: Library/Algorithms/EuclideanAlgorithm.hpp
---
