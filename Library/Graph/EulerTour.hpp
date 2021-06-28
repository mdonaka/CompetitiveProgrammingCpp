#pragma once
#include <stack>
#include <vector>
#include <unordered_map>

class EulerTour {
	const std::vector<int> m_tour;
	const std::vector<std::pair<int, int>> m_appear;

	auto constructTour(int n, const std::unordered_multimap<int, int>& tree, int root) const {
		std::vector<int> tour;
		tour.reserve(2 * n);
		std::stack<int> stk;
		std::vector<int> used(n);
		stk.emplace(root);
		while (!stk.empty()) {
			auto from = stk.top();
			tour.emplace_back(from);
			stk.pop();
			if (used[from]) { continue; }
			stk.emplace(from);
			used[from] = true;

			auto range = tree.equal_range(from);
			for (auto it = range.first; it != range.second; ++it) {
				auto to = it->second;
				if (!used[to]) {
					stk.emplace(to);
				}
			}
		}
		return tour;
	}
	auto constructAppear(int n) const {
		std::vector<std::pair<int, int>> appear(n, { -1,-1 });
		for (int i = 0; i < 2 * n; ++i) {
			if (appear[m_tour[i]].first == -1) {
				appear[m_tour[i]].first = i;
			} else {
				appear[m_tour[i]].second = i;
			}
		}
		return appear;
	}
public:
	EulerTour(int n, const std::unordered_multimap<int, int>& tree, int root)
		:m_tour(constructTour(n, tree, root)),
		m_appear(constructAppear(n)) {
	}

	auto lessOrder(int li, int ri)const {
		return m_appear[li].first < m_appear[ri].first;
	}
	auto isSon(int son, int parent) {
		return m_appear[parent].first < m_appear[son].first&&
			m_appear[son].second < m_appear[parent].second;
	}
};