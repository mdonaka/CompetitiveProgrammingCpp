---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  - icon: ':question:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/RunLengthEncoding.test.cpp
    title: Test/DataStructure/RunLengthEncoding.test.cpp
  - icon: ':x:'
    path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
    title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Convolution_and.test.cpp
    title: Test/Math/Convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math.test.cpp
    title: Test/Math/Math.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_dynamic.test.cpp
    title: Test/Math/Math_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_pow.test.cpp
    title: Test/Math/Math_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Math_pow_dynamic.test.cpp
    title: Test/Math/Math_pow_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/enumerate.test.cpp
    title: Test/Range/enumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/flatten.test.cpp
    title: Test/Range/flatten.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Range/zip.test.cpp
    title: Test/Range/zip.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/istream.hpp\"\n\n#include <ranges>\n\n#line\
    \ 2 \"Library/Utility/io.hpp\"\n\n#include <iostream>\n#line 5 \"Library/Utility/io.hpp\"\
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
    \n    namespace type {\n      template <class T>\n      struct vec {\n       \
    \ using value_type = T;\n      };\n      template <class T>\n      concept is_vec\
    \ = requires {\n        requires std::is_same_v<T, vec<typename T::value_type>>;\n\
    \      };\n\n      template <class T>\n      struct mat {\n        using value_type\
    \ = T;\n      };\n      template <class T>\n      concept is_mat = requires {\n\
    \        requires std::is_same_v<T, mat<typename T::value_type>>;\n      };\n\
    \    }  // namespace type\n\n    template <class T>\n    auto _input() {\n   \
    \   T x;\n      std::cin >> x;\n      return x;\n    }\n    template <typename\
    \ T>\n    requires requires { typename std::tuple_size<T>::type; }\n    auto _input()\
    \ {\n      T x;\n      util::tuple_for_each([](auto&& i) { std::cin >> i; }, x);\n\
    \      return x;\n    }\n    template <type::is_vec T>\n    auto _input(int n)\
    \ {\n      std::vector<typename T::value_type> v;\n      v.reserve(n);\n     \
    \ for (auto i : std::views::iota(0, n)) {\n        v.emplace_back(_input<typename\
    \ T::value_type>());\n      }\n      return v;\n    }\n    template <type::is_mat\
    \ T>\n    auto _input(int h, int w) {\n      std::vector<std::vector<typename\
    \ T::value_type>> mat;\n      mat.reserve(h);\n      for (auto i : std::views::iota(0,\
    \ h)) {\n        mat.emplace_back(_input<type::vec<typename T::value_type>>(w));\n\
    \      }\n      return mat;\n    }\n\n    template <int N, class Tuple, class\
    \ T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple& t, Sizes...\
    \ sizes);\n    template <int N, class Tuple, type::is_vec T, class... Args, class\
    \ Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t, Size size,\
    \ Sizes... sizes);\n    template <int N, class Tuple, type::is_mat T, class...\
    \ Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes);\n\n    template <int N, class\
    \ Tuple, class T, class... Args, class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Sizes... sizes) {\n      std::get<N>(t) = _input<T>();\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);\n\
    \      }\n    }\n    template <int N, class Tuple, type::is_vec T, class... Args,\
    \ class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple& t,\
    \ Size size, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size);\n    \
    \  if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t,\
    \ sizes...);\n      }\n    }\n    template <int N, class Tuple, type::is_mat T,\
    \ class... Args, class Size,\n              class... Sizes>\n    auto _tuple_input(Tuple&\
    \ t, Size size_h, Size size_w, Sizes... sizes) {\n      std::get<N>(t) = _input<T>(size_h,\
    \ size_w);\n      if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N\
    \ + 1, Tuple, Args...>(t, sizes...);\n      }\n    }\n\n    template <class T>\n\
    \    struct _Converter {\n      using type = T;\n    };\n    template <class T>\n\
    \    struct _Converter<type::vec<T>> {\n      using type = std::vector<T>;\n \
    \   };\n    template <class T>\n    struct _Converter<type::mat<T>> {\n      using\
    \ type = std::vector<std::vector<T>>;\n    };\n\n    template <class... Args,\
    \ class... Sizes>\n    requires(std::convertible_to<Sizes, size_t>&&...) auto\
    \ in(Sizes... sizes) {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base, sizes...);\n      return\
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
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
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <ranges>\n\n#include \"../Utility/io.hpp\"\n\nnamespace\
    \ mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n    template\
    \ <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
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
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n"
  dependsOn:
  - Library/Utility/io.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: false
  path: Library/Range/istream.hpp
  requiredBy: []
  timestamp: '2024-12-27 16:26:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/DataStructure/RunLengthEncoding.test.cpp
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - Test/Range/flatten.test.cpp
  - Test/Range/enumerate.test.cpp
  - Test/Range/zip.test.cpp
  - Test/Math/Convolution_and.test.cpp
  - Test/Math/Math_dynamic.test.cpp
  - Test/Math/Math_pow_dynamic.test.cpp
  - Test/Math/Math.test.cpp
  - Test/Math/Math_pow.test.cpp
documentation_of: Library/Range/istream.hpp
layout: document
redirect_from:
- /library/Library/Range/istream.hpp
- /library/Library/Range/istream.hpp.html
title: Library/Range/istream.hpp
---
