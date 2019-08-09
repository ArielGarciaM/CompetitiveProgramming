#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int LOG = 20;
int up[LOG][MAXN], h[MAXN];

int LCA(int u, int v) {
    if(h[v] > h[u])
        swap(u, v);
    int d = h[u] - h[v];
    for(int l = LOG - 1; l >= 0; l--)
        if((1 << l) & d) u = up[l][u];
    if(u == v) return u;
    for(int l = LOG - 1; l >= 0; l--) {
        if(up[l][u] != up[l][v]) {
            u = up[l][u];
            v = up[l][v];
        }
    }
    return up[0][u];
}

int dis(int u, int v) {
    return h[u] + h[v] - 2*h[LCA(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q, last = 0, curr = 1;
    cin >> q;
    h[1] = 0;
    for(int l = 0; l < LOG; l++) up[l][1] = 1;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int p;
            cin >> p;
            p = (p + last)%curr + 1;
            curr++;
            h[curr] = h[p] + 1;
            up[0][curr] = p;
            for(int l = 0; l < LOG - 1; l++)
                up[l + 1][curr] = up[l][up[l][curr]];
            last = h[curr] + 1;
        }
        else {
            int u, v;
            cin >> u >> v;
            u = (u + last)%curr + 1;
            v = (v + last)%curr + 1;
            last = dis(u, v) + 1;
        }
        cout << last << '\n';
    }
}