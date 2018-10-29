#include <bits/stdc++.h>
using namespace std;

int vist[205];
vector<int> adj[205];
bool reach[205][205];

void bfs(int src)
{
    memset(vist, 0, sizeof(vist));
    vist[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(!vist[v])
            {
                q.push(v);
                reach[src][v] = true;
            }
        }
    }
}

int main()
{
    map<string, int> trans;
    memset(reach, false, sizeof(reach[0]));
    int n, m, ind = 1;
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        string s, t, r;
        getline(cin, s);
        stringstream ss(s);
        ss >> t;
        if(!trans.count(t))
        {
            trans[t] = ind;
            ind++;
        }
        ss >> r;
        ss >> r;
        ss >> r;
        ss >> r;
        if(!trans.count(r))
        {
            trans[r] = ind;
            ind++;
        }
        adj[trans[t]].push_back(trans[r]);
    }
    for(int i = 1; i <= trans.size(); i++)
    {
        bfs(i);
    }
    for(int i = 0; i < m; i++)
    {
        string s, t, r;
        getline(cin, s);
        stringstream ss(s);
        ss >> t;
        ss >> r;
        ss >> r;
        ss >> r;
        ss >> r;
        if(reach[trans[t]][trans[r]])
            cout << "Fact\n";
        else if(reach[trans[r]][trans[t]])
            cout << "Alternative Fact\n";
        else
            cout << "Pants on Fire\n";
    }
}
