#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include <iostream>
#include "./../../../Library/Graph/Normal/dijkstra.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
template<class T, class S = T>
using P = std::pair<T, S>;

signed main() {
    int n, m, r;
    cin >> n >> m >> r;
    std::unordered_multimap<int, P<int, ll>> graph;
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.emplace(u, P<int>{v, c});
    }

    auto min_cost = dijkstra(n, graph, r);

    for(const auto x : min_cost) {
        if(x > 1e17) {
            cout << "INF" << endl;
        } else {
            cout << x << endl;
        }
    }
}