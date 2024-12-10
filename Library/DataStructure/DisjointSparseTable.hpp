#pragma once

#include <cmath>
#include <stdexcept>
#include <vector>

#include "../Algebraic/SemiGroup.hpp"

namespace mtd {

  template <semigroup SG>
  class DisjointSparseTable {
    using S = typename SG::value_type;

    const int m_n;
    const std::vector<std::vector<SG>> m_table;

    constexpr static auto accumulation(int n, const std::vector<S>& a, int l,
                                       int r) {
      auto mid = (r + l) >> 1;
      r = std::min(n, r);
      int size = r - l;
      std::vector<SG> acc;
      acc.reserve(size);
      for (int i = l; i < r; ++i) { acc.emplace_back(a[i]); }
      for (int i = mid - 2; i >= l; --i) {
        if (i - l + 1 < size) {
          acc[i - l] = acc[i - l].binaryOperation(acc[i - l + 1]);
        }
      }
      for (int i = mid + 1; i < r; ++i) {
        if (i - l - 1 >= 0) {
          acc[i - l] = acc[i - l - 1].binaryOperation(acc[i - l]);
        }
      }
      return acc;
    }

    constexpr static auto constructTable(int n, const std::vector<S>& a) {
      std::vector<std::vector<SG>> table;
      table.reserve(std::log2(n) + 1);
      table.emplace_back(a.begin(), a.end());

      auto size = 1;
      while (size < n) {
        size <<= 1;
        std::vector<SG> acc;
        acc.reserve(n);
        for (int l = 0; l < n; l += size) {
          for (const auto& x : accumulation(n, a, l, l + size)) {
            acc.emplace_back(x);
          }
        }
        table.emplace_back(acc);
      }
      return table;
    }

    constexpr static auto msb(int x) {
      auto idx = 0;
      while (x > 0) {
        ++idx;
        x >>= 1;
      }
      return idx;
    }

  public:
    DisjointSparseTable(int n, const std::vector<S>& a)
        : m_n(n), m_table(constructTable(n, a)) {}

    constexpr auto get(int l, int r) const {
      if (r < l) { throw std::runtime_error("ERROR! `l` must less than `r`"); }
      l = std::max(l, 0);
      r = std::min(r, m_n - 1);
      if (l == r) { return m_table[0][l].m_val; }
      auto idx = msb(l ^ r);
      return m_table[idx][l].binaryOperation(m_table[idx][r]).m_val;
    }
  };
}  // namespace mtd
