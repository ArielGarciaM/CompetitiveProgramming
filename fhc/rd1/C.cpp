#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 5005;
const ll INF = 1e12;
int ptr[MAXN], dis[MAXN], src, dst;

struct edge {
    int to, rev;
    ll f, cap;
};
vector<edge> adj[MAXN];

void addEdge(int u, int v, ll cap, ll rcap) {
    //cout << "edge = " << u << " " << v << " " << cap << endl;
    edge a = {v, (int)adj[v].size(), 0LL, cap};
    edge b = {u, (int)adj[u].size(), 0LL, rcap};
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

ll dfs(int u, ll f) {
    if(u == dst || !f) return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
            continue;
        if(ll df = dfs(v, min(f, e.cap - e.f))) {
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

int solve() {
    for(int i = 0; i < MAXN; i++) adj[i].clear();
    int n, h;
    cin >> n >> h;
    src = 0, dst = 2*n*n + 1;
    int pt = 1;
    map<ii, int> conv;
    map<int, int> cost;
    vector<ii> pts;
    vector<array<int, 3>> segs;
    vector<int> vert;
    set<int> hs({0, h});
    for(int i = 1; i <= n; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        hs.insert(a);
        hs.insert(b);
        segs.push_back({x, a, b});
    }
    for(auto x : hs)
        vert.push_back(x);

    for(int i = 1; i < vert.size(); i++)
        cost[vert[i]] = vert[i] - vert[i - 1];

    for(auto s : segs) {
        for(int i = 0; i < vert.size(); i++) {
            int y = vert[i];
            if(s[1] < y && y <= s[2]) {
                conv[{s[0], y}] = pt++;
                pts.push_back({s[0], y});
                int sy = vert[i - 1];
                if(sy == 0)
                    addEdge(src, conv[ii{s[0], y}], INF, INF);
                if(y == h)
                    addEdge(conv[ii{s[0], y}], dst, INF, INF);
                if(vert[i - 1] > s[1])
                    addEdge(conv[ii{s[0], y}], conv[ii{s[0], vert[i - 1]}], INF, INF);
            }
        }
    }

    sort(pts.begin(), pts.end(), [&](ii a, ii b) {
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    for(int i = 0; i < pts.size() - 1; i++) {
        auto p1 = pts[i], p2 = pts[i + 1];
        if(p1.second == p2.second) {
            // cout << "(" << p1.first << ", " << p1.second << ") (" << p2.first << ", " << p2.second << ") " << cost[p1.second] << endl;
            int y = cost[p1.second];
            addEdge(conv[p1], conv[p2], y, y);
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