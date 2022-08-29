/*
 * Prim法による最小全域木構成
 * O(E+VlogV)？
 */
std::unordered_multimap<ll, PAIR> Prim(ll n, const unordered_multimap<ll, PAIR>& graph) {

	std::unordered_multimap<ll, PAIR> minSpanningTree;
	std::vector<bool> isUse(n);
	using Type = pair<ll, PAIR>;
	priority_queue<Type, std::vector<Type>, std::greater<Type>> q;

	auto add = [&](ll from) {
		auto range = graph.equal_range(from);
		REPI2(itr, range.first, range.second) {
			ll to = itr->second.first;
			ll cost = itr->second.second;

			if (isUse[to]) { continue; }
			q.emplace(cost, PAIR(from, to));
		}
	};

	isUse[0] = true;
	add(0);

	while (!q.empty()) {
		ll from = q.top().second.second;
		ll f_from = q.top().second.first;
		ll f_cost = q.top().first;
		q.pop();
		if (isUse[from]) { continue; }
		isUse[from] = true;
		minSpanningTree.emplace(f_from, PAIR(from, f_cost));
		add(from);
	}
	return minSpanningTree;
}