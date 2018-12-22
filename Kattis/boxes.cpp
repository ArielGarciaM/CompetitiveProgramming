#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int ht[MAXN], tree[MAXN], parent[21][MAXN], n;
vector<int> adj[MAXN];

int dfs(int src, int lv = 1) {
    tree[src] = 1;
    ht[src] = lv;
    for(auto v : adj[src]) {
        tree[src] += dfs(v, lv + 1);
    }
    return tree[src];
}

void buildLCA() {
    dfs(0);
    for(int j = 1; j < 21; j++) {
        for(int v = 0; v <= n; v++) {
            if(parent[j - 1][v] != -1)
                parent[j][v] = parent[j - 1][parent[j - 1][v]];
        }
    }
}

int LCA(int u, int v) {
    if(ht[u] < ht[v])
        swap(u, v);
    int diff = ht[u] - ht[v];
    for(int j = 20; j >= 0; j--) {
        if(1 << j <= diff) {
            diff -= 1 << j;
            u = parent[j][u];
        }
    }
    if(u == v)
        return u;
    for(int j = 20; j >= 0; j--) {
        if(parent[j][u] != parent[j][v]) {
            u = parent[j][u];
            v = parent[j][v];
        }
    }
    return parent[0][u];
}

bool comp(int u, int v) {
    return ht[u] < ht[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < 21; j++)
            parent[j][i] = -1;
    }
    for(int i = 1; i <= n; i++) {
        cin >> parent[0][i];
        adj[parent[0][i]].push_back(i);
    }
    buildLCA();
    int q;
    cin >> q;
    while(q--) {
        int M, ans = 0;
        vector<int> boxes, independent;
        cin >> M;
        for(int i = 0; i < M; i++) {
            int v;
            cin >> v;
            boxes.push_back(v);
        }
        sort(boxes.begin(), boxes.end(), comp);
        for(int i = 0; i < M; i++) {
            bool extend = true;
            int u = boxes[i];
            for(auto v : independent) {
                if(LCA(u, v) == v) {
                    extend = false;
                    break;
                }
            }
            if(!extend)
                continue;
            independent.push_back(u);
            ans += tree[u];
        }
        /*for(auto u : independent)
            cout << u << " ";
        cout << endl;*/
        cout << ans << endl;
    }
}