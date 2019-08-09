#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main() {
	for(int i = 1; i <= 500; i++) {
		for(int j = 1; j <= 500; j++) {
			if(i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 10000000;
			for(int k = 1; k < i; k++)
				dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
			for(int k = 1; k < j; k++)
				dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
		}
	}
	int a, b;
	cin >> a >> b;
	cout << dp[a][b] << '\n';
}
