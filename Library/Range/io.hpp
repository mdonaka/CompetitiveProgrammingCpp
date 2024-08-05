#pragma once

#include <iostream>
#include <ranges>

namespace myranges {

  template <class T>
  auto _input() {
    T x;
    std::cin >> x;
    return std::make_tuple(x);
  }

  template <class T, class... Args>
  auto _tuple_input() {
    if constexpr (sizeof...(Args) == 0) {
      return _input<T>();
    } else {
      auto ret = _input<T>();
      return std::tuple_cat(ret, _tuple_input<Args...>());
    }
  }

  constexpr int _inf = 1e9;

  template <class... Args>
  struct istream_view
      : public std::ranges::view_interface<istream_view<Args...>> {
    class iterator {
      int count;
      std::tuple<Args...> val;

    public:
      using difference_type = int;
      using value_type = std::tuple<Args...>;
      using iterator_concept = std::input_iterator_tag;

      explicit iterator(int count) : count(count) { operator++(); }

      auto operator*() const { return val; }
      auto& operator++() {
        --count;
        if (count >= 0) { val = _tuple_input<Args...>(); }
        return *this;
      }
      auto operator++(int) { return ++*this; }

      auto operator==(std::default_sentinel_t s) {
        return count < 0 || std::cin.eof() || std::cin.fail() || std::cin.bad();
      }
      friend auto operator==(std::default_sentinel_t s, iterator li) {
        return li == s;
      }
    };

    int count;

  public:
    explicit istream_view(int count = _inf) : count(count) {}
    auto begin() { return iterator(count); }
    auto end() { return std::default_sentinel; }
  };

  namespace __detail {
    template <typename... _Args>
    concept __can_istream_view = requires {
      istream_view(std::declval<_Args>()...);
    };
  }  // namespace __detail

  namespace views {
    struct _Istream {
      template <__detail::__can_istream_view _Tp>
      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {
        return istream_view(std::forward<_Tp>(__e));
      }
    };

    inline constexpr _Istream istream{};
  }  // namespace views

}  // namespace myranges
