#pragma once

#include <vector>
#include <stack>
#include <queue>
#include <numeric>

template <class T>
class CartesianTree {
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

    auto range()const {
        std::vector<int> left(m_n), right(m_n);
        std::iota(left.begin(), left.end(), 0);
        std::iota(right.begin(), right.end(), 0);
        std::vector<int> in(m_n);
        for(int f = 0; f < m_n; ++f) if(m_par[f] > -1) { ++in[m_par[f]]; }
        std::queue<int> q;
        for(int f = 0; f < m_n; ++f) if(in[f] == 0) { q.emplace(f); }
        while(!q.empty()) {
            auto f = q.front(); q.pop();
            if(m_par[f] == -1) { continue; }
            left[m_par[f]] = std::min(left[f], left[m_par[f]]);
            right[m_par[f]] = std::max(right[f], right[m_par[f]]);
            --in[m_par[f]];
            if(in[m_par[f]] == 0) { q.emplace(m_par[f]); }
        }
        return std::make_pair(left, right);
    }

    auto getEdges()const {
        std::vector<std::pair<int, int>> edges;
        edges.reserve(m_n);
        for(int f = 0; f < m_n; ++f) if(m_par[f] > -1) {
            edges.emplace_back(f, m_par[f]);
        }
        return edges;
    }
};