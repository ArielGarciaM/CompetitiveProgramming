#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e6 + 3;
ll sig2[MOD];
int prime[MOD];

void sieve() {
    for(int p = 2; p < MOD; p++) {
        if(prime[p]) continue;
        for(int q = p; q < MOD; q += p) prime[q] = p;
    }
}

ll bpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k <<= 1) {
        if(k & e) res *= b;
        b *= b;
    }
    return res;
}

ll sqsum(ll n) {
    ll res = 1, tt = n;
    while(n > 1) {
        ll p = prime[n], k = 0;
        while(n % p == 0) {
            n /= p;
            k++;
        }
        ll x = 0;
        for(int i = 0; i <= 2*k; i += 2)
            x += bpow(p, i);
        res *= x;
    }
    res -= tt*tt;
    return res;
}

ll f[MOD];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    for(int i = 1; i < MOD; i++)
        f[i] = sqsum(i);
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), dp(1 << n);
    for(auto &x : v) cin >> x;
    for(int ms = 0; ms < (1 << n); ms++) {
        ll p = 1;
        for(int i = 0; i < n; i++)
            if(ms & (1 << i)) p = (p * v[i]) % MOD;
        dp[ms] = f[p];
    }
    for(int i = 0; i < n; i++) {
        for(int ms = 0; ms < (1 << n); ms++) {
            if((ms & (1 << i)) == 0) dp[ms] += dp[ms ^ (1 << i)];
        }
    }
    while(q--) {
        int s;
        cin >> s;
        set<int> st;
        for(int i = 0; i < s; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        int ms = 0;
        for(int i = 0; i < n; i++)
            if(st.count(v[i])) ms |= (1 << i);
        
        cout << dp[ms] << '\n';
    }
}