#pragma once
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
		// �ő�̉񕶐ڔ���
		std::weak_ptr<Node> m_suffixLink;
		// ���T�C�Y�̉�(�͂ޕ���, ����Node)
		std::unordered_map<char, std::shared_ptr<Node>> m_edges;

		// �񕶂̉E�[itr
		std::list<int> m_itrs;
		// �񕶃T�C�Y
		const int m_size;

		// xAx�ƂȂ�A��T��(x=str[itr])
		auto find(int itr, const std::string& s, bool flg = false) {
			// root�ɂ��ǂ蒅����
			if (m_size == -1) { return weak_from_this(); }
			// ���ݒn"A"�ɂ�����"xAx"�ƂȂ�
			if (itr - m_size - 1 >= 0 && s[itr] == s[itr - m_size - 1]) {
				return weak_from_this();
			}
			// ������Ȃ�
			return m_suffixLink.lock()->find(itr, s, flg);
		}

		// �V������Node���쐬����
		auto create(int itr, const std::string& s) {
			// suffixLink�̒T��
			auto suffixLinkFrom = m_suffixLink.lock()/*->m_suffixLink.lock()*/->find(itr, s, true).lock();
			// �VNode�̍쐬
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
			m_size(size),
			m_suffixLink(suffixLink) {}
		Node() :m_size(-1) {}


		// ���T�C�Y�̉񕶂�ǉ�
		auto add(int itr, const std::string& s) {
			auto addRoot = find(itr, s).lock();
			auto nextNode = (addRoot->m_edges.find(s[itr]) == addRoot->m_edges.end()) ?
				addRoot->create(itr, s) :
				std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);
			nextNode.lock()->m_itrs.emplace_back(itr);
			return nextNode;
		}

		// debug�p
		auto outputTree(const std::string& s) ->void {
			if (m_size <= 0) { cout << "root"; } else {
				// �i
				for (int i = 0; (i < (m_size + 1) / 2); ++i) { cout << " |"; }
				cout << "- " << s.substr(*m_itrs.begin() - m_size + 1, m_size);
				// �Eitr
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

		// root������
		auto isOddRoot(const std::weak_ptr<Node>& evenRoot) {
			m_suffixLink = weak_from_this();
			m_edges.emplace(' ', evenRoot);
		}
		/*
		 * lambda: (int size, list<int> rItr) -> void
		 */
		template<class Lambda>
		auto dfs_edges(const Lambda& lambda)->void {
			if (m_size > 0) { lambda(m_size, m_itrs); }
			for (const auto& edge : m_edges) {
				edge.second->dfs_edges(lambda);
			}
		}
	};

	// �ΏۂƂȂ镶����
	const std::string m_s;

	// �������C�����PalindromicTree�̍�(0, -1)
	std::shared_ptr<Node> m_rootOdd;
	std::shared_ptr<Node> m_rootEven;
public:
	// constructor
	PalindromicTree(const std::string& s) :
		m_s(s),
		m_rootOdd(std::make_shared<Node>()),
		m_rootEven(std::make_shared<Node>(0, m_rootOdd)) {
		m_rootOdd->isOddRoot(m_rootEven);
		auto root = m_rootOdd;
		for (int r = 0; r < s.size(); ++r) {
			root = root->add(r, s).lock();
		}
	}

	/*
	 * lambda: (int size, list<int> rItr) -> void
	 */
	template<class Lambda>
	auto dfs_edges(const Lambda& lambda) {
		m_rootOdd->dfs_edges(lambda);
	}

	// debug�p
	auto outputTree() {
		dump(m_s);
		cout << "-- even --\n";
		m_rootEven->outputTree(m_s);
		cout << "-- odd --\n";
		m_rootOdd->outputTree(m_s);
	}
};