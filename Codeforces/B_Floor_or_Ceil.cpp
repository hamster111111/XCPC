#pragma GCC optimize(3, "Ofast", "inline")
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

void solve() {
    int x;
    cin >> x >> n >> m;

    if (n > 30) {cout << 0 << ' ' << 0 << '\n'; return;}
    if (m > 30) m = 30;

    auto find_min = [](int x, int n, int m) -> int {
        int ans = x;
        rep(i, 1, n + m) {
            if (i <= m) ans = (ans + 1) >> 1;
            else ans >>= 1;
        }
        return ans;
    };

    auto find_max = [](int x, int n, int m) -> int {
        int ans = x;
        rep(i, 1, n + m) {
            if (i <= n) ans = ans >> 1;
            else ans = (ans + 1) >> 1;
        }
        return ans;
    };
    cout << find_min(x, n, m) << ' ' << find_max(x, n, m) << '\n';
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