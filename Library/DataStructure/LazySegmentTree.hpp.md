---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
    title: Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/LazySegmentTree.hpp\"\n#include <iostream>\r\
    \n#include <vector>\r\n#include <deque>\r\n#include <utility>\r\n\r\ntemplate<class\
    \ T>\r\nclass isMonoid {\r\n    template <class U>\r\n    static auto check(U\
    \ x) -> decltype(x.binaryOperation(x), std::true_type{});\r\n    static std::false_type\
    \ check(...);\r\npublic:\r\n    static bool const value = decltype(check(std::declval<T>()))::value;\r\
    \n};\r\n\r\ntemplate<\r\n    class Monoid, class MonoidOp, class op,\r\n    std::enable_if_t<isMonoid<Monoid>::value,\
    \ std::nullptr_t> = nullptr,\r\n    std::enable_if_t<isMonoid<MonoidOp>::value,\
    \ std::nullptr_t> = nullptr>\r\nclass LazySegmentTree {\r\nprivate:\r\n\r\n  \
    \  const int m_size;\r\n    std::vector<Monoid> m_node;\r\n    std::vector<MonoidOp>\
    \ m_lazy;\r\n    using S = decltype(Monoid().m_val);\r\n\r\n    int calcSize(int\
    \ n) const { int size = 1; while(size < n) { size <<= 1; }return size; }\r\n\r\
    \n    auto _lazy_update(int i, const MonoidOp& val) {\r\n        if(i >= (m_size\
    \ << 1) - 1) { return; }\r\n        m_lazy[i] = m_lazy[i].binaryOperation(val);\r\
    \n    }\r\n\r\n    auto _propagate(int i) {\r\n        m_node[i] = op()(m_node[i],\
    \ m_lazy[i]);\r\n        _lazy_update((i << 1) + 1, m_lazy[i]);\r\n        _lazy_update((i\
    \ << 1) + 2, m_lazy[i]);\r\n        m_lazy[i] = MonoidOp();\r\n    }\r\n\r\n \
    \   auto _update(int l, int r, int k, int nl, int nr, const MonoidOp& m) {\r\n\
    \        _propagate(k);\r\n        if(nr < l || r < nl) { return; }\r\n      \
    \  if(l <= nl && nr <= r) { _lazy_update(k, m); _propagate(k); return; }\r\n \
    \       _update(l, r, (k << 1) + 1, nl, (nl + nr) >> 1, m);\r\n        _update(l,\
    \ r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr, m);\r\n        m_node[k] = m_node[(k\
    \ << 1) + 1].binaryOperation(m_node[(k << 1) + 2]);\r\n    }\r\n\r\n    auto _query(int\
    \ l, int r, int k, int nl, int nr) {\r\n        _propagate(k);\r\n        if(nr\
    \ < l || r < nl) { return Monoid(); }\r\n        if(l <= nl && nr <= r) { return\
    \ m_node[k]; }\r\n        auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr)\
    \ >> 1);\r\n        auto r_val = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) +\
    \ 1, nr);\r\n        return l_val.binaryOperation(r_val);\r\n    }\r\n\r\n   \
    \ auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned int i =\
    \ 0; i < vec.size(); ++i) {\r\n            m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = m_size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1LL]);\r\n        }\r\
    \n    }\r\npublic:\r\n    LazySegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1), m_lazy((m_size << 1) - 1) {}\r\n    LazySegmentTree(int n, const\
    \ std::vector<S>& vec) :LazySegmentTree(n) { _construct(vec); }\r\n\r\n    auto\
    \ update(int l, int r, const MonoidOp& val) {\r\n        _update(l, r, 0, 0, m_size\
    \ - 1, val);\r\n    }\r\n\r\n    auto query(int l, int r) {\r\n        return\
    \ _query(l, r, 0, 0, m_size - 1).m_val;\r\n    }\r\n\r\n    auto output() {\r\n\
    \        for(int i = 0; i < (m_size << 1) - 1; ++i) { _propagate(i); }\r\n   \
    \     for(int i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] <<\
    \ \" \"; }\r\n        std::cout << std::endl;\r\n    }\r\n\r\n};\r\n\r\ntemplate<\r\
    \n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S& element, // \u5143\r\n\
    \    class T // 2\u9805\u6F14\u7B97\u306EFunctor\r\n>\r\nstruct Monoid {\r\n \
    \   S m_val;\r\n    Monoid() :m_val(element) {}\r\n    Monoid(S val) :m_val(val)\
    \ {}\r\n    Monoid  binaryOperation(const Monoid& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n    }\r\n};\r\
    \n\r\n/*\r\n\u5404\u7A2E\u983B\u51FA\u30B5\u30F3\u30D7\u30EB\r\nex) \u533A\u9593\
    \u6700\u5C0F\u5024\uFF0C\u533A\u9593\u66F4\u65B0\r\nLazySegmentTree<M_M, M_U,\
    \ OP_RUQ_RMQ>\r\n*/\r\n//---- \u8981\u7D20 ----\r\nstd::pair<long long, long long>\
    \ base_s{0,0};\r\nstruct F_RSQ {\r\n    auto operator()(const std::pair<long long,\
    \ long long>& a, const std::pair<long long, long long>& b)const {\r\n        return\
    \ std::pair<long long, long long>{a.first + b.first, a.second + b.second};\r\n\
    \    }\r\n};\r\nusing M_S = Monoid<std::pair<long long, long long>, base_s, F_RSQ>;\r\
    \n\r\nlong long base_m{static_cast<long long>(1e18)};\r\nstruct F_RMQ {\r\n  \
    \  auto operator()(long long a, long long b)const {\r\n        return std::min(a,\
    \ b);\r\n    }\r\n};\r\nusing M_M = Monoid<long long, base_m, F_RMQ>;\r\n\r\n\
    //---- \u4F5C\u7528\u7D20 ----\r\nlong long base_u{static_cast<long long>(-1e18)};\r\
    \nstruct F_RUQ {\r\n    auto operator()(long long a, long long b)const {\r\n \
    \       if(b == base_u) { return a; }\r\n        return b;\r\n    }\r\n};\r\n\
    using M_U = Monoid<long long, base_u, F_RUQ>;\r\n\r\nlong long base_a{static_cast<long\
    \ long>(0)};\r\nstruct F_RAQ {\r\n    auto operator()(long long a, long long b)const\
    \ {\r\n        return a + b;\r\n    }\r\n};\r\nusing M_A = Monoid<long long, base_a,\
    \ F_RAQ>;\r\n\r\n//---- \u4F5C\u7528 ----\r\nstruct OP_RUQ_RSQ {\r\n    auto operator()(const\
    \ M_S& m, const M_U& m2) {\r\n        if(m2.m_val == base_u) { return m; }\r\n\
    \        return M_S(std::pair<long long, long long>{m.m_val.second* m2.m_val,\
    \ m.m_val.second});\r\n    }\r\n};\r\nstruct OP_RUQ_RMQ {\r\n    auto operator()(const\
    \ M_M& m, const M_U& m2) {\r\n        if(m2.m_val == base_u) { return m; }\r\n\
    \        return M_M(m2.m_val);\r\n    }\r\n};\r\nstruct OP_RAQ_RSQ {\r\n    auto\
    \ operator()(const M_S& m, const M_A& m2) {\r\n        return M_S(std::pair<long\
    \ long, long long>{m.m_val.first + m.m_val.second * m2.m_val, m.m_val.second});\r\
    \n    }\r\n};\r\nstruct OP_RAQ_RMQ {\r\n    auto operator()(const M_M& m, const\
    \ M_A& m2) {\r\n        return M_M{m.m_val + m2.m_val};\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n#include <iostream>\r\n#include <vector>\r\n#include <deque>\r\
    \n#include <utility>\r\n\r\ntemplate<class T>\r\nclass isMonoid {\r\n    template\
    \ <class U>\r\n    static auto check(U x) -> decltype(x.binaryOperation(x), std::true_type{});\r\
    \n    static std::false_type check(...);\r\npublic:\r\n    static bool const value\
    \ = decltype(check(std::declval<T>()))::value;\r\n};\r\n\r\ntemplate<\r\n    class\
    \ Monoid, class MonoidOp, class op,\r\n    std::enable_if_t<isMonoid<Monoid>::value,\
    \ std::nullptr_t> = nullptr,\r\n    std::enable_if_t<isMonoid<MonoidOp>::value,\
    \ std::nullptr_t> = nullptr>\r\nclass LazySegmentTree {\r\nprivate:\r\n\r\n  \
    \  const int m_size;\r\n    std::vector<Monoid> m_node;\r\n    std::vector<MonoidOp>\
    \ m_lazy;\r\n    using S = decltype(Monoid().m_val);\r\n\r\n    int calcSize(int\
    \ n) const { int size = 1; while(size < n) { size <<= 1; }return size; }\r\n\r\
    \n    auto _lazy_update(int i, const MonoidOp& val) {\r\n        if(i >= (m_size\
    \ << 1) - 1) { return; }\r\n        m_lazy[i] = m_lazy[i].binaryOperation(val);\r\
    \n    }\r\n\r\n    auto _propagate(int i) {\r\n        m_node[i] = op()(m_node[i],\
    \ m_lazy[i]);\r\n        _lazy_update((i << 1) + 1, m_lazy[i]);\r\n        _lazy_update((i\
    \ << 1) + 2, m_lazy[i]);\r\n        m_lazy[i] = MonoidOp();\r\n    }\r\n\r\n \
    \   auto _update(int l, int r, int k, int nl, int nr, const MonoidOp& m) {\r\n\
    \        _propagate(k);\r\n        if(nr < l || r < nl) { return; }\r\n      \
    \  if(l <= nl && nr <= r) { _lazy_update(k, m); _propagate(k); return; }\r\n \
    \       _update(l, r, (k << 1) + 1, nl, (nl + nr) >> 1, m);\r\n        _update(l,\
    \ r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr, m);\r\n        m_node[k] = m_node[(k\
    \ << 1) + 1].binaryOperation(m_node[(k << 1) + 2]);\r\n    }\r\n\r\n    auto _query(int\
    \ l, int r, int k, int nl, int nr) {\r\n        _propagate(k);\r\n        if(nr\
    \ < l || r < nl) { return Monoid(); }\r\n        if(l <= nl && nr <= r) { return\
    \ m_node[k]; }\r\n        auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr)\
    \ >> 1);\r\n        auto r_val = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) +\
    \ 1, nr);\r\n        return l_val.binaryOperation(r_val);\r\n    }\r\n\r\n   \
    \ auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned int i =\
    \ 0; i < vec.size(); ++i) {\r\n            m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = m_size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1LL]);\r\n        }\r\
    \n    }\r\npublic:\r\n    LazySegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1), m_lazy((m_size << 1) - 1) {}\r\n    LazySegmentTree(int n, const\
    \ std::vector<S>& vec) :LazySegmentTree(n) { _construct(vec); }\r\n\r\n    auto\
    \ update(int l, int r, const MonoidOp& val) {\r\n        _update(l, r, 0, 0, m_size\
    \ - 1, val);\r\n    }\r\n\r\n    auto query(int l, int r) {\r\n        return\
    \ _query(l, r, 0, 0, m_size - 1).m_val;\r\n    }\r\n\r\n    auto output() {\r\n\
    \        for(int i = 0; i < (m_size << 1) - 1; ++i) { _propagate(i); }\r\n   \
    \     for(int i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] <<\
    \ \" \"; }\r\n        std::cout << std::endl;\r\n    }\r\n\r\n};\r\n\r\ntemplate<\r\
    \n    class S,   // \u8981\u7D20\u306E\u578B\r\n    S& element, // \u5143\r\n\
    \    class T // 2\u9805\u6F14\u7B97\u306EFunctor\r\n>\r\nstruct Monoid {\r\n \
    \   S m_val;\r\n    Monoid() :m_val(element) {}\r\n    Monoid(S val) :m_val(val)\
    \ {}\r\n    Monoid  binaryOperation(const Monoid& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n    }\r\n};\r\
    \n\r\n/*\r\n\u5404\u7A2E\u983B\u51FA\u30B5\u30F3\u30D7\u30EB\r\nex) \u533A\u9593\
    \u6700\u5C0F\u5024\uFF0C\u533A\u9593\u66F4\u65B0\r\nLazySegmentTree<M_M, M_U,\
    \ OP_RUQ_RMQ>\r\n*/\r\n//---- \u8981\u7D20 ----\r\nstd::pair<long long, long long>\
    \ base_s{0,0};\r\nstruct F_RSQ {\r\n    auto operator()(const std::pair<long long,\
    \ long long>& a, const std::pair<long long, long long>& b)const {\r\n        return\
    \ std::pair<long long, long long>{a.first + b.first, a.second + b.second};\r\n\
    \    }\r\n};\r\nusing M_S = Monoid<std::pair<long long, long long>, base_s, F_RSQ>;\r\
    \n\r\nlong long base_m{static_cast<long long>(1e18)};\r\nstruct F_RMQ {\r\n  \
    \  auto operator()(long long a, long long b)const {\r\n        return std::min(a,\
    \ b);\r\n    }\r\n};\r\nusing M_M = Monoid<long long, base_m, F_RMQ>;\r\n\r\n\
    //---- \u4F5C\u7528\u7D20 ----\r\nlong long base_u{static_cast<long long>(-1e18)};\r\
    \nstruct F_RUQ {\r\n    auto operator()(long long a, long long b)const {\r\n \
    \       if(b == base_u) { return a; }\r\n        return b;\r\n    }\r\n};\r\n\
    using M_U = Monoid<long long, base_u, F_RUQ>;\r\n\r\nlong long base_a{static_cast<long\
    \ long>(0)};\r\nstruct F_RAQ {\r\n    auto operator()(long long a, long long b)const\
    \ {\r\n        return a + b;\r\n    }\r\n};\r\nusing M_A = Monoid<long long, base_a,\
    \ F_RAQ>;\r\n\r\n//---- \u4F5C\u7528 ----\r\nstruct OP_RUQ_RSQ {\r\n    auto operator()(const\
    \ M_S& m, const M_U& m2) {\r\n        if(m2.m_val == base_u) { return m; }\r\n\
    \        return M_S(std::pair<long long, long long>{m.m_val.second* m2.m_val,\
    \ m.m_val.second});\r\n    }\r\n};\r\nstruct OP_RUQ_RMQ {\r\n    auto operator()(const\
    \ M_M& m, const M_U& m2) {\r\n        if(m2.m_val == base_u) { return m; }\r\n\
    \        return M_M(m2.m_val);\r\n    }\r\n};\r\nstruct OP_RAQ_RSQ {\r\n    auto\
    \ operator()(const M_S& m, const M_A& m2) {\r\n        return M_S(std::pair<long\
    \ long, long long>{m.m_val.first + m.m_val.second * m2.m_val, m.m_val.second});\r\
    \n    }\r\n};\r\nstruct OP_RAQ_RMQ {\r\n    auto operator()(const M_M& m, const\
    \ M_A& m2) {\r\n        return M_M{m.m_val + m2.m_val};\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2023-04-08 05:34:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/LazySegmentTree_RUQRSQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RAQRMQ.test.cpp
  - Test/DataStructure/LazySegmentTree_RUQRMQ.test.cpp
  - Test/Graph/Tree/HeavyLightDecomposition_edge.test.cpp
documentation_of: Library/DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/LazySegmentTree.hpp
- /library/Library/DataStructure/LazySegmentTree.hpp.html
title: Library/DataStructure/LazySegmentTree.hpp
---
