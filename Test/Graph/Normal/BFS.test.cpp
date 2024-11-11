#define PROBLEM "https://yukicoder.me/problems/no/1473"

#include "./../../../Library/Graph/Normal/BFS.hpp"

#include <iostream>
#include <vector>

#include "./../../../Library/Algorithms/BinarySearch.hpp"
#include "./../../../Library/Graph/Graph.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  ll n, m;
  cin >> n >> m;
  auto graph_all = mtd::Graph(n);
  for (int i = 0; i < m; ++i) {
    ll s, t, d;
    cin >> s >> t >> d;
    graph_all.addEdgeUndirected(s - 1, t - 1, d);
  }

  auto solve = [&](ll w) {
    auto graph = mtd::Graph(n);
    for (const auto& [s, t, d] : graph_all.getEdges()) {
      if (w <= d) { graph.addEdge(s, t); }
    }

    std::vector<int> dv(n);
    bfs(graph, 0, [&](ll f, ll t) { dv[t] = dv[f] + 1; });
    return dv[n - 1];
  };

  auto w_max = mtd::binarySearch(0, 1e9 + 1, [&](ll w) {
    auto d = solve(w);
    return d > 0;
  });

  auto ans = solve(w_max);
  cout << w_max << " " << ans << endl;
}
