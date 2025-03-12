#include<bits/stdc++.h>
#define int long long
#define fr first 
#define sc second 
#define dbg(a) std::cerr << #a << ':' << a << '\n'
#define rep(i, a, b) for(int i = (a);i <= (b); ++i)
#define per(i, a, b) for(int i = (a);i >= (b); --i)
#define pb push_back
#define eb emplace_back
#define mem(a, b) memset(a, b, sizeof a)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & -x)
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
const int mod = 998244353;
//const int mod = 1e9 + 7;
using std::cin;
using std::cout;

int n;
int m;
int d;

void solve() {
    cin >> n >> m >> d;
    std::vector<int> p(n + 1);
    std::vector<int> a(m + 1);
    std::vector<int> pos(n + 1);
    rep(i, 1, n) {
        cin >> p[i], pos[p[i]] = i;
    }
    rep(i, 1, m) {
        cin >> a[i];
    }
    rep(i, 1, m - 1) {
        if (pos[a[i + 1]] < pos[a[i]] || pos[a[i]] + d < pos[a[i + 1]]) {
            cout << 0 << '\n';
            return;
        }
    }
    int ans = INF;
    rep(i, 1, m - 1) {
        int far = d + 1 - pos[a[i + 1]] + pos[a[i]];
        int close = pos[a[i + 1]] - pos[a[i]];
        if (d + 1 >= n) far = INF;
        ans = std::min({ans, far, close});
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