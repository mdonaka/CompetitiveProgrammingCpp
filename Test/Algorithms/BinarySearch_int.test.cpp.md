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
    PROBLEM: https://yukicoder.me/problems/no/1882
    links:
    - https://yukicoder.me/problems/no/1882
  bundledCode: "#line 1 \"Test/Algorithms/BinarySearch_int.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1882\"\r\n\r\n#include <algorithm>\r\n#include\
    \ <iostream>\r\n#include <ranges>\r\n#include <vector>\r\n\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\
    \n#include <numeric>\r\n#line 4 \"Library/Algorithms/BinarySearch.hpp\"\n\r\n\
    template <class Lambda>\r\nauto binarySearch(double ok, double ng, int rep, const\
    \ Lambda& is_ok) {\r\n    for([[maybe_unused]] auto _ : std::views::iota(0, rep))\
    \ {\r\n        double mid = (ok + ng) / 2.0;\r\n        (is_ok(mid) ? ok : ng)\
    \ = mid;\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\nauto\
    \ binarySearch(long long ok, long long ng, const Lambda& is_ok) {\r\n    while(std::abs(ok\
    \ - ng) > 1) {\r\n        long long mid = (ok + ng) >> 1;\r\n        (is_ok(mid)\
    \ ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n}\r\n#line 9 \"Test/Algorithms/BinarySearch_int.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  ll n, x;\r\n  cin >> n >> x;\r\n  std::vector<ll> a(n);\r\n  for\
    \ (int i = 0; i < n; ++i) { cin >> a[i]; }\r\n  std::ranges::sort(a);\r\n\r\n\
    \  ll ans = 0;\r\n  for (const auto& val : a) {\r\n    auto idx =\r\n        binarySearch(n,\
    \ -1, [&](ll mid) { return val * a[mid] >= (x << 1); });\r\n    ans += n - idx;\r\
    \n  }\r\n\r\n  cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1882\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <ranges>\r\n#include <vector>\r\
    \n\r\n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\r\n\r\nusing ll\
    \ = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr char endl =\
    \ '\\n';\r\nstruct Preprocessing {\r\n  Preprocessing() {\r\n    std::cin.tie(0);\r\
    \n    std::ios::sync_with_stdio(0);\r\n  };\r\n} _Preprocessing;\r\n\r\nsigned\
    \ main() {\r\n  ll n, x;\r\n  cin >> n >> x;\r\n  std::vector<ll> a(n);\r\n  for\
    \ (int i = 0; i < n; ++i) { cin >> a[i]; }\r\n  std::ranges::sort(a);\r\n\r\n\
    \  ll ans = 0;\r\n  for (const auto& val : a) {\r\n    auto idx =\r\n        binarySearch(n,\
    \ -1, [&](ll mid) { return val * a[mid] >= (x << 1); });\r\n    ans += n - idx;\r\
    \n  }\r\n\r\n  cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_int.test.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:48:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_int.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_int.test.cpp
- /verify/Test/Algorithms/BinarySearch_int.test.cpp.html
title: Test/Algorithms/BinarySearch_int.test.cpp
---
