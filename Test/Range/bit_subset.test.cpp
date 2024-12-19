#define PROBLEM "https://yukicoder.me/problems/no/733"

#include <iostream>
#include <vector>

// begin:tag includes
#include "../../Library/Range/bit.hpp"
#include "../../Library/Utility/Tools.hpp"
// end:tag includes

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t, n;
  std::cin >> t >> n;
  std::vector<int> a(n);
  for (auto i : std::views::iota(0, n)) { std::cin >> a[i]; }

  auto sum = mtd::vec(0, 1 << n);
  for (auto bit : std::views::iota(1, 1 << n)) {
    auto b = mtd::ctz(bit);
    sum[bit] = (bit == (1 << b) ? 0 : sum[bit ^ (1 << b)]) + a[b];
  }

  auto dp = mtd::vec(n, 1 << n);
  for (auto bit : std::views::iota(0, 1 << n)) {
    if (sum[bit] <= t) { dp[bit] = 1; }
  }
  for (auto bit : std::views::iota(0, 1 << n)) {
    for (auto sub : mtd::views::bit_subset(bit)) {
      mtd::chmin(dp[bit], dp[sub] + dp[bit ^ sub]);
    }
  }
  std::cout << dp[(1 << n) - 1] << std::endl;
}
