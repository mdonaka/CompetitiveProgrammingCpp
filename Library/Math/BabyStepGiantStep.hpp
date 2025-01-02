#pragma once

#include <cmath>
#include <optional>
#include <ranges>
#include <unordered_map>

namespace mtd {
  /*
   * x^i * s = t (0 <= i < n) を満たす最小のi
   * O(sqrt(n))
   */
  template <class Monoid, class T, class Product, class Op>
  std::optional<long long> baby_step_giant_step(const Monoid& x, const T& s,
                                                const T& t, long long n,
                                                const Product prod,
                                                const Op& op) {
    if (n == 0) { return (s == t) ? std::make_optional(0) : std::nullopt; }
    if (n == 1) {
      return (s == t)          ? std::make_optional(0)
             : (op(x, s) == t) ? std::make_optional(1)
                               : std::nullopt;
    }

    auto m = static_cast<long long>(std::sqrt(n));
    std::unordered_map<T, size_t> mp;
    auto xm = x;
    for (auto i : std::views::iota(0, m)) {
      mp[op(xm, t)] = i;
      if (i < m - 1) { xm = prod(xm, x); }
    }

    bool find = false;
    auto xks = s;
    for (auto k : std::views::iota(1, n / m + 5)) {
      auto next = op(xm, xks);
      if (mp.contains(next)) {
        auto xi = xks;
        for (auto i : std::views::iota(m * (k - 1), m * k + 1)) {
          if (xi == t) { return i; }
          xi = op(x, xi);
        }
        if (find) { return std::nullopt; }
        find = true;
      }
      std::swap(xks, next);
    }
    return std::nullopt;
  }
};  // namespace mtd
