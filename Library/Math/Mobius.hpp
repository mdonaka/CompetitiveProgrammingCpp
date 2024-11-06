
#include <ranges>
#include <vector>

namespace mtd::mobius {

  template <class T>
  auto n(const std::vector<T>& a) {
    auto ret = a;
    for (auto i : std::views::iota(static_cast<size_t>(1), a.size())) {
      ret[i] = a[i] - a[i - 1];
    }
    return ret;
  }

  template <class T>
  auto bit_subset(const std::vector<T>& a) {
    auto ret = a;
    int size = clz(a.size());
    for (auto b : std::views::iota(0, size)) {
      for (auto bit : std::views::iota(0, 1LL << size)) {
        if (((bit >> b) & 1) && bit < a.size()) {
          ret[bit] -= ret[bit ^ (1LL << b)];
        }
      }
    }
    return ret;
  }

}  // namespace mtd::mobius
