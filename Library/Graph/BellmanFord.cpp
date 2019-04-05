/**
 *  ベルマンフォード法により任意のnodeから全nodeへの最初コストを得る
 *  O(ElogV)
 */
VL BellmanFord(const unordered_multimap<ll, PAIR> graph, ll n, ll begin) {
	VL cost(n, 1e15);
	cost[begin] = 0;

	REP(_, graph.size()) REP(from, n) {
		auto range = graph.equal_range(from);
		REPI2(itr, range.first, range.second) {
			ll to = itr->second.first;
			ll c = itr->second.second;
			cost[to] = std::min(cost[to], cost[from] + c);
		}
	}
	VL cost_ = cost;
	REP(_, n)REP(from, n) {
		auto range = graph.equal_range(from);
		REPI2(itr, range.first, range.second) {
			ll to = itr->second.first;
			ll c = itr->second.second;
			if (cost[from] + c < cost[to]) {
				cost[to] = cost[from] + c;
				cost_[to] = 1e15;
			}
		}
	}
	return cost_;
}
