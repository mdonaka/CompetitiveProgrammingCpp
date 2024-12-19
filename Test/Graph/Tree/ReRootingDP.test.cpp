#include <vector>
#define PROBLEM "https://yukicoder.me/problems/no/2360"

#include <iostream>

// begin:tag includes
#include "../../../Library/Graph/Tree/ReRootingDP.hpp"
#include "../../../Library/Math/ModInt.hpp"
// end:tag includes

using ll = long long;
constexpr ll MOD = 998244353;
using mint = mtd::ModInt<MOD>;
auto math = mtd::Math<mint>();

struct S {
  mint m;
  ll s;
  constexpr S(const mint& m, const ll s) : m(m), s(s) {}
  constexpr S() : S(0, 0) {}
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  ll n;
  std::cin >> n;
  std::vector<ll> a(n);
  for (auto i : std::views::iota(0, n)) { std::cin >> a[i]; }
  auto graph = mtd::Graph<>(n);
  for ([[maybe_unused]] auto _ : std::views::iota(0, n - 1)) {
    int u, v;
    std::cin >> u >> v;
    graph.addEdgeUndirected(u - 1, v - 1);
  }

  std::vector<mint> at;
  for (auto x : a) {
    auto size = std::to_string(x).size();
    at.emplace_back(math.pow(10, size));
  }

  auto op = [](const S& a, const S& b) { return S(a.m + b.m, a.s + b.s); };
  using M = mtd::Monoid<S, S(0, 0), decltype(op)>;

  auto edge_f = [&](const M& m, int f, int t, int c) {
    return M(S(m.m_val.m * at[t] + m.m_val.s * a[t], m.m_val.s));
  };
  auto node_f = [&](const M& m, int i) {
    return M(S(m.m_val.m + a[i], m.m_val.s + 1));
  };
  auto dp = mtd::reRootingDP<M>(graph, edge_f, node_f);

  mint ans = 0;
  for (auto x : dp) { ans += x.m; }
  std::cout << ans << std::endl;
}
