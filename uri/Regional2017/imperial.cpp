#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

// Kruskal
struct Edge
{
    pair<int, int> ends;
    int weight;
    bool operator<(const Edge &edg) const{return weight < edg.weight;}
    Edge(int u, int v, int wt) : ends({u, v}), weight(wt){}
};


// Kruskal - Union Find
vector<int> par;

int find(int x)
{
    return par[x] == -1 ? x : par[x] = find(par[x]);
}

void join(int x, int y)
{
    int a = find(x), b = find(y);
    if(a > b)
        swap(a, b);
    if(a != b)
        par[b] = a;
}

vector<pair<int, int>> adj[MAXN + 2];

int kruskal(vector<Edge> &edges, int n)
{
    for(int i = 0; i <= n; i++)
        par.push_back(-1);
    int count = 0;
    int ret = 0;
    for(auto e : edges)
    {
        int u = e.ends.first;
        int v = e.ends.second;
        int w = e.weight;
        if(find(u) != find(v))
        {
            join(u, v);
            count++;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            ret += w;
        }
        if(count == n - 1)
            break;
    }
    return ret;
}

// LCA
int parent[MAXN + 5][25];
int maxwt[MAXN + 5][25];
int vist[MAXN + 2];
int height[MAXN + 2];

void dfs(int src, int prev = 0, int wt = 0, int ht = 0)
{
    vist[src] = 1;
    parent[src][0] = prev;
    maxwt[src][0] = wt;
    height[src] = ht;
    for(auto e : adj[src])
    {
        int v = e.first, w = e.second;
        if(!vist[v])
            dfs(v, src, w, ht + 1);
    }
}

void buildLCA(int n)
{
    dfs(1);
    for(int lev = 1; lev < 25; lev++)
    {
        for(int v = 1; v <= n; v++)
        {
            if(parent[v][lev - 1])
            {
                parent[v][lev] = parent[parent[v][lev - 1]][lev - 1];
                maxwt[v][lev] = max(maxwt[v][lev - 1], maxwt[parent[v][lev - 1]][lev - 1]);
            }
        }
    }
}

int query(int u, int v)
{
    if(height[u] > height[v])
        swap(u, v);
    int diff = height[v] - height[u];
    int ans = 0;
    //cout << "u, v: " << u << " " << v << endl;
    for(int i = 24; i >= 0; i--)
    {
        if(diff == 0)
            break;
        if(diff >= (1 << i))
        {
            //cout << "diff, i: " << diff << " " << i << endl;
            diff -= (1 << i);
            ans = max(ans, maxwt[v][i]);
            v = parent[v][i];
        }
    }
    //cout << "u, v: " << u << " " << v << endl;
    if(u == v)
        return ans;

    for(int i = 24; i >= 0; i--)
    {
        if(parent[u][i] != parent[v][i])
        {
            ans = max(ans, max(maxwt[u][i], maxwt[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return max(ans, max(maxwt[u][0], maxwt[v][0]));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, R;
    cin >> N >> R;
    vector<Edge> edges;
    map<pair<int, int>, int> wts;
    for(int i = 0; i < R; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(u > v)
            swap(u, v);
        wts[{u, v}] = w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end());
    int mstwt = kruskal(edges, N);
    for(int i = 0; i < MAXN + 5; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            parent[i][j] = 0;
            maxwt[i][j] = 0;
        }
    }
    buildLCA(N);
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u > v)
            swap(u, v);
        cout << mstwt - query(u, v) + wts[{u, v}] << endl;
    }
}