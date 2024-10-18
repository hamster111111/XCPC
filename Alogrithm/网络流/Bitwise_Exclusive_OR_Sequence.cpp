#include <bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

const int N = 21;

int vis[21][21][21][21];
int dis[21][21][21][21];

void solve(){
    auto bfs = [&]() {
        queue<array<int, 4>> q;
        q.push({9, 9, 9, 9});
        dis[9][9][9][9] = 0;
        vis[9][9][9][9] = 1;
        while(q.size()) {
            auto [x, y, z, p] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++ ) {
                for(int j = i; j < 4; j ++ ) {
                    int nx = x, ny = y, nz = z, np = p;
                    for(int k = i; k <= j; k ++ ) {
                        if(k == 0) {
                            nx ++;
                        } else if(k == 1) {
                            ny ++;
                        } else if(k == 2) {
                            nz ++;
                        } else {
                            np ++;
                        }
                    }
                    nx = nx % 19;
                    ny = ny % 19;
                    nz = nz % 19;
                    np = np % 19;
                    if(!vis[nx][ny][nz][np]) {
                        dis[nx][ny][nz][np] = dis[x][y][z][p] + 1;
                        vis[nx][ny][nz][np] = true;
                        q.push({nx, ny, nz, np});
                    }
                    nx = x, ny = y, nz = z, np = p;
                    for(int k = i; k <= j; k ++ ) {
                        if(k == 0) {
                            nx --;
                        } else if(k == 1) {
                            ny --;
                        } else if(k == 2) {
                            nz --;
                        } else {
                            np --;
                        }
                    }
                    nx = (nx + 19) % 19;
                    ny = (ny + 19) % 19;
                    nz = (nz + 19) % 19;
                    np = (np + 19) % 19;
                    if(!vis[nx][ny][nz][np]) {
                        dis[nx][ny][nz][np] = dis[x][y][z][p] + 1;
                        vis[nx][ny][nz][np] = true;
                        q.push({nx, ny, nz, np});
                    }
                }
            }
        }
    };

    bfs();

    int m;
    cin >> m;
    while(m -- ) {
        string x, y;
        cin >> x >> y;
        int a = y[0] - x[0] + 9, b = y[1] - x[1] + 9, c = y[2] - x[2] + 9, d = y[3] - x[3] + 9;
        cout << dis[a][b][c][d] << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T -- ){
        solve();
    }
    return 0;
}