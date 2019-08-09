#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;

void dijkstra(int s, vector<vector<ii>> &adj, vector<ll> &dis) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        int u = p.second;
        ll w = p.first;
        if(w > dis[u])
            continue;
        for(auto e : adj[u]) {
            int v = e.first;
            if(dis[v] > dis[u] + e.second) {
                dis[v] = dis[u] + e.second;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> adj(n + 1), radj(n + 1);
    vector<ll> idis(n + 1, INF), odis(n + 1, INF);
    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }
    dijkstra(1, adj, idis);
    dijkstra(n, radj, odis);
    ll ans = INF;
    for(int u = 1; u <= n; u++)
        for(auto e : adj[u])
            ans = min(ans, idis[u] + odis[e.first] + e.second/2);
    cout << ans << '\n';
}