#define PROBLEM "https://yukicoder.me/problems/no/674"

#include <iostream>
#include "./../../Library/DataStructure/SegmentMap.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    ll d, q;
    cin >> d >> q;

    auto segmap = SegmentMap(d);

    ll ans = 0;
    for(int _ = 0; _ < q; ++_) {
        ll a, b;
        cin >> a >> b;
        segmap.update(a, b, 1);

        auto [__, range] = segmap.get(a);
        ans = std::max(ans, range.second - range.first + 1);
        cout << ans << endl;
    }
}