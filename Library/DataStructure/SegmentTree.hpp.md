---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/CoordinateCompression_comp.test.cpp
    title: Test/Algorithms/CoordinateCompression_comp.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/CoordinateCompression_to.test.cpp
    title: Test/Algorithms/CoordinateCompression_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/LazySegmentTree_maxright.test.cpp
    title: Test/DataStructure/LazySegmentTree_maxright.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_RMQ.test.cpp
    title: Test/DataStructure/SegmentTree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_RSQ.test.cpp
    title: Test/DataStructure/SegmentTree_RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_maxright.test.cpp
    title: Test/DataStructure/SegmentTree_maxright.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_minleft.test.cpp
    title: Test/DataStructure/SegmentTree_minleft.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/String/LCPArray.test.cpp
    title: Test/String/LCPArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#include <deque>\r\
    \n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n\r\n#line\
    \ 2 \"Library/Algebraic/Monoid.hpp\"\n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\
    \n\nnamespace mtd {\n\n  template <class S,    // set\n            S element,\
    \  // identity element\n            class op    // binary operation\n        \
    \    >\n  requires std::is_invocable_r_v<S, op, S, S>\n  struct Monoid {\n   \
    \ using value_type = S;\n    constexpr static S _element = element;\n    using\
    \ op_type = op;\n\n    S m_val;\n    constexpr Monoid(S val) : m_val(val) {}\n\
    \    constexpr Monoid() : Monoid(element) {}\n    constexpr Monoid binaryOperation(const\
    \ Monoid& m2) const {\n      return op()(m_val, m2.m_val);\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& os,\n                               \
    \     const Monoid<S, element, op>& m) {\n      return os << m.m_val;\n    }\n\
    \  };\n\n  namespace __detail {\n    template <typename T, template <typename,\
    \ auto, typename> typename S>\n    concept is_monoid_specialization_of = requires\
    \ {\n      typename std::enable_if_t<std::is_same_v<\n          T, S<typename\
    \ T::value_type, T::_element, typename T::op_type>>>;\n    };\n  }  // namespace\
    \ __detail\n\n  template <typename M>\n  concept monoid = __detail::is_monoid_specialization_of<M,\
    \ Monoid>;\n\n}  // namespace mtd\n#line 9 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  template <monoid Monoid>\r\n  class SegmentTree\
    \ {\r\n  private:\r\n    const int m_size;\r\n    std::vector<Monoid> m_node;\r\
    \n    using S = decltype(Monoid().m_val);\r\n\r\n    constexpr int calcSize(int\
    \ n) const {\r\n      int size = 1;\r\n      while (size < n) { size <<= 1; }\r\
    \n      return size;\r\n    }\r\n\r\n    template <class Lambda>\r\n    constexpr\
    \ auto _update_op(int itr, Monoid&& val, const Lambda& op) {\r\n      int i =\
    \ itr + m_size - 1;\r\n      m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));\r\
    \n      while (i) {\r\n        i = (i - 1) >> 1;\r\n        m_node[i] = m_node[(i\
    \ << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n    }\r\n\r\n\
    \    constexpr auto _query(int _l, int _r) const {\r\n      auto l = std::max(_l,\
    \ 0) + m_size;\r\n      auto r = std::min(_r, m_size - 1) + m_size;\r\n      auto\
    \ lm = Monoid();\r\n      auto rm = Monoid();\r\n      while (l <= r) {\r\n  \
    \      if (l & 1) {\r\n          lm = lm.binaryOperation(m_node[l - 1]);\r\n \
    \         ++l;\r\n        }\r\n        if (!(r & 1)) {\r\n          rm = m_node[r\
    \ - 1].binaryOperation(rm);\r\n          --r;\r\n        }\r\n        l >>= 1,\
    \ r >>= 1;\r\n      }\r\n      return lm.binaryOperation(rm);\r\n    }\r\n\r\n\
    \    constexpr auto _construct(const std::vector<S>& vec) {\r\n      for (unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n      }\r\n      for (int i = m_size - 2; i >= 0; --i) {\r\n        m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n\
    \    }\r\n\r\n  public:\r\n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1) {}\r\n    SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n)\
    \ {\r\n      _construct(vec);\r\n    }\r\n\r\n    template <class Lambda>\r\n\
    \    constexpr auto update_op(int itr, Monoid&& val, const Lambda& op) {\r\n \
    \     return _update_op(itr, std::forward<Monoid>(val), op);\r\n    }\r\n    constexpr\
    \ auto update(int itr, Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid&, const Monoid& m2) { return m2; });\r\
    \n    }\r\n    constexpr auto add(int itr, Monoid&& val) {\r\n      return update_op(itr,\
    \ std::forward<Monoid>(val),\r\n                       [](const Monoid& m1, const\
    \ Monoid& m2) {\r\n                         return Monoid(m1.m_val + m2.m_val);\r\
    \n                       });\r\n    }\r\n    constexpr auto query(int l, int r)\
    \ const { return _query(l, r).m_val; }\r\n    constexpr auto query_all() const\
    \ { return m_node[0].m_val; }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\
    \u308B\u6700\u5927\u306Er\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n  \
    \  template <class F>\r\n    constexpr auto max_right(int _l, const F& judge)\
    \ const {\r\n      if (!judge(Monoid())) {\r\n        throw std::runtime_error(\"\
    SegmentTree.max_right.judge(e) must be true\");\r\n      }\r\n      auto l = std::max(_l,\
    \ 0) + m_size;\r\n      auto r = 2 * m_size - 1;\r\n      auto lm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          auto next = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          if (!judge(next)) {\r\n            auto itr = l;\r\n   \
    \         while (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n   \
    \           auto ritr = 2 * itr + 1;\r\n              auto lval = lm.binaryOperation(m_node[litr\
    \ - 1]);\r\n              if (!judge(lval)) {\r\n                itr = litr;\r\
    \n              } else {\r\n                itr = ritr;\r\n                std::swap(lm,\
    \ lval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ - 1;\r\n          }\r\n          std::swap(lm, next);\r\n          ++l;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return m_size - 1;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5C0F\
    \u306El\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto min_left(int _r, const F& judge) const {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.min_left.judge(e) must be\
    \ true\");\r\n      }\r\n      auto l = m_size;\r\n      auto r = std::min(_r,\
    \ m_size - 1) + m_size;\r\n      auto rm = Monoid();\r\n      while (l <= r) {\r\
    \n        if (l & 1) { ++l; }\r\n        if (!(r & 1) || (_r == m_size - 1 &&\
    \ r == 1)) {\r\n          auto next = m_node[r - 1].binaryOperation(rm);\r\n \
    \         if (!judge(next)) {\r\n            auto itr = r;\r\n            while\
    \ (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n              auto\
    \ ritr = 2 * itr + 1;\r\n              auto rval = m_node[ritr - 1].binaryOperation(rm);\r\
    \n              if (!judge(rval)) {\r\n                itr = ritr;\r\n       \
    \       } else {\r\n                itr = litr;\r\n                std::swap(rm,\
    \ rval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ + 1;\r\n          }\r\n          std::swap(rm, next);\r\n          --r;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return 0;\r\n    }\r\
    \n\r\n    constexpr auto debug() const {\r\n      for (int i = 0; i < m_size;\
    \ ++i) {\r\n        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\
    \n      std::cout << std::endl;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <deque>\r\n#include <iostream>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\n#include \"../Algebraic/Monoid.hpp\"\r\n\r\nnamespace\
    \ mtd {\r\n\r\n  template <monoid Monoid>\r\n  class SegmentTree {\r\n  private:\r\
    \n    const int m_size;\r\n    std::vector<Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    constexpr int calcSize(int n) const {\r\n      int size = 1;\r\n   \
    \   while (size < n) { size <<= 1; }\r\n      return size;\r\n    }\r\n\r\n  \
    \  template <class Lambda>\r\n    constexpr auto _update_op(int itr, Monoid&&\
    \ val, const Lambda& op) {\r\n      int i = itr + m_size - 1;\r\n      m_node[i]\
    \ = op(m_node[i], std::forward<decltype(val)>(val));\r\n      while (i) {\r\n\
    \        i = (i - 1) >> 1;\r\n        m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i\
    \ + 1) << 1]);\r\n      }\r\n    }\r\n\r\n    constexpr auto _query(int _l, int\
    \ _r) const {\r\n      auto l = std::max(_l, 0) + m_size;\r\n      auto r = std::min(_r,\
    \ m_size - 1) + m_size;\r\n      auto lm = Monoid();\r\n      auto rm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          lm = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          ++l;\r\n        }\r\n        if (!(r & 1)) {\r\n       \
    \   rm = m_node[r - 1].binaryOperation(rm);\r\n          --r;\r\n        }\r\n\
    \        l >>= 1, r >>= 1;\r\n      }\r\n      return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    constexpr auto _construct(const std::vector<S>& vec) {\r\n\
    \      for (unsigned int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size\
    \ - 1] = Monoid(vec[i]);\r\n      }\r\n      for (int i = m_size - 2; i >= 0;\
    \ --i) {\r\n        m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i\
    \ + 1) << 1]);\r\n      }\r\n    }\r\n\r\n  public:\r\n    SegmentTree(int n)\
    \ : m_size(calcSize(n)), m_node((m_size << 1) - 1) {}\r\n    SegmentTree(int n,\
    \ const std::vector<S>& vec) : SegmentTree(n) {\r\n      _construct(vec);\r\n\
    \    }\r\n\r\n    template <class Lambda>\r\n    constexpr auto update_op(int\
    \ itr, Monoid&& val, const Lambda& op) {\r\n      return _update_op(itr, std::forward<Monoid>(val),\
    \ op);\r\n    }\r\n    constexpr auto update(int itr, Monoid&& val) {\r\n    \
    \  return update_op(itr, std::forward<Monoid>(val),\r\n                      \
    \ [](const Monoid&, const Monoid& m2) { return m2; });\r\n    }\r\n    constexpr\
    \ auto add(int itr, Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid& m1, const Monoid& m2) {\r\n        \
    \                 return Monoid(m1.m_val + m2.m_val);\r\n                    \
    \   });\r\n    }\r\n    constexpr auto query(int l, int r) const { return _query(l,\
    \ r).m_val; }\r\n    constexpr auto query_all() const { return m_node[0].m_val;\
    \ }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5927\u306E\
    r\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\n\
    \    constexpr auto max_right(int _l, const F& judge) const {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.max_right.judge(e) must\
    \ be true\");\r\n      }\r\n      auto l = std::max(_l, 0) + m_size;\r\n     \
    \ auto r = 2 * m_size - 1;\r\n      auto lm = Monoid();\r\n      while (l <= r)\
    \ {\r\n        if (l & 1) {\r\n          auto next = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          if (!judge(next)) {\r\n            auto itr = l;\r\n   \
    \         while (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n   \
    \           auto ritr = 2 * itr + 1;\r\n              auto lval = lm.binaryOperation(m_node[litr\
    \ - 1]);\r\n              if (!judge(lval)) {\r\n                itr = litr;\r\
    \n              } else {\r\n                itr = ritr;\r\n                std::swap(lm,\
    \ lval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ - 1;\r\n          }\r\n          std::swap(lm, next);\r\n          ++l;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return m_size - 1;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5C0F\
    \u306El\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto min_left(int _r, const F& judge) const {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.min_left.judge(e) must be\
    \ true\");\r\n      }\r\n      auto l = m_size;\r\n      auto r = std::min(_r,\
    \ m_size - 1) + m_size;\r\n      auto rm = Monoid();\r\n      while (l <= r) {\r\
    \n        if (l & 1) { ++l; }\r\n        if (!(r & 1) || (_r == m_size - 1 &&\
    \ r == 1)) {\r\n          auto next = m_node[r - 1].binaryOperation(rm);\r\n \
    \         if (!judge(next)) {\r\n            auto itr = r;\r\n            while\
    \ (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n              auto\
    \ ritr = 2 * itr + 1;\r\n              auto rval = m_node[ritr - 1].binaryOperation(rm);\r\
    \n              if (!judge(rval)) {\r\n                itr = ritr;\r\n       \
    \       } else {\r\n                itr = litr;\r\n                std::swap(rm,\
    \ rval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ + 1;\r\n          }\r\n          std::swap(rm, next);\r\n          --r;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return 0;\r\n    }\r\
    \n\r\n    constexpr auto debug() const {\r\n      for (int i = 0; i < m_size;\
    \ ++i) {\r\n        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\
    \n      std::cout << std::endl;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Algebraic/Monoid.hpp
  isVerificationFile: false
  path: Library/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2025-01-23 04:47:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/SegmentTree_minleft.test.cpp
  - Test/DataStructure/SegmentTree_RSQ.test.cpp
  - Test/DataStructure/SegmentTree_RMQ.test.cpp
  - Test/DataStructure/SegmentTree_maxright.test.cpp
  - Test/DataStructure/LazySegmentTree_maxright.test.cpp
  - Test/Algorithms/CoordinateCompression_to.test.cpp
  - Test/Algorithms/CoordinateCompression_comp.test.cpp
  - Test/String/LCPArray.test.cpp
documentation_of: Library/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/SegmentTree.hpp
- /library/Library/DataStructure/SegmentTree.hpp.html
title: Library/DataStructure/SegmentTree.hpp
---
