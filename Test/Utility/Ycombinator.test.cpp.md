---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Ycombinator.hpp
    title: Library/Utility/Ycombinator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2123
    links:
    - https://yukicoder.me/problems/no/2123
  bundledCode: "#line 1 \"Test/Utility/Ycombinator.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/2123\"\r\n\r\n#line 2 \"Library/Utility/Ycombinator.hpp\"\
    \n\n#include <utility>\n\nauto Y = [](auto f) {\n  return [=](auto&&... args)\
    \ {\n    return f(f, std::forward<decltype(args)>(args)...);\n  };\n};\n#line\
    \ 4 \"Test/Utility/Ycombinator.test.cpp\"\n\r\n#include <iomanip>\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\
    \nusing std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct Preprocessing {\r\
    \n  Preprocessing() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\
    \n  };\r\n} _Preprocessing;\r\n\r\nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\
    \n\r\n  constexpr double nil = -1.0;\r\n  std::vector<double> dp(n + 1, nil);\r\
    \n  auto f = Y([&](auto&& self, ll n) -> double {\r\n    if (n == 0) { return\
    \ 0.0; }\r\n    if (dp[n] != nil) { return dp[n]; }\r\n\r\n    double sum = 0.0;\r\
    \n    for (int x = 0; x < n; ++x) {\r\n      int y = n - x - 1;\r\n      sum +=\
    \ self(self, x);\r\n      sum += self(self, y);\r\n    }\r\n    auto ans = sum\
    \ / n + 1;\r\n    dp[n] = ans;\r\n    return ans;\r\n  });\r\n\r\n  cout << f(n)\
    \ << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2123\"\r\n\r\n#include\
    \ \"./../../Library/Utility/Ycombinator.hpp\"\r\n\r\n#include <iomanip>\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\nusing ll = long long;\r\nusing std::cin;\r\
    \nusing std::cout;\r\nconstexpr char endl = '\\n';\r\nstruct Preprocessing {\r\
    \n  Preprocessing() {\r\n    std::cin.tie(0);\r\n    std::ios::sync_with_stdio(0);\r\
    \n  };\r\n} _Preprocessing;\r\n\r\nsigned main() {\r\n  ll n;\r\n  cin >> n;\r\
    \n\r\n  constexpr double nil = -1.0;\r\n  std::vector<double> dp(n + 1, nil);\r\
    \n  auto f = Y([&](auto&& self, ll n) -> double {\r\n    if (n == 0) { return\
    \ 0.0; }\r\n    if (dp[n] != nil) { return dp[n]; }\r\n\r\n    double sum = 0.0;\r\
    \n    for (int x = 0; x < n; ++x) {\r\n      int y = n - x - 1;\r\n      sum +=\
    \ self(self, x);\r\n      sum += self(self, y);\r\n    }\r\n    auto ans = sum\
    \ / n + 1;\r\n    dp[n] = ans;\r\n    return ans;\r\n  });\r\n\r\n  cout << f(n)\
    \ << endl;\r\n}\r\n"
  dependsOn:
  - Library/Utility/Ycombinator.hpp
  isVerificationFile: true
  path: Test/Utility/Ycombinator.test.cpp
  requiredBy: []
  timestamp: '2024-08-30 15:21:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Utility/Ycombinator.test.cpp
layout: document
redirect_from:
- /verify/Test/Utility/Ycombinator.test.cpp
- /verify/Test/Utility/Ycombinator.test.cpp.html
title: Test/Utility/Ycombinator.test.cpp
---
