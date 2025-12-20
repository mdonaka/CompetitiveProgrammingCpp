#pragma once

#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include "../Algebraic/Monoid.hpp"

namespace mtd {
  template <monoid Monoid, int size = static_cast<int>(1e9 + 1)>
  class DynamicSegmentTree {
  private:
    using S = decltype(Monoid().m_val);

    struct Node {
      Monoid val;
      std::unique_ptr<Node> left;
      std::unique_ptr<Node> right;
      Node() : val(Monoid()), left(nullptr), right(nullptr) {}
      explicit Node(const Monoid& v) : val(v), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> m_root;

    template <class Lambda>
    constexpr void _update_op(std::unique_ptr<Node>& node, int l, int r, int pos,
                               Monoid&& val, const Lambda& op) {
      if (!node) node = std::make_unique<Node>();
      if (r - l == 1) {
        node->val = op(node->val, std::forward<Monoid>(val));
        return;
      }
      int mid = l + (r - l) / 2;
      if (pos < mid) {
        _update_op(node->left, l, mid, pos, std::forward<Monoid>(val), op);
      } else {
        _update_op(node->right, mid, r, pos, std::forward<Monoid>(val), op);
      }
      Monoid left_val = node->left ? node->left->val : Monoid();
      Monoid right_val = node->right ? node->right->val : Monoid();
      node->val = left_val.binaryOperation(right_val);
    }

    constexpr Monoid _query(const std::unique_ptr<Node>& node, int l, int r,
                            int ql, int qr) const {
      if (!node || r <= ql || qr <= l) return Monoid();
      if (ql <= l && r <= qr) return node->val;
      int mid = l + (r - l) / 2;
      return _query(node->left, l, mid, ql, qr)
          .binaryOperation(_query(node->right, mid, r, ql, qr));
    }

  public:
    constexpr DynamicSegmentTree() : m_root(nullptr) {}

    template <class Lambda>
    constexpr auto update_op(int pos, Monoid&& val, const Lambda& op) {
      return _update_op(m_root, 0, size, pos, std::forward<Monoid>(val), op);
    }

    constexpr auto update(int pos, Monoid&& val) {
      return update_op(pos, std::forward<Monoid>(val),
                       [](const Monoid&, const Monoid& m2) { return m2; });
    }

    constexpr auto add(int pos, Monoid&& val) {
      return update_op(pos, std::forward<Monoid>(val),
                       [](const Monoid& m1, const Monoid& m2) {
                         return Monoid(m1.m_val + m2.m_val);
                       });
    }

    constexpr auto query(int l, int r) const {
      if (l > r) return Monoid().m_val;
      return _query(m_root, 0, size, l, r + 1).m_val;
    }

    constexpr auto query_all() const {
      return m_root ? m_root->val.m_val : Monoid().m_val;
    }
  };

}  // namespace mtd
