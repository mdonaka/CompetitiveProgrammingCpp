#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B"

#include <iostream>

// begin:tag includes
#include "./../../../Library/Graph/Tree/EulerTour.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  auto tree = mtd::Graph<>(n);
  for ([[maybe_unused]] auto _ : std::views::iota(0, n)) {
    int u, k;
    std::cin >> u >> k;
    for ([[maybe_unused]] auto __ : std::views::iota(0, k)) {
      int v;
      std::cin >> v;
      tree.addEdgeUndirected(u - 1, v - 1);
    }
  }

  auto et = mtd::EulerTour(tree);
  for (auto i : std::views::iota(0, n)) {
    auto [d, f] = et.range(i);
    std::cout << i + 1 << " " << d + 1 << " " << f + 1 << std::endl;
  }
}
