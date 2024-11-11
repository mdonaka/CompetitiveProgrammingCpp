#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <deque>
#include <iostream>
#include <vector>

#include "./../../Library/DataStructure/LiChaoTree.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  ll n, q;
  cin >> n >> q;

  auto lct = mtd::DynamicLiChaoTree<static_cast<ll>(1e9)>();
  for (int _ = 0; _ < n; ++_) {
    ll a, b;
    cin >> a >> b;
    lct.addLine(a, b);
  }

  for (int _ = 0; _ < q; ++_) {
    ll k;
    cin >> k;
    if (k == 0) {
      ll a, b;
      cin >> a >> b;
      lct.addLine(a, b);
    } else {
      ll x;
      cin >> x;
      cout << lct.query(x) << endl;
    }
  }
}
