#pragma once
#include <numeric>

template <class Lambda>
auto binarySearch(double mn, double mx, int rep, const Lambda& judge,
                  bool rev = false) {
    auto ok = mx;
    auto ng = mn;
    for(int _ = 0; _ < rep; ++_) {
        auto mid = (ok + ng) / 2;
        auto isOk = judge(mid);
        if((isOk && !rev) || (!isOk && rev)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

template <class Lambda>
auto binarySearch(long long ok, long long ng, const Lambda& is_ok) {
    while(std::abs(ok - ng) > 1) {
        long long mid = (ok + ng) >> 1;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}
