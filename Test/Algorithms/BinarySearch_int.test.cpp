#define PROBLEM "https://yukicoder.me/problems/no/1882"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// begin:tag includes
#include "./../../Library/Algorithms/BinarySearch.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n, x;
  std::cin >> n >> x;
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) { std::cin >> a[i]; }
  std::ranges::sort(a);

  ll ans = 0;
  for (const auto& val : a) {
    auto idx = mtd::binarySearch<>(
        n, -1, [&](ll mid) { return val * a[mid] >= (x << 1); });
    ans += n - idx;
  }

  std::cout << ans << std::endl;
}
