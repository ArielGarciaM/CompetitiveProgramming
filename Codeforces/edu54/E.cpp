#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 2;
const int src = 1;
vector<int> adj[MAXN];
vector<int> val[MAXN];
vector<pair<int, int>> proc[MAXN];
vector<pair<int, int>> queries[MAXN];
vector<int> ht(MAXN, -1);

void bfs()
{
    ht[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(ht[v] == -1)
            {
                ht[v] = ht[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}