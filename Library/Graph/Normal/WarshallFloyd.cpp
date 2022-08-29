/**
 *  ワーシャルフロイドにより全nodeから全nodeへの最小コストを得る
 *  O(V^3)
 */
vector<vector<ll>> warshallFloyd(const unordered_multimap<ll, PAIR>& graph, ll n) {
	vector<vector<ll>> cost(n, vector<ll>(n, (1LL << 62) - 1));
	for (const auto& p : graph) {
		ll from = p.first;
		ll to = p.second.first;
		ll c = p.second.second;
		cost[from][to] = c;
	}
	REP(k, n)REP(f, n)REP(t, n) {
		cost[f][t] = std::min(cost[f][t], cost[f][k] + cost[k][t]);
	}
	return cost;
}