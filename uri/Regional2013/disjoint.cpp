#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int memo[MAXN][MAXN];
vector<int> adj[MAXN];

int dp(int u, int v) {
    if(u == v) {
        if(u == 1)
            return 1;
        else
            return 0;
    }
    if(memo[u][v] != -1)
        return memo[u][v];
    if(u < v)
        return memo[u][v] = dp(v, u);
    for(auto w : adj[u]) {
        if(dp(w, v) == 1)
            return memo[u][v] = 1;
    }
    return memo[u][v] = 0;
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
        }
        memset(memo, -1, sizeof memo);
        int ans = 0;
        for(int u = 1; u <= n; u++) {
            for(int v = u + 1; v <= n; v++) {
                ans += dp(u, v);
                //if(dp(u, v) == 0)
                //    cout << u << " " << v << endl;
            }
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i++)
            adj[i].clear();
    }
}