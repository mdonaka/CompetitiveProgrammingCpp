#include <ranges>
#include <vector>

namespace myranges {

  template <std::ranges::range _Range>
  struct enumerate_view
      : public std::ranges::view_interface<enumerate_view<_Range>> {
    class iterator {
      size_t index;
      _Range::const_iterator itr;

    public:
      using difference_type = int;
      using value_type = std::tuple<size_t, typename _Range::value_type>;
      using iterator_concept = std::input_iterator_tag;

      explicit iterator(const typename _Range::const_iterator& itr =
                            typename _Range::const_iterator{})
          : index(0), itr(itr) {}
      auto operator*() const { return std::make_tuple(index, *itr); }
      auto& operator++() {
        ++itr;
        ++index;
        return *this;
      }
      auto operator++(int) { return ++*this; }
      auto operator==(const iterator& other) const { return itr == other.itr; }
    };

    _Range __r = _Range();

    enumerate_view() requires std::default_initializable<_Range>
    = default;
    constexpr explicit enumerate_view(const _Range& __r) : __r(__r) {}

    auto begin() const { return iterator(__r.begin()); }
    auto end() const { return iterator(__r.end()); }
  };

  namespace views {
    namespace __detail {
      struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {
        template <std::ranges::viewable_range _Range>
        constexpr auto operator()(_Range&& __r) const {
          return enumerate_view{std::forward<_Range>(__r)};
        }
        static constexpr bool _S_has_simple_call_op = true;
      };
    }  // namespace __detail

    inline constexpr __detail::_Enumerate enumerate{};
  }  // namespace views
}  // namespace myranges
