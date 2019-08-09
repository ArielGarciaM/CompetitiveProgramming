#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;

const int MAXN = 1e6 + 5;
ll wt[MAXN], rel[MAXN];
int p[MAXN], good[MAXN], ans[MAXN];
vector<int> adj[MAXN];
set<ii> fuggers;

void dfs(int s, ll cum) {
    rel[s] = wt[s] + cum;
    for(auto v : adj[s])
        dfs(v, rel[s]);
}

void precalc(int s) {
    if(adj[s].empty())
        return;
    ll mn = LLONG_MAX;
    for(auto v : adj[s]) {
        precalc(v);
        mn = min(mn, wt[v]);
    }
    wt[s] += mn;
}

void murder(int v) {
    fuggers.erase({wt[v], v});
    if(v == 0) return;
    int u = p[v];
    good[u]++;
    if(good[u] == adj[u].size())
        fuggers.insert({wt[u], u});
}

void test_case() {
    fuggers.clear();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        good[i] = 0;
        wt[i] = 0;
        adj[i].clear();
    }
    for(int i = 1; i < n; i++) {
        int u;
        ll w;
        cin >> u >> w;
        p[i] = u;
        adj[u].push_back(i);
        wt[i] = w;
    }
    dfs(0, 0);
    precalc(0);
    vector<int> leaves;
    for(int i = 0; i < n; i++) {
        if(adj[i].empty())  {
            leaves.push_back(i);
            fuggers.insert({wt[i], i});
        }
    }
    sort(leaves.begin(), leaves.end(), [&](int a, int b){ return rel[a] < rel[b]; });

    for(int i = 0; i < leaves.size(); i++) {
        int l = leaves[i];
        murder(l);
        while(fuggers.size() && (*fuggers.begin()).first <= rel[l])
            murder((*fuggers.begin()).second);
        ans[l] = fuggers.size() + 1;
    }


    sort(leaves.begin(), leaves.end());
    for(auto x : leaves)
        cout << x << " " << ans[x] << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}