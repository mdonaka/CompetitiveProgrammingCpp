---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/PlaneGeometry/ConvexHull.hpp
    title: Library/PlaneGeometry/ConvexHull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A
  bundledCode: "#line 1 \"Test/PlaneGeometry/ConvexHull.test.cpp\"\n#define PROBLEM\
    \ \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A\"\
    \r\n\r\n#line 2 \"Library/PlaneGeometry/ConvexHull.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <cmath>\r\n#include <complex>\r\n#include <stack>\r\n#include <vector>\r\
    \n\r\nclass ConvexHull {\r\n  using Point = std::complex<long double>;\r\n  const\
    \ static inline long double pi = std::acos(-1);\r\n\r\n  static inline auto arg(const\
    \ Point& p) {\r\n    auto a = std::arg(p);\r\n    return ((a < 0.0) ? a + 2 *\
    \ pi : a);\r\n  }\r\n\r\npublic:\r\n  static auto grahamScan(const std::vector<Point>&\
    \ points) {\r\n    auto ps = points;\r\n    auto mn = ps[0];\r\n    for (const\
    \ auto& p : ps)\r\n      if (p.imag() < mn.imag()) { mn = p; }\r\n\r\n    std::sort(ps.begin(),\
    \ ps.end(), [&](const Point& a, const Point& b) {\r\n      auto arg_a = arg(a\
    \ - mn);\r\n      auto arg_b = arg(b - mn);\r\n      if (std::abs(arg_a - arg_b)\
    \ < 1e-9) {\r\n        return std::abs(a - mn) < std::abs(b - mn);\r\n      }\r\
    \n      return arg_a < arg_b;\r\n    });\r\n\r\n    auto cf = std::stack<Point>();\r\
    \n    for (const auto& p : ps)\r\n      while (true) {\r\n        if (cf.size()\
    \ < 2) {\r\n          cf.emplace(p);\r\n          break;\r\n        }\r\n    \
    \    auto p1 = cf.top();\r\n        cf.pop();\r\n        auto p2 = cf.top();\r\
    \n        auto arg1 = arg(p1 - p2);\r\n        auto arg2 = arg(p - p2);\r\n  \
    \      if (arg1 < arg2 || std::abs(arg1 - arg2) < 1e-9) {\r\n          cf.emplace(p1);\r\
    \n          cf.emplace(p);\r\n          break;\r\n        }\r\n      }\r\n\r\n\
    \    auto arg_mx = arg(cf.top() - mn);\r\n    std::stack<Point> line;\r\n    for\
    \ (const auto& p : ps) {\r\n      auto arg_l = arg(p - mn);\r\n      if (std::abs(arg_mx\
    \ - arg_l) < 1e-9) { line.emplace(p); }\r\n    }\r\n    cf.pop();\r\n    while\
    \ (!line.empty()) {\r\n      cf.emplace(line.top());\r\n      line.pop();\r\n\
    \    }\r\n\r\n    auto rev = decltype(ps)();\r\n    rev.reserve(cf.size());\r\n\
    \    while (!cf.empty()) {\r\n      rev.emplace_back(cf.top());\r\n      cf.pop();\r\
    \n    }\r\n    std::reverse(rev.begin(), rev.end());\r\n    return rev;\r\n  }\r\
    \n};\n#line 5 \"Test/PlaneGeometry/ConvexHull.test.cpp\"\n\r\n#include <iostream>\r\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n;\r\n  cin >> n;\r\n  std::vector<std::complex<long\
    \ double>> points;\r\n  points.reserve(n);\r\n  for (int _ = 0; _ < n; ++_) {\r\
    \n    int x, y;\r\n    cin >> x >> y;\r\n    points.emplace_back(x, y);\r\n  }\r\
    \n\r\n  auto cf = ConvexHull::grahamScan(points);\r\n  int size = cf.size();\r\
    \n\r\n  int idx = 0;\r\n  for (int i = 1; i < size; ++i) {\r\n    if (cf[i].imag()\
    \ < cf[idx].imag()) {\r\n      idx = i;\r\n      continue;\r\n    }\r\n    if\
    \ (cf[i].imag() < cf[idx].imag() && cf[i].real() < cf[idx].real()) {\r\n     \
    \ idx = i;\r\n      continue;\r\n    }\r\n  }\r\n\r\n  cout << cf.size() << endl;\r\
    \n  for (int i = 0; i < size; ++i) {\r\n    auto p = cf[(i + idx) % size];\r\n\
    \    cout << p.real() << \" \" << p.imag() << endl;\r\n  }\r\n}\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A\"\
    \r\n\r\n#include \"./../../Library/PlaneGeometry/ConvexHull.hpp\"\r\n\r\n#include\
    \ <iostream>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\
    \nconstexpr char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n;\r\n  cin >>\
    \ n;\r\n  std::vector<std::complex<long double>> points;\r\n  points.reserve(n);\r\
    \n  for (int _ = 0; _ < n; ++_) {\r\n    int x, y;\r\n    cin >> x >> y;\r\n \
    \   points.emplace_back(x, y);\r\n  }\r\n\r\n  auto cf = ConvexHull::grahamScan(points);\r\
    \n  int size = cf.size();\r\n\r\n  int idx = 0;\r\n  for (int i = 1; i < size;\
    \ ++i) {\r\n    if (cf[i].imag() < cf[idx].imag()) {\r\n      idx = i;\r\n   \
    \   continue;\r\n    }\r\n    if (cf[i].imag() < cf[idx].imag() && cf[i].real()\
    \ < cf[idx].real()) {\r\n      idx = i;\r\n      continue;\r\n    }\r\n  }\r\n\
    \r\n  cout << cf.size() << endl;\r\n  for (int i = 0; i < size; ++i) {\r\n   \
    \ auto p = cf[(i + idx) % size];\r\n    cout << p.real() << \" \" << p.imag()\
    \ << endl;\r\n  }\r\n}"
  dependsOn:
  - Library/PlaneGeometry/ConvexHull.hpp
  isVerificationFile: true
  path: Test/PlaneGeometry/ConvexHull.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PlaneGeometry/ConvexHull.test.cpp
layout: document
redirect_from:
- /verify/Test/PlaneGeometry/ConvexHull.test.cpp
- /verify/Test/PlaneGeometry/ConvexHull.test.cpp.html
title: Test/PlaneGeometry/ConvexHull.test.cpp
---
