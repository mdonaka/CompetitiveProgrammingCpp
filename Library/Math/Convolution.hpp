#pragma once

#include <ranges>
#include <vector>

#include "./Mobius.hpp"
#include "./Zeta.hpp"

namespace mtd::convolution {

  template <class T>
  auto bitwise_and(const std::vector<T>& a, const std::vector<T>& b) {
    auto za = mtd::zeta::bit_supset(a);
    auto zb = mtd::zeta::bit_supset(b);
    auto zab = std::vector<T>();
    for (auto i : std::views::iota(static_cast<size_t>(0), a.size())) {
      zab.emplace_back(za[i] * zb[i]);
    }
    auto zma = mtd::mobius::bit_supset(za);
    return mtd::mobius::bit_supset(zab);
  }

}  // namespace mtd::convolution
