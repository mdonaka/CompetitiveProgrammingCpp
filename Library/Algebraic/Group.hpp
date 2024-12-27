#pragma once

#include <iostream>

namespace mtd {

  template <class S,    // set
            S element,  // identity element
            class op,   // binary operation
            class inv   // inverse operation
            >
  requires std::is_invocable_r_v<S, op, S, S>
  struct Group {
    using value_type = S;
    constexpr static S _element = element;
    using op_type = op;
    using inv_type = inv;

    S m_val;
    constexpr Group() : m_val(element) {}
    constexpr Group(S val) : m_val(val) {}
    constexpr Group inverse() const { return inv()(m_val); }
    constexpr Group binaryOperation(const Group& g) const {
      return op()(m_val, g.m_val);
    }
    constexpr friend std::ostream& operator<<(
        std::ostream& os, const Group<S, element, op, inv>& g) {
      return os << g.m_val;
    }
  };

  namespace __detail {
    template <typename T,
              template <typename, auto, typename, typename> typename S>
    concept is_group_specialization_of = requires {
      typename std::enable_if_t<
          std::is_same_v<T, S<typename T::value_type, T::_element,
                              typename T::op_type, typename T::inv_type>>>;
    };
  }  // namespace __detail

  template <typename G>
  concept group = __detail::is_group_specialization_of<G, Group>;

}  // namespace mtd
