#pragma once

#include <functional>

namespace mtd {
  namespace util {
    template <class F, class T>
    constexpr auto tuple_transform(F&& f, T&& t) {
      return std::apply(
          [&]<class... Ts>(Ts&&... elems) {
            return std::tuple<std::invoke_result_t<F&, Ts>...>(
                std::invoke(f, std::forward<Ts>(elems))...);
          },
          std::forward<T>(t));
    }
    template <class F, class T>
    constexpr auto tuple_for_each(F&& f, T&& t) {
      std::apply(
          [&]<class... Ts>(Ts&&... elems) {
            (std::invoke(f, std::forward<Ts>(elems)), ...);
          },
          std::forward<T>(t));
    }
  }  // namespace util
}  // namespace mtd
