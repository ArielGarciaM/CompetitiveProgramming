#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 110;
const ll INF = 1e9;
ii segs[MAXN];
int ptr[MAXN], dis[MAXN], src, dst;
map<int, int> com;

struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void addEdge(int u, int v, int cap, int rcap) {
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, rcap};
    adj[u].push_back(a), adj[v].push_back(b);
}

bool bfs() {
    queue<int> q({src});
    memset(dis, -1, sizeof dis);
    dis[src] = 0;
    while(!q.empty() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] == -1 && e.f < e.cap) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[dst] != -1;
}

ll dfs(int u, int f) {
    if(u == dst || !f) return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
            continue;
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

ll mf() {
    ll res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(ll pushed = dfs(src, INF)) {
            res += pushed;
        }
    }
    return res;
}

struct seg {
    int x, a, b, idx;
};

int solve() {
    for(int i = 0; i < MAXN; i++) adj[i].clear();
    com.clear();
    int n, h;
    cin >> n >> h;
    src = 0, dst = n + 1;
    vector<seg> segs, tmp;
    for(int i = 1; i <= n; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        segs.push_back({x, a, b, i});
    }
    tmp = segs;
    sort(tmp.begin(), tmp.end(), [&](seg s1, seg s2){
        if(s1.a != s2.a) return s1.a < s2.a;
        return s1.b > s2.b;
    });
    segs.clear();
    for(auto s : tmp) {
        if(segs.empty() || s.b > segs.back().b)
            segs.push_back(s);
    }
    sort(segs.begin(), segs.end(), [&](seg s1, seg s2){ return s1.x < s2.x; });
    for(auto s : segs)
        cout << s.x << " (" << s.a << ", " << s.b << ")\n";
    for(int i = 0; i < segs.size(); i++) {
        if(segs[i].a == 0)
            addEdge(src, segs[i].idx, INF, 0);
        if(segs[i].b == h)
            addEdge(segs[i].idx, dst, INF, 0);
        int A = segs[i].a, B = segs[i].b;
        for(int j = i + 1; j < segs.size(); j++) {
            cout << "[" << A << ", " << B << "]" << endl;
            int oA = segs[j].a, oB = segs[j].b;
            int M = min(B, oB), m = max(A, oA);
            if(M <= m) continue;
            addEdge(segs[i].idx, segs[j].idx, M - m, 0);
            cout << segs[i].idx << " " << segs[j].idx << " " << M - m << endl;
            if(oB < B)
                A = oB;
            else
                B = oA;
        }
        A = segs[i].a, B = segs[i].b;
        for(int j = i - 1; j >= 0; j--) {
            int oA = segs[j].a, oB = segs[j].b;
            int M = min(B, oB), m = max(A, oA);
            if(M <= m) continue;
            addEdge(segs[i].idx, segs[j].idx, M - m, 0);
            cout << segs[i].idx << " " << segs[j].idx << " " << M - m << endl;
            if(oB < B)
                A = oB;
            else
                B = oA;
        }
    }
    ll res = mf();
    if(res >= INF)
        res = -1;
    return res;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << '\n';
}