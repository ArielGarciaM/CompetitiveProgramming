#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans, prv;

int dfs(int s) {
    if(s == 1)
        ans[s] = 1;
    else
        ans[s] = 0;
    for(auto v : adj[s]) {
        if(ans[v] == -1)
            dfs(v);
        if(ans[v] && ans[s] < 1 + ans[v]) {
            ans[s] = 1 + ans[v];
            prv[s] = v;
        }
    }
    return ans[s];
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1), ans.resize(n + 1, -1), prv.resize(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    int ans = dfs(n);
    if(ans == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans << '\n';
    vector<int> route;
    int v = n;
    while(prv[v]) {
        route.push_back(v);
        v = prv[v];
    }
    route.push_back(v);
    reverse(route.begin(), route.end());
    for(auto v : route)
        cout << v << " ";
    cout << '\n';
}