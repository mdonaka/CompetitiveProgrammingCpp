#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>

namespace mtd {
  namespace ranges {

    namespace __detail {
      template <class F, class T>
      constexpr auto __tuple_transform(F&& f, T&& t) {
        return std::apply(
            [&]<class... Ts>(Ts&&... elems) {
              return std::tuple<std::invoke_result_t<F&, Ts>...>(
                  std::invoke(f, std::forward<Ts>(elems))...);
            },
            std::forward<T>(t));
      }
      template <class F, class T>
      constexpr auto __tuple_for_each(F&& f, T&& t) {
        std::apply(
            [&]<class... Ts>(Ts&&... elems) {
              (std::invoke(f, std::forward<Ts>(elems)), ...);
            },
            std::forward<T>(t));
      }
      template <typename... T>
      concept __all_random_access = (std::ranges::random_access_range<T> &&
                                     ...);
      template <typename... T>
      concept __all_bidirectional = (std::ranges::bidirectional_range<T> &&
                                     ...);
      template <typename... T>
      concept __all_forward = (std::ranges::forward_range<T> && ...);

      template <class... T>
      constexpr auto _S_iter_concept() {
        if constexpr (__all_random_access<T...>) {
          return std::random_access_iterator_tag{};
        } else if constexpr (__all_bidirectional<T...>) {
          return std::bidirectional_iterator_tag{};
        } else if constexpr (__all_forward<T...>) {
          return std::forward_iterator_tag{};
        } else {
          return std::input_iterator_tag{};
        }
      }
    }  // namespace __detail

    template <std::ranges::range... _Range>
    struct zip_view : public std::ranges::view_interface<zip_view<_Range...>> {
      class iterator {
      public:
        std::tuple<std::ranges::iterator_t<_Range>...> _M_current;

        using difference_type = int;
        using value_type = std::tuple<
            std::iter_reference_t<std::ranges::iterator_t<_Range>>...>;
        using iterator_concept =
            decltype(__detail::_S_iter_concept<_Range...>());

        constexpr iterator() = default;
        constexpr explicit iterator(const decltype(_M_current)& __current)
            : _M_current(__current) {}
        constexpr auto operator*() const {
          return __detail::__tuple_transform([](auto& __i) { return *__i; },
                                             _M_current);
        }
        constexpr auto& operator++() {
          __detail::__tuple_for_each([](auto& __i) { ++__i; }, _M_current);
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator& other) const {
          return [&]<size_t... _Is>(std::index_sequence<_Is...>) {
            return ((std::get<_Is>(_M_current) ==
                     std::get<_Is>(other._M_current)) ||
                    ...);
          }
          (std::make_index_sequence<sizeof...(_Range)>{});
        }
        constexpr auto& operator--() requires
            __detail::__all_bidirectional<_Range...> {
          __detail::__tuple_for_each([](auto& __i) { --__i; }, _M_current);
          return *this;
        }
        constexpr auto operator--(
            int) requires __detail::__all_bidirectional<_Range...> {
          return --*this;
        }
        constexpr auto operator<=>(const iterator&)
            const requires __detail::__all_random_access<_Range...>
        = default;
        constexpr auto operator-(const iterator& itr)
            const requires __detail::__all_random_access<_Range...> {
          return [&]<size_t... _Is>(std::index_sequence<_Is...>) {
            return std::ranges::min({difference_type(
                std::get<_Is>(_M_current) - std::get<_Is>(itr._M_current))...});
          }
          (std::make_index_sequence<sizeof...(_Range)>{});
        }
        constexpr auto& operator+=(const difference_type n) requires
            __detail::__all_random_access<_Range...> {
          __detail::__tuple_for_each([&n](auto& __i) { __i += n; }, _M_current);
          return *this;
        }
        constexpr auto operator+(const difference_type n)
            const requires __detail::__all_random_access<_Range...> {
          auto __r = *this;
          __r += n;
          return __r;
        }
        constexpr friend auto operator+(const difference_type n,
                                        const iterator& itr) requires
            __detail::__all_random_access<_Range...> {
          return itr + n;
        }
        constexpr auto& operator-=(const difference_type n) requires
            __detail::__all_random_access<_Range...> {
          __detail::__tuple_for_each([&n](auto& __i) { __i -= n; }, _M_current);
          return *this;
        }
        constexpr auto operator-(const difference_type n)
            const requires __detail::__all_random_access<_Range...> {
          auto __r = *this;
          __r -= n;
          return __r;
        }
        constexpr auto operator[](const difference_type n)
            const requires __detail::__all_random_access<_Range...> {
          return __detail::__tuple_transform([&n](auto& __i) { return __i[n]; },
                                             _M_current);
        }
      };

      class sentinel {
      public:
        std::tuple<std::ranges::sentinel_t<_Range>...> _M_end;

        constexpr sentinel() = default;
        constexpr explicit sentinel(const decltype(_M_end)& __end)
            : _M_end(__end) {}

        friend constexpr bool operator==(const iterator& __x,
                                         const sentinel& __y) {
          return [&]<size_t... _Is>(std::index_sequence<_Is...>) {
            return (
                (std::get<_Is>(__x._M_current) == std::get<_Is>(__y._M_end)) ||
                ...);
          }
          (std::make_index_sequence<sizeof...(_Range)>{});
        }
      };

