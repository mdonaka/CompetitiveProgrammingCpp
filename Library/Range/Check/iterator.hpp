#pragma once

#include <concepts>

#include "./table.hpp"

namespace mtd::check {

  template <class I>
  consteval auto _is_weakly_incrementable() {
    return std::weakly_incrementable<I>;
  }

  template <class I>
  consteval auto _is_input_or_output_iterator() {
    return std::input_or_output_iterator<I>;
  }

  template <class I>
  consteval auto _is_indirectly_readable() {
    return std::indirectly_readable<I>;
  }

  template <class I>
  consteval auto _is_input_iterator() {
    return std::input_iterator<I>;
  }

  template <class T>
  auto iterator() {
    auto table = Table("iterator");
    table.add("weakly_incrementable", _is_weakly_incrementable<T>());
    table.add("input_or_output_iterator", _is_input_or_output_iterator<T>());
    table.add("indirectly_readable", _is_indirectly_readable<T>());
    table.add("input_iterator", _is_input_iterator<T>());
    table.print();
  }
}  // namespace mtd::check
