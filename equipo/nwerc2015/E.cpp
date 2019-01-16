#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int INF = 1e9;
int ptr[MAXN], dist[MAXN], s, t;
typedef long long ll;

struct Edge {
    int to, rev, f, cap;
    Edge(int to, int rev, int f, int cap) : to(to), rev(rev), f(f), cap(cap){}
};
vector<Edge> adj[MAXN];

void addEdge(int u, int v, int cap) {
    adj[u].push_back(Edge(v, adj[v].size(), 0, cap));
    adj[v].push_back(Edge(u, adj[u].size() - 1, 0, 0));
}

bool bfs() {
    memset(dist, -1, sizeof dist);
    queue<int> q({s});
    dist[s] = 0;
    while(!q.empty() && dist[t] == -1) {
        int u = q.front();
        q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dist[v] == -1 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

int dfs(int u, int flow) {
    if(u == t || !flow)
        return flow;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        Edge &e = adj[u][i];
        int v = e.to;
        if(dist[v] != dist[u] + 1)
            continue;
        if(int pushed = dfs(v, min(flow, e.cap - e.f))) {
            e.f += pushed;
            adj[v][e.rev].f -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int mf = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF))
            mf += pushed;
    }
    return mf;
}

int main() {
    int n;
    cin >> n;
    int ctr = n + 1;
    s = 0, t = 4*n + 1;
    map<ll, int> pos;
    map<int, ll> inv;
    pair<ll, ll> ops[MAXN];
    for(int i = 1; i <= n; i++) {
        addEdge(s, i, 1);
        ll x, y;
        cin >> x >> y;
        ops[i] = {x, y};
        if(!pos.count(x + y)) {
            pos[x + y] = ctr;
            inv[ctr] = x + y;
            ctr++;
        }
        if(!pos.count(x - y)) {
            pos[x - y] = ctr;
            inv[ctr] = x - y;
            ctr++;
        }
        if(!pos.count(x * y)) {
            pos[x * y] = ctr;
            inv[ctr] = x * y;
            ctr++;
        }
        addEdge(i, pos[x + y], 1);
        addEdge(i, pos[x - y], 1);
        addEdge(i, pos[x * y], 1);
    }
    for(auto p : pos)
        addEdge(p.second, t, 1);
    int mf = dinic();
    if(mf < n) {
        cout << "impossible\n";
        return 0;
    }
    bool taken[MAXN];
    memset(taken, false, sizeof taken);
    for(int v = 1; v <= n; v++) {
        for(auto e : adj[v]) {
            if(!e.f || e.to == 0)
                continue;
            ll res = inv[e.to];
            pair<ll, ll> p = ops[v];
            if(p.first + p.second == res) {
                cout << p.first << " + " << p.second << " = " << res << endl;
                break;
            }
            if(p.first - p.second == res) {
                cout << p.first << " - " << p.second << " = " << res << endl;
                break;
            }
            if(p.first * p.second == res) {
                cout << p.first << " * " << p.second << " = " << res << endl;
                break;
            }
        }
    }
}