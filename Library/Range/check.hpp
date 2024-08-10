#pragma once

#include <concepts>
#include <iostream>
#include <iterator>

namespace mtd::check {

  // =======================================================
  //
  template <std::weakly_incrementable>
  void _is_weakly_incrementable() {
    std::cout << "weakly_incrementable: True" << std::endl;
  }
  template <class I>
  void _is_weakly_incrementable() {
    std::cout << "weakly_incrementable: False" << std::endl;
  }

  template <std::input_or_output_iterator I>
  void _is_input_or_output_iterator() {
    std::cout << "input_or_output_iterator: True" << std::endl;
  }
  template <class I>
  void _is_input_or_output_iterator() {
    std::cout << "input_or_output_iterator: False" << std::endl;
  }

  template <std::indirectly_readable>
  void _is_indirectly_readable() {
    std::cout << "indirectly_readable: True" << std::endl;
  }
  template <class I>
  void _is_indirectly_readable() {
    std::cout << "indirectly_readable: False" << std::endl;
  }

  template <std::input_iterator I>
  void _is_input_iterator() {
    std::cout << "input_iterator: True" << std::endl;
  }
  template <class I>
  void _is_input_iterator() {
    std::cout << "input_iterator: False" << std::endl;
  }

  template <class T>
  auto iterator() {
    std::cout << "-- iterator --" << std::endl;
    _is_weakly_incrementable<T>();
    _is_input_or_output_iterator<T>();
    _is_indirectly_readable<T>();
    _is_input_iterator<T>();
  }

  // =======================================================

  template <class I, class S>
  requires std::equality_comparable_with<I, S>
  void _is_equality_comparable_with() {
    std::cout << "equality_comparable_with: True" << std::endl;
  }
  template <class I, class S>
  void _is_equality_comparable_with() {
    std::cout << "equality_comparable_with: False" << std::endl;
  }

  template <std::default_initializable i>
  void _is_default_initializable() {
    std::cout << "default_initializable: True" << std::endl;
  }
  template <class i>
  void _is_default_initializable() {
    std::cout << "default_initializable: False" << std::endl;
  }

  template <std::copyable I>
  void _is_copyable() {
    std::cout << "copyable: True" << std::endl;
  }
  template <class I>
  void _is_copyable() {
    std::cout << "copyable: False" << std::endl;
  }

  template <std::semiregular i>
  void _is_semiregular() {
    std::cout << "semiregular: True" << std::endl;
  }
  template <class i>
  void _is_semiregular() {
    std::cout << "semiregular: False" << std::endl;
  }

  template <class I, std::sentinel_for<I> S>
  void _is_sentinel_for() {
    std::cout << "sentinel_for: True" << std::endl;
  }
  template <class I, class S>
  void _is_sentinel_for() {
    std::cout << "sentinel_for: False" << std::endl;
  }

  template <std::ranges::range T>
  void _is_range() {
    std::cout << "range: True" << std::endl;
  }
  template <class T>
  void _is_range() {
    std::cout << "range: False" << std::endl;
  }
  template <std::ranges::input_range T>
  void _is_input_range() {
    std::cout << "input_range: True" << std::endl;
  }
  template <class T>
  void _is_input_range() {
    std::cout << "input_range: False" << std::endl;
  }

  template <class T>
  auto input_range() {
    std::cout << "-- input range --" << std::endl;
    auto x = T();
    _is_equality_comparable_with<decltype(x.begin()), decltype(x.end())>();
    _is_default_initializable<decltype(x.end())>();
    _is_copyable<decltype(x.end())>();
    _is_semiregular<decltype(x.end())>();
    _is_sentinel_for<decltype(x.begin()), decltype(x.end())>();
    _is_range<T>();
    _is_input_range<T>();
  }

  // =======================================================

  template <std::ranges::view T>
  void _is_view() {
    std::cout << "view: True" << std::endl;
  }
  template <class T>
  void _is_view() {
    std::cout << "view: False" << std::endl;
  }

  template <class T>
  void _is_object_v() {
    std::cout << "is_object_v: " << (std::is_object_v<T> ? "True" : "False")
              << std::endl;
  }

  template <std::move_constructible T>
  void _is_move_constructible() {
    std::cout << "move_constructible: True" << std::endl;
  }
  template <class T>
  void _is_move_constructible() {
    std::cout << "move_constructible: False" << std::endl;
  }

  template <class T>
  requires std::assignable_from<T&, T>
  void _is_assignable_from() {
    std::cout << "assignable_from: True" << std::endl;
  }
  template <class T>
  void _is_assignable_from() {
    std::cout << "assignable_from: False" << std::endl;
  }

  template <std::swappable T>
  void _is_swappable() {
    std::cout << "swappable: True" << std::endl;
  }
  template <class T>
  void _is_swappable() {
    std::cout << "swappable: False" << std::endl;
  }

  template <std::movable T>
  void _is_movable() {
    std::cout << "movable: True" << std::endl;
  }
  template <class T>
  void _is_movable() {
    std::cout << "movable: False" << std::endl;
  }

  template <typename T, typename U>
  requires std::derived_from<T, U>
  void _is_derived_from() { std::cout << "derived_from: True" << std::endl; }
  template <typename T, typename U>
  void _is_derived_from() {
    std::cout << "derived_from: False" << std::endl;
  }

  template <class T>
  void _is_enable_view() {
    std::cout << "enable_view: "
              << (std::ranges::enable_view<T> ? "True" : "False") << std::endl;
  }

  template <class T>
  auto view() {
    std::cout << "-- view --" << std::endl;
    _is_object_v<T>();
    _is_move_constructible<T>();
    _is_assignable_from<T>();
    _is_swappable<T>();
    _is_movable<T>();
    // _is_derived_from<T, std::ranges::view_base>();
    _is_enable_view<T>();
    _is_view<T>();
  }

  // =======================================================

  template <class T>
  auto all() {
    iterator<typename T::iterator>();
    input_range<T>();
    view<T>();
  }

}  // namespace mtd::check
