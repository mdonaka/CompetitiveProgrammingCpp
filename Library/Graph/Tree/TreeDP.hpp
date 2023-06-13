#pragma once
#include <unordered_map>
#include <queue>

template<class Lambda>
auto treeDP(long long n, const std::unordered_multimap<long long, long long>& graph, long long root, const Lambda& lambda) {
    VL out(n, 0);
    {
        std::queue<ll> q; q.emplace(root);
        while(!q.empty()) {
            auto from = q.front();
            q.pop();

            auto range = graph.equal_range(from);
            REPI2(itr, range.first, range.second) {
                auto to = itr->second;
                if(out[to] == 0) {
                    q.emplace(to);
                    ++out[from];
                }
            }
        }
    }

    {
        std::queue<ll> q;
        V<bool> isUsed(n);
        REP(i, n)if(out[i] == 0) { q.emplace(i); isUsed[i] = true; }
        while(!q.empty()) {
            auto from = q.front();
            q.pop();

            auto range = graph.equal_range(from);
            REPI2(itr, range.first, range.second) {
                auto to = itr->second;

                if(!isUsed[to]) {
                    lambda(from, to);
                }

                --out[to];
                if(out[to] == 0) {
                    q.emplace(to);
                    isUsed[to] = true;
                }
            }
        }
    }
}

// #include "BFSonGraph.hpp"
template<class Lambda>
auto graphBFS(long long n, const std::unordered_multimap<long long, long long>& graph, long long root, const Lambda& lambda) {
    V<bool> isUsed(n, false); isUsed[root] = true;
    std::queue<long long> q; q.emplace(root);
    while(!q.empty()) {
        auto from = q.front();
        q.pop();

        auto range = graph.equal_range(from);
        REPI2(itr, range.first, range.second) {
            auto to = itr->second;
            if(!isUsed[to]) {
                q.emplace(to);
                isUsed[to] = true;
                lambda(from, to);
            }
        }
    }
}

/*
 * 部分木の情報をマージするMonoid
 * edgeの情報を親に流すedge_f(M, f, t)
 * nodeの情報を親に流すnode_f(M, i)
 */
template<class Monoid, class Lambda1, class Lambda2>
auto reRootingDP(long long n,
                 const std::unordered_multimap<long long, long long>& graph,
                 const Lambda1& edge_f,
                 const Lambda2& node_f) {

    constexpr int root = 0;

    // <辺情報を考慮したMonoidの2項演算>
    auto merge = [&](Monoid& m1, const Monoid& m2, ll f = -1, ll t = -1) {
        if(f == -1 && t == -1) { m1 = m1.binaryOperation(m2); return; }
        m1 = m1.binaryOperation(edge_f(m2, f, t));
    };

    // <node:toを根とした木で全てマージした解を求める>
    std::vector<std::deque<pair<int, Monoid>>> partial(n);
    auto all_merge = [&](ll to) {
        Monoid val{};
        for(const auto& [from, ad] : partial[to]) { merge(val, ad, from, to); }
        return node_f(val, to);
    };

    // <node:toを根とした木でfrom以外マージした解を求める>
    std::vector<std::unordered_map<int, Monoid>> partial_ac(n);
    std::vector<Monoid> ret(n);
    auto accumulation = [&](ll to) {
        // 左からマージ
        Monoid val_ord{};
        for(const auto& [from, ad] : partial[to]) {
            partial_ac[to].emplace(from, val_ord);
            merge(val_ord, ad, from, to);
        }
        // 右からマージ
        Monoid val_rord{};
        for(auto rit = partial[to].rbegin(); rit != partial[to].rend(); ++rit) {
            auto [from, ad] = *rit;
            merge(partial_ac[to][from], val_rord);
            merge(val_rord, ad, from, to);
        }
        // node情報を反映させて値を確定
        ret[to] = node_f(val_ord, to);
        for(auto&& [_, pac] : partial_ac[to]) { pac = node_f(pac, to); }
    };

    // rootを根とした解を求める
    treeDP(n, graph, root, [&](ll f, ll t) {
        partial[t].emplace_back(f, all_merge(f));
    });
    accumulation(0);

    // rootからbfsして各nodeを根とした解を求める
    graphBFS(n, graph, root, [&](int f, int t) {
        partial[t].emplace_back(f, partial_ac[f][t]);
        accumulation(t);
    });

    return ret;
}

template<
    class S,   // 要素の型
    // ※C++17ではほとんどの型をグローバル宣言した初期値を参照で渡す必要あり
    S& element, // 元
    class T // 2項演算子．
>
struct Monoid {
    S m_val;
    Monoid() :m_val(element) {}
    Monoid(S val) :m_val(val) {}
    Monoid binaryOperation(const Monoid& m2)const { return T()(m_val, m2.m_val); }
    friend std::ostream& operator<<(std::ostream& os, const Monoid& m) {
        os << m.m_val;
        return os;
    }
};
