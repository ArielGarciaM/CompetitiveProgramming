#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

struct edge {
    int v, w;
};
const int MAXN = 1e3 + 5;
const int INF = 1e9;
set<ii> path, bad;
vector<ii> edges;
vector<edge> adj[MAXN];
int back[MAXN], cst[MAXN];

void prim() {
    priority_queue<ii> pq;
    pq.push({INF, 0});
    cst[0] = INF;
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second, w = p.first;
        if(w < cst[u]) continue;
        for(auto e : adj[u]) {
            int v = e.v;
            if(cst[v] < min(w, e.w)) {
                cst[v] = min(w, e.w);
                back[v] = u;
                pq.push({cst[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(u > v) swap(u, v);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v});
    }
    prim();
    int x = n - 1;
    while(x != 0) {
        int u = x, v = back[x];
        if(u > v) swap(u, v);
        path.insert({u, v});
        x = back[x];
    }
    x = n - 1;
    while(true) {
        for(auto y : adj[x]) {
            int u = x, v = y.v;
            if(u > v) swap(u, v);
            if(!path.count({u, v})) bad.insert({u, v});
        }
        if(!x) break;
        x = back[x];
    }
    bool out = false;
    for(int i = 0; i < m; i++) {
        if(bad.count(edges[i])) {
            if(out) cout << " ";
            out = true;
            cout << i;
        }
    }
    if(out)
        cout << '\n';
    else
        cout << "none\n";
}