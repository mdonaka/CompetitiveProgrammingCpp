/**
 * d‚İ‚È‚µƒOƒ‰ƒt‚ÌBFS
 */
V<bool> isUsed(n, false); isUsed[0] = true;
queue<PAIR> q;	q.emplace(0, 0);
while (!q.empty()) {
	auto from = q.front().first;
	auto cost = q.front().second;
	q.pop();

	auto range = graph.equal_range(from);
	REPI2(itr, range.first, range.second) {
		auto to = itr->second;
		if (!isUsed[to]) {
			q.emplace(to);
			isUsed[to] = true;
		}
	}
}