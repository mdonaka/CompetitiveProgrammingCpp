#pragma once

#include <deque>
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
      Node* left;
      Node* right;
      Node() : val(Monoid()), left(nullptr), right(nullptr) {}
      explicit Node(const Monoid& v) : val(v), left(nullptr), right(nullptr) {}
    };

    std::deque<Node> m_nodes;
    Node* m_root;

    Node* _get_node() {
      m_nodes.emplace_back();
      return &m_nodes.back();
    }

    Node* _get_node(const Monoid& val) {
      m_nodes.emplace_back(val);
      return &m_nodes.back();
    }

    template <class Lambda>
    void _update_op(Node*& node, int l, int r, int pos, const Monoid& val,
                    const Lambda& op) {
      if (!node) node = _get_node();
      if (r - l == 1) {
        node->val = op(node->val, val);
        return;
      }
      int mid = l + (r - l) / 2;
      if (pos < mid) {
        _update_op(node->left, l, mid, pos, val, op);
      } else {
        _update_op(node->right, mid, r, pos, val, op);
      }
      Monoid left_val = node->left ? node->left->val : Monoid();
      Monoid right_val = node->right ? node->right->val : Monoid();
      node->val = left_val.binaryOperation(right_val);
    }

    Monoid _query(Node* node, int l, int r, int ql, int qr) const {
      if (!node || r <= ql || qr <= l) return Monoid();
      if (ql <= l && r <= qr) return node->val;
      int mid = l + (r - l) / 2;
      return _query(node->left, l, mid, ql, qr)
          .binaryOperation(_query(node->right, mid, r, ql, qr));
    }

  public:
    constexpr DynamicSegmentTree() : m_root(nullptr) {}

    template <class Lambda>
    void update_op(int pos, const Monoid& val, const Lambda& op) {
      _update_op(m_root, 0, size, pos, val, op);
    }

    void update(int pos, const Monoid& val) {
      update_op(pos, val,
                [](const Monoid&, const Monoid& m2) { return m2; });
    }

    void add(int pos, const Monoid& val) {
      update_op(pos, val, [](const Monoid& m1, const Monoid& m2) {
        return Monoid(m1.m_val + m2.m_val);
      });
    }

    S query(int l, int r) const {
      if (l > r) return Monoid().m_val;
      return _query(m_root, 0, size, l, r + 1).m_val;
    }

    S query_all() const {
      return m_root ? m_root->val.m_val : Monoid().m_val;
    }
  };

}  // namespace mtd
