#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
#define int long long
#define fr first 
#define sc second 
#define DEBUG_
#ifdef DEBUG_
#define dbg(a) std::cerr << #a << ':' << a << '\n'
template<class T>
void print_(T &t) {
   std::cerr << t << '\n';
}
template<class T, class... Args>
void print_(T &t, Args&... args) {
   std::cerr << t << ' ';
   print_(args...);
}
#else
#define dbg(a)
template<class T>
void print_(T &t) {
}
template<class T, class... Args>
void print_(T &t, Args&... args) {
}
#endif
#define rep(i, a, b) for(int i = (a);i <= (b); ++i)
#define per(i, a, b) for(int i = (a);i >= (b); --i)
#define pb push_back
#define eb emplace_back
#define mem(a, b) memset(a, b, sizeof a)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & -x)
#define PY puts("YES")
#define Py puts("Yes")
#define PN puts("NO")
#define Pn puts("No")
#define all(x, l, r) x.begin() + l, x.begin() + r + 1
//using namespace std;
const int N = 1e6 + 10;
const int M = 320;
const int INF = 1e18 + 10;
const int mod = 998244353;
//const int mod = 1e9 + 7;
const int base1 = 131;
const int base2 = 13331;
using PII = std::pair<int, int>;
using ull = unsigned long long;
using ll = long long;
using std::array;
using std::cin;
using std::cout;
using std::vector;
template <class T>
using pq_g = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using pq_ = std::priority_queue<T>;

int n;
int m;

void solve() {
    cin >> n >> m;
    int tot = 0;
    struct Node {
        int to, next;
        std::string s;
    };
    vector<int> head(1010, -1);
    vector<Node> edge(1010);
    vector<bool> state(1010, true);
    auto add = [&](std::queue<std::string>& q, bool f) -> void {
        int p = 0;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            bool flag = false;
            for (int i = head[p]; ~i; i = edge[i].next) {
                std::string ss = edge[i].s;
                if (ss == s) {
                    flag = true;
                    p = edge[i].to;
                }
            }
            if (!flag) {
                edge[tot] = {tot + 1, head[p], s}, head[p] = tot++;
                p = tot; 
            }
            if (f == false) state[p] = false;
        }
    };
    int ans = 0;
    auto dfs = [&](auto& self, int p) -> void {
        // cout << p << '\n';
        if (p && state[p]) {
            ans++;
            return;
        }
        // if (state[p] == false) {
        //     cout << p << '\n';
        // }
        for(int i = head[p]; ~i; i = edge[i].next) {
            int to = edge[i].to;
            self(self, to);
        }
    };
    rep(i, 1, n) {
        std::string ss;
        cin >> ss;
        ss += "/";
        std::string s;
        std::queue<std::string> q;
        for(auto& j : ss) {
            if (j == '/') q.push(s), s.clear();
            else s += j;
        }
        add(q, true);
        // dfs(dfs, 0);
        // cout << '\n';
    }
    rep(i, 1, m) {
        std::string ss;
        cin >> ss;
        ss += "/";
        std::string s;
        std::queue<std::string> q;
        for(auto& j : ss) {
            if (j == '/') q.push(s), s.clear();
            else s += j;
        }
        add(q, false);
    }
    dfs(dfs, 0);
    cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--) {
        solve();
    }
}