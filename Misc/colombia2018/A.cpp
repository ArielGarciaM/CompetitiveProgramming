#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;

ll MOD = 1e9 + 7;

mat mult(mat A, mat B) {
    mat X(4, vector<ll>(4));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++)
                X[i][j] = (X[i][j] + A[i][k] * B[k][j]) % MOD;
        }
    }
    return X;
}

mat id = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
mat M = {{16, 9, 4, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};

mat mexp(mat A, ll e) {
    if(e == 0)
        return id;
    if(e == 1)
        return A;
    if(e % 2)
        return mult(A, mexp(A, e - 1));
    mat p = mexp(A, e / 2);
    return mult(p, p);
}

int main() {
    ll n;
    cin >> n;
    ll m = 10ll*(n / 10ll), ans = 0;
    while(m + 45ll > n && m >= 0) {
        mat A = mexp(M, m/10ll);
        ans = (ans + A[0][0]) % MOD;
        m -= 10ll;
    }
    cout << ans << endl;
}