#define PROBLEM "https://yukicoder.me/problems/no/1473"

#include <iostream>
#include <vector>

#include "./../../../Library/Graph/Graph.hpp"
#include "./../../../Library/Graph/Normal/BFS.hpp"
#include "./../../../Library/Algorithms/binarySearch.hpp"

using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';

signed main() {
    ll n, m;
    cin >> n >> m;
    auto graph_all = Graph(n);
    for(int i = 0; i < m; ++i) {
        ll s, t, d;
        cin >> s >> t >> d;
        graph_all.addEdgeUndirected(s - 1, t - 1, d);
    }

    auto solve = [&](ll w) {
        auto graph = Graph(n);
        for(const auto& [s, td] : graph_all.getEdgesAll()) {
            auto [t, d] = td;
            if(w <= d) { graph.addEdge(s, t); }
        }

        std::vector<int> dv(n);
        bfs(graph, 0, [&](ll f, ll t) {dv[t] = dv[f] + 1; });
        return dv[n - 1];
    };

    auto w_max = binarySearch(0, 1e9, [&](ll w) {
        auto d = solve(w);
        return d > 0;
    }, true);

    auto ans = solve(w_max);
    cout << w_max << " " << ans << endl;
}
