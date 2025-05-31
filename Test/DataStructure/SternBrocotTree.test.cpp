#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include <iostream>
#include <ranges>

// begin:tag includes
#include "./../../Library/DataStructure/SternBrocotTree.hpp"
// end:tag includes

using ll = long long;

signed main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int t;
  std::cin >> t;
  mtd::SternBrocotTree<ll> sbt;
  for (auto _ : std::views::iota(0, t)) {
    std::string s;
    std::cin >> s;

    if (s == "ENCODE_PATH") {
      ll a, b;
      std::cin >> a >> b;
      auto path_rle = sbt.encode(a, b);
      std::cout << path_rle.size() << (path_rle.empty() ? "" : " ");
      for (const auto& [i, right, k] :
           path_rle | mtd::views::enumerate | mtd::views::flatten) {
        std::cout << (right ? 'R' : 'L') << " " << k
                  << (i == path_rle.size() - 1 ? "" : " ");
      }
      std::cout << std::endl;
    }

    if (s == "DECODE_PATH") {
      ll k;
      std::cin >> k;
      std::vector<std::tuple<ll, ll>> path_rle;
      for (auto __ : std::views::iota(0, k)) {
        char c;
        ll n;
        std::cin >> c >> n;
        path_rle.emplace_back(c == 'R', n);
      }
      auto [a, b] = sbt.decode(path_rle).get();
      std::cout << a << " " << b << std::endl;
    }

    if (s == "LCA") {
      ll a, b, c, d;
      std::cin >> a >> b >> c >> d;
      auto [f, g] = sbt.lca(a, b, c, d).get();
      std::cout << f << " " << g << std::endl;
    }

    if (s == "ANCESTOR") {
      ll k, a, b;
      std::cin >> k >> a >> b;
      try {
        auto [f, g] = sbt.ancestor(a, b, k).get();
        std::cout << f << " " << g << std::endl;
      } catch (const std::runtime_error& e) { std::cout << -1 << std::endl; }
    }

    if (s == "RANGE") {
      ll a, b;
      std::cin >> a >> b;
      try {
        auto [node_l, node_r] = sbt.range(a, b);
        auto [f, g] = node_l.get();
        auto [h, k] = node_r.get();
        std::cout << f << " " << g << " " << h << " " << k << std::endl;
      } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
      }
    }
  }
}
