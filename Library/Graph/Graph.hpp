#pragma once
#include <vector>
#include <type_traits>

template<class Node = int, class Cost = long long>
class Graph {
    //using Node = int;
    //using Cost = long long;
    using Edges = std::vector<std::pair<Node, Cost>>;

    const int m_n;
    std::vector<Edges> m_graph;

public:
    Graph(int n) :m_n(n), m_graph(n) {}

    auto addEdge(const Node& f, const Node& t, const Cost& c = 1) {
        m_graph[f].emplace_back(t, c);
    }
    auto addEdgeUndirected(const Node& f, const Node& t, const Cost& c = 1) {
        addEdge(f, t, c); addEdge(t, f, c);
    }
    auto getEdges(const Node& from)const {
        class EdgesRange {
            const typename Edges::const_iterator b, e;
        public:
            EdgesRange(const Edges& edges) :b(edges.begin()), e(edges.end()) {}
            auto begin()const { return b; }
            auto end()const { return e; }
        };
        return EdgesRange(m_graph[from]);
    }
    auto size()const { return m_n; };
};