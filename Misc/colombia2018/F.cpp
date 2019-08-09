#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
const int INF = 1e9;

struct edge {
    int to, rev, f, cap;
};

vector<edge> adj[MAXN];
void addEdge(int u, int v, int c) {
    adj[u].push_back(edge{v, (int)adj[v].size(), 0, c});
    adj[v].push_back(edge{u, (int)adj[u].size() - 1, 0, 0});
}

int ptr[MAXN], dist[MAXN], ct[26], s, t;

bool bfs() {
    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    queue<int> q({s});
    while(!q.empty()) {
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

int dfs(int u, int f) {
    if(u == t || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        auto &e = adj[u][i];
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
    int res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF))
            res += pushed;
    }
    return res;
}

int main() {
    s = 199, t = 200;
    int n;
    cin >> n;
    // Edges n + whatever
    for(int i = 0; i < n; i++) {
        addEdge(s, i, 1);
        string s, t, r;
        cin >> s >> t >> r;
        memset(ct, 0, sizeof ct);
        int mx = 0;
        for(auto c : s)
            ct[c - 'A']++;
        for(auto c : t)
            ct[c - 'A']++;
        for(auto c : r)
            ct[c - 'A']++;
        for(int j = 0; j < 26; j++)
            mx = max(mx, ct[j]);
        for(int j = 0; j < 26; j++)
            if(ct[j] == mx) addEdge(i, n + j, 1);
    }
    int k;
    cin >> k;
    for(int i = n; i < n + 26; i++)
        addEdge(i, t, k);
    cout << maxflow() << endl;
}