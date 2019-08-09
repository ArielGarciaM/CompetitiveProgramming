#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5, INF = 1e9 + 5;
struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void add_edge(int u, int v, int cap, int rcap = 0) {
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, rcap};
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

int dfs(int u, int f) {
    if(u == dst || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
            continue;
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

int mf() {
    int res = 0;
    while(bfs()) {
        fill(ptr, ptr + MAXN, 0);
        while(int df = dfs(src, INF))
            res += df;
    }
    return res;
}

int main() {
    
}