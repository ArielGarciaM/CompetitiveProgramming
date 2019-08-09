#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
const int BIG = 1e9;
int le[MAXN], ri[MAXN], fav[MAXN];
ll A[105][105];
map<string, int> pos;

ll calc(int p) {
    ll d = 1;
    int cur = p;
    ll res = 0;
    while(d <= BIG) {
        cur = le[cur];
        res += A[fav[p]][fav[cur]] / d;
        d <<= 1;
    }
    d = 1, cur = p;
    while(d <= BIG) {
        cur = ri[cur];
        res += A[fav[p]][fav[cur]] / d;
        d <<= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, k;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        pos[s] = i;
        le[i] = i - 1;
        ri[i] = i + 1;
        cin >> fav[i];
    }
    le[0] = 0;
    ri[n + 1] = n + 1;

    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= k; j++)
            cin >> A[i][j];

    while(q--) {
        int t, a, b;
        string A, B;
        cin >> t >> A;
        a = pos[A];
        if(t == 3)
            cout << calc(a) << '\n';
        if(t == 2) {
            cin >> b;
            fav[a] = b;
        }
        if(t == 1) {
            cin >> B;
            b = pos[B];
            if(ri[a] == b) continue;
            ri[le[a]] = ri[a];
            le[ri[a]] = le[a];
            ri[a] = b;
            le[a] = le[b];
            ri[le[b]] = a;
            le[b] = a;
        }
    }
}