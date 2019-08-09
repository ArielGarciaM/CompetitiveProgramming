#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 15;
const ll MOD = 1e9 + 7;
ll dp[(1 << MAX)][230][3];
int t[MAX], gen[MAX], n, T;

ll calc(int ms, int tm, int ge) {
    if(dp[ms][tm][ge] != -1) return dp[ms][tm][ge];
    dp[ms][tm][ge] = 0;
    if(__builtin_popcount(ms) == 1) {
        for(int b = 0; b < n; b++) {
            if(ms & (1 << b)) {
                if(gen[b] == ge && t[b] == tm)
                    dp[ms][tm][ge] = 1;
            }
        }
        return dp[ms][tm][ge];
    }
    ll tot = 0;
    for(int b = 0; b < n; b++) {
        if((ms & (1 << b)) == 0) continue;
        if(gen[b] != ge) continue;
        if(t[b] > tm) continue;
        for(int j = 0; j < 3; j++) {
            if(j != ge)
                tot = (tot + calc(ms ^ (1 << b), tm - t[b], j)) % MOD;
        }
    }
    return dp[ms][tm][ge] = tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> T;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> gen[i];
        gen[i]--;
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for(int i = 1; i < (1 << n); i++) {
        for(int j = 0; j < 3; j++) {
            ans = (ans + calc(i, T, j))%MOD;
        }
    }
    cout << ans << endl;
}