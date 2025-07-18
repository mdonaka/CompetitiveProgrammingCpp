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
#include <queue>
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

}  // namespace mtd
