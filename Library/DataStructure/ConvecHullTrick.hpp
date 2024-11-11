#pragma once

#include <deque>

namespace mtd {
  /*
   * 直線は傾きについて広義単調減少(最大値クエリの場合は広義単調増加)
   * クエリは広義単調増加
   */
  class ConvexHullTrick {
    using T = long long;
    std::deque<std::pair<T, T>> lines;

    static auto func(const std::pair<T, T>& line, const T& x) {
      return x * line.first + line.second;
    }
    static auto check(const std::pair<T, T>& line1,
                      const std::pair<T, T>& line2,
                      const std::pair<T, T>& line3) {
      auto [a1, b1] = line1;
      auto [a2, b2] = line2;
      auto [a3, b3] = line3;
      return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);
    }

  public:
    ConvexHullTrick() {}

    auto add(const std::pair<T, T>& line) {
      while (lines.size() > 1 &&
             check(*std::next(lines.rbegin()), *lines.rbegin(), line)) {
        lines.pop_back();
      }
      lines.emplace_back(line);
    }
    auto add(const T& a, const T& b) { add({a, b}); }

    auto query(const T& x) {
      while (lines.size() > 1 &&
             func(*lines.begin(), x) > func(*std::next(lines.begin()), x)) {
        lines.pop_front();
      }
      return func(*lines.begin(), x);
    }
  };
}  // namespace mtd
