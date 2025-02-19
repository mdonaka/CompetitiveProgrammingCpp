#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "./../../Library/String/ZAlgorithm.hpp"

#include <iostream>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';
struct Preprocessing {
  Preprocessing() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
  };
} _Preprocessing;

signed main() {
  std::string p, t;
  cin >> p >> t;

  std::string s = t + "$" + p;
  auto za = mtd::ZAlgorithm(s);

  int tsz = t.size();
  int ssz = s.size();
  auto ans = za.find(tsz, ssz - 1, tsz);

  for (const auto& it : ans) { cout << it - tsz - 1 << endl; }
}
