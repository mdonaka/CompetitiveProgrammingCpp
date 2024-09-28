#pragma once
#include <numeric>
#include <vector>

class UnionFindWeight {
public:
  std::vector<long long> m_root;
  std::vector<long long> m_rank;
  std::vector<long long> m_weight;

  long long root(long long x) {
    if (m_root[x] == x) { return x; }
    long long r = root(m_root[x]);
    m_weight[x] += m_weight[m_root[x]];
    return m_root[x] = r;
  }
  long long weight(long long x) {
    root(x);
    return m_weight[x];
  }

public:
  UnionFindWeight() = delete;
  UnionFindWeight(long long n) : m_root(n), m_rank(n), m_weight(n) {
    std::iota(m_root.begin(), m_root.end(), 0);
  }
  bool isSame(long long x, long long y) { return root(x) == root(y); }
  bool merge(long long x, long long y, long long w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y) { return false; }
    if (m_rank[x] < m_rank[y]) {
      std::swap(x, y);
      w = -w;
    }
    if (m_rank[x] == m_rank[y]) { ++m_rank[x]; }
    m_root[y] = x;
    m_weight[y] = w;
    return true;
  }
  long long diffWeight(long long x, long long y) {
    return weight(y) - weight(x);
  }
};
