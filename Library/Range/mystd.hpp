#pragma once

#include <ranges>

namespace myranges {

  template <std::ranges::range _Range>
  struct enumerate_view
      : public std::ranges::view_interface<enumerate_view<_Range>> {
    auto flat_tuple() {}

    class iterator;
    class sentinel;

    struct iterator {
      size_t index;
      _Range::iterator _M_current;

      using difference_type = int;
      // TODO: tupleが渡された時にflatにする
      using value_type =
          std::tuple<size_t, typename _Range::iterator::value_type>;
      using iterator_concept = std::input_iterator_tag;

      explicit iterator(const typename _Range::iterator& _M_current =
                            typename _Range::iterator{})
          : index(0), _M_current(_M_current) {}
      auto operator*() const { return std::make_tuple(index, *_M_current); }
      auto& operator++() {
        ++_M_current;
        ++index;
        return *this;
      }
      auto operator++(int) { return ++*this; }
      auto operator==(const iterator& other) const {
        return _M_current == other._M_current;
      }
    };

    class sentinel {
      std::ranges::sentinel_t<_Range> _M_end;

    public:
      constexpr explicit sentinel(std::ranges::sentinel_t<_Range>&& __end)
          : _M_end(std::forward<std::ranges::sentinel_t<_Range>>(__end)) {}

      friend constexpr bool operator==(const iterator& __x,
                                       const sentinel& __y) {
        return __x._M_current == __y._M_end;
      }
    };

    _Range __r = _Range();

    enumerate_view() requires std::default_initializable<_Range>
    = default;
    constexpr explicit enumerate_view(const _Range& __r) : __r(__r) {}

    auto begin() { return iterator(__r.begin()); }
    auto end() {
      if constexpr (requires() { iterator(__r.end()); }) {
        return iterator(__r.end());
      } else {
        return sentinel(__r.end());
      }
    }
  };

  namespace views {
    struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {
      template <std::ranges::viewable_range _Range>
      constexpr auto operator()(_Range&& __r) const {
        return enumerate_view{std::forward<_Range>(__r)};
      }
      static constexpr bool _S_has_simple_call_op = true;
    };

    inline constexpr _Enumerate enumerate{};
  }  // namespace views
}  // namespace myranges
