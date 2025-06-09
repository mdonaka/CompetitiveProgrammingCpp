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
      graph.addArc(u, v - 1);
    }
  }

  auto scc = mtd::StronglyConnectedComponents(std::move(graph));
  auto scc_graph = scc.getGroupGraph();
  auto scc_nodes = scc.getGroupNodes();

  int now = -1;
  bool yes = true;
  for (auto u : mtd::topological_order(scc_graph)) {
    bool ex = (now == -1 ? u == scc.group(0) : false);
    if (now > -1) {
      for (auto [v, _] : scc_graph.getEdges(now)) { ex |= (u == v); }
    }
    yes &= ex;
    now = u;
  }

  std::cout << (yes ? "Yes" : "No") << std::endl;
}
