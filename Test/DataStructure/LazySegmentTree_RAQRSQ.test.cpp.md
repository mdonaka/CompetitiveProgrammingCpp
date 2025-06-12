---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/LazySegmentTree.hpp
    title: Library/DataStructure/LazySegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp\"\n#define\
    \ PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n\r\n#include <deque>\r\n#line 5 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/Monoid.hpp\"\
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
    \ Monoid>;\n\n}  // namespace mtd\n#line 9 \"Library/DataStructure/LazySegmentTree.hpp\"\
    \n\r\nnamespace mtd {\r\n  template <monoid Monoid, monoid MonoidOp, class op>\r\
    \n  class LazySegmentTree {\r\n  private:\r\n    const int m_size;\r\n    std::vector<Monoid>\
    \ m_node;\r\n    std::vector<MonoidOp> m_lazy;\r\n    using S = decltype(Monoid().m_val);\r\
    \n\r\n    constexpr int calcSize(int n) const {\r\n      int size = 1;\r\n   \
    \   while (size < n) { size <<= 1; }\r\n      return size;\r\n    }\r\n\r\n  \
    \  constexpr auto _lazy_update(int i, const MonoidOp& val) {\r\n      if (i >=\
    \ (m_size << 1) - 1) { return; }\r\n      m_lazy[i] = m_lazy[i].binaryOperation(val);\r\
    \n    }\r\n\r\n    constexpr auto _propagate(int i) {\r\n      m_node[i] = op()(m_node[i],\
    \ m_lazy[i]);\r\n      _lazy_update((i << 1) + 1, m_lazy[i]);\r\n      _lazy_update((i\
    \ << 1) + 2, m_lazy[i]);\r\n      m_lazy[i] = MonoidOp();\r\n    }\r\n\r\n   \
    \ constexpr auto _update(int l, int r, int k, int nl, int nr,\r\n            \
    \               const MonoidOp& m) {\r\n      _propagate(k);\r\n      if (nr <\
    \ l || r < nl) { return; }\r\n      if (l <= nl && nr <= r) {\r\n        _lazy_update(k,\
    \ m);\r\n        _propagate(k);\r\n        return;\r\n      }\r\n      _update(l,\
    \ r, (k << 1) + 1, nl, (nl + nr) >> 1, m);\r\n      _update(l, r, (k << 1) + 2,\
    \ ((nl + nr) >> 1) + 1, nr, m);\r\n      m_node[k] = m_node[(k << 1) + 1].binaryOperation(m_node[(k\
    \ << 1) + 2]);\r\n    }\r\n\r\n    constexpr auto _query(int l, int r, int k,\
    \ int nl, int nr) {\r\n      _propagate(k);\r\n      if (nr < l || r < nl) { return\
    \ Monoid(); }\r\n      if (l <= nl && nr <= r) { return m_node[k]; }\r\n     \
    \ auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr) >> 1);\r\n      auto r_val\
    \ = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr);\r\n      return l_val.binaryOperation(r_val);\r\
    \n    }\r\n\r\n    constexpr auto _construct(const std::vector<S>& vec) {\r\n\
    \      for (unsigned int i = 0; i < vec.size(); ++i) {\r\n        m_node[i + m_size\
    \ - 1] = Monoid(vec[i]);\r\n      }\r\n      for (int i = m_size - 2; i >= 0;\
    \ --i) {\r\n        m_node[i] =\r\n            m_node[(i << 1) | 1].binaryOperation(m_node[(i\
    \ + 1) << 1LL]);\r\n      }\r\n    }\r\n\r\n  public:\r\n    constexpr LazySegmentTree(int\
    \ n)\r\n        : m_size(calcSize(n)),\r\n          m_node((m_size << 1) - 1),\r\
    \n          m_lazy((m_size << 1) - 1) {}\r\n    constexpr LazySegmentTree(int\
    \ n, const std::vector<S>& vec)\r\n        : LazySegmentTree(n) {\r\n      _construct(vec);\r\
    \n    }\r\n\r\n    constexpr auto update(int l, int r, const MonoidOp& val) {\r\
    \n      _update(l, r, 0, 0, m_size - 1, val);\r\n    }\r\n\r\n    constexpr auto\
    \ query(int l, int r) {\r\n      return _query(l, r, 0, 0, m_size - 1).m_val;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5927\
    \u306Er\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto max_right(int _l, const F& judge) {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.max_right.judge(e) must\
    \ be true\");\r\n      }\r\n      query(_l, m_size - 1);\r\n      auto l = std::max(_l,\
    \ 0) + m_size;\r\n      auto r = 2 * m_size - 1;\r\n      auto lm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) {\r\n          auto next = lm.binaryOperation(m_node[l\
    \ - 1]);\r\n          if (!judge(next)) {\r\n            auto itr = l;\r\n   \
    \         while (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n   \
    \           auto ritr = 2 * itr + 1;\r\n              _propagate(itr - 1);\r\n\
    \              _propagate(litr - 1);\r\n              auto lval = lm.binaryOperation(m_node[litr\
    \ - 1]);\r\n              if (!judge(lval)) {\r\n                itr = litr;\r\
    \n              } else {\r\n                itr = ritr;\r\n                std::swap(lm,\
    \ lval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ - 1;\r\n          }\r\n          std::swap(lm, next);\r\n          ++l;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return m_size - 1;\r\
    \n    }\r\n\r\n    /*\r\n     * f([l, r]) = true \u3068\u306A\u308B\u6700\u5C0F\
    \u306El\r\n     * judge: (Monoid) -> bool\r\n     **/\r\n    template <class F>\r\
    \n    constexpr auto min_left(int _r, const F& judge) {\r\n      if (!judge(Monoid()))\
    \ {\r\n        throw std::runtime_error(\"SegmentTree.min_left.judge(e) must be\
    \ true\");\r\n      }\r\n      query(0, _r);\r\n      auto l = m_size;\r\n   \
    \   auto r = std::min(_r, m_size - 1) + m_size;\r\n      auto rm = Monoid();\r\
    \n      while (l <= r) {\r\n        if (l & 1) { ++l; }\r\n        if (!(r & 1)\
    \ || (_r == m_size - 1 && r == 1)) {\r\n          auto next = m_node[r - 1].binaryOperation(rm);\r\
    \n          if (!judge(next)) {\r\n            auto itr = r;\r\n            while\
    \ (itr < m_size) {\r\n              auto litr = 2 * itr;\r\n              auto\
    \ ritr = 2 * itr + 1;\r\n              _propagate(itr - 1);\r\n              _propagate(ritr\
    \ - 1);\r\n              auto rval = m_node[ritr - 1].binaryOperation(rm);\r\n\
    \              if (!judge(rval)) {\r\n                itr = ritr;\r\n        \
    \      } else {\r\n                itr = litr;\r\n                std::swap(rm,\
    \ rval);\r\n              }\r\n            }\r\n            return itr - m_size\
    \ + 1;\r\n          }\r\n          std::swap(rm, next);\r\n          --r;\r\n\
    \        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n      return 0;\r\n    }\r\
    \n\r\n    constexpr auto debug() {\r\n      for (int i = 0; i < (m_size << 1)\
    \ - 1; ++i) { _propagate(i); }\r\n      for (int i = 0; i < m_size; ++i) {\r\n\
    \        std::cout << m_node[m_size + i - 1] << \" \";\r\n      }\r\n      std::cout\
    \ << std::endl;\r\n    }\r\n  };\r\n\r\n  namespace type {\r\n    /* \u5404\u7A2E\
    \u983B\u51FA\u30B5\u30F3\u30D7\u30EB */\r\n    using P = std::pair<long long,\
    \ long long>;\r\n    constexpr long long update_element = -1e18;\r\n\r\n    /*----\
    \ \u8981\u7D20 ----*/\r\n    using M_SUM = Monoid<P, P{0, 0}, decltype([](const\
    \ P& a, const P& b) {\r\n                           return P{a.first + b.first,\
    \ a.second + b.second};\r\n                         })>;\r\n    using M_MIN =\
    \ Monoid<long long, static_cast<long long>(1e18),\r\n                        \
    \ decltype([](long long a, long long b) {\r\n                           return\
    \ std::min(a, b);\r\n                         })>;\r\n    using M_MAX = Monoid<long\
    \ long, static_cast<long long>(-1e18),\r\n                         decltype([](long\
    \ long a, long long b) {\r\n                           return std::max(a, b);\r\
    \n                         })>;\r\n    /*---- \u4F5C\u7528\u7D20 ----*/\r\n  \
    \  using M_UP = Monoid<long long, update_element,\r\n                        decltype([](long\
    \ long a, long long b) {\r\n                          if (b == update_element)\
    \ { return a; }\r\n                          return b;\r\n                   \
    \     })>;\r\n    using M_ADD =\r\n        Monoid<long long, static_cast<long\
    \ long>(0),\r\n               decltype([](long long a, long long b) { return a\
    \ + b; })>;\r\n\r\n    /*---- \u4F5C\u7528 ----*/\r\n    using OP_SUM_UP = decltype([](const\
    \ M_SUM& m, const M_UP& m2) {\r\n      if (m2.m_val == update_element) { return\
    \ m; }\r\n      return M_SUM(P{m.m_val.second * m2.m_val, m.m_val.second});\r\n\
    \    });\r\n    using OP_MIN_UP = decltype([](const M_MIN& m, const M_UP& m2)\
    \ {\r\n      if (m2.m_val == update_element) { return m; }\r\n      return M_MIN(m2.m_val);\r\
    \n    });\r\n    using OP_MAX_UP = decltype([](const M_MAX& m, const M_UP& m2)\
    \ {\r\n      if (m2.m_val == update_element) { return m; }\r\n      return M_MAX(m2.m_val);\r\
    \n    });\r\n    using OP_SUM_ADD = decltype([](const M_SUM& m, const M_ADD& m2)\
    \ {\r\n      return M_SUM(\r\n          P{m.m_val.first + m.m_val.second * m2.m_val,\
    \ m.m_val.second});\r\n    });\r\n    using OP_MIN_ADD = decltype([](const M_MIN&\
    \ m, const M_ADD& m2) {\r\n      return M_MIN{m.m_val + m2.m_val};\r\n    });\r\
    \n    using OP_MAX_ADD = decltype([](const M_MAX& m, const M_ADD& m2) {\r\n  \
    \    return M_MAX{m.m_val + m2.m_val};\r\n    });\r\n\r\n  }  // namespace type\r\
    \n}  // namespace mtd\r\n#line 8 \"Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp\"\
    \n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n, q;\r\n\
    \  std::cin >> n >> q;\r\n\r\n  std::vector<std::pair<long long, long long>> v(n,\
    \ {0, 1});\r\n  auto segtree = mtd::LazySegmentTree<mtd::type::M_SUM, mtd::type::M_ADD,\r\
    \n                                      mtd::type::OP_SUM_ADD>(n, v);\r\n\r\n\
    \  for (int _ = 0; _ < q; ++_) {\r\n    int k;\r\n    std::cin >> k;\r\n    if\
    \ (k == 0) {\r\n      int s, t, x;\r\n      std::cin >> s >> t >> x;\r\n     \
    \ --s;\r\n      --t;\r\n      segtree.update(s, t, x);\r\n    } else {\r\n   \
    \   int s, t;\r\n      std::cin >> s >> t;\r\n      --s;\r\n      --t;\r\n   \
    \   std::cout << segtree.query(s, t).first << std::endl;\r\n    }\r\n  }\r\n}\r\
    \n"
  code: "#define PROBLEM \\\r\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \r\n\r\n#include <iostream>\r\n\r\n// begin:tag includes\r\n#include \"./../../Library/DataStructure/LazySegmentTree.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  int n, q;\r\n\
    \  std::cin >> n >> q;\r\n\r\n  std::vector<std::pair<long long, long long>> v(n,\
    \ {0, 1});\r\n  auto segtree = mtd::LazySegmentTree<mtd::type::M_SUM, mtd::type::M_ADD,\r\
    \n                                      mtd::type::OP_SUM_ADD>(n, v);\r\n\r\n\
    \  for (int _ = 0; _ < q; ++_) {\r\n    int k;\r\n    std::cin >> k;\r\n    if\
    \ (k == 0) {\r\n      int s, t, x;\r\n      std::cin >> s >> t >> x;\r\n     \
    \ --s;\r\n      --t;\r\n      segtree.update(s, t, x);\r\n    } else {\r\n   \
    \   int s, t;\r\n      std::cin >> s >> t;\r\n      --s;\r\n      --t;\r\n   \
    \   std::cout << segtree.query(s, t).first << std::endl;\r\n    }\r\n  }\r\n}\r\
    \n"
  dependsOn:
  - Library/DataStructure/LazySegmentTree.hpp
  - Library/Algebraic/Monoid.hpp
  isVerificationFile: true
  path: Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
  requiredBy: []
  timestamp: '2025-01-24 16:43:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
- /verify/Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp.html
title: Test/DataStructure/LazySegmentTree_RAQRSQ.test.cpp
---
