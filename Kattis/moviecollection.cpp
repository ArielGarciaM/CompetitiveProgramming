#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
int BIT[2*MAXN], m, r, pos[MAXN], ctr = MAXN;

void add(int p, int v) {
    for(;p < 2*MAXN; p += (p & -p))
        BIT[p] += v;
}

int sum(int p) {
    int s = 0;
    for(;p > 0; p -= (p & -p))
        s += BIT[p];
    return s;
}

void qry(int x) {
    add(pos[x], -1);
    cout << sum(pos[x]) << " ";
    pos[x] = ctr;
    add(pos[x], 1);
    ctr--;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> m >> r;
        memset(BIT, 0, sizeof(BIT));
        ctr = MAXN;
        for(int i = 1; i <= m; i++) {
            pos[i] = MAXN + i;
            add(pos[i], 1);
            //cout << sum(pos[i]) << endl;
        }
        while(r--) {
            int x;
            cin >> x;
            qry(x);
        }
        cout << endl;
    }
}