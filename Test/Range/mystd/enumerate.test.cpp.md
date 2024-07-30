---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Range/mystd.hpp
    title: Library/Range/mystd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
  bundledCode: "#line 1 \"Test/Range/mystd/enumerate.test.cpp\"\n#define PROBLEM \\\
    \n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\n#include\
    \ <iostream>\n\n// tag:includes begin\n#line 1 \"Library/Range/mystd.hpp\"\n#include\
    \ <ranges>\n#include <vector>\nnamespace myranges {\n\nstruct enumerate_view :\
    \ public std::ranges::view_interface<enumerate_view> {\n  using C = std::vector<int>;\n\
    \n  class iterator {\n    size_t index;\n    C::const_iterator itr;\n\n  public:\n\
    \    using difference_type = int;\n    using value_type = std::tuple<size_t, C::value_type>;\n\
    \    using iterator_concept = std::input_iterator_tag;\n\n    explicit iterator(const\
    \ C::const_iterator& itr = C::const_iterator{})\n        : index(0), itr(itr)\
    \ {}\n    auto operator*() const { return std::make_tuple(index, *itr); }\n  \
    \  auto& operator++() {\n      ++itr;\n      ++index;\n      return *this;\n \
    \   }\n    auto operator++(int) { return ++*this; }\n    auto operator==(const\
    \ iterator& other) const { return itr == other.itr; }\n  };\n\n  C c;\n\n  explicit\
    \ enumerate_view(const C& c) : c(c) {}\n  auto begin() const { return iterator(c.begin());\
    \ }\n  auto end() const { return iterator(c.end()); }\n};\n\n}  // namespace myranges\n\
    #line 7 \"Test/Range/mystd/enumerate.test.cpp\"\n// tag:includes end\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  std::vector<int>\
    \ v;\n  while (std::cin) {\n    int x;\n    std::cin >> x;\n    v.emplace_back(x);\n\
    \  }\n\n  for (auto [i, x] : myranges::enumerate_view(v) |\n                 \
    \        std::views::filter([](const std::tuple<int, int>& t) {\n            \
    \               return std::get<1>(t) > 0;\n                         })) {\n \
    \   std::cout << \"Case \" << i + 1 << \": \" << x << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\
    \n#include <iostream>\n\n// tag:includes begin\n#include \"../../../Library/Range/mystd.hpp\"\
    \n// tag:includes end\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  std::vector<int> v;\n  while (std::cin) {\n    int x;\n    std::cin >> x;\n\
    \    v.emplace_back(x);\n  }\n\n  for (auto [i, x] : myranges::enumerate_view(v)\
    \ |\n                         std::views::filter([](const std::tuple<int, int>&\
    \ t) {\n                           return std::get<1>(t) > 0;\n              \
    \           })) {\n    std::cout << \"Case \" << i + 1 << \": \" << x << std::endl;\n\
    \  }\n}\n"
  dependsOn:
  - Library/Range/mystd.hpp
  isVerificationFile: true
  path: Test/Range/mystd/enumerate.test.cpp
  requiredBy: []
  timestamp: '2024-07-30 22:33:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Range/mystd/enumerate.test.cpp
layout: document
redirect_from:
- /verify/Test/Range/mystd/enumerate.test.cpp
- /verify/Test/Range/mystd/enumerate.test.cpp.html
title: Test/Range/mystd/enumerate.test.cpp
---
