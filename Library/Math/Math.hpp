#pragma once

#include <vector>

namespace mtd {
  template <class T>
  class Math {
    const std::vector<T> m_fac;
    const std::vector<T> m_finv;

    auto constructFac(int s) {
      std::vector<T> fac(s);
      fac[0] = fac[1] = 1;
      for (long long i = 2; i < s; ++i) { fac[i] = fac[i - 1] * i; }
      return fac;
    }
    auto constructInv(int s) {
      std::vector<T> finv(s);
      finv[s - 1] = 1 / m_fac[s - 1];
      for (long long i = s - 2; i >= 0; --i) {
        finv[i] = finv[i + 1] * (i + 1);
      }
      return finv;
    }

  public:
    constexpr Math(int size = 3 * static_cast<int>(1e6))
        : m_fac(constructFac(size)), m_finv(constructInv(size)) {}

    static constexpr T pow(T a, long long b) {
      T ans = 1;
      while (b > 0) {
        if (b & 1) { ans *= a; }
        b >>= 1;
        a *= a;
      }
      return ans;
    }
    constexpr auto fact(int n) const { return (n < 0) ? 0 : m_fac[n]; }
    constexpr auto factInv(int n) const { return (n < 0 ? 0 : m_finv[n]); }
    constexpr auto comb(int n, int r) const {
      return fact(n) * factInv(r) * factInv(n - r);
    }
    constexpr auto perm(int n, int r) const { return fact(n) * factInv(n - r); }
  };
}  // namespace mtd
