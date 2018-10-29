#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int INF = 1e9;

set<int> groups[105];
vector<int> adj[205];
int par[205];
int cap[205][205];
int n, s, t;

void init()
{
    adj[t].clear();
    for(int u = 1; u <= n; u++)
    {
        for(auto v : adj[u])
        {
            if(v == s)
            {
                cap[v][u] = 1;
                cap[u][v] = 0;
            }
            else
            {
                cap[u][v] = 1;
                cap[v][u] = 0;
            }
        }
    }
    for(int v = n + 1; v <= 2*n; v++)
    {
        if(!adj[v].empty() && adj[v].back() == t)
        {
            adj[v].pop_back();
            cap[v][t] = 0;
            cap[t][v] = 0;
        }
    }
}

void addEdge(int u, int v, int c)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = c;
}

bool bfs()
{
    vector<int> vist(205);
    memset(par, 0, sizeof(par));
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == t)
            break;
        vist[u] = 1;
        for(int v : adj[u])
        {
            if(vist[v] || cap[u][v] == 0)
                continue;
            par[v] = u;
            q.push(v);
        }
    }
    return (par[t] != 0);
}

int augment()
{
    int v = t;
    int maxpush = INF;
    while(par[v] != 0)
    {
        maxpush = min(cap[par[v]][v], maxpush);
        v = par[v];
    }
    v = t;
    while(par[v] != 0)
    {
        cap[par[v]][v] -= maxpush;
        cap[v][par[v]] += maxpush;
        v = par[v];
    }
    return maxpush;
}

int maxflow()
{
    int f = 0;
    while(bfs())
    {
        f += augment();
    }
    return f;
}

int main()
{
    // Source = 2*n + 1, Sink = 2*n + 2;
    int q;
    bool hasFull = false;
    cin >> n >> q;
    s = 2*n + 1;
    t = 2*n + 2;
    for(int i = 1; i <= n; i++)
    {
        addEdge(s, i, 1);
        int k;
        cin >> k;
        if(k == n)
            hasFull = true;
        for(int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            addEdge(i, n + x, 1);
        }
    }
    while(q--)
    {
        int k;
        cin >> k;
        if(k == 0)
        {
            cout << (hasFull ? "N\n" : "Y\n");
            continue;
        }
        init();
        for(int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            addEdge(n + x, t, 1);
        }
        int mf = maxflow();
        cout << (mf == k ? "Y\n" : "N\n");
    }
}
