#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
const int INF = 1e9;

int dist[MAXN], q[MAXN], ptr[MAXN], vist[MAXN], src, dst;
bool undo = false;
vector<pair<int, int>> modif;

struct Edge { 
    int to, rev, f, cap, dff;
    Edge(int to = 0, int rev = 0, int f = 0, int cap = 0) : to(to), rev(rev), f(f), cap(cap){};
};

vector<Edge> G[MAXN];
Edge pre[MAXN];

void addEdge(int u, int v, int w = 1) {
    G[u].emplace_back(v, G[v].size(), 0, w);
    G[v].emplace_back(u, G[u].size() - 1, 0, 0);
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
                pre[v] = G[v][e.rev];
                q[qt++] = v;
            }
        }
    }
    return dist[dst] != -1;
}

int dfs(int u, int f) {
    if(u == dst)
        return f;
    for(int &i = ptr[u]; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        int v = e.to;
        if(dist[v] != dist[u] + 1 || e.cap <= e.f)
            continue;
        int df = dfs(v, min(f, e.cap - e.f));
        if(df > 0) {
            e.f += df;
            G[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

int inc(int u, int f) {
    vist[u] = 1;
    if(u == dst)
        return f;
    for(int i = 0; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        int v = e.to;
        if(!vist[v] && e.f < e.cap) {
            int df = inc(v, min(f, e.cap - e.f));
            if(df > 0) {
                e.f += df;
                G[v][e.rev].f -= df;
                modif.emplace_back(v, e.rev);
                modif.emplace_back(u, i);
                return df;
            }
        }
    }
    return 0;
}

int dinic() {
    int result = 0;
    if(!undo) {
        while(bfs()) {
            memset(ptr, 0, sizeof ptr);
            while(int pushed = dfs(src, INF))
                result += pushed;
        }
    }
    else {
        while(true) {
            memset(vist, 0, sizeof vist);
            int pushed = inc(src, INF);
            if(pushed == 0)
                break;
            result += pushed;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    src = 0, dst = m + n + 1;
    for(int i = 1; i <= m; i++)
        addEdge(src, i);
    for(int i = 1; i <= n; i++)
        addEdge(m + i, dst);
    for(int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, m + v);
    }
    int d = dinic();
    for(int i = 0; i < MAXN; i++) {
        for(auto &e : G[i])
            e.dff = e.f;
    }
    undo = true;
    int mx = 0;
    for(auto &e : G[0]) {
        e.cap = 3;
        int ex = dinic();
        mx = max(mx, d + ex);
        if(ex == 2) {
            cout << mx << endl;
            return 0;
        }
        while(!modif.empty()) {
            auto p = modif.back();
            modif.pop_back();
            G[p.first][p.second].f = G[p.first][p.second].dff;
        }
        e.cap = 1;
    }
    cout << mx << endl;
}