#define PROBLEM "https://atcoder.jp/contests/abc156/tasks/abc156_d"

#include <iostream>
#include <string>

#include "./../../Library/Utility/ModCalculator.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

constexpr ll mod = 1e9 + 7;

signed main() {
    ll n, a, b;
    cin >> n >> a >> b;

    auto calc = ModCalculator(mod);
    auto comb = [&](ll n, ll r) {
        ll u = 1, d = 1;
        for(int i = 0; i < r; ++i) {
            (u *= (n - i)) %= mod;
            (d *= (i + 1)) %= mod;
        }
        return u * calc.inv(d) % mod;
    };

    auto ans = calc.pow(2, n) - 1 - comb(n, a) - comb(n, b);
    ans = (ans + 3 * mod) % mod;
    cout << ans << endl;
}