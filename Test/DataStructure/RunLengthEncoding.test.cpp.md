---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/DataStructure/RunLengthEncoding.hpp
    title: Library/DataStructure/RunLengthEncoding.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/Tuple.hpp
    title: Library/Utility/Tuple.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Utility/io.hpp
    title: Library/Utility/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1469
    links:
    - https://yukicoder.me/problems/no/1469
  bundledCode: "#line 1 \"Test/DataStructure/RunLengthEncoding.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1469\"\n\n// begin:tag includes\n\
    #line 2 \"Library/DataStructure/RunLengthEncoding.hpp\"\n\n#include <ranges>\n\
    #include <vector>\n\nnamespace mtd {\n  template <std::ranges::range _R>\n  class\
    \ RunLengthEncoding {\n    using T = std::iter_value_t<std::ranges::iterator_t<_R>>;\n\
    \n    const std::vector<std::tuple<T, int>> r;\n\n    static constexpr auto construct_rle(const\
    \ _R& r) {\n      std::vector<std::tuple<T, int>> rle;\n      if (r.empty()) {\
    \ return rle; }\n      T now = *r.begin();\n      int cnt = 1;\n      for (const\
    \ auto& x : r | std::views::drop(1)) {\n        if (x == now) {\n          ++cnt;\n\
    \        } else {\n          rle.emplace_back(now, cnt);\n          cnt = 1;\n\
    \          now = x;\n        }\n      }\n      rle.emplace_back(now, cnt);\n \
    \     return rle;\n    }\n\n  public:\n    constexpr RunLengthEncoding(const _R&\
    \ r) : r(construct_rle(r)) {}\n\n    constexpr auto begin() const { return r.begin();\
    \ }\n    constexpr auto end() const { return r.end(); }\n  };\n}  // namespace\
    \ mtd\n#line 5 \"Test/DataStructure/RunLengthEncoding.test.cpp\"\n\n#line 2 \"\
    Library/Range/istream.hpp\"\n\n#line 4 \"Library/Range/istream.hpp\"\n\n#line\
    \ 2 \"Library/Utility/io.hpp\"\n\n#include <iostream>\n#line 5 \"Library/Utility/io.hpp\"\
    \n#include <type_traits>\n#line 7 \"Library/Utility/io.hpp\"\n\n#line 2 \"Library/Utility/Tuple.hpp\"\
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
    \ istream{};\n  }  // namespace views\n\n}  // namespace mtd\n#line 7 \"Test/DataStructure/RunLengthEncoding.test.cpp\"\
    \n// end:tag includes\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\
    \n  auto [s] = mtd::io::in<std::string>();\n  auto rle = mtd::RunLengthEncoding(s);\n\
    \  for (auto [c, _] : rle) { std::cout << c; }\n  std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1469\"\n\n// begin:tag\
    \ includes\n#include \"../../Library/DataStructure/RunLengthEncoding.hpp\"\n\n\
    #include \"../../Library/Range/istream.hpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  auto [s] = mtd::io::in<std::string>();\n\
    \  auto rle = mtd::RunLengthEncoding(s);\n  for (auto [c, _] : rle) { std::cout\
    \ << c; }\n  std::cout << std::endl;\n}\n"
  dependsOn:
  - Library/DataStructure/RunLengthEncoding.hpp
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Utility/Tuple.hpp
  isVerificationFile: true
  path: Test/DataStructure/RunLengthEncoding.test.cpp
  requiredBy: []
  timestamp: '2024-12-18 17:23:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/DataStructure/RunLengthEncoding.test.cpp
layout: document
redirect_from:
- /verify/Test/DataStructure/RunLengthEncoding.test.cpp
- /verify/Test/DataStructure/RunLengthEncoding.test.cpp.html
title: Test/DataStructure/RunLengthEncoding.test.cpp
---
