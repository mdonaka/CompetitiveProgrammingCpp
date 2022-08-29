/**
 * Z algorithmによりZ Arrayを構築する
 * O(N)
 * S[0..]とS[i..]の共通接頭辞数
 * ex) aaabaaaab -> [9, 2, 1, 0, 3, 4, 2, 1, 0]
 */
class ZAlgorithm {
	const std::vector<int> m_zArray;

	static auto constrcutZArray(const std::string& str) {
		auto sz = str.size();
		auto zArray = std::vector<int>(sz);
		zArray[0] = sz;

		int i = 1, j = 0;
		while (i < sz) {
			while (i + j < sz && str[j] == str[i + j]) ++j;
			zArray[i] = j;
			if (j == 0) { ++i; continue; }
			int k = 1;
			while (i + k < sz && k + zArray[k] < j) {
				zArray[i + k] = zArray[k];
				++k;
			}
			i += k; j -= k;
		}
		return zArray;
	}
public:
	ZAlgorithm(const std::string& str) :m_zArray(constrcutZArray(str)) {}

	auto getZArray() const {
		return m_zArray;
	}

	/* output fot debug */
	void debugOutput() const {
		dump(m_zArray);
	}

};