#pragma once

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <tuple>
#include <vector>

#include "../Range/util.hpp"

namespace mtd {

  template <class T>
  class SternBrocotTree {
    class Node {
      const T num_l, den_l, num_r, den_r;

      friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        return os << node.num_l + node.num_r << "/" << node.den_l + node.den_r
                  << ": " << node.num_l << "/" << node.den_l << " "
                  << node.num_r << "/" << node.den_r;
      }

      constexpr auto move_left(T d = 1) const {
        return Node(num_l, den_l, d * num_l + num_r, d * den_l + den_r);
      }
      constexpr auto move_right(T d = 1) const {
        return Node(num_l + d * num_r, den_l + d * den_r, num_r, den_r);
      }

    public:
      constexpr auto get() const {
        return std::make_tuple(num_l + num_r, den_l + den_r);
      }
      constexpr auto get_l() const { return Node(num_l, den_l); }
      constexpr auto get_r() const { return Node(num_r, den_r); }

      constexpr static auto encode(T num, T den) {
        if (den <= 0) {
          throw std::runtime_error("denominator must be positive");
        }
        if (num < 0) {
          throw std::runtime_error("numerator must be non-negative");
        }
        if (std::gcd(num, den) > 1) {
          throw std::runtime_error("numerator and denominator must be coprime");
        }

        std::vector<std::tuple<T, T>> path_rle;
        auto dfs = [&](auto&& self, const Node& node) {
          if (node.get() == std::make_tuple(num, den)) { return; }
          auto [num_now, den_now] = node.get();
          if (num_now * den < den_now * num) {
            // Move right
            T tmp = den * node.num_r - node.den_r * num;
            T k = (den_now * num - den * num_now + tmp - 1) / tmp;
            auto next_node = node.move_right(k);
            path_rle.emplace_back(true, k);
            return self(self, next_node);
          } else {
            // Move left
            T tmp = node.den_l * num - den * node.num_l;
            T k = (den * num_now - den_now * num + tmp - 1) / tmp;
            auto next_node = node.move_left(k);
            path_rle.emplace_back(false, k);
            return self(self, next_node);
          }
        };
        dfs(dfs, Node(0, 1, 1, 0));
        return path_rle;
      }

      constexpr static auto decode(
          const std::vector<std::tuple<T, T>>& path_rle) {
        auto run = [&](auto&& self, const Node& node, size_t itr) {
          if (itr == path_rle.size()) { return node; }
          auto [right, k] = path_rle[itr];
          return self(self, right ? node.move_right(k) : node.move_left(k),
                      itr + 1);
        };
        return run(run, Node(0, 1, 1, 0), 0);
      }

      constexpr Node(T num_l, T den_l, T num_r, T den_r)
          : num_l(num_l), den_l(den_l), num_r(num_r), den_r(den_r) {}
      constexpr Node(T num, T den) : Node(decode(encode(num, den))) {}
    };

  public:
    /*
     * Encode the path from the root to the fraction num/den
     **/
    constexpr auto encode(T num, T den) const { return Node::encode(num, den); }

    /*
     * Decode the path from the root to the fraction represented by
     **/
    constexpr auto decode(const std::vector<std::tuple<T, T>>& path_rle) const {
      return Node::decode(path_rle);
    }

    /*
     * Find the lowest common ancestor of two fractions num1/den1 and num2/den2
     **/
    constexpr auto lca(T num1, T den1, T num2, T den2) const {
      auto path_rle1 = Node::encode(num1, den1);
      auto path_rle2 = Node::encode(num2, den2);
      std::vector<std::tuple<T, T>> lca_path;
      for (const auto [p1, p2] : mtd::views::zip(path_rle1, path_rle2)) {
        auto [right1, k1] = p1;
        auto [right2, k2] = p2;
        if (right1 != right2) { return Node(0, 1, 1, 0); }
        lca_path.emplace_back(right1, std::min(k1, k2));
        if (p1 != p2) { break; }
      }
      return decode(lca_path);
    }

    /*
     * Find the k-th ancestor of the fraction num/den
     **/
    constexpr auto ancestor(T num, T den, T k) const {
      auto path_rle = Node::encode(num, den);
      std::vector<std::tuple<T, T>> k_path_rle;
      for (const auto& [right, count] : path_rle) {
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
      return Node::decode(k_path_rle);
    }

    /*
     * Find the lower and upper bounds of the descendants of num/den
     **/
    constexpr auto range(T num, T den) const {
      auto node = Node(num, den);
      if (num == 1 && den == 1) {
        return std::make_tuple(Node(0, 0, 0, 1), Node(0, 0, 1, 0));
      }
      if (den == 1) { return std::make_tuple(node.get_l(), Node(0, 0, 1, 0)); }
      if (num == 1) { return std::make_tuple(Node(0, 0, 0, 1), node.get_r()); }
      return std::make_tuple(node.get_l(), node.get_r());
    }
  };
}  // namespace mtd
