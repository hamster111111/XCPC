#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = a; i <= b; i++)
const int mod = 1e9 + 7;
using std::cin;
using std::cout;

int n;

void solve() {
    cin >> n;
    int sum = n * (n - 1) % mod;
    rep(i, 1, n) sum = sum * i % mod;

    cout << sum << '\n';
}

signed main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}