#pragma once

#include <vector>
#include <deque>

class Prime {
public:
	static inline auto linearSieve(int n) {
		std::deque<int> p_list;
		std::vector<int> lpf(n + 1);
		for (int d = 2; d < n + 1; ++d) {
			if (!lpf[d]) {
				lpf[d] = d;
				p_list.emplace_back(d);
			}
			for (const auto& p : p_list) {
				if (p * d > n || p > lpf[d]) { break; }
				lpf[p * d] = p;
			}
		}
		return std::tuple{ p_list,lpf };
	}
};
