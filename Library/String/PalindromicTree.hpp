#pragma once
#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace mtd {
  auto nullLambda = [](int, const std::list<int>&) {};
  class PalindromicTree {
    // static constexpr auto nullLambda = [](int, const std::list<int>&) {};//
    // c++17

    class Node : public std::enable_shared_from_this<Node> {
      // 回文の右端itr
      std::list<int> m_itrs;
      // 回文サイズ
      const int m_size;

      // 最大の回文接尾辞
      std::weak_ptr<Node> m_suffixLink;
      // 次サイズの回文(囲む文字, 次のNode)
      std::unordered_map<char, std::shared_ptr<Node>> m_edges;

      // xAxとなるAを探す(x=str[itr])
      auto find(int itr, const std::string& s) {
        auto p = this->weak_from_this();
        while (true) {
          auto size = p.lock()->m_size;
          // rootにたどり着いた
          if (size == -1) { return p; }
          // 現在地"A"において"xAx"となる
          if (itr - size - 1 >= 0 && s[itr] == s[itr - size - 1]) { return p; }
          p = p.lock()->m_suffixLink;
        }
      }

      // 新しい回文Nodeを作成する
      auto create(int itr, const std::string& s) {
        // suffixLinkの探索
        auto suffixLinkFrom =
            m_suffixLink.lock() /*->m_suffixLink.lock()*/->find(itr, s).lock();
        // 新Nodeの作成
        auto newNode = std::make_shared<Node>(
            m_size + 2, (suffixLinkFrom->m_edges.find(s[itr]) ==
                         suffixLinkFrom->m_edges.end())
                            ? suffixLinkFrom->m_edges.find(' ')->second
                            : suffixLinkFrom->m_edges.find(s[itr])->second);
        m_edges.emplace(s[itr], newNode);
        return std::weak_ptr<Node>(newNode);
      }

    public:
      // constructor
      Node(int size, const std::weak_ptr<Node>& suffixLink)
          : m_size(size), m_suffixLink(suffixLink) {}
      Node() : m_size(-1) {}

      // 次サイズの回文を追加
      auto add(int itr, const std::string& s) {
        auto addRoot = find(itr, s).lock();
        auto nextNode =
            (addRoot->m_edges.find(s[itr]) == addRoot->m_edges.end())
                ? addRoot->create(itr, s)
                : std::weak_ptr<Node>(addRoot->m_edges.find(s[itr])->second);
        nextNode.lock()->m_itrs.emplace_back(itr);
        return nextNode;
      }

      // debug用
      auto outputTree(const std::string& s) const -> void {
        if (m_size <= 0) {
          std::cerr << "root";
        } else {
          // 段
          for (int i = 0; (i < (m_size + 1) / 2); ++i) { std::cerr << " |"; }
          std::cerr << "- " << s.substr(*m_itrs.begin() - m_size + 1, m_size);
          // 右itr
          std::cerr << " [ ";
          for (const auto& itr : m_itrs) { std::cerr << itr << " "; }
          std::cerr << "] ";
          // suffix link
          // auto p = m_suffixLink.lock();
          // std::cerr << "{" << s.substr(*p->m_itrs.begin() - p->m_size + 1,
          // p->m_size) << "} ";
        }
        std::cerr << "\n";
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

      // ラムダ式の実行
      template <class Lambda>
      auto runLambda(const Lambda& lambda) {
        if (m_size > 0) { lambda(m_size, m_itrs); }
      }

      /*
       * lambda: (int size, list<int> rItr) -> void
       */
      template <class Lambda, class SuffixLinkLambda = decltype(nullLambda)>
      auto dfs_edges(const Lambda& lambda,
                     const SuffixLinkLambda& slLambda = nullLambda) -> void {
        std::stack<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>>
            stk;
        stk.emplace(this->weak_from_this().lock());
        while (!stk.empty()) {
          auto p = stk.top();
          stk.pop();
          p->runLambda(lambda);
          p->m_suffixLink.lock()->runLambda(slLambda);
          for (const auto& [_, next_p] : p->m_edges) {
            // std::cerr << p->m_size << " -> " << next_p->m_size << std::endl;
            stk.emplace(next_p);
          }
        }
      }
    };

    // 対象となる文字列
    const std::string m_s;

    // 偶数長，奇数長のPalindromicTreeの根(0, -1)
    std::shared_ptr<Node> m_rootOdd;
    std::shared_ptr<Node> m_rootEven;

  public:
    // constructor
    PalindromicTree(const std::string& s)
        : m_s(s),
          m_rootOdd(std::make_shared<Node>()),
          m_rootEven(std::make_shared<Node>(0, m_rootOdd)) {
      m_rootOdd->isOddRoot(m_rootEven);
      auto root = m_rootOdd;
      for (int r = 0; r < static_cast<int>(s.size()); ++r) {
        root = root->add(r, s).lock();
      }
    }

    /*
     * lambda: (int size, list<int> rItr) -> void
     */
    template <class Lambda>
    auto dfs_edges(const Lambda& lambda) {
      m_rootOdd->dfs_edges(lambda);
    }

    /*
     * かなり強引な実装
     * lambda: (int from, int to) -> void
     */
    template <class Lambda>
    auto dp_suffixLink(const Lambda& lambda) {
      // 森の生成，探索順序の決定
      int from;
      std::unordered_map<int, int> graph;
      std::vector<int> orderCount(m_s.size());
      m_rootOdd->dfs_edges(
          [&](int, const std::list<int>& rItrs) { from = rItrs.front(); },
          [&](int, const std::list<int>& rItrs) {
            int to = rItrs.front();
            graph.emplace(from, to);
            ++orderCount[to];
          });
      // 探索順序に従って処理
      std::queue<int, std::list<int>> q;
      for (int i = 0; i < static_cast<int>(m_s.size()); ++i) {
        if (orderCount[i] == 0) { q.emplace(i); }
      }
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        auto range = graph.equal_range(f);
        for (auto itr = range.first; itr != range.second; ++itr) {
          int t = itr->second;
          --orderCount[t];
          lambda(f, t);
          if (orderCount[t] == 0) { q.emplace(t); }
        }
      }
    }

    // debug用
    auto outputTree() {
      std::cerr << m_s << std::endl;
      std::cerr << "-- even --\n";
      m_rootEven->outputTree(m_s);
      std::cerr << "-- odd --\n";
      m_rootOdd->outputTree(m_s);
    }
  };
}  // namespace mtd
