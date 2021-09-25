#pragma once
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>


class LowestCommonAncestor {
	const std::vector<std::vector<int>> m_parent;
	const std::vector<int> m_depth;

	auto constructParent(int n, const std::unordered_multimap<int, int>& tree, int root) const {
		int toSize = std::log2(n) + 1;
		std::vector<std::vector<int>> parent(n, std::vector<int>(toSize, root));
		std::queue<int> q;
		q.emplace(root);
		std::vector<int> used(n);
		used[root] = true;
		while (!q.empty()) {
			auto from = q.front();
			q.pop();
			auto range = tree.equal_range(from);
			for (auto it = range.first; it != range.second; ++it) {
				auto to = it->second;
				if (!used[to]) {
					q.emplace(to);
					used[to] = true;
					parent[to][0] = from;
				}
			}
		}
		for (int p2 = 1; p2 < toSize; ++p2)for (int f = 0; f < n; ++f) {
			parent[f][p2] = parent[parent[f][p2 - 1]][p2 - 1];
		}
		return parent;
	}
	auto constructDepth(int n, const std::unordered_multimap<int, int>& tree, int root)const {
		std::vector<int> depth(n);
		std::queue<int> q;
		q.emplace(root);
		std::vector<int> used(n);
		used[root] = true;
		while (!q.empty()) {
			auto from = q.front();
			q.pop();
			auto range = tree.equal_range(from);
			for (auto it = range.first; it != range.second; ++it) {
				auto to = it->second;
				if (!used[to]) {
					q.emplace(to);
					used[to] = true;
					depth[to] = depth[from] + 1;
				}
			}
		}
		return depth;
	}
public:
	LowestCommonAncestor(int n, const std::unordered_multimap<int, int>& tree, int root) :
		m_parent(constructParent(n, tree, root)),
		m_depth(constructDepth(n, tree, root)) {
	}

	auto lca(int l, int r)const {
		const int toSize = m_parent[0].size();
		if (m_depth[l] < m_depth[r]) { std::swap(l, r); }
		for (int k = 0; k < toSize; ++k) {
			if (((m_depth[l] - m_depth[r]) >> k) & 1) {
				l = m_parent[l][k];
			}
		}
		if (l == r) { return l; }
		for (int k = toSize - 1; k >= 0; k--) {
			if (m_parent[l][k] != m_parent[r][k]) {
				l = m_parent[l][k];
				r = m_parent[r][k];
			}
		}
		return m_parent[l][0];
	}
};