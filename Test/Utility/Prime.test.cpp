#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include <iostream>
#include <algorithm>

#include "./../../Library/Utility/Prime.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';


signed main() {
    ll n;
    cin >> n;

    auto prime = Prime(1e5);
    auto fc = prime.factorization(n);

    std::vector<ll> ans;
    for(const auto& [x, c] : fc)for(int i = 0; i < c; ++i) {
        ans.emplace_back(x);
    }
    std::sort(ans.begin(), ans.end());

    cout << n << ": ";
    for(unsigned int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 < ans.size() ? " " : "");
    }
}