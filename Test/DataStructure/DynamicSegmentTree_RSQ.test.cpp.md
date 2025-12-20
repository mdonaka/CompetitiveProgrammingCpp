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
    \n\r\n#include <memory>\r\n#include <ostream>\r\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"Library/Algebraic/Monoid.hpp\"\n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\
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
    \ Monoid>;\n\n}  // namespace mtd\n#line 9 \"Library/DataStructure/DynamicSegmentTree.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <monoid Monoid, int size = static_cast<int>(1e9\
    \ + 1)>\r\n  class DynamicSegmentTree {\r\n  private:\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    struct Node {\r\n      Monoid val;\r\n      std::unique_ptr<Node> left;\r\
    \n      std::unique_ptr<Node> right;\r\n      Node() : val(Monoid()), left(nullptr),\
    \ right(nullptr) {}\r\n      explicit Node(const Monoid& v) : val(v), left(nullptr),\
    \ right(nullptr) {}\r\n    };\r\n\r\n    std::unique_ptr<Node> m_root;\r\n\r\n\
    \    template <class Lambda>\r\n    constexpr void _update_op(std::unique_ptr<Node>&\
    \ node, int l, int r, int pos,\r\n                               Monoid&& val,\
    \ const Lambda& op) {\r\n      if (!node) node = std::make_unique<Node>();\r\n\
    \      if (r - l == 1) {\r\n        node->val = op(node->val, std::forward<Monoid>(val));\r\
    \n        return;\r\n      }\r\n      int mid = l + (r - l) / 2;\r\n      if (pos\
    \ < mid) {\r\n        _update_op(node->left, l, mid, pos, std::forward<Monoid>(val),\
    \ op);\r\n      } else {\r\n        _update_op(node->right, mid, r, pos, std::forward<Monoid>(val),\
    \ op);\r\n      }\r\n      Monoid left_val = node->left ? node->left->val : Monoid();\r\
    \n      Monoid right_val = node->right ? node->right->val : Monoid();\r\n    \
    \  node->val = left_val.binaryOperation(right_val);\r\n    }\r\n\r\n    constexpr\
    \ Monoid _query(const std::unique_ptr<Node>& node, int l, int r,\r\n         \
    \                   int ql, int qr) const {\r\n      if (!node || r <= ql || qr\
    \ <= l) return Monoid();\r\n      if (ql <= l && r <= qr) return node->val;\r\n\
    \      int mid = l + (r - l) / 2;\r\n      return _query(node->left, l, mid, ql,\
    \ qr)\r\n          .binaryOperation(_query(node->right, mid, r, ql, qr));\r\n\
    \    }\r\n\r\n  public:\r\n    constexpr DynamicSegmentTree() : m_root(nullptr)\
    \ {}\r\n\r\n    template <class Lambda>\r\n    constexpr auto update_op(int pos,\
    \ Monoid&& val, const Lambda& op) {\r\n      return _update_op(m_root, 0, size,\
    \ pos, std::forward<Monoid>(val), op);\r\n    }\r\n\r\n    constexpr auto update(int\
    \ pos, Monoid&& val) {\r\n      return update_op(pos, std::forward<Monoid>(val),\r\
    \n                       [](const Monoid&, const Monoid& m2) { return m2; });\r\
    \n    }\r\n\r\n    constexpr auto add(int pos, Monoid&& val) {\r\n      return\
    \ update_op(pos, std::forward<Monoid>(val),\r\n                       [](const\
    \ Monoid& m1, const Monoid& m2) {\r\n                         return Monoid(m1.m_val\
    \ + m2.m_val);\r\n                       });\r\n    }\r\n\r\n    constexpr auto\
    \ query(int l, int r) const {\r\n      if (l > r) return Monoid().m_val;\r\n \
    \     return _query(m_root, 0, size, l, r + 1).m_val;\r\n    }\r\n\r\n    constexpr\
    \ auto query_all() const {\r\n      return m_root ? m_root->val.m_val : Monoid().m_val;\r\
    \n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 8 \"Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp\"\
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
  timestamp: '2025-12-20 16:12:20+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
- /verify/Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp.html
title: Test/DataStructure/DynamicSegmentTree_RSQ.test.cpp
---
