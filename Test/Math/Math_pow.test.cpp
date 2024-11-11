#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

// begin:tag includes
#include "../../Library/Math/ModInt.hpp"
#include "../../Library/Range/istream.hpp"

// end:tag includes
#include <iostream>
#include <string>

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [m, n] = mtd::io::in<int, int>();

  constexpr long long MOD = 1e9 + 7;
  using mint = mtd::ModInt<MOD>;
  auto math = mtd::Math<mint>();

  std::cout << math.pow(m, n) << std::endl;
}
