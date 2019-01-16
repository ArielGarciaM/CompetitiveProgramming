#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN]; // Parejas (vecino, peso)
int dist[MAXN]; // Distancia

void dijkstra(int s) {
    fill(dist, dist + MAXN, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int u = pq.top().second, c = -pq.top().first;
        pq.pop();
        if(dist[u] < c)
            continue;
        for(auto p : adj[u]) {
            int v = p.first, w = p.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
                vist[v] = 1;
            }
        }
    }
}

