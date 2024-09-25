#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
#define int long long
#define fr first 
#define sc second 
#define DEBUG_
#ifdef DEBUG_
#define dbg(a) std::cerr << #a << ':' << a << '\n'
template<class T>
void print_(T &t) {
   std::cerr << t << '\n';
}
template<class T, class... Args>
void print_(T &t, Args&... args) {
   std::cerr << t << ' ';
   print_(args...);
}
#else
#define dbg(a)
template<class T>
void print_(T &t) {
}
template<class T, class... Args>
void print_(T &t, Args&... args) {
}
#endif
#define rep(i, a, b) for(int i = (a);i <= (b); ++i)
#define per(i, a, b) for(int i = (a);i >= (b); --i)
#define pb push_back
#define eb emplace_back
#define mem(a, b) memset(a, b, sizeof a)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define lowbit(x) (x & -x)
#define PY puts("YES")
#define Py puts("Yes")
#define PN puts("NO")
#define Pn puts("No")
#define all(x, l, r) x.begin() + l, x.begin() + r + 1
//using namespace std;
const int N = 1e6 + 10;
const int M = 320;
const int INF = 1e18 + 10;
const int mod = 998244353;
//const int mod = 1e9 + 7;
const int base1 = 131;
const int base2 = 13331;
using PII = std::pair<int, int>;
using ull = unsigned long long;
using ll = long long;
using std::array;
using std::cin;
using std::cout;
using std::vector;
template <class T>
using pq_g = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using pq_ = std::priority_queue<T>;

int n;
int m;

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) {
        cin >> a[i];
    }
    int l = 0, r = *std::max_element(all(a, 1, n)) - *std::min_element(all(a, 1, n));
    auto check2 = [&](int x, int y) -> int {
        // print_(y);
        int s = 0;
        int t = 0;
        int ll = std::max(0ll, y - x), rr = y;
        rep(i, 1, n) {
            if (a[i] > rr) s += a[i] - rr;
            if (a[i] > ll) t += std::min(x, a[i] - ll);
            if (a[i] < ll) {
                if (s + a[i] >= ll) {
                    s += a[i] - ll;
                } else if (s + a[i] + t >= ll) {
                    t -= ll - a[i] - s;
                    s = 0;
                } else {
                    return 1;
                }
            }
        }
        s = 0;
        rep(i, 1, n) {
            if (a[i] > rr) s += a[i] - rr;
            else s -= std::min(s, rr - a[i]);
        }
        if (s > 0) return -1;
        return 0;
    };
    auto check = [&](int x) -> bool {
        int l1 = 1, r1 = 1e12;
        while(l1 < r1) {
            int mid = l1 + r1 + 1 >> 1;
            if (check2(x, mid) == 1) r1 = mid - 1;
            else if (check2(x, mid) == -1) l1 = mid + 1;
            else return true;
        }
        return check2(x, l1) == 0 || check2(x, r1) == 0;
    };
    while (l < r) {
        int mid = l + r >> 1;
        // print_(mid);
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    // std::cout << check2(1, 3) << '\n';
    std::cout << r << '\n';
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