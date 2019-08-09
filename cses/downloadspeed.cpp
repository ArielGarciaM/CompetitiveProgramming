#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 505;
const ll INF = 1e10;

struct edge {
    int to, rev;
    ll f, cap;
};
vector<edge> adj[MAXN];

void add_edge(int u, int v, ll cap) {
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, 0};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int dis[MAXN], ptr[MAXN], src, dst;

bool bfs() {
    fill(dis, dis + MAXN, -1);
    dis[src] = 0;
    queue<int> q({src});
    while(!q.empty() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] == -1 && e.f < e.cap) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[dst] != -1;
}

ll dfs(int u, ll f) {
    if(u == dst || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
            continue;
        if(ll df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

ll mf() {
    ll res = 0;
    while(bfs()) {
        fill(ptr, ptr + MAXN, 0);
        while(ll df = dfs(src, INF))
            res += df;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    src = 1, dst = n;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }
    cout << mf() << '\n';
}