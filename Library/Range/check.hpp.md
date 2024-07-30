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
  bundledCode: "#line 2 \"Library/Range/check.hpp\"\n\n#include <concepts>\n#include\
    \ <iostream>\n#include <iterator>\n\nnamespace myranges::check {\n\n// =======================================================\n\
    //\ntemplate <std::weakly_incrementable>\nvoid _is_weakly_incrementable() {\n\
    \  std::cout << \"weakly_incrementable: True\" << std::endl;\n}\ntemplate <class\
    \ I>\nvoid _is_weakly_incrementable() {\n  std::cout << \"weakly_incrementable:\
    \ False\" << std::endl;\n}\n\ntemplate <std::input_or_output_iterator I>\nvoid\
    \ _is_input_or_output_iterator() {\n  std::cout << \"input_or_output_iterator:\
    \ True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_input_or_output_iterator()\
    \ {\n  std::cout << \"input_or_output_iterator: False\" << std::endl;\n}\n\ntemplate\
    \ <std::indirectly_readable>\nvoid _is_indirectly_readable() {\n  std::cout <<\
    \ \"indirectly_readable: True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_indirectly_readable()\
    \ {\n  std::cout << \"indirectly_readable: False\" << std::endl;\n}\n\ntemplate\
    \ <std::input_iterator I>\nvoid _is_input_iterator() {\n  std::cout << \"input_iterator:\
    \ True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_input_iterator() {\n \
    \ std::cout << \"input_iterator: False\" << std::endl;\n}\n\ntemplate <class T>\n\
    auto iterator() {\n  std::cout << \"-- iterator --\" << std::endl;\n  _is_weakly_incrementable<T>();\n\
    \  _is_input_or_output_iterator<T>();\n  _is_indirectly_readable<T>();\n  _is_input_iterator<T>();\n\
    }\n\n// =======================================================\n\ntemplate <class\
    \ I, class S>\nrequires std::equality_comparable_with<I, S>\nvoid _is_equality_comparable_with()\
    \ {\n  std::cout << \"equality_comparable_with: True\" << std::endl;\n}\ntemplate\
    \ <class I, class S>\nvoid _is_equality_comparable_with() {\n  std::cout << \"\
    equality_comparable_with: False\" << std::endl;\n}\n\ntemplate <std::default_initializable\
    \ i>\nvoid _is_default_initializable() {\n  std::cout << \"default_initializable:\
    \ True\" << std::endl;\n}\ntemplate <class i>\nvoid _is_default_initializable()\
    \ {\n  std::cout << \"default_initializable: False\" << std::endl;\n}\n\ntemplate\
    \ <std::copyable I>\nvoid _is_copyable() {\n  std::cout << \"copyable: True\"\
    \ << std::endl;\n}\ntemplate <class I>\nvoid _is_copyable() {\n  std::cout <<\
    \ \"copyable: False\" << std::endl;\n}\n\ntemplate <std::semiregular i>\nvoid\
    \ _is_semiregular() {\n  std::cout << \"semiregular: True\" << std::endl;\n}\n\
    template <class i>\nvoid _is_semiregular() {\n  std::cout << \"semiregular: False\"\
    \ << std::endl;\n}\n\ntemplate <class I, std::sentinel_for<I> S>\nvoid _is_sentinel_for()\
    \ {\n  std::cout << \"sentinel_for: True\" << std::endl;\n}\ntemplate <class I,\
    \ class S>\nvoid _is_sentinel_for() {\n  std::cout << \"sentinel_for: False\"\
    \ << std::endl;\n}\n\ntemplate <std::ranges::range T>\nvoid _is_range() {\n  std::cout\
    \ << \"range: True\" << std::endl;\n}\ntemplate <class T>\nvoid _is_range() {\n\
    \  std::cout << \"range: False\" << std::endl;\n}\ntemplate <std::ranges::input_range\
    \ T>\nvoid _is_input_range() {\n  std::cout << \"input_range: True\" << std::endl;\n\
    }\ntemplate <class T>\nvoid _is_input_range() {\n  std::cout << \"input_range:\
    \ False\" << std::endl;\n}\n\ntemplate <class T>\nauto input_range(T x) {\n  std::cout\
    \ << \"-- input range --\" << std::endl;\n  _is_equality_comparable_with<decltype(x.begin()),\
    \ decltype(x.end())>();\n  _is_default_initializable<decltype(x.end())>();\n \
    \ _is_copyable<decltype(x.end())>();\n  _is_semiregular<decltype(x.end())>();\n\
    \  _is_sentinel_for<decltype(x.begin()), decltype(x.end())>();\n  _is_range<T>();\n\
    \  _is_input_range<T>();\n}\n\n// =======================================================\n\
    \ntemplate <std::ranges::view T>\nvoid _is_view() {\n  std::cout << \"view: True\"\
    \ << std::endl;\n}\ntemplate <class T>\nvoid _is_view() {\n  std::cout << \"view:\
    \ False\" << std::endl;\n}\n\ntemplate <class T>\nvoid _is_object_v() {\n  std::cout\
    \ << \"is_object_v: \" << (std::is_object_v<T> ? \"True\" : \"False\")\n     \
    \       << std::endl;\n}\n\ntemplate <std::move_constructible T>\nvoid _is_move_constructible()\
    \ {\n  std::cout << \"move_constructible: True\" << std::endl;\n}\ntemplate <class\
    \ T>\nvoid _is_move_constructible() {\n  std::cout << \"move_constructible: False\"\
    \ << std::endl;\n}\n\ntemplate <class T>\nrequires std::assignable_from<T&, T>\n\
    void _is_assignable_from() {\n  std::cout << \"assignable_from: True\" << std::endl;\n\
    }\ntemplate <class T>\nvoid _is_assignable_from() {\n  std::cout << \"assignable_from:\
    \ False\" << std::endl;\n}\n\ntemplate <std::swappable T>\nvoid _is_swappable()\
    \ {\n  std::cout << \"swappable: True\" << std::endl;\n}\ntemplate <class T>\n\
    void _is_swappable() {\n  std::cout << \"swappable: False\" << std::endl;\n}\n\
    \ntemplate <std::movable T>\nvoid _is_movable() {\n  std::cout << \"movable: True\"\
    \ << std::endl;\n}\ntemplate <class T>\nvoid _is_movable() {\n  std::cout << \"\
    movable: False\" << std::endl;\n}\n\ntemplate <class T>\nvoid _is_enable_view()\
    \ {\n  std::cout << \"enable_view: \"\n            << (std::ranges::enable_view<T>\
    \ ? \"True\" : \"False\") << std::endl;\n}\n\ntemplate <class T>\nauto view(T\
    \ x) {\n  std::cout << \"-- view --\" << std::endl;\n  _is_object_v<T>();\n  _is_move_constructible<T>();\n\
    \  _is_assignable_from<T>();\n  _is_swappable<T>();\n  _is_movable<T>();\n  _is_enable_view<T>();\n\
    \  _is_view<T>();\n}\n\n// =======================================================\n\
    //\ntemplate <class T, class... Args>\nauto all(const Args... args) {\n  iterator<typename\
    \ T::iterator>();\n  input_range(T(args...));\n  view(T(args...));\n}\n\n}  //\
    \ namespace myranges::check\n"
  code: "#pragma once\n\n#include <concepts>\n#include <iostream>\n#include <iterator>\n\
    \nnamespace myranges::check {\n\n// =======================================================\n\
    //\ntemplate <std::weakly_incrementable>\nvoid _is_weakly_incrementable() {\n\
    \  std::cout << \"weakly_incrementable: True\" << std::endl;\n}\ntemplate <class\
    \ I>\nvoid _is_weakly_incrementable() {\n  std::cout << \"weakly_incrementable:\
    \ False\" << std::endl;\n}\n\ntemplate <std::input_or_output_iterator I>\nvoid\
    \ _is_input_or_output_iterator() {\n  std::cout << \"input_or_output_iterator:\
    \ True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_input_or_output_iterator()\
    \ {\n  std::cout << \"input_or_output_iterator: False\" << std::endl;\n}\n\ntemplate\
    \ <std::indirectly_readable>\nvoid _is_indirectly_readable() {\n  std::cout <<\
    \ \"indirectly_readable: True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_indirectly_readable()\
    \ {\n  std::cout << \"indirectly_readable: False\" << std::endl;\n}\n\ntemplate\
    \ <std::input_iterator I>\nvoid _is_input_iterator() {\n  std::cout << \"input_iterator:\
    \ True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_input_iterator() {\n \
    \ std::cout << \"input_iterator: False\" << std::endl;\n}\n\ntemplate <class T>\n\
    auto iterator() {\n  std::cout << \"-- iterator --\" << std::endl;\n  _is_weakly_incrementable<T>();\n\
    \  _is_input_or_output_iterator<T>();\n  _is_indirectly_readable<T>();\n  _is_input_iterator<T>();\n\
    }\n\n// =======================================================\n\ntemplate <class\
    \ I, class S>\nrequires std::equality_comparable_with<I, S>\nvoid _is_equality_comparable_with()\
    \ {\n  std::cout << \"equality_comparable_with: True\" << std::endl;\n}\ntemplate\
    \ <class I, class S>\nvoid _is_equality_comparable_with() {\n  std::cout << \"\
    equality_comparable_with: False\" << std::endl;\n}\n\ntemplate <std::default_initializable\
    \ i>\nvoid _is_default_initializable() {\n  std::cout << \"default_initializable:\
    \ True\" << std::endl;\n}\ntemplate <class i>\nvoid _is_default_initializable()\
    \ {\n  std::cout << \"default_initializable: False\" << std::endl;\n}\n\ntemplate\
    \ <std::copyable I>\nvoid _is_copyable() {\n  std::cout << \"copyable: True\"\
    \ << std::endl;\n}\ntemplate <class I>\nvoid _is_copyable() {\n  std::cout <<\
    \ \"copyable: False\" << std::endl;\n}\n\ntemplate <std::semiregular i>\nvoid\
    \ _is_semiregular() {\n  std::cout << \"semiregular: True\" << std::endl;\n}\n\
    template <class i>\nvoid _is_semiregular() {\n  std::cout << \"semiregular: False\"\
    \ << std::endl;\n}\n\ntemplate <class I, std::sentinel_for<I> S>\nvoid _is_sentinel_for()\
    \ {\n  std::cout << \"sentinel_for: True\" << std::endl;\n}\ntemplate <class I,\
    \ class S>\nvoid _is_sentinel_for() {\n  std::cout << \"sentinel_for: False\"\
    \ << std::endl;\n}\n\ntemplate <std::ranges::range T>\nvoid _is_range() {\n  std::cout\
    \ << \"range: True\" << std::endl;\n}\ntemplate <class T>\nvoid _is_range() {\n\
    \  std::cout << \"range: False\" << std::endl;\n}\ntemplate <std::ranges::input_range\
    \ T>\nvoid _is_input_range() {\n  std::cout << \"input_range: True\" << std::endl;\n\
    }\ntemplate <class T>\nvoid _is_input_range() {\n  std::cout << \"input_range:\
    \ False\" << std::endl;\n}\n\ntemplate <class T>\nauto input_range(T x) {\n  std::cout\
    \ << \"-- input range --\" << std::endl;\n  _is_equality_comparable_with<decltype(x.begin()),\
    \ decltype(x.end())>();\n  _is_default_initializable<decltype(x.end())>();\n \
    \ _is_copyable<decltype(x.end())>();\n  _is_semiregular<decltype(x.end())>();\n\
    \  _is_sentinel_for<decltype(x.begin()), decltype(x.end())>();\n  _is_range<T>();\n\
    \  _is_input_range<T>();\n}\n\n// =======================================================\n\
    \ntemplate <std::ranges::view T>\nvoid _is_view() {\n  std::cout << \"view: True\"\
    \ << std::endl;\n}\ntemplate <class T>\nvoid _is_view() {\n  std::cout << \"view:\
    \ False\" << std::endl;\n}\n\ntemplate <class T>\nvoid _is_object_v() {\n  std::cout\
    \ << \"is_object_v: \" << (std::is_object_v<T> ? \"True\" : \"False\")\n     \
    \       << std::endl;\n}\n\ntemplate <std::move_constructible T>\nvoid _is_move_constructible()\
    \ {\n  std::cout << \"move_constructible: True\" << std::endl;\n}\ntemplate <class\
    \ T>\nvoid _is_move_constructible() {\n  std::cout << \"move_constructible: False\"\
    \ << std::endl;\n}\n\ntemplate <class T>\nrequires std::assignable_from<T&, T>\n\
    void _is_assignable_from() {\n  std::cout << \"assignable_from: True\" << std::endl;\n\
    }\ntemplate <class T>\nvoid _is_assignable_from() {\n  std::cout << \"assignable_from:\
    \ False\" << std::endl;\n}\n\ntemplate <std::swappable T>\nvoid _is_swappable()\
    \ {\n  std::cout << \"swappable: True\" << std::endl;\n}\ntemplate <class T>\n\
    void _is_swappable() {\n  std::cout << \"swappable: False\" << std::endl;\n}\n\
    \ntemplate <std::movable T>\nvoid _is_movable() {\n  std::cout << \"movable: True\"\
    \ << std::endl;\n}\ntemplate <class T>\nvoid _is_movable() {\n  std::cout << \"\
    movable: False\" << std::endl;\n}\n\ntemplate <class T>\nvoid _is_enable_view()\
    \ {\n  std::cout << \"enable_view: \"\n            << (std::ranges::enable_view<T>\
    \ ? \"True\" : \"False\") << std::endl;\n}\n\ntemplate <class T>\nauto view(T\
    \ x) {\n  std::cout << \"-- view --\" << std::endl;\n  _is_object_v<T>();\n  _is_move_constructible<T>();\n\
    \  _is_assignable_from<T>();\n  _is_swappable<T>();\n  _is_movable<T>();\n  _is_enable_view<T>();\n\
    \  _is_view<T>();\n}\n\n// =======================================================\n\
    //\ntemplate <class T, class... Args>\nauto all(const Args... args) {\n  iterator<typename\
    \ T::iterator>();\n  input_range(T(args...));\n  view(T(args...));\n}\n\n}  //\
    \ namespace myranges::check\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/check.hpp
  requiredBy: []
  timestamp: '2024-07-30 22:13:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/check.hpp
layout: document
redirect_from:
- /library/Library/Range/check.hpp
- /library/Library/Range/check.hpp.html
title: Library/Range/check.hpp
---
