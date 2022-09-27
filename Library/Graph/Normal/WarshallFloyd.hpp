#pragma once

#include <vector>
#include <unordered_map>

std::vector<std::vector<long long>> warshallFloyd(int n, const std::unordered_multimap<int, std::pair<int, long long>>& graph) {
    std::vector<std::vector<long long>> cost(n, std::vector<long long>(n, 1e18));
    for(const auto& [from, p] : graph) {
        auto [to, c] = p;
        cost[from][to] = c;
    }
    for(int i = 0; i < n; ++i) { cost[i][i] = 0; }
    for(int k = 0; k < n; ++k)for(int f = 0; f < n; ++f)for(int t = 0; t < n; ++t) {
        cost[f][t] = std::min(cost[f][t], cost[f][k] + cost[k][t]);
    }
    return cost;
}