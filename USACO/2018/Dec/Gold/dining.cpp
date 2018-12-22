#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e4 + 5;
const ll INF = 1e12;
int n, m, k;
vector<int> vist(MAXN);
vector<pair<int, ll>> adj[MAXN];

void dijkstra(int src, vector<ll> &dist) {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        vist[i] = 0;
    }
    dist[src] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vist[u])
            continue;
        vist[u] = 1;
        for(auto p : adj[u]) {
            int v = p.first;
            ll w = p.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> dist1(MAXN), dist2(MAXN);
    dijkstra(n, dist1);
    for(int i = 0; i < k; i++) {
        int v;
        ll val;
        cin >> v >> val;
        adj[n + 1].push_back({v, dist1[v] - val});
    }
    dijkstra(n + 1, dist2);
    for(int i = 1; i <= n - 1; i++) {
        //cout << dist1[i] << " " << dist2[i] << endl;
        if(dist2[i] <= dist1[i])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}