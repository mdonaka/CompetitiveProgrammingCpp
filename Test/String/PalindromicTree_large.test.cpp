#define PROBLEM "https://yukicoder.me/problems/no/263"

#include <algorithm>
#include <iostream>

#include "./../../Library/String/PalindromicTree.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';
struct Preprocessing {
  Preprocessing() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
  };
} _Preprocessing;

signed main() {
  std::string a, b;
  cin >> a >> b;
  std::string s = a + "$%" + b;

  auto tree = PalindromicTree(s);

  ll an = a.size();
  std::vector<std::pair<ll, ll>> dp(s.size());
  tree.dfs_edges([&](int size, const std::list<int>& ritr) {
    ll l = 0, r = 0;
    for (const auto& x : ritr)
      if (x != an && x != an + 1) { ++((x < an) ? l : r); }
    dp[ritr.front()] = {l, r};
  });

  tree.dp_suffixLink([&](int from, int to) {
    dp[to].first += dp[from].first;
    dp[to].second += dp[from].second;
  });

  ll ans = 0;
  for (const auto& p : dp) { ans += (p.first * p.second); }
  cout << ans << endl;
}