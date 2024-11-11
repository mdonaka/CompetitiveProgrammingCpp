---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/PlaneGeometry/ConvexHull.test.cpp
    title: Test/PlaneGeometry/ConvexHull.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/PlaneGeometry/ConvexHull.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <cmath>\r\n#include <complex>\r\n#include <stack>\r\n#include <vector>\r\
    \n\r\nnamespace mtd {\r\n  class ConvexHull {\r\n    using Point = std::complex<long\
    \ double>;\r\n    const static inline long double pi = std::acos(-1);\r\n\r\n\
    \    static inline auto arg(const Point& p) {\r\n      auto a = std::arg(p);\r\
    \n      return ((a < 0.0) ? a + 2 * pi : a);\r\n    }\r\n\r\n  public:\r\n   \
    \ static auto grahamScan(const std::vector<Point>& points) {\r\n      auto ps\
    \ = points;\r\n      auto mn = ps[0];\r\n      for (const auto& p : ps)\r\n  \
    \      if (p.imag() < mn.imag()) { mn = p; }\r\n\r\n      std::sort(ps.begin(),\
    \ ps.end(), [&](const Point& a, const Point& b) {\r\n        auto arg_a = arg(a\
    \ - mn);\r\n        auto arg_b = arg(b - mn);\r\n        if (std::abs(arg_a -\
    \ arg_b) < 1e-9) {\r\n          return std::abs(a - mn) < std::abs(b - mn);\r\n\
    \        }\r\n        return arg_a < arg_b;\r\n      });\r\n\r\n      auto cf\
    \ = std::stack<Point>();\r\n      for (const auto& p : ps)\r\n        while (true)\
    \ {\r\n          if (cf.size() < 2) {\r\n            cf.emplace(p);\r\n      \
    \      break;\r\n          }\r\n          auto p1 = cf.top();\r\n          cf.pop();\r\
    \n          auto p2 = cf.top();\r\n          auto arg1 = arg(p1 - p2);\r\n   \
    \       auto arg2 = arg(p - p2);\r\n          if (arg1 < arg2 || std::abs(arg1\
    \ - arg2) < 1e-9) {\r\n            cf.emplace(p1);\r\n            cf.emplace(p);\r\
    \n            break;\r\n          }\r\n        }\r\n\r\n      auto arg_mx = arg(cf.top()\
    \ - mn);\r\n      std::stack<Point> line;\r\n      for (const auto& p : ps) {\r\
    \n        auto arg_l = arg(p - mn);\r\n        if (std::abs(arg_mx - arg_l) <\
    \ 1e-9) { line.emplace(p); }\r\n      }\r\n      cf.pop();\r\n      while (!line.empty())\
    \ {\r\n        cf.emplace(line.top());\r\n        line.pop();\r\n      }\r\n\r\
    \n      auto rev = decltype(ps)();\r\n      rev.reserve(cf.size());\r\n      while\
    \ (!cf.empty()) {\r\n        rev.emplace_back(cf.top());\r\n        cf.pop();\r\
    \n      }\r\n      std::reverse(rev.begin(), rev.end());\r\n      return rev;\r\
    \n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <cmath>\r\n#include\
    \ <complex>\r\n#include <stack>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n\
    \  class ConvexHull {\r\n    using Point = std::complex<long double>;\r\n    const\
    \ static inline long double pi = std::acos(-1);\r\n\r\n    static inline auto\
    \ arg(const Point& p) {\r\n      auto a = std::arg(p);\r\n      return ((a < 0.0)\
    \ ? a + 2 * pi : a);\r\n    }\r\n\r\n  public:\r\n    static auto grahamScan(const\
    \ std::vector<Point>& points) {\r\n      auto ps = points;\r\n      auto mn =\
    \ ps[0];\r\n      for (const auto& p : ps)\r\n        if (p.imag() < mn.imag())\
    \ { mn = p; }\r\n\r\n      std::sort(ps.begin(), ps.end(), [&](const Point& a,\
    \ const Point& b) {\r\n        auto arg_a = arg(a - mn);\r\n        auto arg_b\
    \ = arg(b - mn);\r\n        if (std::abs(arg_a - arg_b) < 1e-9) {\r\n        \
    \  return std::abs(a - mn) < std::abs(b - mn);\r\n        }\r\n        return\
    \ arg_a < arg_b;\r\n      });\r\n\r\n      auto cf = std::stack<Point>();\r\n\
    \      for (const auto& p : ps)\r\n        while (true) {\r\n          if (cf.size()\
    \ < 2) {\r\n            cf.emplace(p);\r\n            break;\r\n          }\r\n\
    \          auto p1 = cf.top();\r\n          cf.pop();\r\n          auto p2 = cf.top();\r\
    \n          auto arg1 = arg(p1 - p2);\r\n          auto arg2 = arg(p - p2);\r\n\
    \          if (arg1 < arg2 || std::abs(arg1 - arg2) < 1e-9) {\r\n            cf.emplace(p1);\r\
    \n            cf.emplace(p);\r\n            break;\r\n          }\r\n        }\r\
    \n\r\n      auto arg_mx = arg(cf.top() - mn);\r\n      std::stack<Point> line;\r\
    \n      for (const auto& p : ps) {\r\n        auto arg_l = arg(p - mn);\r\n  \
    \      if (std::abs(arg_mx - arg_l) < 1e-9) { line.emplace(p); }\r\n      }\r\n\
    \      cf.pop();\r\n      while (!line.empty()) {\r\n        cf.emplace(line.top());\r\
    \n        line.pop();\r\n      }\r\n\r\n      auto rev = decltype(ps)();\r\n \
    \     rev.reserve(cf.size());\r\n      while (!cf.empty()) {\r\n        rev.emplace_back(cf.top());\r\
    \n        cf.pop();\r\n      }\r\n      std::reverse(rev.begin(), rev.end());\r\
    \n      return rev;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/PlaneGeometry/ConvexHull.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/PlaneGeometry/ConvexHull.test.cpp
documentation_of: Library/PlaneGeometry/ConvexHull.hpp
layout: document
redirect_from:
- /library/Library/PlaneGeometry/ConvexHull.hpp
- /library/Library/PlaneGeometry/ConvexHull.hpp.html
title: Library/PlaneGeometry/ConvexHull.hpp
---
