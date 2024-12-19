---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DynamicSegmentTree.hpp
    title: Library/DataStructure/DynamicSegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/LazySegmentTree.hpp
    title: Library/DataStructure/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: Library/DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Tree/ReRootingDP.hpp
    title: Library/Graph/Tree/ReRootingDP.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/CoordinateCompression_comp.test.cpp
    title: Test/Algorithms/CoordinateCompression_comp.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/CoordinateCompression_to.test.cpp
    title: Test/Algorithms/CoordinateCompression_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicSegmentTree.test.cpp
    title: Test/DataStructure/DynamicSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicSegmentTree_RMQ.test.cpp
    title: Test/DataStructure/DynamicSegmentTree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
    title: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LazySegmentTree_RAQRMQ.test.cpp
    title: Test/DataStructure/LazySegmentTree_RAQRMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
    title: Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LazySegmentTree_RUQRMQ.test.cpp
    title: Test/DataStructure/LazySegmentTree_RUQRMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LazySegmentTree_RUQRSQ.test.cpp
    title: Test/DataStructure/LazySegmentTree_RUQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_RMQ.test.cpp
    title: Test/DataStructure/SegmentTree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_RSQ.test.cpp
    title: Test/DataStructure/SegmentTree_RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/ReRootingDP.test.cpp
    title: Test/Graph/Tree/ReRootingDP.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Tree/ReRootingDP_cost.test.cpp
    title: Test/Graph/Tree/ReRootingDP_cost.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/String/LCPArray.test.cpp
    title: Test/String/LCPArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algebraic/Monoid.hpp\"\n\n#include <iostream>\n\n\
    namespace mtd {\n\n  template <class S,    // set\n            S element,  //\
    \ identity element\n            class op    // binary operation\n            >\n\
    \  requires std::is_invocable_r_v<S, op, S, S>\n  struct Monoid {\n    using value_type\
    \ = S;\n    constexpr static S _element = element;\n    using op_type = op;\n\n\
    \    S m_val;\n    constexpr Monoid(S val) : m_val(val) {}\n    constexpr Monoid()\
    \ : Monoid(element) {}\n    constexpr Monoid binaryOperation(const Monoid& m2)\
    \ const {\n      return op()(m_val, m2.m_val);\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                    const Monoid<S,\
    \ element, op>& m) {\n      return os << m.m_val;\n    }\n  };\n\n  namespace\
    \ __detail {\n    template <typename T, template <typename, auto, typename> typename\
    \ S>\n    concept is_specialization_of = requires {\n      typename std::enable_if_t<std::is_same_v<\n\
    \          T, S<typename T::value_type, T::_element, typename T::op_type>>>;\n\
    \    };\n  }  // namespace __detail\n\n  template <typename M>\n  concept monoid\
    \ = __detail::is_specialization_of<M, Monoid>;\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace mtd {\n\n  template <class\
    \ S,    // set\n            S element,  // identity element\n            class\
    \ op    // binary operation\n            >\n  requires std::is_invocable_r_v<S,\
    \ op, S, S>\n  struct Monoid {\n    using value_type = S;\n    constexpr static\
    \ S _element = element;\n    using op_type = op;\n\n    S m_val;\n    constexpr\
    \ Monoid(S val) : m_val(val) {}\n    constexpr Monoid() : Monoid(element) {}\n\
    \    constexpr Monoid binaryOperation(const Monoid& m2) const {\n      return\
    \ op()(m_val, m2.m_val);\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                    const Monoid<S, element, op>& m) {\n\
    \      return os << m.m_val;\n    }\n  };\n\n  namespace __detail {\n    template\
    \ <typename T, template <typename, auto, typename> typename S>\n    concept is_specialization_of\
    \ = requires {\n      typename std::enable_if_t<std::is_same_v<\n          T,\
    \ S<typename T::value_type, T::_element, typename T::op_type>>>;\n    };\n  }\
    \  // namespace __detail\n\n  template <typename M>\n  concept monoid = __detail::is_specialization_of<M,\
    \ Monoid>;\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algebraic/Monoid.hpp
  requiredBy:
  - Library/Graph/Tree/ReRootingDP.hpp
  - Library/DataStructure/LazySegmentTree.hpp
  - Library/DataStructure/SegmentTree.hpp
  - Library/DataStructure/DynamicSegmentTree.hpp
  timestamp: '2024-12-11 01:55:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/String/LCPArray.test.cpp
  - Test/Graph/Tree/ReRootingDP_cost.test.cpp
  - Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  - Test/Graph/Tree/ReRootingDP.test.cpp
  - Test/Algorithms/CoordinateCompression_to.test.cpp
  - Test/Algorithms/CoordinateCompression_comp.test.cpp
  - Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
  - Test/DataStructure/SegmentTree_RSQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RUQRSQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RAQRMQ.test.cpp
  - Test/DataStructure/DynamicSegmentTree.test.cpp
  - Test/DataStructure/SegmentTree_RMQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
  - Test/DataStructure/DynamicSegmentTree_RMQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RUQRMQ.test.cpp
documentation_of: Library/Algebraic/Monoid.hpp
layout: document
redirect_from:
- /library/Library/Algebraic/Monoid.hpp
- /library/Library/Algebraic/Monoid.hpp.html
title: Library/Algebraic/Monoid.hpp
---
