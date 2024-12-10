#pragma once

#include <iostream>

namespace mtd {

  template <class S,  // set
            class op  // binary operation
            >
  requires std::is_invocable_r_v<S, op, S, S>
  struct SemiGroup {
    using value_type = S;
    using op_type = op;

    S m_val;
    constexpr SemiGroup(S val) : m_val(val) {}
    constexpr SemiGroup binaryOperation(const SemiGroup& s) const {
      return op()(m_val, s.m_val);
    }
    constexpr friend std::ostream& operator<<(std::ostream& os,
                                              const SemiGroup<S, op>& s) {
      return os << s.m_val;
    }
  };

  namespace __detail {
    template <typename T, template <typename, typename> typename S>
    concept is_specialization_of = requires {
      typename std::enable_if_t<
          std::is_same_v<T, S<typename T::value_type, typename T::op_type>>>;
    };
  }  // namespace __detail

  template <typename G>
  concept semigroup = __detail::is_specialization_of<G, SemiGroup>;

}  // namespace mtd
