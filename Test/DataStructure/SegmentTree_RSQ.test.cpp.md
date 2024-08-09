---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/SegmentTree.hpp
    title: Library/DataStructure/SegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"Test/DataStructure/SegmentTree_RSQ.test.cpp\"\n#define PROBLEM\
    \ \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\r\n#include <deque>\r\n#include <utility>\r\n#include <vector>\r\n\r\ntemplate\
    \ <class T>\r\nclass isMonoid {\r\n  template <class U>\r\n  static auto check(U\
    \ x) -> decltype(x.binaryOperation(x), std::true_type{});\r\n  static std::false_type\
    \ check(...);\r\n\r\npublic:\r\n  static bool const value = decltype(check(std::declval<T>()))::value;\r\
    \n};\r\n\r\ntemplate <class Monoid,\r\n          std::enable_if_t<isMonoid<Monoid>::value,\
    \ std::nullptr_t> = nullptr>\r\nclass SegmentTree {\r\nprivate:\r\n  const int\
    \ m_size;\r\n  std::vector<Monoid> m_node;\r\n  using S = decltype(Monoid().m_val);\r\
    \n\r\n  int calcSize(int n) const {\r\n    int size = 1;\r\n    while (size <\
    \ n) { size <<= 1; }\r\n    return size;\r\n  }\r\n\r\n  template <class Lambda>\r\
    \n  auto _update_op(int itr, Monoid&& val, const Lambda& op) {\r\n    int i =\
    \ itr + m_size - 1;\r\n    m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));\r\
    \n    while (i) {\r\n      i = (i - 1) >> 1;\r\n      m_node[i] = m_node[(i <<\
    \ 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n    }\r\n  }\r\n\r\n  auto\
    \ _query(int _l, int _r) const {\r\n    _l = std::max(_l, 0);\r\n    _r = std::min(_r,\
    \ m_size - 1);\r\n    auto l = _l + m_size;\r\n    int r = _r + m_size;\r\n  \
    \  auto lm = Monoid();\r\n    auto rm = Monoid();\r\n    while (l <= r) {\r\n\
    \      if (l & 1) {\r\n        lm = lm.binaryOperation(m_node[l - 1]);\r\n   \
    \     ++l;\r\n      }\r\n      if (!(r & 1)) {\r\n        rm = m_node[r - 1].binaryOperation(rm);\r\
    \n        --r;\r\n      }\r\n      l >>= 1, r >>= 1;\r\n    }\r\n    return lm.binaryOperation(rm);\r\
    \n  }\r\n\r\n  auto _construct(const std::vector<S>& vec) {\r\n    for (unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n      m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n    }\r\n    for (int i = m_size - 2; i >= 0; --i) {\r\n      m_node[i] = m_node[(i\
    \ << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n    }\r\n  }\r\n\r\npublic:\r\
    \n  SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size << 1) - 1) {}\r\n\
    \  SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n) {\r\n    _construct(vec);\r\
    \n  }\r\n\r\n  template <class Lambda>\r\n  auto update_op(int itr, Monoid&& val,\
    \ const Lambda& op) {\r\n    return _update_op(itr, std::forward<Monoid>(val),\
    \ op);\r\n  }\r\n  auto update(int itr, Monoid&& val) {\r\n    return update_op(itr,\
    \ std::forward<Monoid>(val),\r\n                     [](const Monoid&, const Monoid&\
    \ m2) { return m2; });\r\n  }\r\n  auto add(int itr, Monoid&& val) {\r\n    return\
    \ update_op(itr, std::forward<Monoid>(val),\r\n                     [](const Monoid&\
    \ m1, const Monoid& m2) {\r\n                       return Monoid(m1.m_val + m2.m_val);\r\
    \n                     });\r\n  }\r\n  auto query(int l, int r) const { return\
    \ _query(l, r).m_val; }\r\n  auto query_all() const { return m_node[0].m_val;\
    \ }\r\n\r\n  auto output() const {\r\n    for (int i = 0; i < m_size; ++i) {\r\
    \n      std::cout << m_node[m_size + i - 1] << \" \";\r\n    }\r\n    std::cout\
    \ << std::endl;\r\n  }\r\n};\r\n\r\ntemplate <class S,    // \u8981\u7D20\u306E\
    \u578B\r\n          S element,  // \u5143\r\n          class T  // lambda\u306F\
    C++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\u306A\u304B\u3063\u305F\uFF0E\uFF0E\
    \uFF0E\r\n                   // S T(S, S)  // 2\u9805\u6F14\u7B97\u5B50\r\n  \
    \        >\r\nstruct Monoid {\r\n  S m_val;\r\n  Monoid() : m_val(element) {}\r\
    \n  Monoid(S val) : m_val(val) {}\r\n  Monoid binaryOperation(const Monoid& m2)\
    \ const {\r\n    return T()(m_val, m2.m_val);\r\n  }\r\n  friend std::ostream&\
    \ operator<<(std::ostream& os,\r\n                                  const Monoid<S,\
    \ element, T>& m) {\r\n    return os << m.m_val;\r\n  }\r\n};\r\n#line 7 \"Test/DataStructure/SegmentTree_RSQ.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n, q;\r\n  cin >> n >> q;\r\
    \n\r\n  struct F {\r\n    auto operator()(ll a, ll b) const { return a + b; }\r\
    \n  };\r\n  using M = Monoid<ll, 0, F>;\r\n  auto segtree = SegmentTree<M>(n);\r\
    \n\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int k, x, y;\r\n    cin >> k >> x\
    \ >> y;\r\n    if (k == 0) {\r\n      segtree.add(x - 1, y);\r\n    } else {\r\
    \n      cout << segtree.query(x - 1, y - 1) << endl;\r\n    }\r\n  }\r\n}\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"./../../Library/DataStructure/SegmentTree.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  int n, q;\r\n  cin >> n >> q;\r\
    \n\r\n  struct F {\r\n    auto operator()(ll a, ll b) const { return a + b; }\r\
    \n  };\r\n  using M = Monoid<ll, 0, F>;\r\n  auto segtree = SegmentTree<M>(n);\r\
    \n\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int k, x, y;\r\n    cin >> k >> x\
    \ >> y;\r\n    if (k == 0) {\r\n      segtree.add(x - 1, y);\r\n    } else {\r\
    \n      cout << segtree.query(x - 1, y - 1) << endl;\r\n    }\r\n  }\r\n}"
  dependsOn:
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: Test/DataStructure/SegmentTree_RSQ.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/SegmentTree_RSQ.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/SegmentTree_RSQ.test.cpp
- /verify/Test/DataStructure/SegmentTree_RSQ.test.cpp.html
title: Test/DataStructure/SegmentTree_RSQ.test.cpp
---
