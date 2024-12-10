---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/Monoid.hpp
    title: Library/Algebraic/Monoid.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/CoordinateCompression.hpp
    title: Library/Algorithms/CoordinateCompression.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/1282
    links:
    - https://yukicoder.me/problems/no/1282
  bundledCode: "#line 1 \"Test/Algorithms/CoordinateCompression_to.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1282\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algorithms/CoordinateCompression.hpp\"\
    \n\r\n#line 4 \"Library/Algorithms/CoordinateCompression.hpp\"\n#include <unordered_map>\r\
    \n#line 6 \"Library/Algorithms/CoordinateCompression.hpp\"\n\r\nnamespace mtd\
    \ {\r\n\r\n  class CoordinateCompression {\r\n    const std::vector<long long>\
    \ m_v;\r\n    const std::vector<long long> m_itox;\r\n    const std::unordered_map<long\
    \ long, int> m_xtoi;\r\n\r\n    static inline auto c_itox(const std::vector<long\
    \ long>& v) {\r\n      auto itox = v;\r\n      std::sort(itox.begin(), itox.end());\r\
    \n      itox.erase(std::unique(itox.begin(), itox.end()), itox.end());\r\n   \
    \   return itox;\r\n    }\r\n    static inline auto c_xtoi(const std::vector<long\
    \ long>& itox) {\r\n      std::unordered_map<long long, int> xtoi;\r\n      for\
    \ (unsigned int i = 0; i < itox.size(); ++i) {\r\n        xtoi.emplace(itox[i],\
    \ i);\r\n      }\r\n      return xtoi;\r\n    }\r\n\r\n  public:\r\n    CoordinateCompression(const\
    \ std::vector<long long>& v)\r\n        : m_v(v), m_itox(c_itox(v)), m_xtoi(c_xtoi(m_itox))\
    \ {}\r\n    auto size() const { return m_itox.size(); }\r\n    auto toi(long long\
    \ x) const { return m_xtoi.at(x); }\r\n    auto tox(int i) const { return m_itox[i];\
    \ }\r\n    auto c(const std::vector<long long>& v) const {\r\n      std::vector<long\
    \ long> ret;\r\n      ret.reserve(size());\r\n      for (const auto& x : v) {\
    \ ret.emplace_back(toi(x)); }\r\n      return ret;\r\n    }\r\n    auto c() const\
    \ { return c(m_v); }\r\n  };\r\n\r\n}  // namespace mtd\r\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\
    \n\r\n#include <deque>\r\n#line 5 \"Library/DataStructure/SegmentTree.hpp\"\n\
    #include <utility>\r\n#line 7 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n\
    #line 2 \"Library/Algebraic/Monoid.hpp\"\n\n#line 4 \"Library/Algebraic/Monoid.hpp\"\
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
    \ auto, typename> typename S>\n    concept is_specialization_of = requires {\n\
    \      typename std::enable_if_t<std::is_same_v<\n          T, S<typename T::value_type,\
    \ T::_element, typename T::op_type>>>;\n    };\n  }  // namespace __detail\n\n\
    \  template <typename M>\n  concept monoid = __detail::is_specialization_of<M,\
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
    \    constexpr auto _query(int _l, int _r) const {\r\n      _l = std::max(_l,\
    \ 0);\r\n      _r = std::min(_r, m_size - 1);\r\n      auto l = _l + m_size;\r\
    \n      auto r = _r + m_size;\r\n      auto lm = Monoid();\r\n      auto rm =\
    \ Monoid();\r\n      while (l <= r) {\r\n        if (l & 1) {\r\n          lm\
    \ = lm.binaryOperation(m_node[l - 1]);\r\n          ++l;\r\n        }\r\n    \
    \    if (!(r & 1)) {\r\n          rm = m_node[r - 1].binaryOperation(rm);\r\n\
    \          --r;\r\n        }\r\n        l >>= 1, r >>= 1;\r\n      }\r\n     \
    \ return lm.binaryOperation(rm);\r\n    }\r\n\r\n    constexpr auto _construct(const\
    \ std::vector<S>& vec) {\r\n      for (unsigned int i = 0; i < vec.size(); ++i)\
    \ {\r\n        m_node[i + m_size - 1] = Monoid(vec[i]);\r\n      }\r\n      for\
    \ (int i = m_size - 2; i >= 0; --i) {\r\n        m_node[i] = m_node[(i << 1) |\
    \ 1].binaryOperation(m_node[(i + 1) << 1]);\r\n      }\r\n    }\r\n\r\n  public:\r\
    \n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size << 1) - 1) {}\r\
    \n    SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n) {\r\n   \
    \   _construct(vec);\r\n    }\r\n\r\n    template <class Lambda>\r\n    constexpr\
    \ auto update_op(int itr, Monoid&& val, const Lambda& op) {\r\n      return _update_op(itr,\
    \ std::forward<Monoid>(val), op);\r\n    }\r\n    constexpr auto update(int itr,\
    \ Monoid&& val) {\r\n      return update_op(itr, std::forward<Monoid>(val),\r\n\
    \                       [](const Monoid&, const Monoid& m2) { return m2; });\r\
    \n    }\r\n    constexpr auto add(int itr, Monoid&& val) {\r\n      return update_op(itr,\
    \ std::forward<Monoid>(val),\r\n                       [](const Monoid& m1, const\
    \ Monoid& m2) {\r\n                         return Monoid(m1.m_val + m2.m_val);\r\
    \n                       });\r\n    }\r\n    constexpr auto query(int l, int r)\
    \ const { return _query(l, r).m_val; }\r\n    constexpr auto query_all() const\
    \ { return m_node[0].m_val; }\r\n\r\n    constexpr auto debug() const {\r\n  \
    \    for (int i = 0; i < m_size; ++i) {\r\n        std::cout << m_node[m_size\
    \ + i - 1] << \" \";\r\n      }\r\n      std::cout << std::endl;\r\n    }\r\n\
    \  };\r\n\r\n}  // namespace mtd\r\n#line 9 \"Test/Algorithms/CoordinateCompression_to.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nstruct Functor {\r\n  auto operator()(ll a, ll b)\
    \ const { return a + b; }\r\n};\r\nusing M = mtd::Monoid<ll, 0, Functor>;\r\n\r\
    \nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\n  std::vector<ll> a, b;\r\n  a.reserve(n);\r\
    \n  b.reserve(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    ll x;\r\n    cin >>\
    \ x;\r\n    a.emplace_back(x);\r\n  }\r\n  for (int i = 0; i < n; ++i) {\r\n \
    \   ll x;\r\n    cin >> x;\r\n    b.emplace_back(x);\r\n  }\r\n  std::sort(a.begin(),\
    \ a.end());\r\n\r\n  auto ab = a;\r\n  for (const auto& x : b) { ab.emplace_back(x);\
    \ }\r\n  auto cc = mtd::CoordinateCompression(ab);\r\n\r\n  ll ans = 0;\r\n  auto\
    \ segtree = mtd::SegmentTree<M>(cc.size());\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    segtree.add(cc.toi(b[i]), 1);\r\n    ans += segtree.query(0, cc.toi(a[i])\
    \ - 1);\r\n  }\r\n\r\n  cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1282\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"./../../Library/Algorithms/CoordinateCompression.hpp\"\
    \r\n#include \"./../../Library/DataStructure/SegmentTree.hpp\"\r\n\r\nusing ll\
    \ = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl =\
    \ '\\n';\r\n\r\nstruct Functor {\r\n  auto operator()(ll a, ll b) const { return\
    \ a + b; }\r\n};\r\nusing M = mtd::Monoid<ll, 0, Functor>;\r\n\r\nsigned main()\
    \ {\r\n  ll n;\r\n  cin >> n;\r\n  std::vector<ll> a, b;\r\n  a.reserve(n);\r\n\
    \  b.reserve(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    ll x;\r\n    cin >>\
    \ x;\r\n    a.emplace_back(x);\r\n  }\r\n  for (int i = 0; i < n; ++i) {\r\n \
    \   ll x;\r\n    cin >> x;\r\n    b.emplace_back(x);\r\n  }\r\n  std::sort(a.begin(),\
    \ a.end());\r\n\r\n  auto ab = a;\r\n  for (const auto& x : b) { ab.emplace_back(x);\
    \ }\r\n  auto cc = mtd::CoordinateCompression(ab);\r\n\r\n  ll ans = 0;\r\n  auto\
    \ segtree = mtd::SegmentTree<M>(cc.size());\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    segtree.add(cc.toi(b[i]), 1);\r\n    ans += segtree.query(0, cc.toi(a[i])\
    \ - 1);\r\n  }\r\n\r\n  cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/CoordinateCompression.hpp
  - Library/DataStructure/SegmentTree.hpp
  - Library/Algebraic/Monoid.hpp
  isVerificationFile: true
  path: Test/Algorithms/CoordinateCompression_to.test.cpp
  requiredBy: []
  timestamp: '2024-12-11 01:55:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/CoordinateCompression_to.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/CoordinateCompression_to.test.cpp
- /verify/Test/Algorithms/CoordinateCompression_to.test.cpp.html
title: Test/Algorithms/CoordinateCompression_to.test.cpp
---
