#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<ll> ans;

ll dfs(int s) {
    if(s == 1)
        ans[s] = 1;
    else
        ans[s] = 0;
    for(auto v : adj[s]) {
        if(ans[v] == -1)
            dfs(v);
        if(ans[v]) {
            ans[s] += ans[v];
            if(ans[s] >= MOD)
                ans[s] -= MOD;
        }
    }
    return ans[s];
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1), ans.resize(n + 1, -1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    cout << dfs(n) << '\n';
}