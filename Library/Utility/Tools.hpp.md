---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Range/bit_subset.test.cpp
    title: Test/Range/bit_subset.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/Tools.hpp\"\n\n#include <vector>\n\nnamespace\
    \ mtd {\n\n  template <class T, class S>\n  inline auto chmax(T& t, const S& s)\
    \ {\n    if (s > t) {\n      t = s;\n      return true;\n    }\n    return false;\n\
    \  }\n\n  template <class T, class S>\n  inline auto chmin(T& t, const S& s) {\n\
    \    if (s < t) {\n      t = s;\n      return true;\n    }\n    return false;\n\
    \  }\n\n  template <class S>\n  constexpr auto vec(S x) {\n    return x;\n  }\n\
    \n  template <class S, class... T>\n  constexpr auto vec(S x, int n, T... ns)\
    \ {\n    return std::vector(n, vec(x, ns...));\n  }\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace mtd {\n\n  template <class\
    \ T, class S>\n  inline auto chmax(T& t, const S& s) {\n    if (s > t) {\n   \
    \   t = s;\n      return true;\n    }\n    return false;\n  }\n\n  template <class\
    \ T, class S>\n  inline auto chmin(T& t, const S& s) {\n    if (s < t) {\n   \
    \   t = s;\n      return true;\n    }\n    return false;\n  }\n\n  template <class\
    \ S>\n  constexpr auto vec(S x) {\n    return x;\n  }\n\n  template <class S,\
    \ class... T>\n  constexpr auto vec(S x, int n, T... ns) {\n    return std::vector(n,\
    \ vec(x, ns...));\n  }\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Tools.hpp
  requiredBy: []
  timestamp: '2024-12-11 02:44:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Range/bit_subset.test.cpp
documentation_of: Library/Utility/Tools.hpp
layout: document
redirect_from:
- /library/Library/Utility/Tools.hpp
- /library/Library/Utility/Tools.hpp.html
title: Library/Utility/Tools.hpp
---