---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/CoordinateCompression.hpp
    title: Library/Algorithms/CoordinateCompression.hpp
  - icon: ':question:'
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
    \n#line 6 \"Library/Algorithms/CoordinateCompression.hpp\"\n\r\nclass CoordinateCompression\
    \ {\r\n\r\n    const std::vector<long long> m_v;\r\n    const std::vector<long\
    \ long> m_itox;\r\n    const std::unordered_map<long long, int> m_xtoi;\r\n\r\n\
    \    static inline auto c_itox(const std::vector<long long>& v) {\r\n        auto\
    \ itox = v;\r\n        std::sort(itox.begin(), itox.end());\r\n        itox.erase(std::unique(itox.begin(),\
    \ itox.end()), itox.end());\r\n        return itox;\r\n    }\r\n    static inline\
    \ auto c_xtoi(const std::vector<long long>& itox) {\r\n        std::unordered_map<long\
    \ long, int> xtoi;\r\n        for(unsigned int i = 0; i < itox.size(); ++i) {\r\
    \n            xtoi.emplace(itox[i], i);\r\n        }\r\n        return xtoi;\r\
    \n    }\r\n\r\npublic:\r\n    CoordinateCompression(const std::vector<long long>&\
    \ v) :\r\n        m_v(v),\r\n        m_itox(c_itox(v)),\r\n        m_xtoi(c_xtoi(m_itox))\
    \ {\r\n    }\r\n    auto size()const { return m_itox.size(); }\r\n    auto toi(long\
    \ long x)const { return m_xtoi.at(x); }\r\n    auto tox(int i)const { return m_itox[i];\
    \ }\r\n    auto c(const std::vector<long long>& v)const {\r\n        std::vector<long\
    \ long> ret; ret.reserve(size());\r\n        for(const auto& x : v) { ret.emplace_back(toi(x));\
    \ }\r\n        return ret;\r\n    }\r\n    auto c()const { return c(m_v); }\r\n\
    };\n#line 2 \"Library/DataStructure/SegmentTree.hpp\"\n\r\n#line 4 \"Library/DataStructure/SegmentTree.hpp\"\
    \n#include <deque>\r\n#include <utility>\r\n\r\ntemplate<class T>\r\nclass isMonoid\
    \ {\r\n    template <class U>\r\n    static auto check(U x) -> decltype(x.binaryOperation(x),\
    \ std::true_type{});\r\n    static std::false_type check(...);\r\npublic:\r\n\
    \    static bool const value = decltype(check(std::declval<T>()))::value;\r\n\
    };\r\n\r\ntemplate<class Monoid, std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t>\
    \ = nullptr >\r\nclass SegmentTree {\r\nprivate:\r\n    const int m_size;\r\n\
    \    std::vector<Monoid> m_node;\r\n    using S = decltype(Monoid().m_val);\r\n\
    \r\n    int calcSize(int n) const { int size = 1; while(size < n) { size <<= 1;\
    \ }return size; }\r\n\r\n    template<class Lambda>\r\n    auto _update_op(int\
    \ itr, Monoid&& val, const Lambda& op) {\r\n        int i = itr + m_size - 1;\r\
    \n        m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));\r\n   \
    \     while(i) {\r\n            i = (i - 1) >> 1;\r\n            m_node[i] = m_node[(i\
    \ << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n        }\r\n    }\r\n\r\
    \n    auto _query(int _l, int _r) const {\r\n        _l = std::max(_l, 0); _r\
    \ = std::min(_r, m_size - 1);\r\n        auto l = _l + m_size;\r\n        int\
    \ r = _r + m_size;\r\n        auto lm = Monoid();\r\n        auto rm = Monoid();\r\
    \n        while(l <= r) {\r\n            if(l & 1) { lm = lm.binaryOperation(m_node[l\
    \ - 1]); ++l; }\r\n            if(!(r & 1)) { rm = m_node[r - 1].binaryOperation(rm);\
    \ --r; }\r\n            l >>= 1, r >>= 1;\r\n        }\r\n        return lm.binaryOperation(rm);\r\
    \n    }\r\n\r\n    auto _construct(const std::vector<S>& vec) {\r\n        for(unsigned\
    \ int i = 0; i < vec.size(); ++i) {\r\n            m_node[i + m_size - 1] = Monoid(vec[i]);\r\
    \n        }\r\n        for(int i = m_size - 2; i >= 0; --i) {\r\n            m_node[i]\
    \ = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);\r\n        }\r\
    \n    }\r\npublic:\r\n    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size\
    \ << 1) - 1) {}\r\n    SegmentTree(int n, const std::vector<S>& vec) :SegmentTree(n)\
    \ { _construct(vec); }\r\n\r\n    template<class Lambda>\r\n    auto update_op(int\
    \ itr, Monoid&& val, const Lambda& op) { return _update_op(itr, std::forward<Monoid>(val),\
    \ op); }\r\n    auto update(int itr, Monoid&& val) { return update_op(itr, std::forward<Monoid>(val),\
    \ [](const Monoid&, const Monoid& m2) {return m2; }); }\r\n    auto add(int itr,\
    \ Monoid&& val) { return update_op(itr, std::forward<Monoid>(val), [](const Monoid&\
    \ m1, const Monoid& m2) {return Monoid(m1.m_val + m2.m_val); }); }\r\n    auto\
    \ query(int l, int r)const { return _query(l, r).m_val; }\r\n    auto query_all()const\
    \ { return m_node[0].m_val; }\r\n\r\n    auto output()const {\r\n        for(int\
    \ i = 0; i < m_size; ++i) { std::cout << m_node[m_size + i - 1] << \" \"; }\r\n\
    \        std::cout << std::endl;\r\n    }\r\n};\r\n\r\n\r\ntemplate<\r\n    class\
    \ S,   // \u8981\u7D20\u306E\u578B\r\n    S element, // \u5143\r\n    class T\
    \ // lambda\u306FC++20\u3058\u3083\u306A\u3044\u3068\u6E21\u305B\u306A\u304B\u3063\
    \u305F\uFF0E\uFF0E\uFF0E\r\n    // S T(S, S)  // 2\u9805\u6F14\u7B97\u5B50\r\n\
    >\r\nstruct Monoid {\r\n    S m_val;\r\n    Monoid() :m_val(element) {}\r\n  \
    \  Monoid(S val) :m_val(val) {}\r\n    Monoid binaryOperation(const Monoid& m2)const\
    \ { return T()(m_val, m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Monoid<S, element, T>& m) {\r\n        return os << m.m_val;\r\n \
    \   }\r\n};\r\n#line 9 \"Test/Algorithms/CoordinateCompression_to.test.cpp\"\n\
    \r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nstruct Functor {\r\n  auto operator()(ll a, ll b)\
    \ const { return a + b; }\r\n};\r\nusing M = Monoid<ll, 0, Functor>;\r\n\r\nsigned\
    \ main() {\r\n  ll n;\r\n  cin >> n;\r\n  std::vector<ll> a, b;\r\n  a.reserve(n);\r\
    \n  b.reserve(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    ll x;\r\n    cin >>\
    \ x;\r\n    a.emplace_back(x);\r\n  }\r\n  for (int i = 0; i < n; ++i) {\r\n \
    \   ll x;\r\n    cin >> x;\r\n    b.emplace_back(x);\r\n  }\r\n  std::sort(a.begin(),\
    \ a.end());\r\n\r\n  auto ab = a;\r\n  for (const auto& x : b) { ab.emplace_back(x);\
    \ }\r\n  auto cc = CoordinateCompression(ab);\r\n\r\n  ll ans = 0;\r\n  auto segtree\
    \ = SegmentTree<M>(cc.size());\r\n  for (int i = 0; i < n; ++i) {\r\n    segtree.add(cc.toi(b[i]),\
    \ 1);\r\n    ans += segtree.query(0, cc.toi(a[i]) - 1);\r\n  }\r\n\r\n  cout <<\
    \ ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1282\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"./../../Library/Algorithms/CoordinateCompression.hpp\"\
    \r\n#include \"./../../Library/DataStructure/SegmentTree.hpp\"\r\n\r\nusing ll\
    \ = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl =\
    \ '\\n';\r\n\r\nstruct Functor {\r\n  auto operator()(ll a, ll b) const { return\
    \ a + b; }\r\n};\r\nusing M = Monoid<ll, 0, Functor>;\r\n\r\nsigned main() {\r\
    \n  ll n;\r\n  cin >> n;\r\n  std::vector<ll> a, b;\r\n  a.reserve(n);\r\n  b.reserve(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    ll x;\r\n    cin >> x;\r\n    a.emplace_back(x);\r\
    \n  }\r\n  for (int i = 0; i < n; ++i) {\r\n    ll x;\r\n    cin >> x;\r\n   \
    \ b.emplace_back(x);\r\n  }\r\n  std::sort(a.begin(), a.end());\r\n\r\n  auto\
    \ ab = a;\r\n  for (const auto& x : b) { ab.emplace_back(x); }\r\n  auto cc =\
    \ CoordinateCompression(ab);\r\n\r\n  ll ans = 0;\r\n  auto segtree = SegmentTree<M>(cc.size());\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    segtree.add(cc.toi(b[i]), 1);\r\n   \
    \ ans += segtree.query(0, cc.toi(a[i]) - 1);\r\n  }\r\n\r\n  cout << ans << endl;\r\
    \n}\r\n"
  dependsOn:
  - Library/Algorithms/CoordinateCompression.hpp
  - Library/DataStructure/SegmentTree.hpp
  isVerificationFile: true
  path: Test/Algorithms/CoordinateCompression_to.test.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/CoordinateCompression_to.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/CoordinateCompression_to.test.cpp
- /verify/Test/Algorithms/CoordinateCompression_to.test.cpp.html
title: Test/Algorithms/CoordinateCompression_to.test.cpp
---
