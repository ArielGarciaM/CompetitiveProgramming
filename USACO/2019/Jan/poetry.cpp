#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5005][5005], sdp[5005], ct[26], clss[5005];
const ll MOD = 1e9 + 7;
pair<int, int> words[5005];

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e / 2);
    return (p * p) % MOD;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        int w, t;
        cin >> w >> t;
        words[i] = {w, t};
    }
    sdp[0] = 1;
    for(int num = 1; num <= K; num++) {
        for(int ty = 1; ty <= N; ty++) {
            if(num - words[ty].first >= 0) {
                dp[num][ty] = sdp[num - words[ty].first];
                sdp[num] = (sdp[num] + dp[num][ty])%MOD;
            }
        }
    }
    for(int ty = 1; ty <= N; ty++)
        clss[words[ty].second] = (clss[words[ty].second] + dp[K][ty]) % MOD;
    for(int i = 0; i < M; i++) {
        char c;
        cin >> c;
        ct[c - 'A']++;
    }
    ll ans = 1;
    for(int i = 0; i < 26; i++) {
        if(ct[i] == 0)
            continue;
        ll p = 0;
        for(int j = 1; j <= N; j++)
            p = (p + mpow(clss[j], ct[i])) % MOD;
        ans = (ans * p) % MOD;
    }
    cout << ans << endl;
}