#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
int prime[MAXN], f[MAXN];
ll fac[MAXN], spec[MAXN], ways[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        for(int q = p; q < MAXN; q += p) {
            if(!prime[q]) prime[q] = p;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    spec[0] = 0;
    for(ll i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        spec[i] = ((spec[i - 1] + 1) * i) % MOD;
    }
    for(int i = 1; i <= 10; i++)
        cout << i << " " << spec[i] << '\n';
    sieve();
    int n;
    cin >> n;
    ways[1] = 1;
    int mx = 31 - __builtin_clz(n);
    for(int i = 2; i <= n; i++) {
        int d = i;
        f[d] = f[d / prime[d]] + 1;
        while(d > 1) {
            int p = prime[d];
            while(d % p == 0) d /= p;
            if(f[i / p] == f[i] - 1) {
                ways[i] = (ways[i] + ways[i / p]*spec[n / (i / p) - n / i]) % MOD;
                if(ways[i] < 0)
                    ways[i] += MOD;
            }
            cout << i << " " << ways[i] << '\n';
        }
    }
    ll tways = 0;
    for(int i = 2; i <= n; i++) {
        if(f[i] == mx)
            tways = (tways + ways[i]) % MOD;
    }
    cout << tways << '\n';
}