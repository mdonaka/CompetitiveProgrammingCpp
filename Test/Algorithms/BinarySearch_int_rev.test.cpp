#define PROBLEM "https://yukicoder.me/problems/no/91"

#include <iostream>
#include <vector>

// begin:tag includes
#include "./../../Library/Algorithms/BinarySearch.hpp"
// end:tag includes

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  std::vector<int> a(3);
  for (int i = 0; i < 3; ++i) { std::cin >> a[i]; }

  auto ans = mtd::binarySearch(0, static_cast<int>(1e9), [&](int mid) {
    int d = 0;
    for (auto x : a) {
      if (x >= mid) {
        d += ((x - mid) >> 1);
      } else {
        d -= mid - x;
      }
    }
    return d >= 0;
  });

  std::cout << ans << std::endl;
}
