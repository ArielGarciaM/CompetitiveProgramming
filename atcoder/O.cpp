#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[1 << 21];

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    dp[0] = 1;
    for(int msk = 1; msk < (1 << n); msk++) {
        int r = __builtin_popcount(msk) - 1;
        for(int i = 0; i < n; i++) {
            if((msk & (1 << i)) && v[r][i])
                dp[msk] = (dp[msk] + dp[msk ^ (1 << i)]) % MOD;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}