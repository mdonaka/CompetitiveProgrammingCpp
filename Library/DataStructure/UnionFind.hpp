#pragma once
#include <numeric>
#include <vector>
/**
 *	UnionFind木を構成する
 *	nodeの深さ，木のサイズを取得可能
 */
class UnionFind {
  std::vector<int> m_root;
  std::vector<int> m_depth;
  std::vector<int> m_size;

public:
  UnionFind(int size) : m_root(size), m_depth(size, 0), m_size(size, 1) {
    std::iota(m_root.begin(), m_root.end(), 0);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) { return; }
    auto t = size(x) + size(y);
    m_size[x] = m_size[y] = t;
    if (m_depth[x] < m_depth[y]) {
      m_root[x] = y;
    } else {
      m_root[y] = x;
    }
    if (m_depth[x] == m_depth[y]) { ++m_depth[x]; }
  }
  bool isSame(int x, int y) { return root(x) == root(y); }
  int root(int x) {
    if (m_root[x] == x) { return x; }
    return m_root[x] = root(m_root[x]);
  }
  int size(int x) {
    if (m_root[x] == x) { return m_size[x]; }
    return size(m_root[x] = root(m_root[x]));
  }
};
