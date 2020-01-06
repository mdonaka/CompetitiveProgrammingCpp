#include <memory>
#include <string>
#include <iostream>
#include <list>
#include "./../../debug.hpp"
#include <unordered_map>
using std::cout;
using std::cin;

class PalindromicTree {
	class Node :public std::enable_shared_from_this<Node> {
		// 最大の回文接尾辞
		std::weak_ptr<Node> m_suffixLink;
		// 次サイズの回文(囲む文字, 次のNode)
		std::unordered_map<char, std::shared_ptr<Node>> m_edges;

		// 回文の右端itr
		std::list<int> m_itrs;
		// 回文サイズ
		const int m_size;

		// xAxとなるAを探す(x=str[itr])
		auto find(int itr, const std::string& s, bool flg = false) {
			// rootにたどり着いた
			if (m_size == -1) { return weak_from_this(); }
			// 現在地"A"において"xAx"となる
			if (itr - m_size - 1 >= 0 && s[itr] == s[itr - m_size - 1]) {
				return weak_from_this();
			}
			// 見つからない
			return m_suffixLink.lock()->find(itr, s, flg);
		}

		// 新しい回文Nodeを作成する
		auto create(int itr, const std::string& s) {
			// suffixLinkの探索
			auto suffixLinkFrom = m_suffixLink.lock()/*->m_suffixLink.lock()*/->find(itr, s, true).lock();
			// 新Nodeの作成
			auto newNode = std::make_shared<Node>(
				m_size + 2, (suffixLinkFrom->m_edges.find(s[itr]) == suffixLinkFrom->m_edges.end()) ?
				suffixLinkFrom->m_edges.find(' ')->second :
				suffixLinkFrom->m_edges.find(s[itr])->second);
			m_edges.emplace(s[itr], newNode);
			return std::weak_ptr<Node>(newNode);
		}

	public:
		// constructor
		Node(int size, const std::weak_ptr<Node>& suffixLink) :
			m_itrs(),
			m_size(size),
			m_suffixLink(suffixLink) {}
		Node() :Node(-1, weak_from_this()) {}


		// 次サイズの回文を追加
		auto add(int itr, const std::string& s) {
			auto addRoot = find(itr, s).lock();
			auto nextNode = (addRoot->m_edges.find(s[itr]) == addRoot->m_edges.end()) ?
				addRoot->create(itr, s) :
				std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);
			nextNode.lock()->m_itrs.emplace_back(itr);
			return nextNode;
		}

		// debug用
		auto outputTree(const std::string& s) ->void {
			if (m_size <= 0) { cout << "root"; } else {
				// 段
				for (int i = 0; (i < (m_size + 1) / 2); ++i) { cout << " |"; }
				cout << "- " << s.substr(*m_itrs.begin() - m_size + 1, m_size);
				// 右itr
				cout << " [ "; for (const auto& itr : m_itrs) { cout << itr << " "; }cout << "] ";
				// suffix link
				//auto p = m_suffixLink.lock();
				//cout << "{" << s.substr(*p->m_itrs.begin() - p->m_size + 1, p->m_size) << "} ";
			} cout << "\n";
			for (const auto& edge : m_edges) {
				if (m_size == -1 && edge.first == ' ') { continue; }
				edge.second->outputTree(s);
			}
		}

		// rootを決定
		auto isOddRoot(const std::weak_ptr<Node>& evenRoot) {
			m_suffixLink = weak_from_this();
			m_edges.emplace(' ', evenRoot);
		}
	};

	// 対象となる文字列
	const std::string m_s;

	// 偶数長，奇数長のPalindromicTreeの根(0, -1)
	std::shared_ptr<Node> m_rootOdd;
	std::shared_ptr<Node> m_rootEven;
public:
	// constructor
	PalindromicTree(const std::string& s) :
		m_s(s),
		m_rootOdd(std::make_shared<Node>()),
		m_rootEven(std::move(std::make_shared<Node>(0, m_rootOdd))) {
		m_rootOdd->isOddRoot(m_rootEven);
		auto root = m_rootOdd;
		for (int r = 0; r < s.size(); ++r) {
			root = root->add(r, s).lock();
		}
	}

	// debug用
	auto outputTree() {
		dump(m_s);
		cout << "-- even --\n";
		m_rootEven->outputTree(m_s);
		cout << "-- odd --\n";
		m_rootOdd->outputTree(m_s);
	}
};