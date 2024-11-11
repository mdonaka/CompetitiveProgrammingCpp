#pragma once
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

namespace mtd {
  template <class T>
  class isMonoid {
    template <class U>
    static auto check(U x) -> decltype(x.binaryOperation(x), std::true_type{});
    static std::false_type check(...);

  public:
    static bool const value = decltype(check(std::declval<T>()))::value;
  };

  template <class Monoid, class MonoidOp, class op,
            std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t> = nullptr,
            std::enable_if_t<isMonoid<MonoidOp>::value, std::nullptr_t> =
                nullptr>
  class LazySegmentTree {
  private:
    const int m_size;
    std::vector<Monoid> m_node;
    std::vector<MonoidOp> m_lazy;
    using S = decltype(Monoid().m_val);

    int calcSize(int n) const {
      int size = 1;
      while (size < n) { size <<= 1; }
      return size;
    }

    auto _lazy_update(int i, const MonoidOp& val) {
      if (i >= (m_size << 1) - 1) { return; }
      m_lazy[i] = m_lazy[i].binaryOperation(val);
    }

    auto _propagate(int i) {
      m_node[i] = op()(m_node[i], m_lazy[i]);
      _lazy_update((i << 1) + 1, m_lazy[i]);
      _lazy_update((i << 1) + 2, m_lazy[i]);
      m_lazy[i] = MonoidOp();
    }

    auto _update(int l, int r, int k, int nl, int nr, const MonoidOp& m) {
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

    auto _query(int l, int r, int k, int nl, int nr) {
      _propagate(k);
      if (nr < l || r < nl) { return Monoid(); }
      if (l <= nl && nr <= r) { return m_node[k]; }
      auto l_val = _query(l, r, (k << 1) + 1, nl, (nl + nr) >> 1);
      auto r_val = _query(l, r, (k << 1) + 2, ((nl + nr) >> 1) + 1, nr);
      return l_val.binaryOperation(r_val);
    }

    auto _construct(const std::vector<S>& vec) {
      for (unsigned int i = 0; i < vec.size(); ++i) {
        m_node[i + m_size - 1] = Monoid(vec[i]);
      }
      for (int i = m_size - 2; i >= 0; --i) {
        m_node[i] =
            m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1LL]);
      }
    }

  public:
    LazySegmentTree(int n)
        : m_size(calcSize(n)),
          m_node((m_size << 1) - 1),
          m_lazy((m_size << 1) - 1) {}
    LazySegmentTree(int n, const std::vector<S>& vec) : LazySegmentTree(n) {
      _construct(vec);
    }

    auto update(int l, int r, const MonoidOp& val) {
      _update(l, r, 0, 0, m_size - 1, val);
    }

    auto query(int l, int r) { return _query(l, r, 0, 0, m_size - 1).m_val; }

    auto output() {
      for (int i = 0; i < (m_size << 1) - 1; ++i) { _propagate(i); }
      for (int i = 0; i < m_size; ++i) {
        std::cout << m_node[m_size + i - 1] << " ";
      }
      std::cout << std::endl;
    }
  };

  template <class S,     // 要素の型
            S& element,  // 元
            class T      // 2項演算のFunctor
            >
  struct Monoid {
    S m_val;
    Monoid() : m_val(element) {}
    Monoid(S val) : m_val(val) {}
    Monoid binaryOperation(const Monoid& m2) const {
      return T()(m_val, m2.m_val);
    }
    friend std::ostream& operator<<(std::ostream& os,
                                    const Monoid<S, element, T>& m) {
      return os << m.m_val;
    }
  };

  /*
  各種頻出サンプル
  ex) 区間最小値，区間更新
  LazySegmentTree<M_M, M_U, OP_RUQ_RMQ>
  */
  //---- 要素 ----
  std::pair<long long, long long> base_s{0, 0};
  struct F_RSQ {
    auto operator()(const std::pair<long long, long long>& a,
                    const std::pair<long long, long long>& b) const {
      return std::pair<long long, long long>{a.first + b.first,
                                             a.second + b.second};
    }
  };
  using M_S = Monoid<std::pair<long long, long long>, base_s, F_RSQ>;

  long long base_m{static_cast<long long>(1e18)};
  struct F_RMQ {
    auto operator()(long long a, long long b) const { return std::min(a, b); }
  };
  using M_M = Monoid<long long, base_m, F_RMQ>;

  //---- 作用素 ----
  long long base_u{static_cast<long long>(-1e18)};
  struct F_RUQ {
    auto operator()(long long a, long long b) const {
      if (b == base_u) { return a; }
      return b;
    }
  };
  using M_U = Monoid<long long, base_u, F_RUQ>;

  long long base_a{static_cast<long long>(0)};
  struct F_RAQ {
    auto operator()(long long a, long long b) const { return a + b; }
  };
  using M_A = Monoid<long long, base_a, F_RAQ>;

  //---- 作用 ----
  struct OP_RUQ_RSQ {
    auto operator()(const M_S& m, const M_U& m2) {
      if (m2.m_val == base_u) { return m; }
      return M_S(std::pair<long long, long long>{m.m_val.second * m2.m_val,
                                                 m.m_val.second});
    }
  };
  struct OP_RUQ_RMQ {
    auto operator()(const M_M& m, const M_U& m2) {
      if (m2.m_val == base_u) { return m; }
      return M_M(m2.m_val);
    }
  };
  struct OP_RAQ_RSQ {
    auto operator()(const M_S& m, const M_A& m2) {
      return M_S(std::pair<long long, long long>{
          m.m_val.first + m.m_val.second * m2.m_val, m.m_val.second});
    }
  };
  struct OP_RAQ_RMQ {
    auto operator()(const M_M& m, const M_A& m2) {
      return M_M{m.m_val + m2.m_val};
    }
  };
}  // namespace mtd
