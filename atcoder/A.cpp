#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int dp[MAXN], h[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        if(i > 2)
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n] << endl;
}