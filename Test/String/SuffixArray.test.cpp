#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D"

#include <iostream>

#include "./../../Library/String/SuffixArray.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    std::string s;
    ll n;
    cin >> s >> n;
    std::vector<std::string> vt;
    vt.reserve(n);
    for(int _ = 0; _ < n; ++_) {
        std::string t;
        cin >> t;
        vt.emplace_back(t);
    }

    auto sa = SuffixArray(s);

    for(const auto& t : vt) {
        auto [l, r] = sa.findPattern(t);
        cout << ((r - l) > 0) << endl;
    }
}