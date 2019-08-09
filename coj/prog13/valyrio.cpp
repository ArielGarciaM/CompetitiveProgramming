#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[505][2];
bool valid = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        ll c, v, l, k, tot = 0;
        cin >> c >> v >> l >> k;
        dp[1][0] = v;
        dp[1][1] = c;
        tot = v;
        valid = false;
        if(dp[1][0] >= k)
            valid = true;
        for(int j = 2; j <= l; j++) {
            dp[j][0] = v*(dp[j - 1][0] + dp[j - 1][1]);
            dp[j][1] = c*(dp[j - 1][0]);
            if(dp[j][0] >= MOD) {
                dp[j][0] %= MOD;
                valid = true;
            }
            if(dp[j][1] >= MOD)
                dp[j][1] %= MOD;
        }
        if(dp[l][0] >= k)
            valid = true;
        cout << dp[l][0] << " ";
        if(valid)
            cout << "Accepted\n";
        else
            cout << "Rejected\n";
    }
}