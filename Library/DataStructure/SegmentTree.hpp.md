---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Algorithms/CoordinateCompression_comp.test.cpp
    title: Test/Algorithms/CoordinateCompression_comp.test.cpp
  - icon: ':x:'
    path: Test/Algorithms/CoordinateCompression_to.test.cpp
    title: Test/Algorithms/CoordinateCompression_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_RMQ.test.cpp
    title: Test/DataStructure/SegmentTree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/SegmentTree_RSQ.test.cpp
    title: Test/DataStructure/SegmentTree_RSQ.test.cpp
  - icon: ':x:'
    path: Test/String/LCPArray.test.cpp
    title: Test/String/LCPArray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#include <deque>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\nnamespace mtd {\r\n  template\
    \ <class T>\r\n  class isMonoid {\r\n    template <class U>\r\n    static auto\
    \ check(U x) -> decltype(x.binaryOperation(x), std::true_type{});\r\n    static\
    \ std::false_type check(...);\r\n\r\n  public:\r\n    static bool const value\
    \ = decltype(check(std::declval<T>()))::value;\r\n  };\r\n\r\n  template <class\
    \ Monoid,\r\n            std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t>\
    \ = nullptr>\r\n  class SegmentTree {\r\n  private:\r\n    const int m_size;\r\
    \n    std::vector<Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    int calcSize(int n) const {\r\n      int size = 1;\r\n      while (size\
    \ < n) { size <<= 1; }\r\n      return size;\r\n    }\r\n\r\n    template <class\
    \ Lambda>\r\n    auto _update_op(int itr, Monoid&& val, const Lambda& op) {\r\n\
    \      int i = itr + m_size - 1;\r\n      m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));\r\
    \n      while (i) {\r\n        i = (i - 1) >> 1;\r\n        m_node[i] = m_node[(i\
    \ << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n    }\r\n\r\n\
    \    auto _query(int _l, int _r) const {\r\n      _l = std::max(_l, 0);\r\n  \
    \    _r = std::min(_r, m_size - 1);\r\n      auto l = _l + m_size;\r\n      int\
    \ r = _r + m_size;\r\n      auto lm = Monoid();\r\n      auto rm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          lm = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          ++l;\r\n        }\r\n        if (!(r & 1)) {\r\n       \
    \   rm = m_node[r - 1].binaryOperation(rm);\r\n          --r;\r\n        }\r\n\
    \        l >>= 1, r >>= 1;\r\n      }\r\n      return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    auto _construct(const std::vector<S>& vec) {\r\n      for (unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n      }\r\n      for (int i = m_size - 2; i >= 0; --i) {\r\n        m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n\
    \    }\r\n\r\n  public:\r\n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1) {}\r\n    SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n)\
    \ {\r\n      _construct(vec);\r\n    }\r\n\r\n    template <class Lambda>\r\n\
    \    auto update_op(int itr, Monoid&& val, const Lambda& op) {\r\n      return\
    \ _update_op(itr, std::forward<Monoid>(val), op);\r\n    }\r\n    auto update(int\
    \ itr, Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid&, const Monoid& m2) { return m2; });\r\
    \n    }\r\n    auto add(int itr, Monoid&& val) {\r\n      return update_op(itr,\
    \ std::forward<Monoid>(val),\r\n                       [](const Monoid& m1, const\
    \ Monoid& m2) {\r\n                         return Monoid(m1.m_val + m2.m_val);\r\
    \n                       });\r\n    }\r\n    auto query(int l, int r) const {\
    \ return _query(l, r).m_val; }\r\n    auto query_all() const { return m_node[0].m_val;\
    \ }\r\n\r\n    auto output() const {\r\n      for (int i = 0; i < m_size; ++i)\
    \ {\r\n        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\n  \
    \    std::cout << std::endl;\r\n    }\r\n  };\r\n\r\n  template <class S,    //\
    \ \u8981\u7D20\u306E\u578B\r\n            S element,  // \u5143\r\n          \
    \  class T  // lambda\u306FC++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\u306A\
    \u304B\u3063\u305F\uFF0E\uFF0E\uFF0E\r\n                     // S T(S, S)  //\
    \ 2\u9805\u6F14\u7B97\u5B50\r\n            >\r\n  struct Monoid {\r\n    S m_val;\r\
    \n    Monoid() : m_val(element) {}\r\n    Monoid(S val) : m_val(val) {}\r\n  \
    \  Monoid binaryOperation(const Monoid& m2) const {\r\n      return T()(m_val,\
    \ m2.m_val);\r\n    }\r\n    friend std::ostream& operator<<(std::ostream& os,\r\
    \n                                    const Monoid<S, element, T>& m) {\r\n  \
    \    return os << m.m_val;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <deque>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\nnamespace mtd {\r\n  template <class T>\r\n  class isMonoid {\r\n    template\
    \ <class U>\r\n    static auto check(U x) -> decltype(x.binaryOperation(x), std::true_type{});\r\
    \n    static std::false_type check(...);\r\n\r\n  public:\r\n    static bool const\
    \ value = decltype(check(std::declval<T>()))::value;\r\n  };\r\n\r\n  template\
    \ <class Monoid,\r\n            std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t>\
    \ = nullptr>\r\n  class SegmentTree {\r\n  private:\r\n    const int m_size;\r\
    \n    std::vector<Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    int calcSize(int n) const {\r\n      int size = 1;\r\n      while (size\
    \ < n) { size <<= 1; }\r\n      return size;\r\n    }\r\n\r\n    template <class\
    \ Lambda>\r\n    auto _update_op(int itr, Monoid&& val, const Lambda& op) {\r\n\
    \      int i = itr + m_size - 1;\r\n      m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));\r\
    \n      while (i) {\r\n        i = (i - 1) >> 1;\r\n        m_node[i] = m_node[(i\
    \ << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n    }\r\n\r\n\
    \    auto _query(int _l, int _r) const {\r\n      _l = std::max(_l, 0);\r\n  \
    \    _r = std::min(_r, m_size - 1);\r\n      auto l = _l + m_size;\r\n      int\
    \ r = _r + m_size;\r\n      auto lm = Monoid();\r\n      auto rm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          lm = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          ++l;\r\n        }\r\n        if (!(r & 1)) {\r\n       \
    \   rm = m_node[r - 1].binaryOperation(rm);\r\n          --r;\r\n        }\r\n\
    \        l >>= 1, r >>= 1;\r\n      }\r\n      return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    auto _construct(const std::vector<S>& vec) {\r\n      for (unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n      }\r\n      for (int i = m_size - 2; i >= 0; --i) {\r\n        m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n\
    \    }\r\n\r\n  public:\r\n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1) {}\r\n    SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n)\
    \ {\r\n      _construct(vec);\r\n    }\r\n\r\n    template <class Lambda>\r\n\
    \    auto update_op(int itr, Monoid&& val, const Lambda& op) {\r\n      return\
    \ _update_op(itr, std::forward<Monoid>(val), op);\r\n    }\r\n    auto update(int\
    \ itr, Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid&, const Monoid& m2) { return m2; });\r\
    \n    }\r\n    auto add(int itr, Monoid&& val) {\r\n      return update_op(itr,\
    \ std::forward<Monoid>(val),\r\n                       [](const Monoid& m1, const\
    \ Monoid& m2) {\r\n                         return Monoid(m1.m_val + m2.m_val);\r\
    \n                       });\r\n    }\r\n    auto query(int l, int r) const {\
    \ return _query(l, r).m_val; }\r\n    auto query_all() const { return m_node[0].m_val;\
    \ }\r\n\r\n    auto output() const {\r\n      for (int i = 0; i < m_size; ++i)\
    \ {\r\n        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\n  \
    \    std::cout << std::endl;\r\n    }\r\n  };\r\n\r\n  template <class S,    //\
    \ \u8981\u7D20\u306E\u578B\r\n            S element,  // \u5143\r\n          \
    \  class T  // lambda\u306FC++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\u306A\
    \u304B\u3063\u305F\uFF0E\uFF0E\uFF0E\r\n                     // S T(S, S)  //\
    \ 2\u9805\u6F14\u7B97\u5B50\r\n            >\r\n  struct Monoid {\r\n    S m_val;\r\
    \n    Monoid() : m_val(element) {}\r\n    Monoid(S val) : m_val(val) {}\r\n  \
    \  Monoid binaryOperation(const Monoid& m2) const {\r\n      return T()(m_val,\
    \ m2.m_val);\r\n    }\r\n    friend std::ostream& operator<<(std::ostream& os,\r\
    \n                                    const Monoid<S, element, T>& m) {\r\n  \
    \    return os << m.m_val;\r\n    }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2024-11-12 00:26:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/String/LCPArray.test.cpp
  - Test/DataStructure/SegmentTree_RMQ.test.cpp
  - Test/DataStructure/SegmentTree_RSQ.test.cpp
  - Test/Algorithms/CoordinateCompression_comp.test.cpp
  - Test/Algorithms/CoordinateCompression_to.test.cpp
documentation_of: Library/DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/SegmentTree.hpp
- /library/Library/DataStructure/SegmentTree.hpp.html
title: Library/DataStructure/SegmentTree.hpp
---
