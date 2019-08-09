#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAXN = 5e4;
int low[MAXN], ord[MAXN], ind[MAXN], sz[MAXN], n, m, e;
vector<int> adj[MAXN], dadj[MAXN], st;
int spy[MAXN], bad[MAXN], vis[MAXN], comp[MAXN];

vi val, sta;
int Time, ncomps;
template<class G> int dfs(int s, G &g) {
    int low = val[s] = ++Time, x; sta.push_back(s);
    for(auto v : g[s]) if(comp[v] < 0)
        low = min(low, val[v] ?: dfs(v, g));
    if(low == val[s]) {
        //cout << "comp: ";
        do {
            x = sta.back(); sta.pop_back();
            //cout << x << " ";
            comp[x] = ncomps;
            if(spy[x])
                bad[ncomps] = 1;
            if(!spy[x])
                sz[ncomps]++;
        } while(x != s);
        //cout << endl;
        ncomps++;
    }
    return val[s] = low;
}
/*int dfs(int s) {
    low[s] = ord[s] = ++tin;
    st.push_back(s);
    for(auto v : adj[s]) {
        if(!ord[v])
            low[s] = min(low[s], dfs(v));
        else if(ord[v] < ord[s] && comp[v] < 0)
            low[s] = min(low[s], ord[v]);
    }
    if(low[s] == ord[s]) {
        int x;
        do {
            x = st.back(); st.pop_back();
            comp[x] = ncomps;
            if(spy[x])
                bad[ncomps] = 1;
            if(!spy[x])
                sz[ncomps]++;
        } while(x != s);
        ncomps++;
    }
    return low[s];
}*/
template <class G>
void scc(G &g) {
    fill(comp, comp + n, -1);
    val.assign(n, 0);
    for(int i = 0; i < n; i++)
        if(comp[i] < 0) dfs(i, g);
}
void calc(int s) {
    vis[s] = 1;
    for(auto v : dadj[s]) {
        if(!vis[v]) calc(v);
        if(bad[v]) bad[s] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 0; i < e; i++) {
        int x;
        cin >> x;
        spy[x] = 1;
    }
    scc(adj);
    for(int i = 0; i < n; i++) {
        for(auto v : adj[i]) {
            if(comp[i] != comp[v])
                dadj[comp[i]].push_back(comp[v]);
        }
    }
    for(int i = 0; i < ncomps; i++)
        if(!vis[i]) calc(i);
    int ans = 0;
    for(int i = 0; i < ncomps; i++) {
        if(bad[i]) continue;
        for(auto v : dadj[i])
            ind[v]++;
    }
    for(int i = 0; i < ncomps; i++) {
        if(bad[i])
            ans += sz[i];
        else if(ind[i] == 0)
            ans++;
    }
    cout << ans << endl;
}