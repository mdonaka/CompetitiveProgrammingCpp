---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Debug/Dump.hpp
    title: Library/Debug/Dump.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Main/includes.hpp
    title: Library/Main/includes.hpp
  - icon: ':warning:'
    path: Library/Main/main.cpp
    title: Library/Main/main.cpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':warning:'
    path: Library/Range/template.cpp
    title: Library/Range/template.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
    title: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Utility/io.hpp\"\n\n#include <iostream>\n#include\
    \ <ranges>\n#include <type_traits>\n#include <vector>\n\n#line 2 \"Library/Debug/Dump.hpp\"\
    \n#include <concepts>\n#include <deque>\n#include <functional>\n#line 6 \"Library/Debug/Dump.hpp\"\
    \n#include <string_view>\n\ntemplate <class T>\nconstexpr inline auto d_val(T\
    \ a, T b) {\n  return b;\n}\n\n// debug\u7528\u51FA\u529B\u30DE\u30AF\u30ED\n\
    #define dump(...)                                               \\\n  do {   \
    \                                                       \\\n    auto __DUMP_NAME_LIST__\
    \ = split(#__VA_ARGS__, ',');         \\\n    splitVariables(std::move(__DUMP_NAME_LIST__),\
    \ __VA_ARGS__); \\\n  } while (false)\n\n// split\ninline auto split(std::string_view\
    \ str, char del = ' ') {\n  std::deque<std::string_view> sList;\n  int from =\
    \ 0;\n  for (int i = 0; auto&& c : str) {\n    if (c == del) {\n      sList.emplace_back(str.substr(from,\
    \ i - from));\n      from = i + 1;\n    }\n    if (c == ' ') { ++from; }\n   \
    \ ++i;\n  }\n  sList.emplace_back(str.substr(from, str.size() - from));\n  return\
    \ sList;\n}\n// \u5236\u7D04\ntemplate <class T>\nconcept Container = requires(T\
    \ x) {\n  x.begin();\n};\n\ntemplate <class T>\nconcept Printable = requires(T\
    \ x) {\n  std::cerr << x;\n};\n\n// \u5BA3\u8A00\ntemplate <class... T>\nconstexpr\
    \ auto print(const std::tuple<T...>&, bool b = true);\ntemplate <class S, class\
    \ T>\nconstexpr auto print(const std::pair<S, T>&, bool b = true);\ninline auto\
    \ print(const std::string&, bool b = true);\nconstexpr auto print(const Printable\
    \ auto&, bool b = true);\nconstexpr auto print(const Container auto&, bool b =\
    \ true);\n// \u5B9A\u7FA9\nconstexpr auto print(const auto&, bool) {\n  std::cerr\
    \ << \"<ERROR!> \\\"print\\\" of This type is not defined.\" << '\\n';\n}\n\n\
    template <class... T>\nconstexpr auto print(const std::tuple<T...>& t, bool b)\
    \ {\n  std::cerr << \"{\";\n  std::apply(\n      [&]<class... Ts>(Ts&&... elems)\
    \ {\n        (std::invoke([](auto i) { print(i, true); }, std::forward<Ts>(elems)),\n\
    \         ...);\n      },\n      t);\n  std::cerr << \"}\";\n  if (b) { std::cerr\
    \ << \" \"; }\n}\ntemplate <class S, class T>\nconstexpr auto print(const std::pair<S,\
    \ T>& p, bool b) {\n  std::cerr << '(';\n  print(p.first, false);\n  std::cerr\
    \ << \", \";\n  print(p.second, false);\n  std::cerr << ')';\n  if (b) { std::cerr\
    \ << \" \"; }\n}\ninline auto print(const std::string& s, bool b) {\n  std::cerr\
    \ << s;\n  if (b) { std::cerr << std::endl; }\n}\nconstexpr auto print(const Printable\
    \ auto& p, bool b) {\n  std::cerr << p;\n  if (b) { std::cerr << ' '; }\n}\nconstexpr\
    \ auto print(const Container auto& c, bool b) {\n  for (auto&& x : c) { print(x);\
    \ }\n  if (b) { std::cerr << '\\n'; }\n}\n\n// \u5909\u6570\u306E\u51FA\u529B\n\
    constexpr auto printVariable(auto&& name, const auto& p) {\n  std::cerr << name\
    \ << \": \";\n  print(p);\n  std::cerr << '\\n';\n}\ninline auto printVariable(auto&&\
    \ name, const std::string& s) {\n  std::cerr << name << \": \";\n  print(s);\n\
    \  std::cerr << '\\n';\n}\nconstexpr auto printVariable(auto&& name, const Container\
    \ auto& c) {\n  std::cerr << \"-- \" << name << \" --\" << '\\n';\n  print(c);\n\
    }\n\n// 1\u5909\u6570\u305A\u3064\u51E6\u7406\nconstexpr auto splitVariables(auto&&\
    \ names) {}\nconstexpr auto splitVariables(auto&& names, const auto& x,\n    \
    \                          const auto&... tail) {\n  printVariable(names.front(),\
    \ x);\n  names.pop_front();\n  splitVariables(std::forward<decltype(names)>(names),\
    \ tail...);\n}\n#line 2 \"Library/Utility/Tuple.hpp\"\n\n#line 4 \"Library/Utility/Tuple.hpp\"\
    \n\nnamespace mtd {\n  namespace util {\n    template <class F, class T>\n   \
    \ constexpr auto tuple_transform(F&& f, T&& t) {\n      return std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            return std::tuple<std::invoke_result_t<F&,\
    \ Ts>...>(\n                std::invoke(f, std::forward<Ts>(elems))...);\n   \
    \       },\n          std::forward<T>(t));\n    }\n    template <class F, class\
    \ T>\n    constexpr auto tuple_for_each(F&& f, T&& t) {\n      std::apply(\n \
    \         [&]<class... Ts>(Ts&&... elems) {\n            (std::invoke(f, std::forward<Ts>(elems)),\
    \ ...);\n          },\n          std::forward<T>(t));\n    }\n  }  // namespace\
    \ util\n}  // namespace mtd\n#line 10 \"Library/Utility/io.hpp\"\n\nnamespace\
    \ mtd {\n  namespace io {\n\n    namespace type {\n      template <class T>\n\
    \      struct vec {\n        using value_type = T;\n      };\n      template <class\
    \ T>\n      concept is_vec = requires {\n        requires std::is_same_v<T, vec<typename\
    \ T::value_type>>;\n      };\n\n      template <class T>\n      struct mat {\n\
    \        using value_type = T;\n      };\n      template <class T>\n      concept\
    \ is_mat = requires {\n        requires std::is_same_v<T, mat<typename T::value_type>>;\n\
    \      };\n    }  // namespace type\n\n    template <class T>\n    auto _input()\
    \ {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n    template <typename\
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
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <ranges>\n#include <type_traits>\n\
    #include <vector>\n\n#include \"../Debug/Dump.hpp\"\n#include \"Tuple.hpp\"\n\n\
    namespace mtd {\n  namespace io {\n\n    namespace type {\n      template <class\
    \ T>\n      struct vec {\n        using value_type = T;\n      };\n      template\
    \ <class T>\n      concept is_vec = requires {\n        requires std::is_same_v<T,\
    \ vec<typename T::value_type>>;\n      };\n\n      template <class T>\n      struct\
    \ mat {\n        using value_type = T;\n      };\n      template <class T>\n \
    \     concept is_mat = requires {\n        requires std::is_same_v<T, mat<typename\
    \ T::value_type>>;\n      };\n    }  // namespace type\n\n    template <class\
    \ T>\n    auto _input() {\n      T x;\n      std::cin >> x;\n      return x;\n\
    \    }\n    template <typename T>\n    requires requires { typename std::tuple_size<T>::type;\
    \ }\n    auto _input() {\n      T x;\n      util::tuple_for_each([](auto&& i)\
    \ { std::cin >> i; }, x);\n      return x;\n    }\n    template <type::is_vec\
    \ T>\n    auto _input(int n) {\n      std::vector<typename T::value_type> v;\n\
    \      v.reserve(n);\n      for (auto i : std::views::iota(0, n)) {\n        v.emplace_back(_input<typename\
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
    \ base;\n    }\n\n  }  // namespace io\n\n}  // namespace mtd\n"
  dependsOn:
  - Library/Debug/Dump.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: false
  path: Library/Utility/io.hpp
  requiredBy:
  - Library/Range/template.cpp
  - Library/Range/istream.hpp
  - Library/Main/main.cpp
  - Library/Main/includes.hpp
  timestamp: '2024-12-18 00:20:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Range/zip.test.cpp
  - Test/Range/enumerate.test.cpp
  - Test/Range/flatten.test.cpp
  - Test/Graph/Normal/StronglyConnectedComponents.test.cpp
  - Test/Math/Math_pow.test.cpp
  - Test/Math/Convolution_and.test.cpp
  - Test/Math/Math.test.cpp
  - Test/Math/Math_pow_dynamic.test.cpp
  - Test/Math/Math_dynamic.test.cpp
  - Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
  - Test/DataStructure/RunLengthEncoding.test.cpp
documentation_of: Library/Utility/io.hpp
layout: document
redirect_from:
- /library/Library/Utility/io.hpp
- /library/Library/Utility/io.hpp.html
title: Library/Utility/io.hpp
---
