#pragma once
#include <iostream>
#include <map>
#include <stdexcept>
#include <deque>

class SegmentMap {
    const int n;
    std::map<int, int> mp;

    auto add(int i, int val, bool left = true, bool right = true) {
        auto it = std::prev(mp.upper_bound(i));
        if(right && std::next(it)->second == val) { mp.erase(std::next(it)); }
        if(left && it->second == val) { return; }
        mp.emplace(i, val);

    }

    auto remove(int l, int r, const decltype(mp)::iterator& it) {
        auto nx = std::next(it)->first;
        auto val = it->second;
        auto ret = std::next(it);
        if(l <= it->first) { ret = mp.erase(it); }
        if(r < nx - 1) { add(r + 1, val, false, true); }
        return ret;
    }

    auto remove(int l, int r) {
        auto it = std::prev(mp.upper_bound(l));
        while(it->first <= r) {
            it = remove(l, r, it);
        }
    }


public:

    SegmentMap(int n) :n(n) {
        mp.emplace(-1, -1);
        mp.emplace(0, -2);
        mp.emplace(n, -1);
    }

    auto output() const {
        for(auto it = std::next(mp.begin()); it != std::prev(mp.end()); ++it) {
            std::cout << "[" << it->first << ", " <<
                std::next(it)->first - 1 << "] :" <<
                it->second << std::endl;
        }
    }

    auto update(int l, int r, int val) {
        if(l < 0 || r >= n) { throw std::runtime_error(""); }
        if(l > r) { throw std::runtime_error(""); }
        remove(l, r);
        add(l, val);
    }

    auto query(int l, int r) {
        if(l < 0 || r >= n) { throw std::runtime_error(""); }
        if(l > r) { throw std::runtime_error(""); }
        auto it = std::prev(mp.upper_bound(l));
        std::deque<std::pair<int, std::pair<int, int>>> dq;
        while(it->first <= r) {
            int nx = std::next(it)->first;
            int nr = std::min(nx - 1, r);
            int nl = std::max(l, it->first);
            dq.emplace_back(it->second, std::pair<int, int>{nl,nr});
            ++it;
        }
        return dq;
    }

    auto get(int i) {
        auto it = std::prev(mp.upper_bound(i));
        int nx = std::next(it)->first;
        int nr = nx - 1;
        int nl = it->first;
        return std::pair{it->second,std::pair{nl,nr}};
    }

};