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
  bundledCode: "#line 2 \"Library/Range/bit.hpp\"\n\n#include <ranges>\n\nnamespace\
    \ mystd {\n  namespace ranges {\n    struct bit_index_view : public std::ranges::view_interface<bit_index_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n        unsigned\
    \ ctz(unsigned int n) {\n          if (!n) return -1;\n          unsigned int\
    \ c = 32;\n          n &= -static_cast<signed int>(n);\n          if (n) c--;\n\
    \          if (n & 0x0000FFFF) c -= 16;\n          if (n & 0x00FF00FF) c -= 8;\n\
    \          if (n & 0x0F0F0F0F) c -= 4;\n          if (n & 0x33333333) c -= 2;\n\
    \          if (n & 0x55555555) c -= 1;\n          return c;\n        }\n\n   \
    \   public:\n        using difference_type = int;\n        using value_type =\
    \ int;\n        using iterator_concept = std::input_iterator_tag;\n\n        explicit\
    \ iterator(int bit = 0) : i(ctz(bit)), bit(bit) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          bit ^= (1 << i);\n  \
    \        i = ctz(bit);\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const iterator &other) const {\n\
    \          return bit == other.bit;\n        }\n      };\n\n      int bit;\n\n\
    \      explicit bit_index_view(int bit) : bit(bit) {}\n      auto begin() const\
    \ { return iterator(bit); }\n      auto end() const { return iterator(); }\n \
    \   };\n\n    struct bit_subset_view\n        : public std::ranges::view_interface<bit_subset_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n      public:\n\
    \        using difference_type = int;\n        using value_type = int;\n     \
    \   using iterator_concept = std::input_iterator_tag;\n\n        explicit iterator(int\
    \ bit = 0) : i(bit), bit(bit) {}\n        auto operator*() const { return i; }\n\
    \        auto &operator++() {\n          i = (i - 1) & bit;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const iterator &other) const { return i == other.i; }\n   \
    \   };\n\n      int bit;\n\n      explicit bit_subset_view(int bit) : bit(bit)\
    \ {}\n      auto begin() const { return iterator(bit); }\n      auto end() const\
    \ { return iterator(); }\n    };\n\n    struct bit_supset_view\n        : public\
    \ std::ranges::view_interface<bit_supset_view> {\n      class iterator {\n   \
    \     int i;\n        int bit;\n        int n;\n\n      public:\n        using\
    \ difference_type = int;\n        using value_type = int;\n        using iterator_concept\
    \ = std::input_iterator_tag;\n\n        explicit iterator(int bit = 0, int n =\
    \ 0) : i(bit), bit(bit), n(n) {}\n        auto operator*() const { return i; }\n\
    \        auto &operator++() {\n          i = (i + 1) | bit;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const std::default_sentinel_t &sentinel) const {\n        \
    \  return i >= (1 << n);\n        }\n      };\n\n      int bit;\n      int n;\n\
    \n      explicit bit_supset_view(int bit, int n) : bit(bit), n(n) {}\n      auto\
    \ begin() const { return iterator(bit, n); }\n      auto end() const { return\
    \ std::default_sentinel; }\n    };\n\n    struct k_bit_subset_view\n        :\
    \ public std::ranges::view_interface<k_bit_subset_view> {\n      class iterator\
    \ {\n        int i;\n        int n;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int n = 0, int k = 0) : i((1 << k) - 1), n(n) {}\n\
    \        auto operator*() const { return i; }\n        auto &operator++() {\n\
    \          int x = i & -i;\n          int y = i + x;\n          i = (((i & ~y)\
    \ / x) >> 1) | y;\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const std::default_sentinel_t &sentinel)\
    \ const {\n          return i >= (1 << n);\n        }\n      };\n\n      int n,\
    \ k;\n\n      explicit k_bit_subset_view(int n, int k) : n(n), k(k) {}\n     \
    \ auto begin() const { return iterator(n, k); }\n      auto end() const { return\
    \ std::default_sentinel; }\n    };\n  }  // namespace ranges\n\n  namespace views\
    \ {\n    namespace __detail {\n      template <typename... _Args>\n      concept\
    \ __can_bit_index_view = requires {\n        ranges::bit_index_view(std::declval<_Args>()...);\n\
    \      };\n      template <typename... _Args>\n      concept __can_bit_subset_view\
    \ = requires {\n        ranges::bit_subset_view(std::declval<_Args>()...);\n \
    \     };\n      template <typename... _Args>\n      concept __can_bit_supset_view\
    \ = requires {\n        ranges::bit_supset_view(std::declval<_Args>()...);\n \
    \     };\n      template <typename... _Args>\n      concept __can_k_bit_subset_view\
    \ = requires {\n        ranges::k_bit_subset_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _BitIndex {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_bit_index_view<_Tp...>\n    \
    \  constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n        return\
    \ ranges::bit_index_view(std::forward<_Tp>(__e)...);\n      }\n    };\n    inline\
    \ constexpr _BitIndex bit_index{};\n\n    struct _BitSubsetView {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_bit_subset_view<_Tp...>\n   \
    \   constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n        return\
    \ ranges::bit_subset_view(std::forward<_Tp>(__e)...);\n      }\n    };\n    inline\
    \ constexpr _BitSubsetView bit_subset{};\n\n    struct _BitSupsetView {\n    \
    \  template <class... _Tp>\n      requires __detail::__can_bit_supset_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::bit_supset_view(std::forward<_Tp>(__e)...);\n      }\n    };\n\
    \    inline constexpr _BitSupsetView bit_supset{};\n\n    struct _KBitSubsetView\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_k_bit_subset_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::k_bit_subset_view(std::forward<_Tp>(__e)...);\n      }\n   \
    \ };\n    inline constexpr _KBitSubsetView k_bit_subset{};\n  }  // namespace\
    \ views\n\n}  // namespace mystd\n"
  code: "#pragma once\n\n#include <ranges>\n\nnamespace mystd {\n  namespace ranges\
    \ {\n    struct bit_index_view : public std::ranges::view_interface<bit_index_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n        unsigned\
    \ ctz(unsigned int n) {\n          if (!n) return -1;\n          unsigned int\
    \ c = 32;\n          n &= -static_cast<signed int>(n);\n          if (n) c--;\n\
    \          if (n & 0x0000FFFF) c -= 16;\n          if (n & 0x00FF00FF) c -= 8;\n\
    \          if (n & 0x0F0F0F0F) c -= 4;\n          if (n & 0x33333333) c -= 2;\n\
    \          if (n & 0x55555555) c -= 1;\n          return c;\n        }\n\n   \
    \   public:\n        using difference_type = int;\n        using value_type =\
    \ int;\n        using iterator_concept = std::input_iterator_tag;\n\n        explicit\
    \ iterator(int bit = 0) : i(ctz(bit)), bit(bit) {}\n        auto operator*() const\
    \ { return i; }\n        auto &operator++() {\n          bit ^= (1 << i);\n  \
    \        i = ctz(bit);\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const iterator &other) const {\n\
    \          return bit == other.bit;\n        }\n      };\n\n      int bit;\n\n\
    \      explicit bit_index_view(int bit) : bit(bit) {}\n      auto begin() const\
    \ { return iterator(bit); }\n      auto end() const { return iterator(); }\n \
    \   };\n\n    struct bit_subset_view\n        : public std::ranges::view_interface<bit_subset_view>\
    \ {\n      class iterator {\n        int i;\n        int bit;\n\n      public:\n\
    \        using difference_type = int;\n        using value_type = int;\n     \
    \   using iterator_concept = std::input_iterator_tag;\n\n        explicit iterator(int\
    \ bit = 0) : i(bit), bit(bit) {}\n        auto operator*() const { return i; }\n\
    \        auto &operator++() {\n          i = (i - 1) & bit;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const iterator &other) const { return i == other.i; }\n   \
    \   };\n\n      int bit;\n\n      explicit bit_subset_view(int bit) : bit(bit)\
    \ {}\n      auto begin() const { return iterator(bit); }\n      auto end() const\
    \ { return iterator(); }\n    };\n\n    struct bit_supset_view\n        : public\
    \ std::ranges::view_interface<bit_supset_view> {\n      class iterator {\n   \
    \     int i;\n        int bit;\n        int n;\n\n      public:\n        using\
    \ difference_type = int;\n        using value_type = int;\n        using iterator_concept\
    \ = std::input_iterator_tag;\n\n        explicit iterator(int bit = 0, int n =\
    \ 0) : i(bit), bit(bit), n(n) {}\n        auto operator*() const { return i; }\n\
    \        auto &operator++() {\n          i = (i + 1) | bit;\n          return\
    \ *this;\n        }\n        auto operator++(int) { return ++*this; }\n      \
    \  auto operator==(const std::default_sentinel_t &sentinel) const {\n        \
    \  return i >= (1 << n);\n        }\n      };\n\n      int bit;\n      int n;\n\
    \n      explicit bit_supset_view(int bit, int n) : bit(bit), n(n) {}\n      auto\
    \ begin() const { return iterator(bit, n); }\n      auto end() const { return\
    \ std::default_sentinel; }\n    };\n\n    struct k_bit_subset_view\n        :\
    \ public std::ranges::view_interface<k_bit_subset_view> {\n      class iterator\
    \ {\n        int i;\n        int n;\n\n      public:\n        using difference_type\
    \ = int;\n        using value_type = int;\n        using iterator_concept = std::input_iterator_tag;\n\
    \n        explicit iterator(int n = 0, int k = 0) : i((1 << k) - 1), n(n) {}\n\
    \        auto operator*() const { return i; }\n        auto &operator++() {\n\
    \          int x = i & -i;\n          int y = i + x;\n          i = (((i & ~y)\
    \ / x) >> 1) | y;\n          return *this;\n        }\n        auto operator++(int)\
    \ { return ++*this; }\n        auto operator==(const std::default_sentinel_t &sentinel)\
    \ const {\n          return i >= (1 << n);\n        }\n      };\n\n      int n,\
    \ k;\n\n      explicit k_bit_subset_view(int n, int k) : n(n), k(k) {}\n     \
    \ auto begin() const { return iterator(n, k); }\n      auto end() const { return\
    \ std::default_sentinel; }\n    };\n  }  // namespace ranges\n\n  namespace views\
    \ {\n    namespace __detail {\n      template <typename... _Args>\n      concept\
    \ __can_bit_index_view = requires {\n        ranges::bit_index_view(std::declval<_Args>()...);\n\
    \      };\n      template <typename... _Args>\n      concept __can_bit_subset_view\
    \ = requires {\n        ranges::bit_subset_view(std::declval<_Args>()...);\n \
    \     };\n      template <typename... _Args>\n      concept __can_bit_supset_view\
    \ = requires {\n        ranges::bit_supset_view(std::declval<_Args>()...);\n \
    \     };\n      template <typename... _Args>\n      concept __can_k_bit_subset_view\
    \ = requires {\n        ranges::k_bit_subset_view(std::declval<_Args>()...);\n\
    \      };\n    }  // namespace __detail\n\n    struct _BitIndex {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_bit_index_view<_Tp...>\n    \
    \  constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n        return\
    \ ranges::bit_index_view(std::forward<_Tp>(__e)...);\n      }\n    };\n    inline\
    \ constexpr _BitIndex bit_index{};\n\n    struct _BitSubsetView {\n      template\
    \ <class... _Tp>\n      requires __detail::__can_bit_subset_view<_Tp...>\n   \
    \   constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n        return\
    \ ranges::bit_subset_view(std::forward<_Tp>(__e)...);\n      }\n    };\n    inline\
    \ constexpr _BitSubsetView bit_subset{};\n\n    struct _BitSupsetView {\n    \
    \  template <class... _Tp>\n      requires __detail::__can_bit_supset_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::bit_supset_view(std::forward<_Tp>(__e)...);\n      }\n    };\n\
    \    inline constexpr _BitSupsetView bit_supset{};\n\n    struct _KBitSubsetView\
    \ {\n      template <class... _Tp>\n      requires __detail::__can_k_bit_subset_view<_Tp...>\n\
    \      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {\n      \
    \  return ranges::k_bit_subset_view(std::forward<_Tp>(__e)...);\n      }\n   \
    \ };\n    inline constexpr _KBitSubsetView k_bit_subset{};\n  }  // namespace\
    \ views\n\n}  // namespace mystd\n"
  dependsOn: []
  isVerificationFile: false
  path: Library/Range/bit.hpp
  requiredBy: []
  timestamp: '2024-08-10 03:10:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/Range/bit.hpp
layout: document
redirect_from:
- /library/Library/Range/bit.hpp
- /library/Library/Range/bit.hpp.html
title: Library/Range/bit.hpp
---
