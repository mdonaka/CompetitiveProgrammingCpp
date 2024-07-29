#pragma once
#include <iostream>
#include <vector>

#include "./tmp.hpp"

auto f() {
  check::iterator<std::vector<int>>();
  check::range(std::vector<int>());
}
