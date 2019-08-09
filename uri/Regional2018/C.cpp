#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
pair<double, int> dp[MAXN][6];
int dur[MAXN], cost[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> dur[i] >> cost[i];
    for(int k = 0; k < 6; k++)
        dp[0][k] = {0, 120};
    for(int i = 1; i <= n; i++) {
        double mn = 1e9;
        for(int k = 0; k < 6; k++)
            mn = min(mn, dp[i - 1][k].first);
        dp[i][0] = {mn + cost[i], dur[i]};
        for(int k = 1; k <= 5; k++) {
            int d = dp[i - 1][k - 1].second;
            if(d < 120)
                dp[i][k] = {dp[i - 1][k - 1].first + (k == 1 ? 0.5 : 0.25) * (double)cost[i], d + dur[i]};
            else
                dp[i][k] = {1e9, 0};
        }
        //for(int k = 0; k < 6; k++)
        //    cout << "dp(" << i << ", " << k << ") = " << "(" << dp[i][k].first << ", " << dp[i][k].second << ")" << endl;
    }
    double mn = 1e9;
    for(int k = 0; k < 6; k++)
        mn = min(dp[n][k].first, mn);
    cout << fixed << setprecision(2) << mn << '\n';
}