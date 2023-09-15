#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include <iostream>
#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Tree/HeavyLightDecomposition.hpp"
#include "./../../../Library/DataStructure/LazySegmentTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {

    ll n;
    cin >> n;
    auto size = n + n - 1;
    auto tree = Graph<int, bool>(size);
    ll add = n;
    for(int f = 0; f < n; ++f) {
        int k;
        cin >> k;
        for(int _ = 0; _ < k; ++_) {
            int t;
            cin >> t;
            tree.addEdgeUndirected(f, add);
            tree.addEdgeUndirected(t, add);
            ++add;
        }
    }

    std::vector<std::pair<ll, ll>> v(n - 1, {0,1});
    auto segtree = LazySegmentTree<M_S, M_A, OP_RAQ_RSQ>(n - 1, v);
    // NOTE: 初期値が含まれる場合はID順に並び変える
    // val[hld.getEdgeId(i + n)] = v[i];
    auto hld = HeavyLightDecomposition(tree);

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