---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Debug/Dump.hpp
    title: Library/Debug/Dump.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/istream.hpp
    title: Library/Range/istream.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
  bundledCode: "#line 1 \"Test/Range/flatten.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\n#include\
    \ <iostream>\n\n// begin:tag includes\n#line 2 \"Library/Range/istream.hpp\"\n\
    \n#include <ranges>\n\n#line 2 \"Library/Utility/io.hpp\"\n\n#line 5 \"Library/Utility/io.hpp\"\
    \n#include <type_traits>\n#include <vector>\n\n#line 2 \"Library/Debug/Dump.hpp\"\
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
    \    }\n    }  // namespace __detail\n\n    template <std::ranges::range... _Range>\n\
    \    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>>\
    \ {\n      class iterator {\n      public:\n        std::tuple<std::ranges::iterator_t<_Range>...>\
    \ _M_current;\n\n        using difference_type = int;\n        using value_type\
    \ = std::tuple<\n            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;\n\
    \        using iterator_concept =\n            decltype(__detail::_S_iter_concept<_Range...>());\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(const\
    \ decltype(_M_current)& __current)\n            : _M_current(__current) {}\n \
    \       constexpr auto operator*() const {\n          return util::tuple_transform([](auto&\
    \ __i) { return *__i; },\n                                       _M_current);\n\
    \        }\n        constexpr auto& operator++() {\n          util::tuple_for_each([](auto&\
    \ __i) { ++__i; }, _M_current);\n          return *this;\n        }\n        constexpr\
    \ auto operator++(int) { return ++*this; }\n        constexpr auto operator==(const\
    \ iterator& other) const {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return ((std::get<_Is>(_M_current) ==\n                     std::get<_Is>(other._M_current))\
    \ ||\n                    ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n        constexpr auto& operator--() requires\n            __detail::__all_bidirectional<_Range...>\
    \ {\n          util::tuple_for_each([](auto& __i) { --__i; }, _M_current);\n \
    \         return *this;\n        }\n        constexpr auto operator--(\n     \
    \       int) requires __detail::__all_bidirectional<_Range...> {\n          return\
    \ --*this;\n        }\n        constexpr auto operator<=>(const iterator&)\n \
    \           const requires __detail::__all_random_access<_Range...>\n        =\
    \ default;\n        constexpr auto operator-(const iterator& itr)\n          \
    \  const requires __detail::__all_random_access<_Range...> {\n          return\
    \ [&]<size_t... _Is>(std::index_sequence<_Is...>) {\n            return std::ranges::min({difference_type(\n\
    \                std::get<_Is>(_M_current) - std::get<_Is>(itr._M_current))...});\n\
    \          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n   \
    \     }\n        constexpr auto& operator+=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range...> {\n          util::tuple_for_each([&n](auto&\
    \ __i) { __i += n; }, _M_current);\n          return *this;\n        }\n     \
    \   constexpr auto operator+(const difference_type n)\n            const requires\
    \ __detail::__all_random_access<_Range...> {\n          auto __r = *this;\n  \
    \        __r += n;\n          return __r;\n        }\n        constexpr friend\
    \ auto operator+(const difference_type n,\n                                  \
    \      const iterator& itr) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          return itr + n;\n        }\n        constexpr auto& operator-=(const\
    \ difference_type n) requires\n            __detail::__all_random_access<_Range...>\
    \ {\n          util::tuple_for_each([&n](auto& __i) { __i -= n; }, _M_current);\n\
    \          return *this;\n        }\n        constexpr auto operator-(const difference_type\
    \ n)\n            const requires __detail::__all_random_access<_Range...> {\n\
    \          auto __r = *this;\n          __r -= n;\n          return __r;\n   \
    \     }\n        constexpr auto operator[](const difference_type n)\n        \
    \    const requires __detail::__all_random_access<_Range...> {\n          return\
    \ util::tuple_transform([&n](auto& __i) { return __i[n]; },\n                \
    \                       _M_current);\n        }\n      };\n\n      class sentinel\
    \ {\n      public:\n        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;\n\
    \n        constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return [&]<size_t... _Is>(std::index_sequence<_Is...>)\
    \ {\n            return (\n                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end))\
    \ ||\n                ...);\n          }\n          (std::make_index_sequence<sizeof...(_Range)>{});\n\
    \        }\n      };\n\n      std::tuple<_Range...> __r;\n      constexpr explicit\
    \ zip_view(const _Range&... __r) : __r(__r...) {}\n      constexpr auto begin()\
    \ {\n        return iterator(util::tuple_transform(std::ranges::begin, __r));\n\
    \      }\n      constexpr auto end() {\n        return sentinel(util::tuple_transform(std::ranges::end,\
    \ __r));\n      }\n    };\n\n    namespace __detail {\n      template <typename\
    \ T>\n      auto _flatten(const T& t) {\n        return std::make_tuple(t);\n\
    \      }\n      template <typename... T>\n      auto _flatten(const std::tuple<T...>&\
    \ t);\n\n      template <typename Head, typename... Tail>\n      auto _flatten_impl(const\
    \ Head& head, const Tail&... tail) {\n        return std::tuple_cat(_flatten(head),\
    \ _flatten(tail)...);\n      }\n      template <typename... T>\n      auto _flatten(const\
    \ std::tuple<T...>& t) {\n        return std::apply(\n            [](const auto&...\
    \ args) { return _flatten_impl(args...); }, t);\n      }\n    }  // namespace\
    \ __detail\n\n    template <std::ranges::range _Range>\n    struct flatten_view\n\
    \        : public std::ranges::view_interface<flatten_view<_Range>> {\n      class\
    \ iterator {\n      public:\n        std::ranges::iterator_t<_Range> _M_current;\n\
    \n        using difference_type = std::ranges::range_difference_t<_Range>;\n \
    \       using value_type = decltype(__detail::_flatten(\n            std::declval<\n\
    \                std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));\n\
    \        using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());\n\
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
    \ {\n          auto __r = *this;\n          __r += n;\n          return __r;\n\
    \        }\n        constexpr friend auto operator+(const difference_type n,\n\
    \                                        const iterator& itr) requires\n     \
    \       __detail::__all_random_access<_Range> {\n          return itr + n;\n \
    \       }\n        constexpr auto& operator-=(const difference_type n) requires\n\
    \            __detail::__all_random_access<_Range> {\n          _M_current -=\
    \ n;\n          return *this;\n        }\n        constexpr auto operator-(const\
    \ difference_type n)\n            const requires __detail::__all_random_access<_Range>\
    \ {\n          auto __r = *this;\n          __r -= n;\n          return __r;\n\
    \        }\n        constexpr auto operator[](const difference_type n)\n     \
    \       const requires __detail::__all_random_access<_Range> {\n          return\
    \ __detail::_flatten(_M_current[n]);\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr sentinel() = default;\n        constexpr explicit sentinel(const\
    \ decltype(_M_end)& __end)\n            : _M_end(__end) {}\n\n        friend constexpr\
    \ bool operator==(const iterator& __x,\n                                     \
    \    const sentinel& __y) {\n          return __x._M_current == __y._M_end;\n\
    \        }\n      };\n\n      _Range __r;\n      constexpr explicit flatten_view(const\
    \ _Range& __r) : __r(__r) {}\n      constexpr auto begin() { return iterator(std::ranges::begin(__r));\
    \ }\n      constexpr auto end() { return sentinel(std::ranges::end(__r)); }\n\
    \    };\n\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_zip_view = requires\
    \ {\n        ranges::zip_view(std::declval<_Args>()...);\n      };\n      template\
    \ <typename... _Args>\n      concept __can_flatten_view = requires {\n       \
    \ ranges::flatten_view(std::declval<_Args>()...);\n      };\n    }  // namespace\
    \ __detail\n\n    struct _ZipView {\n      template <class... _Tp>\n      requires\
    \ __detail::__can_zip_view<_Tp...>\n      constexpr auto operator() [[nodiscard]]\
    \ (_Tp&&... __e) const {\n        return ranges::zip_view(std::forward<_Tp>(__e)...);\n\
    \      }\n    };\n    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure\
    \ {\n      template <class _Tp>\n      requires __detail::__can_zip_view<std::ranges::iota_view<size_t>,\
    \ _Tp>\n      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {\n  \
    \      return ranges::zip_view{std::views::iota(0), std::forward<_Tp>(__e)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\
    \    struct _Flatten : std::views::__adaptor::_RangeAdaptorClosure {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_flatten_view<_Tp...>\n      constexpr\
    \ auto operator() [[nodiscard]] (_Tp&&... __e) const {\n        return ranges::flatten_view(std::forward<_Tp>(__e)...);\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _ZipView zip{};\n    inline constexpr _Enumerate enumerate{};\n\
    \    inline constexpr _Flatten flatten{};\n\n  }  // namespace views\n}  // namespace\
    \ mtd\n#line 8 \"Test/Range/flatten.test.cpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  for (auto [i, x]\
    \ : mtd::views::istream<int>() | mtd::views::enumerate |\n                   \
    \      mtd::views::flatten) {\n    if (x == 0) { break; }\n    std::cout << \"\
    Case \" << i + 1 << \": \" << x << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\
    \n#include <iostream>\n\n// begin:tag includes\n#include \"../../Library/Range/istream.hpp\"\
    \n#include \"../../Library/Range/util.hpp\"\n// end:tag includes\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(0);\n\n  for (auto [i, x]\
    \ : mtd::views::istream<int>() | mtd::views::enumerate |\n                   \
    \      mtd::views::flatten) {\n    if (x == 0) { break; }\n    std::cout << \"\
    Case \" << i + 1 << \": \" << x << std::endl;\n  }\n}\n"
  dependsOn:
  - Library/Range/istream.hpp
  - Library/Utility/io.hpp
  - Library/Debug/Dump.hpp
  - Library/Utility/Tuple.hpp
  - Library/Range/util.hpp
  isVerificationFile: true
  path: Test/Range/flatten.test.cpp
  requiredBy: []
  timestamp: '2024-12-18 00:20:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Range/flatten.test.cpp
layout: document
redirect_from:
- /verify/Test/Range/flatten.test.cpp
- /verify/Test/Range/flatten.test.cpp.html
title: Test/Range/flatten.test.cpp
---
