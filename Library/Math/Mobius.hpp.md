---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Library/Math/Bit.hpp
    title: Library/Math/Bit.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Math/Convolution.hpp
    title: Library/Math/Convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Math/Mobius.hpp\"\n\n#include <ranges>\n#include\
    \ <vector>\n\n#line 2 \"Library/Math/Bit.hpp\"\n\nnamespace mtd {\n\n  constexpr\
    \ unsigned clz(unsigned int x) {\n    int c = 0;\n    if (x == 0) { return 0;\
    \ }\n    if (x & 0xffff0000) {\n      x &= 0xffff0000;\n      c |= 0x10;\n   \
    \ }\n    if (x & 0xff00ff00) {\n      x &= 0xff00ff00;\n      c |= 0x08;\n   \
    \ }\n    if (x & 0xf0f0f0f0) {\n      x &= 0xf0f0f0f0;\n      c |= 0x04;\n   \
    \ }\n    if (x & 0xcccccccc) {\n      x &= 0xcccccccc;\n      c |= 0x02;\n   \
    \ }\n    if (x & 0xaaaaaaaa) { c |= 0x01; }\n    return c + 1;\n  }\n\n  constexpr\
    \ unsigned ctz(unsigned int n) {\n    if (!n) return -1;\n    unsigned int c =\
    \ 32;\n    n &= -static_cast<signed int>(n);\n    if (n) c--;\n    if (n & 0x0000FFFF)\
    \ c -= 16;\n    if (n & 0x00FF00FF) c -= 8;\n    if (n & 0x0F0F0F0F) c -= 4;\n\
    \    if (n & 0x33333333) c -= 2;\n    if (n & 0x55555555) c -= 1;\n    return\
    \ c;\n  }\n\n  constexpr unsigned long long popcount(unsigned long long x) {\n\
    \    x = x - ((x >> 1) & 0x5555555555555555);\n    x = (x & 0x3333333333333333)\
    \ + ((x >> 2) & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;\n\
    \    x = x + (x >> 8);\n    x = x + (x >> 16);\n    x = x + (x >> 32);\n    return\
    \ x & 0x0000007f;\n  }\n\n}  // namespace mtd\n#line 6 \"Library/Math/Mobius.hpp\"\
    \n\nnamespace mtd::mobius {\n\n  template <class T>\n  auto n(const std::vector<T>&\
    \ a) {\n    auto ret = a;\n    for (auto i : std::views::iota(static_cast<size_t>(1),\
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
    \        }\n      }\n    }\n    return ret;\n  }\n\n}  // namespace mtd::mobius\n"
  code: "\n#include <ranges>\n#include <vector>\n\n#include \"./Bit.hpp\"\n\nnamespace\
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
    \        }\n      }\n    }\n    return ret;\n  }\n\n}  // namespace mtd::mobius\n"
  dependsOn:
  - Library/Math/Bit.hpp
  isVerificationFile: false
  path: Library/Math/Mobius.hpp
  requiredBy:
  - Library/Math/Convolution.hpp
  timestamp: '2024-11-09 15:39:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Math/Mobius.hpp
layout: document
redirect_from:
- /library/Library/Math/Mobius.hpp
- /library/Library/Math/Mobius.hpp.html
title: Library/Math/Mobius.hpp
---
