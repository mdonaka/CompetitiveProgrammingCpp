#pragma once
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace mtd {

  class Mo {
    const int q;
    const std::vector<int> lq;
    const std::vector<int> rq;
    const std::vector<int> order;
    int ni, nl, nr;

    auto sort_query() const {
      std::vector<int> _order(q);
      std::iota(_order.begin(), _order.end(), 0);
      int w = static_cast<int>(std::sqrt(q));
      std::sort(_order.begin(), _order.end(), [&](int a, int b) {
        if (lq[a] / w != lq[b] / w) return lq[a] < lq[b];
        if (rq[a] == rq[b]) { return false; }
        bool less = (rq[a] < rq[b]);
        bool flg = (lq[a] / w) & 1;
        return static_cast<bool>(less ^ flg);
      });
      return _order;
    }

  public:
    Mo(int _q, const std::vector<int>& _lq, const std::vector<int>& _rq)
        : q(_q), lq(_lq), rq(_rq), order(sort_query()), ni(0), nl(0), nr(-1) {}

    template <class Lambda1, class Lambda2>
    auto process(const Lambda1& add, const Lambda2& del) {
      const auto l = lq[order[ni]];
      const auto r = rq[order[ni]];
      while (nl > l) { add(--nl); }
      while (nr < r) { add(++nr); }
      while (nl < l) { del(nl++); }
      while (nr > r) { del(nr--); }
      return order[ni++];
    }
  };

}  // namespace mtd
