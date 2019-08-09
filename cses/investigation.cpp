#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sgn = 0;
const ll MOD = 1e9 + 7;

struct edge {
    int v;
    ll w;
};

struct state {
    int di;
    ll w;
    bool operator< (const state &o) const { return tie(w, di) < tie(o.w, o.di); }
    bool operator<= (const state &o) const { return tie(w, di) <= tie(o.w, o.di); } 
    state operator+ (const state &o) { return {di + o.di, w + o.w}; }
};

typedef pair<state, int> psi;

vector<vector<edge>> adj;
vector<state> dis;
vector<ll> cnt;

void dijkstra() {
    fill(dis.begin(), dis.end(), state{1000000000, 1000000000000000000LL});
    fill(cnt.begin(), cnt.end(), 0);
    cnt[1] = 1;
    priority_queue<psi, vector<psi>, greater<psi>> q;
    dis[1] = {0, 0};
    q.push({dis[1], 1});
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        int u = p.second;
        state d = p.first;
        if(dis[u] < d)
            continue;
        for(auto e : adj[u]) {
            if(dis[u] + state{sgn, e.w} <= dis[e.v]) {
                cnt[e.v] += cnt[u];
                if(cnt[e.v] >= MOD)
                    cnt[e.v] -= MOD;
            }
            if(dis[u] + state{sgn, e.w} < dis[e.v]) {
                dis[e.v] = dis[u] + state{sgn, e.w};
                cnt[e.v] = cnt[u];
                q.push({dis[e.v], e.v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dis.resize(n + 1);
    cnt.resize(n + 1);
    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra();
    cout << dis[n].w << " " << cnt[n] << " ";
    sgn = 1;
    dijkstra();
    cout << dis[n].di << " ";
    sgn = -1;
    dijkstra();
    cout << -dis[n].di << '\n';
}