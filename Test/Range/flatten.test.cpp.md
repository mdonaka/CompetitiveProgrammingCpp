---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':x:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  - icon: ':question:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
  bundledCode: "#line 1 \"Test/Range/flatten.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\n#include\
    \ <iostream>\n\n// begin:tag includes\n#line 2 \"Library/Range/istream.hpp\"\n\
    \n#include <ranges>\n\n#line 2 \"Library/Utility/io.hpp\"\n\n#line 5 \"Library/Utility/io.hpp\"\
    \n#include <type_traits>\n#include <vector>\n\n#line 2 \"Library/Utility/Tuple.hpp\"\
    \n\n#include <functional>\n\nnamespace mtd {\n  namespace util {\n    template\
    \ <class F, class T>\n    constexpr auto tuple_transform(F&& f, T&& t) {\n   \
    \   return std::apply(\n          [&]<class... Ts>(Ts&&... elems) {\n        \
    \    return std::tuple<std::invoke_result_t<F&, Ts>...>(\n                std::invoke(f,\
    \ std::forward<Ts>(elems))...);\n          },\n          std::forward<T>(t));\n\
    \    }\n    template <class F, class T>\n    constexpr auto tuple_for_each(F&&\
    \ f, T&& t) {\n      std::apply(\n          [&]<class... Ts>(Ts&&... elems) {\n\
    \            (std::invoke(f, std::forward<Ts>(elems)), ...);\n          },\n \
    \         std::forward<T>(t));\n    }\n  }  // namespace util\n}  // namespace\
    \ mtd\n#line 9 \"Library/Utility/io.hpp\"\n\nnamespace mtd {\n  namespace io {\n\
    \n    namespace __details {\n      template <typename T>\n      concept is_vec\
    \ = std::same_as<\n          T, std::vector<typename T::value_type, typename T::allocator_type>>;\n\
    \      template <typename T>\n      concept is_mat = is_vec<T> && is_vec<typename\
    \ T::value_type>;\n\n    }  // namespace __details\n\n    template <class T>\n\
    \    constexpr auto _input() {\n      T x;\n      std::cin >> x;\n      return\
    \ x;\n    }\n    template <typename T>\n    requires requires { typename std::tuple_size<T>::type;\
    \ }\n    constexpr auto _input() {\n      T x;\n      util::tuple_for_each([](auto&&\
    \ i) { std::cin >> i; }, x);\n      return x;\n    }\n    template <__details::is_vec\
    \ T>\n    constexpr auto _input(int n) {\n      std::vector<typename T::value_type>\
    \ v;\n      v.reserve(n);\n      for (auto i : std::views::iota(0, n)) {\n   \
    \     v.emplace_back(_input<typename T::value_type>());\n      }\n      return\
    \ v;\n    }\n    template <__details::is_mat T>\n    constexpr auto _input(int\
    \ h, int w) {\n      T mat;\n      mat.reserve(h);\n      for (auto i : std::views::iota(0,\
    \ h)) {\n        mat.emplace_back(_input<typename T::value_type>(w));\n      }\n\
    \      return mat;\n    }\n\n    template <int N, class Tuple, class T, class...\
    \ Args, class... Sizes>\n    constexpr auto _tuple_input(Tuple& t, Sizes... sizes);\n\
    \    template <int N, class Tuple, __details::is_vec T, class... Args,\n     \
    \         class Size, class... Sizes>\n    constexpr auto _tuple_input(Tuple&\
    \ t, Size size, Sizes... sizes);\n    template <int N, class Tuple, __details::is_mat\
    \ T, class... Args,\n              class Size, class... Sizes>\n    constexpr\
    \ auto _tuple_input(Tuple& t, Size size_h, Size size_w,\n                    \
    \            Sizes... sizes);\n\n    template <int N, class Tuple, class T, class...\
    \ Args, class... Sizes>\n    constexpr auto _tuple_input(Tuple& t, Sizes... sizes)\
    \ {\n      std::get<N>(t) = _input<T>();\n      if constexpr (sizeof...(Args)\
    \ > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);\n      }\n\
    \    }\n    template <int N, class Tuple, __details::is_vec T, class... Args,\n\
    \              class Size, class... Sizes>\n    constexpr auto _tuple_input(Tuple&\
    \ t, Size size, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size);\n \
    \     if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple,\
    \ Args...>(t, sizes...);\n      }\n    }\n    template <int N, class Tuple, __details::is_mat\
    \ T, class... Args,\n              class Size, class... Sizes>\n    constexpr\
    \ auto _tuple_input(Tuple& t, Size size_h, Size size_w,\n                    \
    \            Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size_h, size_w);\n\
    \      if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple,\
    \ Args...>(t, sizes...);\n      }\n    }\n\n    template <class... Args, class...\
    \ Sizes>\n    requires(std::convertible_to<Sizes, size_t>&&...) constexpr auto\
    \ in(\n        Sizes... sizes) {\n      auto base = std::tuple<Args...>();\n \
    \     _tuple_input<0, decltype(base), Args...>(base, sizes...);\n      return\
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<Args...> val;\n\
    \n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ _count) : count(_count) {\n          operator++();\n        }\n\n        constexpr\
    \ auto operator*() const { return val; }\n        constexpr auto& operator++()\
    \ {\n          --count;\n          if (count >= 0) { val = io::in<Args...>();\
    \ }\n          return *this;\n        }\n        constexpr auto operator++(int)\
    \ { return ++*this; }\n\n        constexpr auto operator==(const iterator& s)\
    \ const {\n          return count == s.count;\n        }\n        constexpr auto\
    \ operator==(std::default_sentinel_t) const {\n          return count < 0 || std::cin.eof()\
    \ || std::cin.fail() ||\n                 std::cin.bad();\n        }\n       \
    \ constexpr friend auto operator==(std::default_sentinel_t s,\n              \
    \                           const iterator& li) {\n          return li == s;\n\
    \        }\n      };\n\n      int count;\n\n    public:\n      constexpr explicit\
    \ istream_view(int _count) : count(_count) {}\n      constexpr explicit istream_view()\
    \ : istream_view(_inf) {}\n      constexpr auto begin() const { return iterator(count);\
    \ }\n      constexpr auto end() const { return std::default_sentinel; }\n    };\n\
    \  }  // namespace ranges\n\n  namespace views {\n    namespace __detail {\n \
    \     template <typename... _Args>\n      concept __can_istream_view = requires\
    \ {\n        ranges::istream_view(std::declval<_Args>()...);\n      };\n    }\
    \  // namespace __detail\n\n    template <class... Args>\n    struct _Istream\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 2 \"Library/Range/util.hpp\"\
    \n\n#include <algorithm>\n#line 6 \"Library/Range/util.hpp\"\n\n#line 8 \"Library/Range/util.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    namespace __detail {\n      template\
    \ <typename... T>\n      concept __all_random_access = (std::ranges::random_access_range<T>\
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
    \ mtd\n#line 8 \"Test/Range/flatten.test.cpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  for (auto [i, x]\
    \ : mtd::views::istream<int>() | std::views::enumerate |\n                   \
    \      mtd::views::flatten) {\n    if (x == 0) { break; }\n    std::cout << \"\
    Case \" << i + 1 << \": \" << x << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\
    \n#include <iostream>\n\n// begin:tag includes\n#include \"../../Library/Range/istream.hpp\"\
    \n#include \"../../Library/Range/util.hpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  for (auto [i, x]\
    \ : mtd::views::istream<int>() | std::views::enumerate |\n                   \
    \      mtd::views::flatten) {\n    if (x == 0) { break; }\n    std::cout << \"\
    Case \" << i + 1 << \": \" << x << std::endl;\n  }\n}\n"
  dependsOn:
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Utility/Tuple.hpp
  - Library/Range/util.hpp
  isVerificationFile: true
  path: Test/Range/flatten.test.cpp
  requiredBy: []
  timestamp: '2025-12-20 02:07:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Range/flatten.test.cpp
layout: document
redirect_from:
- /verify/Test/Range/flatten.test.cpp
- /verify/Test/Range/flatten.test.cpp.html
title: Test/Range/flatten.test.cpp
---
