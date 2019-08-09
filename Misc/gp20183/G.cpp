#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int INF = 1e9;

struct edge {
    int to, rev, f, cap, time;
    edge(int to, int rev, int f, int cap, int time) : to(to), rev(rev), f(f), cap(cap), time(time) {}
};

vector<edge> adj[MAXN];

void addEdge(int u, int v, int cap, int time) {
    adj[u].push_back(edge(v, adj[v].size(), 0, cap, time));
    adj[v].push_back(edge(u, adj[u].size() - 1, 0, 0, time));
}

int s, t, bnd, dist[MAXN], ptr[MAXN];

bool bfs() {
    queue<int> q({s});
    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(e.time > bnd)
                continue;
            if(dist[v] == -1 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

int dfs(int u, int f) {
    if(u == t || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        auto &e = adj[u][i];
        if(e.time > bnd)
            continue;
        int v = e.to;
        if(dist[v] != dist[u] + 1)
            continue;
        if(int pushed = dfs(v, min(f, e.cap - e.f))) {
            e.f += pushed;
            adj[v][e.rev].f -= pushed;
            return pushed;
        }
    }
    return 0;
}

int mf() {
    int res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF))
            res += pushed;
    }
    return res;
}

void clean() {
    for(int i = 0; i < MAXN; i++) {
        for(auto &e : adj[i]) {
            e.f = 0;
        }
    }
}

int main() {
    int p, r, c, sd = 0;
    cin >> p >> r >> c;
    s = p + r + 1, t = p + r + 2;
    for(int i = 1; i <= p; i++) {
        int d;
        cin >> d;
        sd += d;
        addEdge(r + i, t, d, 0);
    }
    for(int i = 1; i <= r; i++) {
        int e;
        cin >> e;
        addEdge(s, i, e, 0);
    }
    while(c--) {
        int u, v, t;
        cin >> u >> v >> t;
        addEdge(v, r + u, INF, t);
    }
    int lo = 0, hi = 1e6 + 5;
    bnd = hi;
    int m = mf();
    if(m < sd) {
        cout << -1 << endl;
        return 0;
    }
    clean();
    while(lo < hi) {
        int mi = (lo + hi)/2;
        bnd = mi;
        int m = mf();
        if(m == sd)
            hi = mi;
        else
            lo = mi + 1;
        clean();
    }
    cout << lo << endl;
}