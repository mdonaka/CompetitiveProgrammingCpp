#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include <iostream>
#include "./../../Library/DataStructure/LazySegmentTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    int n, q;
    cin >> n >> q;

    std::vector<std::pair<long long, long long>> v(n, {0,1});
    auto segtree = LazySegmentTree<M_S, M_A, OP_RAQ_RSQ>(n, v);

    for(int _ = 0; _ < q; ++_) {
        int k;
        cin >> k;
        if(k == 0) {
            int s, t, x;;
            cin >> s >> t >> x;
            --s; --t;
            segtree.update(s, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            --s; --t;
            cout << segtree.query(s, t).first << endl;
        }
    }
}