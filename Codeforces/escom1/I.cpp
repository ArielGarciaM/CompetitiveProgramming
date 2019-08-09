#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll p, om, m, g, K;
vector<ll> v;

ll mpow(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2) return (b * mpow(b, e - 1))%p;
    ll x = mpow(b, e/2);
    return (x * x)%p;
}

vector<ll> dft(vector<ll> P) {
    int n = P.size(), logn = __builtin_ctz(n);
    vector<ll> f(n), root(n);
    vector<int> rev(n);
    for(int i = 1; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (logn - 1));
    for(int i = 0; i < n; i++) {
        f[i] = P[rev[i]];
        root[i] = (i ? (om * root[i - 1])%p : 1);
    }
    for(int k = 1; k < n; k *= 2) {
        for(int i = 0; i < n; i += 2*k) {
            for(int j = 0; j < k; j++) {
                ll z;
                if(j == 0) z = f[i + j + k]; 
                else z = (root[n - j*(n/(2*k))] * f[i + j + k])%p;
                f[i + j + k] = (f[i + j] - z)%p;
                f[i + j] = (f[i + j] + z)%p;
            }
        }
    }
    return f;
}

int main() {
    cin >> p;
    int d = p - 1;
    vector<int> ords;
    for(int q = 2; q <= d; q++) {
        if(d % q) continue;
        ords.push_back((p - 1)/q);
        while(d % q == 0) d /= q;
    }
    while(true) {
        g++;
        bool bad = false;
        for(auto ep : ords) {
            if(mpow(g, ep) == 1) {
                bad = true;
                break;
            }
        }
        if(bad) continue;
        break;
    }
    cout << g << endl;
    /*ll lol = m/4, pro = mpow(n, 2LL*lol);
    m %= 4;
    for(int i = 0; i < n; i++)
        v[i] = (v[i] * pro)%p;
    if(m >= 2LL) {
        vector<ll> w(n);
        for(int i = 0; i < n; i++)
            w[i] = (n * v[i])%p;
        v[0] = w[0];
        for(int i = 1; i < n; i++)
            v[i] = w[n - i];
        m -= 2;
    }
    if(m) {
        //reverse(v.begin(), v.end());
        while(__builtin_popcount(v.size()) > 1)
            v.push_back(0);
        vector<ll> f = dft(v);
        for(auto x : f)
            cout << x << " ";
        cout << '\n';
    }
    for(auto x : v)
        cout << x << " ";*/
}

/*
6 61 1
24 17 39 52 25 7

*/