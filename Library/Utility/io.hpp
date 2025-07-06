#pragma once

#include <iostream>
#include <ranges>
#include <type_traits>
#include <vector>

#include "Tuple.hpp"

namespace mtd {
  namespace io {

    namespace __details {
      template <typename T>
      concept is_vec = std::same_as<
          T, std::vector<typename T::value_type, typename T::allocator_type>>;
      template <typename T>
      concept is_mat = is_vec<T> && is_vec<typename T::value_type>;

    }  // namespace __details

    template <class T>
    constexpr auto _input() {
      T x;
      std::cin >> x;
      return x;
    }
    template <typename T>
    requires requires { typename std::tuple_size<T>::type; }
    constexpr auto _input() {
      T x;
      util::tuple_for_each([](auto&& i) { std::cin >> i; }, x);
      return x;
    }
    template <__details::is_vec T>
    constexpr auto _input(int n) {
      std::vector<typename T::value_type> v;
      v.reserve(n);
      for (auto i : std::views::iota(0, n)) {
        v.emplace_back(_input<typename T::value_type>());
      }
      return v;
    }
    template <__details::is_mat T>
    constexpr auto _input(int h, int w) {
      T mat;
      mat.reserve(h);
      for (auto i : std::views::iota(0, h)) {
        mat.emplace_back(_input<typename T::value_type>(w));
      }
      return mat;
    }

    template <int N, class Tuple, class T, class... Args, class... Sizes>
    constexpr auto _tuple_input(Tuple& t, Sizes... sizes);
    template <int N, class Tuple, __details::is_vec T, class... Args,
              class Size, class... Sizes>
    constexpr auto _tuple_input(Tuple& t, Size size, Sizes... sizes);
    template <int N, class Tuple, __details::is_mat T, class... Args,
              class Size, class... Sizes>
    constexpr auto _tuple_input(Tuple& t, Size size_h, Size size_w,
                                Sizes... sizes);

    template <int N, class Tuple, class T, class... Args, class... Sizes>
    constexpr auto _tuple_input(Tuple& t, Sizes... sizes) {
      std::get<N>(t) = _input<T>();
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);
      }
    }
    template <int N, class Tuple, __details::is_vec T, class... Args,
              class Size, class... Sizes>
    constexpr auto _tuple_input(Tuple& t, Size size, Sizes... sizes) {
      std::get<N>(t) = _input<T>(size);
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);
      }
    }
    template <int N, class Tuple, __details::is_mat T, class... Args,
              class Size, class... Sizes>
    constexpr auto _tuple_input(Tuple& t, Size size_h, Size size_w,
                                Sizes... sizes) {
      std::get<N>(t) = _input<T>(size_h, size_w);
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);
      }
    }

    template <class... Args, class... Sizes>
    requires(std::convertible_to<Sizes, size_t>&&...) constexpr auto in(
        Sizes... sizes) {
      auto base = std::tuple<Args...>();
      _tuple_input<0, decltype(base), Args...>(base, sizes...);
      return base;
    }

  }  // namespace io

}  // namespace mtd
