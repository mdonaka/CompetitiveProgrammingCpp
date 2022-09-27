#pragma once
#include <unordered_map>
#include <queue>
#include <vector>

std::vector<long long> dijkstra(int n, const std::unordered_multimap<int, std::pair<int, long long>>& graph, int begin) {
    std::vector<long long> cost(n, 1e18);
    cost[begin] = 0;
    using P = std::pair<long long, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    q.emplace(0, begin);
    while(!q.empty()) {
        auto [nowCost, from] = q.top();
        q.pop();
        if(cost[from] < nowCost) { continue; }
        auto range = graph.equal_range(from);
        for(auto itr = range.first; itr != range.second; ++itr) {
            auto [to, c] = itr->second;
            if(nowCost + c < cost[to]) {
                cost[to] = nowCost + c;
                q.emplace(cost[to], to);
            }
        }
    }
    return cost;
}