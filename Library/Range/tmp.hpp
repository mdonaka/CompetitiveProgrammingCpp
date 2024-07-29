#pragma once

#include <iostream>
#include <iterator>

namespace check {

template <std::weakly_incrementable>
void is_weakly_incrementable() {
  std::cout << "weakly_incrementable: True" << std::endl;
}
template <class I>
void is_weakly_incrementable() {
  std::cout << "weakly_incrementable: False" << std::endl;
}

template <std::input_or_output_iterator I>
void is_input_or_output_iterator() {
  std::cout << "input_or_output_iterator: True" << std::endl;
}
template <class I>
void is_input_or_output_iterator() {
  std::cout << "input_or_output_iterator: False" << std::endl;
}

template <std::indirectly_readable>
void is_indirectly_readable() {
  std::cout << "indirectly_readable: True" << std::endl;
}
template <class I>
void is_indirectly_readable() {
  std::cout << "indirectly_readable: False" << std::endl;
}

template <std::input_iterator I>
void is_input_iterator() {
  std::cout << "input_iterator: True" << std::endl;
}
template <class I>
void is_input_iterator() {
  std::cout << "input_iterator: False" << std::endl;
}

template <class T>
auto iterator() {
  std::cout << "-- iterator --" << std::endl;
  is_weakly_incrementable<T>();
  is_input_or_output_iterator<T>();
  is_indirectly_readable<T>();
  is_input_iterator<T>();
}

template <class I, class S>
requires std::equality_comparable_with<I, S>
void is_weakly_equality_comparable_with() {
  std::cout << "weakly_equality_comparable_with: True" << std::endl;
}
template <class I, class S>
void is_weakly_equality_comparable_with() {
  std::cout << "weakly_equality_comparable_with: False" << std::endl;
}

template <class I, std::sentinel_for<I> S>
void is_sentinel_for() {
  std::cout << "sentinel_for: True" << std::endl;
}
template <class I, class S>
void is_sentinel_for() {
  std::cout << "sentinel_for: False" << std::endl;
}

template <std::ranges::range T>
void is_range() {
  std::cout << "range: True" << std::endl;
}
template <class T>
void is_range() {
  std::cout << "range: False" << std::endl;
}
template <std::ranges::input_range T>
void is_input_range() {
  std::cout << "input_range: True" << std::endl;
}
template <class T>
void is_input_range() {
  std::cout << "input_range: False" << std::endl;
}

template <class T>
auto range(T x) {
  std::cout << "-- range --" << std::endl;
  is_weakly_equality_comparable_with<decltype(x.begin()), decltype(x.end())>();
  is_sentinel_for<decltype(x.begin()), decltype(x.end())>();
  is_range<T>();
  is_input_range<T>();
}

}  // namespace check
