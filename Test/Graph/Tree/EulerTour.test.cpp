#define PROBLEM "https://yukicoder.me/problems/no/1637"

#include <iostream>

// begin:tag includes
#include "./../../../Library/Graph/Tree/EulerTour.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;
  auto tree = mtd::Graph<>(n);
  for ([[maybe_unused]] auto _ : std::views::iota(0, n - 1)) {
    int a, b;
    std::cin >> a >> b;
    tree.addEdge(a - 1, b - 1);
  }

  auto et = mtd::EulerTour(tree);
  std::vector<int> size(n);
  for (auto i : std::views::iota(0, n)) {
    auto [l, r] = et.range(i);
    size[i] = (r - l + 1) / 2;
  }

  long long ans = 0;
  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {
    int p;
    long long x;
    std::cin >> p >> x;
    ans += x * size[p - 1];
    std::cout << ans << std::endl;
  }
}
