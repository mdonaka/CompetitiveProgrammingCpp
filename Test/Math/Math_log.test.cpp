#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_mod"

#include <ranges>

// begin:tag includes
#include "../../Library/Math/Math.hpp"
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

    if (auto ans = mtd::Math<ll>::log(x, y, m); ans) {
      std::cout << ans.value() << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
  }
}
