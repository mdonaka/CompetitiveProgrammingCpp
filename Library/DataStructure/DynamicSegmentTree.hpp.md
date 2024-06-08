---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicSegmentTree.test.cpp
    title: Test/DataStructure/DynamicSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicSegmentTree_RMQ.test.cpp
    title: Test/DataStructure/DynamicSegmentTree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
    title: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/DynamicSegmentTree.hpp\"\n\r\n#include\
    \ <vector>\r\n#include <deque>\r\n#include <utility>\r\n#include <unordered_map>\r\
    \n\r\ntemplate<class T>\r\nclass isMonoid {\r\n    template <class U>\r\n    static\
    \ auto check(U x) -> decltype(x.binaryOperation(x), std::true_type{});\r\n   \
    \ static std::false_type check(...);\r\npublic:\r\n    static bool const value\
    \ = decltype(check(std::declval<T>()))::value;\r\n};\r\n\r\ntemplate<class Monoid,\
    \ int size = static_cast<int>(1e9 + 1), std::enable_if_t<isMonoid<Monoid>::value,\
    \ std::nullptr_t> = nullptr>\r\nclass DynamicSegmentTree {\r\nprivate:\r\n   \
    \ std::unordered_map<int, Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    auto _get(int i)const { return (m_node.find(i) == m_node.end()) ? Monoid()\
    \ : m_node.at(i); }\r\n\r\n    template<class Lambda>\r\n    auto _update_op(int\
    \ itr, Monoid&& val, const Lambda& op) {\r\n        int i = itr + size - 1;\r\n\
    \        m_node[i] = op(_get(i), std::forward<decltype(val)>(val));\r\n      \
    \  while(i) {\r\n            i = (i - 1) >> 1;\r\n            m_node[i] = _get((i\
    \ << 1) | 1).binaryOperation(_get((i + 1) << 1LL));\r\n        }\r\n    }\r\n\r\
    \n    auto _query(int _l, int _r) const {\r\n        _l = std::max(_l, 0); _r\
    \ = std::min(_r, size - 1);\r\n        auto l = _l + size;\r\n        int r =\
    \ _r + size;\r\n        auto lm = Monoid();\r\n        auto rm = Monoid();\r\n\
    \        while(l <= r) {\r\n            if(l & 1) { lm = lm.binaryOperation(_get(l\
    \ - 1)); ++l; }\r\n            if(!(r & 1)) { rm = _get(r - 1).binaryOperation(rm);\
    \ --r; }\r\n            l >>= 1, r >>= 1;\r\n        }\r\n        return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n            m_node[i + size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = _get((i << 1) | 1).binaryOperation(_get((i + 1) << 1));\r\n        }\r\n \
    \   }\r\npublic:\r\n    DynamicSegmentTree() {}\r\n\r\n    template<class Lambda>\r\
    \n    auto update_op(int itr, Monoid&& val, const Lambda& op) { return _update_op(itr,\
    \ std::forward<Monoid>(val), op); }\r\n    auto update(int itr, Monoid&& val)\
    \ { return update_op(itr, std::forward<Monoid>(val), [](const Monoid&, const Monoid&\
    \ m2) {return m2; }); }\r\n    auto add(int itr, Monoid&& val) { return update_op(itr,\
    \ std::forward<Monoid>(val), [](const Monoid& m1, const Monoid& m2) {return Monoid(m1.m_val\
    \ + m2.m_val); }); }\r\n    auto query(int l, int r)const { return _query(l, r).m_val;\
    \ }\r\n    auto query_all()const { return m_node[0].m_val; }\r\n};\r\n\r\n\r\n\
    template<\r\n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S element, // \u5143\
    \r\n    class T // lambda\u306FC++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\
    \u306A\u304B\u3063\u305F\uFF0E\uFF0E\uFF0E\r\n    // S T(S, S)  // 2\u9805\u6F14\
    \u7B97\u5B50\r\n>\r\nstruct Monoid {\r\n    S m_val;\r\n    Monoid() :m_val(element)\
    \ {}\r\n    Monoid(S val) :m_val(val) {}\r\n    Monoid binaryOperation(const Monoid&\
    \ m2)const { return T()(m_val, m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n \
    \   }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <deque>\r\n#include <utility>\r\
    \n#include <unordered_map>\r\n\r\ntemplate<class T>\r\nclass isMonoid {\r\n  \
    \  template <class U>\r\n    static auto check(U x) -> decltype(x.binaryOperation(x),\
    \ std::true_type{});\r\n    static std::false_type check(...);\r\npublic:\r\n\
    \    static bool const value = decltype(check(std::declval<T>()))::value;\r\n\
    };\r\n\r\ntemplate<class Monoid, int size = static_cast<int>(1e9 + 1), std::enable_if_t<isMonoid<Monoid>::value,\
    \ std::nullptr_t> = nullptr>\r\nclass DynamicSegmentTree {\r\nprivate:\r\n   \
    \ std::unordered_map<int, Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    auto _get(int i)const { return (m_node.find(i) == m_node.end()) ? Monoid()\
    \ : m_node.at(i); }\r\n\r\n    template<class Lambda>\r\n    auto _update_op(int\
    \ itr, Monoid&& val, const Lambda& op) {\r\n        int i = itr + size - 1;\r\n\
    \        m_node[i] = op(_get(i), std::forward<decltype(val)>(val));\r\n      \
    \  while(i) {\r\n            i = (i - 1) >> 1;\r\n            m_node[i] = _get((i\
    \ << 1) | 1).binaryOperation(_get((i + 1) << 1LL));\r\n        }\r\n    }\r\n\r\
    \n    auto _query(int _l, int _r) const {\r\n        _l = std::max(_l, 0); _r\
    \ = std::min(_r, size - 1);\r\n        auto l = _l + size;\r\n        int r =\
    \ _r + size;\r\n        auto lm = Monoid();\r\n        auto rm = Monoid();\r\n\
    \        while(l <= r) {\r\n            if(l & 1) { lm = lm.binaryOperation(_get(l\
    \ - 1)); ++l; }\r\n            if(!(r & 1)) { rm = _get(r - 1).binaryOperation(rm);\
    \ --r; }\r\n            l >>= 1, r >>= 1;\r\n        }\r\n        return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n            m_node[i + size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = _get((i << 1) | 1).binaryOperation(_get((i + 1) << 1));\r\n        }\r\n \
    \   }\r\npublic:\r\n    DynamicSegmentTree() {}\r\n\r\n    template<class Lambda>\r\
    \n    auto update_op(int itr, Monoid&& val, const Lambda& op) { return _update_op(itr,\
    \ std::forward<Monoid>(val), op); }\r\n    auto update(int itr, Monoid&& val)\
    \ { return update_op(itr, std::forward<Monoid>(val), [](const Monoid&, const Monoid&\
    \ m2) {return m2; }); }\r\n    auto add(int itr, Monoid&& val) { return update_op(itr,\
    \ std::forward<Monoid>(val), [](const Monoid& m1, const Monoid& m2) {return Monoid(m1.m_val\
    \ + m2.m_val); }); }\r\n    auto query(int l, int r)const { return _query(l, r).m_val;\
    \ }\r\n    auto query_all()const { return m_node[0].m_val; }\r\n};\r\n\r\n\r\n\
    template<\r\n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S element, // \u5143\
    \r\n    class T // lambda\u306FC++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\
    \u306A\u304B\u3063\u305F\uFF0E\uFF0E\uFF0E\r\n    // S T(S, S)  // 2\u9805\u6F14\
    \u7B97\u5B50\r\n>\r\nstruct Monoid {\r\n    S m_val;\r\n    Monoid() :m_val(element)\
    \ {}\r\n    Monoid(S val) :m_val(val) {}\r\n    Monoid binaryOperation(const Monoid&\
    \ m2)const { return T()(m_val, m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n \
    \   }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/DynamicSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-07-22 05:28:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/DynamicSegmentTree_RMQ.test.cpp
  - Test/DataStructure/DynamicSegmentTree.test.cpp
  - Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
documentation_of: Library/DataStructure/DynamicSegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/DynamicSegmentTree.hpp
- /library/Library/DataStructure/DynamicSegmentTree.hpp.html
title: Library/DataStructure/DynamicSegmentTree.hpp
---
