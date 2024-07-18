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
    \ \"https://yukicoder.me/problems/no/1882\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include <ranges>\r\n#include <algorithm>\r\n\r\n#line 2 \"Library/Algorithms/BinarySearch.hpp\"\
    \n#include <numeric>\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(double\
    \ mn, double mx, int rep, const Lambda& judge,\r\n                  bool rev =\
    \ false) {\r\n    auto ok = mx;\r\n    auto ng = mn;\r\n    for(int _ = 0; _ <\
    \ rep; ++_) {\r\n        auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\
    \n        if((isOk && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n\
    \        } else {\r\n            ng = mid;\r\n        }\r\n    }\r\n    return\
    \ ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\nauto binarySearch(long long ok, long\
    \ long ng, const Lambda& is_ok) {\r\n    while(std::abs(ok - ng) > 1) {\r\n  \
    \      long long mid = (ok + ng) >> 1;\r\n        (is_ok(mid) ? ok : ng) = mid;\r\
    \n    }\r\n    return ok;\r\n}\r\n#line 9 \"Test/Algorithms/BinarySearch_int.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    ll n, x;\r\n    cin >> n >> x;\r\n    std::vector<ll> a(n);\r\n    for(int\
    \ i = 0; i < n; ++i) { cin >> a[i]; }\r\n    std::ranges::sort(a);\r\n\r\n   \
    \ ll ans = 0;\r\n    for(const auto& val : a) {\r\n        auto idx = binarySearch(n,\
    \ -1, [&](ll mid) {\r\n            return val * a[mid] >= (x << 1);\r\n      \
    \  });\r\n        ans += n - idx;\r\n    }\r\n\r\n    cout << ans << endl;\r\n\
    }\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1882\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <ranges>\r\n#include <algorithm>\r\
    \n\r\n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\r\n\r\nusing ll\
    \ = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl =\
    \ '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nsigned main() {\r\n    ll n, x;\r\n    cin >> n >>\
    \ x;\r\n    std::vector<ll> a(n);\r\n    for(int i = 0; i < n; ++i) { cin >> a[i];\
    \ }\r\n    std::ranges::sort(a);\r\n\r\n    ll ans = 0;\r\n    for(const auto&\
    \ val : a) {\r\n        auto idx = binarySearch(n, -1, [&](ll mid) {\r\n     \
    \       return val * a[mid] >= (x << 1);\r\n        });\r\n        ans += n -\
    \ idx;\r\n    }\r\n\r\n    cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_int.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 23:06:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_int.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_int.test.cpp
- /verify/Test/Algorithms/BinarySearch_int.test.cpp.html
title: Test/Algorithms/BinarySearch_int.test.cpp
---
