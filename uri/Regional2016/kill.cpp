#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 1e9;

vector<int> adj[MAXN];
int cap[MAXN][MAXN];
int d[MAXN];
int parent[MAXN];
int s, t;

void addEdge(int u, int v, int c)
{
    adj[u].push_back(v);
    cap[u][v] = c;
}

int augment()
{
    int flow = INF;
    for(int v = t; v != s; v = parent[v])
    {
        if(v == s)
            break;
        flow = min(cap[parent[v]][v], flow);
    }
    for(int v = t; v != s; v = parent[v])
    {
        cap[parent[v]][v] -= flow;
        cap[v][parent[v]] += flow;
    }
    return flow;
}

bool bfs()
{
    memset(d, -1, sizeof(d));
    memset(parent, -1,sizeof(parent));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == t)
            break;
        for(int v : adj[u])
        {
            if(d[v] == -1 && cap[u][v] > 0)
            {
                d[v] = d[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return (d[t] != -1);
}

int maxflow()
{
    int flow = 0;
    while(true)
    {
        if(!bfs())
            break;
        int ext = augment();
        flow += ext;
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
            adj[i].clear();
        memset(cap, 0, MAXN * sizeof(cap[0]));

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