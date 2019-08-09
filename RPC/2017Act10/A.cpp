#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int prcnt[MAXN][26], sfcnt[MAXN][26], dp[MAXN];
vector<int> adj[MAXN];

int dfs(int s) {
    if(dp[s] != -1)
        return dp[s];
    dp[s] = 0;
    for(auto v : adj[s])
        dp[s] = max(dp[s], 1 + dfs(v));
    return dp[s];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(prcnt, 0, sizeof prcnt);
        memset(sfcnt, 0, sizeof sfcnt);
        for(int i = 0; i < MAXN; i++)
            adj[i].clear();
        int n, k;
        cin >> n >> k;
        for(int i = 0; i <= n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < k; j++)
                prcnt[i][s[j] - 'A']++;
            for(int j = s.length() - k; j < s.length(); j++)
                sfcnt[i][s[j] - 'A']++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                bool b = true;
                for(int c = 0; c < 26; c++) {
                    if(sfcnt[i][c] != prcnt[j][c]) {
                        b = false;
                        break;
                    }
                }
                if(!b)
                    continue;
                adj[i].push_back(j);
            }
        }
        memset(dp, -1, sizeof dp);
        cout << dfs(0) << '\n';
    }
}