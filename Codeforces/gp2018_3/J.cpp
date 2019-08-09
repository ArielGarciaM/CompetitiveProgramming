#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

double INF = 1e9;
const int MAXN = 105;

double cost[MAXN][MAXN], dp[MAXN][1 << 9];
ii points[MAXN];

string bin(int n) {
    string res;
    while(n > 0) {
        res += ('0' + n % 2);
        n >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < MAXN; i++) {
        fill(cost[i], cost[i] + MAXN, INF);
        fill(dp[i], dp[i] + (1 << 9), INF);
        cost[i][i] = 0;
        dp[i][0] = 0;
    }

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        if(i < k)
            dp[i][1 << i] = 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            cost[i][j] = cost[j][i] = hypot(points[i].first - points[j].first, points[i].second - points[j].second);

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    for(int mask = 0; mask < (1 << k); mask++) {
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                for(int sm = mask;;sm = ((sm - 1) & mask)) {
                    dp[i][mask] = min(dp[i][mask], dp[i][sm] + dp[i][mask - sm]);
                    if(sm == 0)
                        break;
                }
            }
            for(int j = k; j < n; j++)
                dp[j][mask] = min(dp[j][mask], dp[i][mask] + cost[i][j]);
        }
    }

    double ans = INF;
    for(int i = k; i < n; i++)
        ans = min(ans, dp[i][(1 << k) - 1]);
    cout << fixed << setprecision(5) << ans << '\n';
}