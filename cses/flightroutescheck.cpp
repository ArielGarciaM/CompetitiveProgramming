#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int tin[MAXN], low[MAXN], comp[MAXN], cur, ncomps, fi = -1;
vector<int> adj[MAXN], vis;

void dfs(int s) {
    low[s] = tin[s] = ++cur;
    vis.push_back(s);
    for(auto v : adj[s]) {
        if(!tin[v]) {
            dfs(v);
            low[s] = min(low[s], low[v]);
        }
        else if(!comp[v])
            low[s] = min(low[s], tin[v]);
    }
    if(low[s] == tin[s]) {
        ncomps++;
        int z = -1;
        do {
            z = vis.back();
            comp[z] = ncomps;
            vis.pop_back();
        } while(z != s);
        if(fi == -1)
        	fi = s;
        else {
        	cout << "NO\n";
        	cout << fi << " " << s << '\n';
        	exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int u = 1; u <= n; u++)
        if(!comp[u]) dfs(u);

    cout << "YES\n";
}