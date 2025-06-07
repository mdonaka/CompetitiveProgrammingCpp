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
  bundledCode: "#line 2 \"Library/Range/set.hpp\"\n\n#include <ranges>\n#include <vector>\n\
    \nnamespace mtd {\n  namespace ranges {\n\n    struct base_k_product_view\n  \
    \      : public std::ranges::view_interface<base_k_product_view> {\n      class\
    \ iterator {\n        int n, k;\n        std::vector<int> _M_current;\n\n    \
    \  public:\n        using difference_type = int;\n        using value_type = std::vector<int>;\n\
    \        using iterator_concept = std::bidirectional_iterator_tag;\n\n       \
    \ constexpr iterator() = default;\n        constexpr explicit iterator(int _n,\
    \ int _k)\n            : n(_n), k(_k), _M_current(_n) {}\n        constexpr auto\
    \ operator*() const { return _M_current; }\n        constexpr auto &operator++()\
    \ {\n          ++_M_current[0];\n          for (auto i : std::views::iota(0, n\
    \ - 1)) {\n            if (_M_current[i] >= k) {\n              _M_current[i]\
    \ = 0;\n              ++_M_current[i + 1];\n            }\n          }\n     \
    \     return *this;\n        }\n        constexpr auto operator++(int) { return\
    \ ++*this; }\n        constexpr auto &operator--() {\n          if (_M_current.back()\
    \ == k) {\n            _M_current = std::vector<int>(n, k - 1);\n          } else\
    \ {\n            --_M_current.back();\n            for (auto i : std::views::iota(1,\
    \ n) | std::views::reverse) {\n              if (_M_current[i] < 0) {\n      \
    \          _M_current[i] = k - 1;\n                --_M_current[i - 1];\n    \
    \          }\n            }\n          }\n          return *this;\n        }\n\
    \        constexpr auto operator--(int) { return --*this; }\n        constexpr\
    \ auto operator==(const iterator &s) const {\n          return _M_current == s._M_current;\n\
    \        }\n        constexpr auto operator==(std::default_sentinel_t) const {\n\
    \          return _M_current.back() == k;\n        }\n        constexpr friend\
    \ auto operator==(std::default_sentinel_t s,\n                               \
    \          const iterator &li) {\n          return li == s;\n        }\n     \
    \ };\n\n      int n, k;\n\n      constexpr explicit base_k_product_view(int _n,\
    \ int _k) : n(_n), k(_k) {}\n      constexpr auto begin() const { return iterator(n,\
    \ k); }\n      constexpr auto end() const { return std::default_sentinel; }\n\
    \    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_base_k_product_view\
    \ = requires {\n        ranges::base_k_product_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _BaseKProduct {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_base_k_product_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::base_k_product_view(std::forward<_Tp>(__e)...);\n      }\n \
    \   };\n    inline constexpr _BaseKProduct base_k_product{};\n  }  // namespace\
    \ views\n\n}  // namespace mtd\n"
  code: "#pragma once\n\n#include <ranges>\n#include <vector>\n\nnamespace mtd {\n\
    \  namespace ranges {\n\n    struct base_k_product_view\n        : public std::ranges::view_interface<base_k_product_view>\
    \ {\n      class iterator {\n        int n, k;\n        std::vector<int> _M_current;\n\
    \n      public:\n        using difference_type = int;\n        using value_type\
    \ = std::vector<int>;\n        using iterator_concept = std::bidirectional_iterator_tag;\n\
    \n        constexpr iterator() = default;\n        constexpr explicit iterator(int\
    \ _n, int _k)\n            : n(_n), k(_k), _M_current(_n) {}\n        constexpr\
    \ auto operator*() const { return _M_current; }\n        constexpr auto &operator++()\
    \ {\n          ++_M_current[0];\n          for (auto i : std::views::iota(0, n\
    \ - 1)) {\n            if (_M_current[i] >= k) {\n              _M_current[i]\
    \ = 0;\n              ++_M_current[i + 1];\n            }\n          }\n     \
    \     return *this;\n        }\n        constexpr auto operator++(int) { return\
    \ ++*this; }\n        constexpr auto &operator--() {\n          if (_M_current.back()\
    \ == k) {\n            _M_current = std::vector<int>(n, k - 1);\n          } else\
    \ {\n            --_M_current.back();\n            for (auto i : std::views::iota(1,\
    \ n) | std::views::reverse) {\n              if (_M_current[i] < 0) {\n      \
    \          _M_current[i] = k - 1;\n                --_M_current[i - 1];\n    \
    \          }\n            }\n          }\n          return *this;\n        }\n\
    \        constexpr auto operator--(int) { return --*this; }\n        constexpr\
    \ auto operator==(const iterator &s) const {\n          return _M_current == s._M_current;\n\
    \        }\n        constexpr auto operator==(std::default_sentinel_t) const {\n\
    \          return _M_current.back() == k;\n        }\n        constexpr friend\
    \ auto operator==(std::default_sentinel_t s,\n                               \
    \          const iterator &li) {\n          return li == s;\n        }\n     \
    \ };\n\n      int n, k;\n\n      constexpr explicit base_k_product_view(int _n,\
    \ int _k) : n(_n), k(_k) {}\n      constexpr auto begin() const { return iterator(n,\
    \ k); }\n      constexpr auto end() const { return std::default_sentinel; }\n\
    \    };\n  }  // namespace ranges\n\n  namespace views {\n    namespace __detail\
    \ {\n      template <typename... _Args>\n      concept __can_base_k_product_view\
    \ = requires {\n        ranges::base_k_product_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _BaseKProduct {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_base_k_product_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::base_k_product_view(std::forward<_Tp>(__e)...);\n      }\n \
    \   };\n    inline constexpr _BaseKProduct base_k_product{};\n  }  // namespace\
    \ views\n\n}  // namespace mtd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/set.hpp
  requiredBy: []
  timestamp: '2025-06-08 01:08:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/set.hpp
layout: document
redirect_from:
- /library/Library/Range/set.hpp
- /library/Library/Range/set.hpp.html
title: Library/Range/set.hpp
---
