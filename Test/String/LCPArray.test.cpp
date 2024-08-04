#define PROBLEM "https://yukicoder.me/problems/no/599"

#include "./../../Library/String/LCPArray.hpp"

#include <iostream>

#include "./../../Library/DataStructure/SegmentTree.hpp"

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

struct F {
  auto operator()(int a, int b) const { return std::min(a, b); };
};
using M = Monoid<int, static_cast<int>(1e9), F>;

constexpr ll MOD = 1000000007;

signed main() {
  std::string s;
  cin >> s;

  ll size = s.size();
  auto lcparray = LCPArray(s);
  auto segtree = SegmentTree<M>(size, lcparray.getLCPArray());
  auto sai = lcparray.getSuffixArrayIndexList();

  ll half = (size >> 1);
  std::vector<ll> dp(half + 1);
  dp[0] = 1;
  for (int l = 0; l < half; ++l) {
    for (int r = l; r < half; ++r) {
      auto idx1 = sai[l];
      auto idx2 = sai[size - r - 1];
      if (idx2 < idx1) { std::swap(idx1, idx2); }
      auto lcp = segtree.query(idx1, idx2 - 1);

      int len = r - l + 1;
      if (lcp >= len) {
        dp[r + 1] += dp[l];
        if (dp[r + 1] >= MOD) { dp[r + 1] -= MOD; }
      }
    }
  }

  ll ans = 0;
  for (const auto& x : dp) {
    ans += x;
    if (ans >= MOD) { ans -= MOD; }
  }
  cout << ans;
}
