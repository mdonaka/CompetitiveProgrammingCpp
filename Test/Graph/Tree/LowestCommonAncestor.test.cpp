#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include <iostream>
#include "./../../../Library/Graph/Tree/LowestCommonAncestor.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    ll n;
    cin >> n;
    std::unordered_multimap<int, int> tree;
    for(int f = 0; f < n; ++f) {
        ll k;
        cin >> k;
        for(int _ = 0; _ < k; ++_) {
            int t;
            cin >> t;
            tree.emplace(f, t);
            tree.emplace(t, f);
        }
    }

    auto lca = LowestCommonAncestor(n, tree, 0);

    int q;
    cin >> q;
    for(int _ = 0; _ < q; ++_) {
        int u, v;
        cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }
}