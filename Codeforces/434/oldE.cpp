#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 5e5 + 5;
const int MAGIC = 6000;
const int LOG = 20;
int tourtin[MAXN], tin[MAXN], tout[MAXN], h[MAXN], p[MAXN], root, Time, tourtime, n;
int kval[MAXN], kpfx[MAXN];
ll sval[MAXN], spfx[MAXN];
ii tour[2*MAXN], tab[LOG][2*MAXN];
vector<int> adj[MAXN], byht[MAXN];
ll ans[MAXN];

void dfs(int s) {
    h[s] = p[s] ? h[p[s]] + 1 : 0;
    byht[h[s]].push_back(s);
    tin[s] = ++Time;
    tourtin[s] += ++tourtime;
    tour[tourtime] = {h[s], s};
    for(auto v : adj[s]) {
        dfs(v);
        tour[++tourtime] = {h[s], s};
    }
    tout[s] = Time;
}

void buildRMQ() {
    for(int i = 1; i <= 2*n - 1; i++)
        tab[0][i] = tour[i];
    for(int l = 0; l < LOG - 1; l++) {
        for(int i = 1; i + (1 << l) <= 2*n - 1; i++)
            tab[l + 1][i] = min(tab[l][i], tab[l][i + (1 << l)]);
    }
}

int LCA(int u, int v) {
    int l = tourtin[u], r = tourtin[v];
    if(l > r) swap(l, r);
    int d = 31 - __builtin_clz(r - l + 1);
    ii res = min(tab[d][l], tab[d][r - (1 << d) + 1]);
    return res.second;
}

void solveA(int ht) {
    for(int i = 0; i < byht[ht].size(); i++) {
        int u = byht[ht][i];
        if(p[u]) ans[u] += ans[p[u]] + h[u];
        for(int j = i + 1; j < byht[ht].size(); j++) {
            int v = byht[ht][j];
            int z = LCA(u, v);
            ans[u] += h[z] + 1;
            ans[v] += h[z] + 1;
        }
    }
}

inline void solve(int s) {
    int amt = kpfx[tout[s]] - kpfx[tin[s] - 1];
    sval[tin[s]] += amt;
    sval[tout[s] + 1] -= amt;
}

void solveB(int ht) {
    memset(sval, 0, sizeof sval);
    for(int i = 1; i <= n; i++)
        kpfx[i] = kpfx[i - 1] + kval[i];
    for(int i = 0; i < ht; i++)
        for(auto v : byht[i]) solve(v);
    for(int i = 1; i <= n; i++)
        spfx[i] = spfx[i - 1] + sval[i];
    for(auto u : byht[ht])
        ans[u] = spfx[tin[u]] - ht;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(p[i] == 0)
            root = i;
        else
            adj[p[i]].push_back(i);
    }
    dfs(root);
    buildRMQ();
    for(int ht = 0;;ht++) {
        if(byht[ht].empty()) break;
        for(auto v : byht[ht])
            kval[tin[v]]++;
        if(byht[ht].size() < MAGIC)
            solveA(ht);
        else
            solveB(ht);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}