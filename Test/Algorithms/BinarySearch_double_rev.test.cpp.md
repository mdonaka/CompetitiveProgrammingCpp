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
    ERROR: 1e-9
    PROBLEM: https://yukicoder.me/problems/no/67
    links:
    - https://yukicoder.me/problems/no/67
  bundledCode: "#line 1 \"Test/Algorithms/BinarySearch_double_rev.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/67\"\r\n#define ERROR \"1e-9\"\r\n\
    \r\n#include <iostream>\r\n#include <iomanip>\r\n#include <vector>\r\n#line 2\
    \ \"Library/Algorithms/BinarySearch.hpp\"\n\r\ntemplate <class Lambda>\r\nauto\
    \ binarySearch(double mn, double mx, int rep, const Lambda& judge,\r\n       \
    \           bool rev = false) {\r\n    auto ok = mx;\r\n    auto ng = mn;\r\n\
    \    for(int _ = 0; _ < rep; ++_) {\r\n        auto mid = (ok + ng) / 2;\r\n \
    \       auto isOk = judge(mid);\r\n        if((isOk && !rev) || (!isOk && rev))\
    \ {\r\n            ok = mid;\r\n        } else {\r\n            ng = mid;\r\n\
    \        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\n\
    auto binarySearch(long long mn, long long mx, const Lambda& judge, bool rev =\
    \ false) {\r\n    auto ok = mx + rev;\r\n    auto ng = mn - 1;\r\n    while(ok\
    \ - ng > 1) {\r\n        auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\
    \n        if((isOk && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n\
    \        } else {\r\n            ng = mid;\r\n        }\r\n    }\r\n    return\
    \ ok - rev;\r\n}\r\n#line 8 \"Test/Algorithms/BinarySearch_double_rev.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    ll n;\r\n    cin >> n;\r\n    std::vector<ll> a(n);\r\n    for(int i = 0;\
    \ i < n; ++i) { cin >> a[i]; }\r\n    ll k;\r\n    cin >> k;\r\n\r\n    auto ans\
    \ = binarySearch(1e-9, 1e9, 100, [&](double mid) {\r\n        ll count = 0;\r\n\
    \        for(const auto& x : a) {\r\n            count += (1.0 * x / mid);\r\n\
    \        }\r\n        return count >= k;\r\n    }, true);\r\n\r\n    cout << std::fixed\
    \ << std::setprecision(12) << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/67\"\r\n#define ERROR\
    \ \"1e-9\"\r\n\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <vector>\r\
    \n#include \"./../../Library/Algorithms/BinarySearch.hpp\"\r\n\r\nusing ll = long\
    \ long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\n';\r\
    \nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\n\
    \    std::vector<ll> a(n);\r\n    for(int i = 0; i < n; ++i) { cin >> a[i]; }\r\
    \n    ll k;\r\n    cin >> k;\r\n\r\n    auto ans = binarySearch(1e-9, 1e9, 100,\
    \ [&](double mid) {\r\n        ll count = 0;\r\n        for(const auto& x : a)\
    \ {\r\n            count += (1.0 * x / mid);\r\n        }\r\n        return count\
    \ >= k;\r\n    }, true);\r\n\r\n    cout << std::fixed << std::setprecision(12)\
    \ << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Algorithms/BinarySearch.hpp
  isVerificationFile: true
  path: Test/Algorithms/BinarySearch_double_rev.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 05:50:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Algorithms/BinarySearch_double_rev.test.cpp
layout: document
redirect_from:
- /verify/Test/Algorithms/BinarySearch_double_rev.test.cpp
- /verify/Test/Algorithms/BinarySearch_double_rev.test.cpp.html
title: Test/Algorithms/BinarySearch_double_rev.test.cpp
---
