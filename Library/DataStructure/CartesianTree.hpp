#pragma once

#include <vector>
#include <stack>

class CartesianTree {
    using T = int;

    const int m_n;
    const std::vector<int> m_par;

    static auto constructTree(const std::vector<T>& a) {
        int n = (int)a.size();
        std::vector<int> par(n, -1);
        std::stack<int> stk;
        for(int i = 0; i < n; i++) {
            int prv = -1;
            while(!stk.empty() && a[i] < a[stk.top()]) {
                prv = stk.top();
                stk.pop();
            }
            if(prv != -1) { par[prv] = i; }
            if(!stk.empty()) { par[i] = stk.top(); }
            stk.emplace(i);
        }
        return par;
    }
public:
    CartesianTree(const std::vector<T>& a) :m_n(a.size()), m_par(constructTree(a)) {}

    auto p(int f)const { return m_par[f]; }

    auto getEdges()const {
        std::vector<std::pair<int, int>> edges;
        edges.reserve(m_n);
        for(int f = 0; f < m_n; ++f) if(m_par[f] > -1) {
            edges.emplace_back(f, m_par[f]);
        }
        return edges;
    }
};