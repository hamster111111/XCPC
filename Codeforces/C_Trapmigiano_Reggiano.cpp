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
int st, ed;

void solve() {
    cin >> n >> st >> ed;
    std::vector<std::vector<int>> edge(n + 1);
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        edge[u].pb(v), edge[v].pb(u);
    }
    std::vector<std::vector<int>> deep(n);
    auto do_pre = [&](auto& self, int p, int pre, int dep) -> void {
        deep[dep].pb(p);
        for(auto& i : edge[p]) {
            if (i == pre) continue;
            self(self, i, p, dep + 1);
        }
    };
    do_pre(do_pre, ed, 0, 0);
    per(i, n - 1, 0) {
        for(auto& j : deep[i]) {
            cout << j << ' ';
        }
    }
    cout << '\n';
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