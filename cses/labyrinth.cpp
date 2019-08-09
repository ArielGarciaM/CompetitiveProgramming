#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

string board[1005], cur;
int dis[1005][1005], n, m;
ii prv[1005][1005];
char rec[1005][1005];
vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
string mov = "ULRD";

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> board[i];
	queue<ii> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dis[i][j] = -1;
			if(board[i][j] == 'A') {
				q.push({i, j});
				dis[i][j] = 0;
			}
		}
	}
	while(!q.empty()) {
		auto p = q.front(); q.pop();
		int r = p.first, c = p.second;
		//cout << r << " " << c << " " << dis[r][c] << '\n';
		for(int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m || dis[nr][nc] != -1 || board[nr][nc] == '#')
				continue;
			dis[nr][nc] = dis[r][c] + 1;
			prv[nr][nc] = {r, c};
			rec[nr][nc] = mov[i];
			q.push({nr, nc});
		}
	}
	int x = -1, y = - 1;
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < m; j++) {
			if(board[i][j] == 'B') {
				x = i;
				y = j;
			}
		}
	}
	if(dis[x][y] == -1) {
		cout << "NO\n";
		return 0;
	}
	string result;
	while(board[x][y] != 'A') {
		result += rec[x][y];
		auto p = prv[x][y];
		x = p.first, y = p.second;
	}
	reverse(result.begin(), result.end());
	cout << "YES\n";
	cout << result.size() << '\n';
	cout << result << '\n';
}
