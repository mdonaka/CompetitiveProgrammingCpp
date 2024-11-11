#define PROBLEM "https://yukicoder.me/problems/no/1282"

#include <algorithm>
#include <iostream>
#include <vector>

#include "./../../Library/Algorithms/CoordinateCompression.hpp"
#include "./../../Library/DataStructure/SegmentTree.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

struct Functor {
  auto operator()(ll a, ll b) const { return a + b; }
};
using M = Monoid<ll, 0, Functor>;

signed main() {
  ll n;
  cin >> n;
  std::vector<ll> a, b;
  a.reserve(n);
  b.reserve(n);
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    a.emplace_back(x);
  }
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    b.emplace_back(x);
  }
  std::sort(a.begin(), a.end());

  auto ab = a;
  for (const auto& x : b) { ab.emplace_back(x); }
  auto cc = mtd::CoordinateCompression(ab);
  auto v = cc.c();

  ll ans = 0;
  auto segtree = SegmentTree<M>(cc.size());
  for (int i = 0; i < n; ++i) {
    segtree.add(v[i + n], 1);
    ans += segtree.query(0, v[i] - 1);
  }

  cout << ans << endl;
}
