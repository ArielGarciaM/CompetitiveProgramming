#include <bits/stdc++.h>
using namespace std;

int prime[10005];
int dist[10005];
vector<int> primes;
vector<int> adj[10005];

void sieve() {
    for(int p = 2; p < 10005; p++) {
        if(!prime[p]) {
            primes.push_back(p);
            for(int q = 2*p; q < 10005; q += p)
                prime[q] = p;
        }
    }
}

int bfs(int s, int t) {
    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    queue<int> q({s});
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t];
}

int p10[4] = {1, 10, 100, 1000};

bool check(int p, int q) {
    int diff = 0;
    for(int i = 0; i < 4; i++)
        if((p/p10[i])%10 != (q/p10[i])%10)
            diff++;
    return diff == 1;
}

int main() {
    sieve();
    for(auto p : primes) {
        if(p < 1000)
            continue;
        for(auto q : primes) {
            if(q < 1000)
                continue;
            if(p == q)
                continue;
            if(check(p, q))
                adj[p].push_back(q);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int u, v;
        cin >> u >> v;
        int dis = bfs(u, v);
        if(dis >= 0)
            cout << dis << endl;
        else
            cout << "Impossible\n";
    }
}