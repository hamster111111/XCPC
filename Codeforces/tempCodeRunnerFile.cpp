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
    std::string s = "0";
    auto reply = [&](std::string t, std::string s) -> void {
        // std::cout << t << ' ' << s << '\n';
        printf("%s %s\n", t.c_str(), s.c_str());
        fflush(stdout);
    };
    auto answer = []() -> bool {
        int f;
        // std::cin >> f;
        scanf("%lld", &f);
        // fflush(stdout);
        return f;
    };
    srand(time(0));
    bool is_new = true;
    bool is_back = true;
    int num;
    while (1) {
        std::cout << is_new << '\n';
        if (is_new) {
            num = rand() % 2;
            if (is_back) {
                s = s + std::to_string(num);
                reply("?", s);
                if (!answer()) {
                    s.pop_back();
                    is_new = false;
                }
            } else {
                s = std::to_string(num) + s;
                reply("?", s);
                if (!answer()) {
                    s.erase(0, 1);
                    is_new = false;
                }
            }
        } else {
            num = !num;
            if (is_back) {
                s = s + std::to_string(num);
                reply("?", s);
                if (!answer()) {
                    s.pop_back();
                    is_back = false;
                    is_new = true;
                } else {
                    is_new = true;
                }
            } else {
                s = std::to_string(num) + s;
                reply("?", s);
                if (!answer()) {
                    s.clear();
                    rep(i, 1, n) s += "1";
                    reply("!", s);
                    break;
                } else {
                    is_new = true;
                }
            }
        }
        if(s.size() == n) {
            reply("!", s);
            break;
        }
    }
}

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--) {
        solve();
    }
}