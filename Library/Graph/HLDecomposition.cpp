
class HLDecomposition {
	std::unordered_multimap<int, int> m_graph;
	std::unordered_map<int, int> m_graphRev;

	const int m_root;
	std::vector<int> m_nodeList;
	std::vector<int> m_nodeListPos;
	std::vector<int> m_nodeCostList;
	std::vector<std::pair<int, int>> m_nodeRange;

	static auto reverse(const std::unordered_multimap<int, int>& graph) {
		std::unordered_map<int, int> graphRev;
		for (const auto& p : graph) { graphRev.emplace(p.second, p.first); }
		return graphRev;
	}

	static auto getRoot(int size, const unordered_multimap<int, int>& graph) {
		std::vector<bool> children(size, false);
		for (const auto& p : graph) { children[p.second] = true; }
		for (int i = 0; i < size; ++i)if (!children[i]) { return i; }
	}

	static auto getTreeSize(int size, const unordered_multimap<int, int>& graph, int root) {
		auto treeSize = std::vector<int>(size, 1);
		auto calcTreeSize = [&](auto f, auto from) {
			auto range = graph.equal_range(from);
			if (range.first == range.second) {

				return;
			}
			for (auto itr = range.first; itr != range.second; ++itr) {
				auto to = itr->second;
				f(f, to);
				treeSize[from] += treeSize[to];
			}
		};
		calcTreeSize(calcTreeSize, root);
		return treeSize;
	}

	auto decomposition(const unordered_multimap<int, int>& graph, const std::vector<int>& nodeCost, const std::vector<int>& tSize, int now, int&& nodeFrom) {
		if (nodeFrom == -1) { nodeFrom = now; }
		m_nodeList.emplace_back(now);
		m_nodeCostList.emplace_back(nodeCost[now]);
		m_nodeListPos[now] = m_nodeList.size() - 1;
		m_nodeRange.emplace_back(m_nodeListPos[nodeFrom], -1);
		auto range = graph.equal_range(now);
		if (range.first == range.second) {
			for (int f = m_nodeListPos[nodeFrom]; f <= m_nodeListPos[now]; ++f) {
				m_nodeRange[f].second = m_nodeListPos[now];
			}
			nodeFrom = -1;
			return;
		}
		auto large = -1;
		auto sMax = -1;
		for (auto itr = range.first; itr != range.second; ++itr) {
			auto to = itr->second;
			if (tSize[to] > sMax) { sMax = tSize[to]; large = to; }
		}
		decomposition(graph, nodeCost, tSize, large, std::forward<int>(nodeFrom));
		for (auto itr = range.first; itr != range.second; ++itr) {
			auto to = itr->second;
			if (to == large) { continue; }
			decomposition(graph, nodeCost, tSize, to, std::forward<int>(nodeFrom));
		}
	}

	auto construct(int size, const unordered_multimap<int, int>& graph, const std::vector<int>& nodeCost) {
		m_nodeList.reserve(size);
		m_nodeCostList.reserve(size);
		m_nodeRange.reserve(size);
		decomposition(graph, nodeCost, getTreeSize(size, graph, m_root), m_root, -1);
	}

public:
	HLDecomposition(int size, const unordered_multimap<ll, ll>& graph, const std::vector<int>& nodeCost) :
		m_graph(graph), m_graphRev(reverse(m_graph)),
		m_root(getRoot(size, graph)), m_nodeListPos(size) {
		construct(size, graph, nodeCost);
	}
	HLDecomposition(int size, const unordered_multimap<int, int>& graph) :
		m_graph(graph), m_graphRev(reverse(m_graph)),
		m_root(getRoot(size, graph)), m_nodeListPos(size) {
		construct(size, graph, std::vector<int>(size));
	}

	void debugOutput() const {
		dump(m_nodeList, m_nodeCostList, m_nodeRange);
	}

	/**
	 * Å¬‹¤’Ê‘cæCLCA(Lowest Common Ancestor)‚ð“¾‚é
	 */
	auto LCA(int a, int b) {
		while (a != b) {
			auto posa = m_nodeListPos[a];
			auto posb = m_nodeListPos[b];
			if (posa > posb) { std::swap(posa, posb); a = m_nodeList[posa]; }
			if (m_nodeRange[posb].first <= posa && posa <= m_nodeRange[posb].second) {
				b = a; break;
			}
			b = m_graphRev[m_nodeList[m_nodeRange[posb].first]];
		}
		return a;
	}
};
