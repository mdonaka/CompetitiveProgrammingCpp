#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include <iostream>
#include "./../../../Library/Graph/Flow/SuccessiveShortestPath.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
template<class T, class S = T>
using P = std::pair<T, S>;


signed main() {
    int n, m, f;
    cin >> n >> m >> f;
    std::unordered_multimap<int, P<int, P<ll>>> graph;
    for(int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph.emplace(u, P<int, P<ll>>{v, P<ll>{c, d}});
    }

    auto mcf = SuccessiveShortestPath(n, graph);

    auto [u, c] = mcf.min_cost_max_flow(0, n - 1, f);
    cout << ((u == f) ? c : -1) << endl;
}