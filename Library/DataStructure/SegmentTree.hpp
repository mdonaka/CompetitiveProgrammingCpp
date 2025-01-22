#pragma once

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#include "../Algebraic/Monoid.hpp"

namespace mtd {

  template <monoid Monoid>
  class SegmentTree {
  private:
    const int m_size;
    std::vector<Monoid> m_node;
    using S = decltype(Monoid().m_val);

    constexpr int calcSize(int n) const {
      int size = 1;
      while (size < n) { size <<= 1; }
      return size;
    }

    template <class Lambda>
    constexpr auto _update_op(int itr, Monoid&& val, const Lambda& op) {
      int i = itr + m_size - 1;
      m_node[i] = op(m_node[i], std::forward<decltype(val)>(val));
      while (i) {
        i = (i - 1) >> 1;
        m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);
      }
    }

    constexpr auto _query(int _l, int _r) const {
      _l = std::max(_l, 0);
      _r = std::min(_r, m_size - 1);
      auto l = _l + m_size;
      auto r = _r + m_size;
      auto lm = Monoid();
      auto rm = Monoid();
      while (l <= r) {
        if (l & 1) {
          lm = lm.binaryOperation(m_node[l - 1]);
          ++l;
        }
        if (!(r & 1)) {
          rm = m_node[r - 1].binaryOperation(rm);
          --r;
        }
        l >>= 1, r >>= 1;
      }
      return lm.binaryOperation(rm);
    }

    constexpr auto _construct(const std::vector<S>& vec) {
      for (unsigned int i = 0; i < vec.size(); ++i) {
        m_node[i + m_size - 1] = Monoid(vec[i]);
      }
      for (int i = m_size - 2; i >= 0; --i) {
        m_node[i] = m_node[(i << 1) | 1].binaryOperation(m_node[(i + 1) << 1]);
      }
    }

  public:
    SegmentTree(int n) : m_size(calcSize(n)), m_node((m_size << 1) - 1) {}
    SegmentTree(int n, const std::vector<S>& vec) : SegmentTree(n) {
      _construct(vec);
    }

    template <class Lambda>
    constexpr auto update_op(int itr, Monoid&& val, const Lambda& op) {
      return _update_op(itr, std::forward<Monoid>(val), op);
    }
    constexpr auto update(int itr, Monoid&& val) {
      return update_op(itr, std::forward<Monoid>(val),
                       [](const Monoid&, const Monoid& m2) { return m2; });
    }
    constexpr auto add(int itr, Monoid&& val) {
      return update_op(itr, std::forward<Monoid>(val),
                       [](const Monoid& m1, const Monoid& m2) {
                         return Monoid(m1.m_val + m2.m_val);
                       });
    }
    constexpr auto query(int l, int r) const { return _query(l, r).m_val; }
    constexpr auto query_all() const { return m_node[0].m_val; }

    /*
     * f([l, r]) = true となる最大のr
     * judge: (Monoid) -> bool
     **/
    template <class F>
    constexpr auto max_right(int _l, const F& judge) const {
      if (!judge(Monoid())) {
        throw std::runtime_error("SegmentTree.max_right.judge(e) must be true");
      }
      auto l = std::max(_l, 0) + m_size;
      auto r = 2 * m_size - 1;
      auto lm = Monoid();
      while (l <= r) {
        if (l & 1) {
          auto next = lm.binaryOperation(m_node[l - 1]);
          if (!judge(next)) {
            auto itr = l;
            while (itr < m_size) {
              auto litr = 2 * itr;
              auto ritr = 2 * itr + 1;
              auto lval = lm.binaryOperation(m_node[litr - 1]);
              if (!judge(lval)) {
                itr = litr;
              } else {
                itr = ritr;
                std::swap(lm, lval);
              }
            }
            return itr - m_size - 1;
          }
          std::swap(lm, next);
          ++l;
        }
        l >>= 1, r >>= 1;
      }
      return m_size - 1;
    }

    constexpr auto debug() const {
      for (int i = 0; i < m_size; ++i) {
        std::cout << m_node[m_size + i - 1] << " ";
      }
      std::cout << std::endl;
    }
  };

}  // namespace mtd
