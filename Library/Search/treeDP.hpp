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

// #include "BFSonGraph.hpp"
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

/*
 * �����؂̏����}�[�W����Monoid
 * �}�[�W���ꂽ����e�ɗ���lambda
 */
template<class Monoid, class Lambda>
auto reRootingDP(long long n,
	const std::unordered_multimap<long long, long long>& graph,
	const Lambda& transition) {

	constexpr int root = 0;

	// <���镔���؏����}�[�W����>
	std::vector<std::deque<std::pair<int, Monoid>>> v(n);
	auto merge = [&](const std::deque<std::pair<int, Monoid>>& dq) {
		Monoid val{};
		for (const auto& [_, ad] : dq) {
			val = val.binaryOperation(ad);
		}
		return val;
	};

	// root�����Ƃ����������߂�
	treeDP(n, graph, root, [&](int f, int t) {
		v[t].emplace_back(f, transition(merge(v[f])));
	});

	// <node:t�ŕ������������؂�f�ȊO�}�[�W���������܂Ƃ߂ċ��߂�>
	std::vector<std::unordered_map<int, Monoid>> mp(n);
	auto calc_mp = [&](int t) {
		Monoid val_ord{};
		for (const auto& [i, ad] : v[t]) {
			mp[t].emplace(i, val_ord);
			val_ord = val_ord.binaryOperation(ad);
		}
		Monoid val_rord{};
		for (auto rit = v[t].rbegin(); rit != v[t].rend(); ++rit) {
			auto [i, ad] = *rit;
			mp[t][i] = transition(mp[t][i].binaryOperation(val_rord));
			val_rord = val_rord.binaryOperation(ad);
		}
	};

	// root����bfs���Ċenode�����Ƃ����������߂�
	calc_mp(root);
	graphBFS(n, graph, root, [&](int f, int t) {
		v[t].emplace_back(f, mp[f][t]);
		calc_mp(t);
	});

	// �S�Ă̕����؏����}�[�W���ĕԂ�
	std::vector<Monoid> ret;
	ret.reserve(n);
	for (const auto& dq : v) {
		ret.emplace_back(transition(merge(dq)));
	}
	return ret;
}

template<
	class S,   // �v�f�̌^
	// ��C++17�ł͂قƂ�ǂ̌^���O���[�o���錾���������l���Q�Ƃœn���K�v����
	S& element, // ��
	class T // 2�����Z�q�D
>
struct Monoid {
	S m_val;
	Monoid() :m_val(element) {}
	Monoid(S val) :m_val(val) {}
	Monoid binaryOperation(const Monoid& m2)const { return T()(m_val, m2.m_val); }
};