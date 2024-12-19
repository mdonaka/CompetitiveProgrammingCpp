#include <vector>
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include <iostream>
#include <ranges>

// begin:tag includes
#include "./../../Library/DataStructure/DisjointSetUnion.hpp"
#include "./../../Library/Math/ModInt.hpp"
// end:tag includes

constexpr long long MOD = 998244353;
using mint = mtd::ModInt<MOD>;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  auto dsu = mtd::PotentialDisjointSetUnion<mint>(n);

  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int u, v, x;
      std::cin >> u >> v >> x;

      if (!dsu.isSame(u, v) || dsu.diff(u, v) == x) {
        std::cout << 1 << std::endl;
        dsu.unite(u, v, x);
      } else {
        std::cout << 0 << std::endl;
      }
    } else {
      int u, v;
      std::cin >> u >> v;

      if (dsu.isSame(u, v)) {
        std::cout << dsu.diff(u, v) << std::endl;
      } else {
        std::cout << -1 << std::endl;
      }
    }
  }
}
