#pragma once

#include <vector>

namespace mtd {

  template <class T, class S>
  inline auto chmax(T& t, const S& s) {
    if (s > t) {
      t = s;
      return true;
    }
    return false;
  }

  template <class T, class S>
  inline auto chmin(T& t, const S& s) {
    if (s < t) {
      t = s;
      return true;
    }
    return false;
  }

  template <class S>
  constexpr auto vec(S x) {
    return x;
  }

  template <class S, class... T>
  constexpr auto vec(S x, int n, T... ns) {
    return std::vector(n, vec(x, ns...));
  }

}  // namespace mtd
