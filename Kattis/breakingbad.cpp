#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int color[MAXN + 2];
vector<int> adj[MAXN + 2];
int vist[MAXN + 2];

bool bfs(int src)
{
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vist[u] = 1;
        for(auto v : adj[u])
        {
            if(color[u] == color[v])
                return false;
            if(!vist[v])
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    map<string, int> why;
    vector<string> alsowhy;
    for(int i = 0; i < n; i++) 
    {
        string s;
        cin >> s;
        why[s] = i;
        alsowhy.push_back(s);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string s, t;
        cin >> s >> t;
        int u = why[s], v = why[t];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
    for(int i = 0; i < n; i++)
    {
        if(!vist[i])
        {
            bool b = bfs(i);
            if(!b)
            {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(color[i] == 0)
            cout << alsowhy[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; i++)
    {
        if(color[i] == 1)
            cout << alsowhy[i] << " ";
    }
    cout << "\n";
}