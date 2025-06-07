#pragma once

#include <ranges>
#include <vector>

namespace mtd {
  namespace ranges {

    struct base_k_product_view
        : public std::ranges::view_interface<base_k_product_view> {
      class iterator {
        int n, k;
        std::vector<int> _M_current;

      public:
        using difference_type = int;
        using value_type = std::vector<int>;
        using iterator_concept = std::bidirectional_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int _n, int _k)
            : n(_n), k(_k), _M_current(_n) {}
        constexpr auto operator*() const { return _M_current; }
        constexpr auto &operator++() {
          ++_M_current[0];
          for (auto i : std::views::iota(0, n - 1)) {
            if (_M_current[i] >= k) {
              _M_current[i] = 0;
              ++_M_current[i + 1];
            }
          }
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }
        constexpr auto &operator--() {
          if (_M_current.back() == k) {
            _M_current = std::vector<int>(n, k - 1);
          } else {
            --_M_current.back();
            for (auto i : std::views::iota(1, n) | std::views::reverse) {
              if (_M_current[i] < 0) {
                _M_current[i] = k - 1;
                --_M_current[i - 1];
              }
            }
          }
          return *this;
        }
        constexpr auto operator--(int) { return --*this; }
        constexpr auto operator==(const iterator &s) const {
          return _M_current == s._M_current;
        }
        constexpr auto operator==(std::default_sentinel_t) const {
          return _M_current.back() == k;
        }
        constexpr friend auto operator==(std::default_sentinel_t s,
                                         const iterator &li) {
          return li == s;
        }
      };

      int n, k;

      constexpr explicit base_k_product_view(int _n, int _k) : n(_n), k(_k) {}
      constexpr auto begin() const { return iterator(n, k); }
      constexpr auto end() const { return std::default_sentinel; }
    };
  }  // namespace ranges

  namespace views {
    namespace __detail {
      template <typename... _Args>
      concept __can_base_k_product_view = requires {
        ranges::base_k_product_view(std::declval<_Args>()...);
      };
    }  // namespace __detail

    struct _BaseKProduct {
      template <class... _Tp>
      requires __detail::__can_base_k_product_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp &&...__e) const {
        return ranges::base_k_product_view(std::forward<_Tp>(__e)...);
      }
    };
    inline constexpr _BaseKProduct base_k_product{};
  }  // namespace views

}  // namespace mtd
