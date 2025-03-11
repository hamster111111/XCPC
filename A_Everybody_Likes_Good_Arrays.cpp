#include<bits/stdc++.h>
using std::cin;
using std::cout;

int n;
int m;

void solve() {
    cin >> n;
    std::vector<int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] %= 2;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (v[i] != v[i - 1]) {
            sum += cnt - 1;
            cnt = 1;
        } else cnt++;
    }
    sum += cnt - 1;
    cout << sum << '\n';
}

int main() 
{
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}