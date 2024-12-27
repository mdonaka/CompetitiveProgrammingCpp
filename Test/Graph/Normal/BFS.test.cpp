#define PROBLEM "https://yukicoder.me/problems/no/1473"

#include <iostream>
#include <vector>

// begin:tag includes
#include "./../../../Library/Algorithms/BinarySearch.hpp"
#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Normal/BFS.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;
  auto graph_all = mtd::Graph(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d;
    std::cin >> s >> t >> d;
    graph_all.addEdgeUndirected(s - 1, t - 1, d);
  }

  auto solve = [&](int w) {
    auto graph = mtd::Graph(n);
    for (const auto& [s, t, d] : graph_all.getEdges()) {
      if (w <= d) { graph.addEdge(s, t); }
    }

    std::vector<int> dv(n);
    bfs(graph, 0, [&](int f, int t, auto) { dv[t] = dv[f] + 1; });
    return dv[n - 1];
  };

  auto w_max = mtd::binarySearch(0, static_cast<int>(1e9) + 1, [&](int w) {
    auto d = solve(w);
    return d > 0;
  });

  auto ans = solve(w_max);
  std::cout << w_max << " " << ans << std::endl;
}
