#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include <iostream>
#include "./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp"
#include "./../../../Library/DataStructure/LazySegmentTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {

    ll n;
    cin >> n;
    std::unordered_multimap<int, int> tree;
    ll add = n;
    for(int f = 0; f < n; ++f) {
        int k;
        cin >> k;
        for(int _ = 0; _ < k; ++_) {
            int t;
            cin >> t;
            tree.emplace(f, add);
            tree.emplace(t, add);
            tree.emplace(add, t);
            tree.emplace(add, f);
            ++add;
        }
    }

    int size = n + n - 1;
    std::vector<std::pair<ll, ll>> v(n - 1, {0,1});
    auto segtree = LazySegmentTree<M_S, M_A, OP_RAQ_RSQ>(n - 1, v);
    auto hld = HeavyLightDecomposition(size, tree);

    ll q;
    cin >> q;
    for(int _ = 0; _ < q; ++_) {
        ll k;
        cin >> k;
        if(k == 0) {
            ll v, w;
            cin >> v >> w;
            for(const auto& [l, r] : hld.rangeEdge(0, v)) {
                segtree.update(l, r, w);
            }
        } else {
            ll u;
            cin >> u;
            ll ans = 0;
            for(const auto& [l, r] : hld.rangeEdge(0, u)) {
                ans += segtree.query(l, r).first;
            }
            cout << ans << endl;
        }
    }
}