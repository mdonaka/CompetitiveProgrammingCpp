#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include <iostream>

#include "./../../Library/DataStructure/LazySegmentTree.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n, q;
  cin >> n >> q;

  std::vector<long long> v(n, (1LL << 31) - 1);
  auto segtree =
      mtd::LazySegmentTree<mtd::M_M, mtd::M_U, mtd::OP_RUQ_RMQ>(n, v);

  for (int _ = 0; _ < q; ++_) {
    int k;
    cin >> k;
    if (k == 0) {
      int s, t, x;
      ;
      cin >> s >> t >> x;
      segtree.update(s, t, x);
    } else {
      int s, t;
      cin >> s >> t;
      cout << segtree.query(s, t) << endl;
    }
  }
}
