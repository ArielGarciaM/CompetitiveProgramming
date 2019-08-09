#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 1e18;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ii>> adj(n + 1);
    vector<ll> found(n + 1);
    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, 1});
    vector<ll> paths;
    found[0] = 1;
    while(!q.empty()) {
        if(paths.size() == k)
            break;
        auto p = q.top(); q.pop();
        int u = p.second;
        found[u]++;
        if(u == n)
            paths.push_back(p.first);
        if(found[u] > k)
            continue;
        for(auto e : adj[u])
            q.push({p.first + e.second, e.first});
    }
    for(auto p : paths)
        cout << p << " ";
    cout << '\n';
}