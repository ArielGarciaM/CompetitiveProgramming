#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int parent[MAXN][20], h[MAXN], n;
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    parent[s][0] = (p == 0 ? s : p);
    h[s] = (p == 0 ? 0 : h[p] + 1);
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
}

void buildLCA() {
    dfs(1);
    for(int l = 1; l < 20; l++)
        for(int v = 1; v <= n; v++)
            parent[v][l] = parent[parent[v][l - 1]][l - 1];
}

int LCA(int u, int v) {
    if(h[v] > h[u])
        swap(u, v);
    int diff = h[u] - h[v];
    for(int lv = 19; lv >= 0; lv--) {
        if(diff >= (1 << lv)) {
            u = parent[u][lv];
            diff -= (1 << lv);
        }
    }
    if(u == v)
        return u;
    for(int l = 19; l >= 0; l--) {
        if(parent[u][l] != parent[v][l]) {
            u = parent[u][l];
            v = parent[v][l];
        }
    }
    return parent[u][0];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2*h[LCA(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildLCA();
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = (dist(a, b) + dist(c, d)) - min(dist(a, c) + dist(b, d), dist(a, d) + dist(b, c));
        if(x < 0)
            cout << "0\n";
        else
            cout << x/2 + 1 << '\n';
    }
}