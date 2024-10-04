#pragma once
#include <deque>
#include <iostream>
#include <map>
#include <stdexcept>

template <class ValType = long long, class SizeType = long long>
class SegmentMap {
  const SizeType n;
  std::map<SizeType, ValType> mp;

  auto add(SizeType i, ValType val, bool left = true, bool right = true) {
    auto it = std::prev(mp.upper_bound(i));
    if (right && std::next(it)->second == val) { mp.erase(std::next(it)); }
    if (left && it->second == val) { return; }
    mp.emplace(i, val);
  }

  template <class Iterator>
  auto remove(SizeType l, SizeType r, Iterator& it) {
    auto nx = std::next(it)->first;
    auto val = it->second;
    auto ret = std::next(it);
    if (l <= it->first) { ret = mp.erase(it); }
    if (r < nx - 1) { add(r + 1, val, false, true); }
    return ret;
  }

  auto remove(SizeType l, SizeType r) {
    auto it = std::prev(mp.upper_bound(l));
    while (it->first <= r) { it = remove(l, r, it); }
  }

public:
  SegmentMap(SizeType n) : n(n) {
    mp.emplace(-1, -1);
    mp.emplace(0, -2);
    mp.emplace(n, -1);
  }

  auto output() const {
    for (auto it = std::next(mp.begin()); it != std::prev(mp.end()); ++it) {
      std::cout << "[" << it->first << ", " << std::next(it)->first - 1
                << "] :" << it->second << std::endl;
    }
  }

  auto update(SizeType l, SizeType r, ValType val) {
    if (l < 0 || r >= n) { throw std::runtime_error(""); }
    if (l > r) { throw std::runtime_error(""); }
    remove(l, r);
    add(l, val);
  }

  /*
   * return: [{left, right, value}, ...]
   * */
  auto query(SizeType l, SizeType r) {
    if (l < 0 || r >= n) { throw std::runtime_error(""); }
    if (l > r) { throw std::runtime_error(""); }
    auto it = std::prev(mp.upper_bound(l));
    std::deque<std::tuple<SizeType, SizeType, ValType>> dq;
    while (it->first <= r) {
      auto nx = std::next(it)->first;
      auto nr = std::min(nx - 1, r);
      auto nl = std::max(l, it->first);
      dq.emplace_back(nl, nr, it->second);
      ++it;
    }
    return dq;
  }

  /*
   * return: {left, right, value}
   * */
  auto get(SizeType i) const {
    auto it = std::prev(mp.upper_bound(i));
    auto nx = std::next(it)->first;
    auto nr = nx - 1;
    auto nl = it->first;
    return std::make_tuple(nl, nr, it->second);
  }
};
