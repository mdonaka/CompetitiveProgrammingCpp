---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/91
    links:
    - https://yukicoder.me/problems/no/91
  bundledCode: "#line 1 \"Test/Algorithms/BinarySearch_int_rev.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/91\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\
    \n\r\n#include <concepts>\r\n#include <numeric>\r\n#include <ranges>\r\n#include\
    \ <type_traits>\r\n\r\nnamespace mtd {\r\n\r\n  template <class Lambda>\r\n  auto\
    \ binarySearch(double ok, double ng, int rep, const Lambda& is_ok) {\r\n    for\
    \ ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {\r\n      double mid =\
    \ (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return\
    \ ok;\r\n  }\r\n\r\n  template <class Lambda, std::integral T1, std::integral\
    \ T2>\r\n  auto binarySearch(T1 ok_, T2 ng_, const Lambda& is_ok) {\r\n    using\
    \ T = std::common_type_t<T1, T2>;\r\n    T ok = ok_, ng = ng_;\r\n    while (std::abs(ok\
    \ - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n}  // namespace mtd\r\n#line\
    \ 8 \"Test/Algorithms/BinarySearch_int_rev.test.cpp\"\n// end:tag includes\r\n\
    \r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  std::vector<int> a(3);\r\n  for (int i = 0; i < 3; ++i) { std::cin >>\
    \ a[i]; }\r\n\r\n  auto ans = mtd::binarySearch(0, static_cast<int>(1e9), [&](int\
    \ mid) {\r\n    int d = 0;\r\n    for (auto x : a) {\r\n      if (x >= mid) {\r\
    \n        d += ((x - mid) >> 1);\r\n      } else {\r\n        d -= mid - x;\r\n\
    \      }\r\n    }\r\n    return d >= 0;\r\n  });\r\n\r\n  std::cout << ans <<\
    \ std::endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/91\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\n// begin:tag includes\r\n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\
    \r\n// end:tag includes\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  std::vector<int> a(3);\r\n  for (int i = 0; i < 3; ++i) { std::cin >>\
    \ a[i]; }\r\n\r\n  auto ans = mtd::binarySearch(0, static_cast<int>(1e9), [&](int\
    \ mid) {\r\n    int d = 0;\r\n    for (auto x : a) {\r\n      if (x >= mid) {\r\
    \n        d += ((x - mid) >> 1);\r\n      } else {\r\n        d -= mid - x;\r\n\
    \      }\r\n    }\r\n    return d >= 0;\r\n  });\r\n\r\n  std::cout << ans <<\
    \ std::endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_int_rev.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:36:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_int_rev.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_int_rev.test.cpp
- /verify/Test/Algorithms/BinarySearch_int_rev.test.cpp.html
title: Test/Algorithms/BinarySearch_int_rev.test.cpp
---
