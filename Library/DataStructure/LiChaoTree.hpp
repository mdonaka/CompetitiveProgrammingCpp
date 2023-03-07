#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>

class LiChaoTree {
    using T = long long;
    using Line = std::pair<T, T>;
    constexpr static T INF = std::numeric_limits< T >::max() / 2;

    int m_size;
    std::vector<T> m_x;
    std::vector<Line> m_node;
    std::unordered_map<T, T> m_xtoi;

    static inline int calcSize(int n) { int size = 1; while(size < n) { size <<= 1; }return size; }
    auto f(const Line& line, const T& x)const { return line.first * x + line.second; }

    auto add(const Line& line_, int k, int l, int r) {
        auto line = line_;

        auto m = (l + r) / 2;
        if(f(line, m_x[m]) < f(m_node[k], m_x[m])) { std::swap(line, m_node[k]); }
        if(l + 1 == r) { return; }
        if(line.first > m_node[k].first) {
            add(line, (k << 1) + 1, l, m);
        } else if(line.first < m_node[k].first) {
            add(line, (k << 1) + 2, m, r);
        }
    }

public:
    LiChaoTree(const std::vector<T>& x_) :m_size(calcSize(x_.size())) {
        auto x = x_;
        std::sort(x.begin(), x.end());
        x.erase(std::unique(x.begin(), x.end()), x.end());
        m_x = decltype(m_x)(m_size);
        for(size_t i = 0; i < x.size(); ++i) {
            m_x[i] = x[i];
            m_xtoi.emplace(x[i], i);
        }
        for(size_t i = x.size(); i < m_size; ++i) { m_x[i] = m_x[i - 1] + 1; }
        m_node = decltype(m_node)(m_size << 1, {0,INF});
    }

    auto add(const Line& line) { add(line, 0, 0, m_size); }
    auto add(const T& a, const T& b) { add({a,b}); }

    auto query(const T& x) {
        auto k = m_xtoi[x] + m_size;
        auto ret = INF;
        while(k > 0) {
            ret = std::min(ret, f(m_node[k - 1], x));
            k >>= 1;
        }
        return ret;
    }
};
