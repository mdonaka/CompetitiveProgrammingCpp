#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <deque>

#include "./../../Library/DataStructure/LiChaoTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';


signed main() {
    ll n, q;
    cin >> n >> q;

    auto lct = DynamicLiChaoTree<static_cast<ll>(1e9)>();
    for(int _ = 0; _ < n; ++_) {
        ll a, b;
        cin >> a >> b;
        lct.add(a, b);
    }

    for(int _ = 0; _ < q; ++_) {
        ll k;
        cin >> k;
        if(k == 0) {
            ll a, b;
            cin >> a >> b;
            lct.add(a, b);
        } else {
            ll x;
            cin >> x;
            cout << lct.query(x) << endl;
        }
    }
}
