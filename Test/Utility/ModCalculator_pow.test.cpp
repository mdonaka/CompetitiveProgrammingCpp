#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include <iostream>
#include <string>

#include "./../../Library/Utility/ModCalculator.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    ll m, n;
    cin >> m >> n;

    auto calc = ModCalculator(1e9 + 7);

    cout << calc.pow(m, n) << endl;
}