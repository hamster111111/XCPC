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
const int N = 3e6 + 10;
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
int head[N];
Node edge[N];
int deep[N];
int now[N];
int tot;

void solve() {
    cin >> n;
    auto add = [&](int u, int v, int w) -> void {
        edge[tot] = {v, w, head[u]}, head[u] = tot++;
    };
    int ans = 0;
    mem(head, -1);
    int s = 0, t = n + 1;
    rep(i, 1, n) {
        int e; cin >> e;
        ans += e;
        add(s, i, e);
        add(i, s, 0);
    }
    rep(i, 1, n) {
        int e; cin >> e;
        ans += e;
        add(i, t, e);
        add(t, i, 0);
    }
    cin >> m;
    int cnt = n + 2;
    rep(i, 1, m) {
        int k; cin >> k;
        int c1, c2;
        cin >> c1 >> c2;
        ans += c1 + c2;
        add(s, cnt, c1);
        add(cnt, s, 0);
        add(cnt + 1, t, c2);
        add(t, cnt + 1, 0);
        rep(j, 1, k) {
            int p; cin >> p;
            add(cnt, p, INF);
            add(p, cnt, 0);
            add(p, cnt + 1, INF);
            add(cnt + 1, p, 0);
        }
        cnt += 2;
    }
    auto bfs = [&]() -> int {
        rep(i, 0, cnt) {
            deep[i] = INF;
        }
        now[s] = head[s];
        deep[s] = 0;
        std::queue<int> q;
        q.push(s);
        while (!q.empty()) {
            auto ts = q.front();
            q.pop();
            for(int i = head[ts]; ~i; i = edge[i].next) {
                auto [v, w, ne] = edge[i];
                if (w && deep[v] == INF) {
                    q.push(v);
                    deep[v] = deep[ts] + 1;
                    now[v] = head[v];
                    if (v == t) return 1;
                }
            }
        }
        return 0;
    };
    auto dfs = [&](auto& self, int u, int sum) -> int {
        if (u == t) return sum;
        int flow = 0;
        for(int i = now[u]; ~i; i = edge[i].next) {
            auto [v, w, ne] = edge[i];
            now[u] = i;
            if (w && deep[v] == deep[u] + 1) {
                int f = self(self, v, std::min(sum, w));
                flow += f;
                sum -= f;
                edge[i].w -= f;
                edge[i ^ 1].w += f;
                if (sum == 0) break;
            }
        }
        return flow;
    };
    while(bfs()) ans -= dfs(dfs, s, INF);
    // ans = bfs();
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