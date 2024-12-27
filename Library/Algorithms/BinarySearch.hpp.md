---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Library/String/LCPArray.hpp
    title: Library/String/LCPArray.hpp
  - icon: ':x:'
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
  - icon: ':x:'
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
  bundledCode: "#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n#include <numeric>\r\
    \n#include <ranges>\r\n\r\nnamespace mtd {\r\n\r\n  template <class Lambda>\r\n\
    \  auto binarySearch(double ok, double ng, int rep, const Lambda& is_ok) {\r\n\
    \    for ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {\r\n      double\
    \ mid = (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n \
    \   return ok;\r\n  }\r\n\r\n  template <class Lambda, class T = long long>\r\n\
    \  auto binarySearch(T ok, T ng, const Lambda& is_ok) {\r\n    while (std::abs(ok\
    \ - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n}  // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <numeric>\r\n#include <ranges>\r\n\r\nnamespace\
    \ mtd {\r\n\r\n  template <class Lambda>\r\n  auto binarySearch(double ok, double\
    \ ng, int rep, const Lambda& is_ok) {\r\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ rep)) {\r\n      double mid = (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class Lambda, class\
    \ T = long long>\r\n  auto binarySearch(T ok, T ng, const Lambda& is_ok) {\r\n\
    \    while (std::abs(ok - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n    \
    \  (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n}  //\
    \ namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/BinarySearch.hpp
  requiredBy:
  - Library/String/LCPArray.hpp
  - Library/String/SuffixArray.hpp
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/String/LCPArray.test.cpp
  - Test/String/SuffixArray.test.cpp
  - Test/Graph/Normal/BFS.test.cpp
  - Test/Algorithms/BinarySearch_int_rev.test.cpp
  - Test/Algorithms/BinarySearch_double_rev.test.cpp
  - Test/Algorithms/BinarySearch_int.test.cpp
documentation_of: Library/Algorithms/BinarySearch.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/BinarySearch.hpp
- /library/Library/Algorithms/BinarySearch.hpp.html
title: Library/Algorithms/BinarySearch.hpp
---
