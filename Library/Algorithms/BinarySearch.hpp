#pragma once

#include <concepts>
#include <numeric>
#include <ranges>
#include <type_traits>

namespace mtd {

  template <class Lambda>
  auto binarySearch(double ok, double ng, int rep, const Lambda& is_ok) {
    for ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {
      double mid = (ok + ng) / 2.0;
      (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
  }

  template <class Lambda, std::integral T1, std::integral T2>
  auto binarySearch(T1 ok_, T2 ng_, const Lambda& is_ok) {
    using T = std::common_type_t<T1, T2>;
    T ok = ok_, ng = ng_;
    while (std::abs(ok - ng) > 1) {
      T mid = (ok + ng) >> 1;
      (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
  }

}  // namespace mtd
