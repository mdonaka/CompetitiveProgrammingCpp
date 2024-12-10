#define PROBLEM "https://yukicoder.me/problems/no/1623"

#include <iostream>

// begin:tag includes
#include "./../../Library/DataStructure/Accumulation2D.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;

  constexpr ll size = 3e3 + 1;

  std::vector<ll> rv;
  rv.reserve(n);
  for (int _ = 0; _ < n; ++_) {
    int r;
    std::cin >> r;
    rv.emplace_back(r);
  }
  std::vector<ll> gc(size), bc(size);
  for (int _ = 0; _ < n; ++_) {
    int b;
    std::cin >> b;
    ++bc[b];
  }
  for (int _ = 0; _ < n; ++_) {
    int g;
    std::cin >> g;
    ++gc[g];
  }

  std::vector<std::vector<ll>> table(size, std::vector<ll>(2 * size));
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j) {
      table[std::max(i, j)][i + j] += gc[i] * bc[j];
    }
  auto acc = mtd::Accumulation2D<>(table);

  ll ans = 0;
  for (const auto& r : rv) { ans += acc.get(0, r + 1, r, 2 * size - 1); }
  std::cout << ans << std::endl;
}
