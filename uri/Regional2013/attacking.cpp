#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20050;
const int INF = 1e9;

struct edge {
    int to, rev, f, cap;
    edge(int to, int rev, int f, int cap) : to(to), rev(rev), f(f), cap(cap){}
};

vector<edge> adj[MAXN];

void addEdge(int u, int v) {
    adj[u].emplace_back(v, adj[v].size(), 0, 1);
    adj[v].emplace_back(u, adj[u].size() - 1, 0, 0);
}

int s, t, dist[MAXN], ptr[MAXN];

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

int mf() {
    int res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF))
            res += pushed;
    }
    return res;
}

char board[105][105];
int flood[105][105];
bool seen[MAXN];

int main() {
    int n;
    s = MAXN - 2;
    t = MAXN - 1;
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> board[i][j];
        int comp = 1;
        for(int i = 0; i < MAXN; i++)
            seen[i] = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    comp++;
                    continue;
                }
                if(!seen[comp])
                    addEdge(s, comp);
                seen[comp] = true;
                flood[i][j] = comp;
            }
            comp++;
        }
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                if(board[i][j] == 'X') {
                    comp++;
                    continue;
                }
                if(!seen[comp])
                    addEdge(comp, t);
                seen[comp] = true;
                addEdge(flood[i][j], comp);
            }
            comp++;
        }
        /*for(int i = 0; i < MAXN; i++) {
            for(auto v : adj[i])
                cout << i << " " << v.to << endl;
        }*/
        cout << mf() << endl;
        for(int i = 0; i < MAXN; i++)
            adj[i].clear();
    }
}

