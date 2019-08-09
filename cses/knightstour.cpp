#include <bits/stdc++.h>
using namespace std;

int ans[8][8], deg[8][8], cur = 1;
vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve(int x, int y) {
    ans[x][y] = cur++;
    int mn = 10;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(ans[nx][ny] || nx < 0 || nx > 7 || ny < 0 || ny > 7)
            continue;
        deg[nx][ny]--;
        mn = min(mn, deg[nx][ny]);
    }
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(ans[nx][ny] || nx < 0 || nx > 7 || ny < 0 || ny > 7)
            continue;
        if(deg[nx][ny] == mn) {
            solve(nx, ny);
            return;
        }
    }
}

int main() {
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx > 7 || ny < 0 || ny > 7)
                    continue;
                deg[x][y]++;
            }
        }
    }
    int x, y;
    cin >> x >> y;
    --x, --y;
    solve(x, y);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << ans[j][i] << " ";
        }
        cout << '\n';
    }
}