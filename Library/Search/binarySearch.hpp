#pragma once

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
auto binarySearch(long long mn, long long mx, const Lambda& judge, bool rev = false) {
    auto ok = mx + rev;
    auto ng = mn - 1;
    while(ok - ng > 1) {
        auto mid = (ok + ng) / 2;
        auto isOk = judge(mid);
        if((isOk && !rev) || (!isOk && rev)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok - rev;
}
