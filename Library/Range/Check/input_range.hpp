#pragma once

#include <concepts>

#include "./table.hpp"

namespace mtd::check {

  template <class I, class S>
  consteval auto _is_equality_comparable_with() {
    return std::equality_comparable_with<I, S>;
  }

  template <class I>
  consteval auto _is_default_initializable() {
    return std::default_initializable<I>;
  }

  template <class I>
  consteval auto _is_copyable() {
    return std::copyable<I>;
  }

  template <class I>
  consteval auto _is_semiregular() {
    return std::semiregular<I>;
  }

  template <class I, class S>
  consteval auto _is_sentinel_for() {
    return std::sentinel_for<S, I>;
  }

  template <class T>
  consteval auto _is_range() {
    return std::ranges::range<T>;
  }

  template <class T>
  consteval auto _is_input_range() {
    return std::ranges::input_range<T>;
  }

  template <class T>
  auto input_range() {
    using begin = decltype(std::declval<T>().begin());
    using end = decltype(std::declval<T>().end());

    auto table = Table("input_range");
    table.add("equality_comparable_with",
              _is_equality_comparable_with<begin, end>());
    table.add("default_initializable", _is_default_initializable<begin>());
    table.add("copyable", _is_copyable<end>());
    table.add("semiregular", _is_semiregular<end>());
    table.add("sentinel_for", _is_sentinel_for<begin, end>());
    table.add("range", _is_range<T>());
    table.add("input_range", _is_input_range<T>());
    table.print();
  }

}  // namespace mtd::check
