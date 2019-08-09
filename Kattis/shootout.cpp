#include <bits/stdc++.h>
using namespace std;
typedef double ld;

int n;
vector<ld> q;
ld memo[(1 << 13)][13][13];
bool seen[(1 << 13)];

const ld EPS = 1e-10;

void add(ld *v, ld q, vector<ld> &o) {
    for(int i = 0; i < n; i++)
        v[i] += q*o[i];
}

void calc(int msk) {
    if(seen[msk])
        return;
    int cnt = __builtin_popcount(msk);
    if(cnt == 1) {
        int p = __builtin_ctz(msk);
        for(int i = 0; i < n; i++) {
            if(msk & (1 << i))
                memo[msk][p][i] = 1.0;
            else
                memo[msk][p][i] = 0.0;
        }
        seen[msk] = true;
        return;
    }
    vector<int> pos;
    vector<vector<ld>> best(cnt, vector<ld>(n));
    for(int i = 0; i < n; i++) {
        if(msk & (1 << i)) {
            calc(msk ^ (1 << i));
            pos.push_back(i);
        }
    }
    for(int i = 0; i < cnt; i++) {
        int p = pos[i];
        ld bprob = -1.0;
        for(auto o : pos) {
            if(o == p)
                continue;
            int nxt = pos[(i + 1)%cnt];
            if(nxt == o)
                nxt = pos[(i + 2)%cnt];
            bprob = max(bprob, memo[msk^(1 << o)][nxt][p]);
        }
        int cb = 0;
        for(auto o : pos) {
            if(o == p)
                continue;
            int nxt = pos[(i + 1)%cnt];
            if(nxt == o)
                nxt = pos[(i + 2)%cnt];
            ld pr = memo[msk^(1 << o)][nxt][p];
            if(pr < bprob - EPS)
                continue;
            cb++;
            for(int j = 0; j < n; j++)
                best[i][j] += memo[msk^(1 << o)][nxt][j];
        }
        for(int j = 0; j < n; j++)
            best[i][j] /= ((ld)cb);
        for(int j = 0; j < n; j++)
            best[i][j] *= (1 - q[pos[i]]);
    }
    ld res[13][13];
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 13; j++)
            res[i][j] = 0.0;
    }
    for(int i = 0; i < cnt; i++) {
        int p = pos[i];
        ld mul = 1.0;
        for(int j = 0; j < cnt; j++) {
            add(res[pos[i]], mul, best[(i + j)%cnt]);
            mul *= q[pos[(i + j)%cnt]];
        }
    }
    ld Q = 1.0;
    for(int i = 0; i < cnt; i++)
        Q *= q[pos[i]];
    Q = 1.0 - Q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            memo[msk][i][j] = res[i][j]/Q;
        }
    }
    seen[msk] = true;
}

int main() {
    cout << fixed << setprecision(16);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        q.resize(n);
        for(int i = 0; i < n; i++) {
            ld pro;
            cin >> pro;
            pro /= 100.0;
            q[i] = 1.0 - pro;
        }
        memset(seen, false, sizeof seen);
        calc((1 << n) - 1);
        for(int i = 0; i < n; i++)
            cout << 100.0*memo[(1 << n) - 1][0][i] << " ";
        cout << endl;
    }
}