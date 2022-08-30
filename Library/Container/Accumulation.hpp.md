---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Container/Accumulation_sum.test.cpp
    title: Test/Container/Accumulation_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Container/Accumulation_xor.test.cpp
    title: Test/Container/Accumulation_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Container/Accumulation.hpp\"\n#include <vector>\r\
    \n#include <algorithm>\r\n\r\ntemplate<\r\n    class S,   // \u8981\u7D20\u306E\
    \u578B\r\n    S element, // \u5143\r\n    class T, // 2\u9805\u6F14\u7B97\u5B50\
    \r\n    class U // \u9006\u5143\r\n>\r\nstruct Group {\r\n    S m_val;\r\n   \
    \ Group() :m_val(element) {}\r\n    Group(S val) :m_val(val) {}\r\n    Group inverse()const\
    \ { return U()(m_val); }\r\n    Group binaryOperation(const Group& g)const { return\
    \ T()(m_val, g.m_val); }\r\n};\r\n\r\ntemplate<class P> struct F_A_Inv { auto\
    \ operator()(P x)const { return -x; } };\r\ntemplate<class P> struct F_A_Bin {\
    \ auto operator()(P x, P y)const { return x + y; } };\r\ntemplate<class P> using\
    \ AdditiveGroup = Group<P, P(0), F_A_Bin<P>, F_A_Inv<P>>;\r\n\r\ntemplate <class\
    \ Group = AdditiveGroup<long long>>\r\nclass Accumulation {\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int size;\r\n    std::vector<Group> sumList;\r\npublic:\r\n\r\n\
    \    Accumulation() = delete;\r\n    Accumulation(const std::vector<Group>& v)\
    \ :size(v.size()), sumList(size + 1) {\r\n        for(int i = 0; i < size; ++i)\
    \ {\r\n            sumList[i + 1] = sumList[i].binaryOperation(v[i]);\r\n    \
    \    }\r\n    }\r\n    Accumulation(const std::vector<S>& v)\r\n        :Accumulation(std::vector<Group>(v.begin(),\
    \ v.end())) {\r\n    }\r\n\r\n    auto get(int n) {\r\n        return sumList[n\
    \ + 1].m_val;\r\n    }\r\n    auto get(int l, int r) {\r\n        if(r < l) {\
    \ return Group().m_val; }\r\n        l = std::max(l, 0); r = std::min(r, size\
    \ - 1);\r\n        return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\
    \n    }\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n\r\ntemplate<\r\
    \n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S element, // \u5143\r\n \
    \   class T, // 2\u9805\u6F14\u7B97\u5B50\r\n    class U // \u9006\u5143\r\n>\r\
    \nstruct Group {\r\n    S m_val;\r\n    Group() :m_val(element) {}\r\n    Group(S\
    \ val) :m_val(val) {}\r\n    Group inverse()const { return U()(m_val); }\r\n \
    \   Group binaryOperation(const Group& g)const { return T()(m_val, g.m_val); }\r\
    \n};\r\n\r\ntemplate<class P> struct F_A_Inv { auto operator()(P x)const { return\
    \ -x; } };\r\ntemplate<class P> struct F_A_Bin { auto operator()(P x, P y)const\
    \ { return x + y; } };\r\ntemplate<class P> using AdditiveGroup = Group<P, P(0),\
    \ F_A_Bin<P>, F_A_Inv<P>>;\r\n\r\ntemplate <class Group = AdditiveGroup<long long>>\r\
    \nclass Accumulation {\r\n    using S = decltype(Group().m_val);\r\n\r\n    const\
    \ int size;\r\n    std::vector<Group> sumList;\r\npublic:\r\n\r\n    Accumulation()\
    \ = delete;\r\n    Accumulation(const std::vector<Group>& v) :size(v.size()),\
    \ sumList(size + 1) {\r\n        for(int i = 0; i < size; ++i) {\r\n         \
    \   sumList[i + 1] = sumList[i].binaryOperation(v[i]);\r\n        }\r\n    }\r\
    \n    Accumulation(const std::vector<S>& v)\r\n        :Accumulation(std::vector<Group>(v.begin(),\
    \ v.end())) {\r\n    }\r\n\r\n    auto get(int n) {\r\n        return sumList[n\
    \ + 1].m_val;\r\n    }\r\n    auto get(int l, int r) {\r\n        if(r < l) {\
    \ return Group().m_val; }\r\n        l = std::max(l, 0); r = std::min(r, size\
    \ - 1);\r\n        return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\
    \n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/Accumulation.hpp
  requiredBy: []
  timestamp: '2022-08-31 03:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Container/Accumulation_sum.test.cpp
  - Test/Container/Accumulation_xor.test.cpp
documentation_of: Library/Container/Accumulation.hpp
layout: document
redirect_from:
- /library/Library/Container/Accumulation.hpp
- /library/Library/Container/Accumulation.hpp.html
title: Library/Container/Accumulation.hpp
---
