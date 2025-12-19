---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/5/ITP1_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/5/ITP1_5_A
  bundledCode: "#line 1 \"Test/Range/cartesian_product.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/5/ITP1_5_A\"\n\
    #include <iostream>\n\n// begin:tag includes\n#line 2 \"Library/Range/util.hpp\"\
    \n\n#include <algorithm>\n#line 5 \"Library/Range/util.hpp\"\n#include <ranges>\n\
    \n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#include <functional>\n\nnamespace\
    \ mtd {\n  namespace util {\n    template <class F, class T>\n    constexpr auto\
    \ tuple_transform(F&& f, T&& t) {\n      return std::apply(\n          [&]<class...\
    \ Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n#line 8 \"Library/Range/util.hpp\"\n\nnamespace mtd\
    \ {\n  namespace ranges {\n\n    namespace __detail {\n      template <typename...\
    \ T>\n      concept __all_random_access = (std::ranges::random_access_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_bidirectional = (std::ranges::bidirectional_range<T>\
    \ &&\n                                     ...);\n      template <typename...\
    \ T>\n      concept __all_forward = (std::ranges::forward_range<T> && ...);\n\n\
    \      template <class... T>\n      constexpr auto _S_iter_concept() {\n     \
    \   if constexpr (__all_random_access<T...>) {\n          return std::random_access_iterator_tag{};\n\
    \        } else if constexpr (__all_bidirectional<T...>) {\n          return std::bidirectional_iterator_tag{};\n\
    \        } else if constexpr (__all_forward<T...>) {\n          return std::forward_iterator_tag{};\n\
    \        } else {\n          return std::input_iterator_tag{};\n        }\n  \
    \    }\n\n      template <typename T>\n      auto _flatten(const T& t) {\n   \
    \     return std::make_tuple(t);\n      }\n      template <typename... T>\n  \
    \    auto _flatten(const std::tuple<T...>& t);\n\n      template <typename Head,\
    \ typename... Tail>\n      auto _flatten_impl(const Head& head, const Tail&...\
    \ tail) {\n        return std::tuple_cat(_flatten(head), _flatten(tail)...);\n\
    \      }\n      template <typename... T>\n      auto _flatten(const std::tuple<T...>&\
    \ t) {\n        return std::apply(\n            [](const auto&... args) { return\
    \ _flatten_impl(args...); }, t);\n      }\n    }  // namespace __detail\n\n  \
    \  template <std::ranges::range _Range>\n    struct flatten_view\n        : public\
    \ std::ranges::view_interface<flatten_view<_Range>> {\n      class iterator {\n\
    \      public:\n        std::ranges::iterator_t<_Range> _M_current;\n\n      \
    \  using difference_type = std::ranges::range_difference_t<_Range>;\n        using\
    \ value_type = decltype(__detail::_flatten(\n            std::declval<\n     \
    \           std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));\n   \
    \     using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(decltype(_M_current)\
    \ __current)\n            : _M_current(__current) {}\n        constexpr auto operator*()\
    \ const {\n          return __detail::_flatten(*_M_current);\n        }\n    \
    \    constexpr auto& operator++() {\n          ++_M_current;\n          return\
    \ *this;\n        }\n        constexpr auto operator++(int) { return ++*this;\
    \ }\n        constexpr auto operator==(const iterator& other) const {\n      \
    \    return _M_current == other._M_current;\n        }\n        constexpr auto&\
    \ operator--() requires\n            __detail::__all_bidirectional<_Range> {\n\
    \          --_M_current;\n          return *this;\n        }\n        constexpr\
    \ auto operator--(\n            int) requires __detail::__all_bidirectional<_Range>\
    \ {\n          return --*this;\n        }\n        constexpr auto operator<=>(const\
    \ iterator&)\n            const requires __detail::__all_random_access<_Range>\n\
    \        = default;\n        constexpr auto operator-(const iterator& itr)\n \
    \           const requires __detail::__all_random_access<_Range> {\n         \
    \ return _M_current - itr._M_current;\n        }\n        constexpr auto& operator+=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range>\
    \ {\n          _M_current += n;\n          return *this;\n        }\n        constexpr\
    \ auto operator+(const difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __tmp = *this;\n          __tmp += n;\n          return __tmp;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range> {\n          return itr + n;\n \
    \       }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range> {\n          _M_current -=\
    \ n;\n          return *this;\n        }\n        constexpr auto operator-(const\
    \ difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __tmp = *this;\n          __tmp -= n;\n          return __tmp;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range> {\n          return\
    \ __detail::_flatten(_M_current[n]);\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return __x._M_current == __y._M_end;\n\
    \        }\n      };\n\n      _Range _M_views;\n      constexpr explicit flatten_view(const\
    \ _Range& __views)\n          : _M_views(__views) {}\n      constexpr auto begin()\
    \ { return iterator(std::ranges::begin(_M_views)); }\n      constexpr auto end()\
    \ { return sentinel(std::ranges::end(_M_views)); }\n    };\n\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_flatten_view = requires {\n        ranges::flatten_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _Flatten : std::ranges::range_adaptor_closure<_Flatten>\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::flatten_view(std::forward<_Tp>(__e)...);\n      }\n      static\
    \ constexpr bool _S_has_simple_call_op = true;\n    };\n    struct _ProductN {\n\
    \      template <class... _Tp>\n      constexpr auto operator() [[nodiscard]]\
    \ (_Tp... __e) const {\n        return std::views::cartesian_product(std::views::iota(0,\
    \ __e)...);\n      }\n    };\n\n    inline constexpr _Flatten flatten{};\n   \
    \ inline constexpr _ProductN product_n{};\n  }  // namespace views\n}  // namespace\
    \ mtd\n#line 7 \"Test/Range/cartesian_product.test.cpp\"\n// end:tag includes\n\
    \nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  while\
    \ (true) {\n    int h, w;\n    std::cin >> h >> w;\n    if (h == 0 && w == 0)\
    \ { break; }\n\n    for (auto [y, x] : mtd::views::cartesian_product(std::views::iota(0,\
    \ h),\n                                                     std::views::iota(0,\
    \ w))) {\n      std::cout << \"#\";\n      if (x == w - 1) { std::cout << std::endl;\
    \ }\n    }\n    std::cout << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/5/ITP1_5_A\"\
    \n#include <iostream>\n\n// begin:tag includes\n#include \"../../Library/Range/util.hpp\"\
    \n// end:tag includes\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  while (true) {\n    int h, w;\n    std::cin >> h >> w;\n    if (h == 0 &&\
    \ w == 0) { break; }\n\n    for (auto [y, x] : mtd::views::cartesian_product(std::views::iota(0,\
    \ h),\n                                                     std::views::iota(0,\
    \ w))) {\n      std::cout << \"#\";\n      if (x == w - 1) { std::cout << std::endl;\
    \ }\n    }\n    std::cout << std::endl;\n  }\n}\n"
  dependsOn:
  - Library/Range/util.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: true
  path: Test/Range/cartesian_product.test.cpp
  requiredBy: []
  timestamp: '2025-12-20 01:59:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Range/cartesian_product.test.cpp
layout: document
redirect_from:
- /verify/Test/Range/cartesian_product.test.cpp
- /verify/Test/Range/cartesian_product.test.cpp.html
title: Test/Range/cartesian_product.test.cpp
---
