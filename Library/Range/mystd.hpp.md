---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Range/mystd/enumerate.test.cpp
    title: Test/Range/mystd/enumerate.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/mystd.hpp\"\n\n#include <ranges>\n\nnamespace\
    \ myranges {\n\n  template <std::ranges::range _Range>\n  struct enumerate_view\n\
    \      : public std::ranges::view_interface<enumerate_view<_Range>> {\n    class\
    \ iterator {\n      size_t index;\n      _Range::const_iterator itr;\n\n    public:\n\
    \      using difference_type = int;\n      using value_type = std::tuple<size_t,\
    \ typename _Range::value_type>;\n      using iterator_concept = std::input_iterator_tag;\n\
    \n      explicit iterator(const typename _Range::const_iterator& itr =\n     \
    \                       typename _Range::const_iterator{})\n          : index(0),\
    \ itr(itr) {}\n      auto operator*() const { return std::make_tuple(index, *itr);\
    \ }\n      auto& operator++() {\n        ++itr;\n        ++index;\n        return\
    \ *this;\n      }\n      auto operator++(int) { return ++*this; }\n      auto\
    \ operator==(const iterator& other) const { return itr == other.itr; }\n    };\n\
    \n    _Range __r = _Range();\n\n    enumerate_view() requires std::default_initializable<_Range>\n\
    \    = default;\n    constexpr explicit enumerate_view(const _Range& __r) : __r(__r)\
    \ {}\n\n    auto begin() const { return iterator(__r.begin()); }\n    auto end()\
    \ const { return iterator(__r.end()); }\n  };\n\n  namespace views {\n    struct\
    \ _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {\n      template <std::ranges::viewable_range\
    \ _Range>\n      constexpr auto operator()(_Range&& __r) const {\n        return\
    \ enumerate_view{std::forward<_Range>(__r)};\n      }\n      static constexpr\
    \ bool _S_has_simple_call_op = true;\n    };\n\n    inline constexpr _Enumerate\
    \ enumerate{};\n  }  // namespace views\n}  // namespace myranges\n"
  code: "#pragma once\n\n#include <ranges>\n\nnamespace myranges {\n\n  template <std::ranges::range\
    \ _Range>\n  struct enumerate_view\n      : public std::ranges::view_interface<enumerate_view<_Range>>\
    \ {\n    class iterator {\n      size_t index;\n      _Range::const_iterator itr;\n\
    \n    public:\n      using difference_type = int;\n      using value_type = std::tuple<size_t,\
    \ typename _Range::value_type>;\n      using iterator_concept = std::input_iterator_tag;\n\
    \n      explicit iterator(const typename _Range::const_iterator& itr =\n     \
    \                       typename _Range::const_iterator{})\n          : index(0),\
    \ itr(itr) {}\n      auto operator*() const { return std::make_tuple(index, *itr);\
    \ }\n      auto& operator++() {\n        ++itr;\n        ++index;\n        return\
    \ *this;\n      }\n      auto operator++(int) { return ++*this; }\n      auto\
    \ operator==(const iterator& other) const { return itr == other.itr; }\n    };\n\
    \n    _Range __r = _Range();\n\n    enumerate_view() requires std::default_initializable<_Range>\n\
    \    = default;\n    constexpr explicit enumerate_view(const _Range& __r) : __r(__r)\
    \ {}\n\n    auto begin() const { return iterator(__r.begin()); }\n    auto end()\
    \ const { return iterator(__r.end()); }\n  };\n\n  namespace views {\n    struct\
    \ _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {\n      template <std::ranges::viewable_range\
    \ _Range>\n      constexpr auto operator()(_Range&& __r) const {\n        return\
    \ enumerate_view{std::forward<_Range>(__r)};\n      }\n      static constexpr\
    \ bool _S_has_simple_call_op = true;\n    };\n\n    inline constexpr _Enumerate\
    \ enumerate{};\n  }  // namespace views\n}  // namespace myranges\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/mystd.hpp
  requiredBy: []
  timestamp: '2024-08-03 20:25:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Range/mystd/enumerate.test.cpp
documentation_of: Library/Range/mystd.hpp
layout: document
redirect_from:
- /library/Library/Range/mystd.hpp
- /library/Library/Range/mystd.hpp.html
title: Library/Range/mystd.hpp
---
