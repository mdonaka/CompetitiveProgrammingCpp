---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Main/includes.hpp
    title: Library/Main/includes.hpp
  - icon: ':warning:'
    path: Library/Main/main.cpp
    title: Library/Main/main.cpp
  - icon: ':warning:'
    path: Library/Range/template.cpp
    title: Library/Range/template.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
    title: Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
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
    \n#include <type_traits>\n#include <vector>\n\nnamespace mtd {\n  namespace io\
    \ {\n\n    namespace type {\n      template <class T, int Pre = 1, int Size =\
    \ 0>\n      struct vec {\n        using value_type = T;\n        static constexpr\
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
    \   }\n\n  }  // namespace io\n\n}  // namespace mtd\n#line 6 \"Library/Range/istream.hpp\"\
    \n\nnamespace mtd {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n\
    \    template <class... Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n        constexpr auto operator*()\
    \ const { return val; }\n        constexpr auto& operator++() {\n          --count;\n\
    \          if (count >= 0) { val = io::in<Args...>(); }\n          return *this;\n\
    \        }\n        constexpr auto operator++(int) { return ++*this; }\n\n   \
    \     constexpr auto operator==(const iterator& s) const {\n          return count\
    \ == s.count;\n        }\n        constexpr auto operator==(std::default_sentinel_t\
    \ s) const {\n          return count < 0 || std::cin.eof() || std::cin.fail()\
    \ ||\n                 std::cin.bad();\n        }\n        constexpr friend auto\
    \ operator==(std::default_sentinel_t s,\n                                    \
    \     const iterator& li) {\n          return li == s;\n        }\n      };\n\n\
    \      int count;\n\n    public:\n      constexpr explicit istream_view(int count)\
    \ : count(count) {}\n      constexpr explicit istream_view() : istream_view(_inf)\
    \ {}\n      constexpr auto begin() const { return iterator(count); }\n      constexpr\
    \ auto end() const { return std::default_sentinel; }\n    };\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_istream_view = requires {\n        ranges::istream_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    template <class... Args>\n    struct\
    \ _Istream {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
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
    \ count) : count(count) { operator++(); }\n\n        constexpr auto operator*()\
    \ const { return val; }\n        constexpr auto& operator++() {\n          --count;\n\
    \          if (count >= 0) { val = io::in<Args...>(); }\n          return *this;\n\
    \        }\n        constexpr auto operator++(int) { return ++*this; }\n\n   \
    \     constexpr auto operator==(const iterator& s) const {\n          return count\
    \ == s.count;\n        }\n        constexpr auto operator==(std::default_sentinel_t\
    \ s) const {\n          return count < 0 || std::cin.eof() || std::cin.fail()\
    \ ||\n                 std::cin.bad();\n        }\n        constexpr friend auto\
    \ operator==(std::default_sentinel_t s,\n                                    \
    \     const iterator& li) {\n          return li == s;\n        }\n      };\n\n\
    \      int count;\n\n    public:\n      constexpr explicit istream_view(int count)\
    \ : count(count) {}\n      constexpr explicit istream_view() : istream_view(_inf)\
    \ {}\n      constexpr auto begin() const { return iterator(count); }\n      constexpr\
    \ auto end() const { return std::default_sentinel; }\n    };\n  }  // namespace\
    \ ranges\n\n  namespace views {\n    namespace __detail {\n      template <typename...\
    \ _Args>\n      concept __can_istream_view = requires {\n        ranges::istream_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    template <class... Args>\n    struct\
    \ _Istream {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n"
  dependsOn:
  - Library/Utility/io.hpp
  isVerificationFile: false
  path: Library/Range/istream.hpp
  requiredBy:
  - Library/Range/template.cpp
  - Library/Main/includes.hpp
  - Library/Main/main.cpp
  timestamp: '2024-08-29 12:31:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/Range/enumerate.test.cpp
  - Test/Range/zip.test.cpp
  - Test/Range/flatten.test.cpp
  - Test/Algorithms/EuclideanAlgorithm_gcd.test.cpp
documentation_of: Library/Range/istream.hpp
layout: document
redirect_from:
- /library/Library/Range/istream.hpp
- /library/Library/Range/istream.hpp.html
title: Library/Range/istream.hpp
---
