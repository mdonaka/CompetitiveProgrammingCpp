#define PROBLEM "https://yukicoder.me/problems/no/263"

#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>

auto nullLambda = [](int, const std::list<int>&) {};
class PalindromicTree {
    //static constexpr auto nullLambda = [](int, const std::list<int>&) {};// c++17

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
            auto p = this->weak_from_this();
            while(true) {
                auto size = p.lock()->m_size;
                // root�ɂ��ǂ蒅����
                if(size == -1) { return p; }
                // ���ݒn"A"�ɂ�����"xAx"�ƂȂ�
                if(itr - size - 1 >= 0 && s[itr] == s[itr - size - 1]) {
                    return p;
                }
                p = p.lock()->m_suffixLink;
            }
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
            m_suffixLink(suffixLink) {
        }
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
        auto outputTree(const std::string& s) ->void const {
            if(m_size <= 0) { std::cerr << "root"; } else {
                // �i
                for(int i = 0; (i < (m_size + 1) / 2); ++i) { std::cerr << " |"; }
                std::cerr << "- " << s.substr(*m_itrs.begin() - m_size + 1, m_size);
                // �Eitr
                std::cerr << " [ "; for(const auto& itr : m_itrs) { std::cerr << itr << " "; }std::cerr << "] ";
                // suffix link
                //auto p = m_suffixLink.lock();
                //std::cerr << "{" << s.substr(*p->m_itrs.begin() - p->m_size + 1, p->m_size) << "} ";
            } std::cerr << "\n";
            for(const auto& edge : m_edges) {
                if(m_size == -1 && edge.first == ' ') { continue; }
                edge.second->outputTree(s);
            }
        }

        // root������
        auto isOddRoot(const std::weak_ptr<Node>& evenRoot) {
            m_suffixLink = weak_from_this();
            m_edges.emplace(' ', evenRoot);
        }

        // �����_���̎��s
        template<class Lambda>
        auto runLambda(const Lambda& lambda) {
            if(m_size > 0) { lambda(m_size, m_itrs); }
        }

        /*
         * lambda: (int size, list<int> rItr) -> void
         */
        template<class Lambda, class SuffixLinkLambda = decltype(nullLambda)>
        auto dfs_edges(const Lambda& lambda, const SuffixLinkLambda& slLambda = nullLambda)->void {
            std::stack<std::shared_ptr<Node>> stk;
            stk.emplace(this->weak_from_this().lock());
            while(!stk.empty()) {
                auto p = stk.top();
                stk.pop();
                p->runLambda(lambda);
                p->m_suffixLink.lock()->runLambda(slLambda);
                for(const auto& [_, next_p] : p->m_edges) {
                    // std::cerr << p->m_size << " -> " << next_p->m_size << std::endl;
                    stk.emplace(next_p);
                }
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
        for(int r = 0; r < s.size(); ++r) {
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

    /*
     * ���Ȃ苭���Ȏ���
     * lambda: (int from, int to) -> void
     */
    template<class Lambda>
    auto dp_suffixLink(const Lambda& lambda) {
        // �X�̐����C�T�������̌���
        int from;
        std::unordered_map<int, int> graph;
        std::vector<int> orderCount(m_s.size());
        m_rootOdd->dfs_edges([&](int size, const std::list<int>& rItrs) {
            from = rItrs.front();
        }, [&](int size, const std::list<int>& rItrs) {
            int to = rItrs.front();
            graph.emplace(from, to);
            ++orderCount[to];
        });
        // �T�������ɏ]���ď���
        std::queue<int> q;
        for(int i = 0; i < m_s.size(); ++i)if(orderCount[i] == 0) { q.emplace(i); }
        while(!q.empty()) {
            int from = q.front();
            q.pop();
            auto range = graph.equal_range(from);
            for(auto itr = range.first; itr != range.second; ++itr) {
                int to = itr->second;
                --orderCount[to];
                lambda(from, to);
                if(orderCount[to] == 0) { q.emplace(to); }
            }
        }
    }

    // debug�p
    auto outputTree() {
        std::cerr << m_s << std::endl;
        std::cerr << "-- even --\n";
        m_rootEven->outputTree(m_s);
        std::cerr << "-- odd --\n";
        m_rootOdd->outputTree(m_s);
    }
};
using ll = long long;
using std::cout;
using std::cin;
constexpr char endl = '\n';
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

signed main() {
    std::string a, b;
    cin >> a >> b;
    std::string s = a + "$%" + b;

    auto tree = PalindromicTree(s);

    ll an = a.size();
    std::vector<std::pair<ll, ll>> dp(s.size());
    tree.dfs_edges([&](int size, const std::list<int>& ritr) {
        ll l = 0, r = 0;
        for(const auto& x : ritr) if(x != an && x != an + 1) {
            ++((x < an) ? l : r);
        }
        dp[ritr.front()] = {l,r};
    });

    tree.dp_suffixLink([&](int from, int to) {
        dp[to].first += dp[from].first;
        dp[to].second += dp[from].second;
    });

    ll ans = 0;
    for(const auto& p : dp) { ans += (p.first * p.second); }
    cout << ans << endl;
}