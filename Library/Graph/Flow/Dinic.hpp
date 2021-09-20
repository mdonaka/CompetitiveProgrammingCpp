#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

class Dinic {

	struct HashPair {
		template<class T1, class T2>
		size_t operator()(const std::pair<T1, T2>& p) const {
			auto hash1 = std::hash<T1>{}(p.first);
			auto hash2 = std::hash<T2>{}(p.second);
			size_t seed = 0;
			seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};


	using Graph_f = std::unordered_multimap<int, std::pair<int, int>>;
	using Graph = std::unordered_map<std::pair<int, int>, int, HashPair>;

	const int m_n;
	const Graph m_graph;
	const std::vector<std::unordered_set<int>> m_to_list;

	static auto construct_to_list(int n, const Graph_f& graph_f) {
		std::vector<std::unordered_set<int>> to_list(n);
		for (const auto& [f, tc] : graph_f) {
			auto [t, c] = tc;
			to_list[f].emplace(t);
			to_list[t].emplace(f);
		}
		return to_list;
	}
	static auto construct_graph(const Graph_f& graph_f) {
		Graph graph;
		for (const auto& [f, tc] : graph_f) {
			auto [t, c] = tc;
			graph[std::pair<int, int>{f, t}] += c;
		}
		return graph;
	}

	auto get_depth(int s, const Graph& graph) const {
		std::vector<int> depth(m_n, -1);
		std::queue<int> q;
		q.emplace(s);
		depth[s] = 0;
		while (!q.empty()) {
			int from = q.front();
			q.pop();
			for (const auto& to : m_to_list[from]) {
				if (graph.find({ from, to }) == graph.end()) { continue; }
				if (depth[to] > -1) { continue; }
				depth[to] = depth[from] + 1;
				q.emplace(to);
			}
		}
		return depth;
	}

	auto update_residual(int s, Graph& residual, const std::list<int>& route)const {
		int mn = 1e9;
		int from = s;
		for (const auto& to : route)if (from != to) {
			mn = std::min(mn, residual[{from, to}]);
			from = to;
		}

		from = s;
		for (const auto& to : route)if (from != to) {
			auto& ft = residual[{from, to}];
			int use = ft - mn;
			ft -= mn;
			if (ft == 0) { residual.erase({ from,to }); }
			residual[{to, from}] += mn;
			from = to;
		}
	}

	auto get_route(int s, int t, const Graph& graph) const {

	}
public:
	Dinic(int n, const Graph_f& graph) :
		m_n(n),
		m_graph(construct_graph(graph)),
		m_to_list(construct_to_list(n, graph)) {
	}

	auto max_flow(int s, int t)const {
		auto residual = m_graph;
		while (true) {
			// BFS
			auto depth = get_depth(s, residual);

			// DFS
			bool run = false;
			std::vector<int> visited(m_n);
			auto f = [&](auto&& f, int now, std::list<int>& route)->void {
				route.emplace_back(now);

				// t‚É“ž’B‚µ‚Ä‚¢‚ê‚Î—¬‚·
				if (now == t) { update_residual(s, residual, route); run = true; }

				for (const auto& to : m_to_list[now]) {
					if (residual.find({ now, to }) == residual.end()) { continue; }
					if (depth[to] <= depth[now]) { continue; }
					if (visited[to]) { continue; }
					visited[to] = true;;
					f(f, to, route);
				}
				route.pop_back();
			};
			std::list<int> route;
			visited[s] = true;
			f(f, s, route);
			if (!run) { break; }
		}

		int val = 0;
		for (const auto& to : m_to_list[s]) {
			if (m_graph.find({ s,to }) == m_graph.end()) { continue; }
			val += m_graph.at({ s, to }) - residual[{s, to}];
		}
		return val;
	}
};