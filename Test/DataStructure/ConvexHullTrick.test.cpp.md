---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/ConvecHullTrick.hpp
    title: Library/DataStructure/ConvecHullTrick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/409
    links:
    - https://yukicoder.me/problems/no/409
  bundledCode: "#line 1 \"Test/DataStructure/ConvexHullTrick.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/409\"\r\n\r\n#include <iostream>\r\n#include\
    \ <numeric>\r\n#include <vector>\r\n\r\n#line 2 \"Library/DataStructure/ConvecHullTrick.hpp\"\
    \n\r\n#include <deque>\r\n\r\n/*\r\n * \u76F4\u7DDA\u306F\u50BE\u304D\u306B\u3064\
    \u3044\u3066\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11(\u6700\u5927\u5024\u30AF\u30A8\
    \u30EA\u306E\u5834\u5408\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0)\r\n * \u30AF\
    \u30A8\u30EA\u306F\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\r\n */\r\nclass ConvexHullTrick\
    \ {\r\n  using T = long long;\r\n  std::deque<std::pair<T, T>> lines;\r\n\r\n\
    \  static auto func(const std::pair<T, T>& line, const T& x) {\r\n    return x\
    \ * line.first + line.second;\r\n  }\r\n  static auto check(const std::pair<T,\
    \ T>& line1, const std::pair<T, T>& line2,\r\n                    const std::pair<T,\
    \ T>& line3) {\r\n    auto [a1, b1] = line1;\r\n    auto [a2, b2] = line2;\r\n\
    \    auto [a3, b3] = line3;\r\n    return (a2 - a1) * (b3 - b2) >= (b2 - b1) *\
    \ (a3 - a2);\r\n  }\r\n\r\npublic:\r\n  ConvexHullTrick() {}\r\n\r\n  auto add(const\
    \ std::pair<T, T>& line) {\r\n    while (lines.size() > 1 &&\r\n           check(*std::next(lines.rbegin()),\
    \ *lines.rbegin(), line)) {\r\n      lines.pop_back();\r\n    }\r\n    lines.emplace_back(line);\r\
    \n  }\r\n  auto add(const T& a, const T& b) { add({a, b}); }\r\n\r\n  auto query(const\
    \ T& x) {\r\n    while (lines.size() > 1 &&\r\n           func(*lines.begin(),\
    \ x) > func(*std::next(lines.begin()), x)) {\r\n      lines.pop_front();\r\n \
    \   }\r\n    return func(*lines.begin(), x);\r\n  }\r\n};\r\n#line 8 \"Test/DataStructure/ConvexHullTrick.test.cpp\"\
    \n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n, a, b, w;\r\n  cin >> n\
    \ >> a >> b >> w;\r\n  std::vector<ll> d;\r\n  d.reserve(n);\r\n  for (int i =\
    \ 0; i < n; ++i) {\r\n    ll x;\r\n    cin >> x;\r\n    d.emplace_back(x);\r\n\
    \  }\r\n\r\n  constexpr ll mx = 1e18;\r\n  auto cht = ConvexHullTrick();\r\n \
    \ std::vector<ll> dp(n + 1, mx);\r\n  auto update = [&](ll i, ll x) {\r\n    dp[i]\
    \ = x;\r\n    auto pa = -b * i;\r\n    auto pb = a * i + i * (i + 1) / 2 * b +\
    \ dp[i];\r\n    cht.add(pa, pb);\r\n  };\r\n\r\n  update(0, w);\r\n  for (ll i\
    \ = 1; i < n + 1; ++i) {\r\n    auto ad = d[i - 1] - a * i + a + i * (i - 1) /\
    \ 2 * b;\r\n    auto min = cht.query(i);\r\n    update(i, ad + min);\r\n  }\r\n\
    \r\n  ll ans = dp[n];\r\n  for (ll i = 0; i < n; ++i) {\r\n    ll k = n - i;\r\
    \n    ans = std::min(ans, dp[i] + -a * k + k * (k + 1) / 2 * b);\r\n  }\r\n\r\n\
    \  cout << ans << endl;\r\n}\r\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/409\"\r\n\r\n#include\
    \ <iostream>\r\n#include <numeric>\r\n#include <vector>\r\n\r\n#include \"./../../Library/DataStructure/ConvecHullTrick.hpp\"\
    \r\n\r\nusing ll = long long;\r\nusing std::cin;\r\nusing std::cout;\r\nconstexpr\
    \ char endl = '\\n';\r\n\r\nsigned main() {\r\n  ll n, a, b, w;\r\n  cin >> n\
    \ >> a >> b >> w;\r\n  std::vector<ll> d;\r\n  d.reserve(n);\r\n  for (int i =\
    \ 0; i < n; ++i) {\r\n    ll x;\r\n    cin >> x;\r\n    d.emplace_back(x);\r\n\
    \  }\r\n\r\n  constexpr ll mx = 1e18;\r\n  auto cht = ConvexHullTrick();\r\n \
    \ std::vector<ll> dp(n + 1, mx);\r\n  auto update = [&](ll i, ll x) {\r\n    dp[i]\
    \ = x;\r\n    auto pa = -b * i;\r\n    auto pb = a * i + i * (i + 1) / 2 * b +\
    \ dp[i];\r\n    cht.add(pa, pb);\r\n  };\r\n\r\n  update(0, w);\r\n  for (ll i\
    \ = 1; i < n + 1; ++i) {\r\n    auto ad = d[i - 1] - a * i + a + i * (i - 1) /\
    \ 2 * b;\r\n    auto min = cht.query(i);\r\n    update(i, ad + min);\r\n  }\r\n\
    \r\n  ll ans = dp[n];\r\n  for (ll i = 0; i < n; ++i) {\r\n    ll k = n - i;\r\
    \n    ans = std::min(ans, dp[i] + -a * k + k * (k + 1) / 2 * b);\r\n  }\r\n\r\n\
    \  cout << ans << endl;\r\n}\r\n"
  dependsOn:
  - Library/DataStructure/ConvecHullTrick.hpp
  isVerificationFile: true
  path: Test/DataStructure/ConvexHullTrick.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 04:18:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/ConvexHullTrick.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/ConvexHullTrick.test.cpp
- /verify/Test/DataStructure/ConvexHullTrick.test.cpp.html
title: Test/DataStructure/ConvexHullTrick.test.cpp
---
