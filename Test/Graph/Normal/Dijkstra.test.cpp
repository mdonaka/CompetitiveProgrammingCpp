#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "./../../../Library/Graph/Normal/dijkstra.hpp"

#include <iostream>

#include "./../../../Library/Graph/Graph.hpp"

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n, m, r;
  cin >> n >> m >> r;

  auto graph = Graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph.addEdge(u, v, c);
  }

  auto min_cost = dijkstra(graph, r);

  for (const auto x : min_cost) {
    if (x > 1e17) {
      cout << "INF" << endl;
    } else {
      cout << x << endl;
    }
  }
}