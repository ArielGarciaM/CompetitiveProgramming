#include <bits/stdc++.h>
using namespace std;

int mov[18][26];
int nxt[1<<18][26];
int n, m, s, k;

void calc() {
    for(int ms = 0; ms < (1 << n); ms++) {
        for(int c = 0; c < 26; c++) {
            for(int b = 0; b < n; b++) {
                if(ms & (1 << b))
                    nxt[ms][c] |= mov[b][c];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(mov, 0, sizeof mov);
        memset(nxt, 0, sizeof nxt);
        cin >> n >> m >> s >> k;
        char c;
        for(int i = 0; i < s; i++)
            cin >> c;
        int ac = 0;
        for(int i = 0; i < k; i++) {
            int b;
            cin >> b;
            ac |= (1 << b);
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            mov[u][c - 'a'] |= (1 << v);
        }
        calc();
        int q;
        cin >> q;
        while(q--) {
            string s;
            cin >> s;
            int cur = 1;
            for(auto c : s)
                cur = nxt[cur][c - 'a'];
            cout << ((cur & ac) ? "Yes\n" : "No\n");
        }
    }
}