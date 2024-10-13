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
struct DSU {
    vector<int> f;
    int n;
    DSU(int v) {
        n = v;
        f.resize(n + 1);
        rep(i, 1, n) f[i] = i;
    }
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        int p = find(x), q = find(y);
        f[p] = q;
    }
    bool same(int x, int y) {
        int p = find(x), q = find(y);
        return p == q;
    }
    int get() {
        int ans = 0;
        rep(i, 1, n) if (find(i) == i) ans++;
        return ans;
    }
};

void solve() {
    cin >> n >> m;
    DSU dsu(n);
    vector<array<int, 11>> ne(n + 1);
    rep(i, 1, m) {
        int a, d, k;
        cin >> a >> d >> k;
        ne[a][d] = std::max(ne[a][d], k);
    }
    rep(i, 1, n) {
        rep(j, 1, 10) {
            if (ne[i][j]) {
                ne[i + j][j] = std::max(ne[i][j] - 1, ne[i + j][j]);
                int x = i, y = i + j;
                if (!dsu.same(x, y)) {
                    dsu.merge(x, y);
                }
            }
        }
    }
    cout << dsu.get() << '\n';
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