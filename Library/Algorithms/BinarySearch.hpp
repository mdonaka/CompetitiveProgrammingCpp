#pragma once

#include <numeric>
#include <ranges>

namespace mtd {

  template <class Lambda>
  auto binarySearch(double ok, double ng, int rep, const Lambda& is_ok) {
    for ([[maybe_unused]] auto _ : std::views::iota(0, rep)) {
      double mid = (ok + ng) / 2.0;
      (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
  }

  template <class Lambda, class T = long long>
  auto binarySearch(T ok, T ng, const Lambda& is_ok) {
    while (std::abs(ok - ng) > 1) {
      T mid = (ok + ng) >> 1;
      (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
  }

}  // namespace mtd
