---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Math/BabyStepGiantStep.hpp
    title: Library/Math/BabyStepGiantStep.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"Test/Math/BabyStepGiantStep.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\r\n\r\n#include <iostream>\r\
    \n#include <ranges>\r\n\r\n// begin:tag includes\r\n#line 2 \"Library/Math/BabyStepGiantStep.hpp\"\
    \n\n#include <cmath>\n#include <optional>\n#line 6 \"Library/Math/BabyStepGiantStep.hpp\"\
    \n#include <unordered_set>\n\nnamespace mtd {\n  /*\n   * x^i * s = t (0 <= i\
    \ < n) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ei\n   * O(sqrt(n))\n   */\n \
    \ template <class Hash, class Monoid, class T, class Product, class Op>\n  std::optional<long\
    \ long> baby_step_giant_step(const Monoid& x, const T& s,\n                  \
    \                              const T& t, long long n,\n                    \
    \                            const Product prod,\n                           \
    \                     const Op& op) {\n    if (n == 0) { return (s == t) ? std::make_optional(0)\
    \ : std::nullopt; }\n    if (n == 1) {\n      return (s == t)          ? std::make_optional(0)\n\
    \             : (op(x, s) == t) ? std::make_optional(1)\n                    \
    \           : std::nullopt;\n    }\n\n    auto m = static_cast<long long>(std::sqrt(n));\n\
    \    std::unordered_set<T, Hash> mp;\n    auto xm = x;\n    for (auto i : std::views::iota(0,\
    \ m)) {\n      mp.emplace(op(xm, t));\n      if (i < m - 1) { xm = prod(xm, x);\
    \ }\n    }\n\n    bool find = false;\n    auto xks = s;\n    for (auto k : std::views::iota(1,\
    \ n / m + 5)) {\n      auto next = op(xm, xks);\n      if (mp.contains(next))\
    \ {\n        auto xi = xks;\n        for (auto i : std::views::iota(m * (k - 1),\
    \ m * k + 1)) {\n          if (xi == t) { return i; }\n          xi = op(x, xi);\n\
    \        }\n        if (find) { return std::nullopt; }\n        find = true;\n\
    \      }\n      std::swap(xks, next);\n    }\n    return std::nullopt;\n  }\n\
    };  // namespace mtd\n#line 8 \"Test/Math/BabyStepGiantStep.test.cpp\"\n// end:tag\
    \ includes\r\n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\
    \n  std::ios::sync_with_stdio(0);\r\n\r\n  int t;\r\n  std::cin >> t;\r\n  for\
    \ ([[maybe_unused]] auto _ : std::views::iota(0, t)) {\r\n    ll x, y, m;\r\n\
    \    std::cin >> x >> y >> m;\r\n\r\n    auto ans = (m == 1)\r\n             \
    \      ? 0\r\n                   : mtd::baby_step_giant_step<std::hash<ll>>(\r\
    \n                         x, ll(1), y, m - 1,\r\n                         [&](ll\
    \ _x, ll _y) { return (_x * _y) % m; },\r\n                         [&](const\
    \ ll _m, ll _x) { return (_m * _x) % m; });\r\n\r\n    if (ans) {\r\n      std::cout\
    \ << ans.value() << std::endl;\r\n    } else {\r\n      std::cout << -1 << std::endl;\r\
    \n    }\r\n  }\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \r\n\r\n#include <iostream>\r\n#include <ranges>\r\n\r\n// begin:tag includes\r\
    \n#include \"../../Library/Math/BabyStepGiantStep.hpp\"\r\n// end:tag includes\r\
    \n\r\nusing ll = long long;\r\n\r\nsigned main() {\r\n  std::cin.tie(0);\r\n \
    \ std::ios::sync_with_stdio(0);\r\n\r\n  int t;\r\n  std::cin >> t;\r\n  for ([[maybe_unused]]\
    \ auto _ : std::views::iota(0, t)) {\r\n    ll x, y, m;\r\n    std::cin >> x >>\
    \ y >> m;\r\n\r\n    auto ans = (m == 1)\r\n                   ? 0\r\n       \
    \            : mtd::baby_step_giant_step<std::hash<ll>>(\r\n                 \
    \        x, ll(1), y, m - 1,\r\n                         [&](ll _x, ll _y) { return\
    \ (_x * _y) % m; },\r\n                         [&](const ll _m, ll _x) { return\
    \ (_m * _x) % m; });\r\n\r\n    if (ans) {\r\n      std::cout << ans.value() <<\
    \ std::endl;\r\n    } else {\r\n      std::cout << -1 << std::endl;\r\n    }\r\
    \n  }\r\n}\r\n"
  dependsOn:
  - Library/Math/BabyStepGiantStep.hpp
  isVerificationFile: true
  path: Test/Math/BabyStepGiantStep.test.cpp
  requiredBy: []
  timestamp: '2025-01-09 01:07:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Math/BabyStepGiantStep.test.cpp
layout: document
redirect_from:
- /verify/Test/Math/BabyStepGiantStep.test.cpp
- /verify/Test/Math/BabyStepGiantStep.test.cpp.html
title: Test/Math/BabyStepGiantStep.test.cpp
---
