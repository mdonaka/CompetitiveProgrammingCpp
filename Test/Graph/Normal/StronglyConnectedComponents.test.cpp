#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"

#include <iostream>
#include "./../../../Library/Graph/Normal/StronglyConnectedComponents.hpp"
#include "./../../../Library/Graph/Graph.hpp"
using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';


signed main() {
    int n, m;
    cin >> n >> m;
    auto graph = Graph(n);
    for(int _ = 0; _ < m; ++_) {
        int f, t;
        cin >> f >> t;
        graph.addEdge(f, t);
    }

    auto scc = StronglyConnectedComponents(std::move(graph));

    int q;
    cin >> q;
    for(int _ = 0; _ < q; ++_) {
        int u, v;
        cin >> u >> v;
        cout << scc.isSameGroup(u, v) << endl;
    }
}