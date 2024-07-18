#define PROBLEM "https://yukicoder.me/problems/no/1882"

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

#include "./../../Library/Algorithms/BinarySearch.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    ll n, x;
    cin >> n >> x;
    std::vector<ll> a(n);
    for(int i = 0; i < n; ++i) { cin >> a[i]; }
    std::ranges::sort(a);

    ll ans = 0;
    for(const auto& val : a) {
        auto idx = binarySearch(n, -1, [&](ll mid) {
            return val * a[mid] >= (x << 1);
        });
        ans += n - idx;
    }

    cout << ans << endl;
}
