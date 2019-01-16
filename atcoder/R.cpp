#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct matrix {
    int n;
    vector<vector<ll>> M;

    matrix(vector<vector<ll>> &entries) {
        M = entries;
        n = entries[0].size();
    }

    matrix operator*(const matrix &o) {
        vector<vector<ll>> ans(n, vector<ll>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ll entry = 0;
                for(int k = 0; k < n; k++) {
                    entry = (entry + M[i][k] * o.M[k][j]) % MOD;
                }
                ans[i][j] = entry;
            }
        }
        return matrix(ans);
    }
};

matrix mexp(matrix M, ll k) {
    if(k == 1)
        return M;
    if(k % 2)
        return M * mexp(M, k - 1);
    matrix X = mexp(M, k/2);
    return X * X;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<ll>> adj(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    matrix adjm = matrix(adj);
    adjm = mexp(adjm, k);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = (ans + adjm.M[i][j]) % MOD;
        }
    }
    cout << ans << endl;
}