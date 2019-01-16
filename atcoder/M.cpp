#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e2 + 5;
const int MAXK = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll dp[MAXN][MAXK], a[MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            for(int w = 0; w <= k; w++)
                dp[i][w] = 1;
            continue;
        }
        dp[i][0] = dp[i - 1][0];
        for(int w = 1; w <= k; w++) {
            dp[i][w] = dp[i][w - 1];
            dp[i][w] = (dp[i][w] + dp[i - 1][w]) % MOD;
            if(w - a[i] > 0)
                dp[i][w] = (dp[i][w] - dp[i - 1][w - a[i] - 1] + MOD)%MOD;
        }
    }
    if(k == 0)
        cout << dp[n][k] << endl;
    else
        cout << (dp[n][k] - dp[n][k - 1] + MOD)%MOD << endl;
}
