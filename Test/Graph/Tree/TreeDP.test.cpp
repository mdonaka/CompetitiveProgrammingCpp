#define PROBLEM "https://yukicoder.me/problems/no/763"

#include <iostream>
#include <queue>
#include <vector>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Tree/TreeDP.hpp"

signed main() {
  ll n;
  cin >> n;
  mtd::Graph<int, bool> tree(n);
  for (int f = 0; f < n - 1; ++f) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    tree.addEdgeUndirected(u, v);
  }

  std::vector<int> dp1(n);
  std::vector<int> dp2(n, 1);
  mtd::treeDP(tree, 0, [&](int f, int t) {
    dp1[t] += std::max(dp1[f], dp2[f]);
    dp2[t] += std::max(dp1[f], dp2[f] - 1);
  });

  auto ans = std::max(dp1[0], dp2[0]);
  cout << ans << endl;
}
