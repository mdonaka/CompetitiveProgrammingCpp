#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>

#include "./../../Library/Utility/ModCalculator.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

auto parse(const std::string s) {
    ll a = 0, b = 0;
    bool isa = true;
    for(unsigned int i = 2; i < s.size() - 1; ++i) {
        if(s[i] == ',') { isa = false; continue; }
        auto& x = ((isa) ? a : b);
        x = 10 * x + (s[i] - '0');
    }
    return std::pair<ll, ll>{a, b};
}

signed main() {
    ll t;
    cin >> t;

    constexpr ll MOD = 1e9 + 7;
    auto calc = ModCalculator(MOD);
    for(int _ = 0; _ < t; ++_) {
        std::string s;
        cin >> s;

        auto [n, k] = parse(s);
        if(s[0] == 'C') {
            auto ans = calc.fact(n)
                * calc.inv(calc.fact(k)) % MOD
                * calc.inv(calc.fact(n - k)) % MOD;
            cout << ans << endl;
        } else if(s[0] == 'P') {
            auto ans = calc.fact(n)
                * calc.inv(calc.fact(n - k)) % MOD;
            cout << ans << endl;
        } else {
            cout << calc.comb(std::max(0LL, n + k - 1), k) << endl;
        }
    }
}