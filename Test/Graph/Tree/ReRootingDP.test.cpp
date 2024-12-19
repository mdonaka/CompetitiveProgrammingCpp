#define PROBLEM "https://yukicoder.me/problems/no/2780"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// begin:tag includes
#include "../../../Library/Graph/Tree/ReRootingDP.hpp"
// end:tag includes

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  auto graph = mtd::Graph<>(n);
  for (auto u : std::views::iota(0, n - 1)) {
    int s, t, w;
    std::cin >> s >> t >> w;
    graph.addEdgeUndirected(s, t, w);
  }

  auto op = [](int a, int b) { return std::max(a, b); };
  using M = mtd::Monoid<int, 0, decltype(op)>;

  auto edge_f = [](const M& m, int f, int t, int c) { return M(m.m_val + c); };
  auto node_f = [](const M& m, int i) { return m; };
  auto dp = mtd::reRootingDP<M>(graph, edge_f, node_f);

  auto ans = std::ranges::max(dp);
  std::cout << ans << std::endl;
}
