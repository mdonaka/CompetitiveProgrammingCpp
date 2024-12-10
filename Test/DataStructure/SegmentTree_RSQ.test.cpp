#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

// begin:tag includes
#include "./../../Library/DataStructure/SegmentTree.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  auto op = [](ll a, ll b) { return a + b; };
  using M = mtd::Monoid<ll, 0, decltype(op)>;
  auto segtree = mtd::SegmentTree<M>(n);

  for (int _ = 0; _ < q; ++_) {
    int k, x, y;
    std::cin >> k >> x >> y;
    if (k == 0) {
      segtree.add(x - 1, y);
    } else {
      std::cout << segtree.query(x - 1, y - 1) << std::endl;
    }
  }
}
