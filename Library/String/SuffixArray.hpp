#include <string>
#include <vector>
#include <iostream>
/**
 * SuffixArrayを構築する
 * O(N)? <- memory:n^2
 * 文字列の全てのsuffixをソートした配列が得られる
 * ex) abadc -> [abc, abadc, badc, c, dc]
 */
class SuffixArray {
public:
	enum class TYPE {
		L, S, LMS
	};

	std::vector<std::string> suffixArray;

	static std::vector<TYPE> classifying(const std::string& str) {
		auto sz = str.size();
		auto typeArray = std::vector<TYPE>(sz);
		typeArray[sz - 1] = TYPE::S;
		for (int i = sz - 2; i >= 0; --i) {
			if (str[i] == str[i + 1]) {
				continue;
			}
			typeArray[i] = (str[i] < str[i + 1]) ? TYPE::S : TYPE::L;
		}
		for (int i = 1; i < sz; ++i) {
			if (typeArray[i - 1] == TYPE::L && typeArray[i] == TYPE::S) {
				typeArray[i] = TYPE::LMS;
			}
		}
		return typeArray;
	}

	static std::vector<std::string> createSuffixArray(const std::string& str) {
		std::vector<std::string> v;
		return v;
	}

public:
	SuffixArray(const std::string& str) :suffixArray(createSuffixArray(str)) {}
};