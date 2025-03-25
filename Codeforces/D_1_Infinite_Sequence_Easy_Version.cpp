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
    cin >> n >> m >> m;
    std::vector<int> a(n + 1);
    std::vector<int> pre(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) pre[i] = pre[i - 1] ^ a[i];
    if (n % 2 == 0) {
        a.pb(pre[pre[(n + 1) / 2]]);
        pre.pb(pre[n] ^ a[n + 1]);
        n++;
    }
    auto find = [&](auto& self, int p) -> int {
        if (p <= n) return a[p];
        if ((p >> 1) <= n) {
            return pre[p / 2];
        } else {
            if ((p >> 1) & 1) {
                return pre[n];
            } else {
                return pre[n] ^ self(self, p >> 1);
            }
        }
    };
    cout << find(find, m) << '\n';
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