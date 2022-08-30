#define PROBLEM "https://yukicoder.me/problems/no/1456"

#include <iostream>
#include <unordered_set>

#include "./../../Library/Container/Accumulation.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

struct F_inv { auto operator()(ll x) { return x; } };
struct F_xor { auto operator()(ll x, ll y) { return x ^ y; } };
using G = Group<ll, 0, F_xor, F_inv>;

signed main() {
    ll n, k;
    cin >> n >> k;

    std::vector<ll> a; a.reserve(n);
    for(int _ = 0; _ < n; ++_) {
        ll x; cin >> x;
        a.emplace_back(x);
    }

    auto acc = Accumulation<G>(a);
    std::unordered_set<ll> st;
    for(int i = 0; i < n; ++i) {
        st.emplace(acc.get(i) ^ k);
    }

    if(st.find(0) != st.end()) { cout << "Yes" << endl; return 0; }
    for(int i = 0; i < n; ++i) {
        if(st.find(acc.get(i)) != st.end()) { cout << "Yes" << endl; return 0; }
    }
    cout << "No" << endl;
}