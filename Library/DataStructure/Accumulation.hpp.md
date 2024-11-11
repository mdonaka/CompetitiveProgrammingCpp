---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/Accumulation_sum.test.cpp
    title: Test/DataStructure/Accumulation_sum.test.cpp
  - icon: ':x:'
    path: Test/DataStructure/Accumulation_xor.test.cpp
    title: Test/DataStructure/Accumulation_xor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/Accumulation.hpp\"\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\nnamespace mtd {\r\n\r\n  template <class S,    // \u8981\
    \u7D20\u306E\u578B\r\n            S element,  // \u5143\r\n            class T,\
    \    // 2\u9805\u6F14\u7B97\u5B50\r\n            class U     // \u9006\u5143\r\
    \n            >\r\n  struct Group {\r\n    S m_val;\r\n    Group() : m_val(element)\
    \ {}\r\n    Group(S val) : m_val(val) {}\r\n    Group inverse() const { return\
    \ U()(m_val); }\r\n    Group binaryOperation(const Group& g) const { return T()(m_val,\
    \ g.m_val); }\r\n  };\r\n\r\n  template <class P>\r\n  struct F_A_Inv {\r\n  \
    \  auto operator()(P x) const { return -x; }\r\n  };\r\n  template <class P>\r\
    \n  struct F_A_Bin {\r\n    auto operator()(P x, P y) const { return x + y; }\r\
    \n  };\r\n  template <class P>\r\n  using AdditiveGroup = Group<P, P(0), F_A_Bin<P>,\
    \ F_A_Inv<P>>;\r\n\r\n  template <class Group = AdditiveGroup<long long>>\r\n\
    \  class Accumulation {\r\n    using S = decltype(Group().m_val);\r\n\r\n    const\
    \ int size;\r\n    std::vector<Group> sumList;\r\n\r\n  public:\r\n    Accumulation()\
    \ = delete;\r\n    Accumulation(const std::vector<Group>& v)\r\n        : size(v.size()),\
    \ sumList(size + 1) {\r\n      for (int i = 0; i < size; ++i) {\r\n        sumList[i\
    \ + 1] = sumList[i].binaryOperation(v[i]);\r\n      }\r\n    }\r\n    Accumulation(const\
    \ std::vector<S>& v)\r\n        : Accumulation(std::vector<Group>(v.begin(), v.end()))\
    \ {}\r\n\r\n    auto get(int n) const { return sumList[n + 1].m_val; }\r\n   \
    \ auto get(int l, int r) const {\r\n      if (r < l) { return Group().m_val; }\r\
    \n      l = std::max(l, 0);\r\n      r = std::min(r, size - 1);\r\n      return\
    \ sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\n    }\r\n  };\r\
    \n\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nnamespace\
    \ mtd {\r\n\r\n  template <class S,    // \u8981\u7D20\u306E\u578B\r\n       \
    \     S element,  // \u5143\r\n            class T,    // 2\u9805\u6F14\u7B97\u5B50\
    \r\n            class U     // \u9006\u5143\r\n            >\r\n  struct Group\
    \ {\r\n    S m_val;\r\n    Group() : m_val(element) {}\r\n    Group(S val) : m_val(val)\
    \ {}\r\n    Group inverse() const { return U()(m_val); }\r\n    Group binaryOperation(const\
    \ Group& g) const { return T()(m_val, g.m_val); }\r\n  };\r\n\r\n  template <class\
    \ P>\r\n  struct F_A_Inv {\r\n    auto operator()(P x) const { return -x; }\r\n\
    \  };\r\n  template <class P>\r\n  struct F_A_Bin {\r\n    auto operator()(P x,\
    \ P y) const { return x + y; }\r\n  };\r\n  template <class P>\r\n  using AdditiveGroup\
    \ = Group<P, P(0), F_A_Bin<P>, F_A_Inv<P>>;\r\n\r\n  template <class Group = AdditiveGroup<long\
    \ long>>\r\n  class Accumulation {\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int size;\r\n    std::vector<Group> sumList;\r\n\r\n  public:\r\
    \n    Accumulation() = delete;\r\n    Accumulation(const std::vector<Group>& v)\r\
    \n        : size(v.size()), sumList(size + 1) {\r\n      for (int i = 0; i < size;\
    \ ++i) {\r\n        sumList[i + 1] = sumList[i].binaryOperation(v[i]);\r\n   \
    \   }\r\n    }\r\n    Accumulation(const std::vector<S>& v)\r\n        : Accumulation(std::vector<Group>(v.begin(),\
    \ v.end())) {}\r\n\r\n    auto get(int n) const { return sumList[n + 1].m_val;\
    \ }\r\n    auto get(int l, int r) const {\r\n      if (r < l) { return Group().m_val;\
    \ }\r\n      l = std::max(l, 0);\r\n      r = std::min(r, size - 1);\r\n     \
    \ return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\n    }\r\
    \n  };\r\n\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/Accumulation.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/DataStructure/Accumulation_sum.test.cpp
  - Test/DataStructure/Accumulation_xor.test.cpp
documentation_of: Library/DataStructure/Accumulation.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/Accumulation.hpp
- /library/Library/DataStructure/Accumulation.hpp.html
title: Library/DataStructure/Accumulation.hpp
---
