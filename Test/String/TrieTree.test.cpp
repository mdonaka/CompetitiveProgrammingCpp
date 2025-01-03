#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "./../../Library/String/TrieTree.hpp"

#include <iostream>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  std::string str;
  cin >> str;
  ll n;
  cin >> n;

  auto tree = mtd::TrieTree<bool, false>();
  for (int _ = 0; _ < n; ++_) {
    std::string s;
    cin >> s;
    std::vector<int> v(s.begin(), s.end());
    for (auto&& c : v) { c -= 'A'; }
    tree.emplace(v, true);
  }

  int sz = str.size();
  constexpr int ss = 10;
  ll ans = 0;
  for (int i = 0; i < sz; ++i) {
    std::vector<int> v;
    v.reserve(ss);
    for (int j = i; j < std::min(i + ss, sz); ++j) {
      v.emplace_back(str[j] - 'A');
    }
    tree.find(v, [&](bool) { ++ans; });
  }
  cout << ans << endl;
}
