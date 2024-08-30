---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Library/Range/template.cpp
    title: Library/Range/template.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \           return p.first.size();\n          }));\n\n      // std::cout << std::string(size\
    \ + 12, '_') << std::endl;\n      std::cout << \"|\" << std::string(size + 10,\
    \ '-') << \"|\" << std::endl;\n      std::cout << \"| \" << title << std::string(size\
    \ + 9 - title.size(), ' ')\n                << \"|\" << std::endl;\n      std::cout\
    \ << \"|\" << std::string(size + 10, '-') << \"|\" << std::endl;\n      for (const\
    \ auto& [s, b] : table) {\n        std::cout << \"| \" << std::left << std::setw(size)\
    \ << s << \" | \"\n                  << (b ? \"True \" : \"False\") << \" |\"\
    \ << std::endl;\n      }\n      std::cout << \"|\" << std::string(size + 10, '_')\
    \ << \"|\" << std::endl;\n    }\n  };\n\n  template <class T>\n  auto range()\
    \ {\n    using iterator = decltype(std::declval<T>().begin());\n    using sentinel\
    \ = decltype(std::declval<T>().end());\n\n    auto table = Table(\"range\");\n\
    \    table.add(\"weakly-equality-comparable-with\",\n              std::__detail::__weakly_eq_cmp_with<iterator,\
    \ sentinel>);\n\n    table.add(\"default_initializable\", std::default_initializable<iterator>);\n\
    \    table.add(\"copyable\", std::copyable<sentinel>);\n    table.add(\"semiregular\"\
    , std::semiregular<sentinel>);\n    table.add(\"sentinel_for\", std::sentinel_for<sentinel,\
    \ iterator>);\n    table.add(\"range\", std::ranges::range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto input_range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \n    auto table = Table(\"input_range\");\n    table.add(\"weakly_incrementable\"\
    , std::weakly_incrementable<iterator>);\n    table.add(\"input_or_output_iterator\"\
    ,\n              std::input_or_output_iterator<iterator>);\n    table.add(\"indirectly_readable\"\
    , std::indirectly_readable<iterator>);\n    table.add(\"input_iterator\", std::input_iterator<iterator>);\n\
    \    table.add(\"input_range\", std::ranges::input_range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto forward_range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \n    auto table = Table(\"forward_range\");\n    table.add(\"incrementable\"\
    , std::incrementable<iterator>);\n    table.add(\"sentinel_for\", std::sentinel_for<iterator,\
    \ iterator>);\n    table.add(\"forward_range\", std::ranges::forward_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto bidirectional_range()\
    \ {\n    using iterator = decltype(std::declval<T>().begin());\n\n    auto table\
    \ = Table(\"bidirectional_range\");\n    table.add(\n        \"decrementable\"\
    , requires(iterator t) {\n          { --t } -> std::same_as<iterator&>;\n    \
    \      { t-- } -> std::same_as<iterator>;\n        });\n    table.add(\"bidirectional_range\"\
    , std::ranges::bidirectional_range<T>);\n    table.print();\n  }\n\n  template\
    \ <class T>\n  auto random_access_range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \n    auto table = Table(\"random_access_range\");\n    table.add(\"totally_ordered\"\
    , std::totally_ordered<iterator>);\n    table.add(\"sized_sentinel_for\",\n  \
    \            std::sized_sentinel_for<iterator, iterator>);\n\n    table.add(\n\
    \        \"plus\", requires(iterator i, const iterator j,\n                  \
    \       const std::iter_difference_t<iterator> n) {\n          { i += n } -> std::same_as<iterator&>;\n\
    \          { j + n } -> std::same_as<iterator>;\n          { n + j } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\n        \"minus\", requires(iterator i, const iterator\
    \ j,\n                          const std::iter_difference_t<iterator> n) {\n\
    \          { i -= n } -> std::same_as<iterator&>;\n          { j - n } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\n        \"access\",\n        requires(const iterator\
    \ j, const std::iter_difference_t<iterator> n) {\n          { j[n] } -> std::same_as<std::iter_reference_t<iterator>>;\n\
    \        });\n    table.add(\"random_access_range\", std::ranges::random_access_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto view() {\n    auto table\
    \ = Table(\"view\");\n    table.add(\"object_v\", std::is_object_v<T>);\n    table.add(\"\
    move_constructible\", std::move_constructible<T>);\n    table.add(\"assignable_from\"\
    , std::assignable_from<T&, T>);\n    table.add(\"swappable\", std::swappable<T>);\n\
    \    table.add(\"movable\", std::movable<T>);\n    // table.add(\"derived_from\"\
    , std::derived_from<T, std::ranges::view_base>);\n    table.add(\"enable_view\"\
    , std::ranges::enable_view<T>);\n    table.add(\"view\", std::ranges::view<T>);\n\
    \    table.add(\"viewable_range\", std::ranges::viewable_range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto all() {\n    range<T>();\n    input_range<T>();\n\
    \    forward_range<T>();\n    bidirectional_range<T>();\n    random_access_range<T>();\n\
    \    view<T>();\n  }\n\n}  // namespace mtd::check\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <concepts>\n#include <iomanip>\n\
    #include <iostream>\n#include <ranges>\n#include <string>\n#include <vector>\n\
    \nnamespace mtd::check {\n  class Table {\n    std::string title;\n    std::vector<std::pair<std::string,\
    \ bool>> table;\n\n  public:\n    Table(const std::string& title) : title(title)\
    \ {}\n\n    auto add(const std::string& name, bool b) { table.emplace_back(name,\
    \ b); }\n    auto print() const {\n      auto size = std::ranges::max(\n     \
    \     table |\n          std::views::transform([](const std::pair<std::string,\
    \ bool>& p) {\n            return p.first.size();\n          }));\n\n      //\
    \ std::cout << std::string(size + 12, '_') << std::endl;\n      std::cout << \"\
    |\" << std::string(size + 10, '-') << \"|\" << std::endl;\n      std::cout <<\
    \ \"| \" << title << std::string(size + 9 - title.size(), ' ')\n             \
    \   << \"|\" << std::endl;\n      std::cout << \"|\" << std::string(size + 10,\
    \ '-') << \"|\" << std::endl;\n      for (const auto& [s, b] : table) {\n    \
    \    std::cout << \"| \" << std::left << std::setw(size) << s << \" | \"\n   \
    \               << (b ? \"True \" : \"False\") << \" |\" << std::endl;\n     \
    \ }\n      std::cout << \"|\" << std::string(size + 10, '_') << \"|\" << std::endl;\n\
    \    }\n  };\n\n  template <class T>\n  auto range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \    using sentinel = decltype(std::declval<T>().end());\n\n    auto table = Table(\"\
    range\");\n    table.add(\"weakly-equality-comparable-with\",\n              std::__detail::__weakly_eq_cmp_with<iterator,\
    \ sentinel>);\n\n    table.add(\"default_initializable\", std::default_initializable<iterator>);\n\
    \    table.add(\"copyable\", std::copyable<sentinel>);\n    table.add(\"semiregular\"\
    , std::semiregular<sentinel>);\n    table.add(\"sentinel_for\", std::sentinel_for<sentinel,\
    \ iterator>);\n    table.add(\"range\", std::ranges::range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto input_range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \n    auto table = Table(\"input_range\");\n    table.add(\"weakly_incrementable\"\
    , std::weakly_incrementable<iterator>);\n    table.add(\"input_or_output_iterator\"\
    ,\n              std::input_or_output_iterator<iterator>);\n    table.add(\"indirectly_readable\"\
    , std::indirectly_readable<iterator>);\n    table.add(\"input_iterator\", std::input_iterator<iterator>);\n\
    \    table.add(\"input_range\", std::ranges::input_range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto forward_range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \n    auto table = Table(\"forward_range\");\n    table.add(\"incrementable\"\
    , std::incrementable<iterator>);\n    table.add(\"sentinel_for\", std::sentinel_for<iterator,\
    \ iterator>);\n    table.add(\"forward_range\", std::ranges::forward_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto bidirectional_range()\
    \ {\n    using iterator = decltype(std::declval<T>().begin());\n\n    auto table\
    \ = Table(\"bidirectional_range\");\n    table.add(\n        \"decrementable\"\
    , requires(iterator t) {\n          { --t } -> std::same_as<iterator&>;\n    \
    \      { t-- } -> std::same_as<iterator>;\n        });\n    table.add(\"bidirectional_range\"\
    , std::ranges::bidirectional_range<T>);\n    table.print();\n  }\n\n  template\
    \ <class T>\n  auto random_access_range() {\n    using iterator = decltype(std::declval<T>().begin());\n\
    \n    auto table = Table(\"random_access_range\");\n    table.add(\"totally_ordered\"\
    , std::totally_ordered<iterator>);\n    table.add(\"sized_sentinel_for\",\n  \
    \            std::sized_sentinel_for<iterator, iterator>);\n\n    table.add(\n\
    \        \"plus\", requires(iterator i, const iterator j,\n                  \
    \       const std::iter_difference_t<iterator> n) {\n          { i += n } -> std::same_as<iterator&>;\n\
    \          { j + n } -> std::same_as<iterator>;\n          { n + j } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\n        \"minus\", requires(iterator i, const iterator\
    \ j,\n                          const std::iter_difference_t<iterator> n) {\n\
    \          { i -= n } -> std::same_as<iterator&>;\n          { j - n } -> std::same_as<iterator>;\n\
    \        });\n    table.add(\n        \"access\",\n        requires(const iterator\
    \ j, const std::iter_difference_t<iterator> n) {\n          { j[n] } -> std::same_as<std::iter_reference_t<iterator>>;\n\
    \        });\n    table.add(\"random_access_range\", std::ranges::random_access_range<T>);\n\
    \    table.print();\n  }\n\n  template <class T>\n  auto view() {\n    auto table\
    \ = Table(\"view\");\n    table.add(\"object_v\", std::is_object_v<T>);\n    table.add(\"\
    move_constructible\", std::move_constructible<T>);\n    table.add(\"assignable_from\"\
    , std::assignable_from<T&, T>);\n    table.add(\"swappable\", std::swappable<T>);\n\
    \    table.add(\"movable\", std::movable<T>);\n    // table.add(\"derived_from\"\
    , std::derived_from<T, std::ranges::view_base>);\n    table.add(\"enable_view\"\
    , std::ranges::enable_view<T>);\n    table.add(\"view\", std::ranges::view<T>);\n\
    \    table.add(\"viewable_range\", std::ranges::viewable_range<T>);\n    table.print();\n\
    \  }\n\n  template <class T>\n  auto all() {\n    range<T>();\n    input_range<T>();\n\
    \    forward_range<T>();\n    bidirectional_range<T>();\n    random_access_range<T>();\n\
    \    view<T>();\n  }\n\n}  // namespace mtd::check\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/check.hpp
  requiredBy:
  - Library/Range/template.cpp
  timestamp: '2024-08-30 15:17:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/check.hpp
layout: document
redirect_from:
- /library/Library/Range/check.hpp
- /library/Library/Range/check.hpp.html
title: Library/Range/check.hpp
---
