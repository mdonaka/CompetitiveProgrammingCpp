#pragma once

#include <utility>

namespace mtd {
  auto Y = [](auto f) {
    return [=](auto&&... args) {
      return f(f, std::forward<decltype(args)>(args)...);
    };
  };
}
