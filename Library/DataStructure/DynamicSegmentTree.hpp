#pragma once

#include <deque>
#include <ostream>
#include <unordered_map>
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

  template <class Monoid, int size = static_cast<int>(1e9 + 1),
            std::enable_if_t<isMonoid<Monoid>::value, std::nullptr_t> = nullptr>
  class DynamicSegmentTree {
  private:
    std::unordered_map<int, Monoid> m_node;
    using S = decltype(Monoid().m_val);

    auto _get(int i) const {
      return (m_node.find(i) == m_node.end()) ? Monoid() : m_node.at(i);
    }

    template <class Lambda>
    auto _update_op(int itr, Monoid&& val, const Lambda& op) {
      int i = itr + size - 1;
      m_node[i] = op(_get(i), std::forward<decltype(val)>(val));
      while (i) {
        i = (i - 1) >> 1;
        m_node[i] = _get((i << 1) | 1).binaryOperation(_get((i + 1) << 1LL));
      }
    }

    auto _query(int _l, int _r) const {
      _l = std::max(_l, 0);
      _r = std::min(_r, size - 1);
      auto l = _l + size;
      int r = _r + size;
      auto lm = Monoid();
      auto rm = Monoid();
      while (l <= r) {
        if (l & 1) {
          lm = lm.binaryOperation(_get(l - 1));
          ++l;
        }
        if (!(r & 1)) {
          rm = _get(r - 1).binaryOperation(rm);
          --r;
        }
        l >>= 1, r >>= 1;
      }
      return lm.binaryOperation(rm);
    }

    auto _construct(const std::vector<S>& vec) {
      for (unsigned int i = 0; i < vec.size(); ++i) {
        m_node[i + size - 1] = Monoid(vec[i]);
      }
      for (int i = size - 2; i >= 0; --i) {
        m_node[i] = _get((i << 1) | 1).binaryOperation(_get((i + 1) << 1));
      }
    }

  public:
    DynamicSegmentTree() {}

    template <class Lambda>
    auto update_op(int itr, Monoid&& val, const Lambda& op) {
      return _update_op(itr, std::forward<Monoid>(val), op);
    }
    auto update(int itr, Monoid&& val) {
      return update_op(itr, std::forward<Monoid>(val),
                       [](const Monoid&, const Monoid& m2) { return m2; });
    }
    auto add(int itr, Monoid&& val) {
      return update_op(itr, std::forward<Monoid>(val),
                       [](const Monoid& m1, const Monoid& m2) {
                         return Monoid(m1.m_val + m2.m_val);
                       });
    }
    auto query(int l, int r) const { return _query(l, r).m_val; }
    auto query_all() const { return m_node[0].m_val; }
  };

  template <class S,    // 要素の型
            S element,  // 元
            class T  // lambdaはC++20じゃないと渡せなかった．．．
                     // S T(S, S)  // 2項演算子
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
}  // namespace mtd
