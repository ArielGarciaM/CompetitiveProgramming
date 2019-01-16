#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> sons[MAXN];
int dist[MAXN], pars[MAXN], vist[MAXN];
queue<int> q;

int prop(int s) {
    if(vist[s])
        return dist[s];
    vist[s] = 1;
    for(auto v : sons[s])
        dist[s] = max(dist[s], 1 + prop(v));
    return dist[s];
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        sons[x].push_back(y);
        pars[y]++;
    }
    for(int i = 1; i <= n; i++) {
        if(pars[i] == 0)
            prop(i);
    }
    int mx = 0;
    for(int i = 1; i <= n; i++)
        mx = max(mx, dist[i]);
    cout << mx << endl;
}