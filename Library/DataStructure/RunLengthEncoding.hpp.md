---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/RunLengthEncoding.test.cpp
    title: Test/DataStructure/RunLengthEncoding.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/DataStructure/RunLengthEncoding.hpp\"\n\n#include\
    \ <ranges>\n#include <vector>\n\nnamespace mtd {\n  template <std::ranges::range\
    \ _R>\n  class RunLengthEncoding {\n    using T = std::iter_value_t<std::ranges::iterator_t<_R>>;\n\
    \n    const std::vector<std::tuple<T, int>> r;\n\n    static constexpr auto construct_rle(const\
    \ _R& r) {\n      std::vector<std::tuple<T, int>> rle;\n      if (r.empty()) {\
    \ return rle; }\n      T now = *r.begin();\n      int cnt = 1;\n      for (const\
    \ auto& x : r | std::views::drop(1)) {\n        if (x == now) {\n          ++cnt;\n\
    \        } else {\n          rle.emplace_back(now, cnt);\n          cnt = 1;\n\
    \          now = x;\n        }\n      }\n      rle.emplace_back(now, cnt);\n \
    \     return rle;\n    }\n\n  public:\n    constexpr RunLengthEncoding(const _R&\
    \ _r) : r(construct_rle(_r)) {}\n\n    constexpr auto begin() const { return r.begin();\
    \ }\n    constexpr auto end() const { return r.end(); }\n  };\n}  // namespace\
    \ mtd\n"
  code: "#pragma once\n\n#include <ranges>\n#include <vector>\n\nnamespace mtd {\n\
    \  template <std::ranges::range _R>\n  class RunLengthEncoding {\n    using T\
    \ = std::iter_value_t<std::ranges::iterator_t<_R>>;\n\n    const std::vector<std::tuple<T,\
    \ int>> r;\n\n    static constexpr auto construct_rle(const _R& r) {\n      std::vector<std::tuple<T,\
    \ int>> rle;\n      if (r.empty()) { return rle; }\n      T now = *r.begin();\n\
    \      int cnt = 1;\n      for (const auto& x : r | std::views::drop(1)) {\n \
    \       if (x == now) {\n          ++cnt;\n        } else {\n          rle.emplace_back(now,\
    \ cnt);\n          cnt = 1;\n          now = x;\n        }\n      }\n      rle.emplace_back(now,\
    \ cnt);\n      return rle;\n    }\n\n  public:\n    constexpr RunLengthEncoding(const\
    \ _R& _r) : r(construct_rle(_r)) {}\n\n    constexpr auto begin() const { return\
    \ r.begin(); }\n    constexpr auto end() const { return r.end(); }\n  };\n}  //\
    \ namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/DataStructure/RunLengthEncoding.hpp
  requiredBy: []
  timestamp: '2024-12-27 17:07:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/RunLengthEncoding.test.cpp
documentation_of: Library/DataStructure/RunLengthEncoding.hpp
layout: document
redirect_from:
- /library/Library/DataStructure/RunLengthEncoding.hpp
- /library/Library/DataStructure/RunLengthEncoding.hpp.html
title: Library/DataStructure/RunLengthEncoding.hpp
---
