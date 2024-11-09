#define PROBLEM "https://yukicoder.me/problems/no/1469"

// begin:tag includes
#include "../../Library/DataStructure/RunLengthEncoding.hpp"

#include "../../Library/Range/istream.hpp"
// end:tag includes

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  auto [s] = mtd::io::in<std::string>();
  auto rle = mtd::RunLengthEncoding(s);
  for (auto [c, _] : rle) { std::cout << c; }
  std::cout << std::endl;
}
