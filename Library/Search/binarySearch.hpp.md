---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/String/LCPArray.hpp
    title: Library/String/LCPArray.hpp
  - icon: ':heavy_check_mark:'
    path: Library/String/SuffixArray.hpp
    title: Library/String/SuffixArray.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/String/LCPArray.test.cpp
    title: Test/String/LCPArray.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/String/SuffixArray.test.cpp
    title: Test/String/SuffixArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Search/binarySearch.hpp\"\n\r\ntemplate <class Lambda>\r\
    \nauto binarySearch(double mn, double mx, int rep, const Lambda& judge,\r\n  \
    \                bool rev = false) {\r\n    auto ok = mx;\r\n    auto ng = mn;\r\
    \n    for(int _ = 0; _ < rep; ++_) {\r\n        auto mid = (ok + ng) / 2;\r\n\
    \        auto isOk = judge(mid);\r\n        if((isOk && !rev) || (!isOk && rev))\
    \ {\r\n            ok = mid;\r\n        } else {\r\n            ng = mid;\r\n\
    \        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\n\
    auto binarySearch(long long mn, long long mx, const Lambda& judge, bool rev =\
    \ false) {\r\n    auto ok = mx;\r\n    auto ng = mn - 1;\r\n    while(ok - ng\
    \ > 1) {\r\n        auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\
    \n        if((isOk && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n\
    \        } else {\r\n            ng = mid;\r\n        }\r\n    }\r\n    return\
    \ ok;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(double mn,\
    \ double mx, int rep, const Lambda& judge,\r\n                  bool rev = false)\
    \ {\r\n    auto ok = mx;\r\n    auto ng = mn;\r\n    for(int _ = 0; _ < rep; ++_)\
    \ {\r\n        auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\n\
    \        if((isOk && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n \
    \       } else {\r\n            ng = mid;\r\n        }\r\n    }\r\n    return\
    \ ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(long long mn, long\
    \ long mx, const Lambda& judge, bool rev = false) {\r\n    auto ok = mx;\r\n \
    \   auto ng = mn - 1;\r\n    while(ok - ng > 1) {\r\n        auto mid = (ok +\
    \ ng) / 2;\r\n        auto isOk = judge(mid);\r\n        if((isOk && !rev) ||\
    \ (!isOk && rev)) {\r\n            ok = mid;\r\n        } else {\r\n         \
    \   ng = mid;\r\n        }\r\n    }\r\n    return ok;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Search/binarySearch.hpp
  requiredBy:
  - Library/String/SuffixArray.hpp
  - Library/String/LCPArray.hpp
  timestamp: '2022-09-11 19:45:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/String/LCPArray.test.cpp
  - Test/String/SuffixArray.test.cpp
documentation_of: Library/Search/binarySearch.hpp
layout: document
redirect_from:
- /library/Library/Search/binarySearch.hpp
- /library/Library/Search/binarySearch.hpp.html
title: Library/Search/binarySearch.hpp
---
