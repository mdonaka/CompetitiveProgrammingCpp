#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "./../../Library/Algorithms/EuclideanAlgorithm.hpp"

#include <iostream>
#include <tuple>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  ll x, y;
  cin >> x >> y;

  auto ea = EuclideanAlgorithm(x, y);
  auto [kl, kr] = ea.getMin();
  auto [la, lb] = ea.get(kl);
  auto [ra, rb] = ea.get(kr);

  ll lsum = std::abs(la) + std::abs(lb);
  ll rsum = std::abs(ra) + std::abs(rb);
  if (lsum < rsum || (lsum == rsum && la < ra)) {
    cout << la << " " << lb << endl;
  } else {
    cout << ra << " " << rb << endl;
  }
}