#pragma once

#include <queue>
#include "./../Graph.hpp"
#include "./../../DataStructure/UnionFind.hpp"

template<class Node, class Cost>
auto kruskal(const Graph<Node, Cost>& graph) {
    auto n = graph.size();
    auto min_spanning_tree = Graph(n);

    auto dsu = UnionFind(n);
    using Type = std::pair<Cost, std::pair<Node, Node>>;
    std::priority_queue<Type, std::vector<Type>, std::greater<Type>> q;
    for(const auto& [f, t, c] : graph.getEdges()) {
        q.emplace(c, std::make_pair(f, t));
    }

    while(!q.empty()) {
        auto [cost, ft] = q.top();
        auto [from, to] = ft;
        q.pop();
        if(dsu.isSame(from, to)) { continue; }
        dsu.unite(from, to);
        min_spanning_tree.addEdgeUndirected(from, to, cost);
    }

    return min_spanning_tree;
}
