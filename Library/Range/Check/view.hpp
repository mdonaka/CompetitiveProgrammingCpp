#pragma once

#include <concepts>
#include <ranges>

#include "./table.hpp"

namespace mtd::check {

  template <class T>
  consteval auto _is_view() {
    return std::ranges::view<T>;
  }

  template <class T>
  consteval auto _is_object_v() {
    return std::is_object_v<T>;
  }

  template <class T>
  consteval auto _is_move_constructible() {
    return std::move_constructible<T>;
  }

  template <class T>
  consteval auto _is_assignable_from() {
    return std::assignable_from<T&, T>;
  }

  template <class T>
  consteval auto _is_swappable() {
    return std::swappable<T>;
  }

  template <class T>
  consteval auto _is_movable() {
    return std::movable<T>;
  }

  template <typename T, typename U>
  consteval auto _is_derived_from() {
    return std::derived_from<T, U>;
  }

  template <class T>
  consteval auto _is_enable_view() {
    return std::ranges::enable_view<T>;
  }

  template <class T>
  auto view() {
    auto table = Table("view");
    table.add("object_v", _is_object_v<T>());
    table.add("move_constructible", _is_move_constructible<T>());
    table.add("assignable_from", _is_assignable_from<T>());
    table.add("swappable", _is_swappable<T>());
    table.add("movable", _is_movable<T>());
    table.add("derived_from", _is_derived_from<T, std::ranges::view_base>());
    table.add("enable_view", _is_enable_view<T>());
    table.add("view", _is_view<T>());
    table.print();
  }
}  // namespace mtd::check
