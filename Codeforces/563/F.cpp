#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int h[MAXN], p[MAXN], sz[MAXN];
vector<int> adj[MAXN];

int ask(char c, int u) {
    cout << c << " " << u << '\n';
    cout.flush();
    int res;
    cin >> res;
    if(res == -1)
        exit(0);
    return res;
}

void dfs(int s, int pa) {
    p[s] = pa;
    h[s] = pa ? h[pa] + 1 : 0;
    sz[s] = 1;
    for(auto v : adj[s]) {
        if(v != pa) {
            dfs(v, s);
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int joint = 1;
    int hx = ask('d', 1);
    while(h[joint] < hx) {
        int u = ask('s', joint);
        int gap = 1;
    }
    cout << "! " << joint << '\n';
}