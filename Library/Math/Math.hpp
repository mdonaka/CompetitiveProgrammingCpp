#pragma once

#include <cmath>
#include <numeric>
#include <optional>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "./EuclideanAlgorithm.hpp"

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

    /* O(log b) */
    static constexpr T pow(T a, long long b) {
      T ans = 1;
      while (b > 0) {
        if (b & 1) { ans *= a; }
        b >>= 1;
        a *= a;
      }
      return ans;
    }

    /* O(log mod) */
    static constexpr std::optional<long long> log(
        typename T::value_type x, typename T::value_type y,
        typename T::value_type mod = T::mod()) requires requires {
      typename T::value_type;
      T::mod();
    }
    {
      using S = typename T::value_type;
      auto _pow = [](S a, S b, S mod) {
        S ans = 1;
        while (b > 0) {
          if (b & 1) { (ans *= a) %= mod; }
          b >>= 1;
          (a *= a) %= mod;
        }
        return ans;
      };
      x %= mod;
      y %= mod;

      if (T::mod() == 1) { return 0; }
      if (x == 0 && y == 0) { return 1; }
      if (x == 0 && y == 1) { return 0; }
      if (x == 0) { return std::nullopt; }
      if (y == 1) { return 0; }

      if (auto g = std::gcd(x, mod); g > 1) {
        if (y % g) { return std::nullopt; }
        auto nx = x / g;
        auto nmod = mod / g;
        auto ea = mtd::EuclideanAlgorithm(nx, -nmod, 1);
        auto [t, _] = ea.getMinX();
        auto [nx_inv, __] = ea.get(t);
        nx_inv %= nmod;
        if (auto ans = log(x, y / g * nx_inv, nmod); ans) {
          return ans.value() + 1;
        } else {
          return ans;
        }
      }

      auto s = static_cast<S>(std::sqrt(T::mod())) + 5;
      S xe = y;
      std::unordered_map<S, S> map;
      for (auto i : std::views::iota(0, s)) {
        (xe *= x) %= mod;
        map[xe] = i + 1;
      }

      S xs = 1;
      for ([[maybe_unused]] auto _ : std::views::iota(0, s)) {
        (xs *= x) %= mod;
      }
      S xse = 1;
      for (auto i : std::views::iota(0, s)) {
        (xse *= xs) %= mod;
        if (map.contains(xse)) { return s * (i + 1) - map[xse]; }
      }
      return std::nullopt;
    }

    constexpr auto fact(int n) const { return (n < 0) ? 0 : m_fac[n]; }
    constexpr auto factInv(int n) const { return (n < 0 ? 0 : m_finv[n]); }
    constexpr auto comb(int n, int r) const {
      return fact(n) * factInv(r) * factInv(n - r);
    }
    constexpr auto perm(int n, int r) const { return fact(n) * factInv(n - r); }
  };
}  // namespace mtd
