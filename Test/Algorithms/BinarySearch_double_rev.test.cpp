#define PROBLEM "https://yukicoder.me/problems/no/67"
#define ERROR "1e-9"

#include <iomanip>
#include <iostream>
#include <vector>

#include "./../../Library/Algorithms/BinarySearch.hpp"

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
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  ll k;
  cin >> k;

  auto ans = binarySearch(1e-9, 1e9, 100, [&](double mid) {
    ll count = 0;
    for (const auto& x : a) { count += (1.0 * x / mid); }
    return count >= k;
  });

  cout << std::fixed << std::setprecision(12) << ans << endl;
}
