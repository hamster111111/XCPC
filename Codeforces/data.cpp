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

void solve() {
    int t = 10;
    cout << t << '\n';
    std::mt19937_64 rand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    rep(i, 1, t) {
        int x = rand() % 10 + 1;
        int n = rand() % 5 + 1;
        int m = rand() % 5 + 1;
        cout << x << ' ' << n << ' ' << m << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    freopen("data.out", "w", stdout);
    while (_--) {
        solve();
    }
}