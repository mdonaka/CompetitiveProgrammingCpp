---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Range/template.cpp
    title: Library/Range/template.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Range/enumerate.test.cpp
    title: Test/Range/enumerate.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/util.hpp\"\n\n#include <functional>\n#include\
    \ <iostream>\n#include <ranges>\n\nnamespace mtd {\n  namespace ranges {\n   \
    \ template <std::ranges::range _Range>\n    struct enumerate_view\n        : public\
    \ std::ranges::view_interface<enumerate_view<_Range>> {\n      struct iterator\
    \ {\n        size_t index;\n        _Range::iterator _M_current;\n\n        using\
    \ difference_type = int;\n        // TODO: tuple\u304C\u6E21\u3055\u308C\u305F\
    \u6642\u306Bflat\u306B\u3059\u308B\n        using value_type =\n            std::tuple<size_t,\
    \ typename _Range::iterator::value_type>;\n        using iterator_concept =\n\
    \            std::ranges::iterator_t<_Range>::iterator_concept;\n\n        explicit\
    \ iterator(const typename _Range::iterator& _M_current =\n                   \
    \           typename _Range::iterator{},\n                          size_t index\
    \ = 0)\n            : index(index), _M_current(_M_current) {}\n        auto operator*()\
    \ const { return std::make_tuple(index, *_M_current); }\n        auto& operator++()\
    \ {\n          ++_M_current;\n          ++index;\n          return *this;\n  \
    \      }\n        auto operator++(int) { return ++*this; }\n        auto operator==(const\
    \ iterator& other) const {\n          return _M_current == other._M_current;\n\
    \        }\n        auto& operator--() requires std::ranges::bidirectional_range<_Range>\
    \ {\n          --_M_current;\n          --index;\n          return *this;\n  \
    \      }\n        auto operator--(int) requires std::ranges::bidirectional_range<_Range>\
    \ {\n          return --*this;\n        }\n        auto operator<=>(const iterator&)\n\
    \            const requires std::ranges::random_access_range<_Range>\n       \
    \ = default;\n        auto operator-(const iterator& itr)\n            const requires\
    \ std::ranges::random_access_range<_Range> {\n          return _M_current - itr._M_current;\n\
    \        }\n        auto operator+(const difference_type n)\n            const\
    \ requires std::ranges::random_access_range<_Range> {\n          return iterator(_M_current\
    \ + n, index + n);\n        }\n        auto& operator+=(const difference_type\
    \ n) requires\n            std::ranges::random_access_range<_Range> {\n      \
    \    _M_current += n;\n          index += n;\n          return *this;\n      \
    \  }\n        friend auto operator+(const difference_type n,\n               \
    \               const iterator& itr) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          return itr + n;\n        }\n        auto operator-(const difference_type\
    \ n)\n            const requires std::ranges::random_access_range<_Range> {\n\
    \          return iterator(_M_current - n, index - n);\n        }\n        auto&\
    \ operator-=(const difference_type n) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          _M_current -= n;\n          index -= n;\n          return *this;\n\
    \        }\n        auto operator[](const difference_type n)\n            const\
    \ requires std::ranges::random_access_range<_Range> {\n          return std::make_tuple(index\
    \ + n, _M_current[n]);\n        }\n      };\n\n      class sentinel {\n      \
    \  std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n        constexpr\
    \ explicit sentinel(std::ranges::sentinel_t<_Range>&& __end)\n            : _M_end(std::forward<std::ranges::sentinel_t<_Range>>(__end))\
    \ {}\n\n        friend constexpr bool operator==(const iterator& __x,\n      \
    \                                   const sentinel& __y) {\n          return __x._M_current\
    \ == __y._M_end;\n        }\n      };\n\n      _Range __r = _Range();\n\n    \
    \  enumerate_view() requires std::default_initializable<_Range>\n      = default;\n\
    \      constexpr explicit enumerate_view(const _Range& __r) : __r(__r) {}\n\n\
    \      auto begin() { return iterator(__r.begin()); }\n      auto end() {\n  \
    \      if constexpr (requires() { iterator(__r.end()); }) {\n          return\
    \ iterator(__r.end());\n        } else {\n          return sentinel(__r.end());\n\
    \        }\n      }\n    };\n\n    namespace __detail {\n      template <class\
    \ F, class T>\n      constexpr auto __tuple_transform(F&& f, T&& t) {\n      \
    \  return std::apply(\n            [&]<class... Ts>(Ts&&... elems) {\n       \
    \       return std::tuple<std::invoke_result_t<F&, Ts>...>(\n                \
    \  std::invoke(f, std::forward<Ts>(elems))...);\n            },\n            std::forward<T>(t));\n\
    \      }\n      template <class F, class T>\n      constexpr auto __tuple_for_each(F&&\
    \ f, T&& t) {\n        std::apply(\n            [&]<class... Ts>(Ts&&... elems)\
    \ {\n              (std::invoke(f, std::forward<Ts>(elems)), ...);\n         \
    \   },\n            std::forward<T>(t));\n      }\n    }  // namespace __detail\n\
    \n    template <std::ranges::range... _Range>\n    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      struct iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept = std::input_iterator_tag;\n        // std::ranges::iterator_t<_Range>::iterator_concept;\n\
    \n        constexpr explicit iterator(const decltype(_M_current)& __current)\n\
    \            : _M_current(__current) {}\n        auto operator*() const {\n  \
    \        return __detail::__tuple_transform([](auto& __i) { return *__i; },\n\
    \                                             _M_current);\n        }\n      \
    \  auto& operator++() {\n          __detail::__tuple_for_each([](auto& __i) {\
    \ ++__i; }, _M_current);\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const iterator& other) const {\n\
    \          return _M_current == other._M_current;\n        }\n        // auto&\
    \ operator--() requires std::ranges::bidirectional_range<_Range>\n        // {\n\
    \        //   --_M_current;\n        //   --index;\n        //   return *this;\n\
    \        // }\n        // auto operator--(int) requires\n        // std::ranges::bidirectional_range<_Range>\
    \ {\n        //   return --*this;\n        // }\n        // auto operator<=>(const\
    \ iterator&)\n        //     const requires std::ranges::random_access_range<_Range>\n\
    \        // = default;\n        // auto operator-(const iterator& itr)\n     \
    \   //     const requires std::ranges::random_access_range<_Range> {\n       \
    \ //   return _M_current - itr._M_current;\n        // }\n        // auto operator+(const\
    \ difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return iterator(_M_current + n, index + n);\n        // }\n\
    \        // auto& operator+=(const difference_type n) requires\n        //   \
    \  std::ranges::random_access_range<_Range> {\n        //   _M_current += n;\n\
    \        //   index += n;\n        //   return *this;\n        // }\n        //\
    \ friend auto operator+(const difference_type n,\n        //                 \
    \      const iterator& itr) requires\n        //     std::ranges::random_access_range<_Range>\
    \ {\n        //   return itr + n;\n        // }\n        // auto operator-(const\
    \ difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return iterator(_M_current - n, index - n);\n        // }\n\
    \        // auto& operator-=(const difference_type n) requires\n        //   \
    \  std::ranges::random_access_range<_Range> {\n        //   _M_current -= n;\n\
    \        //   index -= n;\n        //   return *this;\n        // }\n        //\
    \ auto operator[](const difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return std::make_tuple(index + n, _M_current[n]);\n        //\
    \ }\n      };\n\n      class sentinel {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...>\
    \ _M_end;\n\n      public:\n        constexpr explicit sentinel(const decltype(_M_end)&\
    \ __end)\n            : _M_end(__end) {}\n\n        friend constexpr bool operator==(const\
    \ iterator& __x,\n                                         const sentinel& __y)\
    \ {\n          return __x._M_current == __y._M_end;\n        }\n      };\n\n \
    \     std::tuple<_Range...> __r;\n      constexpr explicit zip_view(const _Range&...\
    \ __r) : __r(__r...) {}\n      auto begin() {\n        return iterator(__detail::__tuple_transform(std::ranges::begin,\
    \ __r));\n      }\n      auto end() {\n        return sentinel(__detail::__tuple_transform(std::ranges::end,\
    \ __r));\n      }\n    };\n  }  // namespace ranges\n\n  namespace views {\n \
    \   struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <std::ranges::viewable_range _Range>\n      constexpr auto operator()(_Range&&\
    \ __r) const {\n        return ranges::enumerate_view{std::forward<_Range>(__r)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _Enumerate enumerate{};\n  }  // namespace views\n}  //\
    \ namespace mtd\n"
  code: "#pragma once\n\n#include <functional>\n#include <iostream>\n#include <ranges>\n\
    \nnamespace mtd {\n  namespace ranges {\n    template <std::ranges::range _Range>\n\
    \    struct enumerate_view\n        : public std::ranges::view_interface<enumerate_view<_Range>>\
    \ {\n      struct iterator {\n        size_t index;\n        _Range::iterator\
    \ _M_current;\n\n        using difference_type = int;\n        // TODO: tuple\u304C\
    \u6E21\u3055\u308C\u305F\u6642\u306Bflat\u306B\u3059\u308B\n        using value_type\
    \ =\n            std::tuple<size_t, typename _Range::iterator::value_type>;\n\
    \        using iterator_concept =\n            std::ranges::iterator_t<_Range>::iterator_concept;\n\
    \n        explicit iterator(const typename _Range::iterator& _M_current =\n  \
    \                            typename _Range::iterator{},\n                  \
    \        size_t index = 0)\n            : index(index), _M_current(_M_current)\
    \ {}\n        auto operator*() const { return std::make_tuple(index, *_M_current);\
    \ }\n        auto& operator++() {\n          ++_M_current;\n          ++index;\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n        auto operator==(const iterator& other) const {\n          return\
    \ _M_current == other._M_current;\n        }\n        auto& operator--() requires\
    \ std::ranges::bidirectional_range<_Range> {\n          --_M_current;\n      \
    \    --index;\n          return *this;\n        }\n        auto operator--(int)\
    \ requires std::ranges::bidirectional_range<_Range> {\n          return --*this;\n\
    \        }\n        auto operator<=>(const iterator&)\n            const requires\
    \ std::ranges::random_access_range<_Range>\n        = default;\n        auto operator-(const\
    \ iterator& itr)\n            const requires std::ranges::random_access_range<_Range>\
    \ {\n          return _M_current - itr._M_current;\n        }\n        auto operator+(const\
    \ difference_type n)\n            const requires std::ranges::random_access_range<_Range>\
    \ {\n          return iterator(_M_current + n, index + n);\n        }\n      \
    \  auto& operator+=(const difference_type n) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          _M_current += n;\n          index += n;\n          return *this;\n\
    \        }\n        friend auto operator+(const difference_type n,\n         \
    \                     const iterator& itr) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          return itr + n;\n        }\n        auto operator-(const difference_type\
    \ n)\n            const requires std::ranges::random_access_range<_Range> {\n\
    \          return iterator(_M_current - n, index - n);\n        }\n        auto&\
    \ operator-=(const difference_type n) requires\n            std::ranges::random_access_range<_Range>\
    \ {\n          _M_current -= n;\n          index -= n;\n          return *this;\n\
    \        }\n        auto operator[](const difference_type n)\n            const\
    \ requires std::ranges::random_access_range<_Range> {\n          return std::make_tuple(index\
    \ + n, _M_current[n]);\n        }\n      };\n\n      class sentinel {\n      \
    \  std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n        constexpr\
    \ explicit sentinel(std::ranges::sentinel_t<_Range>&& __end)\n            : _M_end(std::forward<std::ranges::sentinel_t<_Range>>(__end))\
    \ {}\n\n        friend constexpr bool operator==(const iterator& __x,\n      \
    \                                   const sentinel& __y) {\n          return __x._M_current\
    \ == __y._M_end;\n        }\n      };\n\n      _Range __r = _Range();\n\n    \
    \  enumerate_view() requires std::default_initializable<_Range>\n      = default;\n\
    \      constexpr explicit enumerate_view(const _Range& __r) : __r(__r) {}\n\n\
    \      auto begin() { return iterator(__r.begin()); }\n      auto end() {\n  \
    \      if constexpr (requires() { iterator(__r.end()); }) {\n          return\
    \ iterator(__r.end());\n        } else {\n          return sentinel(__r.end());\n\
    \        }\n      }\n    };\n\n    namespace __detail {\n      template <class\
    \ F, class T>\n      constexpr auto __tuple_transform(F&& f, T&& t) {\n      \
    \  return std::apply(\n            [&]<class... Ts>(Ts&&... elems) {\n       \
    \       return std::tuple<std::invoke_result_t<F&, Ts>...>(\n                \
    \  std::invoke(f, std::forward<Ts>(elems))...);\n            },\n            std::forward<T>(t));\n\
    \      }\n      template <class F, class T>\n      constexpr auto __tuple_for_each(F&&\
    \ f, T&& t) {\n        std::apply(\n            [&]<class... Ts>(Ts&&... elems)\
    \ {\n              (std::invoke(f, std::forward<Ts>(elems)), ...);\n         \
    \   },\n            std::forward<T>(t));\n      }\n    }  // namespace __detail\n\
    \n    template <std::ranges::range... _Range>\n    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      struct iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept = std::input_iterator_tag;\n        // std::ranges::iterator_t<_Range>::iterator_concept;\n\
    \n        constexpr explicit iterator(const decltype(_M_current)& __current)\n\
    \            : _M_current(__current) {}\n        auto operator*() const {\n  \
    \        return __detail::__tuple_transform([](auto& __i) { return *__i; },\n\
    \                                             _M_current);\n        }\n      \
    \  auto& operator++() {\n          __detail::__tuple_for_each([](auto& __i) {\
    \ ++__i; }, _M_current);\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const iterator& other) const {\n\
    \          return _M_current == other._M_current;\n        }\n        // auto&\
    \ operator--() requires std::ranges::bidirectional_range<_Range>\n        // {\n\
    \        //   --_M_current;\n        //   --index;\n        //   return *this;\n\
    \        // }\n        // auto operator--(int) requires\n        // std::ranges::bidirectional_range<_Range>\
    \ {\n        //   return --*this;\n        // }\n        // auto operator<=>(const\
    \ iterator&)\n        //     const requires std::ranges::random_access_range<_Range>\n\
    \        // = default;\n        // auto operator-(const iterator& itr)\n     \
    \   //     const requires std::ranges::random_access_range<_Range> {\n       \
    \ //   return _M_current - itr._M_current;\n        // }\n        // auto operator+(const\
    \ difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return iterator(_M_current + n, index + n);\n        // }\n\
    \        // auto& operator+=(const difference_type n) requires\n        //   \
    \  std::ranges::random_access_range<_Range> {\n        //   _M_current += n;\n\
    \        //   index += n;\n        //   return *this;\n        // }\n        //\
    \ friend auto operator+(const difference_type n,\n        //                 \
    \      const iterator& itr) requires\n        //     std::ranges::random_access_range<_Range>\
    \ {\n        //   return itr + n;\n        // }\n        // auto operator-(const\
    \ difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return iterator(_M_current - n, index - n);\n        // }\n\
    \        // auto& operator-=(const difference_type n) requires\n        //   \
    \  std::ranges::random_access_range<_Range> {\n        //   _M_current -= n;\n\
    \        //   index -= n;\n        //   return *this;\n        // }\n        //\
    \ auto operator[](const difference_type n)\n        //     const requires std::ranges::random_access_range<_Range>\
    \ {\n        //   return std::make_tuple(index + n, _M_current[n]);\n        //\
    \ }\n      };\n\n      class sentinel {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...>\
    \ _M_end;\n\n      public:\n        constexpr explicit sentinel(const decltype(_M_end)&\
    \ __end)\n            : _M_end(__end) {}\n\n        friend constexpr bool operator==(const\
    \ iterator& __x,\n                                         const sentinel& __y)\
    \ {\n          return __x._M_current == __y._M_end;\n        }\n      };\n\n \
    \     std::tuple<_Range...> __r;\n      constexpr explicit zip_view(const _Range&...\
    \ __r) : __r(__r...) {}\n      auto begin() {\n        return iterator(__detail::__tuple_transform(std::ranges::begin,\
    \ __r));\n      }\n      auto end() {\n        return sentinel(__detail::__tuple_transform(std::ranges::end,\
    \ __r));\n      }\n    };\n  }  // namespace ranges\n\n  namespace views {\n \
    \   struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <std::ranges::viewable_range _Range>\n      constexpr auto operator()(_Range&&\
    \ __r) const {\n        return ranges::enumerate_view{std::forward<_Range>(__r)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _Enumerate enumerate{};\n  }  // namespace views\n}  //\
    \ namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/util.hpp
  requiredBy:
  - Library/Range/template.cpp
  timestamp: '2024-08-24 17:51:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Range/enumerate.test.cpp
documentation_of: Library/Range/util.hpp
layout: document
redirect_from:
- /library/Library/Range/util.hpp
- /library/Library/Range/util.hpp.html
title: Library/Range/util.hpp
---
