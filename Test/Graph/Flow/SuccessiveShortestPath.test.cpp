#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include <iostream>
#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Flow/SuccessiveShortestPath.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';


signed main() {
    int n, m, f;
    cin >> n >> m >> f;
    auto graph = Graph<int, std::pair<ll, ll>>(n);
    for(int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph.addEdge(u, v, std::make_pair(c, d));
    }

    auto mcf = SuccessiveShortestPath(graph);

    auto [u, c] = mcf.min_cost_max_flow(0, n - 1, f);
    cout << ((u == f) ? c : -1) << endl;
}