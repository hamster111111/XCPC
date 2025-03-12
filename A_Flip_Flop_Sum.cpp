#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
using std::cin;
using std::cout;

int n;

void solve() {
    cin >> n;
    std::vector<int> a(n + 1);
    rep(i, 1, n) {
        cin >> a[i];
    }
    int sum = std::accumulate(a.begin() + 1, a.end(), 0);
    rep(i, 1, n - 1) {
        if (a[i] == -1 && a[i + 1] == -1) {
            cout << sum + 4 << '\n';
            return;
        }
    }
    rep(i, 1, n - 1) {
        if (a[i] * a[i + 1] == -1) {
            cout << sum << '\n';
            return;
        }
    }
    cout << sum - 4 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_ --) {
        solve();
    }
}