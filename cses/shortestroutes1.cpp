#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;
vector<ii> adj[MAXN];
ll dis[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for(int i = 1; i <= n; i++)
        dis[i] = INF;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        ll w = p.first;
        if(w > dis[u])
            continue;
        for(auto e : adj[u]) {
            int v = e.first;
            if(dis[v] > dis[u] + e.second) {
                dis[v] = dis[u] + e.second;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << '\n';
}