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
  bundledCode: "#line 2 \"Library/Range/check.hpp\"\n\n#include <algorithm>\n#include\
    \ <concepts>\n#include <iomanip>\n#include <iostream>\n#include <ranges>\n#include\
    \ <string>\n#include <vector>\n\nnamespace mtd::check {\n  class Table {\n   \
    \ std::string title;\n    std::vector<std::pair<std::string, bool>> table;\n\n\
    \  public:\n    Table(const std::string& title) : title(title) {}\n\n    auto\
    \ add(const std::string& name, bool b) { table.emplace_back(name, b); }\n    auto\
    \ print() const {\n      auto size = std::ranges::max(\n          table |\n  \
    \        std::views::transform([](const std::pair<std::string, bool>& p) {\n \
    \           return p.first.size();\n          }));\n\n      std::cout << std::string(size\
    \ + 12, '_') << std::endl;\n      std::cout << \"| \" << title << std::string(size\
    \ + 9 - title.size(), ' ')\n                << \"|\" << std::endl;\n      std::cout\
    \ << \"|\" << std::string(size + 10, '-') << \"|\" << std::endl;\n      for (const\
    \ auto& [s, b] : table) {\n        std::cout << \"| \" << std::left << std::setw(size)\
    \ << s << \" | \"\n                  << (b ? \"True \" : \"False\") << \" |\"\
    \ << std::endl;\n      }\n    }\n  };\n\n  template <class T>\n  auto iterator()\
    \ {\n    auto table = Table(\"iterator\");\n    table.add(\"weakly_incrementable\"\
    , std::weakly_incrementable<T>);\n    table.add(\"input_or_output_iterator\",\
    \ std::input_or_output_iterator<T>);\n    table.add(\"indirectly_readable\", std::indirectly_readable<T>);\n\
    \    table.add(\"input_iterator\", std::input_iterator<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto input_range() {\n    using begin = decltype(std::declval<T>().begin());\n\
    \    using end = decltype(std::declval<T>().end());\n\n    auto table = Table(\"\
    input_range\");\n    table.add(\"equality_comparable_with\",\n              std::equality_comparable_with<begin,\
    \ end>);\n    table.add(\"default_initializable\", std::default_initializable<begin>);\n\
    \    table.add(\"copyable\", std::copyable<end>);\n    table.add(\"semiregular\"\
    , std::semiregular<end>);\n    table.add(\"sentinel_for\", std::sentinel_for<end,\
    \ begin>);\n    table.add(\"range\", std::ranges::range<T>);\n    table.add(\"\
    input_range\", std::ranges::input_range<T>);\n    table.print();\n  }\n\n  template\
    \ <class T>\n  auto view() {\n    auto table = Table(\"view\");\n    table.add(\"\
    object_v\", std::is_object_v<T>);\n    table.add(\"move_constructible\", std::move_constructible<T>);\n\
    \    table.add(\"assignable_from\", std::assignable_from<T&, T>);\n    table.add(\"\
    swappable\", std::swappable<T>);\n    table.add(\"movable\", std::movable<T>);\n\
    \    table.add(\"derived_from\", std::derived_from<T, std::ranges::view_base>);\n\
    \    table.add(\"enable_view\", std::ranges::enable_view<T>);\n    table.add(\"\
    view\", std::ranges::view<T>);\n    table.print();\n  }\n\n  template <class T>\n\
    \  requires requires(T t) { typename T::iterator; }\n  auto all() {\n    iterator<typename\
    \ T::iterator>();\n    input_range<T>();\n    view<T>();\n  }\n\n}  // namespace\
    \ mtd::check\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <concepts>\n#include <iomanip>\n\
    #include <iostream>\n#include <ranges>\n#include <string>\n#include <vector>\n\
    \nnamespace mtd::check {\n  class Table {\n    std::string title;\n    std::vector<std::pair<std::string,\
    \ bool>> table;\n\n  public:\n    Table(const std::string& title) : title(title)\
    \ {}\n\n    auto add(const std::string& name, bool b) { table.emplace_back(name,\
    \ b); }\n    auto print() const {\n      auto size = std::ranges::max(\n     \
    \     table |\n          std::views::transform([](const std::pair<std::string,\
    \ bool>& p) {\n            return p.first.size();\n          }));\n\n      std::cout\
    \ << std::string(size + 12, '_') << std::endl;\n      std::cout << \"| \" << title\
    \ << std::string(size + 9 - title.size(), ' ')\n                << \"|\" << std::endl;\n\
    \      std::cout << \"|\" << std::string(size + 10, '-') << \"|\" << std::endl;\n\
    \      for (const auto& [s, b] : table) {\n        std::cout << \"| \" << std::left\
    \ << std::setw(size) << s << \" | \"\n                  << (b ? \"True \" : \"\
    False\") << \" |\" << std::endl;\n      }\n    }\n  };\n\n  template <class T>\n\
    \  auto iterator() {\n    auto table = Table(\"iterator\");\n    table.add(\"\
    weakly_incrementable\", std::weakly_incrementable<T>);\n    table.add(\"input_or_output_iterator\"\
    , std::input_or_output_iterator<T>);\n    table.add(\"indirectly_readable\", std::indirectly_readable<T>);\n\
    \    table.add(\"input_iterator\", std::input_iterator<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto input_range() {\n    using begin = decltype(std::declval<T>().begin());\n\
    \    using end = decltype(std::declval<T>().end());\n\n    auto table = Table(\"\
    input_range\");\n    table.add(\"equality_comparable_with\",\n              std::equality_comparable_with<begin,\
    \ end>);\n    table.add(\"default_initializable\", std::default_initializable<begin>);\n\
    \    table.add(\"copyable\", std::copyable<end>);\n    table.add(\"semiregular\"\
    , std::semiregular<end>);\n    table.add(\"sentinel_for\", std::sentinel_for<end,\
    \ begin>);\n    table.add(\"range\", std::ranges::range<T>);\n    table.add(\"\
    input_range\", std::ranges::input_range<T>);\n    table.print();\n  }\n\n  template\
    \ <class T>\n  auto view() {\n    auto table = Table(\"view\");\n    table.add(\"\
    object_v\", std::is_object_v<T>);\n    table.add(\"move_constructible\", std::move_constructible<T>);\n\
    \    table.add(\"assignable_from\", std::assignable_from<T&, T>);\n    table.add(\"\
    swappable\", std::swappable<T>);\n    table.add(\"movable\", std::movable<T>);\n\
    \    table.add(\"derived_from\", std::derived_from<T, std::ranges::view_base>);\n\
    \    table.add(\"enable_view\", std::ranges::enable_view<T>);\n    table.add(\"\
    view\", std::ranges::view<T>);\n    table.print();\n  }\n\n  template <class T>\n\
    \  requires requires(T t) { typename T::iterator; }\n  auto all() {\n    iterator<typename\
    \ T::iterator>();\n    input_range<T>();\n    view<T>();\n  }\n\n}  // namespace\
    \ mtd::check\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/check.hpp
  requiredBy: []
  timestamp: '2024-08-17 21:05:39+09:00'
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
