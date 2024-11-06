#pragma once

#include <ranges>

#include "./../Math/Bit.hpp"

namespace mtd {
  namespace ranges {
    struct bit_index_view : public std::ranges::view_interface<bit_index_view> {
      class iterator {
        int i;
        int bit;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::forward_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int bit) : i(ctz(bit)), bit(bit) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          bit ^= (1 << i);
          i = ctz(bit);
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator &other) const {
          return bit == other.bit;
        }
      };

      int bit;

      constexpr explicit bit_index_view(int bit) : bit(bit) {}
      constexpr auto begin() const { return iterator(bit); }
      constexpr auto end() const { return iterator(); }
    };

    struct bit_subset_view
        : public std::ranges::view_interface<bit_subset_view> {
      class iterator {
        int i;
        int bit;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::bidirectional_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int bit) : i(bit), bit(bit) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          i = (i - 1) & bit;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator &other) const {
          return i == other.i;
        }
      };

      int bit;

      constexpr explicit bit_subset_view(int bit) : bit(bit) {}
      constexpr auto begin() const { return iterator(bit); }
      constexpr auto end() const { return iterator(); }
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
        using iterator_concept = std::bidirectional_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int bit, int n) : i(bit), bit(bit), n(n) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          i = (i + 1) | bit;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator &other) const {
          return i == other.i && bit == other.bit && n == other.n;
        }
        constexpr auto operator==(
            const std::default_sentinel_t &sentinel) const {
          return i >= (1 << n);
        }
      };

      int bit;
      int n;

      constexpr explicit bit_supset_view(int bit, int n) : bit(bit), n(n) {}
      constexpr auto begin() const { return iterator(bit, n); }
      constexpr auto end() const { return std::default_sentinel; }
    };

    struct k_bit_subset_view
        : public std::ranges::view_interface<k_bit_subset_view> {
      class iterator {
        int i;
        int n;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::bidirectional_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int n, int k) : i((1 << k) - 1), n(n) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          int x = i & -i;
          int y = i + x;
          i = (((i & ~y) / x) >> 1) | y;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator &other) const {
          return i == other.i && n == other.n;
        }
        constexpr auto operator==(
            const std::default_sentinel_t &sentinel) const {
          return i >= (1 << n);
        }
      };

      int n, k;
      constexpr explicit k_bit_subset_view(int n, int k) : n(n), k(k) {}
      constexpr auto begin() const { return iterator(n, k); }
      constexpr auto end() const { return std::default_sentinel; }
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
