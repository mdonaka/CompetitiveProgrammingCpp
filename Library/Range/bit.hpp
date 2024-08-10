#pragma once

#include <ranges>

namespace mtd {
  namespace ranges {
    struct bit_index_view : public std::ranges::view_interface<bit_index_view> {
      class iterator {
        int i;
        int bit;

        unsigned ctz(unsigned int n) {
          if (!n) return -1;
          unsigned int c = 32;
          n &= -static_cast<signed int>(n);
          if (n) c--;
          if (n & 0x0000FFFF) c -= 16;
          if (n & 0x00FF00FF) c -= 8;
          if (n & 0x0F0F0F0F) c -= 4;
          if (n & 0x33333333) c -= 2;
          if (n & 0x55555555) c -= 1;
          return c;
        }

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::input_iterator_tag;

        explicit iterator(int bit = 0) : i(ctz(bit)), bit(bit) {}
        auto operator*() const { return i; }
        auto &operator++() {
          bit ^= (1 << i);
          i = ctz(bit);
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto operator==(const iterator &other) const {
          return bit == other.bit;
        }
      };

      int bit;

      explicit bit_index_view(int bit) : bit(bit) {}
      auto begin() const { return iterator(bit); }
      auto end() const { return iterator(); }
    };

    struct bit_subset_view
        : public std::ranges::view_interface<bit_subset_view> {
      class iterator {
        int i;
        int bit;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::input_iterator_tag;

        explicit iterator(int bit = 0) : i(bit), bit(bit) {}
        auto operator*() const { return i; }
        auto &operator++() {
          i = (i - 1) & bit;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto operator==(const iterator &other) const { return i == other.i; }
      };

      int bit;

      explicit bit_subset_view(int bit) : bit(bit) {}
      auto begin() const { return iterator(bit); }
      auto end() const { return iterator(); }
    };

    struct bit_supset_view
        : public std::ranges::view_interface<bit_supset_view> {
      class iterator {
        int i;
        int bit;
        int n;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::input_iterator_tag;

        explicit iterator(int bit = 0, int n = 0) : i(bit), bit(bit), n(n) {}
        auto operator*() const { return i; }
        auto &operator++() {
          i = (i + 1) | bit;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto operator==(const std::default_sentinel_t &sentinel) const {
          return i >= (1 << n);
        }
      };

      int bit;
      int n;

      explicit bit_supset_view(int bit, int n) : bit(bit), n(n) {}
      auto begin() const { return iterator(bit, n); }
      auto end() const { return std::default_sentinel; }
    };

    struct k_bit_subset_view
        : public std::ranges::view_interface<k_bit_subset_view> {
      class iterator {
        int i;
        int n;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::input_iterator_tag;

        explicit iterator(int n = 0, int k = 0) : i((1 << k) - 1), n(n) {}
        auto operator*() const { return i; }
        auto &operator++() {
          int x = i & -i;
          int y = i + x;
          i = (((i & ~y) / x) >> 1) | y;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto operator==(const std::default_sentinel_t &sentinel) const {
          return i >= (1 << n);
        }
      };

      int n, k;

      explicit k_bit_subset_view(int n, int k) : n(n), k(k) {}
      auto begin() const { return iterator(n, k); }
      auto end() const { return std::default_sentinel; }
    };
  }  // namespace ranges

  namespace views {
    namespace __detail {
      template <typename... _Args>
      concept __can_bit_index_view = requires {
        ranges::bit_index_view(std::declval<_Args>()...);
      };
      template <typename... _Args>
      concept __can_bit_subset_view = requires {
        ranges::bit_subset_view(std::declval<_Args>()...);
      };
      template <typename... _Args>
      concept __can_bit_supset_view = requires {
        ranges::bit_supset_view(std::declval<_Args>()...);
      };
      template <typename... _Args>
      concept __can_k_bit_subset_view = requires {
        ranges::k_bit_subset_view(std::declval<_Args>()...);
      };
    }  // namespace __detail

    struct _BitIndex {
      template <class... _Tp>
      requires __detail::__can_bit_index_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {
        return ranges::bit_index_view(std::forward<_Tp>(__e)...);
      }
    };
    inline constexpr _BitIndex bit_index{};

    struct _BitSubsetView {
      template <class... _Tp>
      requires __detail::__can_bit_subset_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {
        return ranges::bit_subset_view(std::forward<_Tp>(__e)...);
      }
    };
    inline constexpr _BitSubsetView bit_subset{};

    struct _BitSupsetView {
      template <class... _Tp>
      requires __detail::__can_bit_supset_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {
        return ranges::bit_supset_view(std::forward<_Tp>(__e)...);
      }
    };
    inline constexpr _BitSupsetView bit_supset{};

    struct _KBitSubsetView {
      template <class... _Tp>
      requires __detail::__can_k_bit_subset_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {
        return ranges::k_bit_subset_view(std::forward<_Tp>(__e)...);
      }
    };
    inline constexpr _KBitSubsetView k_bit_subset{};
  }  // namespace views

}  // namespace mtd
