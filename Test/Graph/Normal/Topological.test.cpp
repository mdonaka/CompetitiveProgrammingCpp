#include <vector>
#define PROBLEM "https://yukicoder.me/problems/no/2780"
#include <iostream>

// begin:tag includes
#include "../../../Library/Graph/Normal/StronglyConnectedComponents.hpp"
#include "../../../Library/Graph/Normal/Topological.hpp"
// end:tag includes

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  auto graph = mtd::Graph<>(n);
  for (auto u : std::views::iota(0, n)) {
    int m;
    std::cin >> m;
    for ([[maybe_unused]] auto _ : std::views::iota(0, m)) {
      int v;
      std::cin >> v;
      graph.addEdge(u, v - 1);
    }
  }

  auto scc = mtd::StronglyConnectedComponents(std::move(graph));
  auto scc_graph = scc.getGroupGraph();
  auto size = scc.size();
  std::vector<int> dp(size);
  dp[scc.group(0)] = true;
  for (auto u : mtd::topological_order(scc_graph)) {
    for (auto [v, _] : scc_graph.getEdges(u)) { dp[v] |= dp[u]; }
  }

  auto yes = std::ranges::all_of(dp, [](int x) { return x; });
  std::cout << (yes ? "Yes" : "No") << std::endl;
}
