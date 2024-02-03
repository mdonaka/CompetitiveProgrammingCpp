---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/String/LCPArray.hpp
    title: Library/String/LCPArray.hpp
  - icon: ':question:'
    path: Library/String/SuffixArray.hpp
    title: Library/String/SuffixArray.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/BinarySearch_double_rev.test.cpp
    title: Test/Algorithms/BinarySearch_double_rev.test.cpp
  - icon: ':x:'
    path: Test/Algorithms/BinarySearch_int.test.cpp
    title: Test/Algorithms/BinarySearch_int.test.cpp
  - icon: ':x:'
    path: Test/Algorithms/BinarySearch_int_rev.test.cpp
    title: Test/Algorithms/BinarySearch_int_rev.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/BFS.test.cpp
    title: Test/Graph/Normal/BFS.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/String/LCPArray.test.cpp
    title: Test/String/LCPArray.test.cpp
  - icon: ':x:'
    path: Test/String/SuffixArray.test.cpp
    title: Test/String/SuffixArray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\ntemplate <class\
    \ Lambda>\r\nauto binarySearch(double mn, double mx, int rep, const Lambda& judge,\r\
    \n                  bool rev = false) {\r\n    auto ok = mx;\r\n    auto ng =\
    \ mn;\r\n    for(int _ = 0; _ < rep; ++_) {\r\n        auto mid = (ok + ng) /\
    \ 2;\r\n        auto isOk = judge(mid);\r\n        if((isOk && !rev) || (!isOk\
    \ && rev)) {\r\n            ok = mid;\r\n        } else {\r\n            ng =\
    \ mid;\r\n        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\
    \nauto binarySearch(long long ok, long long ng, const Lambda& is_ok) {\r\n   \
    \ while(std::abs(ok - ng) > 1) {\r\n        long long mid = (ok + ng) >> 1;\r\n\
    \        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(double mn,\
    \ double mx, int rep, const Lambda& judge,\r\n                  bool rev = false)\
    \ {\r\n    auto ok = mx;\r\n    auto ng = mn;\r\n    for(int _ = 0; _ < rep; ++_)\
    \ {\r\n        auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\n\
    \        if((isOk && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n \
    \       } else {\r\n            ng = mid;\r\n        }\r\n    }\r\n    return\
    \ ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(long long ok, long\
    \ long ng, const Lambda& is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n  \
    \      long long mid = (ok + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\
    \n    }\r\n    return ok;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/BinarySearch.hpp
  requiredBy:
  - Library/String/SuffixArray.hpp
  - Library/String/LCPArray.hpp
  timestamp: '2024-02-03 20:57:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Graph/Normal/BFS.test.cpp
  - Test/Algorithms/BinarySearch_int_rev.test.cpp
  - Test/Algorithms/BinarySearch_double_rev.test.cpp
  - Test/Algorithms/BinarySearch_int.test.cpp
  - Test/String/SuffixArray.test.cpp
  - Test/String/LCPArray.test.cpp
documentation_of: Library/Algorithms/BinarySearch.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/BinarySearch.hpp
- /library/Library/Algorithms/BinarySearch.hpp.html
title: Library/Algorithms/BinarySearch.hpp
---
