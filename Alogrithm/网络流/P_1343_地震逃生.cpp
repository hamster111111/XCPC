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
const int N = 3e2 + 10;
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
int x;
int g[N][N];
int flow[N];
int pre[N];

void solve() {
    cin >> n >> m >> x;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] += w;
    }
    auto bfs = [&]() -> int {
        mem(pre, -1);
        flow[1] = INF;
        pre[1] = 0;
        std::queue<int> q;
        q.push(1);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t == n) {
                break;
            }
            rep(i, 1, n) {
                if (i != 1 && g[t][i] > 0 && pre[i] == -1) {
                    q.push(i);
                    pre[i] = t;
                    flow[i] = std::min(flow[t], g[t][i]);
                }
            }
        }
        if (pre[n] == -1) return -1;
        return flow[n];
    };
    int tot = 0;
    auto maxflow = [&]() -> void {
        while (1) {
            int f = bfs();
            // dbg(f);
            if (f == -1) break;
            tot += f;
            int cur = n;
            while (pre[cur]) {
                int fa = pre[cur];
                g[fa][cur] -= f;
                g[cur][fa] += f;
                cur = fa;
            }
        }
    };
    maxflow();
    if (tot) 
        cout << tot << ' ' << (x + tot - 1) / tot << "\n";
    else cout << "Orz Ni Jinan Saint Cow!\n"; 
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