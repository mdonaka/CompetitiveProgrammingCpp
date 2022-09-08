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
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A\"\r\n\r\n\
    #include <iostream>\r\n#line 2 \"Library/PlaneGeometry/ConvexHull.hpp\"\n\r\n\
    #include <vector>\r\n#include <stack>\r\n#include <algorithm>\r\n#include <cmath>\r\
    \n#include <complex>\r\n\r\nclass ConvexHull {\r\n\tusing Point = std::complex<long\
    \ double>;\r\n\tconst static inline long double pi = std::acos(-1);\r\n\r\n\t\
    static inline auto arg(const Point& p) {\r\n\t\tauto a = std::arg(p);\r\n\t\t\
    return ((a < 0.0) ? a + 2 * pi : a);\r\n\t}\r\npublic:\r\n\r\n\tstatic auto grahamScan(const\
    \ std::vector<Point>& points) {\r\n\t\tauto ps = points;\r\n\t\tauto mn = ps[0];\r\
    \n\t\tfor (const auto& p : ps)if (p.imag() < mn.imag()) { mn = p; }\r\n\r\n\t\t\
    std::sort(ps.begin(), ps.end(), [&](const Point& a, const Point& b) {\r\n\t\t\t\
    auto arg_a = arg(a - mn);\r\n\t\t\tauto arg_b = arg(b - mn);\r\n\t\t\tif (std::abs(arg_a\
    \ - arg_b) < 1e-9) {\r\n\t\t\t\treturn std::abs(a - mn) < std::abs(b - mn);\r\n\
    \t\t\t}\r\n\t\t\treturn arg_a < arg_b;\r\n\t\t});\r\n\r\n\t\tauto cf = std::stack<Point>();\r\
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
    \ rev.end());\r\n\t\treturn rev;\r\n\t}\r\n};\n#line 5 \"Test/PlaneGeometry/ConvexHull.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    int n;\r\n    cin >> n;\r\n\
    \    std::vector<std::complex<long double>> points;\r\n    points.reserve(n);\r\
    \n    for(int _ = 0; _ < n; ++_) {\r\n        int x, y;\r\n        cin >> x >>\
    \ y;\r\n        points.emplace_back(x, y);\r\n    }\r\n\r\n    auto cf = ConvexHull::grahamScan(points);\r\
    \n    int size = cf.size();\r\n\r\n    int idx = 0;\r\n    for(int i = 1; i <\
    \ size; ++i) {\r\n        if(cf[i].imag() < cf[idx].imag()) { idx = i; continue;\
    \ }\r\n        if(cf[i].imag() < cf[idx].imag() &&\r\n           cf[i].real()\
    \ < cf[idx].real()) {\r\n            idx = i; continue;\r\n        }\r\n    }\r\
    \n\r\n    cout << cf.size() << endl;\r\n    for(int i = 0; i < size; ++i) {\r\n\
    \        auto p = cf[(i + idx) % size];\r\n        cout << p.real() << \" \" <<\
    \ p.imag() << endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"./../../Library/PlaneGeometry/ConvexHull.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n    int n;\r\n    cin >> n;\r\n\
    \    std::vector<std::complex<long double>> points;\r\n    points.reserve(n);\r\
    \n    for(int _ = 0; _ < n; ++_) {\r\n        int x, y;\r\n        cin >> x >>\
    \ y;\r\n        points.emplace_back(x, y);\r\n    }\r\n\r\n    auto cf = ConvexHull::grahamScan(points);\r\
    \n    int size = cf.size();\r\n\r\n    int idx = 0;\r\n    for(int i = 1; i <\
    \ size; ++i) {\r\n        if(cf[i].imag() < cf[idx].imag()) { idx = i; continue;\
    \ }\r\n        if(cf[i].imag() < cf[idx].imag() &&\r\n           cf[i].real()\
    \ < cf[idx].real()) {\r\n            idx = i; continue;\r\n        }\r\n    }\r\
    \n\r\n    cout << cf.size() << endl;\r\n    for(int i = 0; i < size; ++i) {\r\n\
    \        auto p = cf[(i + idx) % size];\r\n        cout << p.real() << \" \" <<\
    \ p.imag() << endl;\r\n    }\r\n}"
  dependsOn:
  - Library/PlaneGeometry/ConvexHull.hpp
  isVerificationFile: true
  path: Test/PlaneGeometry/ConvexHull.test.cpp
  requiredBy: []
  timestamp: '2022-09-08 21:53:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/PlaneGeometry/ConvexHull.test.cpp
layout: document
redirect_from:
- /verify/Test/PlaneGeometry/ConvexHull.test.cpp
- /verify/Test/PlaneGeometry/ConvexHull.test.cpp.html
title: Test/PlaneGeometry/ConvexHull.test.cpp
---
