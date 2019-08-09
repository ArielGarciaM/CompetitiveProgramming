#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll binom[205][205], cnt[10], prf[10], dp[10][55][11], sum;
string s;

ll calc() {
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 55; j++)
            for(int k = 0; k < 11; k++)
                dp[i][j][k] = 0;
    for(int i = 0; i < 10; i++)
        prf[i] = cnt[i] + (i ? prf[i - 1] : 0);
    ll fir = (prf[9] + 1)/2, snd = prf[9]/2;
    for(int k = 0; k <= min(cnt[0], fir); k++)
        dp[0][k][0] = 1;
    for(int dig = 1; dig <= 9; dig++) {
        for(ll k = 0; k <= min(prf[dig], fir); k++) {
            if(prf[dig] - k > snd) continue;
            ll l = prf[dig] - k;
            for(int res = 0; res <= 10; res++) {
                for(int amt = 0; amt <= min(k, cnt[dig]); amt++) {
                    int ores = (res - amt * dig) % 11;
                    int omt = cnt[dig] - amt;
                    if(ores < 0)
                        ores += 11;
                    ll tot = dp[dig - 1][k - amt][ores];
                    tot = (tot * binom[k][amt]) % MOD;
                    tot = (tot * binom[l][omt]) % MOD;
                    dp[dig][k][res] += tot;
                    if(dp[dig][k][res] >= MOD)
                        dp[dig][k][res] -= MOD;
                }
            }
        }
    }
    return dp[9][fir][(6*sum) % 11];
}

void solve() {
    fill(cnt, cnt + 10, 0);
    sum = 0;
    for(auto c : s) {
        cnt[c - '0']++;
        sum += (c - '0');
    }
    ll ans = calc();
    if(cnt[0]) {
        cnt[0]--;
        ans -= calc();
    }
    ans %= MOD;
    if(ans < 0)
        ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 205; i++)
        binom[i][0] = binom[i][i] = 1;
    for(int i = 1; i < 205; i++)
        for(int j = 1; j < 205; j++)
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
    while(cin >> s) solve();
}