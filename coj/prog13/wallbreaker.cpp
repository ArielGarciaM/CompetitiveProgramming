#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char board[1005][1005];
int comp[1005][1005], score[1005*1005], n, m;
bool reach[1005][1005];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j, int cc) {
    comp[i][j] = cc;
    //cout << cc << " " << i << " " << j << '\n';
    if(board[i][j] == '#')
        score[cc]++;
    for(int d = 0; d < 8; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if(ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1) continue;
        if(comp[ni][nj]) continue;
        if(board[ni][nj] == '*') {
            if(cc == 1) reach[ni][nj] = true;
            continue;
        }
        dfs(ni, nj, cc);
    }
}

void test_case(int n, int m) {
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            board[i][j] = '.';
            reach[i][j] = false;
            comp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    //for(int i = 0; i <= n + 1; i++) {
    //    for(int j = 0; j <= m + 1; j++) {
    //        cout << board[i][j];
    //    }
    //    cout << '\n';
    //}

    int cc = 1;
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            if(!comp[i][j] && board[i][j] != '*') {
                score[cc] = 0;
                dfs(i, j, cc);
                cc++;
            }
        }
    }
    //for(int i = 1; i <= cc - 1; i++)
    //    cout << i << " " << score[i] << '\n';
    int ans = score[1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!reach[i][j]) continue;
            set<int> seen;
            int tmp = 0;
            for(int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if(board[ni][nj] == '*') continue;
                int c = comp[ni][nj];
                if(!seen.count(c)) {
                    //cout << i << " " << j << " " << c << '\n';
                    tmp += score[c];
                    seen.insert(c);
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    while(cin >> n >> m)
        test_case(n, m);
}