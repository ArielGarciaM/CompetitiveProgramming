#include <bits/stdc++.h>
using namespace std;

const int MAXN = 310; // 2*100 gruas + 100 edificios + source + sink + lo que se ofrezca
const int INF = 1e9;
int n, m, src = 0, dst;
int dist[MAXN], q[MAXN], work[MAXN];

struct Edge {
    int to, rev, f, cap;
    Edge(int to, int rev, int f, int cap) : to(to), rev(rev), f(f), cap(cap){}
};

vector<Edge> G[MAXN];

void addEdge(int s, int t, int cap) {
    // cout << "arista " << s << " a " << t << " capacidad " << cap << endl;
    G[s].push_back(Edge(t, G[t].size(), 0, cap));
    G[t].push_back(Edge(s, G[s].size() - 1, 0, 0));
}

bool bfs() {
    memset(dist, -1, sizeof dist);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for(int qh = 0; qh < qt; qh++) {
        int u = q[qh];
        for(auto e : G[u]) {
            int v = e.to;
            if(dist[v] == -1 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[dst] > 0;
}

int push(int u, int f) {
    if(u == dst) return f;
    for(int &i = work[u]; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        if(e.cap <= e.f)
            continue;
        int v = e.to;
        if(dist[v] == dist[u] + 1) {
            int df = push(v, min(f, e.cap - e.f));
            if(df > 0) {
                e.f += df;
                G[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxflow() {
    int mf = 0;
    while(bfs()) {
        memset(work, 0, sizeof work);
        while(int delta = push(src, INF))
            mf += delta;
    }
    return mf;
}

void finish() {
    int pre[MAXN], vist[MAXN];
    memset(vist, 0, sizeof vist);
    pre[src] = -1;
    vist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto e : G[u]) {
            int v = e.to;
            if(e.f > 0 && !vist[v]) {
                vist[v] = 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        vector<int> ans;
        int x = 2*n + i;
        while(x != src){
            x = pre[x];
            if(1 <= x && x <= n)
                ans.push_back(x);
        }
        for(int j = ans.size() - 1; j >= 0; j--)
            cout << ans[j] << " ";
        cout << endl;
    }
}

int main() {
    /*
    Detalles importantes.
    0 es el source
    1 al n son los vértices normales de las gruas
    n + 1 a 2n son los vertices extra de las gruas
    2n + 1 a 2n + m son los vertices de los edificios
    2n + m + 1 es el sink
    */
    cin >> n;
    vector<pair<int, int>> cr(n + 1);
    for(int i = 1; i <= n; i++) {
        int w, l;
        cin >> w >> l;
        cr[i] = {w, l};
        addEdge(i, n + i, 1);
        if(w == 0)
            addEdge(src, i, 1);
    }
    cin >> m;
    dst = 2*n + m + 1;
    vector<int> bu(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> bu[i];
        addEdge(2*n + i, dst, 1);
    }
    // Construye aristas entre vertices grua
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cr[i].second >= cr[j].first)
                addEdge(i + n, j, 1);
        }
    }

    // Construye aristas entre vértices edificio y grua
    for(int b = 1; b <= m; b++) {
        for(int i = 1; i <= n; i++) {
            if(cr[i].second >= bu[b])
                addEdge(i + n, 2*n + b, 1);
        }
    }
    
    int mf = maxflow();
    if(mf < m) {
        cout << "impossible\n";
        return 0;
    }
    finish();
}