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
  bundledCode: "#line 2 \"Library/Range/check.hpp\"\n\n#include <iostream>\n#include\
    \ <iterator>\n\nnamespace myranges::check {\n\ntemplate <std::weakly_incrementable>\n\
    void _is_weakly_incrementable() {\n  std::cout << \"weakly_incrementable: True\"\
    \ << std::endl;\n}\ntemplate <class I>\nvoid _is_weakly_incrementable() {\n  std::cout\
    \ << \"weakly_incrementable: False\" << std::endl;\n}\n\ntemplate <std::input_or_output_iterator\
    \ I>\nvoid _is_input_or_output_iterator() {\n  std::cout << \"input_or_output_iterator:\
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
    }\n\ntemplate <class I, class S>\nrequires std::equality_comparable_with<I, S>\n\
    void _is_equality_comparable_with() {\n  std::cout << \"equality_comparable_with:\
    \ True\" << std::endl;\n}\ntemplate <class I, class S>\nvoid _is_equality_comparable_with()\
    \ {\n  std::cout << \"equality_comparable_with: False\" << std::endl;\n}\n\ntemplate\
    \ <std::default_initializable i>\nvoid _is_default_initializable() {\n  std::cout\
    \ << \"default_initializable: True\" << std::endl;\n}\ntemplate <class i>\nvoid\
    \ _is_default_initializable() {\n  std::cout << \"default_initializable: False\"\
    \ << std::endl;\n}\n\ntemplate <std::copyable I>\nvoid _is_copyable() {\n  std::cout\
    \ << \"copyable: True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_copyable()\
    \ {\n  std::cout << \"copyable: False\" << std::endl;\n}\n\ntemplate <std::semiregular\
    \ i>\nvoid _is_semiregular() {\n  std::cout << \"semiregular: True\" << std::endl;\n\
    }\ntemplate <class i>\nvoid _is_semiregular() {\n  std::cout << \"semiregular:\
    \ False\" << std::endl;\n}\n\ntemplate <class I, std::sentinel_for<I> S>\nvoid\
    \ _is_sentinel_for() {\n  std::cout << \"sentinel_for: True\" << std::endl;\n\
    }\ntemplate <class I, class S>\nvoid _is_sentinel_for() {\n  std::cout << \"sentinel_for:\
    \ False\" << std::endl;\n}\n\ntemplate <std::ranges::range T>\nvoid _is_range()\
    \ {\n  std::cout << \"range: True\" << std::endl;\n}\ntemplate <class T>\nvoid\
    \ _is_range() {\n  std::cout << \"range: False\" << std::endl;\n}\ntemplate <std::ranges::input_range\
    \ T>\nvoid _is_input_range() {\n  std::cout << \"input_range: True\" << std::endl;\n\
    }\ntemplate <class T>\nvoid _is_input_range() {\n  std::cout << \"input_range:\
    \ False\" << std::endl;\n}\n\ntemplate <class T>\nauto range(T x) {\n  std::cout\
    \ << \"-- range --\" << std::endl;\n  _is_equality_comparable_with<decltype(x.begin()),\
    \ decltype(x.end())>();\n  _is_default_initializable<decltype(x.end())>();\n \
    \ _is_copyable<decltype(x.end())>();\n  _is_semiregular<decltype(x.end())>();\n\
    \  _is_sentinel_for<decltype(x.begin()), decltype(x.end())>();\n  _is_range<T>();\n\
    \  _is_input_range<T>();\n}\n\ntemplate <class T, class... Args>\nauto all(const\
    \ Args... args) {\n  iterator<typename T::iterator>();\n  range(T(args...));\n\
    }\n\n}  // namespace myranges::check\n"
  code: "#pragma once\n\n#include <iostream>\n#include <iterator>\n\nnamespace myranges::check\
    \ {\n\ntemplate <std::weakly_incrementable>\nvoid _is_weakly_incrementable() {\n\
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
    }\n\ntemplate <class I, class S>\nrequires std::equality_comparable_with<I, S>\n\
    void _is_equality_comparable_with() {\n  std::cout << \"equality_comparable_with:\
    \ True\" << std::endl;\n}\ntemplate <class I, class S>\nvoid _is_equality_comparable_with()\
    \ {\n  std::cout << \"equality_comparable_with: False\" << std::endl;\n}\n\ntemplate\
    \ <std::default_initializable i>\nvoid _is_default_initializable() {\n  std::cout\
    \ << \"default_initializable: True\" << std::endl;\n}\ntemplate <class i>\nvoid\
    \ _is_default_initializable() {\n  std::cout << \"default_initializable: False\"\
    \ << std::endl;\n}\n\ntemplate <std::copyable I>\nvoid _is_copyable() {\n  std::cout\
    \ << \"copyable: True\" << std::endl;\n}\ntemplate <class I>\nvoid _is_copyable()\
    \ {\n  std::cout << \"copyable: False\" << std::endl;\n}\n\ntemplate <std::semiregular\
    \ i>\nvoid _is_semiregular() {\n  std::cout << \"semiregular: True\" << std::endl;\n\
    }\ntemplate <class i>\nvoid _is_semiregular() {\n  std::cout << \"semiregular:\
    \ False\" << std::endl;\n}\n\ntemplate <class I, std::sentinel_for<I> S>\nvoid\
    \ _is_sentinel_for() {\n  std::cout << \"sentinel_for: True\" << std::endl;\n\
    }\ntemplate <class I, class S>\nvoid _is_sentinel_for() {\n  std::cout << \"sentinel_for:\
    \ False\" << std::endl;\n}\n\ntemplate <std::ranges::range T>\nvoid _is_range()\
    \ {\n  std::cout << \"range: True\" << std::endl;\n}\ntemplate <class T>\nvoid\
    \ _is_range() {\n  std::cout << \"range: False\" << std::endl;\n}\ntemplate <std::ranges::input_range\
    \ T>\nvoid _is_input_range() {\n  std::cout << \"input_range: True\" << std::endl;\n\
    }\ntemplate <class T>\nvoid _is_input_range() {\n  std::cout << \"input_range:\
    \ False\" << std::endl;\n}\n\ntemplate <class T>\nauto range(T x) {\n  std::cout\
    \ << \"-- range --\" << std::endl;\n  _is_equality_comparable_with<decltype(x.begin()),\
    \ decltype(x.end())>();\n  _is_default_initializable<decltype(x.end())>();\n \
    \ _is_copyable<decltype(x.end())>();\n  _is_semiregular<decltype(x.end())>();\n\
    \  _is_sentinel_for<decltype(x.begin()), decltype(x.end())>();\n  _is_range<T>();\n\
    \  _is_input_range<T>();\n}\n\ntemplate <class T, class... Args>\nauto all(const\
    \ Args... args) {\n  iterator<typename T::iterator>();\n  range(T(args...));\n\
    }\n\n}  // namespace myranges::check\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/check.hpp
  requiredBy: []
  timestamp: '2024-07-30 00:37:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/check.hpp
layout: document
redirect_from:
- /library/Library/Range/check.hpp
- /library/Library/Range/check.hpp.html
title: Library/Range/check.hpp
---
