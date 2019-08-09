#include <bits/stdc++.h>
using namespace std;

int A[1030][1030], B[1030][1030], col[1030], swp[1030], comp, seen[1030];
vector<int> adj[1030], cadj[1030];
vector<pair<int, int>> bad;

void dfs(int s) {
    col[s] = comp;
    for(auto v : adj[s]) {
        if(col[v] == -1)
            dfs(v);
    }
}

bool bip(int s, int c = 0) {
    swp[s] = c;
    seen[s] = 1;
    for(auto v : cadj[s]) {
        if(swp[v] == c)
            return false;
        if(seen[v])
            continue;
        if(swp[v] == -1)
            bip(v, 1 - c);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    memset(col, -1, sizeof col);
    memset(swp, -1, sizeof swp);
    while(tc--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> A[i][j];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cin >> B[i][j];
        }
        bool b = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((A[i][j] == B[i][j] && A[j][i] == B[j][i])||(A[i][j] == B[j][i] && A[j][i] == B[i][j])) {
                    if(A[i][j] == A[j][i])
                        continue;
                    if(A[i][j] == B[i][j]) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                    else
                        bad.push_back({i, j});
                }
                else {
                    b = false;
                    break;
                }
            }
            if(!b)
                break;
        }
        comp = 0;
        for(int i = 0; i < n; i++) {
            if(col[i] == -1) {
                dfs(i);
                comp++;
            }
        }
        while(!bad.empty()) {
            auto p = bad.back();
            bad.pop_back();
            cadj[col[p.first]].push_back(col[p.second]);
            cadj[col[p.second]].push_back(col[p.first]);
        }
        for(int i = 0; i < comp; i++) {
            if(swp[i] == -1) {
                if(!bip(i)) {
                    b = false;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            col[i] = -1;
            swp[i] = -1;
            seen[i] = 0;
            bad.clear();
            adj[i].clear();
            cadj[i].clear();
        }
        cout << (b ? "Yes\n" : "No\n");
    }
}