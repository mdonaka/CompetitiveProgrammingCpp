---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Algorithms/BinarySearch.hpp
    title: Library/Algorithms/BinarySearch.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-9
    PROBLEM: https://yukicoder.me/problems/no/67
    links:
    - https://yukicoder.me/problems/no/67
  bundledCode: "#line 1 \"Test/Algorithms/BinarySearch_double_rev.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/67\"\r\n#define ERROR \"1e-9\"\r\n\
    \r\n#include <iomanip>\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line\
    \ 2 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n#include <numeric>\r\n#include\
    \ <ranges>\r\n\r\nnamespace mtd {\r\n\r\n  template <class Lambda>\r\n  auto binarySearch(double\
    \ ok, double ng, int rep, const Lambda& is_ok) {\r\n    for ([[maybe_unused]]\
    \ auto _ : std::views::iota(0, rep)) {\r\n      double mid = (ok + ng) / 2.0;\r\
    \n      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n\
    \  template <class Lambda, class T = long long>\r\n  auto binarySearch(T ok, T\
    \ ng, const Lambda& is_ok) {\r\n    while (std::abs(ok - ng) > 1) {\r\n      T\
    \ mid = (ok + ng) >> 1;\r\n      (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n  \
    \  return ok;\r\n  }\r\n\r\n}  // namespace mtd\r\n#line 9 \"Test/Algorithms/BinarySearch_double_rev.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  ll n;\r\n  cin >> n;\r\n  std::vector<ll> a(n);\r\n  for (int\
    \ i = 0; i < n; ++i) { cin >> a[i]; }\r\n  ll k;\r\n  cin >> k;\r\n\r\n  auto\
    \ ans = mtd::binarySearch(1e-9, 1e9, 100, [&](double mid) {\r\n    ll count =\
    \ 0;\r\n    for (const auto& x : a) { count += (1.0 * x / mid); }\r\n    return\
    \ count >= k;\r\n  });\r\n\r\n  cout << std::fixed << std::setprecision(12) <<\
    \ ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/67\"\r\n#define ERROR\
    \ \"1e-9\"\r\n\r\n#include <iomanip>\r\n#include <iostream>\r\n#include <vector>\r\
    \n\r\n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\r\n\r\nusing ll\
    \ = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl =\
    \ '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  ll n;\r\n  cin >> n;\r\n  std::vector<ll> a(n);\r\n  for (int\
    \ i = 0; i < n; ++i) { cin >> a[i]; }\r\n  ll k;\r\n  cin >> k;\r\n\r\n  auto\
    \ ans = mtd::binarySearch(1e-9, 1e9, 100, [&](double mid) {\r\n    ll count =\
    \ 0;\r\n    for (const auto& x : a) { count += (1.0 * x / mid); }\r\n    return\
    \ count >= k;\r\n  });\r\n\r\n  cout << std::fixed << std::setprecision(12) <<\
    \ ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_double_rev.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_double_rev.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_double_rev.test.cpp
- /verify/Test/Algorithms/BinarySearch_double_rev.test.cpp.html
title: Test/Algorithms/BinarySearch_double_rev.test.cpp
---
