#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int dp[MAXN], mx[MAXN], d[MAXN], x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 1; i <= m; i++)
        cin >> x[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mx[j] = mx[j - 1];
            if(d[i] > x[j]) mx[j] = max(mx[j], dp[j]);
        }
        for(int j = m; j >= 1; j--)
            if(d[i] == x[j]) dp[j] = mx[j] + 1;
        //for(int j = 1; j <= m; j++)
        //    cout << "dp(" << i << ", " << j << ") = " << dp[j] << endl;
    }
    int ans = 0;
    for(int j = 1; j <= m; j++)
        ans = max(ans, 2*dp[j]);
    cout << ans << '\n';
}