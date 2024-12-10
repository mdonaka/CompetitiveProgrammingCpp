#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <map>

// begin:tag includes
#include "./../../Library/DataStructure/DisjointSparseTable.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n, q;
  std::cin >> n >> q;
  std::vector<int> a;
  a.reserve(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    a.emplace_back(x);
  }

  auto op = [](int a, int b) { return std::min(a, b); };
  using SG = mtd::SemiGroup<int, decltype(op)>;
  auto dst = mtd::DisjointSparseTable<SG>(n, a);

  for (int _ = 0; _ < q; ++_) {
    ll l, r;
    std::cin >> l >> r;
    std::cout << dst.get(l, r - 1) << std::endl;
  }
}
