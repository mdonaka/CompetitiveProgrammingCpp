#include <unordered_map>
#include <queue>

template<class Lambda>
auto treeDP(long long n, const std::unordered_multimap<long long, long long>& graph, long long root, const Lambda& lambda) {
	VL out(n, 0);
	{
		std::queue<ll> q; q.emplace(root);
		while (!q.empty()) {
			auto from = q.front();
			q.pop();

			auto range = graph.equal_range(from);
			REPI2(itr, range.first, range.second) {
				auto to = itr->second;
				if (out[to] == 0) {
					q.emplace(to);
					++out[from];
				}
			}
		}
	}

	{
		std::queue<ll> q;
		V<bool> isUsed(n);
		REP(i, n)if (out[i] == 0) { q.emplace(i); isUsed[i] = true; }
		while (!q.empty()) {
			auto from = q.front();
			q.pop();

			auto range = graph.equal_range(from);
			REPI2(itr, range.first, range.second) {
				auto to = itr->second;

				if (!isUsed[to]) {
					lambda(from, to);
				}

				--out[to];
				if (out[to] == 0) {
					q.emplace(to);
					isUsed[to] = true;
				}
			}
		}
	}
}