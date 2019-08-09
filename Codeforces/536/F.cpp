#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;
const ll MOD = 998244353;
const ll EMOD = MOD - 1;

mat mult(mat A, mat B) {
    int n = A[0].size();
    mat C(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % EMOD;
            }
        }
    }
    return C;
}

mat mexp(mat A, ll n) {
    if(n == 1)
        return A;
    if(n % 2) {
        mat B = mexp(A, n - 1);
        return mult(A, B);
    }
    mat B = mexp(A, n/2);
    int m = B[0].size();
    return mult(B, B);
}

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

ll p3[100001];
set<ll> pows;

int main() {
    int k;
    ll n, m;
    cin >> k;
    mat A(k, vector<ll>(k));
    for(int i = 1; i < k; i++)
        A[i][i - 1] = 1;
    for(int i = 0; i < k; i++)
        cin >> A[0][i];
    cin >> n >> m;
    mat M = mexp(A, n - k);
    ll e = M[0][0];
    cout << __gcd(EMOD, e) << endl;
    p3[0] = 1;
    pows.insert(1);
    for(int i = 1; i < 100001; i++) {
        p3[i] = (p3[i - 1] * 3ll)%MOD;
        pows.insert(p3[i]);
    }
    ll z = 100000;
    ll t = inv(mpow(3ll, z));
    ll ord = 0;
    for(ll i = 0; i < 100000; i++) {
        ll y = (m*mpow(t, i))%MOD;
        if(!pows.count(y))
            continue;
        for(ll j = 0; j < 100001; j++) {
            if(y == p3[j]) {
                ord = (z*i + j)%EMOD;
                break;
            }
        }
    }
    cout << __gcd(ord, EMOD) << endl;
}