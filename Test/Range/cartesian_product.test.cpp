#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/5/ITP1_5_A"
#include <iostream>

// begin:tag includes
#include "../../Library/Range/util.hpp"
// end:tag includes

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  while (true) {
    int h, w;
    std::cin >> h >> w;
    if (h == 0 && w == 0) { break; }

    for (auto [y, x] : mtd::views::cartesian_product(std::views::iota(0, h),
                                                     std::views::iota(0, w))) {
      std::cout << "#";
      if (x == w - 1) { std::cout << std::endl; }
    }
    std::cout << std::endl;
  }
}
