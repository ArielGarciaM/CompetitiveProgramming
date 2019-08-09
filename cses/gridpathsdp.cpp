#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

char board[1000][1000];
ll dp[1000][1000];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> board[i][j];

	if(board[0][0] == '.')
		dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == '*') continue;
			if(i) dp[i][j] += dp[i - 1][j];
			if(j) dp[i][j] += dp[i][j - 1];
			while(dp[i][j] >= MOD)
				dp[i][j] -= MOD;
		}
	}
	cout << dp[n - 1][n - 1] << '\n';
}
