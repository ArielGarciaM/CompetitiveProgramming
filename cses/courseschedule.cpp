#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int vis[MAXN], fin[MAXN];
vector<int> ts, adj[MAXN];
bool bad = false;

void dfs(int s) {
    vis[s] = 1;
    for(auto v : adj[s]) {
        if(vis[v]) {
            if(!fin[v])
                bad = true;
        }
        else
            dfs(v);
    }
    fin[s] = 1;
    ts.push_back(s);
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int v = 1; v <= n; v++)
        if(!vis[v]) dfs(v);
    if(bad) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(ts.begin(), ts.end());
    for(auto v : ts)
        cout << v << " ";
    cout << '\n';
}