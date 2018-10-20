#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
const int INF = 1e9;
vector<pair<int, int>> adj[MAXN + 2];
bool fire[MAXN + 2];

int dijkstra(vector<int> &stat)
{
    vector<int> dist(MAXN + 2, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = 0;
    adj[MAXN + 1].clear();
    for(int src : stat)
    {
        adj[MAXN + 1].push_back({0, src});
    }
    dist[MAXN + 1] = 0;
    pq.push({0, MAXN + 1});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        ans = max(ans, dist[u]);
        for(auto e : adj[u])
        {
            int w = e.first, v = e.second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return ans;
}

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    for(int t = 0; t < tc; t++)
    {
        if(t > 0)
        {
            cout << endl;
        }

        for(int i = 0; i < MAXN + 2; i++)
            adj[i].clear();

        int fi, n;
        cin >> fi >> n;
        memset(fire, false, sizeof(fire));
        for(int i = 0; i < fi; i++)
        {
            int f;
            cin >> f;
            fire[f] = true;
        }
        int u, v, wt;
        string input;
        cin.ignore();
        while(getline(cin, input))
        {
            if(input.empty())
                break;
            stringstream ss(input);
            ss >> u >> v >> wt;
            adj[u - 1].push_back({wt, v - 1});
            adj[v - 1].push_back({wt, u - 1});
        }
        vector<int> ans(MAXN + 2);
        int best = INF;
        for(int newst = 0; newst < n; newst++)
        {
            vector<int> stat;
            for(int i = 0; i < n; i++)
            {
                if(fire[i] || i == newst)
                    stat.push_back(i);
            }
            ans[newst] = dijkstra(stat);
            best = min(best, ans[newst]);
        }
        for(int i = 0; i < n; i++)
        {
            if(ans[i] == best)
            {
                cout << i << endl;
                break;
            }
        }
    }
}