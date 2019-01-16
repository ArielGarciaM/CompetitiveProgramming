#include <bits/stdc++.h>
using namespace std;

const int MAXL = 3e3 + 5;
int dp[MAXL][MAXL];
pair<int, int> pre[MAXL][MAXL];

int main() {
    string s, t;
    cin >> s >> t;
    for(int i = 1; i <= s.length(); i++) {
        for(int j = 1; j <= t.length(); j++) {
            if(dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                pre[i][j] = {i - 1, j};
            }
            if(dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                pre[i][j] = {i, j - 1};
            }
            if(s[i - 1] == t[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                pre[i][j] = {i - 1, j - 1};
            }
        }
    }
    string ans = "";
    int i = s.length(), j = t.length();
    while(i > 0 && j > 0) {
        pair<int, int> p = pre[i][j];
        if(dp[i][j] > dp[p.first][p.second])
            ans += s[i - 1];
        i = p.first, j = p.second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}