#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 1e5 + 5;
int n, k, pt = 1, treesz[MAXN], comp[MAXN], dfso[MAXN], pos[MAXN];
gp_hash_table<int, int> dsu[MAXN];
pair<int, int> edge[MAXN];
vector<int> adj[MAXN], st[MAXN];

int find(int v, int u) {
    return ((dsu[v][u] > 0) ? dsu[v][u] = find(v, dsu[v][u]) : u);
}

void join(int v, int a, int b) {
    a = find(v, a), b = find(v, b);
    if(a != b) {
        comp[v]--;
        dsu[v][a] = b;
    }
}

void pre(int s) {
    treesz[s] = 1;
    pos[s] = pt;
    dfso[pt++] = s;
    for(auto v : adj[s]) {
        pre(v);
        treesz[s] += treesz[v];
    }
}

void dfs(int s) {
    int mx = -1, mxv = -1;
    for(auto v : adj[s]) {
        dfs(v);
        if(treesz[v] > mx) {
            mx = treesz[v];
            mxv = v;
        }
    }
    if(mxv != -1)
        swap(dsu[s], dsu[mxv]), comp[s] = comp[mxv];
    else
        comp[s] = k;
    join(s, edge[s].first, edge[s].second);
    for(auto v : adj[s]) {
        dsu[v].clear();
        if(v == mxv)
            continue;
        for(int w = pos[v]; w < pos[v] + treesz[v]; w++) {
            auto e = edge[dfso[w]];
            if(e.first != 0)
                join(s, e.first, e.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        edge[i] = {x, y};
    }
    pre(1);
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << comp[i] << '\n';
}