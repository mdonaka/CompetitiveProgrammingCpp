#include <unordered_map>
#include <queue>

template<class Lambda>
auto graphBFS(long long n, const std::unordered_multimap<long long, long long>& graph, long long root, const Lambda& lambda) {
	V<bool> isUsed(n, false); isUsed[root] = true;
	std::queue<long long> q; q.emplace(root);
	while (!q.empty()) {
		auto from = q.front();
		q.pop();

		auto range = graph.equal_range(from);
		REPI2(itr, range.first, range.second) {
			auto to = itr->second;
			if (!isUsed[to]) {
				q.emplace(to);
				isUsed[to] = true;
				lambda(from, to);
			}
		}
	}
}
