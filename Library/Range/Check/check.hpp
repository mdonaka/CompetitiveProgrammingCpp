#pragma once

#include <concepts>
#include <iostream>

#include "./input_range.hpp"
#include "./iterator.hpp"
#include "./view.hpp"

namespace mtd::check {

  template <class T>
  requires requires(T t) { typename T::iterator; }
  auto all() {
    iterator<typename T::iterator>();
    input_range<T>();
    view<T>();
  }

}  // namespace mtd::check
