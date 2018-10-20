#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e4;
const int INF = 1e9;
// G[u][v] es el peso de la arista u -> v
map<int, int> G[MAXN + 5];
vector<int> par(MAXN + 5);
int f;

int augment(int src, int snk, vector<int> &par)
{
    int minE = INF;
    for(int v = snk;;v = par[v])
    {
        if(v == src)
            break;
        minE = min(minE, G[par[v]][v]);
    }
    for(int v = snk; v != src; v = par[v])
    {
        G[par[v]][v] -= minE;
        G[v][par[v]] += minE;
    }
    return minE;
}

void bfs(int src, int snk, vector<int> &par)
{
    bool vist[MAXN + 5];
    memset(vist, false, sizeof(vist));
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vist[u] = true;
        if(u == snk)
            break;
        for(auto p : G[u])
        {
            int v = p.first, w = p.second;
            if(w > 0 && !vist[v])
            {
                par[v] = u;
                q.push(v);
            }
        }
    }
}

long long maxflow(int src, int snk)
{
    long long mf = 0;
    do
    {
        f = 0;
        bfs(src, snk, par);
        f = augment(src, snk, par);
        mf += f;
    } while(f);
    return mf;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x][n + y] = INF;
        G[y][n + x] = INF;
    }
    int src = 2*n + 1, snk = 2*n + 2;
    for(int i = 1; i <= n; i++)
    {
        G[src][i] = 1;
        G[n + i][snk] = 1;
    }
    int f = maxflow(src, snk);
    if(f < n)
    {
        cout << "Impossible\n";
        return 0;
    }
    for(int u = 1; u <= n; u++)
    {
        for(auto p : G[u])
        {
            int v = p.first;
            if(G[v][u] == 1)
            {
                cout << v - n << endl;
                break;
            } 
        }
    }
}