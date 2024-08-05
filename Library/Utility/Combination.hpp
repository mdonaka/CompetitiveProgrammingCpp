#pragma once
#include <vector>

#include "./ModCalculator.hpp"

/**
 *	MODなしcombination
 *	n< 51, r<51
 */
long long combFast(long long a, long long b) {
  ++a;
  static long long now = 1;
  static std::vector<std::vector<long long>> pascalComb(1);
  pascalComb.reserve(51);
  if (a < now) { return pascalComb[a][b]; }
  for (; now < a + 1; ++now) {
    std::vector<long long> v(now);
    v[0] = v[now - 1] = 1;
    for (long long j = 1; j < now - 1; ++j) {
      v[j] = pascalComb[now - 1][j - 1] + pascalComb[now - 1][j];
    }
    pascalComb.emplace_back(v);
  }
  return pascalComb[a][b];
}

/**
 *	シンプルcombination
 *	O(r)
 */
long long combSimple(long long a, long long b, long long MOD) {
  if (b > a - b) { return combSimple(a, a - b, MOD); }
  long long ans = 1;
  for (long long i = 0; i < b; ++i) {
    ans *= a - i;
    ans %= MOD;
  }
  long long t = 1;
  for (long long i = 1; i < b + 1; ++i) {
    t *= i;
    t %= MOD;
  }
  ans *= calc.pow(t, MOD - 2);
  ans %= MOD;
  return ans;
}