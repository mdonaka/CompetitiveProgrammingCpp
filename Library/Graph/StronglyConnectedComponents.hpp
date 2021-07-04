#pragma once

#include <unordered_map>
#include <stack>
#include <vector>
#include <list>

class SCC {
	const int m_n;
	const std::unordered_multimap<int, int> m_graph;
	const std::unordered_multimap<int, int> m_revGraph;
	const std::vector<int> m_group;

	auto reverse()const {
		std::unordered_multimap<int, int> graph;
		for (const auto& [f, t] : m_graph) { graph.emplace(t, f); }
		return graph;
	}

	template<class Lambda>
	auto dfs(int n,
		const std::unordered_multimap<int, int>& graph,
		int root,
		std::vector<int>& isUsed,
		const Lambda& lambda) const {
		isUsed[root] = true;
		std::stack<int> q; q.emplace(root);
		while (!q.empty()) {
			auto from = q.top();
			q.pop();

			auto range = graph.equal_range(from);
			for (auto itr = range.first; itr != range.second; ++itr) {
				auto to = itr->second;
				if (!isUsed[to]) {
					q.emplace(to);
					isUsed[to] = true;
					lambda(from, to);
				}
			}
		}
	}

	auto constructGroup()const {
		std::list<int> order;
		{
			std::vector<int> used(m_n);
			for (int from = 0; from < m_n; ++from) if (!used[from]) {
				std::list<int> localOrder;
				localOrder.emplace_front(from);
				dfs(m_n, m_graph, from, used, [&](int f, int t) {
					used[t] = true;
					localOrder.emplace_front(t);
				});
				for (const auto& x : localOrder) {
					order.emplace_front(x);
				}
			}
		}
		std::vector<int> group(m_n);
		{
			std::vector<int> used(m_n);

			int g = 0;
			for (const auto& from : order) if (!used[from]) {
				group[from] = g;
				dfs(m_n, m_revGraph, from, used, [&](int f, int t) {
					used[t] = true;
					group[t] = g;
				});
				++g;
			}
		}
		return group;
	}
public:
	SCC(int n, const std::unordered_multimap<int, int>& graph) :
		m_n(n),
		m_graph(graph),
		m_revGraph(reverse()),
		m_group(constructGroup()) {
	}

	auto isSameGroup(int a, int b)const {
		return m_group[a] == m_group[b];
	}
};