#pragma once

#include <vector>
#include <deque>
#include <unordered_map>

class Prime {
	const int n;
	const std::deque<int> p_list;

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

	Prime(int n) :n(n), p_list(std::get<0>(linearSieve(n))) {}

	/* n‚Ísqrt(max(x))‚ ‚ê‚Î\•ª‚È‚Ì‚Å‹C‚ğ•t‚¯‚é */
	auto factorization(int x) const {
		std::unordered_map<int, int> table;
		for (const auto& p : p_list) {
			while (x % p == 0) {
				table[p]++;
				x /= p;
			}
		}
		if (x > 1) { table[x]++; }
		return table;
	}

};
