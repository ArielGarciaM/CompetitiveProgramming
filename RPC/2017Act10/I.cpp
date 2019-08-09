#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator< (const edge &o) const { return w < o.w; }
};

const int MAXN = 105;
int par[MAXN];

void init() {
    for(int i = 0; i < MAXN; i++)
        par[i] = -1;
}

int find(int i) {
    return (par[i] == -1 ? i : par[i] = find(par[i]));
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return false;
    par[u] = v;
    return true;
}

vector<edge> edges;

int n, m;

int kruskal() {
    init();
    int comps = n, mwt = 1e9;
    sort(edges.rbegin(), edges.rend());
    for(auto e : edges) {
        if(join(e.u, e.v)) {
            comps--;
            //cout << e.u << " " << e.v << " " << e.w << endl;
            mwt = min(mwt, e.w);
        }
    }
    return mwt;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n >> m;
        edges.clear();
        while(m--) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(edge{u, v, w});
        }
        cout << "Case #" << tc << ": " << kruskal() << '\n';
    }
}