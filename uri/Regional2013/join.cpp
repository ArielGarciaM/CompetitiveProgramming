#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e4 + 5;
vector<int> adj[MAXN], dist1, dist2;
int dep[MAXN], dp[MAXN], path[MAXN], far[MAXN], mxl[MAXN], mxr[MAXN], suff[MAXN];

void dfs(int s, int p = 0) {
    dep[s] = 0;
    for(auto v : adj[s]) {
        if(v != p) {
            dfs(v, s);
            dep[s] = max(dep[s], 1 + dep[v]);
        }
    }
    for(int i = 0; i < adj[s].size(); i++) {
        if(i > 0) 
            mxl[i] = mxl[i - 1];
        else
            mxl[i] = 0;
        if(adj[s][i] != p)
            mxl[i] = max(mxl[i], dep[adj[s][i]] + 1);
    }
    for(int i = adj[s].size() - 1; i >= 0; i--) {
        if(i < adj[s].size() - 1) 
            mxr[i] = mxr[i + 1];
        else
            mxr[i] = 0;
        if(adj[s][i] != p)
            mxr[i] = max(mxr[i], dep[adj[s][i]] + 1);
    }
    for(int i = 0; i < adj[s].size(); i++) {
        if(adj[s].size() == 1) {
            dp[adj[s][i]] = 0;
            break;
        }
        if(adj[s][i] == p)
            continue;
        if(i == 0) {
            dp[adj[s][i]] = mxr[1];
            continue;
        }
        if(i == adj[s].size() - 1) {
            dp[adj[s][i]] = mxl[adj[s].size() - 2];
            continue;
        }
        dp[adj[s][i]] = max(mxl[i - 1], mxr[i + 1]);
    }
}

void calc(int s, int p = 0) {
    int ans = dep[s];
    path[s] = dp[s];
    if(p != 0) {
        if(p != 1)
            path[s] = max(path[s], 1 + path[p]);
        ans = max(ans, 1 + path[s]);
    }
    far[s] = ans;
    for(auto v : adj[s])
        if(v != p)
            calc(v, s);
}

void get(int m, vector<int> &res) {
    for(int i = 0; i < m - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    //for(int v = 1; v <= m; v++)
    //    cout << dp[v] << " ";
    //cout << endl;
    dp[1] = 0;
    calc(1);
    for(int v = 1; v <= m; v++) {
        adj[v].clear();
        //cout << far[v] << " ";
        res.push_back(far[v]);
    }
    //cout << endl;
}

int main() {
    int n, q;
    while(cin >> n >> q) {
        get(n, dist1);
        get(q, dist2);
        sort(dist1.begin(), dist1.end());
        sort(dist2.begin(), dist2.end());
        //cout << dist1.back() << " " << dist2.back() << endl;
        ll diam = max(dist1.back(), dist2.back());
        for(int i = q - 1; i >= 0; i--)
            suff[i] = suff[i + 1] + dist2[i];
        ll ans = 0;
        for(auto d : dist1) {
            if(d + dist2[q - 1] + 1 < diam) {
                ans += (ll)q * diam;
                continue;
            }
            int lo = 0, hi = q - 1;
            while(lo < hi) {
                int mi = (lo + hi)/2;
                if(d + dist2[mi] + 1 >= diam)
                    hi = mi;
                else
                    lo = mi + 1;
            }
            ans += (suff[lo] + (ll)(q - lo)*(d + 1ll) + (ll)lo*diam);
        }
        cout << fixed << setprecision(3) << (double)ans/(double)(n*q) << endl;
        dist1.clear(), dist2.clear();
        memset(suff, 0, sizeof suff);
    }
}