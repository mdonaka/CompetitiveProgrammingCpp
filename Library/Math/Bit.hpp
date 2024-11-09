#pragma once

namespace mtd {

  constexpr unsigned clz(unsigned int x) {
    int c = 0;
    if (x == 0) { return 0; }
    if (x & 0xffff0000) {
      x &= 0xffff0000;
      c |= 0x10;
    }
    if (x & 0xff00ff00) {
      x &= 0xff00ff00;
      c |= 0x08;
    }
    if (x & 0xf0f0f0f0) {
      x &= 0xf0f0f0f0;
      c |= 0x04;
    }
    if (x & 0xcccccccc) {
      x &= 0xcccccccc;
      c |= 0x02;
    }
    if (x & 0xaaaaaaaa) { c |= 0x01; }
    return c + 1;
  }

  constexpr unsigned ctz(unsigned int n) {
    if (!n) return -1;
    unsigned int c = 32;
    n &= -static_cast<signed int>(n);
    if (n) c--;
    if (n & 0x0000FFFF) c -= 16;
    if (n & 0x00FF00FF) c -= 8;
    if (n & 0x0F0F0F0F) c -= 4;
    if (n & 0x33333333) c -= 2;
    if (n & 0x55555555) c -= 1;
    return c;
  }

  constexpr unsigned long long popcount(unsigned long long x) {
    x = x - ((x >> 1) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    return x & 0x0000007f;
  }

}  // namespace mtd
