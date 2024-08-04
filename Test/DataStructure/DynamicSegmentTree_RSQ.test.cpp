#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#include "./../../Library/DataStructure/DynamicSegmentTree.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n, q;
  cin >> n >> q;

  struct F {
    auto operator()(ll a, ll b) const { return a + b; }
  };
  using M = Monoid<ll, 0, F>;
  auto segtree = DynamicSegmentTree<M>();

  for (int _ = 0; _ < q; ++_) {
    int k, x, y;
    cin >> k >> x >> y;
    if (k == 0) {
      segtree.add(x - 1, y);
    } else {
      cout << segtree.query(x - 1, y - 1) << endl;
    }
  }
}