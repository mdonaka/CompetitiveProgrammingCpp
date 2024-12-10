---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DisjointSparseTable.hpp
    title: Library/DataStructure/DisjointSparseTable.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
    title: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DisjointSparseTable_xor.test.cpp
    title: Test/DataStructure/DisjointSparseTable_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algebraic/SemiGroup.hpp\"\n\n#include <iostream>\n\
    \nnamespace mtd {\n\n  template <class S,  // set\n            class op  // binary\
    \ operation\n            >\n  requires std::is_invocable_r_v<S, op, S, S>\n  struct\
    \ SemiGroup {\n    using value_type = S;\n    using op_type = op;\n\n    S m_val;\n\
    \    constexpr SemiGroup(S val) : m_val(val) {}\n    constexpr SemiGroup binaryOperation(const\
    \ SemiGroup& s) const {\n      return op()(m_val, s.m_val);\n    }\n    constexpr\
    \ friend std::ostream& operator<<(std::ostream& os,\n                        \
    \                      const SemiGroup<S, op>& s) {\n      return os << s.m_val;\n\
    \    }\n  };\n\n  namespace __detail {\n    template <typename T, template <typename,\
    \ typename> typename S>\n    concept is_specialization_of = requires {\n     \
    \ typename std::enable_if_t<\n          std::is_same_v<T, S<typename T::value_type,\
    \ typename T::op_type>>>;\n    };\n  }  // namespace __detail\n\n  template <typename\
    \ G>\n  concept semigroup = __detail::is_specialization_of<G, SemiGroup>;\n\n\
    }  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace mtd {\n\n  template <class\
    \ S,  // set\n            class op  // binary operation\n            >\n  requires\
    \ std::is_invocable_r_v<S, op, S, S>\n  struct SemiGroup {\n    using value_type\
    \ = S;\n    using op_type = op;\n\n    S m_val;\n    constexpr SemiGroup(S val)\
    \ : m_val(val) {}\n    constexpr SemiGroup binaryOperation(const SemiGroup& s)\
    \ const {\n      return op()(m_val, s.m_val);\n    }\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const SemiGroup<S, op>& s) {\n      return os << s.m_val;\n    }\n  };\n\n \
    \ namespace __detail {\n    template <typename T, template <typename, typename>\
    \ typename S>\n    concept is_specialization_of = requires {\n      typename std::enable_if_t<\n\
    \          std::is_same_v<T, S<typename T::value_type, typename T::op_type>>>;\n\
    \    };\n  }  // namespace __detail\n\n  template <typename G>\n  concept semigroup\
    \ = __detail::is_specialization_of<G, SemiGroup>;\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algebraic/SemiGroup.hpp
  requiredBy:
  - Library/DataStructure/DisjointSparseTable.hpp
  timestamp: '2024-12-11 02:19:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/DisjointSparseTable_xor.test.cpp
  - Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
documentation_of: Library/Algebraic/SemiGroup.hpp
layout: document
redirect_from:
- /library/Library/Algebraic/SemiGroup.hpp
- /library/Library/Algebraic/SemiGroup.hpp.html
title: Library/Algebraic/SemiGroup.hpp
---
