#define PROBLEM "https://yukicoder.me/problems/no/1282"

#include "./../../Library/DataStructure/DynamicSegmentTree.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

struct Functor {
  auto operator()(ll a, ll b) const { return a + b; }
};
using M = mtd::Monoid<ll, 0, Functor>;

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

  ll ans = 0;
  auto segtree = mtd::DynamicSegmentTree<M>();
  for (int i = 0; i < n; ++i) {
    segtree.add(b[i], 1);
    ans += segtree.query(0, a[i] - 1);
  }

  cout << ans << endl;
}
