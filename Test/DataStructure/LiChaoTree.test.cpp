#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "./../../Library/DataStructure/LiChaoTree.hpp"

#include <deque>
#include <iostream>
#include <vector>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

struct Query {
  int k;
  ll a, b;
  Query(int k, ll a, ll b) : k(k), a(a), b(b) {}
  Query(int k, ll x) : Query(k, x, 0) {}
};

signed main() {
  ll n, q;
  cin >> n >> q;
  std::vector<std::pair<ll, ll>> v;
  v.reserve(n);
  for (int _ = 0; _ < n; ++_) {
    ll a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }
  std::vector<Query> queries;
  queries.reserve(q);
  std::vector<ll> xs;
  xs.reserve(q);
  for (int _ = 0; _ < q; ++_) {
    ll k;
    cin >> k;
    if (k == 0) {
      ll a, b;
      cin >> a >> b;
      queries.emplace_back(k, a, b);
    } else {
      ll x;
      cin >> x;
      queries.emplace_back(k, x);
      xs.emplace_back(x);
    }
  }

  auto lct = LiChaoTree(xs);
  for (const auto& [a, b] : v) { lct.addLine(a, b); }

  for (const auto& query : queries) {
    if (query.k == 0) {
      lct.addLine(query.a, query.b);
    } else {
      cout << lct.query(query.a) << endl;
    }
  }
}
