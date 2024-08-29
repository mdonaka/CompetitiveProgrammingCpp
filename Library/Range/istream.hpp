#pragma once

#include <ranges>

#include "../Utility/io.hpp"

namespace mtd {
  namespace ranges {

    constexpr int _inf = 1e9;

    template <class... Args>
    struct istream_view
        : public std::ranges::view_interface<istream_view<Args...>> {
      class iterator {
        int count;
        std::tuple<typename io::_Converter<Args>::type...> val;

      public:
        using difference_type = int;
        using value_type = decltype(val);
        using iterator_concept = std::input_iterator_tag;

        constexpr iterator() = default;
        constexpr explicit iterator(int count) : count(count) { operator++(); }

        constexpr auto operator*() const { return val; }
        constexpr auto& operator++() {
          --count;
          if (count >= 0) { val = io::in<Args...>(); }
          return *this;
        }
        constexpr auto operator++(int) { return ++*this; }

        constexpr auto operator==(const iterator& s) const {
          return count == s.count;
        }
        constexpr auto operator==(std::default_sentinel_t s) const {
          return count < 0 || std::cin.eof() || std::cin.fail() ||
                 std::cin.bad();
        }
        constexpr friend auto operator==(std::default_sentinel_t s,
                                         const iterator& li) {
          return li == s;
        }
      };

      int count;

    public:
      constexpr explicit istream_view(int count) : count(count) {}
      constexpr explicit istream_view() : istream_view(_inf) {}
      constexpr auto begin() const { return iterator(count); }
      constexpr auto end() const { return std::default_sentinel; }
    };
  }  // namespace ranges

  namespace views {
    namespace __detail {
      template <typename... _Args>
      concept __can_istream_view = requires {
        ranges::istream_view(std::declval<_Args>()...);
      };
    }  // namespace __detail

    template <class... Args>
    struct _Istream {
      template <class... _Tp>
      requires __detail::__can_istream_view<_Tp...>
      constexpr auto operator() [[nodiscard]] (_Tp&&... __e) const {
        return ranges::istream_view<Args...>(std::forward<_Tp>(__e)...);
      }
    };

    template <class... Args>
    inline constexpr _Istream<Args...> istream{};
  }  // namespace views

}  // namespace mtd
