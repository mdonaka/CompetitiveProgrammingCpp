#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include <iostream>

// begin:tag includes
#include "./../../Library/DataStructure/LazySegmentTree.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  int n, q;
  std::cin >> n >> q;

  std::vector<long long> v(n, (1LL << 31) - 1);
  auto segtree = mtd::LazySegmentTree<mtd::type::M_MIN, mtd::type::M_UP,
                                      mtd::type::OP_MIN_UP>(n, v);

  for (int _ = 0; _ < q; ++_) {
    int k;
    std::cin >> k;
    if (k == 0) {
      int s, t, x;
      std::cin >> s >> t >> x;
      segtree.update(s, t, x);
    } else {
      int s, t;
      std::cin >> s >> t;
      std::cout << segtree.query(s, t) << std::endl;
    }
  }
}
