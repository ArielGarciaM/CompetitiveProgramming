#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int MAXN = 6005;
ll val[MAXN], pf[MAXN], res[MAXN], cost[MAXN][MAXN], start[MAXN], dp[MAXN][MAXN], B, C;

void solve(int k, int L, int R, int optL, int optR) {
    if(L > R || optL > optR) return;
    int x = (L + R)/2, opt;
    ll ans = INF;
    for(int m = optR; m >= max(x + 1, optL); m--) {
        //cout << k << " " << x << " " << m << " " << cost[x][m] + dp[k - 1][m];
        ll possible = cost[x][m] + dp[k - 1][m];
        if(possible < ans) {
            ans = possible;
            opt = m;
        }
    }
    dp[k][x] = ans;
    solve(k, L, x - 1, optL, opt);
    solve(k, x + 1, R, opt, optR);
}

int main() {
    int n;
    cin >> n >> B >> C;
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        pf[i] = pf[i - 1] + val[i];
    }
    for(int L = 1; L <= n; L++) {
        for(int R = L + 1; R <= n; R++) {
            if(R == L + 1) {
                cost[L][R] = 0;
                continue;
            }
            int m = (L + R + 1)/2;
            cost[L][R] = cost[L][R - 1] + C*(pf[R - 1] - pf[m - 1]);
        }
    }
    //for(int L = 1; L <= n; L++)
    //    for(int R = L + 1; R <= n; R++)
    //        cout << "cost(" << L << ", " << R << ") = " << cost[L][R] << endl;
    for(int i = 2; i <= n; i++)
        start[i] = start[i - 1] + C*(val[i - 1] + pf[i - 2]);
    //for(int i = 1; i <= n; i++)
    //    cout << start[i] << " ";
    //cout << endl;
    dp[1][n + 1] = INF;
    dp[1][n] = 0;
    for(int i = n - 1; i >= 1; i--)
        dp[1][i] = dp[1][i + 1] + C*(pf[n] - pf[i]);
    for(int i = 2; i <= n; i++)
        solve(i, 1, n - i + 1, 1, n);
    for(int i = 1; i <= n; i++) {
        res[i] = INF;
        for(int l = 1; l <= n - i + 1; l++) {
            dp[i][l] += start[l];
            res[i] = min(res[i], dp[i][l]);
            //cout << "dp(" << i << ", " << l << ") = " << dp[i][l] << endl;
        }
    }
    for(ll i = 1; i <= n; i++)
        cout << res[i] + B * i << " ";
    cout << endl;
}