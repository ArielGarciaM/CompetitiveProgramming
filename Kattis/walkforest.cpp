#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAXN = 1005;
vector<ii> adj[MAXN];
ll dist[MAXN], cnt[MAXN], memo[MAXN];

ll dp(int s) {
    if(s == 2)
        return 1;
    if(memo[s] != -1)
        return memo[s];
    ll d = 0;
    for(auto e : adj[s]) {
        int v = e.first;
        if(dist[v] < dist[s])
            d += dp(v);
    }
    return memo[s] = d;
}

void dijkstra(int s) {
    fill(dist, dist + MAXN, 2e9);
    dist[s] = 0;
    priority_queue<ii> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        if(-p.first > dist[u])
            continue;
        for(auto e : adj[u]) {
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n, n > 0) {
        cin >> m;
        for(int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        dijkstra(2);
        memset(cnt, 0, sizeof cnt);
        memset(memo, -1, sizeof memo);
        cout << dp(1) << endl;
        for(int i = 0; i < MAXN; i++)
            adj[i].clear();
    }
}