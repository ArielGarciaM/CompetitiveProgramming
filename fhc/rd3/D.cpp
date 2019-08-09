#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 8e5 + 5;
int mn[MAXN], when[MAXN], tin[MAXN], tout[MAXN], pt[MAXN], dtime = 0;
vector<int> adj[MAXN], abv[MAXN];

struct node {
    int l, r;
    ll sum, lazy, cnt;
    node *left, *right;

    ll get() { return lazy * cnt + sum; }
    void merge() { sum = left->get() + right->get(); cnt = left->cnt + right->cnt; }
    void compose(ll upd) { lazy += upd; }
    void push() { left->compose(lazy); right->compose(lazy); lazy = 0; }

    node(int l, int r) : l(l), r(r), sum(0), lazy(0), cnt(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            merge();
        }
    }

    void add(int rl, int rr) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) { compose(1); return; }
        push();
        left->add(rl, rr);
        right->add(rl, rr);
        merge();
    }

    void toggle(int p) {
        if(r < p || p < l) return;
        if(l == r) { cnt = 1; use = true; return; }
        push();
        left->toggle(p);
        right->toggle(p);
        merge();
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return 0;
        if(rl <= l && r <= rr) return get();
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};

void dfs(int rt) {
    memset(pt, 0, sizeof pt);
    memset(tin, 0, sizeof tin);
    vector<int> sta;
    sta.push_back(rt);
    while(sta.size()) {
        int s = sta.back();
        if(!tin[s]) tin[s] = dtime++;
        bool mov = false;
        for(int &i = pt[s]; i < adj[s].size(); i++) {
            if(tin[adj[s][i]]) continue;
            mov = true;
            int v = adj[s][i];
            sta.push_back(v);
            break;
        }
        if(mov)
            continue;
        mn[s] = s;
        for(auto v : adj[s])
            mn[s] = min(mn[s], mn[v]);
        tout[s] = dtime - 1;
        when[s] = s;
        sta.pop_back();
        if(adj[s].size() >= 2) {
            sort(adj[s].begin(), adj[s].end(), [&](int a, int b){ return mn[a] < mn[b]; });
            when[s] = min(when[s], max(mn[adj[s][0]], mn[adj[s][1]]));
        }
        abv[when[s]].push_back(s);
    }
}

ll solve() {
    ll res = 1;
    int n, rt;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        abv[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if(p) adj[p].push_back(i);
        else rt = i;
    }
    dtime = 1;
    dfs(rt);
    node tree(1, n);
    for(int v = 1; v <= n; v++) {
        tree.toggle(tin[v]);
        for(auto u : abv[v]) tree.add(tin[u], tout[u]);
        ll cu = tree.qry(1, n) % MOD;
        res = (res * cu) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << endl;
}