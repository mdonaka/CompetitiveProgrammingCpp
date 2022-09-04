#define PROBLEM "https://yukicoder.me/problems/no/1390"

#include <iostream>
#include <vector>
#include <deque>

#include "./../../Library/Container/UnionFind.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    ll n, m;
    cin >> n >> m;
    std::vector<std::deque<ll>> cv(n);
    for(int _ = 0; _ < n; ++_) {
        ll b, c;
        cin >> b >> c;
        cv[c - 1].emplace_back(b - 1);
    }

    auto dsu = UnionFind(m);

    ll ans = 0;
    for(const auto& dq : cv) if(!dq.empty()) {
        auto base = dq.front();
        for(const auto& tg : dq) {
            if(!dsu.isSame(base, tg)) {
                dsu.unite(base, tg);
                ++ans;
            }
        }
    }
    cout << ans << endl;
}