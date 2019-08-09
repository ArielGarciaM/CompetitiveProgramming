#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[5005][5005], prob[26], nprob[26];
int m, n;

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e/2);
    return (p * p)%MOD;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

int main() {
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < 26; i++) {
        ll p, q;
        cin >> p >> q;
        prob[i] = (p * inv(q)) % MOD;
        nprob[i] = (MOD + 1 - prob[i]) % MOD;
    }
    dp[0][0] = 1;
    for(int l = 1; l <= n; l++) {
        for(int k = 0; k <= m; k++) {
            if(k == 0) {
                dp[l][0] = (nprob[s[0] - 'a']*dp[l - 1][0])%MOD;
                continue;
            }
            if(k < m) {
                dp[l][k] = ((prob[s[k - 1] - 'a']*dp[l - 1][k - 1])%MOD + (nprob[s[k] - 'a']*dp[l - 1][k])%MOD) % MOD;
                continue;
            }
            dp[l][m] = (dp[l - 1][m] + (prob[s[m - 1] - 'a']*dp[l - 1][m - 1])%MOD) % MOD;
        }
    }
    cout << (dp[n][m]%MOD + MOD) % MOD << endl;
}