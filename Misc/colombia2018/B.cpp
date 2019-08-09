#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
string s, t;
int n, col[MAXN], ccomp[MAXN], sz[MAXN], cur, ctw, ctb, comp;
vector<int> adj[MAXN], cadj[MAXN];

void flood(int s) {
    col[s] = comp;
    sz[comp]++;
    for(auto v : adj[s])
        if(col[v] == -1)
            flood(v);
}

bool bip(int s, int c, bool f){
    ccomp[s] = c;
    if(c == 0)
        ctw += sz[s];
    else
        ctb += sz[s];
    for(auto v : cadj[s]) {
        if(ccomp[v] == ccomp[s])
            return false;
        if(ccomp[v] != -1)
            continue;
        if(!bip(v, 1 - c, false))
            return false;
    }
    if(f)
        cur += min(ctw, ctb);
    return true;
}

int check() {
    cur = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) {
            adj[i].push_back((i + 1)%n);
            adj[(i + 1)%n].push_back(i);
        }
    }
    memset(col, -1, sizeof col);
    memset(sz, 0, sizeof sz);
    comp = 0;
    for(int i = 0; i < n; i++) {
        if(col[i] == -1) {
            flood(i);
            comp++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            cadj[col[i]].push_back(col[(i + 1)%n]);
            cadj[col[(i + 1)%n]].push_back(col[i]);
        }
    }
    memset(ccomp, -1, sizeof ccomp);
    for(int i = 0; i < comp; i++) {
        if(ccomp[i] == -1) {
            ctw = ctb = 0;
            if(!bip(i, 0, true))
                return -1;
        }
    }
    return cur;
}

int main() {
    cin >> s >> t;
    n = s.length();
    int ans = 1000000, ct0 = 0, ct1 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1')
            ct0++;
        if(t[i] == '1')
            ct1++;
    }
    if(ct0 % 2 != ct1 % 2) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        ans = min(ans, check());
        for(int i = 0; i < MAXN; i++) {
            adj[i].clear();
            cadj[i].clear();
        }
        string aux = t.substr(1, 10000) + t[0];
        t = aux;
    }
    cout << ans << endl;
}