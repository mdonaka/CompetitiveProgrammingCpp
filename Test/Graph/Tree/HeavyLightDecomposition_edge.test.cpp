#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include <iostream>

// begin:tag includes
#include "./../../../Library/DataStructure/LazySegmentTree.hpp"
#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n;
  std::cin >> n;
  auto size = n + n - 1;
  auto tree = mtd::Graph<int, bool>(size);
  ll add = n;
  for (int f = 0; f < n; ++f) {
    int k;
    std::cin >> k;
    for (int _ = 0; _ < k; ++_) {
      int t;
      std::cin >> t;
      tree.addEdgeUndirected(f, add);
      tree.addEdgeUndirected(t, add);
      ++add;
    }
  }

  std::vector<std::pair<ll, ll>> v(n - 1, {0, 1});
  auto segtree = mtd::LazySegmentTree<mtd::type::M_SUM, mtd::type::M_ADD,
                                      mtd::type::OP_SUM_ADD>(n - 1, v);
  // NOTE: 初期値が含まれる場合はID順に並び変える
  // val[hld.getEdgeId(i + n)] = v[i];
  auto hld = mtd::HeavyLightDecomposition(tree);

  ll q;
  std::cin >> q;
  for (int _ = 0; _ < q; ++_) {
    ll k;
    std::cin >> k;
    if (k == 0) {
      ll v, w;
      std::cin >> v >> w;
      for (const auto& [l, r] : hld.rangeEdge(0, v)) {
        segtree.update(l, r, w);
      }
    } else {
      ll u;
      std::cin >> u;
      ll ans = 0;
      for (const auto& [l, r] : hld.rangeEdge(0, u)) {
        ans += segtree.query(l, r).first;
      }
      std::cout << ans << std::endl;
    }
  }
}
