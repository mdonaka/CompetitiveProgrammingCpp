#pragma once

#include <limits>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <iostream>

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

// X_MAX: ax+bÇ≈Ç†ÇÈxÇ∆ÇµÇƒéÊÇËÇ§ÇÈç≈ëÂíl
template<long long X_MAX, class T = long long>
class DynamicLiChaoTree {
    constexpr static T INF = 2e18;

    class Line {
        T a, b;
    public:
        Line(const T& a, const T& b) :a(a), b(b) {}
        Line() :Line(0, INF) {}
        Line(const Line& other) noexcept :Line(other.a, other.b) {}
        Line(Line&& other) noexcept :Line(other) {}
        Line& operator=(Line&& other) noexcept {
            if(this != &other) { a = other.a; b = other.b; }
            return *this;
        }
        auto operator<(const Line& line)const { return a < line.a; }
        auto operator>(const Line& line)const { return line.operator<(*this); }

        auto f(const T& x)const { return a * x + b; }
        auto debug()const { std::cerr << "(" << a << " " << b << ")" << std::endl; }
    };

    struct Node {
        Line line;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const Line& line) :line(line) {}
        auto f(const T& x)const { return line.f(x); }
    };

    std::unique_ptr<Node> m_root;

    auto add(std::unique_ptr<Node>& node, Line&& line, long long l, long long r) {
        if(!node) { node = std::make_unique<Node>(line); return; }

        auto m = (l + r) / 2;
        if(line.f(m) < node->f(m)) { std::swap(node->line, line); }
        if(l + 1 == r) { return; }
        if(line > node->line) {
            add(node->left, std::move(line), l, m);
        } else if(line < node->line) {
            add(node->right, std::move(line), m, r);
        }
    }

    auto query(const std::unique_ptr<Node>& node, const T& x, long long l, long long r) const {
        if(!node) { return Line().f(x); }
        auto m = (l + r) / 2;
        return std::min(
            node->f(x),
            (x < m) ? query(node->left, x, l, m) : query(node->right, x, m, r)
        );
    }
public:
    DynamicLiChaoTree() {}

    auto add(const T& a, const T& b) { add(m_root, Line(a, b), -X_MAX, X_MAX); }
    auto add(const std::pair<T, T>& line) { add(line.first, line.second); }
    auto query(const T& x) const { return query(m_root, x, -X_MAX, X_MAX); }

    auto debug(const std::unique_ptr<Node>& node, int size)const {
        if(size == 0) { std::cerr << "-- li chao tree --" << std::endl; }
        if(!node) { return; }
        for(int i = 0; i < size; ++i) { std::cerr << "- "; }
        node->line.debug();
        if(node->left) { std::cout << "L"; debug(node->left, size + 1); }
        if(node->right) { std::cout << "R"; debug(node->right, size + 1); }
    }
    auto debug()const { debug(m_root, 0); }
};
