#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> ii;

struct edge {
    int u, v, w;
};
vector<edge> edges;

const int MAXN = 1e5 + 5;
vector<ii> adj[MAXN];
int rep[MAXN], prime[MAXN];
ll cnt[MAXN], sz[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(!prime[p])
            for(int q = p; q < MAXN; q += p)
                prime[q] = p;
    }
}

void init() {
    fill(rep, rep + MAXN, -1);
    fill(sz, sz + MAXN, 1);
}

int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    rep[u] = v;
    sz[v] += sz[u];
}

ll test_case() {
    int n;
    cin >> n;
    init();
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w == 1)
            join(u, v);
        else {
            if(w == prime[w]) {
                edges.push_back({u, v, w});
                continue;
            }
            int d = w;
            int p = prime[d];
            d /= p;
            int q = prime[d];
            if(p * q != w || p == q)
                continue;
            edges.push_back({u, v, w});
        }
    }
    ll ans = 0;
    while(!edges.empty()) {
        auto e = edges.back(); edges.pop_back();
        int p = find(e.u), q = find(e.v);
        if(e.w > prime[e.w])
            ans += sz[p] * sz[q];
        else {
            //cout << p << " " << q << " " << e.w << '\n';
            adj[p].push_back({q, e.w});
            adj[q].push_back({p, e.w});
        }
    }
    // cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
        ll s = adj[i].size();
        ll tp = 0;
        for(auto p : adj[i]) {
            tp += sz[p.first];
            cnt[p.second] += sz[p.first];
        }
        tp *= tp;
        for(auto p : adj[i]) {
            tp -= cnt[p.second]*cnt[p.second];
            cnt[p.second] = 0;
        }
        ans += tp/2;
        adj[i].clear();
    }
    return ans;
}

int main() {
    freopen("evaluations.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        cout << "Case " << i << ": " << test_case() << '\n';
}

/*
1
5
1 2 1
2 3 2
2 4 2
1 5 3

ans 2


1
5
1 2 3
2 3 2
2 4 2
1 5 3

ans  
*/