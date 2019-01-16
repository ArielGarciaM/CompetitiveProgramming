#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXW = 1e5 + 5;
ll dp[MAXW], w[105], v[105];

int main() {
    int n, W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(int i = 1; i <= n; i++) {
        for(int we = W; we >= 0; we--) {
            if(we - w[i] < 0)
                break;
            dp[we] = max(dp[we], dp[we - w[i]] + v[i]);
        }
    }
    ll mx = 0;
    for(int i = 0; i <= W; i++)
        mx = max(mx, dp[i]);
    cout << mx << endl;
}