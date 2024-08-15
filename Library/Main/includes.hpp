#pragma once

#include "../Range/istream.hpp"
#include "../Utility/io.hpp"

namespace mtd {

  template <class T, int Pre = 1, int Size = 0>
  using tvec = mtd::io::type::vec<T, Pre, Size>;
  using mtd::io::in;

  inline constexpr auto i = std::views::iota;
  template <class... Args>
  inline constexpr auto ins = mtd::views::istream<Args...>;
}  // namespace mtd
