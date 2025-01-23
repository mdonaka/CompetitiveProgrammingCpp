#define PROBLEM "https://yukicoder.me/problems/no/833"

#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

// begin:tag includes
#include "./../../Library/DataStructure/LazySegmentTree.hpp"
#include "./../../Library/DataStructure/SegmentTree.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;
  std::vector<ll> a(n);
  for (auto i : std::views::iota(0, n)) { std::cin >> a[i]; }

  std::vector<ll> v(n);
  std::iota(v.begin(), v.end(), 0);
  auto segtree1 = mtd::LazySegmentTree<mtd::type::M_MIN, mtd::type::M_UP,
                                       mtd::type::OP_MIN_UP>(n, v);
  auto segtree2 = mtd::LazySegmentTree<mtd::type::M_MAX, mtd::type::M_UP,
                                       mtd::type::OP_MAX_UP>(n, v);
  auto range = [&](int i) {
    auto val = segtree1.query(i, i);
    auto judge_l = [&](const mtd::type::M_MIN& m) { return m.m_val >= val; };
    auto judge_r = [&](const mtd::type::M_MAX& m) { return m.m_val <= val; };
    auto l = segtree1.min_left(i, judge_l);
    auto r = segtree2.max_right(i, judge_r);
    return std::make_tuple(l, r);
  };
  for (auto i : std::views::iota(0, n)) { range(i); }

  auto op = [](ll a, ll b) { return a + b; };
  using M = mtd::Monoid<ll, 0LL, decltype(op)>;
  auto segtree3 = mtd::SegmentTree<M>(n, a);

  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {
    int t, x;
    std::cin >> t >> x;
    --x;
    if (t == 1) {
      auto val = segtree1.query(x, x);
      auto [l, r] = range(x + 1);
      segtree1.update(l, r, val);
      segtree2.update(l, r, val);
    } else if (t == 2) {
      auto [l, r] = range(x + 1);
      segtree1.update(x + 1, r, x + 1);
      segtree2.update(x + 1, r, x + 1);
    } else if (t == 3) {
      segtree3.add(x, 1);
    } else {
      auto [l, r] = range(x);
      std::cout << segtree3.query(l, r) << std::endl;
    }
  }
}
