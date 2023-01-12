---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Container/DisjointSparseTable.test.cpp
    title: Test/Container/DisjointSparseTable.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Container/DisjointSparseTable.hpp\"\n#include <vector>\r\
    \n#include <cmath>\r\n\r\ntemplate <class SG>\r\nclass DisjointSparseTable {\r\
    \n\r\n    using S = decltype(SG::Type());\r\n\r\n    const int m_n;\r\n    const\
    \ std::vector<std::vector<SG>> m_table;\r\n\r\n    static auto accumulation(int\
    \ n, const std::vector<S>& a, int l, int r) {\r\n        auto mid = (r + l) >>\
    \ 1;\r\n        r = std::min(n, r);\r\n        int size = r - l;\r\n        std::vector<SG>\
    \ acc; acc.reserve(size);\r\n        for(int i = l; i < r; ++i) { acc.emplace_back(a[i]);\
    \ }\r\n        for(int i = mid - 2; i >= l; --i) if(i - l + 1 < size) {\r\n  \
    \          acc[i - l] = acc[i - l].binaryOperation(acc[i - l + 1]);\r\n      \
    \  }\r\n        for(int i = mid + 1; i < r; ++i)if(i - l - 1 >= 0) {\r\n     \
    \       acc[i - l] = acc[i - l - 1].binaryOperation(acc[i - l]);\r\n        }\r\
    \n        return acc;\r\n    }\r\n\r\n    static auto constructTable(int n, const\
    \ std::vector<S>& a) {\r\n        std::vector<std::vector<SG>> table; table.reserve(std::log2(n)\
    \ + 1);\r\n        table.emplace_back(a.begin(), a.end());\r\n\r\n        auto\
    \ size = 1;\r\n        while(size < n) {\r\n            size <<= 1;\r\n      \
    \      std::vector<SG> acc; acc.reserve(n);\r\n            for(int l = 0; l <\
    \ n; l += size) for(const auto& x : accumulation(n, a, l, l + size)) {\r\n   \
    \             acc.emplace_back(x);\r\n            }\r\n            table.emplace_back(acc);\r\
    \n        }\r\n        return table;\r\n    }\r\n\r\n    static auto msb(int x)\
    \ {\r\n        auto idx = 0;\r\n        while(x > 0) { ++idx; x >>= 1; }\r\n \
    \       return idx;\r\n    }\r\npublic:\r\n    DisjointSparseTable(int n, const\
    \ std::vector<S>& a) :m_n(n), m_table(constructTable(n, a)) {}\r\n\r\n    auto\
    \ get(int l, int r)const {\r\n        if(r < l) { throw std::runtime_error(\"\
    ERROR! `l` must less than `r`\"); }\r\n        l = std::max(l, 0); r = std::min(r,\
    \ m_n - 1);\r\n        if(l == r) { return m_table[idx][l].m_val; }\r\n      \
    \  auto idx = msb(l ^ r);\r\n        return m_table[idx][l].binaryOperation(m_table[idx][r]).m_val;\r\
    \n    }\r\n};\r\ntemplate<\r\n    class S,// \u8981\u7D20\u306E\u578B\r\n    class\
    \ T // 2\u9805\u6F14\u7B97\u5B50\r\n>\r\nstruct SemiGroup {\r\n    static inline\
    \ auto Type() { return S(); }\r\n    S m_val;\r\n    SemiGroup(S val) :m_val(val)\
    \ {}\r\n    SemiGroup binaryOperation(const SemiGroup& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SemiGroup<S, T>& m) {\r\n        return os << m.m_val;\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cmath>\r\n\r\ntemplate <class\
    \ SG>\r\nclass DisjointSparseTable {\r\n\r\n    using S = decltype(SG::Type());\r\
    \n\r\n    const int m_n;\r\n    const std::vector<std::vector<SG>> m_table;\r\n\
    \r\n    static auto accumulation(int n, const std::vector<S>& a, int l, int r)\
    \ {\r\n        auto mid = (r + l) >> 1;\r\n        r = std::min(n, r);\r\n   \
    \     int size = r - l;\r\n        std::vector<SG> acc; acc.reserve(size);\r\n\
    \        for(int i = l; i < r; ++i) { acc.emplace_back(a[i]); }\r\n        for(int\
    \ i = mid - 2; i >= l; --i) if(i - l + 1 < size) {\r\n            acc[i - l] =\
    \ acc[i - l].binaryOperation(acc[i - l + 1]);\r\n        }\r\n        for(int\
    \ i = mid + 1; i < r; ++i)if(i - l - 1 >= 0) {\r\n            acc[i - l] = acc[i\
    \ - l - 1].binaryOperation(acc[i - l]);\r\n        }\r\n        return acc;\r\n\
    \    }\r\n\r\n    static auto constructTable(int n, const std::vector<S>& a) {\r\
    \n        std::vector<std::vector<SG>> table; table.reserve(std::log2(n) + 1);\r\
    \n        table.emplace_back(a.begin(), a.end());\r\n\r\n        auto size = 1;\r\
    \n        while(size < n) {\r\n            size <<= 1;\r\n            std::vector<SG>\
    \ acc; acc.reserve(n);\r\n            for(int l = 0; l < n; l += size) for(const\
    \ auto& x : accumulation(n, a, l, l + size)) {\r\n                acc.emplace_back(x);\r\
    \n            }\r\n            table.emplace_back(acc);\r\n        }\r\n     \
    \   return table;\r\n    }\r\n\r\n    static auto msb(int x) {\r\n        auto\
    \ idx = 0;\r\n        while(x > 0) { ++idx; x >>= 1; }\r\n        return idx;\r\
    \n    }\r\npublic:\r\n    DisjointSparseTable(int n, const std::vector<S>& a)\
    \ :m_n(n), m_table(constructTable(n, a)) {}\r\n\r\n    auto get(int l, int r)const\
    \ {\r\n        if(r < l) { throw std::runtime_error(\"ERROR! `l` must less than\
    \ `r`\"); }\r\n        l = std::max(l, 0); r = std::min(r, m_n - 1);\r\n     \
    \   if(l == r) { return m_table[idx][l].m_val; }\r\n        auto idx = msb(l ^\
    \ r);\r\n        return m_table[idx][l].binaryOperation(m_table[idx][r]).m_val;\r\
    \n    }\r\n};\r\ntemplate<\r\n    class S,// \u8981\u7D20\u306E\u578B\r\n    class\
    \ T // 2\u9805\u6F14\u7B97\u5B50\r\n>\r\nstruct SemiGroup {\r\n    static inline\
    \ auto Type() { return S(); }\r\n    S m_val;\r\n    SemiGroup(S val) :m_val(val)\
    \ {}\r\n    SemiGroup binaryOperation(const SemiGroup& m2)const { return T()(m_val,\
    \ m2.m_val); }\r\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SemiGroup<S, T>& m) {\r\n        return os << m.m_val;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/Container/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2023-01-13 03:43:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Container/DisjointSparseTable.test.cpp
documentation_of: Library/Container/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/Library/Container/DisjointSparseTable.hpp
- /library/Library/Container/DisjointSparseTable.hpp.html
title: Library/Container/DisjointSparseTable.hpp
---
