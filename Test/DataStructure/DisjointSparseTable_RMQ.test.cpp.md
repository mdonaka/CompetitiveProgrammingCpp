---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/DisjointSparseTable.hpp
    title: Library/DataStructure/DisjointSparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/DataStructure/DisjointSparseTable_RMQ.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <iostream>\r\n#include <map>\r\n\r\n#line 2 \"Library/DataStructure/DisjointSparseTable.hpp\"\
    \n#include <cmath>\r\n#include <stdexcept>\r\n#include <vector>\r\n\r\ntemplate\
    \ <class SG>\r\nclass DisjointSparseTable {\r\n  using S = decltype(SG::Type());\r\
    \n\r\n  const int m_n;\r\n  const std::vector<std::vector<SG>> m_table;\r\n\r\n\
    \  static auto accumulation(int n, const std::vector<S>& a, int l, int r) {\r\n\
    \    auto mid = (r + l) >> 1;\r\n    r = std::min(n, r);\r\n    int size = r -\
    \ l;\r\n    std::vector<SG> acc;\r\n    acc.reserve(size);\r\n    for (int i =\
    \ l; i < r; ++i) { acc.emplace_back(a[i]); }\r\n    for (int i = mid - 2; i >=\
    \ l; --i) {\r\n      if (i - l + 1 < size) {\r\n        acc[i - l] = acc[i - l].binaryOperation(acc[i\
    \ - l + 1]);\r\n      }\r\n    }\r\n    for (int i = mid + 1; i < r; ++i) {\r\n\
    \      if (i - l - 1 >= 0) {\r\n        acc[i - l] = acc[i - l - 1].binaryOperation(acc[i\
    \ - l]);\r\n      }\r\n    }\r\n    return acc;\r\n  }\r\n\r\n  static auto constructTable(int\
    \ n, const std::vector<S>& a) {\r\n    std::vector<std::vector<SG>> table;\r\n\
    \    table.reserve(std::log2(n) + 1);\r\n    table.emplace_back(a.begin(), a.end());\r\
    \n\r\n    auto size = 1;\r\n    while (size < n) {\r\n      size <<= 1;\r\n  \
    \    std::vector<SG> acc;\r\n      acc.reserve(n);\r\n      for (int l = 0; l\
    \ < n; l += size) {\r\n        for (const auto& x : accumulation(n, a, l, l +\
    \ size)) {\r\n          acc.emplace_back(x);\r\n        }\r\n      }\r\n     \
    \ table.emplace_back(acc);\r\n    }\r\n    return table;\r\n  }\r\n\r\n  static\
    \ auto msb(int x) {\r\n    auto idx = 0;\r\n    while (x > 0) {\r\n      ++idx;\r\
    \n      x >>= 1;\r\n    }\r\n    return idx;\r\n  }\r\n\r\npublic:\r\n  DisjointSparseTable(int\
    \ n, const std::vector<S>& a)\r\n      : m_n(n), m_table(constructTable(n, a))\
    \ {}\r\n\r\n  auto get(int l, int r) const {\r\n    if (r < l) { throw std::runtime_error(\"\
    ERROR! `l` must less than `r`\"); }\r\n    l = std::max(l, 0);\r\n    r = std::min(r,\
    \ m_n - 1);\r\n    if (l == r) { return m_table[0][l].m_val; }\r\n    auto idx\
    \ = msb(l ^ r);\r\n    return m_table[idx][l].binaryOperation(m_table[idx][r]).m_val;\r\
    \n  }\r\n};\r\ntemplate <class S,  // \u8981\u7D20\u306E\u578B\r\n          class\
    \ T   // 2\u9805\u6F14\u7B97\u5B50\r\n          >\r\nstruct SemiGroup {\r\n  static\
    \ inline auto Type() { return S(); }\r\n  S m_val;\r\n  SemiGroup(S val) : m_val(val)\
    \ {}\r\n  SemiGroup binaryOperation(const SemiGroup& m2) const {\r\n    return\
    \ T()(m_val, m2.m_val);\r\n  }\r\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const SemiGroup<S, T>& m) {\r\n    return os << m.m_val;\r\n  }\r\n};\r\n\
    #line 7 \"Test/DataStructure/DisjointSparseTable_RMQ.test.cpp\"\n\r\nusing ll\
    \ = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl =\
    \ '\\n';\r\n\r\nstruct Functor {\r\n  auto operator()(int a, int b) const { return\
    \ std::min(a, b); }\r\n};\r\n\r\nsigned main() {\r\n  ll n, q;\r\n  cin >> n >>\
    \ q;\r\n  std::vector<int> a;\r\n  a.reserve(n);\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    int x;\r\n    cin >> x;\r\n    a.emplace_back(x);\r\n  }\r\n\r\n  using\
    \ SG = SemiGroup<int, Functor>;\r\n  auto dst = DisjointSparseTable<SG>(n, a);\r\
    \n  for (int _ = 0; _ < q; ++_) {\r\n    ll l, r;\r\n    cin >> l >> r;\r\n  \
    \  cout << dst.get(l, r - 1) << endl;\r\n  }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <iostream>\r\n#include <map>\r\n\r\n#include \"./../../Library/DataStructure/DisjointSparseTable.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nstruct Functor {\r\n  auto operator()(int a, int b)\
    \ const { return std::min(a, b); }\r\n};\r\n\r\nsigned main() {\r\n  ll n, q;\r\
    \n  cin >> n >> q;\r\n  std::vector<int> a;\r\n  a.reserve(n);\r\n  for (int i\
    \ = 0; i < n; ++i) {\r\n    int x;\r\n    cin >> x;\r\n    a.emplace_back(x);\r\
    \n  }\r\n\r\n  using SG = SemiGroup<int, Functor>;\r\n  auto dst = DisjointSparseTable<SG>(n,\
    \ a);\r\n  for (int _ = 0; _ < q; ++_) {\r\n    ll l, r;\r\n    cin >> l >> r;\r\
    \n    cout << dst.get(l, r - 1) << endl;\r\n  }\r\n}"
  dependsOn:
  - Library/DataStructure/DisjointSparseTable.hpp
  isVerificationFile: true
  path: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
  requiredBy: []
  timestamp: '2024-10-04 14:22:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
- /verify/Test/DataStructure/DisjointSparseTable_RMQ.test.cpp.html
title: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
---
