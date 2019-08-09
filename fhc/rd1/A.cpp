#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
int dis[55][55];
vector<array<int, 3>> edg;

void solve() {
    for(int i = 0; i < 55; i++) {
        for(int j = 0; j < 55; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    int n, m;
    cin >> n >> m;
    edg.clear();
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = z;
        dis[y][x] = z;
        edg.push_back({x, y, z});
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(auto e : edg) {
        if(dis[e[0]][e[1]] != e[2]) {
            cout << "Impossible\n";
            return;
        }
    }
    cout << m << '\n';
    for(auto e : edg)
        cout << e[0] << " " << e[1] << " " << e[2] << '\n';
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}