---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Range/mystd/enumerate.test.cpp
    title: Test/Range/mystd/enumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Library/Range/mystd.hpp\"\n#include <ranges>\n#include <vector>\n\
    namespace myranges {\n\nstruct enumerate_view : public std::ranges::view_interface<enumerate_view>\
    \ {\n  using C = std::vector<int>;\n\n  class iterator {\n    size_t index;\n\
    \    C::const_iterator itr;\n\n  public:\n    using difference_type = int;\n \
    \   using value_type = std::tuple<size_t, C::value_type>;\n    using iterator_concept\
    \ = std::input_iterator_tag;\n\n    explicit iterator(const C::const_iterator&\
    \ itr = C::const_iterator{})\n        : index(0), itr(itr) {}\n    auto operator*()\
    \ const { return std::make_tuple(index, *itr); }\n    auto& operator++() {\n \
    \     ++itr;\n      ++index;\n      return *this;\n    }\n    auto operator++(int)\
    \ { return ++*this; }\n    auto operator==(const iterator& other) const { return\
    \ itr == other.itr; }\n  };\n\n  C c;\n\n  explicit enumerate_view(const C& c)\
    \ : c(c) {}\n  auto begin() const { return iterator(c.begin()); }\n  auto end()\
    \ const { return iterator(c.end()); }\n};\n\nstruct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure\
    \ {\n  template <std::ranges::viewable_range _Range>\n  constexpr auto operator()(_Range&&\
    \ __r) const {\n    return enumerate_view{std::forward<_Range>(__r)};\n  }\n \
    \ static constexpr bool _S_has_simple_call_op = true;\n};\n\ninline constexpr\
    \ _Enumerate enumerate{};\n\n}  // namespace myranges\n"
  code: "#include <ranges>\n#include <vector>\nnamespace myranges {\n\nstruct enumerate_view\
    \ : public std::ranges::view_interface<enumerate_view> {\n  using C = std::vector<int>;\n\
    \n  class iterator {\n    size_t index;\n    C::const_iterator itr;\n\n  public:\n\
    \    using difference_type = int;\n    using value_type = std::tuple<size_t, C::value_type>;\n\
    \    using iterator_concept = std::input_iterator_tag;\n\n    explicit iterator(const\
    \ C::const_iterator& itr = C::const_iterator{})\n        : index(0), itr(itr)\
    \ {}\n    auto operator*() const { return std::make_tuple(index, *itr); }\n  \
    \  auto& operator++() {\n      ++itr;\n      ++index;\n      return *this;\n \
    \   }\n    auto operator++(int) { return ++*this; }\n    auto operator==(const\
    \ iterator& other) const { return itr == other.itr; }\n  };\n\n  C c;\n\n  explicit\
    \ enumerate_view(const C& c) : c(c) {}\n  auto begin() const { return iterator(c.begin());\
    \ }\n  auto end() const { return iterator(c.end()); }\n};\n\nstruct _Enumerate\
    \ : std::views::__adaptor::_RangeAdaptorClosure {\n  template <std::ranges::viewable_range\
    \ _Range>\n  constexpr auto operator()(_Range&& __r) const {\n    return enumerate_view{std::forward<_Range>(__r)};\n\
    \  }\n  static constexpr bool _S_has_simple_call_op = true;\n};\n\ninline constexpr\
    \ _Enumerate enumerate{};\n\n}  // namespace myranges\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/mystd.hpp
  requiredBy: []
  timestamp: '2024-08-02 16:17:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Range/mystd/enumerate.test.cpp
documentation_of: Library/Range/mystd.hpp
layout: document
redirect_from:
- /library/Library/Range/mystd.hpp
- /library/Library/Range/mystd.hpp.html
title: Library/Range/mystd.hpp
---
