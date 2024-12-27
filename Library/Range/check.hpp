#pragma once

#include <algorithm>
#include <concepts>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

namespace mtd::check {
  class Table {
    std::string title;
    std::vector<std::pair<std::string, bool>> table;

  public:
    Table(const std::string& _title) : title(_title) {}

    auto add(const std::string& name, bool b) { table.emplace_back(name, b); }
    auto print() const {
      auto size = std::ranges::max(
          table |
          std::views::transform([](const std::pair<std::string, bool>& p) {
            return p.first.size();
          }));

      // std::cout << std::string(size + 12, '_') << std::endl;
      std::cout << "|" << std::string(size + 10, '-') << "|" << std::endl;
      std::cout << "| " << title << std::string(size + 9 - title.size(), ' ')
                << "|" << std::endl;
      std::cout << "|" << std::string(size + 10, '-') << "|" << std::endl;
      for (const auto& [s, b] : table) {
        std::cout << "| " << std::left << std::setw(static_cast<int>(size)) << s
                  << " | " << (b ? "True " : "False") << " |" << std::endl;
      }
      std::cout << "|" << std::string(size + 10, '_') << "|" << std::endl;
    }
  };

  template <class T>
  auto range() {
    using iterator = decltype(std::declval<T>().begin());
    using sentinel = decltype(std::declval<T>().end());

    auto table = Table("range");
    table.add("weakly-equality-comparable-with",
              std::__detail::__weakly_eq_cmp_with<iterator, sentinel>);

    table.add("default_initializable", std::default_initializable<iterator>);
    table.add("copyable", std::copyable<sentinel>);
    table.add("semiregular", std::semiregular<sentinel>);
    table.add("sentinel_for", std::sentinel_for<sentinel, iterator>);
    table.add("range", std::ranges::range<T>);
    table.print();
  }

  template <class T>
  auto input_range() {
    using iterator = decltype(std::declval<T>().begin());

    auto table = Table("input_range");
    table.add("weakly_incrementable", std::weakly_incrementable<iterator>);
    table.add("input_or_output_iterator",
              std::input_or_output_iterator<iterator>);
    table.add("indirectly_readable", std::indirectly_readable<iterator>);
    table.add("input_iterator", std::input_iterator<iterator>);
    table.add("input_range", std::ranges::input_range<T>);
    table.print();
  }

  template <class T>
  auto forward_range() {
    using iterator = decltype(std::declval<T>().begin());

    auto table = Table("forward_range");
    table.add("incrementable", std::incrementable<iterator>);
    table.add("sentinel_for", std::sentinel_for<iterator, iterator>);
    table.add("forward_range", std::ranges::forward_range<T>);
    table.print();
  }

  template <class T>
  auto bidirectional_range() {
    using iterator = decltype(std::declval<T>().begin());

    auto table = Table("bidirectional_range");
    table.add(
        "decrementable", requires(iterator t) {
          { --t } -> std::same_as<iterator&>;
          { t-- } -> std::same_as<iterator>;
        });
    table.add("bidirectional_range", std::ranges::bidirectional_range<T>);
    table.print();
  }

  template <class T>
  auto random_access_range() {
    using iterator = decltype(std::declval<T>().begin());

    auto table = Table("random_access_range");
    table.add("totally_ordered", std::totally_ordered<iterator>);
    table.add("sized_sentinel_for",
              std::sized_sentinel_for<iterator, iterator>);

    table.add(
        "plus", requires(iterator i, const iterator j,
                         const std::iter_difference_t<iterator> n) {
          { i += n } -> std::same_as<iterator&>;
          { j + n } -> std::same_as<iterator>;
          { n + j } -> std::same_as<iterator>;
        });
    table.add(
        "minus", requires(iterator i, const iterator j,
                          const std::iter_difference_t<iterator> n) {
          { i -= n } -> std::same_as<iterator&>;
          { j - n } -> std::same_as<iterator>;
        });
    table.add(
        "access",
        requires(const iterator j, const std::iter_difference_t<iterator> n) {
          { j[n] } -> std::same_as<std::iter_reference_t<iterator>>;
        });
    table.add("random_access_range", std::ranges::random_access_range<T>);
    table.print();
  }

  template <class T>
  auto view() {
    auto table = Table("view");
    table.add("object_v", std::is_object_v<T>);
    table.add("move_constructible", std::move_constructible<T>);
    table.add("assignable_from", std::assignable_from<T&, T>);
    table.add("swappable", std::swappable<T>);
    table.add("movable", std::movable<T>);
    // table.add("derived_from", std::derived_from<T, std::ranges::view_base>);
    table.add("enable_view", std::ranges::enable_view<T>);
    table.add("view", std::ranges::view<T>);
    table.add("viewable_range", std::ranges::viewable_range<T>);
    table.print();
  }

  template <class T>
  auto all() {
    range<T>();
    input_range<T>();
    forward_range<T>();
    bidirectional_range<T>();
    random_access_range<T>();
    view<T>();
  }

}  // namespace mtd::check
