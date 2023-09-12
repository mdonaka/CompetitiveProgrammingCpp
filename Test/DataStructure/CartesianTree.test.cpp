#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <iostream>
#include "./../../Library/DataStructure/CartesianTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    int n;
    cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) { cin >> a[i]; }

    auto ct = CartesianTree(a);
    for(int f = 0; f < n; ++f) {
        int p = ct.p(f);
        cout << (p == -1 ? f : p) << (f < n - 1 ? " " : "");
    }
    cout << endl;
}