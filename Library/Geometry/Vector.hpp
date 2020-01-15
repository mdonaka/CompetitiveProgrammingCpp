#pragma once
#include <vector>

#include "./../../debug.hpp"
namespace Geometry {

	class Vector {
		const std::vector<double> m_v;

	public:
		/* constructor */
		Vector(std::vector<double>&& v) : m_v(std::forward<decltype(v)>(v)) {};
		//Vector(const std::vector<double>& v) : m_v(v) {};

		/* ì¡éÍä÷êî */
		auto norm() const {
			double sum = 0.0;
			for (const auto& x : m_v) { sum += (x * x); }
			return std::sqrt(sum);
		}
		auto innerProduct(const Vector& vec) const {
			double sum = 0.0;
			for (int i = 0; i < m_v.size(); ++i) { sum += m_v[i] * vec.m_v[i]; }
			return sum;
		}
		auto outerProduct(const Vector& vec)const {
			if (m_v.size() == 3) { return Vector({m_v[1] * vec.m_v[2] - m_v[2] * vec.m_v[1],m_v[2] * vec.m_v[0] - m_v[0] * vec.m_v[2],m_v[0] * vec.m_v[1] - m_v[1] * vec.m_v[0]}); }
			if (m_v.size() == 2) { return Vector({0.0,0.0,m_v[0] * vec.m_v[1] - m_v[1] * vec.m_v[0]}); }
			std::cout << m_v.size() << " dim outerProduct is not defined" << std::endl;
			exit(EXIT_FAILURE);
		}
		auto cos(const Vector& vec) const {
			auto norms = this->norm() * vec.norm();
			if (std::abs(norms) < 1e-5) { return 0.0; }
			return this->innerProduct(vec) / norms;
		}
		auto unit() const {
			return (*this / this->norm());
		}

		/* äeéÌââéZ */
		auto operator+(double d)const ->Vector {
			std::vector<double> v; v.reserve(m_v.size());
			for (const auto& x : m_v) { v.emplace_back(x + d); }
			return Vector(std::move(v));
		}
		auto operator+(const Vector& vec)const  ->Vector {
			std::vector<double> v; v.reserve(m_v.size());
			for (int i = 0; i < m_v.size(); ++i) { v.emplace_back(m_v[i] + vec.m_v[i]); }
			return Vector(std::move(v));
		}
		template<class T>
		auto operator-(T d)const ->Vector { return operator+(d * (-1)); }
		auto operator*(double d)const ->Vector {
			std::vector<double> v; v.reserve(m_v.size());
			for (const auto& x : m_v) { v.emplace_back(x * d); }
			return Vector(std::move(v));
		}
		auto operator*(const Vector& vec)const ->Vector {
			std::vector<double> v; v.reserve(m_v.size());
			for (int i = 0; i < m_v.size(); ++i) { v.emplace_back(m_v[i] * vec.m_v[i]); }
			return Vector(std::move(v));
		}
		auto operator/(double d)const ->Vector { return operator*(1.0 / d); }
		auto operator==(const Vector& vec) {
			bool equal = true;
			for (int i = 0; i < m_v.size(); ++i) { equal &= (std::abs(m_v[i] - vec.m_v[i]) < 1e-5); }
			return equal;
		}
		auto operator[](int n)const { return m_v[n]; }

		/* output */
		friend std::ostream& operator<<(std::ostream& os, const Vector& p) {
			os << "{"; for (auto itr = p.m_v.begin(); itr != p.m_v.end(); ++itr) { os << *itr << ((itr == (--p.m_v.end())) ? "" : ", "); } cout << "}";;
			return os;
		}
		auto getVector()const { return m_v; }
	};
};