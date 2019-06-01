/**
 *  ダイクストラにより任意のnodeから全nodeへの最初コストを得る
 *  O((E+V)logV)
 */
VL dijkstra(const unordered_multimap<ll, PAIR> graph, ll n, ll begin) {
	VL cost(n, 1e15);
	cost[begin] = 0;
	priority_queue<PAIR, vector<PAIR>, std::greater<PAIR>> q;
	q.emplace(0, begin);
	while (!q.empty()) {
		ll from = q.top().second;
		ll nowCost = q.top().first;
		q.pop();
		if (cost[from] < nowCost) { continue; }
		auto range = graph.equal_range(from);
		REPI2(itr, range.first, range.second) {
			ll to = itr->second.first;
			ll c = itr->second.second;
			if (nowCost + c < cost[to]) {
				cost[to] = nowCost + c;
				q.emplace(cost[to], to);
			}
		}
	}
	return cost;
}