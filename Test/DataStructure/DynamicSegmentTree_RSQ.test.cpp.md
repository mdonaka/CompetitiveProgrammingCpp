---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DynamicSegmentTree.hpp
    title: Library/DataStructure/DynamicSegmentTree.hpp
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
  bundledCode: "#line 1 \"Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp\"\n#define\
    \ PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/DynamicSegmentTree.hpp\"\
    \n\r\n#include <deque>\r\n#include <ostream>\r\n#include <unordered_map>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/Monoid.hpp\"\
    \n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\n\nnamespace mtd {\n\n  template\
    \ <class S,    // set\n            S element,  // identity element\n         \
    \   class op    // binary operation\n            >\n  requires std::is_invocable_r_v<S,\
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
    \ Monoid>;\n\n}  // namespace mtd\n#line 10 \"Library/DataStructure/DynamicSegmentTree.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <monoid Monoid, int size = static_cast<int>(1e9\
    \ + 1)>\r\n  class DynamicSegmentTree {\r\n  private:\r\n    std::unordered_map<int,\
    \ Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\n\r\n    constexpr\
    \ auto _get(int i) const {\r\n      return (m_node.find(i) == m_node.end()) ?\
    \ Monoid() : m_node.at(i);\r\n    }\r\n\r\n    template <class Lambda>\r\n   \
    \ constexpr auto _update_op(int itr, Monoid&& val, const Lambda& op) {\r\n   \
    \   int i = itr + size - 1;\r\n      m_node[i] = op(_get(i), std::forward<decltype(val)>(val));\r\
    \n      while (i) {\r\n        i = (i - 1) >> 1;\r\n        m_node[i] = _get((i\
    \ << 1) | 1).binaryOperation(_get((i + 1) << 1LL));\r\n      }\r\n    }\r\n\r\n\
    \    constexpr auto _query(int _l, int _r) const {\r\n      _l = std::max(_l,\
    \ 0);\r\n      _r = std::min(_r, size - 1);\r\n      auto l = _l + size;\r\n \
    \     int r = _r + size;\r\n      auto lm = Monoid();\r\n      auto rm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          lm = lm.binaryOperation(_get(l\
    \ - 1));\r\n          ++l;\r\n        }\r\n        if (!(r & 1)) {\r\n       \
    \   rm = _get(r - 1).binaryOperation(rm);\r\n          --r;\r\n        }\r\n \
    \       l >>= 1, r >>= 1;\r\n      }\r\n      return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    constexpr auto _construct(const std::vector<S>& vec) {\r\n\
    \      for (unsigned int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + size\
    \ - 1] = Monoid(vec[i]);\r\n      }\r\n      for (int i = size - 2; i >= 0; --i)\
    \ {\r\n        m_node[i] = _get((i << 1) | 1).binaryOperation(_get((i + 1) <<\
    \ 1));\r\n      }\r\n    }\r\n\r\n  public:\r\n    constexpr DynamicSegmentTree()\
    \ {}\r\n\r\n    template <class Lambda>\r\n    constexpr auto update_op(int itr,\
    \ Monoid&& val, const Lambda& op) {\r\n      return _update_op(itr, std::forward<Monoid>(val),\
    \ op);\r\n    }\r\n    constexpr auto update(int itr, Monoid&& val) {\r\n    \
    \  return update_op(itr, std::forward<Monoid>(val),\r\n                      \
    \ [](const Monoid&, const Monoid& m2) { return m2; });\r\n    }\r\n    constexpr\
    \ auto add(int itr, Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid& m1, const Monoid& m2) {\r\n        \
    \                 return Monoid(m1.m_val + m2.m_val);\r\n                    \
    \   });\r\n    }\r\n    constexpr auto query(int l, int r) const { return _query(l,\
    \ r).m_val; }\r\n    constexpr auto query_all() const { return m_node[0].m_val;\
    \ }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 8 \"Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp\"\
    \n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n, q;\r\n\
    \  std::cin >> n >> q;\r\n\r\n  auto op = [](ll a, ll b) { return a + b; };\r\n\
    \  using M = mtd::Monoid<ll, 0, decltype(op)>;\r\n  auto segtree = mtd::DynamicSegmentTree<M>();\r\
    \n\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int k, x, y;\r\n    std::cin >> k\
    \ >> x >> y;\r\n    if (k == 0) {\r\n      segtree.add(x - 1, y);\r\n    } else\
    \ {\r\n      std::cout << segtree.query(x - 1, y - 1) << std::endl;\r\n    }\r\
    \n  }\r\n}\r\n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#include \"./../../Library/DataStructure/DynamicSegmentTree.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n, q;\r\n\
    \  std::cin >> n >> q;\r\n\r\n  auto op = [](ll a, ll b) { return a + b; };\r\n\
    \  using M = mtd::Monoid<ll, 0, decltype(op)>;\r\n  auto segtree = mtd::DynamicSegmentTree<M>();\r\
    \n\r\n  for (int _ = 0; _ < q; ++_) {\r\n    int k, x, y;\r\n    std::cin >> k\
    \ >> x >> y;\r\n    if (k == 0) {\r\n      segtree.add(x - 1, y);\r\n    } else\
    \ {\r\n      std::cout << segtree.query(x - 1, y - 1) << std::endl;\r\n    }\r\
    \n  }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/DynamicSegmentTree.hpp
  - Library/Algebraic/Monoid.hpp
  isVerificationFile: true
  path: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
  requiredBy: []
  timestamp: '2024-12-11 01:55:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
- /verify/Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp.html
title: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
---
