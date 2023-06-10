#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include <iostream>
#include "./../../../Library/Graph/Normal/WarshallFloyd.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
template<class T, class S = T>
using P = std::pair<T, S>;

signed main() {
    int n, m;
    cin >> n >> m;
    auto graph = Graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.addEdge(u, v, c);
    }

    auto min_cost = warshallFloyd(n, graph);

    for(int k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int t = 0; t < n; ++t) {
        if(min_cost[f][t] > min_cost[f][k] + min_cost[k][t]) {
            cout << "NEGATIVE CYCLE" << endl; return 0;
        }
    }

    for(const auto r : min_cost) {
        for(auto itr = r.begin(); itr != r.end(); ++itr) {
            if(*itr > 1e17) {
                cout << "INF";
            } else {
                cout << *itr;
            }
            if(itr != std::prev(r.end())) { cout << " "; }
        }
        cout << endl;
    }
}