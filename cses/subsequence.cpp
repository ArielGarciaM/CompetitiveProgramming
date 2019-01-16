#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int dp[MAXN][4], nxt[MAXN][4];

int main() {
    string s, lett = "ACGT";
    cin >> s;
    int n = s.size();
    dp[n][0] = dp[n][1] = dp[n][2] = dp[n][3] = 1;
    nxt[n][0] = nxt[n][1] = nxt[n][2] = nxt[n][3] = -1;
    for(int pos = n - 1; pos >= 0; pos--) {
        for(int t = 0; t < 4; t++) {
            if(s[pos] != lett[t]) {
                dp[pos][t] = dp[pos + 1][t];
                nxt[pos][t] = t;
            }
            else {
                int mn = 1000000000, pmn = -1;
                for(int j = 0; j < 4; j++) {
                    if(dp[pos + 1][j] < mn) {
                        mn = dp[pos + 1][j];
                        pmn = j;
                    }
                }
                dp[pos][t] = 1 + mn;
                nxt[pos][t] = pmn;
            }
        }
    }
    string ans = "";
    int mn = 1000000000, pmn = -1;
    for(int j = 0; j < 4; j++) {
        if(dp[0][j] < mn) {
            mn = dp[0][j];
            pmn = j;
        }
    }
    //cout << mn << endl;
    ans += lett[pmn];
    for(int pos = 0; pos < n; pos++) {
        if(dp[pos + 1][nxt[pos][pmn]] < dp[pos][pmn])
            ans += lett[nxt[pos][pmn]];
        pmn = nxt[pos][pmn];
    }
    cout << ans << endl;
}