#define PROBLEM "https://yukicoder.me/problems/no/1435"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// begin:tag includes
#include "./../../Library/DataStructure/SegmentTree.hpp"
// end:tag includes

using ll = long long;

struct T {
  ll min1, min2, max;
  constexpr T(ll _min1, ll _min2, ll _max)
      : min1(_min1), min2(_min2), max(_max) {}
};
auto op = [](const T& a, const T& b) {
  std::vector<ll> v{a.min1, a.min2, b.min1, b.min2};
  std::ranges::sort(v);
  return T(v[0], v[1], std::max(a.max, b.max));
};
constexpr T e{1LL << 60, 1LL << 60, -(1LL << 60)};
using M = mtd::Monoid<T, e, decltype(op)>;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  std::vector<ll> a(n);
  for (auto i : std::views::iota(0, n)) { std::cin >> a[i]; }

  auto segtree = mtd::SegmentTree<M>(n);
  for (auto i : std::views::iota(0, n)) {
    segtree.update(i, T(a[i], 1LL << 60, a[i]));
  }

  ll ans = 0;
  for (auto r : std::views::iota(0, n)) {
    auto l = segtree.min_left(r, [](const M& m) {
      auto [min1, min2, max] = m.m_val;
      return max <= min1 + min2;
    });
    ans += r - l;
  }
  std::cout << ans << std::endl;
}
