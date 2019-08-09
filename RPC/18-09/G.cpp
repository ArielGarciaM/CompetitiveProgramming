#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    double w;
};

bool cmp(const edge& e1, const edge& e2) { return e1.w > e2.w; }
vector<edge> edges;

const int MAXN = 505;
double p[MAXN][MAXN];
bool use[MAXN][MAXN];

const int MAXV = 2*MAXN;
int rep[MAXV], n, m;

void init() { fill(rep, rep + MAXV, -1); }
int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}
bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    rep[v] = u;
    return true;
}
void kruskal() {
    sort(edges.begin(), edges.end(), cmp);
    for(auto e : edges) {
        if(join(e.u, e.v))
            use[e.u][e.v - m] = true;
    }
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while(k--) {
            int j;
            cin >> j;
            edges.push_back({i, j + m, p[i][j]});
        }
    }
    init();
    kruskal();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(use[i][j])
                cout << i << " " << j << '\n';
        }
    }
}