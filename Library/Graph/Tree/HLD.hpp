#pragma once

#include <unordered_map>
#include <queue>
#include <stack>

class HLD {

    using node_t = int;
    using Graph_f = std::unordered_multimap<node_t, node_t>;
    using Graph = std::unordered_map<node_t, std::deque<node_t>>;

    const Graph m_tree;
    const std::vector<node_t> m_height;
    const std::vector<std::pair<node_t, node_t>> m_root_par;

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
                    to_list.emplace_front(t);
                } else {
                    to_list.emplace_back(t);
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
            auto itr = tree.at(f).begin();
            stk.emplace(*itr, root, par);
            root_par[f] = {root,par};
            for(++itr; itr != tree.at(f).end(); ++itr) {
                stk.emplace(*itr, *itr, f);
            }
        }
        return root_par;
    }
    static auto construcHeight(node_t n, const Graph& tree) {
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
public:

    HLD(node_t n, const Graph_f& tree) :
        m_tree(constructGraph(n, tree)),
        m_root_par(constructRootPar(n, m_tree)),
        m_height(construcHeight(n, m_tree)) {
    }

    auto getId(node_t n, const Graph& tree) const {
        std::vector<node_t> id(n);
        node_t val = 0;
        std::stack<node_t> stk;
        stk.emplace(0);
        while(!stk.empty()) {
            auto f = stk.top();
            stk.pop();
            id[f] = val; ++val;
            if(tree.find(f) == tree.end()) { continue; }
            for(const auto& t : tree.at(f)) { stk.emplace(t); }
        }
        return id;
    }

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
    }
};
