/**
 * クラスカル法による最小全域木構成
 * O(ElogE)？
 * Unionfind木が必要
 */
std::unordered_multimap<ll, PAIR> Kruskal(ll n, const unordered_multimap<ll, PAIR>& graph) {

	std::unordered_multimap<ll, PAIR> minSpanningTree;
	auto tree = UnionFind(n);
	using Type = pair<ll, PAIR>;
	priority_queue<Type, std::vector<Type>, std::greater<Type>> q;
	REPC(p, graph) {
		q.emplace(p.second.second, PAIR(p.first, p.second.first));
	}

	while (!q.empty()) {
		auto& val = q.top();
		ll from = val.second.first;
		ll to = val.second.second;
		ll cost = val.first;
		q.pop();
		if (tree.isSame(from, to)) { continue; }
		tree.unite(from, to);
		minSpanningTree.emplace(from, PAIR(to, cost));
	}

	return minSpanningTree;
}
