#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll dp[MAXN][2];
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    dp[s][1] = dp[s][0] = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        dp[s][0] = (dp[s][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[s][1] = (dp[s][1] * dp[v][0]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}