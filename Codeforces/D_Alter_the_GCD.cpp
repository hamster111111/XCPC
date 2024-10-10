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
    vector<int> a(n + 10);
    vector<int> b(n + 10);
    vector<vector<int>> st_a(n + 10, vector<int>(21));
    vector<vector<int>> st_b(n + 10, vector<int>(21));
    rep(i, 1, n) cin >> a[i], st_a[i][0] = a[i];
    rep(i, 1, n) cin >> b[i], st_b[i][0] = b[i];
    rep(j, 1, 4) {
        rep(i, 1, n) {
            st_a[i][j] = std::__gcd(st_a[i][j - 1], st_a[std::min(n + 1, i + (1ll << (j - 1)))][j - 1]);
            st_b[i][j] = std::__gcd(st_b[i][j - 1], st_b[std::min(n + 1, i + (1ll << (j - 1)))][j - 1]);
        }
    }
    vector<bool> st(n + 1);
    int gcd = 0;
    rep(i, 1, n) {
        if (std::__gcd(gcd, a[i]) != gcd) st[i] = true, st[i - 1] = true, st[i + 1] = true;
        gcd = std::__gcd(gcd, a[i]);
    }
    gcd = 0;
    rep(i, 1, n) {
        if (std::__gcd(gcd, b[i]) != gcd) st[i] = true, st[i - 1] = true, st[i + 1] = true;
        gcd = std::__gcd(gcd, b[i]);
    }
    vector<int> v;
    rep(i, 1, n) {
        if (st[i]) v.pb(i);
    }
    auto ask1 = [&](int l, int r) -> int {
        int ans = 0;
        per(j, 20, 0) {
            if (l + (1ll << j) - 1 <= r) {
                ans = std::__gcd(ans, st_a[l][j]);
                l = l + (1ll << j);
            }
            if (l > r) break;
        }
        return ans;
    };
    auto ask2 = [&](int l, int r) -> int {
        int ans = 0;
        per(j, 20, 0) {
            if (l + (1ll << j) - 1 <= r) {
                ans = std::__gcd(ans, st_b[l][j]);
                l = l + (1ll << j);
            }
            if (l > r) break;
        }
        return ans;
    };
    int ans = 0, num = 0;
    rep(i, 0, v.size() - 1) {
        rep(j, i, v.size() - 1) {
            int c1 = ask1(1, v[i] - 1);
            int c2 = ask1(v[i], v[j]);
            int c3 = ask1(v[j] + 1, n);
            int d1 = ask2(1, v[i] - 1);
            int d2 = ask2(v[i], v[j]);
            int d3 = ask2(v[j] + 1, n);
            int gcd1 = std::__gcd(c1, d2);
            gcd1 = std::__gcd(gcd1, c3);
            int gcd2 = std::__gcd(d1, c2);
            gcd2 = std::__gcd(gcd2, d3);
            // if (v[i] == 1 && v[j] == 3) {
            //     print_(d3);
            // }
            if (gcd1 + gcd2 == ans) num ++;
            else if (gcd1 + gcd2 > ans) ans = gcd1 + gcd2, num = 1;
        }
    }
    cout << ans << ' ' << num << '\n';
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