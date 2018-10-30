#include <bits/stdc++.h>
using namespace std;

const int MAXN = 805;
const int INF = 1e9;
int cap[MAXN][MAXN];
int parent[MAXN];
int vist[MAXN];
vector<int> adj[MAXN];
int s, t;

void addEdge(int u, int v, int c)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = c;
}

bool bfs()
{
    memset(vist, 0, sizeof(vist));
    vist[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == t)
            break;
        for(auto v : adj[u])
        {
            if(!vist[v] && cap[u][v] > 0)
            {
                vist[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return (vist[t] == 1);
}

int augment()
{
    int maxpush = INF;
    for(int v = t; v != s; v = parent[v])
    {
        maxpush = min(cap[parent[v]][v], maxpush);
    }
    for(int v = t; v != s; v = parent[v])
    {
        cap[parent[v]][v] -= maxpush;
        cap[v][parent[v]] += maxpush;
    }
    return maxpush;
}

int maxflow()
{
    int mf = 0;
    while(bfs())
    {
        mf += augment();
    }
    return mf;
}

int main()
{
    int rect[21][21];
    int R, C, N, ct = 0;
    cin >> R >> C;
    N = R*C;
    for(int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < C; j++)
        {
            rect[i][j] = s[j];
            if(s[j] == 'o')
                ct++;
        }
    }
    if(ct % 2)
    {
        cout << "N\n";
        return 0;
    }
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            for(auto d : dir)
            {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || ni >= R || nj < 0 || nj >= C)
                    continue;
                int u = C*i + j, v = C*ni + nj;
                addEdge(u, v, 1);
                if(rect[i][j] == '-')
                    addEdge(N + u, v, 1);
                if(rect[ni][nj] == '-')
                    addEdge(u, N + v, 1);
                if(rect[i][j] == '-' && rect[ni][nj] == '-')
                    addEdge(N + u, N + v, 1);
            }
        }
    }
    s = 2*N, t = 2*N + 1;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            int v = C*i + j;
            if((i + j) % 2)
            {
                addEdge(s, v, 1);
                addEdge(s, v + N, 1);
            }
            else
            {
                addEdge(v, t, 1);
                addEdge(v + N, t, 1);
            }
        }
    }
    int def = maxflow() - (2*N - ct)/2;
    if(def == 0)
        cout << "Y\n";
    else
        cout << "N\n";
}