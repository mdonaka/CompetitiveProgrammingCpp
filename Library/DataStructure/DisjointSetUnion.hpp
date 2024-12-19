#pragma once

#include <iostream>
#include <numeric>
#include <vector>

namespace mtd {

  template <class T = int>
  class PotentialDisjointSetUnion {
    std::vector<int> m_root;
    std::vector<int> m_rank;
    std::vector<int> m_size;
    std::vector<T> m_potential;

  public:
    PotentialDisjointSetUnion() = delete;
    PotentialDisjointSetUnion(int n)
        : m_root(n), m_rank(n), m_size(n), m_potential(n) {
      std::iota(m_root.begin(), m_root.end(), 0);
    }

    auto unite(int x, int y, T p = 0) {
      p += potential(x);
      p -= potential(y);
      x = root(x);
      y = root(y);
      if (x == y) { return false; }
      if (m_rank[x] < m_rank[y]) {
        std::swap(x, y);
        p = -p;
      }
      if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }
      m_size[x] = m_size[y] = size(x) + size(y);
      m_root[y] = x;
      m_potential[y] = p;
      return true;
    }

    auto root(int x) -> int {
      if (m_root[x] == x) { return x; }
      int r = root(m_root[x]);
      m_potential[x] += m_potential[m_root[x]];
      return m_root[x] = r;
    }

    auto potential(int x) -> T {
      root(x);
      return m_potential[x];
    }

    auto size(int x) -> int {
      if (m_root[x] == x) { return m_size[x]; }
      return size(m_root[x] = root(m_root[x]));
    }

    auto isSame(int x, int y) { return root(x) == root(y); }

    auto diff(int x, int y) { return potential(y) - potential(x); }

    friend std::ostream& operator<<(std::ostream& os,
                                    const PotentialDisjointSetUnion& dsu) {
      for (const auto& x : dsu.m_root) { os << x << " "; }
      return os;
    }
  };
}  // namespace mtd
