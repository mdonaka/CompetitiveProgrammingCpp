---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/SemiGroup.hpp
    title: Library/Algebraic/SemiGroup.hpp
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
    \ <iostream>\r\n#include <map>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/DataStructure/DisjointSparseTable.hpp\"\
    \n\r\n#include <cmath>\r\n#include <stdexcept>\r\n#include <vector>\r\n\r\n#line\
    \ 2 \"Library/Algebraic/SemiGroup.hpp\"\n\n#line 4 \"Library/Algebraic/SemiGroup.hpp\"\
    \n\nnamespace mtd {\n\n  template <class S,  // set\n            class op  //\
    \ binary operation\n            >\n  requires std::is_invocable_r_v<S, op, S,\
    \ S>\n  struct SemiGroup {\n    using value_type = S;\n    using op_type = op;\n\
    \n    S m_val;\n    constexpr SemiGroup(S val) : m_val(val) {}\n    constexpr\
    \ SemiGroup binaryOperation(const SemiGroup& s) const {\n      return op()(m_val,\
    \ s.m_val);\n    }\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const SemiGroup<S, op>& s)\
    \ {\n      return os << s.m_val;\n    }\n  };\n\n  namespace __detail {\n    template\
    \ <typename T, template <typename, typename> typename S>\n    concept is_semigroup_specialization_of\
    \ = requires {\n      typename std::enable_if_t<\n          std::is_same_v<T,\
    \ S<typename T::value_type, typename T::op_type>>>;\n    };\n  }  // namespace\
    \ __detail\n\n  template <typename G>\n  concept semigroup = __detail::is_semigroup_specialization_of<G,\
    \ SemiGroup>;\n\n}  // namespace mtd\n#line 8 \"Library/DataStructure/DisjointSparseTable.hpp\"\
    \n\r\nnamespace mtd {\r\n\r\n  template <semigroup SG>\r\n  class DisjointSparseTable\
    \ {\r\n    using S = typename SG::value_type;\r\n\r\n    const int m_n;\r\n  \
    \  const std::vector<std::vector<SG>> m_table;\r\n\r\n    constexpr static auto\
    \ accumulation(int n, const std::vector<S>& a, int l,\r\n                    \
    \                   int r) {\r\n      auto mid = (r + l) >> 1;\r\n      r = std::min(n,\
    \ r);\r\n      int size = r - l;\r\n      std::vector<SG> acc;\r\n      acc.reserve(size);\r\
    \n      for (int i = l; i < r; ++i) { acc.emplace_back(a[i]); }\r\n      for (int\
    \ i = mid - 2; i >= l; --i) {\r\n        if (i - l + 1 < size) {\r\n         \
    \ acc[i - l] = acc[i - l].binaryOperation(acc[i - l + 1]);\r\n        }\r\n  \
    \    }\r\n      for (int i = mid + 1; i < r; ++i) {\r\n        if (i - l - 1 >=\
    \ 0) {\r\n          acc[i - l] = acc[i - l - 1].binaryOperation(acc[i - l]);\r\
    \n        }\r\n      }\r\n      return acc;\r\n    }\r\n\r\n    constexpr static\
    \ auto constructTable(int n, const std::vector<S>& a) {\r\n      std::vector<std::vector<SG>>\
    \ table;\r\n      table.reserve(std::log2(n) + 1);\r\n      table.emplace_back(a.begin(),\
    \ a.end());\r\n\r\n      auto size = 1;\r\n      while (size < n) {\r\n      \
    \  size <<= 1;\r\n        std::vector<SG> acc;\r\n        acc.reserve(n);\r\n\
    \        for (int l = 0; l < n; l += size) {\r\n          for (const auto& x :\
    \ accumulation(n, a, l, l + size)) {\r\n            acc.emplace_back(x);\r\n \
    \         }\r\n        }\r\n        table.emplace_back(acc);\r\n      }\r\n  \
    \    return table;\r\n    }\r\n\r\n    constexpr static auto msb(int x) {\r\n\
    \      auto idx = 0;\r\n      while (x > 0) {\r\n        ++idx;\r\n        x >>=\
    \ 1;\r\n      }\r\n      return idx;\r\n    }\r\n\r\n  public:\r\n    DisjointSparseTable(int\
    \ n, const std::vector<S>& a)\r\n        : m_n(n), m_table(constructTable(n, a))\
    \ {}\r\n\r\n    constexpr auto get(int l, int r) const {\r\n      if (r < l) {\
    \ throw std::runtime_error(\"ERROR! `l` must less than `r`\"); }\r\n      l =\
    \ std::max(l, 0);\r\n      r = std::min(r, m_n - 1);\r\n      if (l == r) { return\
    \ m_table[0][l].m_val; }\r\n      auto idx = msb(l ^ r);\r\n      return m_table[idx][l].binaryOperation(m_table[idx][r]).m_val;\r\
    \n    }\r\n  };\r\n}  // namespace mtd\r\n#line 8 \"Test/DataStructure/DisjointSparseTable_RMQ.test.cpp\"\
    \n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  ll n, q;\r\n \
    \ std::cin >> n >> q;\r\n  std::vector<int> a;\r\n  a.reserve(n);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int x;\r\n    std::cin >> x;\r\n    a.emplace_back(x);\r\
    \n  }\r\n\r\n  auto op = [](int a, int b) { return std::min(a, b); };\r\n  using\
    \ SG = mtd::SemiGroup<int, decltype(op)>;\r\n  auto dst = mtd::DisjointSparseTable<SG>(n,\
    \ a);\r\n\r\n  for (int _ = 0; _ < q; ++_) {\r\n    ll l, r;\r\n    std::cin >>\
    \ l >> r;\r\n    std::cout << dst.get(l, r - 1) << std::endl;\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <iostream>\r\n#include <map>\r\n\r\n// begin:tag includes\r\n#include \"./../../Library/DataStructure/DisjointSparseTable.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  ll n, q;\r\n \
    \ std::cin >> n >> q;\r\n  std::vector<int> a;\r\n  a.reserve(n);\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int x;\r\n    std::cin >> x;\r\n    a.emplace_back(x);\r\
    \n  }\r\n\r\n  auto op = [](int a, int b) { return std::min(a, b); };\r\n  using\
    \ SG = mtd::SemiGroup<int, decltype(op)>;\r\n  auto dst = mtd::DisjointSparseTable<SG>(n,\
    \ a);\r\n\r\n  for (int _ = 0; _ < q; ++_) {\r\n    ll l, r;\r\n    std::cin >>\
    \ l >> r;\r\n    std::cout << dst.get(l, r - 1) << std::endl;\r\n  }\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/DisjointSparseTable.hpp
  - Library/Algebraic/SemiGroup.hpp
  isVerificationFile: true
  path: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 16:29:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
- /verify/Test/DataStructure/DisjointSparseTable_RMQ.test.cpp.html
title: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
---
