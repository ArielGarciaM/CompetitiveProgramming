#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 1e9;
int dist[MAXN], ptr[MAXN], s, t;

struct Edge {
    int to, rev, f, cap;
};

vector<Edge> G[MAXN];

void addEdge(int u, int v, int cap)
{
    G[u].push_back(Edge({v, (int)G[v].size(), 0, cap}));
    G[v].push_back(Edge({u, (int)G[u].size() - 1, 0, 0}));
}

bool bfs()
{
    memset(dist, -1, sizeof dist);
    queue<int> q({s});
    dist[s] = 0;
    while(!q.empty() && dist[t] == -1) {
        int u = q.front();
        q.pop();
        for(auto e : G[u]) {
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
    for(int &i = ptr[u]; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        int v = e.to;
        if(dist[v] != dist[u] + 1)
            continue;
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            G[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

int maxflow()
{
    int flow = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int pushed = dfs(s, INF))
            flow += pushed;
    }
    return flow;
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> votes[60];
    for(int i = 1; i <= n; i++)
    {
        cin >> votes[i].first >> votes[i].second;
    }
    int ans = 0;
    for(int ww = 1; ww <= n; ww++)
    {
        for(int i = 0; i < MAXN; i++)
            G[i].clear();

        bool wvoter[60], wvotee[60];
        memset(wvoter, false, sizeof(wvoter));
        memset(wvotee, false, sizeof(wvotee));
        int wvoters = 0;
        for(int i = 1; i <= n; i++)
        {
            if(votes[i].first == ww || votes[i].second == ww)
            {
                wvoter[i] = true;
                wvoters++;
            }
            if(votes[ww].first == i || votes[ww].second == i)
                wvotee[i] = true;
        }
        if(wvoters <= 1)
        {
            ans++;
            continue;
        }
        s = 2*n + 1;
        t = 2*n + 2;
        for(int i = 1; i <= n; i++)
        {
            addEdge(s, i, 1);
            int mvotes = wvotee[i] ? wvoters - 2 : wvoters - 1;
            addEdge(n + i, t, mvotes);
            if(wvoter[i] || ww == i)
                continue;
            addEdge(i, votes[i].first + n, 1);
            addEdge(i, votes[i].second + n, 1);
        }
        int f = maxflow();
        if(f < n - 1 - wvoters)
            ans++;
    }
    cout << ans << endl;
}