#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[16004];
const int INF = 1e9;

int dijkstra(int s, int t)
{
    vector<int> dist(16004, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        int u = pq.top().second;
        if(u == t)
            break;
        pq.pop();
        for(auto p : adj[u])
        {
            int v = p.first, w = p.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

int main()
{
    freopen("input81.in", "r", stdin);
    string s, sanit = "";
    int rect[81][81];
    for(int i = 0; i < 80; i++)
    {
        cin >> s;
        sanit = "";
        for(int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if('0' <= c && c <= '9') sanit += c;
            else sanit += ' ';
        }
        stringstream ss(sanit);
        for(int j = 0; j < 80; j++)
        {
            ss >> rect[i][j];
        }
    }
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
    for(int i = 0; i < 80; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            for(auto d : dir)
            {
                int ni = i + d.first, nj = j + d.second;
                if(ni >= 0 && ni < 80 && nj >= 0 && nj < 80)
                {
                    adj[80*i + j].push_back({80*ni + nj, rect[ni][nj]});
                }
            }
        }
    }
    cout << dijkstra(0, 80*80 - 1) + rect[0][0] << endl;
}