#pragma once

#include <iostream>
#include <ranges>
#include <type_traits>
#include <vector>

namespace mtd {
  namespace io {

    namespace type {
      template <class T>
      struct vec {
        using value_type = T;
      };
      template <class T>
      concept is_vec = requires {
        requires std::is_same_v<T, vec<typename T::value_type>>;
      };

      template <class T>
      struct mat {
        using value_type = T;
      };
      template <class T>
      concept is_mat = requires {
        requires std::is_same_v<T, mat<typename T::value_type>>;
      };
    }  // namespace type

    template <class T>
    auto _input() {
      T x;
      std::cin >> x;
      return x;
    }
    template <type::is_vec T>
    auto _input(int n) {
      std::vector<typename T::value_type> v(n);
      for (auto i : std::views::iota(0, n)) { std::cin >> v[i]; }
      return v;
    }
    template <type::is_mat T>
    auto _input(int h, int w) {
      std::vector<std::vector<typename T::value_type>> mat;
      for (auto i : std::views::iota(0, h)) {
        mat.emplace_back(_input<type::vec<typename T::value_type>>(w));
      }
      return mat;
    }

    template <int N, class Tuple, class T, class... Args, class... Sizes>
    auto _tuple_input(Tuple& t, Sizes... sizes);
    template <int N, class Tuple, type::is_vec T, class... Args, class Size,
              class... Sizes>
    auto _tuple_input(Tuple& t, Size size, Sizes... sizes);
    template <int N, class Tuple, type::is_mat T, class... Args, class Size,
              class... Sizes>
    auto _tuple_input(Tuple& t, Size size_h, Size size_w, Sizes... sizes);

    template <int N, class Tuple, class T, class... Args, class... Sizes>
    auto _tuple_input(Tuple& t, Sizes... sizes) {
      std::get<N>(t) = _input<T>();
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);
      }
    }
    template <int N, class Tuple, type::is_vec T, class... Args, class Size,
              class... Sizes>
    auto _tuple_input(Tuple& t, Size size, Sizes... sizes) {
      std::get<N>(t) = _input<T>(size);
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);
      }
    }
    template <int N, class Tuple, type::is_mat T, class... Args, class Size,
              class... Sizes>
    auto _tuple_input(Tuple& t, Size size_h, Size size_w, Sizes... sizes) {
      std::get<N>(t) = _input<T>(size_h, size_w);
      if constexpr (sizeof...(Args) > 0) {
        _tuple_input<N + 1, Tuple, Args...>(t, sizes...);
      }
    }

    template <class T>
    struct _Converter {
      using type = T;
    };
    template <class T>
    struct _Converter<type::vec<T>> {
      using type = std::vector<T>;
    };
    template <class T>
    struct _Converter<type::mat<T>> {
      using type = std::vector<std::vector<T>>;
    };

    template <class... Args, class... Sizes>
    requires(std::convertible_to<Sizes, size_t>&&...) auto in(Sizes... sizes) {
      auto base = std::tuple<typename _Converter<Args>::type...>();
      _tuple_input<0, decltype(base), Args...>(base, sizes...);
      return base;
    }

  }  // namespace io

}  // namespace mtd
