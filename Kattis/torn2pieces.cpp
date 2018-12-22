#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> adj;
map<string, int> vist;
map<string, string> parent;

void dfs(string src)
{
    vist[src] = 1;
    for(auto v : adj[src])
    {
        if(!vist[v])
        {
            parent[v] = src;
            dfs(v);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        string s, u, v;
        getline(cin, s);
        stringstream ss(s);
        ss >> u;
        while(ss >> v)
        {
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }
    string s, to;
    cin >> s >> to;
    parent[s] = "$";
    dfs(s);
    if(!parent.count(to))
    {
        cout << "no route found\n";
        return 0;
    }
    vector<string> ans;
    while(to != "$")
    {
        ans.push_back(to);
        to = parent[to];
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << "\n";
}