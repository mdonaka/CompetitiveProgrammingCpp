#include "./bit.hpp"
#include "./check.hpp"
#include "./istream.hpp"
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

        explicit iterator(int i = 0) : i(i) {}
        auto operator*() const { return i; }
        auto &operator++() {
          ++i;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
      };

      int n;

      explicit input_range_template_view(int n) : n(n) {}
      auto begin() const { return iterator(0); }
      auto end() const { return iterator(n); }
    };

    struct forward_range_template_view
        : public std::ranges::view_interface<forward_range_template_view> {
      class iterator {
        int i;

      public:
        using difference_type = int;
        using value_type = int;
        using iterator_concept = std::forward_iterator_tag;

        explicit iterator(int i = 0) : i(i) {}
        auto operator*() const { return i; }
        auto &operator++() {
          ++i;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
      };

      int n;

      explicit forward_range_template_view(int n) : n(n) {}
      auto begin() const { return iterator(0); }
      auto end() const { return iterator(n); }
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

        explicit iterator(int i = 0) : i(i) {}
        auto operator*() const { return i; }
        auto &operator++() {
          ++i;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto &operator--() {
          --i;
          return *this;
        }
        auto operator--(int) { return --*this; }
        auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
      };

      int n;

      explicit bidirectional_range_template_view(int n) : n(n) {}
      auto begin() const { return iterator(0); }
      auto end() const { return iterator(n); }
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

        explicit iterator(int i = 0) : i(i) {}
        auto operator*() const { return i; }
        auto &operator++() {
          ++i;
          return *this;
        }
        auto operator++(int) { return ++*this; }
        auto &operator--() {
          --i;
          return *this;
        }
        auto operator--(int) { return --*this; }
        auto operator==(const iterator &sentinel) const {
          return i == sentinel.i;
        }
        auto operator<=>(const iterator &) const = default;
        auto operator-(const iterator &itr) const { return i - itr.i; }
        auto operator+(const difference_type n) const {
          return iterator(i + n);
        }
        auto &operator+=(const difference_type n) {
          i += n;
          return *this;
        }
        friend auto operator+(const difference_type n, const iterator &itr) {
          return itr + n;
        }
        auto operator-(const difference_type n) const {
          return iterator(i - n);
        }
        auto &operator-=(const difference_type n) {
          i -= n;
          return *this;
        }
        auto operator[](const difference_type n) const { return i + n; }
      };

      int n;

      explicit random_access_range_template_view(int n) : n(n) {}
      auto begin() const { return iterator(0); }
      auto end() const { return iterator(n); }
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
  // mtd::check::all<
  //     mtd::ranges::enumerate_view<mtd::ranges::input_range_template_view>>();
  // mtd::check::all<mtd::ranges::enumerate_view<
  //     mtd::ranges::bidirectional_range_template_view>>();
  // mtd::check::all<mtd::ranges::enumerate_view<
  //     mtd::ranges::random_access_range_template_view>>();
  // mtd::check::all<
  //     mtd::ranges::zip_view<mtd::ranges::input_range_template_view,
  //                           mtd::ranges::input_range_template_view>>();

  // istream
  // mtd::check::all<mtd::ranges::k_bit_subset_view>();
}
