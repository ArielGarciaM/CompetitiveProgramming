#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXL = 20;
int f[MAXL][MAXN]; // f[i][v] is 2^i-th successor of v.
int ept[MAXN]; // Entry point into eventual cycle.
int cyc[MAXN]; // Cycles only, identifier of cycle.
int dis[MAXN]; // For chains, distance to cycle. For cycles, position in cycle.
int pre[MAXN]; // Prev node for traversal.
int siz[MAXN]; // For cycle identifiers, size of cycle.
int n;

void trav(int v) {

    while(!ept[f[0][v]]) {
        pre[f[0][v]] = v;
        ept[v] = v;
        v = f[0][v];
    }
    ept[v] = v;
    if(cyc[f[0][v]] || ept[f[0][v]] != f[0][v]) {
        // Merge into chain
        pre[f[0][v]] = v;
        v = f[0][v];
        int e = ept[v], di = (ept[v] == v ? 1 : dis[v] + 1);
        while(pre[v]) {
            v = pre[v];
            ept[v] = e;
            dis[v] = di++;
        }
    }
    else {
        // Merge into cycle
        int c = f[0][v], pos = 1;
        while(v != c) {
            dis[v] = pos++;
            cyc[v] = c;
            v = pre[v];
        }
        dis[v] = pos;
        siz[v] = pos;
        cyc[v] = c;
        int di = 1;
        while(pre[v]) {
            if(cyc[pre[v]])
                break;
            v = pre[v];
            ept[v] = c;
            dis[v] = di++;
        }
    }
}

int lca(int u, int v) {
    if(cyc[u])
        return u;
    if(cyc[v])
        return v;
    if(dis[u] > dis[v])
        swap(u, v);
    int d = dis[v] - dis[u];
    for(int l = MAXL -1; l >= 0; l--) {
        if(d >= (1 << l)) {
            d -= 1 << l;
            v = f[l][v];
        }
    }
    if(u == v)
        return u;
    for(int l = MAXL - 1; l >= 0; l--) {
        if(f[l][u] != f[l][v]) {
            u = f[l][u];
            v = f[l][v];
        }
    }
    return f[0][u];
}

void query(int u, int v) {
    if(ept[u] != ept[v]) {
        if(cyc[ept[u]] != cyc[ept[v]]) {
            cout << -1 << endl;
            return;
        }
        int x = 0;
        if(!cyc[u])
            x += dis[u];
        if(!cyc[v])
            x += dis[v];
        int d = abs(dis[ept[u]] - dis[ept[v]]);
        cout << x + min(d, siz[cyc[ept[u]]] - d) << endl;
        return;
    }
    int l = lca(u, v);
    if(l == ept[u]) {
        int x = 0;
        if(!cyc[u])
            x += dis[u];
        if(!cyc[v])
            x += dis[v];
        cout << x << endl;
        return;
    }
    cout << dis[u] + dis[v] - 2*dis[l] << endl;
}

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    while(cin >> n) {
        for(int i = 1; i <= n; i++)
            cin >> f[0][i];

        for(int l = 1; l < MAXL; l++) {
            for(int i = 1; i <= n; i++)
                f[l][i] = f[l - 1][f[l - 1][i]];
        }

        for(int i = 0; i <= n; i++)
            ept[i] = cyc[i] = dis[i] = pre[i] = siz[i] = 0;

        for(int i = 1; i <= n; i++) {
            if(!ept[i])
                trav(i);

            /*for(int v = 1; v <= n; v++)
                cout << v << " " << ept[v] << " " << dis[v] << " " << cyc[v] << " " << siz[v] << endl;*/
        }

        int q;
        cin >> q;
        while(q--) {
            int u, v;
            cin >> u >> v;
            query(u, v);
        }
    }
}