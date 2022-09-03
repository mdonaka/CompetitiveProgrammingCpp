
#include <iostream>
#include "./../../Library/Container/Accumulation2D.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    int n;
    cin >> n;

    constexpr ll size = 5;//3e3 + 1;

    std::vector<ll> rv; rv.reserve(n);
    for(int _ = 0; _ < n; ++_) { int r; cin >> r; rv.emplace_back(r); }
    std::vector<ll> gc(size), bc(size);
    for(int _ = 0; _ < n; ++_) { int b; cin >> b; ++bc[b]; }
    for(int _ = 0; _ < n; ++_) { int g; cin >> g; ++gc[g]; }

    std::vector<std::vector<ll>> table(size, std::vector<ll>(2 * size));
    for(int i = 0; i < size; ++i)for(int j = 0; j < size; ++j) {
        table[std::max(i, j)][i + j] += gc[i] * bc[j];
    }
    auto acc = Accumulation2D(table);

    ll ans = 0;
    for(const auto& r : rv) {
        ans += acc.get(0, r + 1, r, 2 * size - 1);
    }
    cout << ans << endl;
}