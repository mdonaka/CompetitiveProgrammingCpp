#pragma once

#include <algorithm>
#include <iostream>
#include <ranges>

#include "../Utility/Tuple.hpp"

namespace mtd {
  namespace ranges {

    namespace __detail {
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
          auto __tmp = *this;
          __tmp += n;
          return __tmp;
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
          auto __tmp = *this;
          __tmp -= n;
          return __tmp;
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

      _Range _M_views;
      constexpr explicit flatten_view(const _Range& __views)
          : _M_views(__views) {}
      constexpr auto begin() { return iterator(std::ranges::begin(_M_views)); }
      constexpr auto end() { return sentinel(std::ranges::end(_M_views)); }
    };

  }  // namespace ranges

  namespace views {
    namespace __detail {
      template <typename... _Args>
      concept __can_flatten_view = requires {
        ranges::flatten_view(std::declval<_Args>()...);
      };
    }  // namespace __detail

    struct _Flatten : std::ranges::range_adaptor_closure<_Flatten> {
      template <class... _Tp>
      requires __detail::__can_flatten_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {
        return ranges::flatten_view(std::forward<_Tp>(__e)...);
      }
      static constexpr bool _S_has_simple_call_op = true;
    };
    struct _ProductN {
      template <class... _Tp>
      constexpr auto operator() [[nodiscard]] (_Tp... __e) const {
        return std::views::cartesian_product(std::views::iota(0, __e)...);
      }
    };

    inline constexpr _Flatten flatten{};
    inline constexpr _ProductN product_n{};
  }  // namespace views
}  // namespace mtd
