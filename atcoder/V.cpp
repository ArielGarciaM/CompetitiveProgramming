#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n;
ll M, g[MAXN], prod[MAXN], f[MAXN], pleft[MAXN], pright[MAXN];
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    int m = adj[s].size();
    if(s != 1)
        m--;
    g[s] = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        g[s] = (g[s] * (g[v] + 1)) % M;
    }
    pleft[0] = pright[m + 1] = 1ll;
    int ctl = 1, ctr = m;
    for(int i = 0; i < adj[s].size(); i++) {
        int v = adj[s][i];
        if(v == p)
            continue;
        pleft[ctl] = (pleft[ctl - 1] * (g[v] + 1)) % M;
        ctl++;
    }
    for(int i = adj[s].size() - 1; i >= 0; i--) {
        int v = adj[s][i];
        if(v == p)
            continue;
        pright[ctr] = (pright[ctr + 1] * (g[v] + 1)) % M;
        ctr--;
    }
    ctl = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        prod[v] = (pleft[ctl - 1] * pright[ctl + 1]) % M;
        ctl++;
    }
}

void calcf(int s, int p = 0) {
    if(s != 1)
        f[s] = (prod[s] * (f[p] + 1ll)) % M;
    //cout << s << " " << prod[s] << " " << f[p] << " " << f[s] << endl;
    for(auto v : adj[s]) {
        if(v != p)
            calcf(v, s);
    }
}

int main() {
    cin >> n >> M;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    f[1] = 0;
    calcf(1);
    for(int i = 1; i <= n; i++)
        cout << ((f[i] + 1ll) * g[i]) % M << endl;
}