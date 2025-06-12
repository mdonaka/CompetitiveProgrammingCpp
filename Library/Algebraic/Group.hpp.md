---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/Accumulation.hpp
    title: Library/DataStructure/Accumulation.hpp
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
  bundledCode: "#line 2 \"Library/Algebraic/Group.hpp\"\n\n#include <iostream>\n\n\
    namespace mtd {\n\n  template <class S,    // set\n            S element,  //\
    \ identity element\n            class op,   // binary operation\n            class\
    \ inv   // inverse operation\n            >\n  requires std::is_invocable_r_v<S,\
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
    \ Group>;\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace mtd {\n\n  template <class\
    \ S,    // set\n            S element,  // identity element\n            class\
    \ op,   // binary operation\n            class inv   // inverse operation\n  \
    \          >\n  requires std::is_invocable_r_v<S, op, S, S>\n  struct Group {\n\
    \    using value_type = S;\n    constexpr static S _element = element;\n    using\
    \ op_type = op;\n    using inv_type = inv;\n\n    S m_val;\n    constexpr Group()\
    \ : m_val(element) {}\n    constexpr Group(S val) : m_val(val) {}\n    constexpr\
    \ Group inverse() const { return inv()(m_val); }\n    constexpr Group binaryOperation(const\
    \ Group& g) const {\n      return op()(m_val, g.m_val);\n    }\n    constexpr\
    \ friend std::ostream& operator<<(\n        std::ostream& os, const Group<S, element,\
    \ op, inv>& g) {\n      return os << g.m_val;\n    }\n  };\n\n  namespace __detail\
    \ {\n    template <typename T,\n              template <typename, auto, typename,\
    \ typename> typename S>\n    concept is_group_specialization_of = requires {\n\
    \      typename std::enable_if_t<\n          std::is_same_v<T, S<typename T::value_type,\
    \ T::_element,\n                              typename T::op_type, typename T::inv_type>>>;\n\
    \    };\n  }  // namespace __detail\n\n  template <typename G>\n  concept group\
    \ = __detail::is_group_specialization_of<G, Group>;\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algebraic/Group.hpp
  requiredBy:
  - Library/DataStructure/Accumulation.hpp
  - Library/DataStructure/Accumulation2D.hpp
  timestamp: '2024-12-27 16:29:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/Accumulation_sum.test.cpp
  - Test/DataStructure/Accumulation_xor.test.cpp
  - Test/DataStructure/Accumulation2D_sum.test.cpp
documentation_of: Library/Algebraic/Group.hpp
layout: document
redirect_from:
- /library/Library/Algebraic/Group.hpp
- /library/Library/Algebraic/Group.hpp.html
title: Library/Algebraic/Group.hpp
---
