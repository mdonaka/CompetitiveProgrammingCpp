
template<class Val = bool, Val ignore = false>
class TrieTree {
	const Val val;
	std::vector<std::unique_ptr<TrieTree>> next;

	auto emplace(const std::vector<int>& vec, Val val, int it) {
		if (it == vec.size()) { return; }
		if (!next[vec[it]]) {
			auto in = (it == vec.size() - 1) ? val : ignore;
			next[vec[it]] = std::make_unique<TrieTree>(in);
		}
		next[vec[it]]->emplace(vec, val, it + 1);
	}

	auto find(const std::vector<int>& vec, int it)const {
		if (it == vec.size()) { return val; }
		if (!next[vec[it]]) { return ignore; }
		return next[vec[it]]->find(vec, it + 1);
	}

public:
	TrieTree() : TrieTree(0) {}
	TrieTree(Val val) :val(val), next(std::vector<std::unique_ptr<TrieTree>>(26)) {}

	auto emplace(const std::vector<int>& vec, Val val) { return emplace(vec, val, 0); }

	auto find(const std::vector<int>& vec) { return find(vec, 0); }

};
