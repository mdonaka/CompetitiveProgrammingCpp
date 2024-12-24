#define PROBLEM "https://yukicoder.me/problems/no/415"

// begin:tag includes
#include "../../Library/Math/EuclideanAlgorithm.hpp"
#include "../../Library/Utility/io.hpp"
// end:tag includes

#include <iostream>

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [n, d] = mtd::io::in<int, int>();
  auto ea = mtd::EuclideanAlgorithm(n, d);
  std::cout << n / ea.gcd() - 1 << std::endl;
}
