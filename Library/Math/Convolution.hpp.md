---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Math/Bit.hpp
    title: Library/Math/Bit.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Mobius.hpp
    title: Library/Math/Mobius.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Zeta.hpp
    title: Library/Math/Zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/convolution_and.test.cpp
    title: Test/Math/convolution_and.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/Convolution.hpp\"\n\n#include <ranges>\n#include\
    \ <vector>\n\n#line 1 \"Library/Math/Mobius.hpp\"\n\n#line 4 \"Library/Math/Mobius.hpp\"\
    \n\n#line 2 \"Library/Math/Bit.hpp\"\n\nnamespace mtd {\n\n  constexpr unsigned\
    \ clz(unsigned int x) {\n    int c = 0;\n    if (x == 0) { return 0; }\n    if\
    \ (x & 0xffff0000) {\n      x &= 0xffff0000;\n      c |= 0x10;\n    }\n    if\
    \ (x & 0xff00ff00) {\n      x &= 0xff00ff00;\n      c |= 0x08;\n    }\n    if\
    \ (x & 0xf0f0f0f0) {\n      x &= 0xf0f0f0f0;\n      c |= 0x04;\n    }\n    if\
    \ (x & 0xcccccccc) {\n      x &= 0xcccccccc;\n      c |= 0x02;\n    }\n    if\
    \ (x & 0xaaaaaaaa) { c |= 0x01; }\n    return c + 1;\n  }\n\n  constexpr unsigned\
    \ ctz(unsigned int n) {\n    if (!n) return -1;\n    unsigned int c = 32;\n  \
    \  n &= -static_cast<signed int>(n);\n    if (n) c--;\n    if (n & 0x0000FFFF)\
    \ c -= 16;\n    if (n & 0x00FF00FF) c -= 8;\n    if (n & 0x0F0F0F0F) c -= 4;\n\
    \    if (n & 0x33333333) c -= 2;\n    if (n & 0x55555555) c -= 1;\n    return\
    \ c;\n  }\n}  // namespace mtd\n#line 6 \"Library/Math/Mobius.hpp\"\n\nnamespace\
    \ mtd::mobius {\n\n  template <class T>\n  auto n(const std::vector<T>& a) {\n\
    \    auto ret = a;\n    for (auto i : std::views::iota(static_cast<size_t>(1),\
    \ a.size())) {\n      ret[i] = a[i] - a[i - 1];\n    }\n    return ret;\n  }\n\
    \n  template <class T>\n  auto bit_subset(const std::vector<T>& a) {\n    auto\
    \ ret = a;\n    int size = clz(a.size());\n    for (auto b : std::views::iota(0,\
    \ size)) {\n      for (auto bit : std::views::iota(0, 1LL << size)) {\n      \
    \  if (((bit >> b) & 1) && bit < a.size()) {\n          ret[bit] -= ret[bit ^\
    \ (1LL << b)];\n        }\n      }\n    }\n    return ret;\n  }\n\n  template\
    \ <class T>\n  auto bit_supset(const std::vector<T>& a) {\n    auto ret = a;\n\
    \    int size = clz(a.size());\n    for (auto b : std::views::iota(0, size)) {\n\
    \      for (auto bit : std::views::iota(0, 1LL << size)) {\n        if (((bit\
    \ >> b) & 1) && bit < a.size()) {\n          ret[bit ^ (1LL << b)] -= ret[bit];\n\
    \        }\n      }\n    }\n    return ret;\n  }\n\n}  // namespace mtd::mobius\n\
    #line 2 \"Library/Math/Zeta.hpp\"\n\n#line 5 \"Library/Math/Zeta.hpp\"\n\n#line\
    \ 7 \"Library/Math/Zeta.hpp\"\n\nnamespace mtd::zeta {\n\n  template <class T>\n\
    \  auto n(const std::vector<T>& a) {\n    auto ret = a;\n    for (auto i : std::views::iota(static_cast<size_t>(1),\
    \ a.size())) {\n      ret[i] += ret[i - 1];\n    }\n    return ret;\n  }\n\n \
    \ template <class T>\n  auto bit_subset(const std::vector<T>& a) {\n    auto ret\
    \ = a;\n    int size = clz(a.size());\n    for (auto b : std::views::iota(0, size))\
    \ {\n      for (auto bit : std::views::iota(0, 1LL << size)) {\n        if (((bit\
    \ >> b) & 1) && bit < a.size()) {\n          ret[bit] += ret[bit ^ (1LL << b)];\n\
    \        }\n      }\n    }\n    return ret;\n  }\n\n  template <class T>\n  auto\
    \ bit_supset(const std::vector<T>& a) {\n    auto ret = a;\n    int size = clz(a.size());\n\
    \    for (auto b : std::views::iota(0, size)) {\n      for (auto bit : std::views::iota(0,\
    \ 1LL << size)) {\n        if (((bit >> b) & 1) && bit < a.size()) {\n       \
    \   ret[bit ^ (1LL << b)] += ret[bit];\n        }\n      }\n    }\n    return\
    \ ret;\n  }\n}  // namespace mtd::zeta\n#line 8 \"Library/Math/Convolution.hpp\"\
    \n\nnamespace mtd::convolution {\n\n  template <class T>\n  auto bitwise_and(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    auto za = mtd::zeta::bit_supset(a);\n\
    \    auto zb = mtd::zeta::bit_supset(b);\n    auto zab = std::vector<T>();\n \
    \   for (auto i : std::views::iota(static_cast<size_t>(0), a.size())) {\n    \
    \  zab.emplace_back(za[i] * zb[i]);\n    }\n    auto zma = mtd::mobius::bit_supset(za);\n\
    \    return mtd::mobius::bit_supset(zab);\n  }\n\n}  // namespace mtd::convolution\n"
  code: "#pragma once\n\n#include <ranges>\n#include <vector>\n\n#include \"./Mobius.hpp\"\
    \n#include \"./Zeta.hpp\"\n\nnamespace mtd::convolution {\n\n  template <class\
    \ T>\n  auto bitwise_and(const std::vector<T>& a, const std::vector<T>& b) {\n\
    \    auto za = mtd::zeta::bit_supset(a);\n    auto zb = mtd::zeta::bit_supset(b);\n\
    \    auto zab = std::vector<T>();\n    for (auto i : std::views::iota(static_cast<size_t>(0),\
    \ a.size())) {\n      zab.emplace_back(za[i] * zb[i]);\n    }\n    auto zma =\
    \ mtd::mobius::bit_supset(za);\n    return mtd::mobius::bit_supset(zab);\n  }\n\
    \n}  // namespace mtd::convolution\n"
  dependsOn:
  - Library/Math/Mobius.hpp
  - Library/Math/Bit.hpp
  - Library/Math/Zeta.hpp
  isVerificationFile: false
  path: Library/Math/Convolution.hpp
  requiredBy: []
  timestamp: '2024-11-06 16:04:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/convolution_and.test.cpp
documentation_of: Library/Math/Convolution.hpp
layout: document
redirect_from:
- /library/Library/Math/Convolution.hpp
- /library/Library/Math/Convolution.hpp.html
title: Library/Math/Convolution.hpp
---
