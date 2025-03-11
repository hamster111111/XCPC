#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
using std::cin;
using std::cout;
const int mod = 1e9 + 7;

int n;
int m;

void solve() {
    cin >> n;
    std::vector<std::vector<int>> edge(n + 1);
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        edge[u].pb(v), edge[v].pb(u);
    }
    std::vector<int> deep(n + 1);
    auto ksm = [](int a, int b) -> int {
        int ans = 1;
        while (b) {
            
            if (b & 1) ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans % mod;
    };
    auto dfs = [&](auto& self, int p, int pre) -> void {
        for(auto& i : edge[p]) {
            if (i == pre) continue;
            self(self, i, p);
            deep[p] = std::max(deep[p], deep[i] + 1);
        }
    };
    dfs(dfs, 1, 0);
    int ans = 0;
    rep(i, 1, n) {
        ans = (ans + (deep[i] + 1) * ksm(2, mod - 2) % mod) % mod;
    }
    ans = (ans * ksm(2, n)) % mod;
    cout << ans << '\n';
}

signed main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}