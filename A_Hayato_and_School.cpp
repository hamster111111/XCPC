#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= b; ++i)
#define per(i, a, b) for(int i = (a); i >= b; --i)
using std::cin;
using std::cout;

int n;

void solve() {
    cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> ans;
    rep(i, 1, n) cin >> a[i], a[i] %= 2;
    rep(i, 1, n) {
        if (a[i]) ans.push_back(i);
    }

    if (ans.size() == 0 || (ans.size() == 2 && n == 3)) {
        cout << "NO\n";
        return;
    }

    if (ans.size() < 3) {
        while(ans.size() != 1)ans.pop_back();
        rep(i, 1, n) {
            if (a[i] == 0) ans.push_back(i);
            if (ans.size() == 3) break;
        }
    }

    while (ans.size() > 3) ans.pop_back();
    cout << "YES\n";
    for(auto& i : ans) cout << i << " ";
    cout << "\n";
}

signed main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}