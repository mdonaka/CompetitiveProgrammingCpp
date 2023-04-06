#define PROBLEM "https://yukicoder.me/problems/no/67"

#include <iostream>
#include <iomanip>
#include <vector>
#include "./../../Library/Search/binarySearch.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    ll n;
    cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; ++i) { cin >> a[i]; }
    ll k;
    cin >> k;

    auto ans = binarySearch(1e-9, 1e9, 100, [&](double mid) {
        ll count = 0;
        for(const auto& x : a) {
            count += (1.0 * x / mid);
        }
        return count >= k;
    }, true);

    cout << std::fixed << std::setprecision(12) << ans << endl;
}
