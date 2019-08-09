#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int wt[MAXN], rep[MAXN], sz[MAXN];
ll cur, cnt[MAXN], tmp[MAXN], fin[MAXN];
vector<int> byw[MAXN];
pair<int, int> edges[MAXN];

int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    cur += (ll)sz[u] * (ll)sz[v];
    if(sz[u] < sz[v])
        swap(u, v);
    rep[v] = u;
    sz[u] += sz[v];
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < MAXN; i++)
        byw[i].clear();
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v};
        for(int d = 1; d * d <= w; d++) {
            if(w % d) continue;
            byw[d].push_back(i);
            if(w / d > d) byw[w / d].push_back(i);
        }
    }
    fill(rep, rep + MAXN, -1);
    fill(sz, sz + MAXN, 1);
    for(int d = 1; d < MAXN; d++) {
        cur = 0;
        for(auto id : byw[d]) {
            auto e = edges[id];
            join(e.first, e.second);
        }
        cnt[d] = cur;
        for(auto id : byw[d]) {
            auto e = edges[id];
            rep[e.first] = -1;
            sz[e.first] = 1;
            rep[e.second] = -1;
            sz[e.second] = 1;
        }
    }
    memset(tmp, 0, sizeof tmp);
    for(int d = MAXN; d >= 1; d--) {
        fin[d] = cnt[d] - tmp[d];
        for(int k = 1; k * k <= d; k++) {
            if(d % k) continue;
            tmp[k] += fin[d];
            if(d / k > k) tmp[d / k] += fin[d];
        }
    }
    ll ans = 0;
    for(ll d = 1; d < MAXN; d++)
        ans += d * fin[d];
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}