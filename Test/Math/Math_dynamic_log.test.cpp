#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_mod"

#include <ranges>

#include "./../../Library/Debug/Dump.hpp"

// begin:tag includes
#include "../../Library/Math/DynamicModInt.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t;
  std::cin >> t;
  // t = 1;
  for ([[maybe_unused]] auto _ : std::views::iota(0, t)) {
    ll x, y, m;
    std::cin >> x >> y >> m;

    // x = 156648746;
    // y = 154396384;
    // m = 916122984;

    using mint = mtd::DynamicModInt<>;
    mint::set_mod(m);
    auto math = mtd::Math<mint>();

    if (auto ans = math.log(x, y); ans) {
      std::cout << ans.value() << std::endl;
      // dump(math.pow(x, 1618984));
      // dump(math.pow(x, ans.value()));
    } else {
      std::cout << -1 << std::endl;
    }
  }
}
