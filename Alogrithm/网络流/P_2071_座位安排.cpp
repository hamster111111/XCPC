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
struct Node {
    int to, w, next;
};

void solve() {
    cin >> n;
    vector<Node> edge(n << 4);
    vector<int> h(n << 2, -1);
    int tot = 0;
    auto add = [&](int u, int v, int w) -> void {
        edge[tot] = {v, w, h[u]}, h[u] = tot++;
    };
    rep(i, 1, n << 1) {
        int u, v;
        cin >> u >> v;
        add(i, v + (n << 1), 1), add(v + (n << 1), i, 0);
        add(i, u + (n << 1), 1), add(u + (n << 1), i, 0);
        add(0, i, 1), add(i, 0, 0);
    }
    int s = 0, t = 3 * n + 1;
    rep(i, 1, n) {
        add(i + (n << 1), t, 2), add(t, i + (n << 1), 0);
    }
    vector<int> deep(n << 2);
    vector<int> now(n << 2);
    auto bfs = [&]() -> int {
        std::queue<int> q;
        q.push(s);
        for(auto& i : deep) i = INF;
        deep[s] = 0;
        now[s] = h[s];
        while (!q.empty()) {
            auto ts = q.front();
            q.pop();
            for(int i = h[ts]; ~i; i = edge[i].next) {
                auto [v, w, ne] = edge[i];
                if (w && deep[v] == INF) {
                    // dbg(ts);
                    // dbg(v);
                    // dbg(w);
                    deep[v] = deep[ts] + 1;
                    now[v] = h[v];
                    q.push(v);
                    if (v == t) return 1;
                }
            }
        }
        return 0;
    };
    int cnt = 0;
    auto dfs = [&](auto& self, int p, int sum) -> int {
        // cnt ++;
        // if (cnt > 100) return 0;
        // cout << p << '\n';
        if (p == t) return sum;
        int k = 0, flow = 0;
        for(int i = now[p]; (~i) && sum > 0; i = edge[i].next) {
            auto [v, w, ne] = edge[i];
            now[p] = i;
            if (w && deep[v] == deep[p] + 1) {
                k = self(self, v, std::min(sum, w));
                if (k == 0) deep[v] = INF;
                edge[i].w -= k;
                edge[i ^ 1].w += k;
                flow += k;
                sum -= k;
            }
        }
        return flow;
    };
    int ans = 0;
    while (bfs()) ans += dfs(dfs, s, INF);
    // if (bfs()) ans += dfs(dfs, s, INF);
    cout << ans << '\n'; 
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_--) {
        solve();
    }
}