      std::tuple<_Range...> __r;
      constexpr explicit zip_view(const _Range&... __r) : __r(__r...) {}
      constexpr auto begin() {
        return iterator(__detail::__tuple_transform(std::ranges::begin, __r));
      }
      constexpr auto end() {
        return sentinel(__detail::__tuple_transform(std::ranges::end, __r));
      }
    };

    namespace __detail {
      template <typename T>
      auto _flatten(const T& t) {
        return std::make_tuple(t);
      }
      template <typename... T>
      auto _flatten(const std::tuple<T...>& t);

      template <typename Head, typename... Tail>
      auto _flatten_impl(const Head& head, const Tail&... tail) {
        return std::tuple_cat(_flatten(head), _flatten(tail)...);
      }
      template <typename... T>
      auto _flatten(const std::tuple<T...>& t) {
        return std::apply(
            [](const auto&... args) { return _flatten_impl(args...); }, t);
      }
    }  // namespace __detail

    template <std::ranges::range _Range>
    struct flatten_view
        : public std::ranges::view_interface<flatten_view<_Range>> {
      class iterator {
      public:
        std::ranges::iterator_t<_Range> _M_current;

        using difference_type = std::ranges::range_difference_t<_Range>;
        using value_type = decltype(__detail::_flatten(
            std::declval<
                std::iter_reference_t<std::ranges::iterator_t<_Range>>>()));
        using iterator_concept = decltype(__detail::_S_iter_concept<_Range>());

        constexpr iterator() = default;
        constexpr explicit iterator(decltype(_M_current) __current)
            : _M_current(__current) {}
        constexpr auto operator*() const {
          return __detail::_flatten(*_M_current);
        }
        constexpr auto& operator++() {
          ++_M_current;
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto operator==(const iterator& other) const {
          return _M_current == other._M_current;
        }
        constexpr auto& operator--() requires
            __detail::__all_bidirectional<_Range> {
          --_M_current;
          return *this;
        }
        constexpr auto operator--(
            int) requires __detail::__all_bidirectional<_Range> {
          return --*this;
        }
        constexpr auto operator<=>(const iterator&)
            const requires __detail::__all_random_access<_Range>
        = default;
        constexpr auto operator-(const iterator& itr)
            const requires __detail::__all_random_access<_Range> {
          return _M_current - itr._M_current;
        }
        constexpr auto& operator+=(const difference_type n) requires
            __detail::__all_random_access<_Range> {
          _M_current += n;
          return *this;
        }
        constexpr auto operator+(const difference_type n)
            const requires __detail::__all_random_access<_Range> {
          auto __r = *this;
          __r += n;
          return __r;
        }
        constexpr friend auto operator+(const difference_type n,
                                        const iterator& itr) requires
            __detail::__all_random_access<_Range> {
          return itr + n;
        }
        constexpr auto& operator-=(const difference_type n) requires
            __detail::__all_random_access<_Range> {
          _M_current -= n;
          return *this;
        }
        constexpr auto operator-(const difference_type n)
            const requires __detail::__all_random_access<_Range> {
          auto __r = *this;
          __r -= n;
          return __r;
        }
        constexpr auto operator[](const difference_type n)
            const requires __detail::__all_random_access<_Range> {
          return __detail::_flatten(_M_current[n]);
        }
      };

      class sentinel {
        std::ranges::sentinel_t<_Range> _M_end;

      public:
        constexpr sentinel() = default;
        constexpr explicit sentinel(const decltype(_M_end)& __end)
            : _M_end(__end) {}

        friend constexpr bool operator==(const iterator& __x,
                                         const sentinel& __y) {
          return __x._M_current == __y._M_end;
        }
      };

      _Range __r;
      constexpr explicit flatten_view(const _Range& __r) : __r(__r) {}
      constexpr auto begin() { return iterator(std::ranges::begin(__r)); }
      constexpr auto end() { return sentinel(std::ranges::end(__r)); }
    };

  }  // namespace ranges

  namespace views {
    namespace __detail {
      template <typename... _Args>
      concept __can_zip_view = requires {
        ranges::zip_view(std::declval<_Args>()...);
      };
      template <typename... _Args>
      concept __can_flatten_view = requires {
        ranges::flatten_view(std::declval<_Args>()...);
      };
    }  // namespace __detail

    struct _ZipView {
      template <class... _Tp>
      requires __detail::__can_zip_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {
        return ranges::zip_view(std::forward<_Tp>(__e)...);
      }
    };
    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {
      template <class _Tp>
      requires __detail::__can_zip_view<std::ranges::iota_view<size_t>, _Tp>
      constexpr auto operator() [[nodiscard]] (_Tp&& __e) const {
        return ranges::zip_view{std::views::iota(0), std::forward<_Tp>(__e)};
      }
      static constexpr bool _S_has_simple_call_op = true;
    };
    struct _Flatten : std::views::__adaptor::_RangeAdaptorClosure {
      template <class... _Tp>
      requires __detail::__can_flatten_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {
        return ranges::flatten_view(std::forward<_Tp>(__e)...);
      }
      static constexpr bool _S_has_simple_call_op = true;
    };

    inline constexpr _ZipView zip{};
    inline constexpr _Enumerate enumerate{};
    inline constexpr _Flatten flatten{};

  }  // namespace views
}  // namespace mtd
