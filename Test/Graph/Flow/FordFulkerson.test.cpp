#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include <iostream>
#include "./../../../Library/Graph/Flow/FordFulkerson.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
template<class T, class S = T>
using P = std::pair<T, S>;


signed main() {
    int n, m;
    cin >> n >> m;
    std::unordered_multimap<int, P<int, ll>> graph;
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.emplace(u, P<int>{v, c});
    }

    auto mf = FordFulkerson(n, graph);

    cout << mf.max_flow(0, n - 1) << endl;
}