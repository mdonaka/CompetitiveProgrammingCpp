#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "./../../../Library/Graph/Normal/Prim.hpp"

#include <iostream>

#include "./../../../Library/Graph/Graph.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n, m;
  cin >> n >> m;

  auto graph = Graph(n);
  for (int i = 0; i < m; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    graph.addEdgeUndirected(s, t, w);
  }

  auto min_spanning_tree = prim(graph);

  ll ans = 0;
  for (const auto& [f, t, c] : min_spanning_tree.getEdges()) {
    if (f < t) { ans += c; }
  }
  cout << ans << endl;
}