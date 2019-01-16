#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
int L[MAXN], R[MAXN], K[MAXN];
ll M[MAXN][2][2];

ll tot(int v);

inline ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

inline ll add(ll a, ll b) {
    return (a + b) % MOD;
}

inline ll sub(ll a, ll b) {
    ll r = (a - b) % MOD;
    return (r + MOD) % MOD;
}

ll dp(int v, int o, int r) {
    if(v == 0)
        return (o == r ? 1 : 0);
    if(M[v][o][r] != -1)
        return M[v][o][r];
    if(K[v] == 0) {
        if(r == 1)
            return M[v][o][r] = 0;
        if(o == 0)
            return M[v][o][r] = mult(add(dp(L[v], 1, 0), dp(L[v], 1, 1)), add(dp(R[v], 1, 0), dp(R[v], 1, 1)));
        return M[v][o][r] = sub(mult(tot(L[v]), tot(R[v])), dp(v, 0, 0));
    }
    if(K[v] == 1) {
        if(r == 0)
            return M[v][o][r] = 0;
        if(o == 0)
            return M[v][o][r] = mult(add(dp(L[v], 1, 0), dp(L[v], 1, 1)), add(dp(R[v], 1, 0), dp(R[v], 1, 1)));
        return M[v][o][r] = sub(mult(tot(L[v]), tot(R[v])), dp(v, 0, 1));
    }
    if(o == 0 && r == 0)
        return M[v][o][r] = mult(dp(L[v], 1, 1), dp(R[v], 1, 1));
    if(o == 0)
        return M[v][o][r] = sub(mult(add(dp(L[v], 1, 0), dp(L[v], 1, 1)),  add(dp(R[v], 1, 0), dp(R[v], 1, 1))), dp(v, 0, 0));
    if(r == 0)
        return M[v][o][r] = sub(mult(add(dp(L[v], 0, 1), dp(L[v], 1, 1)),  add(dp(R[v], 0, 1), dp(R[v], 1, 1))), dp(v, 0, 0));
    return M[v][o][r] = sub(mult(tot(L[v]), tot(R[v])), add(dp(v, 0, 0), add(dp(v, 1, 0), dp(v, 0, 1))));
}

ll tot(int v) {
    return (dp(v, 0, 0) + dp(v, 0, 1) + dp(v, 1, 0) + dp(v, 1, 1)) % MOD;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> L[i] >> R[i] >> K[i];
    memset(M, -1, sizeof M);
    cout << (dp(1, 0, 1) + dp(1, 1, 0)) % MOD << endl;
}