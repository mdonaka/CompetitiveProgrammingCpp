---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Normal/Topological.hpp
    title: Library/Graph/Normal/Topological.hpp
  - icon: ':question:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':question:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  - icon: ':question:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/DataStructure/RunLengthEncoding.test.cpp
    title: Test/DataStructure/RunLengthEncoding.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
    title: Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Graph/Normal/Topological.test.cpp
    title: Test/Graph/Normal/Topological.test.cpp
  - icon: ':x:'
    path: Test/Math/Convolution_and.test.cpp
    title: Test/Math/Convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Math/EuclideanAlgorithm_gcd.test.cpp
    title: Test/Math/EuclideanAlgorithm_gcd.test.cpp
  - icon: ':x:'
    path: Test/Math/Math.test.cpp
    title: Test/Math/Math.test.cpp
  - icon: ':x:'
    path: Test/Math/Math_dynamic.test.cpp
    title: Test/Math/Math_dynamic.test.cpp
  - icon: ':x:'
    path: Test/Math/Math_pow.test.cpp
    title: Test/Math/Math_pow.test.cpp
  - icon: ':x:'
    path: Test/Math/Math_pow_dynamic.test.cpp
    title: Test/Math/Math_pow_dynamic.test.cpp
  - icon: ':x:'
    path: Test/Range/enumerate.test.cpp
    title: Test/Range/enumerate.test.cpp
  - icon: ':x:'
    path: Test/Range/flatten.test.cpp
    title: Test/Range/flatten.test.cpp
  - icon: ':x:'
    path: Test/Range/zip.test.cpp
    title: Test/Range/zip.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/Tuple.hpp\"\n\n#include <functional>\n\n\
    namespace mtd {\n  namespace util {\n    template <class F, class T>\n    constexpr\
    \ auto tuple_transform(F&& f, T&& t) {\n      return std::apply(\n          [&]<class...\
    \ Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <functional>\n\nnamespace mtd {\n  namespace util\
    \ {\n    template <class F, class T>\n    constexpr auto tuple_transform(F&& f,\
    \ T&& t) {\n      return std::apply(\n          [&]<class... Ts>(Ts&&... elems)\
    \ {\n            return std::tuple<std::invoke_result_t<F&, Ts>...>(\n       \
    \         std::invoke(f, std::forward<Ts>(elems))...);\n          },\n       \
    \   std::forward<T>(t));\n    }\n    template <class F, class T>\n    constexpr\
    \ auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n          [&]<class...\
    \ Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/Tuple.hpp
  requiredBy:
  - Library/Range/istream.hpp
  - Library/Range/util.hpp
  - Library/Graph/Normal/Topological.hpp
  - Library/Utility/io.hpp
  timestamp: '2024-12-17 23:51:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Range/zip.test.cpp
  - Test/Range/enumerate.test.cpp
  - Test/Range/flatten.test.cpp
  - Test/Graph/Normal/Topological.test.cpp
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - Test/Math/Math_pow.test.cpp
  - Test/Math/Convolution_and.test.cpp
  - Test/Math/EuclideanAlgorithm_gcd.test.cpp
  - Test/Math/Math.test.cpp
  - Test/Math/Math_pow_dynamic.test.cpp
  - Test/Math/Math_dynamic.test.cpp
  - Test/DataStructure/RunLengthEncoding.test.cpp
documentation_of: Library/Utility/Tuple.hpp
layout: document
redirect_from:
- /library/Library/Utility/Tuple.hpp
- /library/Library/Utility/Tuple.hpp.html
title: Library/Utility/Tuple.hpp
---
