#pragma once

#include <algorithm>
#include <vector>

#include "../Algebraic/Group.hpp"

namespace mtd {

  namespace type {

    using inv = decltype([](auto x) { return -x; });
    using op = decltype([](auto x, auto y) { return x + y; });
    template <class P>
    using AdditiveGroup = Group<P, P(0), op, inv>;

  }  // namespace type

  template <group Group = type::AdditiveGroup<long long>>
  class Accumulation {
    using S = decltype(Group().m_val);

    const int size;
    std::vector<Group> sumList;

  public:
    constexpr Accumulation() = delete;
    constexpr Accumulation(const std::vector<Group>& v)
        : size(v.size()), sumList(size + 1) {
      for (int i = 0; i < size; ++i) {
        sumList[i + 1] = sumList[i].binaryOperation(v[i]);
      }
    }
    constexpr Accumulation(const std::vector<S>& v)
        : Accumulation(std::vector<Group>(v.begin(), v.end())) {}

    constexpr auto get(int n) const { return sumList[n + 1].m_val; }
    constexpr auto get(int l, int r) const {
      if (r < l) { return Group::_element; }
      l = std::max(l, 0);
      r = std::min(r, size - 1);
      return sumList[r + 1].binaryOperation(sumList[l].inverse()).m_val;
    }

    constexpr friend std::ostream& operator<<(std::ostream& os,
                                              const Accumulation<Group>& acc) {
      for (const auto& x : acc.sumList) { os << x << " "; }
      return os;
    }
  };

}  // namespace mtd
