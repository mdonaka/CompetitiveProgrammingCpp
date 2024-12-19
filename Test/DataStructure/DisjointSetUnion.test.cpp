#include <vector>
#define PROBLEM "https://yukicoder.me/problems/no/1390"

#include <iostream>

// begin:tag includes
#include "./../../Library/DataStructure/DisjointSetUnion.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> cv(n);
  for (int _ = 0; _ < n; ++_) {
    int b, c;
    std::cin >> b >> c;
    cv[c - 1].emplace_back(b - 1);
  }

  auto dsu = mtd::PotentialDisjointSetUnion(m);

  int ans = 0;
  for (const auto& v : cv)
    if (!v.empty()) {
      auto base = v.front();
      for (const auto& tg : v) {
        if (!dsu.isSame(base, tg)) {
          dsu.unite(base, tg);
          ++ans;
        }
      }
    }
  std::cout << ans << std::endl;
}
