---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algebraic/SemiGroup.hpp
    title: Library/Algebraic/SemiGroup.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
    title: Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/DisjointSparseTable_xor.test.cpp
    title: Test/DataStructure/DisjointSparseTable_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/DisjointSparseTable.hpp\"\n\r\n#include\
    \ <cmath>\r\n#include <stdexcept>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algebraic/SemiGroup.hpp\"\
    \n\n#include <iostream>\n\nnamespace mtd {\n\n  template <class S,  // set\n \
    \           class op  // binary operation\n            >\n  requires std::is_invocable_r_v<S,\
    \ op, S, S>\n  struct SemiGroup {\n    using value_type = S;\n    using op_type\
    \ = op;\n\n    S m_val;\n    constexpr SemiGroup(S val) : m_val(val) {}\n    constexpr\
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
    \n    }\r\n  };\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <cmath>\r\n#include <stdexcept>\r\n#include\
    \ <vector>\r\n\r\n#include \"../Algebraic/SemiGroup.hpp\"\r\n\r\nnamespace mtd\
    \ {\r\n\r\n  template <semigroup SG>\r\n  class DisjointSparseTable {\r\n    using\
    \ S = typename SG::value_type;\r\n\r\n    const int m_n;\r\n    const std::vector<std::vector<SG>>\
    \ m_table;\r\n\r\n    constexpr static auto accumulation(int n, const std::vector<S>&\
    \ a, int l,\r\n                                       int r) {\r\n      auto mid\
    \ = (r + l) >> 1;\r\n      r = std::min(n, r);\r\n      int size = r - l;\r\n\
    \      std::vector<SG> acc;\r\n      acc.reserve(size);\r\n      for (int i =\
    \ l; i < r; ++i) { acc.emplace_back(a[i]); }\r\n      for (int i = mid - 2; i\
    \ >= l; --i) {\r\n        if (i - l + 1 < size) {\r\n          acc[i - l] = acc[i\
    \ - l].binaryOperation(acc[i - l + 1]);\r\n        }\r\n      }\r\n      for (int\
    \ i = mid + 1; i < r; ++i) {\r\n        if (i - l - 1 >= 0) {\r\n          acc[i\
    \ - l] = acc[i - l - 1].binaryOperation(acc[i - l]);\r\n        }\r\n      }\r\
    \n      return acc;\r\n    }\r\n\r\n    constexpr static auto constructTable(int\
    \ n, const std::vector<S>& a) {\r\n      std::vector<std::vector<SG>> table;\r\
    \n      table.reserve(std::log2(n) + 1);\r\n      table.emplace_back(a.begin(),\
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
    \n    }\r\n  };\r\n}  // namespace mtd\r\n"
  dependsOn:
  - Library/Algebraic/SemiGroup.hpp
  isVerificationFile: false
  path: Library/DataStructure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2024-12-27 16:29:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/DisjointSparseTable_xor.test.cpp
  - Test/DataStructure/DisjointSparseTable_RMQ.test.cpp
documentation_of: Library/DataStructure/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/DisjointSparseTable.hpp
- /library/Library/DataStructure/DisjointSparseTable.hpp.html
title: Library/DataStructure/DisjointSparseTable.hpp
---
