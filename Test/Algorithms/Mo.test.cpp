#define PROBLEM "https://yukicoder.me/problems/no/1471"

#include "./../../Library/Algorithms/Mo.hpp"

#include <iostream>
#include <map>

using ll = long long;
using std::cin;
using std::cout;
constexpr char endl = '\n';

signed main() {
  int n, q;
  cin >> n >> q;
  std::string s;
  cin >> s;

  std::vector<int> lq;
  lq.reserve(q);
  std::vector<int> rq;
  rq.reserve(q);
  std::vector<int> xv;
  xv.reserve(q);
  for (int _ = 0; _ < q; ++_) {
    int l, r, x;
    cin >> l >> r >> x;
    --l;
    --r;
    lq.emplace_back(l);
    rq.emplace_back(r);
    xv.emplace_back(x);
  }

  auto mo = mtd::Mo(q, lq, rq);

  std::map<char, int> mp;
  std::vector<char> ans(q);
  for (int _ = 0; _ < q; ++_) {
    auto i = mo.process([&](int i) { mp[s[i]]++; }, [&](int i) { mp[s[i]]--; });

    int cnt = 0;
    for (const auto& [c, x] : mp) {
      cnt += x;
      if (cnt >= xv[i]) {
        ans[i] = c;
        break;
      }
    }
  }

  for (const auto& c : ans) { cout << c << endl; }
}
