#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct edge {
    int tox, toy, asc, desc;
};

struct state {
    int asc, desc, x, y;
    bool operator<(const state &o) const { return tie(asc, desc) > tie(o.asc, o.desc);}
};

const int INF = 1e9 + 9;
ii dis[605][605];
int board[605][605];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<edge> adj[605][605];

void solve(int x, int y) {
    priority_queue<state> pq;
    pq.push({0, 0, x, y});
    dis[x][y] = {0, 0};
    while(!pq.empty()) {
        state s = pq.top(); pq.pop();
        if(ii{s.asc, s.desc} > dis[s.x][s.y])
            continue;
        //cout << s.x << " " << s.y << " " << s.asc << " " << s.desc <<'\n';
        auto p = dis[s.x][s.y];
        for(auto e : adj[s.x][s.y]) {
            int tx = e.tox, ty = e.toy;
            ii pot = {p.first + e.asc, p.second + e.desc};
            if(pot < dis[tx][ty]) {
                dis[tx][ty] = pot;
                pq.push({pot.first, pot.second, tx, ty});
            }
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 605; i++)
        for(int j = 0; j < 605; j++)
            adj[i][j].clear();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if(board[ni][nj] >= board[i][j] && board[ni][nj] <= board[i][j] + 2) {
                    //cout << i << " " << j << " " << ni << " " << nj << " " << board[ni][nj] - board[i][j] << " 0\n";
                    adj[i][j].push_back({ni, nj, board[ni][nj] - board[i][j], 0});
                }
                if(board[ni][nj] < board[i][j] && board[ni][nj] >= board[i][j] - 4) {
                    //cout << i << " " << j << " " << ni << " " << nj << " 0 " << board[i][j] - board[ni][nj] << '\n';
                    adj[i][j].push_back({ni, nj, 0, board[i][j] - board[ni][nj]});
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dis[i][j] = ii{INF, INF};
    solve(n - 1, 0);
    auto p = dis[0][m - 1];
    if(p.first < INF)
        cout << p.first << " " << p.second << '\n';
    else
        cout << "IMPOSSIBLE\n";
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}