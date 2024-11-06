---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Math/Convolution.hpp
    title: Library/Math/Convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Mobius.hpp
    title: Library/Math/Mobius.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Math/Zeta.hpp
    title: Library/Math/Zeta.hpp
  - icon: ':warning:'
    path: Library/Range/bit.hpp
    title: Library/Range/bit.hpp
  - icon: ':warning:'
    path: Library/Range/template.cpp
    title: Library/Range/template.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/convolution_and.test.cpp
    title: Test/Math/convolution_and.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/Bit.hpp\"\n\nnamespace mtd {\n\n  constexpr\
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
    \ c;\n  }\n}  // namespace mtd\n"
  code: "#pragma once\n\nnamespace mtd {\n\n  constexpr unsigned clz(unsigned int\
    \ x) {\n    int c = 0;\n    if (x == 0) { return 0; }\n    if (x & 0xffff0000)\
    \ {\n      x &= 0xffff0000;\n      c |= 0x10;\n    }\n    if (x & 0xff00ff00)\
    \ {\n      x &= 0xff00ff00;\n      c |= 0x08;\n    }\n    if (x & 0xf0f0f0f0)\
    \ {\n      x &= 0xf0f0f0f0;\n      c |= 0x04;\n    }\n    if (x & 0xcccccccc)\
    \ {\n      x &= 0xcccccccc;\n      c |= 0x02;\n    }\n    if (x & 0xaaaaaaaa)\
    \ { c |= 0x01; }\n    return c + 1;\n  }\n\n  constexpr unsigned ctz(unsigned\
    \ int n) {\n    if (!n) return -1;\n    unsigned int c = 32;\n    n &= -static_cast<signed\
    \ int>(n);\n    if (n) c--;\n    if (n & 0x0000FFFF) c -= 16;\n    if (n & 0x00FF00FF)\
    \ c -= 8;\n    if (n & 0x0F0F0F0F) c -= 4;\n    if (n & 0x33333333) c -= 2;\n\
    \    if (n & 0x55555555) c -= 1;\n    return c;\n  }\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/Bit.hpp
  requiredBy:
  - Library/Range/bit.hpp
  - Library/Range/template.cpp
  - Library/Math/Zeta.hpp
  - Library/Math/Mobius.hpp
  - Library/Math/Convolution.hpp
  timestamp: '2024-11-06 14:52:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/convolution_and.test.cpp
documentation_of: Library/Math/Bit.hpp
layout: document
redirect_from:
- /library/Library/Math/Bit.hpp
- /library/Library/Math/Bit.hpp.html
title: Library/Math/Bit.hpp
---
