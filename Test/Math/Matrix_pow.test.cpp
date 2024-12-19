#define PROBLEM "https://yukicoder.me/problems/no/1136"

#include <iostream>

// begin:tag includes
#include "../../Library/Math/Matrix.hpp"
#include "../../Library/Math/ModInt.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  constexpr long long MOD = 1e9 + 7;
  using mint = mtd::ModInt<MOD>;

  long long n;
  std::cin >> n;

  mtd::Matrix<mint> mat({{-1, 1}, {0, 3}});
  auto mat_p = mat.pow(n);
  mint ans = mat_p[0][0] + mat_p[0][1];
  std::cout << ans << std::endl;
}
