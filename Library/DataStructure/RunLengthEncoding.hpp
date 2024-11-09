#pragma once

#include <ranges>
#include <vector>

namespace mtd {
  template <std::ranges::range _R>
  class RunLengthEncoding {
    using T = std::iter_value_t<std::ranges::iterator_t<_R>>;

    const std::vector<std::tuple<T, int>> r;

    static constexpr auto construct_rle(const _R& r) {
      std::vector<std::tuple<T, int>> rle;
      if (r.empty()) { return rle; }
      T now = *r.begin();
      int cnt = 1;
      for (const auto& x : r | std::views::drop(1)) {
        if (x == now) {
          ++cnt;
        } else {
          rle.emplace_back(now, cnt);
          cnt = 1;
          now = x;
        }
      }
      rle.emplace_back(now, cnt);
      return rle;
    }

  public:
    constexpr RunLengthEncoding(const _R& r) : r(construct_rle(r)) {}

    constexpr auto begin() const { return r.begin(); }
    constexpr auto end() const { return r.end(); }
  };
}  // namespace mtd
