#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <map>
#include "./../../Library/Container/DisjointSparseTable.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

struct Functor { auto operator()(int a, int b)const { return std::min(a, b); } };

signed main() {
    ll n, q;
    cin >> n >> q;
    std::vector<int> a; a.reserve(n);
    for(int i = 0; i < n; ++i) { int x; cin >> x; a.emplace_back(x); }

    using SG = SemiGroup<int, Functor>;
    auto dst = DisjointSparseTable<SG>(n, a);
    for(int _ = 0; _ < q; ++_) {
        ll l, r;
        cin >> l >> r;
        cout << dst.get(l, r - 1) << endl;
    }
}