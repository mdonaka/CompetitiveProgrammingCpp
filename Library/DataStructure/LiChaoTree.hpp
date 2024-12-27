#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <unordered_map>
#include <vector>

namespace mtd {
  /*
   * クエリ先読みが必要
   * クエリで呼ばれるxと線分の端点を全てコンストラクタに渡す
   */
  class LiChaoTree {
    using T = long long;
    using Line = std::pair<T, T>;
    constexpr static T INF = std::numeric_limits<T>::max() / 2;

    int m_size;
    std::vector<T> m_x;
    std::vector<Line> m_node;
    std::unordered_map<T, T> m_xtoi;

    static inline int calcSize(int n) {
      int size = 1;
      while (size < n) { size <<= 1; }
      return size;
    }
    auto f(const Line& line, const T& x) const {
      return line.first * x + line.second;
    }

    auto addLine(const Line& line_, T k, T l, T r) {
      auto line = line_;

      auto m = (l + r) / 2;
      if (f(line, m_x[m]) < f(m_node[k], m_x[m])) {
        std::swap(line, m_node[k]);
      }
      if (l + 1 == r) { return; }
      if (line.first > m_node[k].first) {
        addLine(line, (k << 1) + 1, l, m);
      } else if (line.first < m_node[k].first) {
        addLine(line, (k << 1) + 2, m, r);
      }
    }

  public:
    LiChaoTree(const std::vector<T>& x_)
        : m_size(calcSize(static_cast<int>(x_.size()))) {
      auto x = x_;
      std::sort(x.begin(), x.end());
      x.erase(std::unique(x.begin(), x.end()), x.end());
      m_x = decltype(m_x)(m_size);
      for (size_t i = 0; i < x.size(); ++i) {
        m_x[i] = x[i];
        m_xtoi.emplace(x[i], i);
      }
      for (int i = static_cast<int>(x.size()); i < m_size; ++i) {
        m_x[i] = m_x[i - 1] + 1;
      }
      m_node = decltype(m_node)(m_size << 1, {0, INF});
    }

    auto addLine(const Line& line) { addLine(line, 0, 0, m_size); }
    auto addLine(const T& a, const T& b) { addLine({a, b}); }
    auto addSegment(const Line& line, const T& l_, const T& r_) {
      auto l = m_xtoi[l_], r = m_xtoi[r_];
      auto lk = l + m_size - 1;
      auto rk = r + m_size - 1;
      auto len = 1;
      while (lk <= rk) {
        if (!(lk & 1)) {
          addLine(line, lk, l, l + len);
          l += len;
          ++lk;
        }
        if (rk & 1) {
          r -= len;
          addLine(line, rk, r + 1, r + len + 1);
          --rk;
        }
        lk = (lk - 1) >> 1;
        rk = (rk - 1) >> 1;
        len <<= 1;
      }
    }
    auto addSegment(const T& a, const T& b, const T& l, const T& r) {
      addSegment({a, b}, l, r);
    }

    auto query(const T& x) {
      auto k = m_xtoi[x] + m_size;
      auto ret = INF;
      while (k > 0) {
        ret = std::min(ret, f(m_node[k - 1], x));
        k >>= 1;
      }
      return ret;
    }

    auto debug() const {
      std::cerr << "-- Li Chao Tree --" << std::endl;
      for (unsigned int i = 0; i < m_node.size(); ++i) {
        std::cerr << i << ": (" << m_node[i].first << " " << m_node[i].second
                  << ")" << std::endl;
      }
    }
  };

  /*
   * クエリ先読みが不要なLiChaoTree
   * 線分追加は非常に遅いため非推奨
   *
   * X_MAX: ax+bであるxとして取りうる最大値
   */
  template <long long X_MAX, class T = long long>
  class DynamicLiChaoTree {
    constexpr static T INF = 2e18;

    class Line {
      T a, b;

    public:
      Line(const T& _a, const T& _b) : a(_a), b(_b) {}
      Line() : Line(0, INF) {}
      Line(const Line& other) noexcept : Line(other.a, other.b) {}
      Line(Line&& other) noexcept : Line(other) {}
      Line& operator=(Line&& other) noexcept {
        if (this != &other) {
          a = other.a;
          b = other.b;
        }
        return *this;
      }
      auto operator<(const Line& line) const { return a < line.a; }
      auto operator>(const Line& line) const { return line.operator<(*this); }

      auto f(const T& x) const { return a * x + b; }
      auto debug() const {
        if (b == INF) {
          std::cerr << "(" << a << " inf)" << std::endl;
        } else {
          std::cerr << "(" << a << " " << b << ")" << std::endl;
        }
      }
    };

    struct Node {
      Line line;
      std::unique_ptr<Node> left;
      std::unique_ptr<Node> right;

      Node(const Line& _line) : line(_line) {}
      auto f(const T& x) const { return line.f(x); }
    };

    std::unique_ptr<Node> m_root;

    auto addLine(std::unique_ptr<Node>& node, Line&& line, T l, T r) {
      if (!node) {
        node = std::make_unique<Node>(line);
        return;
      }

      auto m = (l + 1 == r) ? l : (l + r) / 2;
      if (line.f(m) < node->f(m)) { std::swap(node->line, line); }
      if (l + 1 == r) { return; }
      if (line > node->line) {
        addLine(node->left, std::move(line), l, m);
      } else if (line < node->line) {
        addLine(node->right, std::move(line), m, r);
      }
    }
    auto addSegment(std::unique_ptr<Node>& node, const Line& line, T l, T r,
                    T sl, T sr) {
      if (sr <= l || r <= sl) { return; }
      if (l <= sl && sr <= r) {
        addLine(node, Line(line), sl, sr);
        return;
      }
      auto m = (sl + sr) / 2;
      if (!node) { node = std::make_unique<Node>(Line()); }
      addSegment(node->left, line, l, r, sl, m);
      addSegment(node->right, line, l, r, m, sr);
    }

    auto query(const std::unique_ptr<Node>& node, const T& x, T l, T r) const {
      if (!node) { return Line().f(x); }
      auto m = (l + r) / 2;
      return std::min(node->f(x), (x < m) ? query(node->left, x, l, m)
                                          : query(node->right, x, m, r));
    }

  public:
    DynamicLiChaoTree() {}

    auto addLine(const T& a, const T& b) {
      addLine(m_root, Line(a, b), -X_MAX, X_MAX + 1);
    }
    auto addLine(const std::pair<T, T>& line) {
      addLine(line.first, line.second);
    }
    [[deprecated(
        "This method is too slow. Please use LiChaoTree and not "
        "DynamicLiChaoTree.")]] auto
    addSegment(const T& a, const T& b, const T& l, const T& r) {
      addSegment(m_root, Line(a, b), l, r + 1, -X_MAX, X_MAX + 1);
    }
    auto addSegment(const std::pair<T, T>& line, const T& l, const T& r) {
      addSegment(line.first, line.second, l, r);
    }
    auto query(const T& x) const { return query(m_root, x, -X_MAX, X_MAX + 1); }

    auto debug(const std::unique_ptr<Node>& node, int size) const {
      if (size == 0) { std::cerr << "-- li chao tree --" << std::endl; }
      if (!node) { return; }
      for (int i = 0; i < size; ++i) { std::cerr << "- "; }
      node->line.debug();
      if (node->left) {
        std::cout << "L";
        debug(node->left, size + 1);
      }
      if (node->right) {
        std::cout << "R";
        debug(node->right, size + 1);
      }
    }
    auto debug() const { debug(m_root, 0); }
  };
}  // namespace mtd
