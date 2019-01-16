#include <bits/stdc++.h>
using namespace std;

int vert;
const int MAXN = 4e5;
vector<int> adj[MAXN];
int vist[MAXN];

int add(int ui, int uj, int vi, int vj) {
    adj[vert*ui + uj].push_back(vert*vi + vj);
    adj[vert*vi + vj].push_back(vert*ui + uj);
}

void dfs(int s) {
    vist[s] = 1;
    for(auto v : adj[s]) {
        if(!vist[v])
            dfs(v);
    }
}

int main() {
    int n;
    while(cin >> n) {
        vert = 2*n + 1;
        for(int i = 0; i <= 2*n - 1; i++) {
            string s;
            if(i < 2*n - 1)
                cin >> s;
            int off = (i % 2);
            if(i < 2*n - 1){ 
                if(off)
                    add(i, 0, i + 1, 0);
                else
                    add(i, 2*n, i + 1, 2*n);
            }
            for(int j = 0; j < n; j++) {
                if(i == 0 || i == 2*n - 1)
                    add(i, 2*j + 1, i, 2*j + 2);
                if(i == 2*n - 1)
                    continue;
                if(s[j] == 'H') {
                    add(i, 2*j + off, i, 2*j + 1 + off);
                    add(i + 1, 2*j + off, i + 1, 2*j + 1 + off);
                }
                else {
                    add(i, 2*j + off, i + 1, 2*j + off);
                    add(i, 2*j + 1 + off, i + 1, 2*j + 1 + off);
                }
            }
        }
        memset(vist, 0, sizeof vist);
        int ct = 0;
        for(int i = 0; i < (2*n)*(2*n + 1); i++) {
            if(vist[i])
                continue;
            dfs(i);
            ct++;
        }
        cout << ct - 1 << endl;
        for(int i = 0; i < (2*n)*(2*n + 1); i++)
            adj[i].clear();
    }
}
