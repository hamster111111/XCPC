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
    rep(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y), edge[y].pb(x);
    }
    int r0 = 0, r1 = 0, r_ = 0;
    int h0 = 0, h1 = 0, h_ = 0;
    std::string s;
    cin >> s;
    s = " " + s;
    auto dfs = [&](auto& self, int p, int pre) -> void {
        if (p == 1 || edge[p].size() == 1) {
            if (s[p] == '0') h0++;
            if (s[p] == '1') h1++;
            if (s[p] == '?') h_++;
        }
        for(auto& i : edge[p]) {
            if (i == pre) continue;
            self(self, i, p);
        }
    };
    rep(i, 1, n) {
        if (s[i] == '0') r0++;
        if (s[i] == '1') r1++;
        if (s[i] == '?') r_++;
    }
    dfs(dfs, 1, 0);
    r_ -= h_;
    if (s[1] == '?') h_--;
    int ans = 0;
    if (s[1] == '?') {
        ans = std::max(h0, h1);
        if (h0 == h1 && (r_ % 2)) {
            h_++;
        }
        ans += h_ / 2;
    } else {
        if (s[1] == '1') ans = h0;
        if (s[1] == '0') ans = h1;
        ans += (h_ + 1) / 2;
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