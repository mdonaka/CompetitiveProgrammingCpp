#pragma once

#include <utility>

auto Y = [](auto f) {
  return [=](auto&&... args) {
    return f(f, std::forward<decltype(args)>(args)...);
  };
};
