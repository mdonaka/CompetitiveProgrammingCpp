---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/1435
    links:
    - https://yukicoder.me/problems/no/1435
  bundledCode: "#line 1 \"Test/DataStructure/SegmentTree_minleft.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1435\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <ranges>\r\n#include <vector>\r\n\r\n// begin:tag\
    \ includes\r\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#include\
    \ <deque>\r\n#line 5 \"Library/DataStructure/SegmentTree.hpp\"\n#include <utility>\r\
    \n#line 7 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#line 2 \"Library/Algebraic/Monoid.hpp\"\
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
    \ <typename T, template <typename, auto, typename> typename S>\n    concept is_monoid_specialization_of\
    \ = requires {\n      typename std::enable_if_t<std::is_same_v<\n          T,\
    \ S<typename T::value_type, T::_element, typename T::op_type>>>;\n    };\n  }\
    \  // namespace __detail\n\n  template <typename M>\n  concept monoid = __detail::is_monoid_specialization_of<M,\
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
    \n      std::cout << std::endl;\r\n    }\r\n  };\r\n\r\n}  // namespace mtd\r\n\
    #line 10 \"Test/DataStructure/SegmentTree_minleft.test.cpp\"\n// end:tag includes\r\
    \n\r\nusing ll = long long;\r\n\r\nstruct T {\r\n  ll min1, min2, max;\r\n  constexpr\
    \ T(ll _min1, ll _min2, ll _max)\r\n      : min1(_min1), min2(_min2), max(_max)\
    \ {}\r\n};\r\nauto op = [](const T& a, const T& b) {\r\n  std::vector<ll> v{a.min1,\
    \ a.min2, b.min1, b.min2};\r\n  std::ranges::sort(v);\r\n  return T(v[0], v[1],\
    \ std::max(a.max, b.max));\r\n};\r\nconstexpr T e{1LL << 60, 1LL << 60, -(1LL\
    \ << 60)};\r\nusing M = mtd::Monoid<T, e, decltype(op)>;\r\n\r\nsigned main()\
    \ {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n;\r\
    \n  std::cin >> n;\r\n  std::vector<ll> a(n);\r\n  for (auto i : std::views::iota(0,\
    \ n)) { std::cin >> a[i]; }\r\n\r\n  auto segtree = mtd::SegmentTree<M>(n);\r\n\
    \  for (auto i : std::views::iota(0, n)) {\r\n    segtree.update(i, T(a[i], 1LL\
    \ << 60, a[i]));\r\n  }\r\n\r\n  ll ans = 0;\r\n  for (auto r : std::views::iota(0,\
    \ n)) {\r\n    auto l = segtree.min_left(r, [](const M& m) {\r\n      auto [min1,\
    \ min2, max] = m.m_val;\r\n      return max <= min1 + min2;\r\n    });\r\n   \
    \ ans += r - l;\r\n  }\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1435\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <ranges>\r\n#include <vector>\r\
    \n\r\n// begin:tag includes\r\n#include \"./../../Library/DataStructure/SegmentTree.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nstruct T {\r\n  ll\
    \ min1, min2, max;\r\n  constexpr T(ll _min1, ll _min2, ll _max)\r\n      : min1(_min1),\
    \ min2(_min2), max(_max) {}\r\n};\r\nauto op = [](const T& a, const T& b) {\r\n\
    \  std::vector<ll> v{a.min1, a.min2, b.min1, b.min2};\r\n  std::ranges::sort(v);\r\
    \n  return T(v[0], v[1], std::max(a.max, b.max));\r\n};\r\nconstexpr T e{1LL <<\
    \ 60, 1LL << 60, -(1LL << 60)};\r\nusing M = mtd::Monoid<T, e, decltype(op)>;\r\
    \n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<ll> a(n);\r\n  for (auto i\
    \ : std::views::iota(0, n)) { std::cin >> a[i]; }\r\n\r\n  auto segtree = mtd::SegmentTree<M>(n);\r\
    \n  for (auto i : std::views::iota(0, n)) {\r\n    segtree.update(i, T(a[i], 1LL\
    \ << 60, a[i]));\r\n  }\r\n\r\n  ll ans = 0;\r\n  for (auto r : std::views::iota(0,\
    \ n)) {\r\n    auto l = segtree.min_left(r, [](const M& m) {\r\n      auto [min1,\
    \ min2, max] = m.m_val;\r\n      return max <= min1 + min2;\r\n    });\r\n   \
    \ ans += r - l;\r\n  }\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/SegmentTree.hpp
  - Library/Algebraic/Monoid.hpp
  isVerificationFile: true
  path: Test/DataStructure/SegmentTree_minleft.test.cpp
  requiredBy: []
  timestamp: '2025-01-23 04:47:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/SegmentTree_minleft.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/SegmentTree_minleft.test.cpp
- /verify/Test/DataStructure/SegmentTree_minleft.test.cpp.html
title: Test/DataStructure/SegmentTree_minleft.test.cpp
---
