#include <bits/stdc++.h>
using namespace std;

char board[1005][1005];
int comp[1005][1005], n, m;
vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};

void dfs(int r, int c, int cc) {
	comp[r][c] = cc;
	for(int i = 0; i < 4; i++) {
		int nr = r + dx[i], nc = c + dy[i];
		if(nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] == '#' || comp[nr][nc])
			continue;
		dfs(nr, nc, cc);
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int cc = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!comp[i][j] && board[i][j] == '.') dfs(i, j, ++cc);
		}
	}
	cout << cc << '\n';
}
