#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B"
#include <iostream>

// tag:includes begin
#include "../../Library/Range/istream.hpp"
#include "../../Library/Range/util.hpp"
// tag:includes end

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  for (auto [i, x] : mtd::views::istream<int>() | mtd::views::enumerate |
                         mtd::views::flatten) {
    if (x == 0) { break; }
    std::cout << "Case " << i + 1 << ": " << x << std::endl;
  }
}
