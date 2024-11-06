#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include <iostream>

// begin:tag includes
#include "../../Library/Math/Convolution.hpp"
#include "../../Library/Range/istream.hpp"
// end:tag includes
#include "../../Library/Debug/Dump.hpp"

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [n] = mtd::io::in<int>();
  auto a = mtd::io::_input<mtd::io::type::vec<int>>(1LL << n);
  auto b = mtd::io::_input<mtd::io::type::vec<int>>(1LL << n);

  auto ans = mtd::convolution::bitwise_and(a, b);
  for (auto x : ans) { std::cout << x << " "; }
  std::cout << std::endl;
}
