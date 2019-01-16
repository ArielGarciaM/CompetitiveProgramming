#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 102;
const int MAXV = 1e5 + 2;
const ll INF = 1e18;
ll dp[MAXN][MAXV], val[MAXN], wt[MAXN];

int main() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXV; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    int n;
    ll w;
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];
    for(int i = 1; i <= n; i++) {
        for(int v = 0; v < MAXV; v++) {
            dp[i][v] = dp[i - 1][v];
            if(v - val[i] >= 0)
                dp[i][v] = min(dp[i][v], dp[i - 1][v - val[i]] + wt[i]);
        }
    }
    for(int v = MAXV - 1; v >= 0; v--) {
        if(dp[n][v] <= w) {
            cout << v << endl;
            return 0;
        }
    }
}