#define PROBLEM "https://yukicoder.me/problems/no/1456"

#include <iostream>
#include <unordered_set>

// begin:tag includes
#include "./../../Library/DataStructure/Accumulation.hpp"
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

  auto inv = [](ll x) { return x; };
  auto op = [](ll x, ll y) { return x ^ y; };
  using G = mtd::Group<ll, 0, decltype(op), decltype(inv)>;
  auto acc = mtd::Accumulation<G>(a);

  std::unordered_set<ll> st;
  for (int i = 0; i < n; ++i) { st.emplace(acc.get(i) ^ k); }

  if (st.find(0) != st.end()) {
    std::cout << "Yes" << std::endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (st.find(acc.get(i)) != st.end()) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
}
