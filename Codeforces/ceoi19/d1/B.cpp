#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> edge;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;
int n, q, mv, upos[MAXN], vpos[MAXN], in[MAXN], out[MAXN];
ll w, last, mw;
vector<pair<int, int>> edges;
vector<edge> adj[MAXN];

void dfs(int s, int p = 0, ll cur = 0) {
    if(cur > mw) {
        mw = cur;
        mv = s;
    }
    for(auto e : adj[s]) {
        if(e.first == p) continue;
        dfs(e.first, s, cur + e.second);
    }
}

ll diam_naive() {
    mw = 0;
    dfs(1);
    mw = 0;
    dfs(mv);
    return mw;
}

void solve_naive() {
    while(q--) {
        ll d, e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;
        int u = edges[d].first, v = edges[d].second;
        adj[u][upos[d]].second = e;
        adj[v][vpos[d]].second = e;
        last = diam_naive();
        cout << last << '\n';
    }
}

void solve_star() {
    set<pair<int, int>, greater<pair<int, int>>> S;
    for(auto e : adj[1])
        S.insert({e.second, e.first});
    vector<ll> dis(n + 1);
    for(auto e : adj[1])
        dis[e.first] = e.second;
    while(q--) {
        ll d, e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;
        int u = edges[d].first, v = edges[d].second;
        S.erase({dis[v], v});
        dis[v] = e;
        S.insert({dis[v], v});
        auto it = S.begin();
        last = it->first;
        ++it;
        if(it != S.end()) last += it->first;
        cout << last << endl;
    }
}

void solve_btree() {
    vector<ll> down(n + 1), tot(n + 1);
    for(int v = n; v >= 1; v--) {
        tot[v] = down[v] = 0;
        for(auto e : adj[v])
            if(e.first > v) {
                tot[v] += e.second + down[e.first];
                down[v] = max(down[v], e.second + down[e.first]);
            }
    }
    set<pair<ll, int>, greater<pair<ll, int>>> S;
    for(int v = 1; v <= n; v++)
        S.insert({tot[v], v});
    while(q--) {
        ll d, e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;
        int u = edges[d].first, v = edges[d].second;
        adj[u][upos[d]].second = e;
        adj[v][vpos[d]].second = e;
        for(int x = u; x >= 1; x /= 2) {
            S.erase({tot[x], x});
            tot[x] = down[x] = 0;
            for(auto e : adj[x])
                if(e.first > x) {
                    tot[x] += e.second + down[e.first];
                    down[x] = max(down[x], e.second + down[e.first]);
                }
            S.insert({tot[x], x});
        }
        last = S.begin()->first;
        cout << last << endl;
    }
}

struct node {
    int l, r;
    ll mx, lazy;
    node *left, *right;

    ll get() { return mx + lazy; }
    void merge() { mx = max(left->get(), right->get()); }
    void compose(ll upd) { lazy += upd; }
    void push() {
        left->compose(lazy);
        right->compose(lazy);
        lazy = 0;
    }

    node(int l, int r, vector<ll> &v) : l(l), r(r), lazy(0) {
        if(l == r)
            mx = v[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, v);
            right = new node(m + 1, r, v);
            merge();
        }
    }

    void upd(int rl, int rr, int val) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) { compose(val); return; }
        push();
        left->upd(rl, rr, val);
        right->upd(rl, rr, val);
        merge();
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return -INF;
        if(rl <= l && r <= rr) return get();
        push();
        merge();
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int dtime;
void tour(int s, int p, ll tot, vector<int> &in, vector<int> &out, vector<ll> &rpath) {
    in[s] = ++dtime;
    rpath[in[s]] = tot;
    for(auto e : adj[s]) {
        if(e.first == p) continue;
        tour(e.first, s, tot + e.second, in, out, rpath);
    }
    out[s] = dtime;
}

void classify(int s, int p, int t, vector<int> &type) {
    type[s] = t;
    for(auto e : adj[s]) {
        if(e.first == p) continue;
        classify(e.first, s, t, type);
    }
}

void solve_root() {
    vector<int> in(n + 1), out(n + 1), type(n + 1);
    vector<ll> rpath(n + 1);
    tour(1, 0, 0, in, out, rpath);
    for(auto e : adj[1])
        classify(e.first, 1, e.first, type);

    node tree(1, n, rpath);
    set<pair<ll, int>, greater<pair<ll, int>>> S;

    for(auto e : adj[1]) {
        int v = e.first;
        S.insert({tree.qry(in[v], out[v]), v});
    }
    //for(int v = 1; v <= n; v++)
    //    cout << rpath[v] << endl;
    while(q--) {
        ll d, e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;
        int u = edges[d].first, v = edges[d].second;
        ll pre = adj[u][upos[d]].second;
        if(in[u] > in[v])
            swap(u, v);
        int t = type[v];
        //assert(S.count({tree.qry(in[t], out[t]), t}));
        //S.erase({tree.qry(in[t], out[t]), t});
        //tree.upd(in[v], out[v], e - pre);
        cout << "UPDATED!" << endl;
        //S.insert({tree.qry(in[t], out[t]), t});
        adj[u][upos[d]].second = e;
        adj[v][vpos[d]].second = e;
        exit(0);
        //auto it = S.begin();
        //last = it->first;
        //++it;
        //if(it != S.end()) last += it->first;
        //cout << last << endl;
        //cout << "OUTPUTTED!" << endl;
        cout << q << " left." << endl;
        //exit(0);
    }
    cout << "FINISHED <3" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> w;
    bool star = true, btree = true;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        if(u > v) swap(u, v);
        if(u != 1) star = false;
        if(v != 2*u && v != 2*u + 1) btree = false;
        upos[i] = adj[u].size();
        vpos[i] = adj[v].size();
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
        edges.push_back({u, v});
    }
    /*if(star) {
        solve_star();
        return 0;
    }
    if(btree) {
        solve_btree();
        return 0;
    }
    if(n <= 5000 && q <= 5000) {
        solve_naive();
        return 0;
    }*/
    solve_root();
}