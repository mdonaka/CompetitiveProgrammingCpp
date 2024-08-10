#pragma once

#include <iostream>
#include <ranges>
#include <type_traits>
#include <vector>

namespace mtd {
  namespace io {

    namespace type {
      template <class T, int Pre = 1, int Size = 0>
      struct vec {
        using value_type = T;
        static constexpr int pre = Pre;
        static constexpr int size = Size;
      };
      template <class T>
      concept is_vec = requires {
        std::is_same_v<T, vec<typename T::value_type, T::pre, T::size>>;
      };
    }  // namespace type

    template <type::is_vec T>
    auto _input(int n) {
      std::vector<typename T::value_type> v(n);
      for (auto i : std::views::iota(0, n)) { std::cin >> v[i]; }
      return v;
    }

    template <class T>
    auto _input() {
      T x;
      std::cin >> x;
      return x;
    }

    template <int N, class Tuple, class T, class... Args>
    auto _tuple_input(Tuple& t) {
      if constexpr (type::is_vec<T>) {
        if constexpr (T::size == 0) {
          std::get<N>(t) = _input<T>(std::get<N - T::pre>(t));
        } else {
          std::get<N>(t) = _input<T>(T::size);
        }
      } else {
        std::get<N>(t) = _input<T>();
      }
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t);
      }
    }

    template <class T>
    struct _Converter {
      using type = int;
    };
    template <class T, int Pre, int Size>
    struct _Converter<type::vec<T, Pre, Size>> {
      using type = std::vector<T>;
    };

    template <class... Args>
    auto in() {
      auto base = std::tuple<typename _Converter<Args>::type...>();
      _tuple_input<0, decltype(base), Args...>(base);
      return base;
    }

  }  // namespace io

  template <class T, int Pre = 1, int Size = 0>
  using tvec = io::type::vec<T, Pre, Size>;
  using io::in;

}  // namespace mtd
