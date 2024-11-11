#define PROBLEM "https://yukicoder.me/problems/no/1390"

#include "./../../Library/DataStructure/UnionFind.hpp"

#include <deque>
#include <iostream>
#include <vector>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  ll n, m;
  cin >> n >> m;
  std::vector<std::deque<ll>> cv(n);
  for (int _ = 0; _ < n; ++_) {
    ll b, c;
    cin >> b >> c;
    cv[c - 1].emplace_back(b - 1);
  }

  auto dsu = mtd::UnionFind(m);

  ll ans = 0;
  for (const auto& dq : cv)
    if (!dq.empty()) {
      auto base = dq.front();
      for (const auto& tg : dq) {
        if (!dsu.isSame(base, tg)) {
          dsu.unite(base, tg);
          ++ans;
        }
      }
    }
  cout << ans << endl;
}
