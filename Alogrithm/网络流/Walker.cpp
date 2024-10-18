#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
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
const double eps = 1e-10;
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

void solve() {
    double n, p1, v1, p2, v2;
    cin >> n >> p1 >> v1 >> p2 >> v2;
    if (p1 > p2) {
        std::swap(p1, p2);
        std::swap(v1, v2);
    }
    auto check1 = [&](double t) -> bool {
        double l1, r1, l2, r2;
        if (t * v1 >= p1) {
            l1 = 0;
            if (t * v1 >= 2 * p1) {
                r1 = std::min(t * v1 - p1, n);
            } else r1 = p1;
        } else {
            r1 = p1;
            l1 = p1 - t * v1;
        }

        if (t * v2 >= n - p2) {
            r2 = n;
            if (t * v2 >= 2 * (n - p2)) {
                l2 = std::max((double)0, 2 * n - t * v2 - p2);
            } else l2 = p2;
        } else {
            l2 = p2;
            r2 = p2 + t * v2;
        }
        if (r1 >= l2) {
            if (std::min(l1, l2) < eps && n - std::max(r1, r2) < eps) return true;
        }
        return false;
    };
    auto find1 = [&]() -> double {
        double l = 0, r = 1e10;
        while (r - l > eps) {
            double mid = (r + l) / 2;
            if (check1(mid)) r = mid;
            else l = mid;
        }
        return r;
    };

    auto check3 = [&](double t) -> bool {
        double l1, r1, l2, r2;
        if (t * v2 >= p2) {
            l2 = 0;
            if (t * v2 >= 2 * p2) {
                r2 = std::min(t * v2 - p2, n);
            } else r2 = p2;
        } else {
            r2 = p2;
            l2 = p2 - t * v2;
        }

        if (t * v1 >= n - p1) {
            r1 = n;
            if (t * v1 >= 2 * (n - p1)) {
                l1 = std::max((double)0, 2 * n - t * v1 - p1);
            } else l1 = p1;
        } else {
            l1 = p1;
            r1 = p1 + t * v1;
        }
        if (r1 >= l2) {
            if (std::min(l1, l2) < eps && n - std::max(r1, r2) < eps) return true;
        }
        return false;
    };

    auto find3 = [&]() -> double {
        double l = 0, r = 1e10;
        while (r - l > eps) {
            double mid = (r + l) / 2;
            if (check3(mid)) r = mid;
            else l = mid;
        }
        return r;
    };

    auto check2 = [&](double x) -> double {
        double t1 = p1 / v1 + 2 * (x - p1) / v1;
        double t2 = (n - p2) / v2 + 2 * (p2 - x) / v2;
        return std::max(t1, t2);
    };

    auto find2 = [&]() -> double {
        double l = p1, r = p2;
        while (r - l > eps) {
            double k = (r - l) / 3;
            double mid1 = l + k, mid2 = l + 2 * k;
            if (check2(mid1) < check2(mid2)) r = mid2;
            else l = mid1;
        }
        return check2(r);
    };

    double t1 = find1();
    double t2 = find2();
    double t3 = find3();

    cout << std::fixed << std::setprecision(10) << std::min({t1, t2 ,t3}) << '\n';
    cout << std::fixed << std::setprecision(10) << t1 << '\n';
    cout << std::fixed << std::setprecision(10) << t2 << '\n';
    cout << std::fixed << std::setprecision(10) << t3 << '\n';
    cout << '\n';
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