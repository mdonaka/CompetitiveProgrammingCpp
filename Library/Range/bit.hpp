#pragma once

#include <ranges>

namespace myranges {

  struct bit_index_view : public std::ranges::view_interface<bit_index_view> {
    class iterator {
      int i;
      int bit;

      unsigned ctz(unsigned int n) {
#ifdef __GNUC__
        return __builtin_ctz(n);
#endif
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
      auto operator==(const iterator &other) const { return bit == other.bit; }
    };

    int bit;

    explicit bit_index_view(int bit) : bit(bit) {}
    auto begin() const { return iterator(bit); }
    auto end() const { return iterator(); }
  };

  struct bit_subset_view : public std::ranges::view_interface<bit_subset_view> {
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

  struct bit_supset_view : public std::ranges::view_interface<bit_supset_view> {
    class iterator {
      int i;
      int n;
      int bit;

    public:
      using difference_type = int;
      using value_type = int;
      using iterator_concept = std::input_iterator_tag;

      explicit iterator(int n = 0, int bit = 0) : i(bit), n(n), bit(bit) {}
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

    int n;
    int bit;

    explicit bit_supset_view(int n, int bit) : n(n), bit(bit) {}
    auto begin() const { return iterator(n, bit); }
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

}  // namespace myranges
