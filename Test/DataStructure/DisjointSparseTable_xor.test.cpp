#define PROBLEM "https://yukicoder.me/problems/no/1456"

#include <iostream>
#include <unordered_set>

// begin:tag includes
#include "./../../Library/DataStructure/DisjointSparseTable.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n, k;
  std::cin >> n >> k;

  std::vector<ll> a;
  a.reserve(n);
  for (int _ = 0; _ < n; ++_) {
    ll x;
    std::cin >> x;
    a.emplace_back(x);
  }

  auto op = [](ll x, ll y) { return x ^ y; };
  using SG = mtd::SemiGroup<ll, decltype(op)>;
  auto dst = mtd::DisjointSparseTable<SG>(n, a);

  std::unordered_set<ll> st;
  for (int i = 0; i < n; ++i) { st.emplace(dst.get(0, i) ^ k); }

  if (st.find(0) != st.end()) {
    std::cout << "Yes" << std::endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (st.find(dst.get(0, i)) != st.end()) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
}
