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
struct Node {
    std::string op;
    int n;
};

void solve() {
    cin >> n;
    std::vector a(n + 1, std::vector<Node>(2));
    rep(i, 1, n) {
        rep(j, 0, 1) {
            std::string op;
            int p;
            cin >> op >> p;
            a[i][j] = {op, p};
        }
    }
    a[0][0].op = "+";
    a[0][1].op = "+";
    a[0][0].n = 1;
    a[0][1].n = 1;
    std::vector dp(n + 2, std::vector<int>(2));
    dp[n + 1][0] = dp[n + 1][1] = 1;
    per(i, n, 0) {
        rep(j, 0, 1) {
            dp[i][j] = dp[i + 1][j];
            if (a[i][j].op == "x") {
                dp[i][j] += (a[i][j].n - 1) * std::max(dp[i + 1][j], dp[i + 1][!j]);
            }
        }
    }
    int ans = dp[0][0] + dp[0][1];
    rep(i, 1, n) {
        rep(j, 0, 1) {
            if (a[i][j].op == "+") {
                ans += std::max(dp[i + 1][j], dp[i + 1][!j]) * a[i][j].n;
            }
        }
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