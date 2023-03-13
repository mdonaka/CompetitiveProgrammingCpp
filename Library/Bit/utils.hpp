#pragma once
#include <deque>

unsigned ctz(unsigned int n) {
    #ifdef __GNUC__
    return __builtin_ctz(bit);
    #endif
    if(!n) return -1;
    unsigned int c = 32;
    n &= -static_cast<signed int>(n);
    if(n) c--;
    if(n & 0x0000FFFF) c -= 16;
    if(n & 0x00FF00FF) c -= 8;
    if(n & 0x0F0F0F0F) c -= 4;
    if(n & 0x33333333) c -= 2;
    if(n & 0x55555555) c -= 1;
    return c;
}

auto all_index(unsigned int bit) {
    std::deque<int> dq;
    while(bit) {
        auto i = ctz(bit);
        bit ^= (1LL << i);
        dq.emplace_back(i);
    }
    return dq;
}

auto count(unsigned int bit) {
    bit = (bit & 0x55555555) + (bit >> 1 & 0x55555555);
    bit = (bit & 0x33333333) + (bit >> 2 & 0x33333333);
    bit = (bit & 0x0f0f0f0f) + (bit >> 4 & 0x0f0f0f0f);
    bit = (bit & 0x00ff00ff) + (bit >> 8 & 0x00ff00ff);
    return (bit & 0x0000ffff) + (bit >> 16 & 0x0000ffff);
}