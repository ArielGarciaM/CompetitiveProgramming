#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int dp[MAXN], h[MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        dp[i] = 2e9;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j >= max(1, i - k); j--)
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
    cout << dp[n] << endl;
}