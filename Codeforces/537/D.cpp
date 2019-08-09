#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

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

const ll MAXN = 1e5 + 5;
ll fac[MAXN], ifac[MAXN];

ll binom(ll n, ll k) {
    ll aux = (ifac[k]*ifac[n - k])%MOD;
    return (fac[n] * aux)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = ifac[0] = 1;
    for(ll i = 1; i < MAXN; i++) {
        fac[i] = (i * fac[i - 1])%MOD;
        ifac[i] = inv(fac[i]);
    }
    map<char, ll> cnt;
    string s;
    cin >> s;
    ll n = s.length()/2;
    for(int i = 0; i < 2*n; i++)
        cnt[s[i]]++;
    ll p = 1;
    for(auto pr : cnt)
        p = (p * ifac[pr.second]) % MOD;
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(s[x - 1] != s[y - 1]) {
            ll a = cnt[s[x - 1]], b = cnt[s[y - 1]];
            if(a + b > n) {
                cout << "0\n";
                continue;
            }
            ll res = (binom(n, a) * binom(n - a, b)) % MOD;
            res = (res * fac[2*n - a - b]) % MOD;
            res = (res * fac[a]) % MOD;
            res = (res * fac[b]) % MOD;
            res = (res * p) % MOD;
            cout << (2*res)%MOD << '\n';
        }
        else {
            ll a = cnt[s[x - 1]];
            if(a > n) {
                cout << "0\n";
                continue;
            }
            ll res = (binom(n, a) * fac[2*n - a]) % MOD;
            res = (res * fac[a]) % MOD;
            res = (res * p) % MOD;
            cout << (2*res)%MOD << '\n';
        }
    }
}