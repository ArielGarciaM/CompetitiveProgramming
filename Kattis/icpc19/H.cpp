#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int LOG = 20;
int n, k, f[MAXN][LOG], ans[MAXN], rev[MAXN], desc[MAXN], upk[MAXN], diff[MAXN];
vector<int> adj[MAXN], cadj[MAXN], comps[MAXN];
int comp[MAXN], h[MAXN], cyc[MAXN], csize;

void push(int d, int start) {
    int first = start, last = start + d;
    if(d >= csize) {
        diff[0]++;
        return;
    }
    first %= csize;
    last %= csize;
    if(first <= last) {
        diff[first]++;
        diff[last + 1]--;
    }
    else {
        diff[first]++;
        diff[0]++;
        diff[last + 1]--;
    }
}

void dfs(int s, int c) {
    comp[s] = c;
    comps[c].push_back(s);
    for(auto v : cadj[s]) {
        if(!comp[v])
            dfs(v, c);
    }
}

void calcup(int s, int root, int p = 0) {
    h[s] = (p ? h[p] + 1 : 0);
    if(h[s] && h[s] <= k) push(k - h[s], root);
    if(h[s] >= k)
        desc[upk[s]]++;
    for(auto v : adj[s]) {
        if(v == rev[s] || v == p)
            continue;
        calcup(v, root, s);
    }
}

void add(int s, int p = 0) {
    ans[s]++;
    for(auto v : adj[s]) {
        if(v == rev[s] || v == p)
            continue;
        add(v, s);
        ans[s] += ans[v];
        ans[s] -= desc[v];
    }
}

void solve(int com) {
    int u = comps[com][0], sz = comps[com].size();
    for(int i = 0; i < sz; i++) u = f[u][0];
    int v = u;
    csize = 0;
    do {
        rev[f[v][0]] = v;
        v = f[v][0];
        cyc[csize++] = v;
    } while(v != u);
    for(int i = 0; i < csize; i++)
        diff[i] = 0;
    for(int i = 0; i < csize; i++) {
        calcup(cyc[i], i);
        add(cyc[i]);
        ans[cyc[i]] = 0;
    }
    for(int i = 0; i < csize; i++)
        ans[cyc[i]] += min(csize, k + 1);
    int part = 0;
    for(int i = 0; i < csize; i++) {
        part += diff[i];
        ans[cyc[i]] += part;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> f[i][0];
        adj[f[i][0]].push_back(i);
        cadj[i].push_back(f[i][0]);
        cadj[f[i][0]].push_back(i);
    }
    for(int l = 1; l < LOG; l++) {
        for(int i = 1; i <= n; i++) {
            f[i][l] = f[f[i][l - 1]][l - 1];
        }
    }
    for(int i = 1; i <= n; i++) {
        upk[i] = i;
        for(int l = LOG - 1; l >= 0; l--) {
            if(k & (1 << l))
                upk[i] = f[upk[i]][l];
        }
    }
    int ncomps = 0;
    for(int i = 1; i <= n; i++) {
        if(!comp[i]) {
            dfs(i, ++ncomps);
        }
    }
    for(int i = 1; i <= ncomps; i++)
        solve(i);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}