---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Group.hpp
    title: Library/Algebraic/Group.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/Accumulation2D.hpp
    title: Library/DataStructure/Accumulation2D.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/Accumulation2D_sum.test.cpp
    title: Test/DataStructure/Accumulation2D_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/Accumulation_sum.test.cpp
    title: Test/DataStructure/Accumulation_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/Accumulation_xor.test.cpp
    title: Test/DataStructure/Accumulation_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/Accumulation.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/Group.hpp\"\n\n#include\
    \ <iostream>\n\nnamespace mtd {\n\n  template <class S,    // set\n          \
    \  S element,  // identity element\n            class op,   // binary operation\n\
    \            class inv   // inverse operation\n            >\n  requires std::is_invocable_r_v<S,\
    \ op, S, S>\n  struct Group {\n    using value_type = S;\n    constexpr static\
    \ S _element = element;\n    using op_type = op;\n    using inv_type = inv;\n\n\
    \    S m_val;\n    constexpr Group() : m_val(element) {}\n    constexpr Group(S\
    \ val) : m_val(val) {}\n    constexpr Group inverse() const { return inv()(m_val);\
    \ }\n    constexpr Group binaryOperation(const Group& g) const {\n      return\
    \ op()(m_val, g.m_val);\n    }\n    constexpr friend std::ostream& operator<<(\n\
    \        std::ostream& os, const Group<S, element, op, inv>& g) {\n      return\
    \ os << g.m_val;\n    }\n  };\n\n  namespace __detail {\n    template <typename\
    \ T,\n              template <typename, auto, typename, typename> typename S>\n\
    \    concept is_group_specialization_of = requires {\n      typename std::enable_if_t<\n\
    \          std::is_same_v<T, S<typename T::value_type, T::_element,\n        \
    \                      typename T::op_type, typename T::inv_type>>>;\n    };\n\
    \  }  // namespace __detail\n\n  template <typename G>\n  concept group = __detail::is_group_specialization_of<G,\
    \ Group>;\n\n}  // namespace mtd\n#line 7 \"Library/DataStructure/Accumulation.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  namespace type {\r\n\r\n    using inv = decltype([](auto\
    \ x) { return -x; });\r\n    using op = decltype([](auto x, auto y) { return x\
    \ + y; });\r\n    template <class P>\r\n    using AdditiveGroup = Group<P, P(0),\
    \ op, inv>;\r\n\r\n  }  // namespace type\r\n\r\n  template <group Group = type::AdditiveGroup<long\
    \ long>>\r\n  class Accumulation {\r\n    using S = decltype(Group().m_val);\r\
    \n\r\n    const int size;\r\n    std::vector<Group> sumList;\r\n\r\n  public:\r\
    \n    constexpr Accumulation() = delete;\r\n    constexpr Accumulation(const std::vector<Group>&\
    \ v)\r\n        : size(v.size()), sumList(size + 1) {\r\n      for (int i = 0;\
    \ i < size; ++i) {\r\n        sumList[i + 1] = sumList[i].binaryOperation(v[i]);\r\
    \n      }\r\n    }\r\n    constexpr Accumulation(const std::vector<S>& v)\r\n\
    \        : Accumulation(std::vector<Group>(v.begin(), v.end())) {}\r\n\r\n   \
    \ constexpr auto get(int n) const { return sumList[n + 1].m_val; }\r\n    constexpr\
    \ auto get(int l, int r) const {\r\n      if (r < l) { return Group::_element;\
    \ }\r\n      l = std::max(l, 0);\r\n      r = std::min(r, size - 1);\r\n     \
    \ return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\n    }\r\
    \n\r\n    constexpr friend std::ostream& operator<<(std::ostream& os,\r\n    \
    \                                          const Accumulation<Group>& acc) {\r\
    \n      for (const auto& x : acc.sumList) { os << x << \" \"; }\r\n      return\
    \ os;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n#include\
    \ \"../Algebraic/Group.hpp\"\r\n\r\nnamespace mtd {\r\n\r\n  namespace type {\r\
    \n\r\n    using inv = decltype([](auto x) { return -x; });\r\n    using op = decltype([](auto\
    \ x, auto y) { return x + y; });\r\n    template <class P>\r\n    using AdditiveGroup\
    \ = Group<P, P(0), op, inv>;\r\n\r\n  }  // namespace type\r\n\r\n  template <group\
    \ Group = type::AdditiveGroup<long long>>\r\n  class Accumulation {\r\n    using\
    \ S = decltype(Group().m_val);\r\n\r\n    const int size;\r\n    std::vector<Group>\
    \ sumList;\r\n\r\n  public:\r\n    constexpr Accumulation() = delete;\r\n    constexpr\
    \ Accumulation(const std::vector<Group>& v)\r\n        : size(v.size()), sumList(size\
    \ + 1) {\r\n      for (int i = 0; i < size; ++i) {\r\n        sumList[i + 1] =\
    \ sumList[i].binaryOperation(v[i]);\r\n      }\r\n    }\r\n    constexpr Accumulation(const\
    \ std::vector<S>& v)\r\n        : Accumulation(std::vector<Group>(v.begin(), v.end()))\
    \ {}\r\n\r\n    constexpr auto get(int n) const { return sumList[n + 1].m_val;\
    \ }\r\n    constexpr auto get(int l, int r) const {\r\n      if (r < l) { return\
    \ Group::_element; }\r\n      l = std::max(l, 0);\r\n      r = std::min(r, size\
    \ - 1);\r\n      return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;\r\
    \n    }\r\n\r\n    constexpr friend std::ostream& operator<<(std::ostream& os,\r\
    \n                                              const Accumulation<Group>& acc)\
    \ {\r\n      for (const auto& x : acc.sumList) { os << x << \" \"; }\r\n     \
    \ return os;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Algebraic/Group.hpp
  isVerificationFile: false
  path: Library/DataStructure/Accumulation.hpp
  requiredBy:
  - Library/DataStructure/Accumulation2D.hpp
  timestamp: '2024-12-27 16:29:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/Accumulation_xor.test.cpp
  - Test/DataStructure/Accumulation_sum.test.cpp
  - Test/DataStructure/Accumulation2D_sum.test.cpp
documentation_of: Library/DataStructure/Accumulation.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/Accumulation.hpp
- /library/Library/DataStructure/Accumulation.hpp.html
title: Library/DataStructure/Accumulation.hpp
---
