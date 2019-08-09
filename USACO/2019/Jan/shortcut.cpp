#include <bits/stdc++.h>
using namespace std;

struct trip {
    long long d, p, v;
    bool operator< (const trip &o) const {
        if(d != o.d)
            return d > o.d;
        if(p != o.p)
            return p > o.p;
        return v > o.v;
    }
};

const long long MAXN = 10005;
const long long INF = 1e9;
vector<pair<long long, long long>> adj[MAXN]; // loc, cost
long long dist[MAXN], cost[MAXN], par[MAXN];
vector<long long> prox[MAXN];

void dijkstra(long long s) {
    for(long long i = 0; i < MAXN; i++) {
        dist[i] = INF;
        par[i] = INF;
    }
    priority_queue<trip> pq;
    pq.push({0, 0, s});
    dist[s] = 0;
    par[s] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        long long d = t.d, p = t.p, u = t.v;
        if(dist[u] < d || (dist[u] == d && par[u] < p))
            continue;
        for(auto e : adj[u]) {
            long long v = e.first;
            if(dist[v] > dist[u] + e.second || (dist[v] == dist[u] + e.second && u < par[v])) {
                //cout << u << " " << v << " " << e.second << endl;
                dist[v] = dist[u] + e.second;
                par[v] = u;
                pq.push({dist[v], par[v], v});
            }
        }
    }
}

void dfs(long long s) {
    for(auto v : prox[s]) {
        dfs(v);
        cost[s] += cost[v];
    }
}

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    long long n, m, t;
    cin >> n >> m >> t;
    for(long long i = 1; i <= n; i++)
        cin >> cost[i];
    for(long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dijkstra(1);
    /*for(long long i = 1; i <= n; i++) {
        cout << i << ": ";
        long long v = i;
        while(v != 0) {
            cout << v;
            v = par[v];
            if(v != 0)
                cout << "->";
        }
        cout << endl;
    }*/
    for(long long i = 1; i <= n; i++)
        prox[par[i]].push_back(i);
    dfs(1);
    long long ans = 0;
    for(long long v = 1; v <= n; v++) {
        if(t < dist[v])
            ans = max(ans, cost[v]*(dist[v] - t));
    }
    cout << ans << endl;
}