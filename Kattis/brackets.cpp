#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 2e18;
ll dp[1005][1005];

int main() {
    ll n, m;
    cin >> n >> m;
    n /= 2;
    dp[n][n] = 1;
    for(int y = n - 1; y >= 0; y--) {
        for(int x = n; x >= y; x--) {
            dp[x][y] = min(dp[x + 1][y] + dp[x][y + 1], INF);
        }
    }
    string ans = "";
    int x = 0, y = 0;
    while(x < n || y < n) {
        if(dp[x + 1][y] >= m) {
            x++;
            ans += '(';
        }
        else {
            m -= dp[x + 1][y];
            y++;
            ans += ')';
        }
    }
    cout << ans << endl;
}