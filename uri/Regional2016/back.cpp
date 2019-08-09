#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 5;
int deg[MAXN], in[MAXN];
vector<int> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    assert(n <= 100000);
    assert(m <= 100000);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    set<ii> active;
    for(int i = 1; i <= n; i++) {
        active.insert({deg[i], i});
        in[i] = 1;
    }
    while(active.size() && (active.begin()->first < a || active.rbegin()->first > (int)active.size() - 1 - b)) {
        while(active.size() && active.begin()->first < a) {
            int u = active.begin()->second;
            active.erase({deg[u], u});
            in[u] = 0;
            for(auto v : adj[u]) {
                if(!in[v]) continue;
                active.erase({deg[v], v});
                deg[v]--;
                active.insert({deg[v], v});
            }
        }
        while(active.size() && active.rbegin()->first > (int)active.size() - 1 - b) {
            int u = active.rbegin()->second;
            active.erase({deg[u], u});
            in[u] = 0;
            for(auto v : adj[u]) {
                if(!in[v]) continue;
                active.erase({deg[v], v});
                deg[v]--;
                active.insert({deg[v], v});
            }
        }
    }
    cout << active.size() << endl;
}