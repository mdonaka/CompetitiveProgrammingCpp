#pragma once

#include <cassert>
#include <iostream>
#include <vector>

namespace mtd {
  template <class T>
  class Matrix {
    int h, w;
    std::vector<std::vector<T>> mat;

  public:
    Matrix(const std::vector<std::vector<T>>& _mat)
        : h(_mat.size()), w(_mat[0].size()), mat(_mat) {}

    inline static auto identity(int size) {
      std::vector<std::vector<T>> ret(size, std::vector<T>(size));
      for (int i = 0; i < size; ++i) { ret[i][i] = 1; }
      return Matrix(ret);
    }

    auto begin() const { return mat.begin(); }
    auto end() const { return mat.end(); }

    const auto& operator[](int i) const { return mat[i]; }
    auto& operator[](int i) { return mat[i]; }

    auto operator*(const Matrix& tgt) const {
      assert(w == tgt.h);
      std::vector<std::vector<T>> ret(h, std::vector<T>(tgt.w));
      for (int i = 0; i < h; ++i)
        for (int j = 0; j < tgt.w; ++j) {
          for (int k = 0; k < w; ++k) { ret[i][j] += mat[i][k] * tgt[k][j]; }
        }
      return Matrix(ret);
    }

    auto pow(long long n) const {
      assert(h == w);
      auto ret = identity(h);
      auto now = *this;
      while (n) {
        if (n & 1) { ret = ret * now; }
        n >>= 1;
        now = now * now;
      }
      return ret;
    }
  };
}  // namespace mtd
