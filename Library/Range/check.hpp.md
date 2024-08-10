---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Test/Range/enumerate.test.cpp
    title: Test/Range/enumerate.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Library/Range/check.hpp\"\n\n#include <concepts>\n#include\
    \ <iostream>\n#include <iterator>\n\nnamespace mtd::check {\n\n  // =======================================================\n\
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
    \    input_range<T>();\n    view<T>();\n  }\n\n}  // namespace mtd::check\n"
  code: "#pragma once\n\n#include <concepts>\n#include <iostream>\n#include <iterator>\n\
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
    \    input_range<T>();\n    view<T>();\n  }\n\n}  // namespace mtd::check\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/check.hpp
  requiredBy: []
  timestamp: '2024-08-10 19:46:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Test/Range/enumerate.test.cpp
documentation_of: Library/Range/check.hpp
layout: document
redirect_from:
- /library/Library/Range/check.hpp
- /library/Library/Range/check.hpp.html
title: Library/Range/check.hpp
---
