#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7e4 + 5;
set<int> adj[MAXN], virgin;
vector<int> comps[MAXN];
int comp[MAXN], p[MAXN], cp[MAXN], sp;
bitset<100005> dp[2000], bk[2000];

void trav(int v, int cc) {
    queue<int> q({v});
    virgin.erase(v);
    comp[v] = cc;
    comps[cc].push_back(v);
    cp[cc] += p[v];
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vector<int> tor;
        for(auto v : virgin) {
            if(adj[u].count(v)) continue;
            tor.push_back(v);
            comp[v] = cc;
            comps[cc].push_back(v);
            cp[cc] += p[v];
            q.push(v);
        }
        while(tor.size()){
            int x = tor.back();
            virgin.erase(x);
            tor.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sp += p[i];
        virgin.insert(i);
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int cc = 1;
    for(int i = 1; i <= n; i++)
        if(!comp[i]) trav(i, cc++);
    dp[0][0] = 1;
    for(int i = 1; i <= cc; i++) {
        for(int w = 0; w <= sp/2; w++) {
            if(dp[i - 1][w]) {
                dp[i][w] = 1;
                continue;
            }
            if(w >= cp[i] && dp[i - 1][w - cp[i]]) {
                dp[i][w] = 1;
                bk[i][w] = 1;
            }
        }
    }
    int bst = 0;
    for(int j = sp/2; j >= 0; j--) {
        if(dp[cc][j]) {
            bst = j;
            break;
        }
    }
    cout << sp - 2*bst << '\n';
    vector<int> ans;
    int cw = bst;
    for(int i = cc; i >= 1; i--) {
        if(!bk[i][cw]) continue;
        cw -= cp[i];
        for(auto x : comps[i])
            ans.push_back(x);
    }
    for(auto v : ans)
        cout << v << " ";
    cout << '\n';
}