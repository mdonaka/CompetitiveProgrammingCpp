#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include <iostream>

// begin:tag includes
#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n;
  std::cin >> n;
  auto tree = mtd::Graph<int, bool>(n);
  for (int f = 0; f < n; ++f) {
    ll k;
    std::cin >> k;
    for (int _ = 0; _ < k; ++_) {
      int t;
      std::cin >> t;
      tree.addArc(f, t);
    }
  }

  auto hld = mtd::HeavyLightDecomposition(tree);

  int q;
  std::cin >> q;
  for (int _ = 0; _ < q; ++_) {
    int u, v;
    std::cin >> u >> v;
    std::cout << hld.lca(u, v) << std::endl;
  }
}
