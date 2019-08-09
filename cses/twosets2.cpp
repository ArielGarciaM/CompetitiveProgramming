#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[1000000];

int main() {
	int n;
	cin >> n;
	if(n % 4 == 1 || n % 4 == 2) {
		cout << "0\n";
		return 0;
	}
	dp[0] = 1;
	int s = (n * (n + 1))/4;
	for(int i = 1; i <= n; i++){
		for(int j = s; j >= i; j--) {
			dp[j] += dp[j - i];
			if(dp[j] >= MOD)
				dp[j] -= MOD;
		}
	}
	cout << (dp[s] * 500000004LL)%MOD << '\n';
}
