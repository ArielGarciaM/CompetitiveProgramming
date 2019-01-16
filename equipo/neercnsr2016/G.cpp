#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN], ts;
int into[MAXN], deep[MAXN], n, m, k;
vector<pair<int, int>> edges;
set<int> pq;

void tsAdd(int u) {
    ts.push_back(u);
    for(auto v : adj[u]) {
        into[v]--;
        if(into[v] == 0)
            pq.insert(v);
    }
}

int get(int u) {
    if(adj[u].empty())
        return u;
    return deep[u] = get(deep[u]);
}

int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deep[u] = v;
        into[v]++;
    }
    for(int v = 1; v <= n; v++) {
        deep[v] = (deep[v] ? deep[v] : v);
        if(into[v] == 0)
            pq.insert(v);
    }
    while(ts.size() < n) {
        if(pq.size() == 1 || k == 0) {
            int v = *pq.begin();
            pq.erase(pq.begin());
            tsAdd(v);
        }
        else {
            int v = *pq.begin();
            pq.erase(pq.begin());
            int u;
            if(k == 1)
               u = *(--pq.end());
            else
                u = *pq.begin();
            edges.push_back({u, v});
            adj[u].push_back(v);
            deep[u] = get(v);
            into[v]++;
            k--;
        }
    }
    for(auto v : ts)
        cout << v << " ";
    cout << '\n';
    cout << edges.size() << '\n';
    for(auto e : edges)
        cout << e.first << " " << e.second << '\n';
}