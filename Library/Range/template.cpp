#include "./bit.hpp"
#include "./check.hpp"
#include "./istream.hpp"
#include "./set.hpp"
#include "./util.hpp"

namespace mtd {
  namespace ranges {
    struct input_range_template_view
        : public std::ranges::view_interface<input_range_template_view> {
      class iterator {
        int i;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::input_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int _i) : i(_i) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          ++i;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
      };

      int n;

      constexpr explicit input_range_template_view(int _n) : n(_n) {}
      constexpr auto begin() const { return iterator(0); }
      constexpr auto end() const { return iterator(n); }
    };

    struct forward_range_template_view
        : public std::ranges::view_interface<forward_range_template_view> {
      class iterator {
        int i;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::forward_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int _i) : i(_i) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          ++i;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
      };

      int n;

      constexpr explicit forward_range_template_view(int _n) : n(_n) {}
      constexpr auto begin() const { return iterator(0); }
      constexpr auto end() const { return iterator(n); }
    };

    struct bidirectional_range_template_view
        : public std::ranges::view_interface<
              bidirectional_range_template_view> {
      class iterator {
        int i;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::bidirectional_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int _i) : i(_i) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          ++i;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto &operator--() {
          --i;
          return *this;
        }
        constexpr auto operator--(int) { return --*this; }
        constexpr auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
      };

      int n;

      constexpr explicit bidirectional_range_template_view(int _n) : n(_n) {}
      constexpr auto begin() const { return iterator(0); }
      constexpr auto end() const { return iterator(n); }
    };

    struct random_access_range_template_view
        : public std::ranges::view_interface<
              random_access_range_template_view> {
      class iterator {
        int i;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::random_access_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int _i) : i(_i) {}
        constexpr auto operator*() const { return i; }
        constexpr auto &operator++() {
          ++i;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto &operator--() {
          --i;
          return *this;
        }
        constexpr auto operator--(int) { return --*this; }
        constexpr auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
        constexpr auto operator<=>(const iterator &) const = default;
        constexpr auto operator-(const iterator &itr) const {
          return i - itr.i;
        }
        constexpr auto &operator+=(const difference_type n) {
          i += n;
          return *this;
        }
        constexpr auto operator+(const difference_type n) const {
          auto __r = *this;
          __r += n;
          return __r;
        }
        constexpr friend auto operator+(const difference_type n,
                                        const iterator &itr) {
          return itr + n;
        }
        constexpr auto &operator-=(const difference_type n) {
          i -= n;
          return *this;
        }
        constexpr auto operator-(const difference_type n) const {
          auto __r = *this;
          __r -= n;
          return __r;
        }
        constexpr auto operator[](const difference_type n) const {
          return i + n;
        }
      };

      int n;

      constexpr explicit random_access_range_template_view(int _n) : n(_n) {}
      constexpr auto begin() const { return iterator(0); }
      constexpr auto end() const { return iterator(n); }
    };

  }  // namespace ranges
}  // namespace mtd

int main() {
  // template
  // mtd::check::all<mtd::ranges::input_range_template_view>();
  // mtd::check::all<mtd::ranges::forward_range_template_view>();
  // mtd::check::all<mtd::ranges::bidirectional_range_template_view>();
  // mtd::check::all<mtd::ranges::random_access_range_template_view>();

  // bit
  // mtd::check::all<mtd::ranges::bit_index_view>();
  // mtd::check::all<mtd::ranges::bit_subset_view>();
  // mtd::check::all<mtd::ranges::bit_supset_view>();
  // mtd::check::all<mtd::ranges::k_bit_subset_view>();

  // util
  // mtd::check::all<mtd::ranges::zip_view<std::ranges::iota_view<int>>>();
  // mtd::check::all<
  //     mtd::ranges::zip_view<mtd::ranges::bidirectional_range_template_view,
  //                           mtd::ranges::random_access_range_template_view>>();
  // mtd::check::all<mtd::ranges::flatten_view<std::ranges::iota_view<int>>>();
  // mtd::check::all<mtd::ranges::flatten_view<
  //     mtd::ranges::zip_view<mtd::ranges::bidirectional_range_template_view,
  //                           mtd::ranges::random_access_range_template_view>>>();
  // mtd::check::all<
  //     mtd::ranges::cartesian_product_view<std::ranges::iota_view<int>>>();
  // mtd::check::all<mtd::ranges::cartesian_product_view<
  //     mtd::ranges::bidirectional_range_template_view,
  //     mtd::ranges::random_access_range_template_view>>();

  // istream
  // mtd::check::all<mtd::ranges::istream_view<int>>();

  // set
  // mtd::check::all<mtd::ranges::base_k_product_view>();
}
