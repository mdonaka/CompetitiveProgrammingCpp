#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include <iostream>
#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Flow/FordFulkerson.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';


signed main() {
    int n, m;
    cin >> n >> m;
    auto graph = Graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.addEdge(u, v, c);
    }

    auto mf = FordFulkerson(graph);

    cout << mf.max_flow(0, n - 1) << endl;
}