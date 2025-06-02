#pragma once

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <tuple>
#include <vector>

#include "../Range/util.hpp"

namespace mtd {

  template <class T, class CompT = long long>
  class SternBrocotTree {
    using Path = std::vector<std::tuple<bool, T>>;

    class Node {
      // 定数倍高速化のため破壊的変更や怪しい仕様あり
      T num_l, den_l, num_r, den_r;
      Path path_rle;

      friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        return os << node.num_l + node.num_r << "/" << node.den_l + node.den_r
                  << ": " << node.num_l << "/" << node.den_l << " "
                  << node.num_r << "/" << node.den_r;
      }

    public:
      static constexpr auto get_root() { return Node(0, 1, 1, 0); }

      constexpr auto get() const {
        return std::make_tuple(num_l + num_r, den_l + den_r);
      }
      constexpr auto get_l() const { return Node(num_l, den_l); }
      constexpr auto get_r() const { return Node(num_r, den_r); }
      constexpr auto get_path_rle() const { return path_rle; }

      constexpr auto move_left(T d = 1) {
        if (d == 0) { return false; }
        path_rle.emplace_back(false, d);
        num_r += d * num_l;
        den_r += d * den_l;
        return true;
      }
      constexpr auto move_left_to(T num, T den) {
        auto den_d = static_cast<CompT>(den);
        auto num_d = static_cast<CompT>(num);
        auto tmp = den_l * num_d - den_d * num_l;
        T d =
            (den_d * (num_l + num_r) - (den_l + den_r) * num_d + tmp - 1) / tmp;
        return move_left(d);
      }
      constexpr auto move_right(T d = 1) {
        if (d == 0) { return false; }
        path_rle.emplace_back(true, d);
        num_l += d * num_r;
        den_l += d * den_r;
        return true;
      }
      constexpr auto move_right_to(T num, T den) {
        auto den_d = static_cast<CompT>(den);
        auto num_d = static_cast<CompT>(num);
        auto tmp = den_d * num_r - den_r * num_d;
        T d =
            ((den_l + den_r) * num_d - den_d * (num_l + num_r) + tmp - 1) / tmp;
        return move_right(d);
      }

      constexpr static auto generate_node(T num, T den) {
        if (den <= 0) {
          throw std::runtime_error("denominator must be positive");
        }
        if (num < 0) {
          throw std::runtime_error("numerator must be non-negative");
        }
        if (std::gcd(num, den) > 1) {
          throw std::runtime_error("numerator and denominator must be coprime");
        }

        auto node = get_root();
        Path path_rle;
        while (true) {
          if (node.get() == std::make_tuple(num, den)) { break; }
          node.move_left_to(num, den);
          node.move_right_to(num, den);
        }
        return node;
      }

      constexpr static auto decode(const Path& path_rle) {
        auto node = get_root();
        for (const auto& [right, k] : path_rle) {
          if (right) {
            node.move_right(k);
          } else {
            node.move_left(k);
          }
        }
        return node;
      }

      constexpr Node(T num_l, T den_l, T num_r, T den_r, Path&& path_rle)
          : num_l(num_l),
            den_l(den_l),
            num_r(num_r),
            den_r(den_r),
            path_rle(std::move(path_rle)) {}
      constexpr Node(T num_l, T den_l, T num_r, T den_r)
          : Node(num_l, den_l, num_r, den_r, Path()) {}
      constexpr Node(T num, T den) : Node(generate_node(num, den)) {}

      constexpr auto operator!=(const Node& other) const {
        return std::tie(num_l, den_l, num_r, den_r) !=
               std::tie(other.num_l, other.den_l, other.num_r, other.den_r);
      }
      constexpr auto operator==(const Node& other) const {
        return !(*this != other);
      }
    };

  public:
    /*
     * Encode the path from the root to the fraction num/den
     **/
    constexpr auto encode(const Node& node) const {
      return node.get_path_rle();
    }
    constexpr auto encode(T num, T den) const { return encode(Node(num, den)); }

    /*
     * Decode the path from the root to the fraction represented by
     **/
    constexpr auto decode(const Path& path_rle) const {
      return Node::decode(path_rle);
    }

    /*
     * Find the lowest common ancestor of two fractions num1/den1 and num2/den2
     **/
    constexpr auto lca(const Node& node1, const Node& node2) const {
      auto path_rle1 = encode(node1);
      auto path_rle2 = encode(node2);
      Path lca_path;
      for (const auto [p1, p2] : mtd::views::zip(path_rle1, path_rle2)) {
        auto [right1, k1] = p1;
        auto [right2, k2] = p2;
        if (right1 != right2) { return Node(0, 1, 1, 0); }
        lca_path.emplace_back(right1, std::min(k1, k2));
        if (p1 != p2) { break; }
      }
      return decode(lca_path);
    }
    constexpr auto lca(T num1, T den1, T num2, T den2) const {
      return lca(Node(num1, den1), Node(num2, den2));
    }

    /*
     * Find the k-th ancestor of the fraction num/den
     **/
    constexpr auto ancestor(const Node& node, T k) const {
      Path k_path_rle;
      for (const auto& [right, count] : encode(node)) {
        if (count > k) {
          k_path_rle.emplace_back(right, k);
          k = 0;
          break;
        } else {
          k_path_rle.emplace_back(right, count);
          k -= count;
        }
      }
      if (k > 0) { throw std::runtime_error("k is too large for the path"); }
      return decode(k_path_rle);
    }
    constexpr auto ancestor(T num, T den, T k) const {
      return ancestor(Node(num, den), k);
    }

    /*
     * Find the lower and upper bounds of the descendants of num/den
     **/
    constexpr auto range(const Node& node) const {
      auto [num, den] = node.get();
      if (num == 1 && den == 1) {
        return std::make_tuple(Node(0, 0, 0, 1), Node(0, 0, 1, 0));
      }
      if (den == 1) { return std::make_tuple(node.get_l(), Node(0, 0, 1, 0)); }
      if (num == 1) { return std::make_tuple(Node(0, 0, 0, 1), node.get_r()); }
      return std::make_tuple(node.get_l(), node.get_r());
    }
    constexpr auto range(T num, T den) const { return range(Node(num, den)); }

    /*
     * Create a node representing the fraction num/den
     **/
    constexpr auto create_node(T num, T den) const { return Node(num, den); }

    /*
     * Get the root node of the tree
     **/
    constexpr auto get_root() const { return Node::get_root(); }
  };
}  // namespace mtd
