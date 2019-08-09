#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 1e9 + 7;
 
vector<vector<int>> dp, radj;
 
int main() {
	int n, m;
	cin >> n >> m;
	dp.resize(1 << n, vector<int>(n));
	radj.resize(n);
	while(m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		radj[v].push_back(u);
	}
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < n; j++)
			dp[i][j] = 0;
	dp[1][0] = 1;
	for(int msk = 3; msk < (1 << n); msk += 2) {
		for(int fin = 0; fin < n; fin++) {
			if(msk & (1 << fin)) {
				int sm = (msk ^ (1 << fin));
				for(auto v : radj[fin]) {
					if((1 << v) & sm) {
						dp[msk][fin] += dp[sm][v];
						if(dp[msk][fin] >= MOD) dp[msk][fin] -= MOD;
					}
				}
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1] << '\n';
}