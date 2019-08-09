#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
string s;
const int MAXN = 505;
const ll MOD = 1e9 + 7;
ll dp[MAXN][MAXN], binom[2*MAXN][2*MAXN];
 
ll calc(ll l, ll r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l % 2 == r % 2) return dp[l][r] = 0;
    if(l == r + 1) return dp[l][r] = 1;
    ll ans = 0;
    for(int m = l + 1; m <= r; m++) {
        if(s[l] != s[m]) continue;
        ll cl = ((m - 1) - (l + 1) + 1)/2ll, cr = (r - (m + 1) + 1)/2ll, wl = calc(l + 1, m - 1), wr = calc(m + 1, r);
        ll ways = ((wl * wr) % MOD * binom[cl + cr + 1][cr]);
        ans = (ans + ways)%MOD;
    }
    return dp[l][r] = ans;
}
 
int main() {
    cin >> s;
    for(int i = 0; i < 2*MAXN; i++) {
        binom[i][0] = binom[i][i] = 1;
        for(int j = 1; j <= i - 1; j++)
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1])%MOD;
    }
    memset(dp, -1, sizeof dp);
    cout << calc(0, s.size() - 1) << endl;
}