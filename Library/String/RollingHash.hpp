#pragma once

#include <array>
#include <ranges>
#include <string>
#include <vector>

namespace mtd {

  template <class T = long long,
            long long BASE = static_cast<long long>(1LL << 30),
            int HASH_USE = 5>
  class RollingHash {
    constexpr static int SIZE = 5;
    constexpr static std::array<T, SIZE> MOD_V = {
        998244353, 1000000007, 1000000009, 1000000021, 1000000033};

    std::vector<std::vector<T>> hash, power, inv;

    constexpr static auto pow = [](T a, T b, T mod) {
      T res = 1;
      while (b) {
        if (b & 1) { res = res * a % mod; }
        a = a * a % mod;
        b >>= 1;
      }
      return res;
    };

  public:
    constexpr RollingHash(const std::vector<T>& v)
        : hash(HASH_USE, v),
          power(HASH_USE, std::vector<T>(v.size(), 1)),
          inv(HASH_USE, std::vector<T>(v.size(), 1)) {
      for (auto mi : std::views::iota(0, HASH_USE)) {
        T inv_base = pow(BASE, MOD_V[mi] - 2, MOD_V[mi]);
        for (auto i : std::views::iota(1, static_cast<int>(v.size()))) {
          power[mi][i] = power[mi][i - 1] * BASE;
          power[mi][i] %= MOD_V[mi];
          hash[mi][i] += hash[mi][i - 1] * BASE;
          hash[mi][i] %= MOD_V[mi];
          inv[mi][i] = inv[mi][i - 1] * inv_base;
          inv[mi][i] %= MOD_V[mi];
        }
      }
    }

    constexpr auto calc_hash(int l, int r) const {
      std::vector<T> res;
      for (auto mi : std::views::iota(0, HASH_USE)) {
        auto val = hash[mi][r] - (l == 0 ? 0 : hash[mi][l - 1]) *
                                     power[mi][r - l + 1] % MOD_V[mi];
        if (val < 0) { val += MOD_V[mi]; }
        res.emplace_back(val);
      }
      return res;
    }
  };

}  // namespace mtd
