#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,fma")
using namespace std;
typedef long long ll;

const int MAXN = 2220002;
int prime[MAXN], phi[MAXN];
ll res[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(prime[p]) continue;
        for(int q = p; q < MAXN; q += p)
            prime[q] = p;
    }
}

void cphi(int n) {
    int nn = n, m = n;
    while(n > 1) {
        int p = prime[n];
        m /= p;
        m *= (p - 1);
        while(n % p == 0)
            n /= p;
    }
    phi[nn] = m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int n;
    cin >> n;
    vector<int> divs;
    for(int d = 1; d * d <= n; d++) {
        if(n % d) continue;
        divs.push_back(d);
        cphi(d);
        if(n/d > d) {
            divs.push_back(n/d);
            cphi(n / d);
        }
    }
    for(auto d : divs) {
        ll p = phi[n/d];
        for(int k = 0; k < n; k += d)
            res[k] += p * d;
    }
    for(int k = 0; k < n; k++)
        cout << res[k] << '\n';
}