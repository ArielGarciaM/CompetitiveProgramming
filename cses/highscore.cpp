#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int MAXN = 2505;
ll dis[MAXN];

int main() {
    fill(dis, dis + MAXN, INF);
    int n, m;
    cin >> n >> m;
    vector<array<ll, 3>> edges;
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, -w});
    }
    dis[1] = 0;
    bool neg = false;
    for(int ii = 0; ii <= 2*n; ii++) {
        for(auto e : edges) {
            if(dis[e[1]] > dis[e[0]] + e[2]) {
                dis[e[1]] = dis[e[0]] + e[2];
                if(ii >= n) { 
                    if(dis[e[1]] < 1e14)
                        dis[e[1]] = -INF;
                    if(e[1] == n) neg = true;
                }
            }
        }
    }
    if(neg)
        cout << "-1\n";
    else
        cout << -dis[n] << '\n';
}