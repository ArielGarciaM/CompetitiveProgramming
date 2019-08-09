#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

char board[32][32];
int vis[32][32];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
	int t;
	cin >> t;
	while(t--) {
		for(int i = 0; i < 32; i++)
			for(int j = 0; j < 32; j++)
				board[i][j] = '0';
		memset(vis, 0, sizeof vis);
		int r, c;
		cin >> r >> c;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				cin >> board[i][j];
		int ans = 0;
		queue<ii> q;
		q.push(ii{0, 0});
		vis[0][0] = 1;
		while(!q.empty()) {
			ii p = q.front();
			q.pop();
			if(1 <= p.first && p.first <= r && 1 <= p.second && p.second <= c)
				ans++;
			for(int i = 0; i < 4; i++) {
				int nr = p.first + dx[i], nc = p.second + dy[i];
				if(nr < 0 || nc < 0 || nr > 31 || nc > 31)
					continue;
				if(board[nr][nc] == '1')
					continue;
				if(!vis[nr][nc]) {
					vis[nr][nc] = 1;
					q.push({nr, nc});
				}
			}
		}
		cout << ans << '\n';
	}
}