#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

// begin:tag includes
#include "../../../Library/Graph/Normal/StronglyConnectedComponents.hpp"

#include "../../../Library/Graph/Graph.hpp"
#include "../../../Library/Range/istream.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [n, m] = mtd::io::in<int, int>();
  auto graph = mtd::Graph(n);
  for (auto [f, t] : mtd::views::istream<int, int>(m)) { graph.addEdge(f, t); }

  auto scc = mtd::StronglyConnectedComponents(std::move(graph));

  auto [q] = mtd::io::in<int>();
  for (auto [u, v] : mtd::views::istream<int, int>(q)) {
    std::cout << scc.isSameGroup(u, v) << std::endl;
  }
}
