#pragma once

#include <iostream>
#include <iterator>

namespace myranges::check {

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
auto range(T x) {
  std::cout << "-- range --" << std::endl;
  _is_equality_comparable_with<decltype(x.begin()), decltype(x.end())>();
  _is_default_initializable<decltype(x.end())>();
  _is_copyable<decltype(x.end())>();
  _is_semiregular<decltype(x.end())>();
  _is_sentinel_for<decltype(x.begin()), decltype(x.end())>();
  _is_range<T>();
  _is_input_range<T>();
}

template <class T, class... Args>
auto all(const Args... args) {
  iterator<typename T::iterator>();
  range(T(args...));
}

}  // namespace myranges::check
