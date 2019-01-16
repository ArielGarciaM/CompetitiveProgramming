#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1 << 16], cost[1 << 16], mat[16][16];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    for(int msk = 1; msk < (1 << n); msk++) {
        int b = 31 - __builtin_clz(msk);
        cost[msk] = cost[msk ^ (1 << b)];
        for(int k = 0; k < b; k++) {
            if(msk & (1 << k))
                cost[msk] += mat[b][k];
        }
    }
    for(int msk = 1; msk < (1 << n); msk++) {
        for(int sm = msk; sm; sm = (sm - 1) & msk) {
            dp[msk] = max(dp[msk], dp[msk ^ sm] + cost[sm]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}