---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/Ycombinator.hpp\"\n\nauto Y = [](auto f)\
    \ {\n    return [=](auto&&... args) {\n        return f(f, std::forward<decltype(args)>(args)...);\n\
    \    };\n};\n\n\n"
  code: "#pragma once\n\nauto Y = [](auto f) {\n    return [=](auto&&... args) {\n\
    \        return f(f, std::forward<decltype(args)>(args)...);\n    };\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Ycombinator.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Utility/Ycombinator.hpp
layout: document
redirect_from:
- /library/Library/Utility/Ycombinator.hpp
- /library/Library/Utility/Ycombinator.hpp.html
title: Library/Utility/Ycombinator.hpp
---
