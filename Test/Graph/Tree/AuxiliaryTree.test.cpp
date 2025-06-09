#define PROBLEM "https://yukicoder.me/problems/no/901"

#include "../../../Library/Graph/Tree/AuxiliaryTree.hpp"

#include <iostream>
#include <ranges>

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;
  mtd::Graph tree(n);
  for (auto _ : std::views::iota(0, n - 1)) {
    int f, t, c;
    std::cin >> f >> t >> c;
    tree.addEdge(f, t, c);
  }

  auto at = mtd::AuxiliaryTree(tree);

  int q;
  std::cin >> q;
  for ([[maybe_unused]] auto _ : std::views::iota(0, q)) {
    int k;
    std::cin >> k;
    std::vector<int> v(k);
    for (auto i : std::views::iota(0, k)) { std::cin >> v[i]; }

    auto comp_tree = at.compression(v);

    long long ans = 0;
    for (const auto& [f, t, c] : comp_tree.getEdges())
      if (f < t) { ans += c; }

    std::cout << ans << "\n";
  }
}
