#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
vector<int> adj[3 * MAXN];
int dis[3 * MAXN], n, m, S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(n + v);
        adj[n + u].push_back(n + n + v);
        adj[n + n + u].push_back(v);
    }
    cin >> S >> T;
    memset(dis, -1, sizeof dis);
    queue<int> q({S});
    dis[S] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    if(dis[T] == -1)
        cout << "-1\n";
    else
        cout << dis[T]/3 << '\n';
}