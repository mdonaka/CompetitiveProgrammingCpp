#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

class FordFulkerson {

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

	auto get_route(int s, int t, const Graph& graph) const {
		std::unordered_set<int> visited;
		auto f = [&](auto&& f, int now, std::list<int>& route)->bool {
			route.emplace_back(now);
			for (const auto& to : m_to_list[now]) {
				if (graph.find({ now, to }) == graph.end()) { continue; }
				if (to == t) { route.emplace_back(t); return true; }
				if (visited.find(to) == visited.end()) {
					visited.emplace(to);
					if (f(f, to, route)) { return true; }
				}
			}
			route.pop_back();
			return false;
		};
		std::list<int> route;
		visited.emplace(s);
		auto ok = f(f, s, route);
		if (ok) { return route; } else { return std::list<int>{}; }
	}
public:
	FordFulkerson(int n, const Graph_f& graph) :
		m_graph(construct_graph(graph)),
		m_to_list(construct_to_list(n, graph)) {
	}

	auto max_flow(int s, int t)const {
		auto residual = m_graph;
		while (true) {
			auto route = get_route(s, t, residual);
			if (route.empty()) { break; }

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
		int val = 0;
		for (const auto& to : m_to_list[s]) {
			if (m_graph.find({ s,to }) == m_graph.end()) { continue; }
			val += m_graph.at({ s, to }) - residual[{s, to}];
		}
		return val;
	}
};