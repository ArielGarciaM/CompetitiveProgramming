#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int deg[MAXN], sta[MAXN], ex[MAXN];
vector<int> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    while(p--) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q({l});
    sta[l] = 1;
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(!sta[v]) {
                ex[v]++;
                if(2*ex[v] >= deg[v]) {
                    q.push(v);
                    sta[v] = 1;
                }
            }
        }
    }
    cout << (sta[x] ? "leave\n" : "stay\n");
}