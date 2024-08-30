#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1009"

// tag:includes begin
#include "../../Library/Range/istream.hpp"
#include "./../../Library/Algorithms/EuclideanAlgorithm.hpp"
// tag:includes end

#include <iostream>

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  for (auto [x, y] : mtd::views::istream<int, int>()) {
    auto ea = EuclideanAlgorithm(x, y);
    std::cout << ea.gcd() << std::endl;
  }
}
