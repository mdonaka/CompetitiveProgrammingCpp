#define PROBLEM "https://yukicoder.me/problems/no/273"

#include <iostream>
#include <algorithm>
#include "./../../Library/String/PalindromicTree.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    std::string s;
    cin >> s;

    auto p = PalindromicTree(s);

    ll ans = 0;
    p.dfs_edges([&](ll size, const auto& _) {
        if(size < s.size()) { ans = std::max(ans, size); }
    });
    cout << ans << endl;
}