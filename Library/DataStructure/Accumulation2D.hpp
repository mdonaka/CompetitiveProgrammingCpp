#pragma once
#include <vector>

template <class S,    // 要素の型
          S element,  // 元
          class T,    // 2項演算子
          class U     // 逆元
          >
struct Group {
  S m_val;
  Group() : m_val(element) {}
  Group(S val) : m_val(val) {}
  Group inverse() const { return U()(m_val); }
  Group binaryOperation(const Group& g) const { return T()(m_val, g.m_val); }
};

template <class P>
struct F_A_Inv {
  auto operator()(P x) const { return -x; }
};
template <class P>
struct F_A_Bin {
  auto operator()(P x, P y) const { return x + y; }
};
template <class P>
using AdditiveGroup = Group<P, P(0), F_A_Bin<P>, F_A_Inv<P>>;

template <class Group = AdditiveGroup<long long>>
class Accumulation2D {
private:
  using S = decltype(Group().m_val);

  const int h;
  const int w;
  std::vector<std::vector<Group>> sumList;

public:
  Accumulation2D() = delete;
  Accumulation2D(const std::vector<std::vector<S>>& v)
      : h(v.size()), w(v[0].size()), sumList(h + 1, std::vector<Group>(w + 1)) {
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) { sumList[i + 1][j + 1] = v[i][j]; }
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w + 1; ++j) {
        sumList[i + 1][j] = sumList[i + 1][j].binaryOperation(sumList[i][j]);
      }
    for (int i = 0; i < h + 1; ++i)
      for (int j = 0; j < w; ++j) {
        sumList[i][j + 1] = sumList[i][j + 1].binaryOperation(sumList[i][j]);
      }
  }
  S get(int y, int x) { return sumList[y + 1][x + 1].m_val; }
  S get(int y1, int x1, int y2, int x2) {
    if (y2 < y1 || x2 < x1) { return Group().m_val; }
    x1 = std::max(x1, 0);
    y1 = std::max(y1, 0);
    y2 = std::min(y2, h - 1);
    x2 = std::min(x2, w - 1);
    return sumList[y2 + 1][x2 + 1]
        .binaryOperation(sumList[y1][x1])
        .binaryOperation(sumList[y2 + 1][x1].inverse())
        .binaryOperation(sumList[y1][x2 + 1].inverse())
        .m_val;
  }
};
