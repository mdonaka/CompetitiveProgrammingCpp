---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/Range/io.hpp
    title: Library/Range/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/istream.hpp\"\n\n#include <ranges>\n\n#line\
    \ 2 \"Library/Range/io.hpp\"\n\n#include <iostream>\n#line 5 \"Library/Range/io.hpp\"\
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
    \ type = int;\n    };\n    template <class T, int Pre, int Size>\n    struct _Converter<type::vec<T,\
    \ Pre, Size>> {\n      using type = std::vector<T>;\n    };\n\n    template <class...\
    \ Args>\n    auto in() {\n      auto base = std::tuple<typename _Converter<Args>::type...>();\n\
    \      _tuple_input<0, decltype(base), Args...>(base);\n      return base;\n \
    \   }\n\n  }  // namespace io\n\n  template <class T, int Pre = 1, int Size =\
    \ 0>\n  using tvec = io::type::vec<T, Pre, Size>;\n  using io::in;\n\n}  // namespace\
    \ mtd\n#line 6 \"Library/Range/istream.hpp\"\n\nnamespace mtd {\n  namespace ranges\
    \ {\n\n    constexpr int _inf = 1e9;\n\n    template <class... Args>\n    struct\
    \ istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int count) : count(count) { operator++(); }\n\n  \
    \      auto operator*() const { return val; }\n        auto& operator++() {\n\
    \          --count;\n          if (count >= 0) { val = io::in<Args...>(); }\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n\n        auto operator==(const iterator& s) const { return count == s.count;\
    \ }\n        auto operator==(std::default_sentinel_t s) const {\n          return\
    \ count < 0 || std::cin.eof() || std::cin.fail() ||\n                 std::cin.bad();\n\
    \        }\n        friend auto operator==(std::default_sentinel_t s, const iterator&\
    \ li) {\n          return li == s;\n        }\n      };\n\n      int count;\n\n\
    \    public:\n      constexpr explicit istream_view(int count) : count(count)\
    \ {}\n      constexpr explicit istream_view() : istream_view(_inf) {}\n      auto\
    \ begin() const { return iterator(count); }\n      auto end() const { return std::default_sentinel;\
    \ }\n    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_istream_view = requires\
    \ {\n        ranges::istream_view(std::declval<_Args>()...);\n      };\n    }\
    \  // namespace __detail\n\n    template <class... Args>\n    struct _Istream\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <ranges>\n\n#include \"./io.hpp\"\n\nnamespace mtd\
    \ {\n  namespace ranges {\n\n    constexpr int _inf = 1e9;\n\n    template <class...\
    \ Args>\n    struct istream_view\n        : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n      class iterator {\n        int count;\n        std::tuple<typename io::_Converter<Args>::type...>\
    \ val;\n\n      public:\n        using difference_type = int;\n        using value_type\
    \ = decltype(val);\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int count) : count(count) { operator++(); }\n\n  \
    \      auto operator*() const { return val; }\n        auto& operator++() {\n\
    \          --count;\n          if (count >= 0) { val = io::in<Args...>(); }\n\
    \          return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n\n        auto operator==(const iterator& s) const { return count == s.count;\
    \ }\n        auto operator==(std::default_sentinel_t s) const {\n          return\
    \ count < 0 || std::cin.eof() || std::cin.fail() ||\n                 std::cin.bad();\n\
    \        }\n        friend auto operator==(std::default_sentinel_t s, const iterator&\
    \ li) {\n          return li == s;\n        }\n      };\n\n      int count;\n\n\
    \    public:\n      constexpr explicit istream_view(int count) : count(count)\
    \ {}\n      constexpr explicit istream_view() : istream_view(_inf) {}\n      auto\
    \ begin() const { return iterator(count); }\n      auto end() const { return std::default_sentinel;\
    \ }\n    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_istream_view = requires\
    \ {\n        ranges::istream_view(std::declval<_Args>()...);\n      };\n    }\
    \  // namespace __detail\n\n    template <class... Args>\n    struct _Istream\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_istream_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {\n      \
    \  return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);\n      }\n\
    \    };\n\n    template <class... Args>\n    inline constexpr _Istream<Args...>\
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n"
  dependsOn:
  - Library/Range/io.hpp
  isVerificationFile: false
  path: Library/Range/istream.hpp
  requiredBy: []
  timestamp: '2024-08-10 19:46:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/istream.hpp
layout: document
redirect_from:
- /library/Library/Range/istream.hpp
- /library/Library/Range/istream.hpp.html
title: Library/Range/istream.hpp
---
