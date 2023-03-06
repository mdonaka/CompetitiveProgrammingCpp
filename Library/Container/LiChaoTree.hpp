#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>

class LiChaoTree {
    using T = long long;
    using Line = std::pair<T, T>;
    constexpr static T mx = 1e18;

    int m_size;
    std::vector<T> m_x;
    std::vector<Line> m_node;
    std::unordered_map<T, T> m_xtoi;

    static inline int calcSize(int n) { int size = 1; while(size < n) { size <<= 1; }return size; }
    auto f(const Line& line, const T& x)const { return (x == mx) ? mx : line.first * x + line.second; }

    auto add(const Line& line_, int k, int l, int r) {
        auto line = line_;
        if(l + 1 == r) {
            if(f(line, m_x[l]) < f(m_node[k], m_x[l])) { m_node[k] = line; }
            return;
        }
        if(m_node[k].second == mx) { m_node[k] = line; return; }

        auto m = (l + r) >> 1;
        auto r_ = std::min(r, static_cast<int>(m_xtoi.size()) - 1);
        auto m_ = std::min(m - 1, r_);
        auto left = f(line, m_x[l]) < f(m_node[k], m_x[l]);
        auto mid = f(line, m_x[m_]) < f(m_node[k], m_x[m_]);
        auto right = f(line, m_x[r_]) < f(m_node[k], m_x[r_]);

        if(left && right) { m_node[k] = line; return; }
        if(!left && !right) { return; }
        if(mid) { std::swap(m_node[k], line); }
        if(left ^ mid) {
            add(line, (k << 1) + 1, l, m);
        } else {
            add(line, (k << 1) + 2, m, r);
        }
    }

public:
    LiChaoTree(const std::vector<T>& x_) {
        auto x = x_;
        std::sort(x.begin(), x.end());
        x.erase(std::unique(x.begin(), x.end()), x.end());

        m_size = calcSize(x.size());
        m_x = decltype(m_x)(m_size, mx);
        m_node = decltype(m_node)((m_size << 1) - 1, {0,mx});
        for(size_t i = 0; i < x.size(); ++i) {
            m_x[i] = x[i];
            m_xtoi.emplace(x[i], i);
        }
    }

    auto add(const Line& line) { add(line, 0, 0, m_size); }
    auto add(const T& a, const T& b) { add({a,b}); }

    auto query(const T& x) {
        auto k = m_xtoi[x] + m_size - 1;
        auto ret = mx;
        while(k >= 0) {
            ret = std::min(ret, f(m_node[k], x));
            k = (k - 1) >> 1;
        }
        return ret;
    }
};