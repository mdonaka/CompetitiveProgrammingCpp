---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Container/Accumulation2D_sum.test.cpp
    title: Test/Container/Accumulation2D_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Container/Accumulation2D.hpp\"\n#include <vector>\r\
    \n\r\ntemplate<\r\n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S element,\
    \ // \u5143\r\n    class T, // 2\u9805\u6F14\u7B97\u5B50\r\n    class U // \u9006\
    \u5143\r\n>\r\nstruct Group {\r\n    S m_val;\r\n    Group() :m_val(element) {}\r\
    \n    Group(S val) :m_val(val) {}\r\n    Group inverse()const { return U()(m_val);\
    \ }\r\n    Group binaryOperation(const Group& g)const { return T()(m_val, g.m_val);\
    \ }\r\n};\r\n\r\ntemplate<class P> struct F_A_Inv { auto operator()(P x)const\
    \ { return -x; } };\r\ntemplate<class P> struct F_A_Bin { auto operator()(P x,\
    \ P y)const { return x + y; } };\r\ntemplate<class P> using AdditiveGroup = Group<P,\
    \ P(0), F_A_Bin<P>, F_A_Inv<P>>;\r\n\r\ntemplate <class Group = AdditiveGroup<long\
    \ long>>\r\nclass Accumulation2D {\r\nprivate:\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int h;\r\n    const int w;\r\n    std::vector<std::vector<Group>>\
    \ sumList;\r\npublic:\r\n\r\n    Accumulation2D() = delete;\r\n    Accumulation2D(const\
    \ std::vector<std::vector<S>>& v) :\r\n        h(v.size()),\r\n        w(v[0].size()),\r\
    \n        sumList(h + 1, std::vector<Group>(w + 1)) {\r\n        for(int i = 0;\
    \ i < h; ++i) for(int j = 0; j < w; ++j) {\r\n            sumList[i + 1][j + 1]\
    \ = v[i][j];\r\n        }\r\n        for(int i = 0; i < h; ++i) for(int j = 0;\
    \ j < w + 1; ++j) {\r\n            sumList[i + 1][j] = sumList[i + 1][j].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n        for(int i = 0; i < h + 1; ++i) for(int j = 0; j < w; ++j)\
    \ {\r\n            sumList[i][j + 1] = sumList[i][j + 1].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n    }\r\n    S get(int y, int x) {\r\n        return sumList[y\
    \ + 1][x + 1].m_val;\r\n    }\r\n    S get(int y1, int x1, int y2, int x2) {\r\
    \n        if(y2 < y1 || x2 < x1) { return Group().m_val; }\r\n        x1 = std::max(x1,\
    \ 0); y1 = std::max(y1, 0);\r\n        y2 = std::min(y2, h - 1); x2 = std::min(x2,\
    \ w - 1);\r\n        return sumList[y2 + 1][x2 + 1]\r\n            .binaryOperation(sumList[y1][x1])\r\
    \n            .binaryOperation(sumList[y2 + 1][x1].inverse())\r\n            .binaryOperation(sumList[y1][x2\
    \ + 1].inverse()).m_val;\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate<\r\n    class S,   // \u8981\
    \u7D20\u306E\u578B\r\n    S element, // \u5143\r\n    class T, // 2\u9805\u6F14\
    \u7B97\u5B50\r\n    class U // \u9006\u5143\r\n>\r\nstruct Group {\r\n    S m_val;\r\
    \n    Group() :m_val(element) {}\r\n    Group(S val) :m_val(val) {}\r\n    Group\
    \ inverse()const { return U()(m_val); }\r\n    Group binaryOperation(const Group&\
    \ g)const { return T()(m_val, g.m_val); }\r\n};\r\n\r\ntemplate<class P> struct\
    \ F_A_Inv { auto operator()(P x)const { return -x; } };\r\ntemplate<class P> struct\
    \ F_A_Bin { auto operator()(P x, P y)const { return x + y; } };\r\ntemplate<class\
    \ P> using AdditiveGroup = Group<P, P(0), F_A_Bin<P>, F_A_Inv<P>>;\r\n\r\ntemplate\
    \ <class Group = AdditiveGroup<long long>>\r\nclass Accumulation2D {\r\nprivate:\r\
    \n    using S = decltype(Group().m_val);\r\n\r\n    const int h;\r\n    const\
    \ int w;\r\n    std::vector<std::vector<Group>> sumList;\r\npublic:\r\n\r\n  \
    \  Accumulation2D() = delete;\r\n    Accumulation2D(const std::vector<std::vector<S>>&\
    \ v) :\r\n        h(v.size()),\r\n        w(v[0].size()),\r\n        sumList(h\
    \ + 1, std::vector<Group>(w + 1)) {\r\n        for(int i = 0; i < h; ++i) for(int\
    \ j = 0; j < w; ++j) {\r\n            sumList[i + 1][j + 1] = v[i][j];\r\n   \
    \     }\r\n        for(int i = 0; i < h; ++i) for(int j = 0; j < w + 1; ++j) {\r\
    \n            sumList[i + 1][j] = sumList[i + 1][j].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n        for(int i = 0; i < h + 1; ++i) for(int j = 0; j < w; ++j)\
    \ {\r\n            sumList[i][j + 1] = sumList[i][j + 1].binaryOperation(sumList[i][j]);\r\
    \n        }\r\n    }\r\n    S get(int y, int x) {\r\n        return sumList[y\
    \ + 1][x + 1].m_val;\r\n    }\r\n    S get(int y1, int x1, int y2, int x2) {\r\
    \n        if(y2 < y1 || x2 < x1) { return Group().m_val; }\r\n        x1 = std::max(x1,\
    \ 0); y1 = std::max(y1, 0);\r\n        y2 = std::min(y2, h - 1); x2 = std::min(x2,\
    \ w - 1);\r\n        return sumList[y2 + 1][x2 + 1]\r\n            .binaryOperation(sumList[y1][x1])\r\
    \n            .binaryOperation(sumList[y2 + 1][x1].inverse())\r\n            .binaryOperation(sumList[y1][x2\
    \ + 1].inverse()).m_val;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/Accumulation2D.hpp
  requiredBy: []
  timestamp: '2022-09-03 18:35:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Container/Accumulation2D_sum.test.cpp
documentation_of: Library/Container/Accumulation2D.hpp
layout: document
redirect_from:
- /library/Library/Container/Accumulation2D.hpp
- /library/Library/Container/Accumulation2D.hpp.html
title: Library/Container/Accumulation2D.hpp
---
