---
data:
  _extendedDependsOn: []
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
    \ <ranges>\n#include <type_traits>\n#include <vector>\n\nnamespace mtd {\n  namespace\
    \ io {\n\n    namespace type {\n      template <class T, int Pre = 1, int Size\
    \ = 0>\n      struct vec {\n        using value_type = T;\n        static constexpr\
    \ int pre = Pre;\n        static constexpr int size = Size;\n      };\n      template\
    \ <class T>\n      concept is_vec = requires {\n        std::is_same_v<T, vec<typename\
    \ T::value_type, T::pre, T::size>>;\n      };\n    }  // namespace type\n\n  \
    \  template <type::is_vec T>\n    auto _input(int n) {\n      std::vector<typename\
    \ T::value_type> v(n);\n      for (auto i : std::views::iota(0, n)) { std::cin\
    \ >> v[i]; }\n      return v;\n    }\n\n    template <class T>\n    auto _input()\
    \ {\n      T x;\n      std::cin >> x;\n      return x;\n    }\n\n    template\
    \ <int N, class Tuple, class T, class... Args>\n    auto _tuple_input(Tuple& t)\
    \ {\n      if constexpr (type::is_vec<T>) {\n        if constexpr (T::size ==\
    \ 0) {\n          std::get<N>(t) = _input<T>(std::get<N - T::pre>(t));\n     \
    \   } else {\n          std::get<N>(t) = _input<T>(T::size);\n        }\n    \
    \  } else {\n        std::get<N>(t) = _input<T>();\n      }\n      if constexpr\
    \ (sizeof...(Args) > 0) {\n        _tuple_input<N + 1, Tuple, Args...>(t);\n \
    \     }\n    }\n\n    template <class T>\n    struct _Converter {\n      using\
    \ type = T;\n    };\n    template <class T, int Pre, int Size>\n    struct _Converter<type::vec<T,\
    \ Pre, Size>> {\n      using type = std::vector<T>;\n    };\n\n    template <class...\
    \ Args>\n    auto in() {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base);\n      return base;\n \
    \   }\n\n  }  // namespace io\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <iostream>\n#include <ranges>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace mtd {\n  namespace io {\n\n    namespace type {\n\
    \      template <class T, int Pre = 1, int Size = 0>\n      struct vec {\n   \
    \     using value_type = T;\n        static constexpr int pre = Pre;\n       \
    \ static constexpr int size = Size;\n      };\n      template <class T>\n    \
    \  concept is_vec = requires {\n        std::is_same_v<T, vec<typename T::value_type,\
    \ T::pre, T::size>>;\n      };\n    }  // namespace type\n\n    template <type::is_vec\
    \ T>\n    auto _input(int n) {\n      std::vector<typename T::value_type> v(n);\n\
    \      for (auto i : std::views::iota(0, n)) { std::cin >> v[i]; }\n      return\
    \ v;\n    }\n\n    template <class T>\n    auto _input() {\n      T x;\n     \
    \ std::cin >> x;\n      return x;\n    }\n\n    template <int N, class Tuple,\
    \ class T, class... Args>\n    auto _tuple_input(Tuple& t) {\n      if constexpr\
    \ (type::is_vec<T>) {\n        if constexpr (T::size == 0) {\n          std::get<N>(t)\
    \ = _input<T>(std::get<N - T::pre>(t));\n        } else {\n          std::get<N>(t)\
    \ = _input<T>(T::size);\n        }\n      } else {\n        std::get<N>(t) = _input<T>();\n\
    \      }\n      if constexpr (sizeof...(Args) > 0) {\n        _tuple_input<N +\
    \ 1, Tuple, Args...>(t);\n      }\n    }\n\n    template <class T>\n    struct\
    \ _Converter {\n      using type = T;\n    };\n    template <class T, int Pre,\
    \ int Size>\n    struct _Converter<type::vec<T, Pre, Size>> {\n      using type\
    \ = std::vector<T>;\n    };\n\n    template <class... Args>\n    auto in() {\n\
    \      auto base = std::tuple<typename _Converter<Args>::type...>();\n      _tuple_input<0,\
    \ decltype(base), Args...>(base);\n      return base;\n    }\n\n  }  // namespace\
    \ io\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Utility/io.hpp
  requiredBy:
  - Library/Range/template.cpp
  - Library/Range/istream.hpp
  - Library/Main/includes.hpp
  - Library/Main/main.cpp
  timestamp: '2024-08-18 00:08:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Range/enumerate.test.cpp
  - Test/Range/zip.test.cpp
  - Test/Range/flatten.test.cpp
documentation_of: Library/Utility/io.hpp
layout: document
redirect_from:
- /library/Library/Utility/io.hpp
- /library/Library/Utility/io.hpp.html
title: Library/Utility/io.hpp
---
