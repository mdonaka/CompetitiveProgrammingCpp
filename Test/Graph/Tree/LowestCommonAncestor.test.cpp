#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "./../../../Library/Graph/Tree/LowestCommonAncestor.hpp"

#include <iostream>

#include "./../../../Library/Graph/Graph.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  ll n;
  cin >> n;
  mtd::Graph tree(n);
  for (int f = 0; f < n; ++f) {
    ll k;
    cin >> k;
    for (int _ = 0; _ < k; ++_) {
      int t;
      cin >> t;
      tree.addEdge(f, t);
    }
  }

  auto lca = mtd::LowestCommonAncestor(tree, 0);

  int q;
  cin >> q;
  for (int _ = 0; _ < q; ++_) {
    int u, v;
    cin >> u >> v;
    cout << lca.lca(u, v) << endl;
  }
}
