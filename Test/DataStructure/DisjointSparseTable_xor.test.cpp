#define PROBLEM "https://yukicoder.me/problems/no/1456"

#include <iostream>
#include <unordered_set>

#include "./../../Library/DataStructure/DisjointSparseTable.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

struct F {
  auto operator()(ll x, ll y) { return x ^ y; }
};
using SG = mtd::SemiGroup<ll, F>;

signed main() {
  ll n, k;
  cin >> n >> k;

  std::vector<ll> a;
  a.reserve(n);
  for (int _ = 0; _ < n; ++_) {
    ll x;
    cin >> x;
    a.emplace_back(x);
  }

  auto dst = mtd::DisjointSparseTable<SG>(n, a);
  std::unordered_set<ll> st;
  for (int i = 0; i < n; ++i) { st.emplace(dst.get(0, i) ^ k); }

  if (st.find(0) != st.end()) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (st.find(dst.get(0, i)) != st.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
