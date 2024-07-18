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
  bundledCode: "#line 2 \"Library/PlaneGeometry/ConvexHull.hpp\"\n\r\n#include <vector>\r\
    \n#include <stack>\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <complex>\r\
    \n\r\nclass ConvexHull {\r\n\tusing Point = std::complex<long double>;\r\n\tconst\
    \ static inline long double pi = std::acos(-1);\r\n\r\n\tstatic inline auto arg(const\
    \ Point& p) {\r\n\t\tauto a = std::arg(p);\r\n\t\treturn ((a < 0.0) ? a + 2 *\
    \ pi : a);\r\n\t}\r\npublic:\r\n\r\n\tstatic auto grahamScan(const std::vector<Point>&\
    \ points) {\r\n\t\tauto ps = points;\r\n\t\tauto mn = ps[0];\r\n\t\tfor (const\
    \ auto& p : ps)if (p.imag() < mn.imag()) { mn = p; }\r\n\r\n\t\tstd::sort(ps.begin(),\
    \ ps.end(), [&](const Point& a, const Point& b) {\r\n\t\t\tauto arg_a = arg(a\
    \ - mn);\r\n\t\t\tauto arg_b = arg(b - mn);\r\n\t\t\tif (std::abs(arg_a - arg_b)\
    \ < 1e-9) {\r\n\t\t\t\treturn std::abs(a - mn) < std::abs(b - mn);\r\n\t\t\t}\r\
    \n\t\t\treturn arg_a < arg_b;\r\n\t\t});\r\n\r\n\t\tauto cf = std::stack<Point>();\r\
    \n\t\tfor (const auto& p : ps) while (true) {\r\n\t\t\tif (cf.size() < 2) { cf.emplace(p);\
    \ break; }\r\n\t\t\tauto p1 = cf.top(); cf.pop();\r\n\t\t\tauto p2 = cf.top();\r\
    \n\t\t\tauto arg1 = arg(p1 - p2);\r\n\t\t\tauto arg2 = arg(p - p2);\r\n\t\t\t\
    if (arg1 < arg2 || std::abs(arg1 - arg2) < 1e-9) {\r\n\t\t\t\tcf.emplace(p1);\r\
    \n\t\t\t\tcf.emplace(p);\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tauto\
    \ arg_mx = arg(cf.top() - mn);\r\n\t\tstd::stack<Point> line;\r\n\t\tfor (const\
    \ auto& p : ps) {\r\n\t\t\tauto arg_l = arg(p - mn);\r\n\t\t\tif (std::abs(arg_mx\
    \ - arg_l) < 1e-9) {\r\n\t\t\t\tline.emplace(p);\r\n\t\t\t}\r\n\t\t}\r\n\t\tcf.pop();\r\
    \n\t\twhile (!line.empty()) { cf.emplace(line.top()); line.pop(); }\r\n\r\n\t\t\
    auto rev = decltype(ps)();\r\n\t\trev.reserve(cf.size());\r\n\t\twhile (!cf.empty())\
    \ {\r\n\t\t\trev.emplace_back(cf.top());\r\n\t\t\tcf.pop();\r\n\t\t}\r\n\t\tstd::reverse(rev.begin(),\
    \ rev.end());\r\n\t\treturn rev;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <stack>\r\n#include <algorithm>\r\
    \n#include <cmath>\r\n#include <complex>\r\n\r\nclass ConvexHull {\r\n\tusing\
    \ Point = std::complex<long double>;\r\n\tconst static inline long double pi =\
    \ std::acos(-1);\r\n\r\n\tstatic inline auto arg(const Point& p) {\r\n\t\tauto\
    \ a = std::arg(p);\r\n\t\treturn ((a < 0.0) ? a + 2 * pi : a);\r\n\t}\r\npublic:\r\
    \n\r\n\tstatic auto grahamScan(const std::vector<Point>& points) {\r\n\t\tauto\
    \ ps = points;\r\n\t\tauto mn = ps[0];\r\n\t\tfor (const auto& p : ps)if (p.imag()\
    \ < mn.imag()) { mn = p; }\r\n\r\n\t\tstd::sort(ps.begin(), ps.end(), [&](const\
    \ Point& a, const Point& b) {\r\n\t\t\tauto arg_a = arg(a - mn);\r\n\t\t\tauto\
    \ arg_b = arg(b - mn);\r\n\t\t\tif (std::abs(arg_a - arg_b) < 1e-9) {\r\n\t\t\t\
    \treturn std::abs(a - mn) < std::abs(b - mn);\r\n\t\t\t}\r\n\t\t\treturn arg_a\
    \ < arg_b;\r\n\t\t});\r\n\r\n\t\tauto cf = std::stack<Point>();\r\n\t\tfor (const\
    \ auto& p : ps) while (true) {\r\n\t\t\tif (cf.size() < 2) { cf.emplace(p); break;\
    \ }\r\n\t\t\tauto p1 = cf.top(); cf.pop();\r\n\t\t\tauto p2 = cf.top();\r\n\t\t\
    \tauto arg1 = arg(p1 - p2);\r\n\t\t\tauto arg2 = arg(p - p2);\r\n\t\t\tif (arg1\
    \ < arg2 || std::abs(arg1 - arg2) < 1e-9) {\r\n\t\t\t\tcf.emplace(p1);\r\n\t\t\
    \t\tcf.emplace(p);\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\r\n\t\tauto arg_mx\
    \ = arg(cf.top() - mn);\r\n\t\tstd::stack<Point> line;\r\n\t\tfor (const auto&\
    \ p : ps) {\r\n\t\t\tauto arg_l = arg(p - mn);\r\n\t\t\tif (std::abs(arg_mx -\
    \ arg_l) < 1e-9) {\r\n\t\t\t\tline.emplace(p);\r\n\t\t\t}\r\n\t\t}\r\n\t\tcf.pop();\r\
    \n\t\twhile (!line.empty()) { cf.emplace(line.top()); line.pop(); }\r\n\r\n\t\t\
    auto rev = decltype(ps)();\r\n\t\trev.reserve(cf.size());\r\n\t\twhile (!cf.empty())\
    \ {\r\n\t\t\trev.emplace_back(cf.top());\r\n\t\t\tcf.pop();\r\n\t\t}\r\n\t\tstd::reverse(rev.begin(),\
    \ rev.end());\r\n\t\treturn rev;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/PlaneGeometry/ConvexHull.hpp
  requiredBy: []
  timestamp: '2021-08-08 14:42:54+09:00'
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
