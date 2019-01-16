#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5005;
const int INF = 1e9;
int q[MAXN], ptr[MAXN], dist[MAXN], src, dst;

struct Edge {
    int to, rev, f, cap;
    Edge(int to, int rev, int f, int cap) : to(to), rev(rev), f(f), cap(cap){}
};

vector<Edge> G[MAXN];

void addEdge(int u, int v, ll cap) {
    G[u].push_back(Edge(v, G[v].size(), 0, cap));
    G[v].push_back(Edge(u, G[u].size() - 1, 0, cap));
}

bool bfs() {
    memset(dist, -1, sizeof dist);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for(int qh = 0; qh < qt; qh++) {
        int u = q[qh];
        for(auto e : G[u]) {
            int v = e.to;
            if(dist[v] == -1 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[dst] != -1;
}

ll push(int u, int f) {
    if(u == dst)
        return f;
    for(int &i = ptr[u]; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        if(e.cap <= e.f)
            continue;
        int v = e.to;
        if(dist[v] == dist[u] + 1) {
            int df = push(v, min(f, e.cap - e.f));
            if(df > 0) {
                e.f += df;
                G[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

ll dinic() {
    ll res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(ll delta = push(src, INF))
            res += delta;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false),
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    src = 1, dst = n;
    while(m--) {
        int u, v, cap;
        cin >> u >> v >> w;
        addEdge(u, v, cap);
    }
    cout << dinic() << endl;
}