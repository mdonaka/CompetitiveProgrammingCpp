#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <numeric>
#include "./../../Library/DataStructure/LiChaoTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';


signed main() {
    ll n, a, b, w;
    cin >> n >> a >> b >> w;
    std::vector<ll> d; d.reserve(n);
    for(int i = 0; i < n; ++i) {
        ll x; cin >> x;
        d.emplace_back(x);
    }

    std::vector<ll> xs(n);
    std::iota(xs.begin(), xs.end(), 1);
    LiChaoTree lct(xs);

    constexpr ll mx = 1e18;
    std::vector<ll> dp(n + 1, mx);
    auto update = [&](ll i, ll x) {
        dp[i] = x;
        auto pa = -b * i;
        auto pb = a * i + i * (i + 1) / 2 * b + dp[i];
        lct.addLine(pa, pb);
    };

    update(0, w);
    for(ll i = 1; i < n + 1; ++i) {
        auto ad = d[i - 1] - a * i + a + i * (i - 1) / 2 * b;
        auto min = lct.query(i);
        update(i, ad + min);
    }

    ll ans = dp[n];
    for(ll i = 0; i < n; ++i) {
        ll k = n - i;
        ans = std::min(ans, dp[i] + -a * k + k * (k + 1) / 2 * b);
    }

    cout << ans << endl;
}

