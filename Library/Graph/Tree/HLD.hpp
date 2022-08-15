#pragma once

#include <unordered_map>
#include <queue>
#include <stack>

class HLD {

    using node_t = int;
    using Graph_f = std::unordered_multimap<node_t, node_t>;
    using Graph = std::unordered_map<node_t, std::deque<node_t>>;

    const node_t m_n;
    const Graph m_tree;
    const std::vector<node_t> m_height;
    const std::vector<std::pair<node_t, node_t>> m_root_par;
    const std::vector<node_t> m_ids;

    static auto constructGraph(node_t n, const Graph_f& tree) {
        std::deque<std::pair<node_t, node_t>> order;
        std::vector<node_t> used(n);
        std::stack<std::pair<node_t, node_t>> stk;
        stk.emplace(0, -1); used[0] = true;
        while(!stk.empty()) {
            auto [f, p] = stk.top();
            order.emplace_front(f, p);
            stk.pop();
            auto range = tree.equal_range(f);
            for(auto itr = range.first; itr != range.second; ++itr) {
                auto t = itr->second;
                if(!used[t]) {
                    used[t] = true;
                    stk.emplace(t, f);
                }
            }
        }

        std::vector<node_t> size(n, 1);
        Graph hld_tree;
        for(const auto& [f, p] : order) {
            auto range = tree.equal_range(f);
            node_t size_sum = 1;
            node_t size_max = 0;
            std::deque<node_t> to_list;
            for(auto itr = range.first; itr != range.second; ++itr) {
                auto t = itr->second;
                if(t == p) { continue; }
                if(size[t] > size_max) {
                    size_max = size[t];
                    to_list.emplace_back(t);
                } else {
                    to_list.emplace_front(t);
                }
                size_sum += size[t];
            }
            if(!to_list.empty()) {
                hld_tree.emplace(f, to_list);
            }
            size[f] = size_sum;
        }
        return hld_tree;
    }
    static auto constructRootPar(node_t n, const Graph& tree) {
        std::vector<std::pair<node_t, node_t>> root_par(n);
        std::stack<std::tuple<node_t, node_t, node_t>> stk;
        stk.emplace(0, 0, -1);
        while(!stk.empty()) {
            auto [f, root, par] = stk.top();
            stk.pop();

            if(tree.find(f) == tree.end()) { root_par[f] = {root,par}; continue; }
            auto itr = tree.at(f).rbegin();
            stk.emplace(*itr, root, par);
            root_par[f] = {root,par};
            for(++itr; itr != tree.at(f).rend(); ++itr) {
                stk.emplace(*itr, *itr, f);
            }
        }
        return root_par;
    }
    static auto constructHeight(node_t n, const Graph& tree) {
        std::vector<node_t> height(n);
        std::queue<node_t> q;
        q.emplace(0);
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            if(tree.find(f) == tree.end()) { continue; }
            for(const auto& t : tree.at(f)) {
                height[t] = height[f] + 1;
                q.emplace(t);
            }
        }
        return height;
    }

    auto constructIds() const {
        std::vector<node_t> ids(m_n);
        node_t val = 0;
        std::stack<node_t> stk;
        stk.emplace(0);
        while(!stk.empty()) {
            auto f = stk.top();
            stk.pop();
            ids[f] = val; ++val;
            if(m_tree.find(f) == m_tree.end()) { continue; }
            for(const auto& t : m_tree.at(f)) { stk.emplace(t); }
        }
        return ids;
    }

public:

    HLD(node_t n, const Graph_f& tree) :
        m_n(n),
        m_tree(constructGraph(n, tree)),
        m_root_par(constructRootPar(n, m_tree)),
        m_height(constructHeight(n, m_tree)),
        m_ids(constructIds()) {
    }
    auto hld_order_vec()const {
        std::vector<node_t> order(m_n);
        for(int i = 0; i < m_n; ++i) { order[m_ids[i]] = i; }
        return order;
    }

    auto get_id(node_t i)const { return m_ids[i]; }

    auto lca(node_t f, node_t t)const {
        do {
            auto [fr, fp] = m_root_par[f];
            auto [tr, tp] = m_root_par[t];
            if(fr == tr) { break; }
            auto fph = (fp > -1) ? m_height[fp] : -1;
            auto tph = (tp > -1) ? m_height[tp] : -1;
            if(fph < tph) { t = tp; } else { f = fp; }
        } while(true);
        return (m_height[f] < m_height[t]) ? f : t;
    }

    auto range(node_t f, node_t t)const {
        std::deque<std::pair<node_t, node_t>> ret;
        auto add = [&](node_t f, node_t t) {
            auto l = std::min(m_ids[f], m_ids[t]);
            auto r = std::max(m_ids[f], m_ids[t]);
            ret.emplace_back(l, r);
        };
        do {
            auto [fr, fp] = m_root_par[f];
            auto [tr, tp] = m_root_par[t];
            if(fr == tr) { add(f, t); break; }
            auto fph = (fp > -1) ? m_height[fp] : -1;
            auto tph = (tp > -1) ? m_height[tp] : -1;
            if(fph < tph) { add(t, tr); t = tp; } else { add(f, fr); f = fp; }
        } while(true);
        return ret;
    }
};