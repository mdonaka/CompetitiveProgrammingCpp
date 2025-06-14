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
    PROBLEM: https://yukicoder.me/problems/no/1882
    links:
    - https://yukicoder.me/problems/no/1882
  bundledCode: "#line 1 \"Test/Algorithms/BinarySearch_int.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1882\"\r\n\r\n#include <algorithm>\r\n#include\
    \ <iostream>\r\n#include <ranges>\r\n#include <vector>\r\n\r\n// begin:tag includes\r\
    \n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n#include <concepts>\r\n\
    #include <numeric>\r\n#line 6 \"Library/Algorithms/BinarySearch.hpp\"\n#include\
    \ <type_traits>\r\n\r\nnamespace mtd {\r\n\r\n  template <class Lambda>\r\n  auto\
    \ binarySearch(double ok, double ng, int rep, const Lambda& is_ok) {\r\n    for\
    \ ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {\r\n      double mid =\
    \ (ok + ng) / 2.0;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return\
    \ ok;\r\n  }\r\n\r\n  template <class Lambda, std::integral T1, std::integral\
    \ T2>\r\n  auto binarySearch(T1 ok_, T2 ng_, const Lambda& is_ok) {\r\n    using\
    \ T = std::common_type_t<T1, T2>;\r\n    T ok = ok_, ng = ng_;\r\n    while (std::abs(ok\
    \ - ng) > 1) {\r\n      T mid = (ok + ng) >> 1;\r\n      (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n}  // namespace mtd\r\n#line\
    \ 10 \"Test/Algorithms/BinarySearch_int.test.cpp\"\n// end:tag includes\r\n\r\n\
    using ll = long long;\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\
    \n\r\n  ll n, x;\r\n  std::cin >> n >> x;\r\n  std::vector<ll> a(n);\r\n  for\
    \ (int i = 0; i < n; ++i) { std::cin >> a[i]; }\r\n  std::ranges::sort(a);\r\n\
    \r\n  ll ans = 0;\r\n  for (const auto& val : a) {\r\n    auto idx = mtd::binarySearch<>(\r\
    \n        n, -1, [&](ll mid) { return val * a[mid] >= (x << 1); });\r\n    ans\
    \ += n - idx;\r\n  }\r\n\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1882\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <ranges>\r\n#include <vector>\r\
    \n\r\n// begin:tag includes\r\n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\
    \r\n// end:tag includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n\
    \  std::cin.tie(0);\r\n  std::ios::sync_with_stdio(0);\r\n\r\n  ll n, x;\r\n \
    \ std::cin >> n >> x;\r\n  std::vector<ll> a(n);\r\n  for (int i = 0; i < n; ++i)\
    \ { std::cin >> a[i]; }\r\n  std::ranges::sort(a);\r\n\r\n  ll ans = 0;\r\n  for\
    \ (const auto& val : a) {\r\n    auto idx = mtd::binarySearch<>(\r\n        n,\
    \ -1, [&](ll mid) { return val * a[mid] >= (x << 1); });\r\n    ans += n - idx;\r\
    \n  }\r\n\r\n  std::cout << ans << std::endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_int.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:36:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_int.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_int.test.cpp
- /verify/Test/Algorithms/BinarySearch_int.test.cpp.html
title: Test/Algorithms/BinarySearch_int.test.cpp
---
