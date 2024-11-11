#define PROBLEM "https://yukicoder.me/problems/no/674"

// begin:tag includes
#include "./../../Library/DataStructure/SegmentMap.hpp"
// end:tag includes

#include <iostream>
#include <ranges>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  ll d, q;
  cin >> d >> q;

  auto segmap = mtd::SegmentMap(d);

  ll ans = 0;
  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {
    ll a, b;
    cin >> a >> b;
    segmap.update(a, b, 1);

    auto [l, r, __] = segmap.get(a);
    ans = std::max(ans, r - l + 1);
    cout << ans << endl;
  }
}
