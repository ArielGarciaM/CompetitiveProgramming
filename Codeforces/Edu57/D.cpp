#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll vals[MAXN], ans, dp[MAXN][4];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        cin >> vals[i];
        dp[i][0] = dp[i - 1][0] + (s[i - 1] == 'h' ? vals[i] : 0);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + (s[i - 1] == 'a' ? vals[i] : 0));
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2] + (s[i - 1] == 'r' ? vals[i] : 0));
        dp[i][3] = min(dp[i - 1][2], dp[i - 1][3] + (s[i - 1] == 'd' ? vals[i] : 0));
    }
    cout << dp[n][3] << endl;
}