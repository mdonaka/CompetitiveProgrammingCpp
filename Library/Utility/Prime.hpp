#pragma once

#include <deque>
#include <unordered_map>
#include <vector>

class Prime {
  const long long n;
  const std::deque<long long> p_list;

  static inline auto linearSieve(long long n) {
    std::deque<long long> p_list;
    std::vector<long long> lpf(n + 1);
    for (int d = 2; d < n + 1; ++d) {
      if (!lpf[d]) {
        lpf[d] = d;
        p_list.emplace_back(d);
      }
      for (const auto& p : p_list) {
        if (p * d > n || p > lpf[d]) { break; }
        lpf[p * d] = p;
      }
    }
    return std::tuple{p_list, lpf};
  }

public:
  Prime(long long n) : n(n), p_list(std::get<0>(linearSieve(n))) {}

  /* nはsqrt(max(x))あれば十分なので気を付ける */
  auto factorization(long long x) const {
    std::unordered_map<long long, long long> table;
    for (const auto& p : p_list) {
      while (x % p == 0) {
        table[p]++;
        x /= p;
      }
    }
    if (x > 1) { table[x]++; }
    return table;
  }
  auto getPList() const { return p_list; }
};
