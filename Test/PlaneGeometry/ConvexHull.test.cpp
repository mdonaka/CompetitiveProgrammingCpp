#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"

#include "./../../Library/PlaneGeometry/ConvexHull.hpp"

#include <iostream>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n;
  cin >> n;
  std::vector<std::complex<long double>> points;
  points.reserve(n);
  for (int _ = 0; _ < n; ++_) {
    int x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }

  auto cf = mtd::ConvexHull::grahamScan(points);
  int size = cf.size();

  int idx = 0;
  for (int i = 1; i < size; ++i) {
    if (cf[i].imag() < cf[idx].imag()) {
      idx = i;
      continue;
    }
    if (cf[i].imag() < cf[idx].imag() && cf[i].real() < cf[idx].real()) {
      idx = i;
      continue;
    }
  }

  cout << cf.size() << endl;
  for (int i = 0; i < size; ++i) {
    auto p = cf[(i + idx) % size];
    cout << p.real() << " " << p.imag() << endl;
  }
}
