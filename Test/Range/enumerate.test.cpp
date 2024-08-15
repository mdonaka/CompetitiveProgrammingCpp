#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_B"
#include <iostream>

// tag:includes begin
#include "../../Library/Range/util.hpp"
#include "../../Library/Utility/io.hpp"
// tag:includes end

#include <vector>

#include "../../Library/Range/check.hpp"

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  for (auto [i, x] :
       mystd::views::istream<int>() | mystd::views::enumerate |
           std::views::filter([](const std::tuple<int, std::tuple<int>>& t) {
             return std::get<0>(std::get<1>(t)) > 0;
           })) {
    std::cout << "Case " << i + 1 << ": " << std::get<0>(x) << std::endl;
  }
}
