#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
const int INF = 1e9;
int dist[MAXN], ptr[MAXN], src, dst;

struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void addEdge(int u, int v, int c) {
    adj[u].push_back(edge{v, (int)adj[v].size(), 0, c});
    adj[v].push_back(edge{u, (int)adj[u].size() - 1, 0, 0});
}

bool bfs() {
    memset(dist, -1, sizeof dist);
    dist[src] = 0;
    queue<int> q({src});
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dist[v] == -1 && e.f < e.cap) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist[dst] != -1;
}

int dfs(int u, int f) {
    if(u == dst || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
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

int maxflow() {
    int mf = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(src, INF))
            mf += pushed;
    }
    return mf;
}

bool bad[10005];
int w, h;

int main() {
    //src w*h, sink w*h + 1
    int w, h, k;
    cin >> w >> h >> k;
    src = w*h, dst = w*h + 1;
    while(k--) {
        int x, y;
        cin >> x >> y;
        bad[w*y + x] = true;
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int v = w*i + j;
            if(bad[v])
                continue;
            if((i + j) % 2)
                addEdge(v, dst, 1);
            else
                addEdge(src, v, 1);
            if((i + j) % 2 == 0) {
                if(j > 0 && !bad[v - 1])
                    addEdge(v, v - 1, 1);
                if(j + 1 < w && !bad[v + 1])
                    addEdge(v, v + 1, 1);
                if(i > 0 && !bad[v - w])
                    addEdge(v, v - w, 1);
            }
        }
    }
    cout << maxflow() << endl;
}