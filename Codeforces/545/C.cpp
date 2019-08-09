#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi val, comp, z;
int Time, ncomps;
template<class G> int dfs(int j, G& g) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for(auto e : g[j]) if(comp[e] < 0)
        low = min(low, val[e] ?: dfs(e, g));
    if(low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
        } while (x != j);
        ncomps++;
    }
    return val[j] = low;
}

template<class G> void scc(G& g) {
    int n = g.size();
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    for(int i = 0; i < n; i++)
        if(comp[i] < 0)
            dfs(i, g);
}

const int MAXN = 5e6 + 5;
vector<vi> adj, sadj;
int dp[MAXN], cnt[MAXN], ctr[MAXN];

void sdfs(int s) {
    dp[s] = cnt[s];
    ctr[s] = 1;
    for(auto v : sadj[s]) {
        if(!ctr[v])
            sdfs(v);
        dp[s] = max(dp[s], cnt[s] + dp[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, d, tot;
    cin >> n >> m >> d;
    tot = n*d;
    adj.assign(tot, vi());
    while(m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        for(int day = 0; day < d; day++) {
            int nd = day + 1;
            if(nd >= d)
                nd -= d;
            adj[n*day + u].push_back(n*nd + v);
        }
    }
    scc(adj);
    sadj.assign(ncomps, vi());

    for(int u = 0; u < tot; u++) {
        for(auto v : adj[u]) {
            if(comp[u] != comp[v] && !ctr[comp[v]])
                sadj[comp[u]].push_back(comp[v]);
            ctr[comp[v]]++;
        }
        for(auto v : adj[u])
            ctr[comp[v]]--;
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int day = 0; day < d; day++) {
            if(s[day] == '1') {
                if(ctr[comp[n*day + i]] == 0)
                    cnt[comp[n*day + i]]++;
                ctr[comp[n*day + i]]++;
            }
        }
        for(int day = 0; day < d; day++) {
            if(s[day] == '1')
                ctr[comp[n*day + i]]--;
        }
    }

    sdfs(comp[0]);
    cout << dp[comp[0]] << endl;
}