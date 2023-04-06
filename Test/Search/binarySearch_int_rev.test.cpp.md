---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Search/binarySearch.hpp
    title: Library/Search/binarySearch.hpp
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
  bundledCode: "#line 1 \"Test/Search/binarySearch_int_rev.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/91\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#line 2 \"Library/Search/binarySearch.hpp\"\n\r\ntemplate <class\
    \ Lambda>\r\nauto binarySearch(double mn, double mx, int rep, const Lambda& judge,\r\
    \n                  bool rev = false) {\r\n    auto ok = mx;\r\n    auto ng =\
    \ mn;\r\n    for(int _ = 0; _ < rep; ++_) {\r\n        auto mid = (ok + ng) /\
    \ 2;\r\n        auto isOk = judge(mid);\r\n        if((isOk && !rev) || (!isOk\
    \ && rev)) {\r\n            ok = mid;\r\n        } else {\r\n            ng =\
    \ mid;\r\n        }\r\n    }\r\n    return ok;\r\n}\r\n\r\ntemplate <class Lambda>\r\
    \nauto binarySearch(long long mn, long long mx, const Lambda& judge, bool rev\
    \ = false) {\r\n    auto ok = mx + rev;\r\n    auto ng = mn - 1;\r\n    while(ok\
    \ - ng > 1) {\r\n        auto mid = (ok + ng) / 2;\r\n        auto isOk = judge(mid);\r\
    \n        if((isOk && !rev) || (!isOk && rev)) {\r\n            ok = mid;\r\n\
    \        } else {\r\n            ng = mid;\r\n        }\r\n    }\r\n    return\
    \ ok - rev;\r\n}\r\n#line 6 \"Test/Search/binarySearch_int_rev.test.cpp\"\n\r\n\
    using ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char\
    \ endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\nsigned main() {\r\n    std::vector<ll> a(3);\r\n\
    \    for(int i = 0; i < 3; ++i) { cin >> a[i]; }\r\n\r\n    auto ans = binarySearch(0,\
    \ 1e9, [&](ll mid) {\r\n        ll d = 0;\r\n        for(const auto& x : a) {\r\
    \n            if(x >= mid) {\r\n                d += ((x - mid) >> 1);\r\n   \
    \         } else {\r\n                d -= mid - x;\r\n            }\r\n     \
    \   }\r\n        return d >= 0;\r\n    }, true);\r\n\r\n    cout << ans << endl;\r\
    \n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/91\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include \"./../../Library/Search/binarySearch.hpp\"\r\n\
    \r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\nsigned main() {\r\n\
    \    std::vector<ll> a(3);\r\n    for(int i = 0; i < 3; ++i) { cin >> a[i]; }\r\
    \n\r\n    auto ans = binarySearch(0, 1e9, [&](ll mid) {\r\n        ll d = 0;\r\
    \n        for(const auto& x : a) {\r\n            if(x >= mid) {\r\n         \
    \       d += ((x - mid) >> 1);\r\n            } else {\r\n                d -=\
    \ mid - x;\r\n            }\r\n        }\r\n        return d >= 0;\r\n    }, true);\r\
    \n\r\n    cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/Search/binarySearch.hpp
  isVerificationFile: true
  path: Test/Search/binarySearch_int_rev.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 23:26:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Search/binarySearch_int_rev.test.cpp
layout: document
redirect_from:
- /verify/Test/Search/binarySearch_int_rev.test.cpp
- /verify/Test/Search/binarySearch_int_rev.test.cpp.html
title: Test/Search/binarySearch_int_rev.test.cpp
---
