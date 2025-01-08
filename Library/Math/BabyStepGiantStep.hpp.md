---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Math/BabyStepGiantStep.test.cpp
    title: Test/Math/BabyStepGiantStep.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Math/BabyStepGiantStep.hpp\"\n\n#include <cmath>\n\
    #include <optional>\n#include <ranges>\n#include <unordered_set>\n\nnamespace\
    \ mtd {\n  /*\n   * x^i * s = t (0 <= i < n) \u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306Ei\n   * O(sqrt(n))\n   */\n  template <class Hash, class Monoid, class T,\
    \ class Product, class Op>\n  std::optional<long long> baby_step_giant_step(const\
    \ Monoid& x, const T& s,\n                                                const\
    \ T& t, long long n,\n                                                const Product\
    \ prod,\n                                                const Op& op) {\n   \
    \ if (n == 0) { return (s == t) ? std::make_optional(0) : std::nullopt; }\n  \
    \  if (n == 1) {\n      return (s == t)          ? std::make_optional(0)\n   \
    \          : (op(x, s) == t) ? std::make_optional(1)\n                       \
    \        : std::nullopt;\n    }\n\n    auto m = static_cast<long long>(std::sqrt(n));\n\
    \    std::unordered_set<T, Hash> mp;\n    auto xm = x;\n    for (auto i : std::views::iota(0,\
    \ m)) {\n      mp.emplace(op(xm, t));\n      if (i < m - 1) { xm = prod(xm, x);\
    \ }\n    }\n\n    bool find = false;\n    auto xks = s;\n    for (auto k : std::views::iota(1,\
    \ n / m + 5)) {\n      auto next = op(xm, xks);\n      if (mp.contains(next))\
    \ {\n        auto xi = xks;\n        for (auto i : std::views::iota(m * (k - 1),\
    \ m * k + 1)) {\n          if (xi == t) { return i; }\n          xi = op(x, xi);\n\
    \        }\n        if (find) { return std::nullopt; }\n        find = true;\n\
    \      }\n      std::swap(xks, next);\n    }\n    return std::nullopt;\n  }\n\
    };  // namespace mtd\n"
  code: "#pragma once\n\n#include <cmath>\n#include <optional>\n#include <ranges>\n\
    #include <unordered_set>\n\nnamespace mtd {\n  /*\n   * x^i * s = t (0 <= i <\
    \ n) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306Ei\n   * O(sqrt(n))\n   */\n  template\
    \ <class Hash, class Monoid, class T, class Product, class Op>\n  std::optional<long\
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
    };  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/BabyStepGiantStep.hpp
  requiredBy: []
  timestamp: '2025-01-09 01:07:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Math/BabyStepGiantStep.test.cpp
documentation_of: Library/Math/BabyStepGiantStep.hpp
layout: document
redirect_from:
- /library/Library/Math/BabyStepGiantStep.hpp
- /library/Library/Math/BabyStepGiantStep.hpp.html
title: Library/Math/BabyStepGiantStep.hpp
---
