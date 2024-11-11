#pragma once

#include <algorithm>
#include <cmath>
#include <complex>
#include <stack>
#include <vector>

namespace mtd {
  class ConvexHull {
    using Point = std::complex<long double>;
    const static inline long double pi = std::acos(-1);

    static inline auto arg(const Point& p) {
      auto a = std::arg(p);
      return ((a < 0.0) ? a + 2 * pi : a);
    }

  public:
    static auto grahamScan(const std::vector<Point>& points) {
      auto ps = points;
      auto mn = ps[0];
      for (const auto& p : ps)
        if (p.imag() < mn.imag()) { mn = p; }

      std::sort(ps.begin(), ps.end(), [&](const Point& a, const Point& b) {
        auto arg_a = arg(a - mn);
        auto arg_b = arg(b - mn);
        if (std::abs(arg_a - arg_b) < 1e-9) {
          return std::abs(a - mn) < std::abs(b - mn);
        }
        return arg_a < arg_b;
      });

      auto cf = std::stack<Point>();
      for (const auto& p : ps)
        while (true) {
          if (cf.size() < 2) {
            cf.emplace(p);
            break;
          }
          auto p1 = cf.top();
          cf.pop();
          auto p2 = cf.top();
          auto arg1 = arg(p1 - p2);
          auto arg2 = arg(p - p2);
          if (arg1 < arg2 || std::abs(arg1 - arg2) < 1e-9) {
            cf.emplace(p1);
            cf.emplace(p);
            break;
          }
        }

      auto arg_mx = arg(cf.top() - mn);
      std::stack<Point> line;
      for (const auto& p : ps) {
        auto arg_l = arg(p - mn);
        if (std::abs(arg_mx - arg_l) < 1e-9) { line.emplace(p); }
      }
      cf.pop();
      while (!line.empty()) {
        cf.emplace(line.top());
        line.pop();
      }

      auto rev = decltype(ps)();
      rev.reserve(cf.size());
      while (!cf.empty()) {
        rev.emplace_back(cf.top());
        cf.pop();
      }
      std::reverse(rev.begin(), rev.end());
      return rev;
    }
  };
}  // namespace mtd
