#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;
double dp[MAXN][MAXN], p[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++) {
        for(int h = 0; h <= n; h++) {
            dp[i][h] = (1.0 - p[i])*dp[i - 1][h];
            if(h > 0)
                dp[i][h] += p[i]*dp[i - 1][h - 1];
        }
    }
    double ans = 0;
    for(int i = n/2 + 1; i <= n; i++)
        ans += dp[n][i];
    cout << fixed << setprecision(20) << ans << endl;
}