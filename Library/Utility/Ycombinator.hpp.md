---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Utility/Ycombinator.test.cpp
    title: Test/Utility/Ycombinator.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/Ycombinator.hpp\"\n\n#include <utility>\n\
    \nauto Y = [](auto f) {\n  return [=](auto&&... args) {\n    return f(f, std::forward<decltype(args)>(args)...);\n\
    \  };\n};\n"
  code: "#pragma once\n\n#include <utility>\n\nauto Y = [](auto f) {\n  return [=](auto&&...\
    \ args) {\n    return f(f, std::forward<decltype(args)>(args)...);\n  };\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Ycombinator.hpp
  requiredBy: []
  timestamp: '2024-08-30 15:21:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Utility/Ycombinator.test.cpp
documentation_of: Library/Utility/Ycombinator.hpp
layout: document
redirect_from:
- /library/Library/Utility/Ycombinator.hpp
- /library/Library/Utility/Ycombinator.hpp.html
title: Library/Utility/Ycombinator.hpp
---
