---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/Utility/Ycombinator.hpp
    title: Library/Utility/Ycombinator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"Test/Utility/Ycombinator.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/117\"\r\n\r\n#include <iostream>\r\n#include\
    \ <iomanip>\r\n#include <vector>\r\n\r\n#line 1 \"Library/Utility/Ycombinator.hpp\"\
    \n\nauto Y = [](auto f) {\n\treturn [=](auto&&... args) {\n\t\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t\t};\n};\n\n\n#line 8 \"Test/Utility/Ycombinator.test.cpp\"\n\r\nusing ll =\
    \ long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr char endl = '\\\
    n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0);\
    \ }; }_Preprocessing;\r\n\r\n\r\nsigned main() {\r\n    ll n;\r\n    cin >> n;\r\
    \n\r\n    constexpr double nil = -1.0;\r\n    std::vector<double> dp(n + 1, nil);\r\
    \n    auto f = Y([&](auto&& self, ll n) -> double {\r\n        if(n == 0) { return\
    \ 0.0; }\r\n        if(dp[n] != nil) { return dp[n]; }\r\n\r\n        double sum\
    \ = 0.0;\r\n        for(int x = 0; x < n; ++x) {\r\n            int y = n - x\
    \ - 1;\r\n            sum += self(self, x);\r\n            sum += self(self, y);\r\
    \n        }\r\n        auto ans = sum / n + 1;\r\n        dp[n] = ans;\r\n   \
    \     return ans;\r\n    });\r\n\r\n    cout << std::fixed << std::setprecision(12)\
    \ << f(n) << endl;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\r\n\r\n#include\
    \ <iostream>\r\n#include <iomanip>\r\n#include <vector>\r\n\r\n#include \"./../../Library/Utility/Ycombinator.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cout;\r\nusing std::cin;\r\nconstexpr\
    \ char endl = '\\n';\r\nstruct Preprocessing { Preprocessing() { std::cin.tie(0);\
    \ std::ios::sync_with_stdio(0); }; }_Preprocessing;\r\n\r\n\r\nsigned main() {\r\
    \n    ll n;\r\n    cin >> n;\r\n\r\n    constexpr double nil = -1.0;\r\n    std::vector<double>\
    \ dp(n + 1, nil);\r\n    auto f = Y([&](auto&& self, ll n) -> double {\r\n   \
    \     if(n == 0) { return 0.0; }\r\n        if(dp[n] != nil) { return dp[n]; }\r\
    \n\r\n        double sum = 0.0;\r\n        for(int x = 0; x < n; ++x) {\r\n  \
    \          int y = n - x - 1;\r\n            sum += self(self, x);\r\n       \
    \     sum += self(self, y);\r\n        }\r\n        auto ans = sum / n + 1;\r\n\
    \        dp[n] = ans;\r\n        return ans;\r\n    });\r\n\r\n    cout << std::fixed\
    \ << std::setprecision(12) << f(n) << endl;\r\n}"
  dependsOn:
  - Library/Utility/Ycombinator.hpp
  isVerificationFile: true
  path: Test/Utility/Ycombinator.test.cpp
  requiredBy: []
  timestamp: '2023-03-07 07:52:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Utility/Ycombinator.test.cpp
layout: document
redirect_from:
- /verify/Test/Utility/Ycombinator.test.cpp
- /verify/Test/Utility/Ycombinator.test.cpp.html
title: Test/Utility/Ycombinator.test.cpp
---
