#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
vector<int> adj[MAXN];
vector<int> vist(MAXN);
int A[MAXN];

int dfs(int s)
{
    vist[s] = 1;
    int ans = A[s];
    for(auto v : adj[s])
    {
        if(!vist[v])
            ans += dfs(v);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
    {
        if(!vist[i])
        {
            if(dfs(i) != 0)
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    cout << "POSSIBLE\n";
    return 0;
}