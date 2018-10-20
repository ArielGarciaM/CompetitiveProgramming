#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

vector<double> dist(MAXN + 2, -1.0);

class Compare
{
public:
    bool operator() (pair<double, int> a, pair<double, int> b)
    {
        return a.first < b.first;
    }
};

vector<pair<double, int>> adj[MAXN + 2];

double dijkstra(int src, int to)
{
    for(int i = 0; i < dist.size(); i++)
        dist[i] = -1.0;
    dist[src] = 1.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, Compare> pq;
    pq.push(make_pair(1.0, src));
    while(!pq.empty())
    {
        int u = pq.top().second;
        //cout << "u: " << u << endl;
        pq.pop();
        if(u == to)
            break;
        for(auto e : adj[u])
        {
            double wt = e.first;
            int v = e.second;
            if(dist[v] < dist[u]*wt)
            {
                dist[v] = dist[u]*wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[to];
}

int main()
{
    int n, m;
    while(cin >> n >> m, n > 0)
    {
        for(int i = 0; i < MAXN + 2; i++)
            adj[i].clear();
        for(int i = 0; i < m; i++)
        {
            int u, v;
            double d;
            cin >> u >> v >> d;
            adj[u].push_back(make_pair(d, v));
            adj[v].push_back(make_pair(d, u));
        }
        cout << fixed << setprecision(4) << dijkstra(0, n - 1) << endl;
    }
}