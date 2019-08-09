#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 18;
const ll MOD = 998244353;
ll dp[1 << MAXN], amt[1 << MAXN];
int from[MAXN], conn[MAXN];
bool good[1 << MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        conn[u] |= (1 << v);
        conn[v] |= (1 << u);
        from[v] |= (1 << u);
    }
    for(int b = 0; b < (1 << n); b++) {
        good[b] = true;
        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                if((b & (1 << u)) && (b & (1 << v)) && (conn[u] & (1 << v)))
                    good[b] = false;
            }
        }
    }

    amt[0] = 1;
    for(int msk = 0; msk < (1 << n); msk++) {
        for(int sm = msk; sm > 0; sm = (sm - 1) & msk) {
            if(!good[sm])
                continue;
            int oth = msk ^ sm;
            ll cnt = 0;
            for(int b = 0; b < n; b++)
                if(sm & (1 << b))
                    cnt += __builtin_popcount(from[b] & oth);
            dp[msk] = (dp[msk] + cnt * amt[oth] + dp[oth]) % MOD;
            amt[msk] = (amt[msk] + amt[oth]) % MOD;
        }
        cout << msk << " " << dp[msk] << " " << amt[msk] << " " << good[msk] << endl;
    }
    cout << dp[(1 << n) - 1] << '\n';
}