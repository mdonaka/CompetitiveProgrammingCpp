---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Utility/Ycombinator.test.cpp
    title: Test/Utility/Ycombinator.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Utility/Ycombinator.hpp\"\n\nauto Y = [](auto f)\
    \ {\n\treturn [=](auto&&... args) {\n\t\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t\t};\n};\n\n\n"
  code: "\nauto Y = [](auto f) {\n\treturn [=](auto&&... args) {\n\t\t\treturn f(f,\
    \ std::forward<decltype(args)>(args)...);\n\t\t};\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Ycombinator.hpp
  requiredBy: []
  timestamp: '2021-05-17 09:31:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Utility/Ycombinator.test.cpp
documentation_of: Library/Utility/Ycombinator.hpp
layout: document
redirect_from:
- /library/Library/Utility/Ycombinator.hpp
- /library/Library/Utility/Ycombinator.hpp.html
title: Library/Utility/Ycombinator.hpp
---
