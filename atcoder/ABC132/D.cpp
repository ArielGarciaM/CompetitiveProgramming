#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binom[2005][2005];
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 2005; i++)
        binom[i][0] = binom[i][i] = 1;
    for(int i = 1; i < 2005; i++)
        for(int j = 1; j < 2005; j++)
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1])%MOD;

    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= k; i++) {
        cout << (binom[k - 1][i - 1] * binom[n - k + 1][i]) % MOD << '\n';
    }
}