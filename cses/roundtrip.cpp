#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN], route;
int vis[MAXN];

void dfs(int s, int p = 0) {
    vis[s] = 1;
    route.push_back(s);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        if(vis[v]) {
            vector<int> ans;
            bool out = false;
            ans.push_back(s);
            for(auto x : route) {
                if(x == v)
                    out = true;
                if(out)
                    ans.push_back(x);
                if(x == s)
                    break;
            }
            cout << ans.size() << '\n';
            for(auto x : ans)
                cout << x << " ";
            cout << '\n';
            exit(0);
        }
        else
            dfs(v, s);
    }
    route.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            route.clear();
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE\n";
}