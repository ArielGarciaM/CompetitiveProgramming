#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 305;
const ll MOD = 1e9 + 7;

ll dp[MAXN][MAXN], pdp[MAXN][MAXN];

int main() {
    int r, q;
    cin >> r >> q;
    r--;
    q--;
    dp[0][0] = 1;
    for(int h = 0; h <= 299; h++) pdp[0][h] = 1;
    for(int v = 1; v <= 299; v++) {
        for(int h = 1; h <= v; h++) {
            for(int p = 0; p <= v - 1; p++) {
                dp[v][h] = (dp[v][h] + dp[p][h - 1]*pdp[v - 1 - p][h] + pdp[p][h - 1]*dp[v - 1 - p][h] - dp[p][h - 1]*dp[v - 1 - p][h])%MOD;
                if(dp[v][h] < 0) dp[v][h] += MOD;
            }
        }
        pdp[v][0] = 0;
        for(int h = 1; h <= 299; h++)
            pdp[v][h] = (pdp[v][h - 1] + dp[v][h])%MOD;
    }
    cout << dp[q][r] << '\n';
}