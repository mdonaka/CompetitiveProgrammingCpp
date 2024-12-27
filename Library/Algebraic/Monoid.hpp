#pragma once

#include <iostream>

namespace mtd {

  template <class S,    // set
            S element,  // identity element
            class op    // binary operation
            >
  requires std::is_invocable_r_v<S, op, S, S>
  struct Monoid {
    using value_type = S;
    constexpr static S _element = element;
    using op_type = op;

    S m_val;
    constexpr Monoid(S val) : m_val(val) {}
    constexpr Monoid() : Monoid(element) {}
    constexpr Monoid binaryOperation(const Monoid& m2) const {
      return op()(m_val, m2.m_val);
    }
    friend std::ostream& operator<<(std::ostream& os,
                                    const Monoid<S, element, op>& m) {
      return os << m.m_val;
    }
  };

  namespace __detail {
    template <typename T, template <typename, auto, typename> typename S>
    concept is_monoid_specialization_of = requires {
      typename std::enable_if_t<std::is_same_v<
          T, S<typename T::value_type, T::_element, typename T::op_type>>>;
    };
  }  // namespace __detail

  template <typename M>
  concept monoid = __detail::is_monoid_specialization_of<M, Monoid>;

}  // namespace mtd
