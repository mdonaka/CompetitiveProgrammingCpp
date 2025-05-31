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
    path: Test/Algorithms/BinarySearch_double_rev.test.cpp
    title: Test/Algorithms/BinarySearch_double_rev.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/BinarySearch_int.test.cpp
    title: Test/Algorithms/BinarySearch_int.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/BinarySearch_int_rev.test.cpp
    title: Test/Algorithms/BinarySearch_int_rev.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/BFS.test.cpp
    title: Test/Graph/Normal/BFS.test.cpp
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
  bundledCode: "#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n#include <concepts>\r\
    \n#include <numeric>\r\n#include <ranges>\r\n#include <type_traits>\r\n\r\nnamespace\
    \ mtd {\r\n\r\n  template <class Lambda>\r\n  auto binarySearch(double ok, double\
    \ ng, int rep, const Lambda& is_ok) {\r\n    for ([[maybe_unused]] auto _ : std::views::iota(0,\
    \ rep)) {\r\n      double mid = (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class Lambda, std::integral\
    \ T1, std::integral T2>\r\n  auto binarySearch(T1 ok_, T2 ng_, const Lambda& is_ok)\
    \ {\r\n    using T = std::common_type_t<T1, T2>;\r\n    T ok = ok_, ng = ng_;\r\
    \n    while (std::abs(ok - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n   \
    \   (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n} \
    \ // namespace mtd\r\n"
  code: "#pragma once\r\n\r\n#include <concepts>\r\n#include <numeric>\r\n#include\
    \ <ranges>\r\n#include <type_traits>\r\n\r\nnamespace mtd {\r\n\r\n  template\
    \ <class Lambda>\r\n  auto binarySearch(double ok, double ng, int rep, const Lambda&\
    \ is_ok) {\r\n    for ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {\r\
    \n      double mid = (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\
    \n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class Lambda, std::integral\
    \ T1, std::integral T2>\r\n  auto binarySearch(T1 ok_, T2 ng_, const Lambda& is_ok)\
    \ {\r\n    using T = std::common_type_t<T1, T2>;\r\n    T ok = ok_, ng = ng_;\r\
    \n    while (std::abs(ok - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n   \
    \   (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n} \
    \ // namespace mtd\r\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Algorithms/BinarySearch.hpp
  requiredBy:
  - Library/String/SuffixArray.hpp
  - Library/String/LCPArray.hpp
  timestamp: '2024-12-27 17:36:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/String/SuffixArray.test.cpp
  - Test/String/LCPArray.test.cpp
  - Test/Graph/Normal/BFS.test.cpp
  - Test/Algorithms/BinarySearch_int.test.cpp
  - Test/Algorithms/BinarySearch_double_rev.test.cpp
  - Test/Algorithms/BinarySearch_int_rev.test.cpp
documentation_of: Library/Algorithms/BinarySearch.hpp
layout: document
redirect_from:
- /library/Library/Algorithms/BinarySearch.hpp
- /library/Library/Algorithms/BinarySearch.hpp.html
title: Library/Algorithms/BinarySearch.hpp
---
