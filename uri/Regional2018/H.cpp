#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 2;
const ll INF = 1e14;
const int src = 1;

struct edge
{
    int v;
    ll len, cost;
    edge(int v = 0, ll len = 0, ll cost = 0) : v(v), len(len), cost(cost){}
};

vector<edge> adj[MAXN];
vector<bool> vist(MAXN, false);
vector<ll> dist(MAXN, INF);
vector<ll> prevCost(MAXN);

ll dijkstra()
{
    ll ans = 0;
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vist[u])
            continue;
        vist[u] = true;
        ans += prevCost[u];
        //cout << "entering " << u << ", added " << prevCost[u] << endl;
        for(edge e : adj[u])
        {
            int v = e.v;
            ll len = e.len, cost = e.cost;
            //cout << "trying to enter " << v << endl;
            if(dist[v] > dist[u] + len || (dist[v] == dist[u] + len && prevCost[v] > cost))
            {
                //cout << "entered " << v << " updated distance to " << dist[u] + len << endl;
                dist[v] = dist[u] + len;
                prevCost[v] = cost;
                pq.push({dist[v], v});
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll len, cost;
        cin >> u >> v >> len >> cost;
        adj[u].push_back(edge(v, len, cost));
        adj[v].push_back(edge(u, len, cost));
    }
    ll ans = dijkstra();
    cout << ans << endl;
}