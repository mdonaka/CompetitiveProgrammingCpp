#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include "./../../Library/DataStructure/LiChaoTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

struct Query {
    int k;
    ll a, b, l, r;
    Query(int k, ll l, ll r, ll a, ll b) :k(k), a(a), b(b), l(l), r(r) {}
    Query(int k, ll x) :Query(k, 0, 0, x, x) {}
};

signed main() {
    ll n, q;
    cin >> n >> q;

    auto lct = DynamicLiChaoTree<static_cast<ll>(1e9)>();
    for(int _ = 0; _ < n; ++_) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b; --r;
        lct.add_segment(a, b, l, r);
    }

    for(int _ = 0; _ < q; ++_) {
        ll k;
        cin >> k;
        if(k == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b; --r;
            lct.add_segment(a, b, l, r);
        } else {
            ll x;
            cin >> x;
            auto ans = lct.query(x);
            if(ans >= 2e18) {
                cout << "INFINITY" << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
}
