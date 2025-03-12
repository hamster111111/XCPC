#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)
using std::cin;
using std::cout;

int n;

void solve() {
    auto ask = [](int x) -> void {
        cout << "- " << x << '\n';
    };
    auto get = []() -> int {
        int x;
        cin >> x;
        return x;
    };
    auto know = [](int x) -> void {
        cout << "! " << x << '\n';
    };
    int ans = 0;
    int cnt = get();
    ask(1);
    int next_cnt = get();
    int diff = next_cnt - cnt;
    ans += 1ll << diff + 1;
    int cur = diff + 1;

    while (cur != next_cnt) {

        cnt = next_cnt;

        ask(1ll << cur);

        next_cnt = get();

        diff = next_cnt - cnt + 1;
        cur += diff;
        ans += 1ll << cur; 
    }

    know(ans);

}

signed main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}