#pragma once
#include <vector>

#include "./../../debug.hpp"
namespace Geometry {

	class Vector {
		const std::vector<double> m_v;

	public:
		/* constructor */
		Vector(std::initializer_list<double>&& v) : m_v(std::forward<decltype(v)>(v)) {};

		/* output */
		friend std::ostream& operator<<(std::ostream& os, const Vector& p) {
			os << "{"; for (auto itr = p.m_v.begin(); itr != p.m_v.end(); ++itr) { os << *itr << ((itr == (--p.m_v.end())) ? "" : ", "); } cout << "}";;
			return os;
		}
	};
};