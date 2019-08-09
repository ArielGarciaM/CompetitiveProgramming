#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 205;
int dist[MAXN][MAXN][4];
pair<ii, int> pre[MAXN][MAXN][4];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
int xb, yb, xu, yu, xc, yc, xg, yg;
int N, M;

void bfs(int x, int y, int m) {
    queue<pair<ii, int>> q;
    q.push(make_pair(ii{x, y}, 0));
    dist[x][y][0] = 0;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        x = p.first.first, y = p.first.second, m = p.second;
        if(x == xg && y == yg)
            continue;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx <= 0 || nx > N || ny <= 0 || ny > M)
                continue;
            int nm = m;
            if(nx == xc && ny == yc)
                nm |= 1;
            if(nx == xu && ny == yu)
                nm |= 2;
            if(dist[nx][ny][nm] == -1) {
                q.push(make_pair(ii{nx, ny}, nm));
                pre[nx][ny][nm] = make_pair(ii{x, y}, m);
                dist[nx][ny][nm] = dist[x][y][m] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >> M, N > 0) {
        cin >> xb >> yb >> xc >> yc >> xg >> yg >> xu >> yu;
        memset(dist, -1, sizeof dist);
        pre[xb][yb][0] = make_pair(ii{-1, -1}, -1);
        bfs(xb, yb, 0);
        if(dist[xg][yg][1] == -1)
            cout << "NO\n";
        else {
            cout << "YES\n";
            string ans = "";
            int cx = xg, cy = yg, cm = 1;
            auto p = pre[cx][cy][cm];
            while(p.second != -1) {
                int nx = p.first.first, ny = p.first.second, nm = p.second;
                if(cx == nx + 1)
                    ans += "U";
                if(cx == nx - 1)
                    ans += "D";
                if(cy == ny + 1)
                    ans += "R";
                if(cy == ny - 1)
                    ans += "L";
                cx = nx, cy = ny;
                p = pre[cx][cy][nm];
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
    }
}