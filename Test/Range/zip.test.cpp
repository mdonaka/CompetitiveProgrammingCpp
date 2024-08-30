#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B"
#include <iostream>

// begin:tag includes
#include "../../Library/Range/istream.hpp"
#include "../../Library/Range/util.hpp"
// end:tag includes

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto istream = mtd::views::istream<int>();
  auto iota = std::views::iota(0);
  for (auto [i, x] : mtd::views::zip(iota, istream)) {
    if (std::get<0>(x) == 0) { break; }
    std::cout << "Case " << i + 1 << ": " << std::get<0>(x) << std::endl;
  }
}
