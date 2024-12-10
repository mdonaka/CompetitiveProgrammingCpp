#pragma once

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#include "../Algebraic/Monoid.hpp"

namespace mtd {
  template <monoid Monoid, monoid MonoidOp, class op>
  class LazySegmentTree {
  private:
    const int m_size;
    std::vector<Monoid> m_node;
    std::vector<MonoidOp> m_lazy;
    using S = decltype(Monoid().m_val);

    constexpr int calcSize(int n) const {
      int size = 1;
      while (size < n) { size <<= 1; }
      return size;
    }

    constexpr auto _lazy_update(int i, const MonoidOp& val) {
      if (i >= (m_size << 1) - 1) { return; }
      m_lazy[i] = m_lazy[i].binaryOperation(val);
    }

    constexpr auto _propagate(int i) {
      m_node[i] = op()(m_node[i], m_lazy[i]);
      _lazy_update((i << 1) + 1, m_lazy[i]);
      _lazy_update((i << 1) + 2, m_lazy[i]);
      m_lazy[i] = MonoidOp();
    }

    constexpr auto _update(int l, int r, int k, int nl, int nr,
                           const MonoidOp& m) {
      _propagate(k);
      if (nr < l || r < nl) { return; }
      if (l <= nl && nr <= r) {
        _lazy_update(k, m);
        _propagate(k);
        return;
      }
      _update(l, r, (k << 1) + 1, nl, (nl + nr) >> 1, m);
      _update(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr, m);
      m_node[k] = m_node[(k << 1) + 1].binaryOperation(m_node[(k << 1) + 2]);
    }

    constexpr auto _query(int l, int r, int k, int nl, int nr) {
      _propagate(k);
      if (nr < l || r < nl) { return Monoid(); }
      if (l <= nl && nr <= r) { return m_node[k]; }
      auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr) >> 1);
      auto r_val = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr);
      return l_val.binaryOperation(r_val);
    }

    constexpr auto _construct(const std::vector<S>& vec) {
      for (unsigned int i = 0; i < vec.size(); ++i) {
        m_node[i + m_size - 1] = Monoid(vec[i]);
      }
      for (int i = m_size - 2; i >= 0; --i) {
        m_node[i] =
            m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1LL]);
      }
    }

  public:
    constexpr LazySegmentTree(int n)
        : m_size(calcSize(n)),
          m_node((m_size << 1) - 1),
          m_lazy((m_size << 1) - 1) {}
    constexpr LazySegmentTree(int n, const std::vector<S>& vec)
        : LazySegmentTree(n) {
      _construct(vec);
    }

    constexpr auto update(int l, int r, const MonoidOp& val) {
      _update(l, r, 0, 0, m_size - 1, val);
    }

    constexpr auto query(int l, int r) {
      return _query(l, r, 0, 0, m_size - 1).m_val;
    }

    constexpr auto output() {
      for (int i = 0; i < (m_size << 1) - 1; ++i) { _propagate(i); }
      for (int i = 0; i < m_size; ++i) {
        std::cout << m_node[m_size + i - 1] << " ";
      }
      std::cout << std::endl;
    }
  };

  namespace type {
    /* 各種頻出サンプル */
    using P = std::pair<long long, long long>;
    constexpr long long update_element = -1e18;

    /*---- 要素 ----*/
    using M_SUM = Monoid<P, P{0, 0}, decltype([](const P& a, const P& b) {
                           return P{a.first + b.first, a.second + b.second};
                         })>;
    using M_MIN = Monoid<long long, static_cast<long long>(1e18),
                         decltype([](long long a, long long b) {
                           return std::min(a, b);
                         })>;
    using M_MAX = Monoid<long long, static_cast<long long>(-1e18),
                         decltype([](long long a, long long b) {
                           return std::max(a, b);
                         })>;
    /*---- 作用素 ----*/
    using M_UP = Monoid<long long, update_element,
                        decltype([](long long a, long long b) {
                          if (b == update_element) { return a; }
                          return b;
                        })>;
    using M_ADD =
        Monoid<long long, static_cast<long long>(0),
               decltype([](long long a, long long b) { return a + b; })>;

    /*---- 作用 ----*/
    using OP_SUM_UP = decltype([](const M_SUM& m, const M_UP& m2) {
      if (m2.m_val == update_element) { return m; }
      return M_SUM(P{m.m_val.second * m2.m_val, m.m_val.second});
    });
    using OP_MIN_UP = decltype([](const M_MIN& m, const M_UP& m2) {
      if (m2.m_val == update_element) { return m; }
      return M_MIN(m2.m_val);
    });
    using OP_MAX_UP = decltype([](const M_MAX& m, const M_UP& m2) {
      if (m2.m_val == update_element) { return m; }
      return M_MAX(m2.m_val);
    });
    using OP_SUM_ADD = decltype([](const M_SUM& m, const M_ADD& m2) {
      return M_SUM(
          P{m.m_val.first + m.m_val.second * m2.m_val, m.m_val.second});
    });
    using OP_MIN_ADD = decltype([](const M_MIN& m, const M_ADD& m2) {
      return M_MIN{m.m_val + m2.m_val};
    });
    using OP_MAX_ADD = decltype([](const M_MAX& m, const M_ADD& m2) {
      return M_MAX{m.m_val + m2.m_val};
    });

  }  // namespace type
}  // namespace mtd
