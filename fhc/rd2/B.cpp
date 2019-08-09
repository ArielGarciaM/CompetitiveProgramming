#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4040;
int rep[MAXN], sz[MAXN], color[MAXN], dp[MAXN], pre[MAXN];

void init() {
    fill(rep, rep + MAXN, -1);
    fill(sz, sz + MAXN, 1);
    fill(color, color + MAXN, 0);
}

int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    rep[v] = u;
    sz[u] += sz[v];
}

string solve() {
    int n, m;
    cin >> n >> m;

    init();
    for(int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;
        for(int p = L;;p++) {
            int q = (R + L - p);
            if(p >= q) break;
            join(p, q);
        }
    }
    map<int, int> sizes;
    for(int i = 1; i <= n; i++) {
        int u = find(i);
        if(!sizes.count(u)) sizes[u] = sz[u];
    }
    vector<pair<int, int>> v;
    for(auto p : sizes)
        v.push_back(p);
    int t = v.size();
    fill(dp, dp + MAXN, 0);
    fill(pre, pre + MAXN, 0);
    dp[0] = 1;
    for(int i = 0; i < t; i++) {
        for(int wt = n/2; wt >= 0; wt--) {
            if(dp[wt]) continue;
            if(wt >= v[i].second && dp[wt - v[i].second]) {
                dp[wt] = 1;
                pre[wt] = i;
            }
        }
    }
    int W = n/2;
    for(;;W--)
        if(dp[W]) break;
    while(W) {
        color[v[pre[W]].first] = 1;
        W -= v[pre[W]].second;
    }
    string res = "";
    for(int i = 1; i <= n; i++)
        res += ('0' + color[find(i)]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << '\n';
}