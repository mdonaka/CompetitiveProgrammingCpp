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
    std::vector<std::vector<ll>> v; v.reserve(n);
    std::vector<ll> xs; xs.reserve(2 * n + 2 * q);
    for(int _ = 0; _ < n; ++_) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        --r;
        v.emplace_back(std::vector<ll>{l, r, a, b});
        xs.emplace_back(l); xs.emplace_back(r);
    }

    std::vector<Query> queries; queries.reserve(q);
    for(int _ = 0; _ < q; ++_) {
        ll k;
        cin >> k;
        if(k == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            --r;
            queries.emplace_back(k, l, r, a, b);
            xs.emplace_back(l); xs.emplace_back(r);
        } else {
            ll x;
            cin >> x;
            queries.emplace_back(k, x);
            xs.emplace_back(x);
        }
    }

    auto lct = LiChaoTree(xs);
    for(const auto& s : v) {
        lct.addSegment(s[2], s[3], s[0], s[1]);
    }

    for(const auto& query : queries) {
        if(query.k == 0) {
            lct.addSegment(query.a, query.b, query.l, query.r);
        } else {
            auto ans = lct.query(query.a);
            if(ans >= 2e18) {
                cout << "INFINITY" << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
}
