#define PROBLEM "https://yukicoder.me/problems/no/2123"

#include "./../../Library/Utility/Ycombinator.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

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
  ll n;
  cin >> n;

  constexpr double nil = -1.0;
  std::vector<double> dp(n + 1, nil);
  auto f = mtd::Y([&](auto&& self, ll n) -> double {
    if (n == 0) { return 0.0; }
    if (dp[n] != nil) { return dp[n]; }

    double sum = 0.0;
    for (int x = 0; x < n; ++x) {
      int y = n - x - 1;
      sum += self(self, x);
      sum += self(self, y);
    }
    auto ans = sum / n + 1;
    dp[n] = ans;
    return ans;
  });

  cout << f(n) << endl;
}
