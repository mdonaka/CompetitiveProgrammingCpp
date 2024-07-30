#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B"
#include <iostream>

// tag:includes begin
#include "../../../Library/Range/mystd.hpp"
// tag:includes end

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::vector<int> v;
  while (std::cin) {
    int x;
    std::cin >> x;
    v.emplace_back(x);
  }

  for (auto [i, x] : myranges::enumerate_view(v) |
                         std::views::filter([](const std::tuple<int, int>& t) {
                           return std::get<1>(t) > 0;
                         })) {
    std::cout << "Case " << i + 1 << ": " << x << std::endl;
  }
}
