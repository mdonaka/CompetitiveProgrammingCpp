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
    \n#include <vector>\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\n#include\
    \ <numeric>\r\n#include <ranges>\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(double\
    \ ok, double ng, int rep, const Lambda& is_ok) {\r\n    for([[maybe_unused]] auto\
    \ _ : std::views::iota(0, rep)) {\r\n        double mid = (ok + ng) / 2.0;\r\n\
    \        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n    return ok;\r\n}\r\n\r\n\
    template <class Lambda>\r\nauto binarySearch(long long ok, long long ng, const\
    \ Lambda& is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n        long long\
    \ mid = (ok + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\n    }\r\n\
    \    return ok;\r\n}\r\n#line 6 \"Test/Algorithms/BinarySearch_int_rev.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    std::vector<ll> a(3);\r\n    for(int i = 0; i < 3; ++i) { cin >> a[i]; }\r\
    \n\r\n    auto ans = binarySearch(0, 1e9, [&](ll mid) {\r\n        ll d = 0;\r\
    \n        for(const auto& x : a) {\r\n            if(x >= mid) {\r\n         \
    \       d += ((x - mid) >> 1);\r\n            } else {\r\n                d -=\
    \ mid - x;\r\n            }\r\n        }\r\n        return d >= 0;\r\n    });\r\
    \n\r\n    cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/91\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    std::vector<ll> a(3);\r\n    for(int i = 0; i < 3; ++i) { cin >> a[i]; }\r\
    \n\r\n    auto ans = binarySearch(0, 1e9, [&](ll mid) {\r\n        ll d = 0;\r\
    \n        for(const auto& x : a) {\r\n            if(x >= mid) {\r\n         \
    \       d += ((x - mid) >> 1);\r\n            } else {\r\n                d -=\
    \ mid - x;\r\n            }\r\n        }\r\n        return d >= 0;\r\n    });\r\
    \n\r\n    cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_int_rev.test.cpp
  requiredBy: []
  timestamp: '2024-07-19 01:34:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_int_rev.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_int_rev.test.cpp
- /verify/Test/Algorithms/BinarySearch_int_rev.test.cpp.html
title: Test/Algorithms/BinarySearch_int_rev.test.cpp
---
