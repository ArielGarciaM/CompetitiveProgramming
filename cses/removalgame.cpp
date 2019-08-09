#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2][5005][5005];
const ll INF = 1e18;

int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for(auto &x : v)
		cin >> x;
	for(int k = 0; k < n; k++) {
		for(int l = 0; l + k < n; l++) {
			int r = l + k;
			if(l == r) {
				dp[0][l][r] = v[l];
				dp[1][l][r] = 0;
			}
			else {
				dp[1][l][r] = INF;
				dp[0][l][r] = max(v[l] + dp[1][l + 1][r], v[r] + dp[1][l][r - 1]);
				dp[1][l][r] = min(dp[0][l + 1][r], dp[0][l][r - 1]);
			}
		}
	}
	cout << dp[0][0][n - 1] << '\n';
}
