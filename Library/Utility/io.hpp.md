---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/RunLengthEncoding.test.cpp
    title: Test/DataStructure/RunLengthEncoding.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
    title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/Convolution_and.test.cpp
    title: Test/Math/Convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/EuclideanAlgorithm_gcd.test.cpp
    title: Test/Math/EuclideanAlgorithm_gcd.test.cpp
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
    path: Test/Range/flatten.test.cpp
    title: Test/Range/flatten.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/io.hpp\"\n\n#include <iostream>\n#include\
    \ <ranges>\n#include <type_traits>\n#include <vector>\n\n#line 2 \"Library/Utility/Tuple.hpp\"\
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
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <ranges>\n#include <type_traits>\n\
    #include <vector>\n\n#include \"Tuple.hpp\"\n\nnamespace mtd {\n  namespace io\
    \ {\n\n    namespace __details {\n      template <typename T>\n      concept is_vec\
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
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n"
  dependsOn:
  - Library/Utility/Tuple.hpp
  isVerificationFile: false
  path: Library/Utility/io.hpp
  requiredBy:
  - Library/Range/istream.hpp
  timestamp: '2025-07-06 21:41:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/DataStructure/RunLengthEncoding.test.cpp
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - Test/Range/flatten.test.cpp
  - Test/Math/Math_pow_dynamic.test.cpp
  - Test/Math/Math_dynamic.test.cpp
  - Test/Math/EuclideanAlgorithm_gcd.test.cpp
  - Test/Math/Convolution_and.test.cpp
  - Test/Math/Math.test.cpp
  - Test/Math/Math_pow.test.cpp
documentation_of: Library/Utility/io.hpp
layout: document
redirect_from:
- /library/Library/Utility/io.hpp
- /library/Library/Utility/io.hpp.html
title: Library/Utility/io.hpp
---
