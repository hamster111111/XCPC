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
// const int mod = 998244353;
const int mod = 1e9 + 7;
using std::cin;
using std::cout;

int n;

void solve() {
    std::string s;
    cin >> n >> s;
    std::reverse(s.begin(),s.end());
    s = " " + s;
    std::vector<int> f(n + 1);
    rep(i, 1, n - 1) {
        if (s[i] == '1') {
            f[i] = (f[i - 1] + 500000004 * ((1 - f[i - 1] + mod) % mod) % mod) % mod;
        } else {
            f[i] = 500000004 * f[i - 1] % mod;
        }
    }
    cout << (n - 1 + f[n - 1]) % mod << '\n';
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