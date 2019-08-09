#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> v(n), dp(m + 1, 1), tmp(m + 1, 0);
	dp[0] = 0;
	int x;
	cin >> x;
	if(x) {
		fill(dp.begin(), dp.end(), 0);
		dp[x] = 1;
	}	
	for(int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		if(x) {
			ll tot = (dp[x] + (x < m ? dp[x + 1] : 0) + (x ? dp[x - 1] : 0));
			while(tot >= MOD) tot -= MOD;
			fill(dp.begin(), dp.end(), 0);
			dp[x] = tot;
		}
		else {
			for(int j = m; j >= 1; j--) {
				ll tot = dp[j] + dp[j - 1] + (j < m ? dp[j + 1] : 0);
				while(tot >= MOD) tot -= MOD;
				tmp[j] = tot;
			}
			dp = tmp;
		}
	}
	ll tot = accumulate(dp.begin(), dp.end(), 0LL);
	cout << tot % MOD << '\n';
}
