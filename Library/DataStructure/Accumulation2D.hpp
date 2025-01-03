#pragma once
#include <vector>

#include "../Algebraic/Group.hpp"
#include "./Accumulation.hpp"

namespace mtd {

  template <group Group = type::AdditiveGroup<long long>>
  class Accumulation2D {
  private:
    using S = decltype(Group().m_val);

    const int h;
    const int w;
    std::vector<std::vector<Group>> sumList;

  public:
    constexpr Accumulation2D() = delete;
    constexpr Accumulation2D(const std::vector<std::vector<S>>& v)
        : h(v.size()),
          w(v[0].size()),
          sumList(h + 1, std::vector<Group>(w + 1)) {
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) { sumList[i + 1][j + 1] = v[i][j]; }
      }
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w + 1; ++j) {
          sumList[i + 1][j] = sumList[i + 1][j].binaryOperation(sumList[i][j]);
        }
      }
      for (int i = 0; i < h + 1; ++i) {
        for (int j = 0; j < w; ++j) {
          sumList[i][j + 1] = sumList[i][j + 1].binaryOperation(sumList[i][j]);
        }
      }
    }
    constexpr S get(int y, int x) { return sumList[y + 1][x + 1].m_val; }
    constexpr S get(int y1, int x1, int y2, int x2) {
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

}  // namespace mtd
