#include <ranges>
#include <vector>
namespace myranges {

struct enumerate_view : public std::ranges::view_interface<enumerate_view> {
  using C = std::vector<int>;

  class iterator {
    size_t index;
    C::const_iterator itr;

  public:
    using difference_type = int;
    using value_type = std::tuple<size_t, C::value_type>;
    using iterator_concept = std::input_iterator_tag;

    explicit iterator(const C::const_iterator& itr = C::const_iterator{})
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

  C c;

  explicit enumerate_view(const C& c) : c(c) {}
  auto begin() const { return iterator(c.begin()); }
  auto end() const { return iterator(c.end()); }
};

struct _Enumerate : std::views::__adaptor::_RangeAdaptorClosure {
  template <std::ranges::viewable_range _Range>
  constexpr auto operator()(_Range&& __r) const {
    return enumerate_view{std::forward<_Range>(__r)};
  }
  static constexpr bool _S_has_simple_call_op = true;
};

inline constexpr _Enumerate enumerate{};

}  // namespace myranges
