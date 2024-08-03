---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/io.hpp\"\n\n#include <iostream>\n#include\
    \ <ranges>\n\nnamespace myranges {\n\n  template <class T>\n  auto _input() {\n\
    \    T x;\n    std::cin >> x;\n    return std::make_tuple(x);\n  }\n\n  template\
    \ <class T, class... Args>\n  auto _tuple_input() {\n    if constexpr (sizeof...(Args)\
    \ == 0) {\n      return _input<T>();\n    } else {\n      auto ret = _input<T>();\n\
    \      return std::tuple_cat(ret, _tuple_input<Args...>());\n    }\n  }\n\n  constexpr\
    \ int _inf = 1e9;\n\n  template <class... Args>\n  struct istream_view\n     \
    \ : public std::ranges::view_interface<istream_view<Args...>> {\n    class iterator\
    \ {\n      int count;\n      std::tuple<Args...> val;\n\n    public:\n      using\
    \ difference_type = int;\n      using value_type = std::tuple<Args...>;\n    \
    \  using iterator_concept = std::input_iterator_tag;\n\n      explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n      auto operator*() const { return\
    \ val; }\n      auto& operator++() {\n        --count;\n        if (count >= 0)\
    \ {\n          val = _tuple_input<Args...>();\n        }\n        return *this;\n\
    \      }\n      auto operator++(int) { return ++*this; }\n\n      auto operator==(std::default_sentinel_t\
    \ s) {\n        return count < 0 || std::cin.eof() || std::cin.fail() || std::cin.bad();\n\
    \      }\n      friend auto operator==(std::default_sentinel_t s, iterator li)\
    \ {\n        return li == s;\n      }\n    };\n\n    int count;\n\n  public:\n\
    \    explicit istream_view(int count = _inf) : count(count) {}\n    auto begin()\
    \ { return iterator(count); }\n    auto end() { return std::default_sentinel;\
    \ }\n  };\n\n  namespace __detail {\n    template <typename... _Args>\n    concept\
    \ __can_istream_view = requires {\n      istream_view(std::declval<_Args>()...);\n\
    \    };\n  }  // namespace __detail\n\n  namespace views {\n    struct _Istream\
    \ {\n      template <__detail::__can_istream_view _Tp>\n      constexpr auto operator()\
    \ [[nodiscard]] (_Tp&& __e) const {\n        return istream_view(std::forward<_Tp>(__e));\n\
    \      }\n    };\n\n    inline constexpr _Istream istream{};\n  }  // namespace\
    \ views\n\n}  // namespace myranges\n"
  code: "#pragma once\n\n#include <iostream>\n#include <ranges>\n\nnamespace myranges\
    \ {\n\n  template <class T>\n  auto _input() {\n    T x;\n    std::cin >> x;\n\
    \    return std::make_tuple(x);\n  }\n\n  template <class T, class... Args>\n\
    \  auto _tuple_input() {\n    if constexpr (sizeof...(Args) == 0) {\n      return\
    \ _input<T>();\n    } else {\n      auto ret = _input<T>();\n      return std::tuple_cat(ret,\
    \ _tuple_input<Args...>());\n    }\n  }\n\n  constexpr int _inf = 1e9;\n\n  template\
    \ <class... Args>\n  struct istream_view\n      : public std::ranges::view_interface<istream_view<Args...>>\
    \ {\n    class iterator {\n      int count;\n      std::tuple<Args...> val;\n\n\
    \    public:\n      using difference_type = int;\n      using value_type = std::tuple<Args...>;\n\
    \      using iterator_concept = std::input_iterator_tag;\n\n      explicit iterator(int\
    \ count) : count(count) { operator++(); }\n\n      auto operator*() const { return\
    \ val; }\n      auto& operator++() {\n        --count;\n        if (count >= 0)\
    \ {\n          val = _tuple_input<Args...>();\n        }\n        return *this;\n\
    \      }\n      auto operator++(int) { return ++*this; }\n\n      auto operator==(std::default_sentinel_t\
    \ s) {\n        return count < 0 || std::cin.eof() || std::cin.fail() || std::cin.bad();\n\
    \      }\n      friend auto operator==(std::default_sentinel_t s, iterator li)\
    \ {\n        return li == s;\n      }\n    };\n\n    int count;\n\n  public:\n\
    \    explicit istream_view(int count = _inf) : count(count) {}\n    auto begin()\
    \ { return iterator(count); }\n    auto end() { return std::default_sentinel;\
    \ }\n  };\n\n  namespace __detail {\n    template <typename... _Args>\n    concept\
    \ __can_istream_view = requires {\n      istream_view(std::declval<_Args>()...);\n\
    \    };\n  }  // namespace __detail\n\n  namespace views {\n    struct _Istream\
    \ {\n      template <__detail::__can_istream_view _Tp>\n      constexpr auto operator()\
    \ [[nodiscard]] (_Tp&& __e) const {\n        return istream_view(std::forward<_Tp>(__e));\n\
    \      }\n    };\n\n    inline constexpr _Istream istream{};\n  }  // namespace\
    \ views\n\n}  // namespace myranges\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/io.hpp
  requiredBy: []
  timestamp: '2024-08-03 20:25:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/io.hpp
layout: document
redirect_from:
- /library/Library/Range/io.hpp
- /library/Library/Range/io.hpp.html
title: Library/Range/io.hpp
---
