#include <bits/stdc++.h>
using namespace std;

int go[20][26];
int reach[1 << 20][26];
int n, m, k, s;

void calc() {
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int c = 0; c < 26; c++) {
            for(int bit = 0; bit < n; bit++) {
                if(mask & (1 << bit))
                    reach[mask][c] |= go[bit][c];
            }
        }
    }
}

void test_case() {
    memset(go, 0, sizeof go);
    memset(reach, 0, sizeof reach);
    cin >> n >> m >> k >> s;
    char c;
    int ac = 0;
    for(int i = 0; i < s; i++)
        cin >> c;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        ac |= (1 << x);
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y >> c;
        go[x][c - 'a'] |= (1 << y);
    }
    calc();
    int q;
    cin >> q;
    while(q--) {
        int state = 1;
        string s;
        cin >> s;
        for(auto c : s)
            state = reach[state][c - 'a'];
        cout << ((state & ac) ? "Yes\n" : "No\n");
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}

