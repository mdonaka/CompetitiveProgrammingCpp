#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include <iostream>
#include <map>

// begin:tag includes
#include "./../../Library/DataStructure/Accumulation.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  do {
    ll n, k;
    std::cin >> n >> k;
    if (n == 0 && k == 0) { break; }

    std::vector<ll> a;
    a.reserve(n);
    for (int _ = 0; _ < n; ++_) {
      ll x;
      std::cin >> x;
      a.emplace_back(x);
    }

    auto acc = mtd::Accumulation<>(a);

    ll ans = -1e18;
    for (int i = 0; i < n - k + 1; ++i) {
      auto val = acc.get(i, i + k - 1);
      ans = std::max(ans, val);
    }
    std::cout << ans << std::endl;
  } while (true);
}
