#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <iostream>

#include "./../../Library/DataStructure/SegmentTree.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n, q;
  cin >> n >> q;

  struct F {
    auto operator()(ll a, ll b) const { return std::min(a, b); }
  };
  using M = Monoid<ll, (1LL << 31) - 1, F>;
  auto segtree = SegmentTree<M>(n);

  for (int _ = 0; _ < q; ++_) {
    int k, x, y;
    cin >> k >> x >> y;
    if (k == 0) {
      segtree.update(x, y);
    } else {
      cout << segtree.query(x, y) << endl;
    }
  }
}