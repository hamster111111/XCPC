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
    cin >> n;
    vector<vector<int>> edge(n + 1);
    vector<int> fa(n + 1);
    rep(i, 2, n) {
        int e;
        cin >> e;
        edge[e].pb(i), edge[i].pb(e);
        fa[i] = e;
    }
    fa[1] = 0;
    edge[1].pb(0);
    vector<int> deep(n + 1);
    vector<int> num(n + 1);
    vector<vector<int>> d(n + 1);
    int tot = 0;
    auto dfs = [&](auto& self, int pre, int p) -> void {
        deep[p] = 1;
        for(auto& i : edge[p]) {
            if (i == pre) continue;
            self(self, p, i);
            deep[p] = std::max(deep[p], deep[i] + 1);
        }
        d[deep[p]].pb(p);
        num[p] = (int)edge[p].size() - 1;
        if (num[p] == 0) tot++;
    };
    dfs(dfs, 0, 1);
    int ans = tot;
    rep(i, 1, n) {
        for(auto& j : d[i]) {
            num[fa[j]]--;
            if (num[j] == 0) tot--;
            if (num[fa[j]] == 0) tot++;
        }
        ans = std::min(ans, i + tot);
    }
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