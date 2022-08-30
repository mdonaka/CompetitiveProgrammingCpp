#pragma once
#include <vector>
#include <algorithm>

class CumulativeSum {
    using T = long long;

    const int size;
    std::vector<long long> sumList;
public:

    CumulativeSum() = delete;
    CumulativeSum(const std::vector<T>& v) :size(v.size()), sumList(size + 1) {
        for(int i = 0; i < size; ++i) {
            sumList[i + 1] = sumList[i] + v[i];
        }
    }
    T get(int n) {
        return sumList[n + 1];
    }
    T get(int l, int r) {
        if(r < l) { return 0LL; }
        l = std::max(l, 0); r = std::min(r, size - 1);
        return sumList[r + 1] - sumList[l];
    }
};
