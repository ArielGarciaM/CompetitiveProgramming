#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int bv, bh, par[MAXN], di[MAXN];
bool line;

void dfs(int s, int h = 0, int p = 0) {
    par[s] = p ?: s;
    if(h > bh) {
        bh = h;
        bv = s;
    }
    for(auto v : adj[s])
        if(v != p) dfs(v, h + 1, s);
}

int solve() {
    bv = bh = -1;
    dfs(1);
    int r = bv;
    bv = bh = -1;
    dfs(r);
    if(bh % 2)
        return -1;
    int d = bh/2;
    while(d--)
        bv = par[bv];
    return bv;
}

int main() {
    int n;
    cin >> n;
    line = true;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(adj[i].size() > 2) line = false;
    if(n <= 3) {
        cout << "1\n";
        return 0;
    }
    int res = solve();
    if(res != -1) {
        check(res);
    }
}