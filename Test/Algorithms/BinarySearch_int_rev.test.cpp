#define PROBLEM "https://yukicoder.me/problems/no/91"

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
  std::vector<ll> a(3);
  for (int i = 0; i < 3; ++i) { cin >> a[i]; }

  auto ans = mtd::binarySearch(0, 1e9, [&](ll mid) {
    ll d = 0;
    for (const auto& x : a) {
      if (x >= mid) {
        d += ((x - mid) >> 1);
      } else {
        d -= mid - x;
      }
    }
    return d >= 0;
  });

  cout << ans << endl;
}
