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
using pii = std::pair<int, int>;

int n;
int h;
int w;

void solve() {
    cin >> n >> w >> h;
    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);
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