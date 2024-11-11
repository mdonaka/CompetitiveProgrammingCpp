#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>

// begin:tag includes
#include "../../Library/Math/ModInt.hpp"
#include "../../Library/Range/istream.hpp"
// end:tag includes

auto parse(const std::string s) {
  long long a = 0, b = 0;
  bool isa = true;
  for (unsigned int i = 2; i < s.size() - 1; ++i) {
    if (s[i] == ',') {
      isa = false;
      continue;
    }
    auto& x = ((isa) ? a : b);
    x = 10 * x + (s[i] - '0');
  }
  return std::make_pair(a, b);
}

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [t] = mtd::io::in<int>();

  constexpr long long MOD = 1e9 + 7;
  using mint = mtd::ModInt<MOD>;
  auto math = mtd::Math<mint>();
  for (auto [s] : mtd::views::istream<std::string>(t)) {
    auto [n, k] = parse(s);
    if (s[0] == 'C') {
      std::cout << math.comb(n, k) << std::endl;
    } else if (s[0] == 'P') {
      std::cout << math.perm(n, k) << std::endl;
    } else {
      std::cout << math.comb(std::max(0LL, n + k - 1), k) << std::endl;
    }
  }
}
