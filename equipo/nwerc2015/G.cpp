#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
ll BIT[MAXN], n;
int perms[3][MAXN], pos[3][MAXN], cperm[MAXN];

void upd(int p, int v) {
    for(;p < MAXN; p += (p & -p))
        BIT[p] += v;
}

ll sum(int p) {
    ll res = 0;
    for(;p > 0; p -= (p & -p))
        res += BIT[p];
    return res;
}

ll invs() {
    memset(BIT, 0, sizeof BIT);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = cperm[i];
        ans += (sum(n) - sum(x));
        upd(x, 1);
    }
    return ans;
}

int main() {
    cin >> n;
    for(int j = 0; j < 3; j++) {
        for(int i = 1; i <= n; i++){
            cin >> perms[j][i];
            pos[j][perms[j][i]] = i;
        }
    }

    ll ans = 0;
    for(int i1 = 0; i1 < 2; i1++) {
        for(int i2 = i1 + 1; i2 < 3; i2++) {
            for(int i = 1; i <= n; i++)
                cperm[i] = pos[i1][perms[i2][i]];
            ans += invs();
        }
    }
    cout << n*(n - 1)/2 - ans/2 << endl;
}