---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Library/Range/check.hpp
    title: Library/Range/check.hpp
  - icon: ':x:'
    path: Library/Range/io.hpp
    title: Library/Range/io.hpp
  - icon: ':x:'
    path: Library/Range/util.hpp
    title: Library/Range/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B
  bundledCode: "#line 1 \"Test/Range/enumerate.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\n#include\
    \ <iostream>\n\n// tag:includes begin\n#line 2 \"Library/Range/io.hpp\"\n\n#line\
    \ 4 \"Library/Range/io.hpp\"\n#include <ranges>\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace mtd {\n  namespace io {\n\n    namespace type {\n    \
    \  template <class T, int Pre = 1, int Size = 0>\n      struct vec {\n       \
    \ using value_type = T;\n        static constexpr int pre = Pre;\n        static\
    \ constexpr int size = Size;\n      };\n      template <class T>\n      concept\
    \ is_vec = requires {\n        std::is_same_v<T, vec<typename T::value_type, T::pre,\
    \ T::size>>;\n      };\n    }  // namespace type\n\n    template <type::is_vec\
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
    \ _Converter {\n      using type = int;\n    };\n    template <class T, int Pre,\
    \ int Size>\n    struct _Converter<type::vec<T, Pre, Size>> {\n      using type\
    \ = std::vector<T>;\n    };\n\n    template <class... Args>\n    auto in() {\n\
    \      auto base = std::tuple<typename _Converter<Args>::type...>();\n      _tuple_input<0,\
    \ decltype(base), Args...>(base);\n      return base;\n    }\n\n  }  // namespace\
    \ io\n\n  template <class T, int Pre = 1, int Size = 0>\n  using tvec = io::type::vec<T,\
    \ Pre, Size>;\n  using io::in;\n\n}  // namespace mtd\n#line 2 \"Library/Range/util.hpp\"\
    \n\n#line 4 \"Library/Range/util.hpp\"\n\nnamespace mtd {\n  namespace ranges\
    \ {\n    template <std::ranges::range _Range>\n    struct enumerate_view\n   \
    \     : public std::ranges::view_interface<enumerate_view<_Range>> {\n      auto\
    \ flat_tuple() {}\n\n      class iterator;\n      class sentinel;\n\n      struct\
    \ iterator {\n        size_t index;\n        _Range::iterator _M_current;\n\n\
    \        using difference_type = int;\n        // TODO: tuple\u304C\u6E21\u3055\
    \u308C\u305F\u6642\u306Bflat\u306B\u3059\u308B\n        using value_type =\n \
    \           std::tuple<size_t, typename _Range::iterator::value_type>;\n     \
    \   using iterator_concept = std::input_iterator_tag;\n\n        explicit iterator(const\
    \ typename _Range::iterator& _M_current =\n                              typename\
    \ _Range::iterator{})\n            : index(0), _M_current(_M_current) {}\n   \
    \     auto operator*() const { return std::make_tuple(index, *_M_current); }\n\
    \        auto& operator++() {\n          ++_M_current;\n          ++index;\n \
    \         return *this;\n        }\n        auto operator++(int) { return ++*this;\
    \ }\n        auto operator==(const iterator& other) const {\n          return\
    \ _M_current == other._M_current;\n        }\n      };\n\n      class sentinel\
    \ {\n        std::ranges::sentinel_t<_Range> _M_end;\n\n      public:\n      \
    \  constexpr explicit sentinel(std::ranges::sentinel_t<_Range>&& __end)\n    \
    \        : _M_end(std::forward<std::ranges::sentinel_t<_Range>>(__end)) {}\n\n\
    \        friend constexpr bool operator==(const iterator& __x,\n             \
    \                            const sentinel& __y) {\n          return __x._M_current\
    \ == __y._M_end;\n        }\n      };\n\n      _Range __r = _Range();\n\n    \
    \  enumerate_view() requires std::default_initializable<_Range>\n      = default;\n\
    \      constexpr explicit enumerate_view(const _Range& __r) : __r(__r) {}\n\n\
    \      auto begin() { return iterator(__r.begin()); }\n      auto end() {\n  \
    \      if constexpr (requires() { iterator(__r.end()); }) {\n          return\
    \ iterator(__r.end());\n        } else {\n          return sentinel(__r.end());\n\
    \        }\n      }\n    };\n  }  // namespace ranges\n\n  namespace views {\n\
    \    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {\n     \
    \ template <std::ranges::viewable_range _Range>\n      constexpr auto operator()(_Range&&\
    \ __r) const {\n        return ranges::enumerate_view{std::forward<_Range>(__r)};\n\
    \      }\n      static constexpr bool _S_has_simple_call_op = true;\n    };\n\n\
    \    inline constexpr _Enumerate enumerate{};\n  }  // namespace views\n}  //\
    \ namespace mtd\n#line 8 \"Test/Range/enumerate.test.cpp\"\n// tag:includes end\n\
    \n#line 11 \"Test/Range/enumerate.test.cpp\"\n\n#line 2 \"Library/Range/check.hpp\"\
    \n\n#include <concepts>\n#line 5 \"Library/Range/check.hpp\"\n#include <iterator>\n\
    \nnamespace mtd::check {\n\n  // =======================================================\n\
    \  //\n  template <std::weakly_incrementable>\n  void _is_weakly_incrementable()\
    \ {\n    std::cout << \"weakly_incrementable: True\" << std::endl;\n  }\n  template\
    \ <class I>\n  void _is_weakly_incrementable() {\n    std::cout << \"weakly_incrementable:\
    \ False\" << std::endl;\n  }\n\n  template <std::input_or_output_iterator I>\n\
    \  void _is_input_or_output_iterator() {\n    std::cout << \"input_or_output_iterator:\
    \ True\" << std::endl;\n  }\n  template <class I>\n  void _is_input_or_output_iterator()\
    \ {\n    std::cout << \"input_or_output_iterator: False\" << std::endl;\n  }\n\
    \n  template <std::indirectly_readable>\n  void _is_indirectly_readable() {\n\
    \    std::cout << \"indirectly_readable: True\" << std::endl;\n  }\n  template\
    \ <class I>\n  void _is_indirectly_readable() {\n    std::cout << \"indirectly_readable:\
    \ False\" << std::endl;\n  }\n\n  template <std::input_iterator I>\n  void _is_input_iterator()\
    \ {\n    std::cout << \"input_iterator: True\" << std::endl;\n  }\n  template\
    \ <class I>\n  void _is_input_iterator() {\n    std::cout << \"input_iterator:\
    \ False\" << std::endl;\n  }\n\n  template <class T>\n  auto iterator() {\n  \
    \  std::cout << \"-- iterator --\" << std::endl;\n    _is_weakly_incrementable<T>();\n\
    \    _is_input_or_output_iterator<T>();\n    _is_indirectly_readable<T>();\n \
    \   _is_input_iterator<T>();\n  }\n\n  // =======================================================\n\
    \n  template <class I, class S>\n  requires std::equality_comparable_with<I, S>\n\
    \  void _is_equality_comparable_with() {\n    std::cout << \"equality_comparable_with:\
    \ True\" << std::endl;\n  }\n  template <class I, class S>\n  void _is_equality_comparable_with()\
    \ {\n    std::cout << \"equality_comparable_with: False\" << std::endl;\n  }\n\
    \n  template <std::default_initializable i>\n  void _is_default_initializable()\
    \ {\n    std::cout << \"default_initializable: True\" << std::endl;\n  }\n  template\
    \ <class i>\n  void _is_default_initializable() {\n    std::cout << \"default_initializable:\
    \ False\" << std::endl;\n  }\n\n  template <std::copyable I>\n  void _is_copyable()\
    \ {\n    std::cout << \"copyable: True\" << std::endl;\n  }\n  template <class\
    \ I>\n  void _is_copyable() {\n    std::cout << \"copyable: False\" << std::endl;\n\
    \  }\n\n  template <std::semiregular i>\n  void _is_semiregular() {\n    std::cout\
    \ << \"semiregular: True\" << std::endl;\n  }\n  template <class i>\n  void _is_semiregular()\
    \ {\n    std::cout << \"semiregular: False\" << std::endl;\n  }\n\n  template\
    \ <class I, std::sentinel_for<I> S>\n  void _is_sentinel_for() {\n    std::cout\
    \ << \"sentinel_for: True\" << std::endl;\n  }\n  template <class I, class S>\n\
    \  void _is_sentinel_for() {\n    std::cout << \"sentinel_for: False\" << std::endl;\n\
    \  }\n\n  template <std::ranges::range T>\n  void _is_range() {\n    std::cout\
    \ << \"range: True\" << std::endl;\n  }\n  template <class T>\n  void _is_range()\
    \ {\n    std::cout << \"range: False\" << std::endl;\n  }\n  template <std::ranges::input_range\
    \ T>\n  void _is_input_range() {\n    std::cout << \"input_range: True\" << std::endl;\n\
    \  }\n  template <class T>\n  void _is_input_range() {\n    std::cout << \"input_range:\
    \ False\" << std::endl;\n  }\n\n  template <class T>\n  auto input_range() {\n\
    \    std::cout << \"-- input range --\" << std::endl;\n    auto x = T();\n   \
    \ _is_equality_comparable_with<decltype(x.begin()), decltype(x.end())>();\n  \
    \  _is_default_initializable<decltype(x.end())>();\n    _is_copyable<decltype(x.end())>();\n\
    \    _is_semiregular<decltype(x.end())>();\n    _is_sentinel_for<decltype(x.begin()),\
    \ decltype(x.end())>();\n    _is_range<T>();\n    _is_input_range<T>();\n  }\n\
    \n  // =======================================================\n\n  template <std::ranges::view\
    \ T>\n  void _is_view() {\n    std::cout << \"view: True\" << std::endl;\n  }\n\
    \  template <class T>\n  void _is_view() {\n    std::cout << \"view: False\" <<\
    \ std::endl;\n  }\n\n  template <class T>\n  void _is_object_v() {\n    std::cout\
    \ << \"is_object_v: \" << (std::is_object_v<T> ? \"True\" : \"False\")\n     \
    \         << std::endl;\n  }\n\n  template <std::move_constructible T>\n  void\
    \ _is_move_constructible() {\n    std::cout << \"move_constructible: True\" <<\
    \ std::endl;\n  }\n  template <class T>\n  void _is_move_constructible() {\n \
    \   std::cout << \"move_constructible: False\" << std::endl;\n  }\n\n  template\
    \ <class T>\n  requires std::assignable_from<T&, T>\n  void _is_assignable_from()\
    \ {\n    std::cout << \"assignable_from: True\" << std::endl;\n  }\n  template\
    \ <class T>\n  void _is_assignable_from() {\n    std::cout << \"assignable_from:\
    \ False\" << std::endl;\n  }\n\n  template <std::swappable T>\n  void _is_swappable()\
    \ {\n    std::cout << \"swappable: True\" << std::endl;\n  }\n  template <class\
    \ T>\n  void _is_swappable() {\n    std::cout << \"swappable: False\" << std::endl;\n\
    \  }\n\n  template <std::movable T>\n  void _is_movable() {\n    std::cout <<\
    \ \"movable: True\" << std::endl;\n  }\n  template <class T>\n  void _is_movable()\
    \ {\n    std::cout << \"movable: False\" << std::endl;\n  }\n\n  template <typename\
    \ T, typename U>\n  requires std::derived_from<T, U>\n  void _is_derived_from()\
    \ { std::cout << \"derived_from: True\" << std::endl; }\n  template <typename\
    \ T, typename U>\n  void _is_derived_from() {\n    std::cout << \"derived_from:\
    \ False\" << std::endl;\n  }\n\n  template <class T>\n  void _is_enable_view()\
    \ {\n    std::cout << \"enable_view: \"\n              << (std::ranges::enable_view<T>\
    \ ? \"True\" : \"False\") << std::endl;\n  }\n\n  template <class T>\n  auto view()\
    \ {\n    std::cout << \"-- view --\" << std::endl;\n    _is_object_v<T>();\n \
    \   _is_move_constructible<T>();\n    _is_assignable_from<T>();\n    _is_swappable<T>();\n\
    \    _is_movable<T>();\n    // _is_derived_from<T, std::ranges::view_base>();\n\
    \    _is_enable_view<T>();\n    _is_view<T>();\n  }\n\n  // =======================================================\n\
    \n  template <class T>\n  auto all() {\n    iterator<typename T::iterator>();\n\
    \    input_range<T>();\n    view<T>();\n  }\n\n}  // namespace mtd::check\n#line\
    \ 13 \"Test/Range/enumerate.test.cpp\"\n\nint main() {\n  std::cin.tie(0);\n \
    \ std::ios::sync_with_stdio(0);\n\n  for (auto [i, x] :\n       mystd::views::istream<int>()\
    \ | mystd::views::enumerate |\n           std::views::filter([](const std::tuple<int,\
    \ std::tuple<int>>& t) {\n             return std::get<0>(std::get<1>(t)) > 0;\n\
    \           })) {\n    std::cout << \"Case \" << i + 1 << \": \" << std::get<0>(x)\
    \ << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B\"\
    \n#include <iostream>\n\n// tag:includes begin\n#include \"../../Library/Range/io.hpp\"\
    \n#include \"../../Library/Range/util.hpp\"\n// tag:includes end\n\n#include <vector>\n\
    \n#include \"../../Library/Range/check.hpp\"\n\nint main() {\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(0);\n\n  for (auto [i, x] :\n       mystd::views::istream<int>()\
    \ | mystd::views::enumerate |\n           std::views::filter([](const std::tuple<int,\
    \ std::tuple<int>>& t) {\n             return std::get<0>(std::get<1>(t)) > 0;\n\
    \           })) {\n    std::cout << \"Case \" << i + 1 << \": \" << std::get<0>(x)\
    \ << std::endl;\n  }\n}\n"
  dependsOn:
  - Library/Range/io.hpp
  - Library/Range/util.hpp
  - Library/Range/check.hpp
  isVerificationFile: true
  path: Test/Range/enumerate.test.cpp
  requiredBy: []
  timestamp: '2024-08-10 19:46:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Range/enumerate.test.cpp
layout: document
redirect_from:
- /verify/Test/Range/enumerate.test.cpp
- /verify/Test/Range/enumerate.test.cpp.html
title: Test/Range/enumerate.test.cpp
---
