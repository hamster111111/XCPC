#pragma GCC optimize("O3, unroll-loops")
#include<bits/stdc++.h>
// #define int long long
#define ll long long
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
int k;
int m;

void solve() {
    cin >> n >> k;
    std::string a, b, c;
    cin >> a >> b;
    std::vector<char> diff;
    std::vector<int> st(26);
    rep(i, 0, n - 1) {
        if (a[i] != b[i] && std::find(diff.begin(), diff.end(), a[i]) == diff.end()) diff.pb(a[i]);
    }
    ll ans = 0;
    m = diff.size();
    // for(auto& i : diff) std::cerr << i << " ";
    // std::cerr << "\n";
    rep(i, 0, (1 << m) - 1) {
        if (__builtin_popcountll(i) > k) continue;
        ll res = 0;
        rep(j, 0, m - 1) if (i & (1ll << j)) st[diff[j] - 'a']++;
        c = a;
        rep(j, 0, n - 1) if (c[j] != b[j] && st[c[j] - 'a']) c[j] = b[j];
        // rep(j, 0, 25) std::cerr << st[j] << " ";
        // std::cerr << "\n";
        rep(j, 0, m - 1) if (i & (1ll << j)) st[diff[j] - 'a']--;
        ll len = 0;
        rep(j, 0, n - 1) {
            if (c[j] == b[j]) {
                len++;
            } else {
                // std::cerr << len << '\n';
                res += (len + 1) * len / 2;
                len = 0;
            }
        }
        res += (len + 1) * len / 2;
        ans = std::max(ans, res);
    }
    cout << ans << '\n';
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