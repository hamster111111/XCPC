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
    int x;
    cin >> x >> n >> m;

    auto find_min = [](int x, int n, int m) -> int {
        int num = 0;
        rep(i, 0, std::min(30ll, n + m - 1)) {
            if (x >> i & 1) {
                num++;
            }
        }
        int ans = 0;
        per(i, 30, std::min(30ll, n + m)) {
            ans <<= 1;
            if (x >> i & 1) ans++;
        }
        // cout << ans << '\n';
        if (n + m - num >= m) return ans;
        return ++ans;
    };

    auto find_max = [](int x, int n, int m) -> int {
        int num = 0;
        per(i, std::min(30ll, n + m - 1), 0) {
            if (x >> i & 1) {
                num += std::max(0ll, n + m - 30);
                break;
            } else num++;
        }
        int ans = 0;
        per(i, 30, std::min(30ll, n + m)) {
            ans <<= 1;
            if (x >> i & 1) ans++;
        }
        if (num >= m) return ans;
        return ++ans;
    };
    cout << find_min(x, n, m) << ' ' << find_max(x, n, m) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    freopen("data.out", "r", stdin);
    freopen("baoli.out", "w", stdout);
    std::cin >> _;
    while (_--) {
        solve();
    }
}