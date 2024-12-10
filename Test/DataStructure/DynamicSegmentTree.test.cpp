#define PROBLEM "https://yukicoder.me/problems/no/1282"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// begin:tag includes
#include "./../../Library/DataStructure/DynamicSegmentTree.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n;
  std::cin >> n;
  std::vector<ll> a, b;
  a.reserve(n);
  b.reserve(n);
  for (int i = 0; i < n; ++i) {
    ll x;
    std::cin >> x;
    a.emplace_back(x);
  }
  for (int i = 0; i < n; ++i) {
    ll x;
    std::cin >> x;
    b.emplace_back(x);
  }
  std::ranges::sort(a);

  auto op = [](ll a, ll b) { return a + b; };
  using M = mtd::Monoid<ll, 0, decltype(op)>;
  auto segtree = mtd::DynamicSegmentTree<M>();

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    segtree.add(b[i], 1);
    ans += segtree.query(0, a[i] - 1);
  }

  std::cout << ans << std::endl;
}
