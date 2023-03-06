#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include <iostream>
#include <map>
#include "./../../Library/DataStructure/Accumulation.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    do {
        ll n, k;
        cin >> n >> k;
        if(n == 0 && k == 0) { break; }

        std::vector<ll> a; a.reserve(n);
        for(int _ = 0; _ < n; ++_) {
            ll x; cin >> x;
            a.emplace_back(x);
        }

        auto acc = Accumulation<>(a);

        ll ans = -1e18;
        for(int i = 0; i < n - k + 1; ++i) {
            auto val = acc.get(i, i + k - 1);
            ans = std::max(ans, val);
        }
        cout << ans << endl;
    } while(true);
}