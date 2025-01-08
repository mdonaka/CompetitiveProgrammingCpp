#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include <ranges>

// begin:tag includes
#include "../../Library/Math/BabyStepGiantStep.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t;
  std::cin >> t;
  for ([[maybe_unused]] auto _ : std::views::iota(0, t)) {
    ll x, y, m;
    std::cin >> x >> y >> m;

    auto ans = (m == 1)
                   ? 0
                   : mtd::baby_step_giant_step<std::hash<ll>>(
                         x, ll(1), y, m - 1,
                         [&](ll _x, ll _y) { return (_x * _y) % m; },
                         [&](const ll _m, ll _x) { return (_m * _x) % m; });

    if (ans) {
      std::cout << ans.value() << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
  }
}
