#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

// begin:tag includes
#include "../../../Library/Graph/Normal/Topological.hpp"

#include "../../../Library/Range/istream.hpp"
// end:tag includes

#include <iostream>
#include <string>

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [v, e] = mtd::io::in<int, int>();
  auto graph = mtd::Graph<>(v);
  for (auto [s, t] : mtd::views::istream<int, int>(e)) { graph.addEdge(s, t); }

  auto order = mtd::topological_order(graph);
  for (auto x : order) { std::cout << x << std::endl; }
}
