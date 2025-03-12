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
    cin >> n;
    int a = 0, b = 0;
    rep(i, 1, 1e6) {
        int p = 0;
        if (n <= i * 4 - 3) {
            p = n, n = 0;
        } else p = i * 4 - 3, n -= 4 * i - 3;
        if (i & 1) a += p;
        else b += p;
        if (n == 0) break;
    }
    cout << a << " " << b << "\n";
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