---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Math/Mobius.hpp\"\n\n#include <ranges>\n#include\
    \ <vector>\n\nnamespace mtd::mobius {\n\n  template <class T>\n  auto n(const\
    \ std::vector<T>& a) {\n    auto ret = a;\n    for (auto i : std::views::iota(static_cast<size_t>(1),\
    \ a.size())) {\n      ret[i] = a[i] - a[i - 1];\n    }\n    return ret;\n  }\n\
    \n  template <class T>\n  auto bit_subset(const std::vector<T>& a) {\n    auto\
    \ ret = a;\n    int size = clz(a.size());\n    for (auto b : std::views::iota(0,\
    \ size)) {\n      for (auto bit : std::views::iota(0, 1LL << size)) {\n      \
    \  if (((bit >> b) & 1) && bit < a.size()) {\n          ret[bit] -= ret[bit ^\
    \ (1LL << b)];\n        }\n      }\n    }\n    return ret;\n  }\n\n}  // namespace\
    \ mtd::mobius\n"
  code: "\n#include <ranges>\n#include <vector>\n\nnamespace mtd::mobius {\n\n  template\
    \ <class T>\n  auto n(const std::vector<T>& a) {\n    auto ret = a;\n    for (auto\
    \ i : std::views::iota(static_cast<size_t>(1), a.size())) {\n      ret[i] = a[i]\
    \ - a[i - 1];\n    }\n    return ret;\n  }\n\n  template <class T>\n  auto bit_subset(const\
    \ std::vector<T>& a) {\n    auto ret = a;\n    int size = clz(a.size());\n   \
    \ for (auto b : std::views::iota(0, size)) {\n      for (auto bit : std::views::iota(0,\
    \ 1LL << size)) {\n        if (((bit >> b) & 1) && bit < a.size()) {\n       \
    \   ret[bit] -= ret[bit ^ (1LL << b)];\n        }\n      }\n    }\n    return\
    \ ret;\n  }\n\n}  // namespace mtd::mobius\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Math/Mobius.hpp
  requiredBy: []
  timestamp: '2024-11-06 14:52:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Math/Mobius.hpp
layout: document
redirect_from:
- /library/Library/Math/Mobius.hpp
- /library/Library/Math/Mobius.hpp.html
title: Library/Math/Mobius.hpp
---
