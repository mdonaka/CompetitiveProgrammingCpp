#pragma once
#include <vector> 
#include <queue>

#include "./../Graph.hpp"

template<class Node, class Cost, class Lambda>
auto treeDP(const Graph<Node, Cost>& tree, Node root, const Lambda& lambda) {
    auto n = tree.size();
    std::vector<Node> in(n);
    for(const auto& [f, t] : tree.getEdgesAll2()) if(f < t) {
        ++in[f]; ++in[t];
    }
    std::queue<Node> q;
    std::vector<bool> used(n);
    for(Node i = 0; i < n; ++i)if(i != root && in[i] == 1) {
        q.emplace(i);
    }
    while(!q.empty()) {
        auto from = q.front();
        q.pop();
        used[from] = true;

        for(const auto& [to, _] : tree.getEdges(from)) {
            if(used[to]) { continue; }
            lambda(from, to);
            --in[to];
            if(in[to] == 1) { q.emplace(to); }
        }
    }
}
