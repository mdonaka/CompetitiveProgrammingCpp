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
    Table(const std::string& title) : title(title) {}

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
        std::cout << "| " << std::left << std::setw(size) << s << " | "
                  << (b ? "True " : "False") << " |" << std::endl;
      }
      std::cout << "|" << std::string(size + 10, '_') << "|" << std::endl;
    }
  };

  template <class T>
  auto iterator() {
    auto table = Table("iterator");
    table.add("weakly_incrementable", std::weakly_incrementable<T>);
    table.add("input_or_output_iterator", std::input_or_output_iterator<T>);
    table.add("indirectly_readable", std::indirectly_readable<T>);
    table.add("input_iterator", std::input_iterator<T>);
    table.print();
  }

  template <class T>
  auto input_range() {
    using begin = decltype(std::declval<T>().begin());
    using end = decltype(std::declval<T>().end());

    auto table = Table("input_range");
    table.add("weakly-equality-comparable-with",
              std::__detail::__weakly_eq_cmp_with<begin, end>);

    table.add("default_initializable", std::default_initializable<begin>);
    table.add("copyable", std::copyable<end>);
    table.add("semiregular", std::semiregular<end>);
    table.add("sentinel_for", std::sentinel_for<end, begin>);
    table.add("range", std::ranges::range<T>);
    table.add("input_range", std::ranges::input_range<T>);
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
    table.print();
  }

  template <class T>
  auto viewable_range() {
    auto table = Table("viewable_range");
    table.add("viewable_range", std::ranges::viewable_range<T>);
    table.print();
  }

  template <class T>
  requires requires(T t) { typename T::iterator; }
  auto all() {
    iterator<typename T::iterator>();
    input_range<T>();
    view<T>();
    viewable_range<T>();
  }

}  // namespace mtd::check
