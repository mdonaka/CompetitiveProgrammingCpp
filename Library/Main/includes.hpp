#pragma once

#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <ranges>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include "../Range/istream.hpp"
#include "../Utility/Tools.hpp"
#include "../Utility/io.hpp"

namespace mtd {

  struct Preprocessing {
    Preprocessing() {
      std::cin.tie(0);
      std::ios::sync_with_stdio(0);
    };
  } _Preprocessing;

  template <class T>
  using tvec = mtd::io::type::vec<T>;
  template <class T>
  using tmat = mtd::io::type::mat<T>;
  using mtd::io::in;

  template <class... Args>
  inline constexpr auto ins = mtd::views::istream<Args...>;
}  // namespace mtd
