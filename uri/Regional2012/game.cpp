#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

const int MAXV = 2505;
const int INF = 1e9;
int n, R, C;
int src, dst;
int dist[MAXV], q[MAXV], work[MAXV];
char board[51][51];

struct Edge {
    int to, rev, f, cap;
    Edge(int to, int rev, int f, int cap) : to(to), rev(rev), f(f), cap(cap){}
};


vector<Edge> G[MAXV];

void addEdge(int s, int t, int cap) {
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
    return dist[dst] != -1;
}

int push(int u, int f) {
    if(u == dst)
        return f;
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
        while(int fl = push(src, INF))
            mf += fl;
    }
    return mf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int ct, wct, ed;
    while(cin >> R >> C) {
        n = R*C + 2;
        src = R*C;
        dst = R*C + 1;
        ct = wct = ed = 0;
        for(int i = 0; i < R; i++) {
            string str;
            cin >> str;
            for(int j = 0; j < C; j++) {
                board[i][j] = str[j];
                if(str[j] == '.')
                    ct++;
            }
        }
        if(ct % 2) {
            cout << "1\n";
            continue;
        }
        for(int x = 0; x < R*C; x++) {
            int i = x/C, j = x%C;
            if(board[i][j] != '.')
                continue;
            if((i + j) % 2) {
                addEdge(x, dst, 1);
                continue;
            }
            else {
                wct++;
                addEdge(src, x, 1);
            }
            for(auto d : dir) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || ni >= R || nj < 0 || nj >= C)
                    continue;
                if(board[ni][nj] == '.')
                    addEdge(C*i + j, C*ni + nj, 1);
            }
        }
        if(2*wct != ct) {
            cout << "1\n";
        }
        else {
            int mf = maxflow();
            if(mf == ct/2)
                cout << "2\n";
            else
                cout << "1\n";
        }
        for(int i = 0; i < MAXV; i++)
            G[i].clear();
    }
}