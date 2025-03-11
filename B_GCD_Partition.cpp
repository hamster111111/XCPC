#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i) 
#define per(i, a, b) for(int i = (a); i >= (b); --i)
using std::cin;
using std::cout;

int n;

void solve() {
    cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> pre(n + 1);
    std::vector<int> suf(n + 2);
    rep(i, 1, n) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    per(i, n, 1) {
        suf[i] = suf[i + 1] + a[i];
    }
    int ans = 0;
    rep(i, 1, n - 1) {
        ans = std::max(ans, std::__gcd(pre[i], suf[i + 1]));
    }
    cout << ans << '\n';
}

signed main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}