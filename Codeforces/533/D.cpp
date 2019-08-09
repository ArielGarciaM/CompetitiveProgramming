#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int dist[10][MAXN], po[10], pos[10], ans[10], n, m, p;
queue<int> q[10];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char board[1000][1000];

void bfs(int pl) {
    while(!q[pl].empty()) {
        int u = q[pl].front();
        q[pl].pop();
        int r = u / m, c = u % m;
        for(int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if(board[nr][nc] != '.')
                continue;
            bool b = true;
            for(int j = 1; j < pl; j++) {
                if(dist[j][m*nr + nc] != -1 && (dist[j][m*nr + nc] + po[j] - 1)/po[j] <= (dist[pl][u])/po[pl] + 1) {
                    b = false;
                    break;
                }
            }
            if(!b)
                continue;
            if(dist[pl][m*nr + nc] == -1) {
                dist[pl][m*nr + nc] = dist[pl][u] + 1;
                q[pl].push(m*nr + nc);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dist, -1, sizeof dist);
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> po[i];
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if(board[i][j] >= '1' && board[i][j] <= '9') {
                q[board[i][j] - '0'].push(m*i + j);
                dist[board[i][j] - '0'][m*i + j] = 0;
            }
        }
    }
    for(int j = 1; j <= p; j++)
        bfs(j);
    for(int v = 0; v < m*n; v++) {
        if(board[v/m][v%m] == '#')
            continue;
        int mn = 10000000, bst = -1;
        for(int j = 1; j <= p; j++) {
            cout << v/m << " " << v%m << " " << j << " " << dist[j][v] << endl;
            if(dist[j][v] != -1 && (dist[j][v] + po[j] - 1)/po[j] < mn) {
                mn = (dist[j][v] + po[j] - 1)/po[j];
                bst = j;
            }
        }
        if(bst != -1)
            ans[bst]++;
    }
    for(int i = 1; i <= p; i++)
        cout << ans[i] << " ";
    cout << endl;
}