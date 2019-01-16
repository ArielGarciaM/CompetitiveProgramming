#include <bits/stdc++.h>
using namespace std;

int dp[100002], h[1002], s[1002];

int main() {
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int pos = 0; pos < n; pos++) {
        for(int wt = x; wt >= 0; wt--) {
            if(wt - h[pos] >= 0)
                dp[wt] = max(dp[wt], s[pos] + dp[wt - h[pos]]);
        }
    }
    int ans = 0;
    for(int w = 0; w <= x; w++)
        ans = max(ans, dp[w]);
    cout << ans << endl;
}