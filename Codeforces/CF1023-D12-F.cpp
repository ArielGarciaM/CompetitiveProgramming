#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXL = 23;
const long long INF = 1e9 + 1;
int h[MAXN];
int parent[MAXN][MAXL];
int deg[MAXN];
int pardsu[MAXN];
int rankdsu[MAXN];
int root;
vector<int> adj[MAXN];
vector<int> leaves;
vector<pair<int, int>> queries[MAXN];
map<long long, long long> mp;

struct edge
{
    int u, v, wt;
    edge(int u = 0, int v = 0, int wt = 0) : u(u), v(v), wt(wt){}
};

vector<edge> edges;
vector<edge> badEdges;

int find(int x)
{
    return (pardsu[x] == 0) ? x : pardsu[x] = find(pardsu[x]);
}

void join(int x, int y)
{
    int a = find(x), b = find(y);
    if(rankdsu[a] < rankdsu[b])
        swap(a, b);
    if(a != b)
    {
        pardsu[b] = a;
        if(rankdsu[a] == rankdsu[b])
            rankdsu[a]++;
    }
}

void kruskal()
{
    for(edge e : edges)
    {
        if(find(e.u) != find(e.v))
        {
            join(e.u, e.v);
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }
        else
            badEdges.push_back(e);
    }
}

void bfs()
{
    vector<int> vist(MAXN);
    h[root] = 0;
    queue<int> q;
    q.push(root);
    vist[root] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            deg[u]++;
            if(!vist[v])
            {
                vist[v] = 1;
                parent[v][0] = u;
                h[v] = h[u] + 1;
                q.push(v);
            }
        }
    }
}

void buildLCA()
{
    bfs();
    for(int i = 0; i < MAXL - 1; i++)
    {
        for(int v = 1; v < MAXN; v++)
        {
            if(parent[v][i] != 0)
            {
                parent[v][i + 1] = parent[parent[v][i]][i];
            }
        }
    }
}

int LCA(int u, int v)
{
    if(h[u] > h[v])
        swap(u, v);
    int diff = h[v] - h[u];
    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(diff >= (1 << i))
        {
            v = parent[v][i];
            diff -= (1 << i);
        }
    }
    if(u == v)
        return u;
    for(int i = MAXL - 1; i >= 0; i--)
    {
        if(parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    vector<edge> ownEdges;
    long long n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        edge e = edge(u, v, 0);
        ownEdges.push_back(e);
        edges.push_back(e);
        long long x = min(u, v), y = max(u, v);
        mp[n*x + y] = INF;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge e = edge(u, v, w);
        edges.push_back(e);
    }
    kruskal();
    root = edges[0].u;
    buildLCA();
    for(edge e : badEdges)
    {
        int l = LCA(e.u, e.v);
        queries[e.u].push_back({l, e.wt});
        queries[e.v].push_back({l, e.wt});
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
            leaves.push_back(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cq;
    for(int l : leaves)
    {
        int v = l;
        cq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
        while(v != 0)
        {
            for(int i = queries[v].size() - 1; i >= 0; i--)
            {
                cq.push({queries[v][i].second, queries[v][i].first});
                queries[v].pop_back();
            }
            while(!cq.empty() && v == cq.top().second)
            {
                cq.pop();
            }
            long long x = min(v, parent[v][0]), y = max(v, parent[v][0]), vtx = n*x + y;
            if(!cq.empty() && mp.count(vtx))
            {
                long long t = mp[vtx];
                mp[vtx] = min(t, (long long)cq.top().first);
            }
            v = parent[v][0];
        }
    }
    long long ans = 0;
    for(edge e : ownEdges)
    {
        long long x = min(e.u, e.v), y = max(e.u, e.v), vtx = n*x + y;
        long long z = mp[vtx];
        if(z == INF)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += z;
    }
    cout << ans << endl;
}
